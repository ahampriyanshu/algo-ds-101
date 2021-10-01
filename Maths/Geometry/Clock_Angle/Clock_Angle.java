public class Clock_Angle {
	public static int findAngle(int hour, int minute){
		if (hour <0 || minute < 0 || hour >12 || minute > 59){
			System.out.println("Wrong input");
			return -1;
		}
            
		
		if(hour == 12){
			hour = 0;
		}
		if(hour >12){
			hour = hour-12;
		}
		
		int hour_angle = (int)(0.5 * (hour*60 + minute));
        int minute_angle = (int)(6*minute);
		
		int angle = Math.abs(hour_angle - minute_angle);
		
		return angle;
	}
	
	public static void main(String[] args){
		System.out.println(findAngle(10,12));
	}
}

//Maths_And_Stats => Geometry => Clock_Angle => Clock_Angle.java