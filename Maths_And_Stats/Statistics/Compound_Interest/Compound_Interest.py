# Python program to calculate Compound Interest


def compoundInterest(principle, rate, time):
    ci = principle * pow((1 + rate/100), time)
    print("Compound Interest is", ci)  

# driver
compoundInterest(1000, 9.50, 3)
