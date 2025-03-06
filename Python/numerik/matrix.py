# partialPivot: https://www.youtube.com/watch?v=DiZ0zSzZj1g
# https://www.quantstart.com/articles/LU-Decomposition-in-Python-and-NumPy/
#

import numpy as np
import pprint

def partialPivot(A, b):

    # checks
    # A must be nxn
    # rows of b must match rows of a
    # b must have only 1 column

    if A.shape[0] != A.shape[1]:
        raise ValueError("Error: Matrix A must be square")
        return

    if b.shape[1] > 1 or b.shape[0] != A.shape[0]:
        
        raise ValueError("Error: wrong size of constant vector b")
        return

    n = len (b)
    m = n-1
    i = 0
    x = np.zeros(n)

    # creating an augmented matrix: 

    Aug = np.concatenate((A, b), axis=1, dtype=float)

    while i < n:

        for p in range (i+1, n):                            #partial pivoting
            if abs(Aug[i,i]) < abs(Aug[p,i]):
                Aug[[p,i]] = Aug[[i,p]]

        
        if Aug[i, i] == 0.0:
            raise ValueError("Error: Singular Matrix")
            return               

        for j in range(i+1, n):                             #forward elimination
            scaling_factor = Aug[j][i] / Aug[i][i]
            Aug[j] = Aug[j] - (scaling_factor * Aug[i])
            print(Aug)

        i +=1
    
    #backward substitution

    x[m] = Aug[m][n] / Aug[m][m]

    for k in range (n-2, -1, -1):
        x[k] = Aug[k][n]

        for j in range(k+1, n):
            x[k] = x[k] - Aug[k][j] * x[j]
        
        x[k] = x[k] / Aug[k][k]

    return x


######################## LU Decomposition ########################
""" LU decomposition in scipy

import scipy
import scipy.linalg

A = scipy.array([values],[values],[values],...)
P,L,U = scipy.linalg.lu(A)

"""

def LU(A, b):
    n = len(A)

    #create L and U
    #np.zeros in pure python
    L = [[0.0] * n for i in range(n)]
    U = [[0.0] * n for i in range(n)]

    #create P and PA
    P = pivot_matrix(A)
    PA = np.dot(P,A)

    #LU decomposition
    for j in range(n):
        
        #set diagonal elements of L to 1
        L[j][j]=1.0

        # u_{ij} = a_{ij} - \sum_{k=1}^{i-1} u_{kj} l_{ik}
        for i in range (j+1):
            s1 = sum(U[k][j] * L[i][k] for k in range(i))
            U[i][j] = PA[i][j] - s1
        
        # l_{ij} = \frac{1}{u_{jj}} (a_{ij} - \sum_{k=1}^{j-1} u_{kj} l_{ik} ) 
        for i in range(j, n):
            s2 = sum(U[k][j] * L[i][k] for k in range(j))
            L[i][j] = (PA[i][j] - s2) / U[j][j]
    
    return (P, L, U)

    return


def pivot_matrix(M):
    
    """returns a  pivoting matrix for M"""

    n = len(M)

    #create nxn identity matrix
    Id = [[float(i==j) for i in range(n)] for j in range(n)]

    # rearrange Id such that the largest element of each column of M is placed 
    # on the diagonal of M

    for j in range(n):
        row  = max(range(j, n), key=lambda i: abs(M[i][j]))
        #Swap rows
        if j != row:
            Id[j], Id[row] = Id[row], Id[j]

    return Id

################### Gram-Schmidt ###################

def gram_schmidt(A):

    """ Gram-Schmidt orthogonalization """

    n = len(A)

    for i in range(n):

        v = A[:, i]         #   v is ith column of A

        #orthogonalization:     v = v - <v,w_j> * w_j
        for j in range(i):
            v = v - np.dot(A[:, i], A[:, j]) * A[:, j]
        
        # linear independence test
        if np.array_equal(v, np.zeros(n)):
            raise ValueError("Error: Matrix is linearly dependent")

        #normalization          v = v / ||v|| (euclidean norm)
        v = v / np.sqrt(np.dot(v,v))
        
        #replace the ith column with orthonormal vector v
        A[:, i] = v

    return A

