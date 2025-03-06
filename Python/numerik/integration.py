import math
import numpy as np

def trapez(lower:int, upper:int, n:int, f):

    """Trapezoidal rule for numerical integration"""

    sum = f(lower) + f(upper)

    h = (upper - lower)/n

    for i in range(1, n):
        sum += 2*f(lower+i*h)

    return (h/2) * sum    

def simpsonOneThird(lower:int, upper:int, n:int, f):

    """Simpson's 1/3 rule for numerical integration"""

    sum = f(lower) + f(upper)

    h = (upper - lower) / n

    for i in range(1,n-1):
        if i%2 == 0:
            sum += 2*f(lower + i*h)
        else:
            sum += 4*f(lower + i*h)
    return (upper-lower)/(3*n)*sum

def simpsonThreeEight(lower:int, upper:int, n:int, vector:list, f):

    """Simpson's 3/8 rule for numerical integration"""

    sum = f(vector[0]) + f(vector[-1])

    h = (upper - lower) / n

    for i in range(1, n-1):
        if i%3 == 0:
            sum += 2*f(lower + i*h)
        else:
            sum += 3*f(lower + i*h)

    return 3*(upper-lower)/(8*n)*sum

def midpoint(lower:int, upper:int, n:int, f):
    
    sum=0

    for i in range (0,n):
        sum += f( (i*(upper-lower)/n + (i+1)(upper-lower)/n)/2 )*((upper-lower)/n)

    return sum


def romberg(lower:int, upper:int, f):
    
    I=np.zeros((10,10))
    ea=100; n=1; i = 1
    I[1,1] = trapez(lower, upper, n, f)

    while ea > 0.001:
        n = 2**i
        I[i+1, 1] = trapez(lower, upper, n, f)

        for k in range (2, i+2):
            j = 2 + i - k
            I[j, k] = (4 ** (k-1) * I[j+1, k-1] - I[j, k-1] ) / (4 ** (k-1) - 1)

        ea = abs((I[1, i+1] - I[2, i]) / I[1, i+1]) * 100
        et = abs((1.71828 - I[1, i+1]) / 1.7182) * 100

        print('%f \t %f \t %f \t %f' % (i, ea, et, I[1, i+1]))

        i += 1

romberg (0, 1, (lambda x: math.exp(math.cos(x**3))))