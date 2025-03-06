import numpy as np
from numpy.polynomial import Polynomial
import matplotlib.pyplot as plt
import matrix

def lagrange(points, x):

    """ Lagrange interpolation
        x: test value
        points: lisft of x,y pairs  """

    n = len(points)
    L = np.zeros(n)
    for i in range (n):
        xi, yi = points[i]
        L[i] = 1                                 
        for k in range(n):
            xk,yk = points[k]
            if k != i:
                L[i] *= float(x-xk)/float(xi-xk)   
        L[i] = yi*L[i]                            
    return sum(L)

def newton(points, x):

    """ Newton interpolation 
        x: test value
        points: list of x,y pairs"""
    n = len(points)
    A = np.zeros((n,n))
    A = dividedDifference(points)
    Newton = 0
    for i in range(n):
        temp = 1
        for j in range(i):
            temp *=(x-points[j][0])
        Newton +=A[i][i]*temp

    return Newton

def monomial(points, b):

    """ Monomial interpolation"""

    n = len(points)
    V = np.array(vandermonde(points.take(0, axis=1)))
    x = matrix.partialPivot(V, b)
    print(np.array(x))

#Helper methods

def dividedDifference(points):

    """ Divided differences method"""

    n = len(points)
    A = np.zeros((n,n))

    for col in range(n):
        for row in range(col,n):
            if col == 0:                    # fills first columnn with y values
                A[row,0] = points[row][1]
            else:
                A[row][col] = (A[row][col-1]-A[row-1][col-1])/(points[row][0] - points[row-col][0])
    
    return A

def vandermonde(A):

    """ Monomial interpolation"""

    n = len(A)

    V = [[xi**i for i in range(n)] for xi in A]

    return V

def driver():
    data = np.array([[1,1], [3,9], [6,36], [10,100], [12,144]])
    z=[]
    for i in range(13):
        z.append([i, np.round(lagrange(data, i), 10)])
    w=[]
    for i in range(13):
        w.append([i, np.round(newton(data, i), 10)])

#    print(z)
#    output: vector of 12 2 element lists
    z = np.array(z)
    w = np.array(w)
    print(z)
#    output:    12x2 matrix 
    plt.plot(data[:,0], data[:,1], 'r', 
             z[:,0], z[:,1], 'b', 
             w[:,0], w[:,1], 'c')

    plt.show()

#driver()

data = np.array([[1,1], [3,9], [6,36], [10,100], [12,144]])
b = np.array([[1],[9],[36],[100],[144]])
monomial(data, b)
#vandermonde(data)