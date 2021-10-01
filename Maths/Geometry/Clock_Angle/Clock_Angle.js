var hour = prompt("Enter Hour (12 hour format) -> ");
var minute = prompt("Enter Minute -> ");
var hourAngle,minAngle,angle;

minAngle = 6 * minute;
hrAngle = (30 * hour) + (0.5 * minute);

if(hrAngle>minAngle){
    angle = hrAngle - minAngle;
}else{
    angle = minAngle - hrAngle;
}
if(angle>180){
    angle = 360 - angle;
}
alert("Smallest Angle between hour and minute hand for the entered time is -> " + angle);