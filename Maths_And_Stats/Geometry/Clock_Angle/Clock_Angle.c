#include<stdio.h>

int main(){
    int hour,minute;
    float hourAngle,minAngle,angle;
    printf("Enter Hour (12 hour format) -> ");
    scanf("%d",&hour);
    printf("Enter Minute -> ");
    scanf("%d",&minute);

    minAngle = 6 * minute;
    hourAngle = (30 * hour) + (0.5 * minute);

    if(hourAngle>minAngle){
        angle = hourAngle - minAngle;
    }else{
        angle = minAngle - hourAngle;
    }
    if(angle>180){
        angle = 360 - angle;
    }
    printf("Smallest Angle between hour and minute hand for the entered time is -> %0.1f",angle);

    return 0;
}