import math

def Easter(Year):
    # Gauss Easter Algorithm
    a = Year % 19
    b = Year % 4
    c = Year % 7
    k = math.floor(Year / 100)
    p = math.floor((13 + 8 * k) / 25)
    q = k/4
    m = (15 - p + k - q) % 30
    n = (4 + k - q) % 7
    d = (19 * a + m) % 30
    e = (2 * b + 4 * c + 6 * d + n) % 7
    days = (22 + d + e)
  
    # d is 29
    if ((d == 29) and (e == 6)):
        print(Year, "- 04 -19")
        return
    # d is 28
    elif ((d == 28) and (e == 6)):
        print(Year, "- 04 -18")
        return
    else:
        # If days > 31, April
        if (days > 31):
            print(Year, "- 04 -", int(days - 31))
            return
        else:
            # Otherwise, March
            print(Year, "- 03 -", days)
            return




Year = 2012
Easter(Year)





