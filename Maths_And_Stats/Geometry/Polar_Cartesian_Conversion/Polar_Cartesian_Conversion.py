import math

def polarToCart(r, theta):
    
    theta = theta*math.pi/180.0
    
    x = r*math.cos(theta)
    y = r*math.sin(theta)
    
    return (x, y)