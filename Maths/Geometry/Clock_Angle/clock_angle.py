"""
author- Ose Oaiya (esoiya)

Submission Description:
Clock angle problems relate two different measurements: angles and time.
The angle is typically measured in degrees from the mark of number 12 clockwise.
The time is usually based on a 12-hour clock.
The hour hand of a normal 12-hour analogue clock turns 360° in 12 hours (720 minutes) or 0.5° per minute.
"""


def clock_angle(hour, minute):
    """
    Calculate Clock Angle between hour hand and minute hand

    param hour: hour
    type: int

    param minute: number of minutes pas the hour
    type: int

    return: the smallest angle of the two possible angles
    """

    if (hour < 0 or minute < 0 or hour > 12 or minute > 59):
        raise ValueError("Invalid Input: Time is based on a 12-hour clock")

    if hour == 12:
        hour = 0
    
    # calculate the angle moved by the hour and minute hands
    # with reference to 12:00
    hour_angle = 0.5 * (hour * 60 + minute)
    minute_angle = 6 * minute

    # Find the difference between the two angles
    angle = abs(minute_angle - hour_angle)

    return angle
