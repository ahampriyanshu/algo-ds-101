public class Uebung1_2 implements PlugInFilter, MouseListener {
    private ImageProcessor ip;
    boolean[] state;
    int[] pixels;
    Queue<Integer> nextPixels;
    int threshould;

    /**
     * adds one pixel to the next-pixel queue only if it's not
     * already added.
     */
    void addNextPixel(int p) {
        if(!state[p]) {
            nextPixels.add(p);
            state[p] = true;
        }
    }

    boolean pixelsSimilar(int color1, int color2) {
        int dr = Math.abs(((color1 >> 16) & 0xff) -
                          ((color2 >> 16) & 0xff));
        int dg = Math.abs(((color1 >>  8) & 0xff) -
                          ((color2 >>  8) & 0xff));
        int db = Math.abs(((color1 >>  0) & 0xff) -
                          ((color2 >>  0) & 0xff));
        return ((double)(dr + dg + db) / 3.0) <= threshould;
    }

    /**
     * actually does the hard work :)
     * @param x the x position from which to start filling
     * @param y the y position from which to start filling
     */
    private void doFill(int x, int y, boolean connect8) {
        // first, add the start pixel
        int width = ip.getWidth(),
            height = ip.getHeight();
        /* for 8bit, we just gonna take the median of rgb */
        Color colorC = ij.gui.Toolbar.getForegroundColor();
        int color = colorC.getRGB();
        int firstPixel = ip.get(x, y);

        // go on with the mainloop
        addNextPixel(y * width + x);
        while(!nextPixels.isEmpty()) {
            int nextPixel = nextPixels.remove();
            int pixel = pixels[nextPixel];
            if(pixelsSimilar(pixel, firstPixel)) {
                // yay it matches. put the neighbours.
                int xN = nextPixel % width,
                    yN = nextPixel / width;
                /* the three pixels above */
                if(yN - 1 >= 0) {
                    if(connect8) {
                        if(xN + 1 < width) { 
                            addNextPixel(nextPixel - width + 1);
                        }
                        if(xN - 1 >= 0) {
                            addNextPixel(nextPixel - width - 1);
                        }
                    }
                    addNextPixel(nextPixel - width);
                }

                /* pixels left and right from the current one */
                if(xN > 0) {
                    addNextPixel(nextPixel - 1);
                }
                if(xN + 1 < width) {
                    addNextPixel(nextPixel + 1);
                }

                /* three pixels below */
                if(yN + 1 < height) {
                    if(connect8) {
                        if(xN + 1 < width) { 
                            addNextPixel(nextPixel + width + 1);
                        }
                        if(xN - 1 >= 0) {
                            addNextPixel(nextPixel + width - 1);
                        }
                    }
                    addNextPixel(nextPixel + width);
                }

                /* color it finally */
                pixels[nextPixel] = color;
            }
        }
    }

    @Override
    public void run(ImageProcessor ip) {
        ij.WindowManager.getCurrentImage().getCanvas().addMouseListener(this);
        this.ip = ip;
        this.pixels = (int[])ip.getPixels();
        this.state = new boolean[ip.getPixelCount()];
        this.nextPixels = new LinkedList<Integer>();
    }

    @Override
    public int setup(String arg0, ImagePlus arg1) {
        return DOES_RGB;
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        ij.WindowManager.getCurrentWindow().getCanvas().removeMouseListener(this);
        ij.gui.GenericDialog g = new GenericDialog("Please enter parameters");
        g.addChoice("connection", new String[]{"4-connect", "8-connect"}, "8-connect");
        g.addNumericField("Threshould (0..255)", 0.0, 3);
        g.showDialog();

        boolean connect8 = g.getNextChoice().equals("8-connect");
        threshould = (int) g.getNextNumber();
        doFill(e.getX(), e.getY(), connect8);
        ij.WindowManager.getCurrentImage().draw();
    }
}