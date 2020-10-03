def CheckPythagoreanTriplet(a, b, c):
    if not a or not b or not c:
        return
    elif a ** 2 == b ** 2 + c ** 2:
        return a

    elif b ** 2 == a ** 2 + c ** 2:
        return b

    elif c ** 2 == a ** 2 + b ** 2:
        return c

    return

print("Enter the sides of right angled triangle: ")
x = int(input())
y = int(input())
z = int(input())

hypotenuse = CheckPythagoreanTriplet(x, y, z)

if hypotenuse == x:
    print("{0}, {1}, {2} are the sides of a right angled triangle with  {0} as hypotenuse and {1}, {2} as legs"
          .format(x, y, z))

elif hypotenuse == y:
    print("{1}, {0}, {2} are the sides of a right angled triangle with  {0} as hypotenuse and {1}, {2} as legs"
          .format(y, x, z))

elif hypotenuse == z:
    print("{1}, {2}, {0} are the sides of a right angled triangle with {0} as hypotenuse and {1}, {2} as legs"
          .format(z, x, y))

else:
    print("{}, {}, {} are not the sides of a right angled triangle".format(x, y, z))
