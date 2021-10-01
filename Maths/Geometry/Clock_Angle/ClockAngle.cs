using System;

namespace clock_angle
{
    class ClockAngle
    {
        static void Main(string[] args)
        {
	    Console.WriteLine("Enter hours:");
            int hours = Convert.ToInt32(Console.ReadLine());
	    Console.WriteLine("Enter minutes:");
            int minutes = Convert.ToInt32(Console.ReadLine());
            double angle = findAngleBetweenHourAndMinuteHand(hours, minutes);
            Console.WriteLine(angle);
        }
        
        private static double findAngleBetweenHourAndMinuteHand(int hours, int minutes)
        {
            if(hours<0||minutes<0||hours>12||minutes>59)
            {
                Console.WriteLine("Invalid input");
                return 0;
            }
            double angleHoursHandMoved = 0.5*((hours*60)+minutes);
            double angleMinutesHandMoved = 6*minutes;
            return Math.Abs(angleHoursHandMoved-angleMinutesHandMoved);
        }
    }
}
