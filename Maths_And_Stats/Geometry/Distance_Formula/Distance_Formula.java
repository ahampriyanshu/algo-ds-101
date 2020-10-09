public class Distance_Formula {
	public static double findDistance(double x1, double y1 , double x2, double y2){
		double length = x2 - x1;
		double height = y2 - y1;
		
		return Math.sqrt(length*length + height*height);
	}
}