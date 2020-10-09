/**
 * Compile and execute: java -classpath StackStatic.jar StackStatic.java
 * Stack implementation in language C <https://github.com/jytaloramon/data-structure/tree/master/stack> 
 *
 * @author  Ytalo Ramon
*/

package Stack;

public class StackStatic {
    public static void main(String[] args) {

        String value, inputs_operations[][] = { { "1", "Orange" }, { "1", "Apple" }, { "4", "Orange" }, { "0", "" },
                { "1", "Pineapple" }, { "2", "" }, { "0", "" }, { "0", "" }, { "0", "" }, { "1", "Avocado" },
                { "1", "Strawberry" }, { "2", "" }, { "1", "Guava" }, { "1", "Star Fruit" }, { "2", "" },
                { "1", "Banana" }, { "4", "Banana" }, { "2", "" }, { "1", "Acerola" }, { "4", "Guava" } };

        Stack stack = new Stack(5);

        System.out.println("---------- Static Stack ----------\n");

        for (String[] input_op : inputs_operations) {
            try {
                switch (input_op[0]) {
                    case "0":
                        System.out.print("POP: " + input_op[1]);
                        value = stack.pop();
                        System.out.println(value);
                        break;

                    case "1":
                        System.out.print("PUSH: " + input_op[1]);
                        stack.push(input_op[1]);
                        System.out.println(" => OK!");
                        break;

                    case "2":
                        System.out.print("PEEK: " + input_op[1]);
                        value = stack.peek();
                        System.out.println(value);
                        break;

                    default:
                        System.out.print("SEARCH: " + input_op[1]);
                        int rs = stack.search(input_op[1]);
                        System.out.println(rs != -1 ? " - OFFSET (" + rs + ")" : "Not Found!");

                }
            } catch (Exception e) {
                System.out.println();
                System.out.println(e.getMessage());
            }

            System.out.println();
            System.out.println(stack);
            System.out.println("\n");
        }

    }

}

/**
 * Stack
 */
class Stack {

    private int p_top; // index of the item top.
    private int length; // Stack length, max of items.
    private String items[]; // Array of item.

    /**
     * Constructor of class.
     * 
     * @param length max of itens in stack.
     */
    public Stack(int length) {
        this.p_top = -1;
        this.length = length;
        this.items = new String[length];
    }

    /**
     * Check if the stack is empty.
     * 
     * @return or true if empty or false if not empty.
     */
    public boolean isEmpty() {
        return this.p_top == -1;
    }

    /**
     * Check if the stack is full.
     * 
     * @return or true if full or false if not full.
     */
    public boolean isFull() {
        return this.p_top == this.length - 1;
    }

    /**
     * Push a new item onto the stack.
     * 
     * @param value insertion value.
     * @throws Exception if it is not possible to insert - stack is full.
     */
    public void push(String value) throws Exception {
        if (this.isFull())
            throw new Exception("Full Stack, impossible add. item!");

        this.pTopIncrement();
        this.items[this.p_top] = value;
    }

    /**
     * Remove the item at the top of the stack.
     * 
     * @return the removed value.
     * @throws Exception if it is not possible to remove - stack empty.
     */
    public String pop() throws Exception {
        if (this.isEmpty())
            throw new Exception("Empty Stack, impossible remove item!");

        String value = this.items[this.p_top];
        this.items[this.p_top] = null;
        this.pTopDecrement();
        return value;
    }

    /**
     * Removes all items from the Stack.
     */
    public void clear() {
        for (int i = this.p_top; i >= 0; i--)
            this.items[i] = null;

        this.p_top = -1;
    }

    /**
     * Return the item on the top of the stack. Not remove value.
     * 
     * @return the value at the top.
     * @throws Exception if it is not possible to remove - stack empty.
     */
    public String peek() throws Exception {
        if (this.isEmpty())
            throw new Exception("Empty Stack, impossible remove item!");

        return this.items[this.p_top];
    }

    /**
     * Search for value in the stack.
     * 
     * @param value sought value
     * @return if found, its offset from the top of the stack is returned.
     *         Otherwise, -1 is returned.
     */
    public int search(String value) {
        for (int i = this.p_top; i >= 0; i--) {
            if (this.items[i].equalsIgnoreCase(value))
                return this.p_top - i;
        }

        return -1;
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder("Status Stack:\n");
        for (int i = this.p_top; i >= 0; i--)
            stringBuilder.append("| " + (this.p_top - i) + " - " + this.items[i] + "\n");
        stringBuilder.append("------------------\n");

        return stringBuilder.toString();
    }

    /**
     * Increment value p_top
     */
    private void pTopIncrement() {
        this.p_top++;
    }

    /**
     * Decrement value p_top
     */
    private void pTopDecrement() {
        this.p_top--;
    }

}