def convert(degree):

	pi = 3.14159265359
	return degree * (pi/180)

degree = float(input("Enter degrees:"))
print("In radians:", convert(degree))