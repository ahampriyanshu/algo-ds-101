from math import sin, pi

def Rsum(a,b):

    for i in range(1001):
        s = 0.0
        delx = float(b-a)/1000.0
        g = i*delx
        h = (i+1.0)*delx

        y_i = float(sin(a+g))
        y_ii = float(sin(a+h))
        s += 1.0/2.0 * (y_i + y_ii) * delx
        #s += 1/2 * (sin(a+i*delx) + sin(a+(i+1)*delx)) * delx

    return s

print Rsum(0,pi)
