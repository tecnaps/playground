import numpy as np


b = np.array([1,-3,-6])

A = np.array([[1,-2,-3], [1,0,4], [-1,0,0]])

print(np.linalg.solve(A,b))

A = np.array([[1,-2,-3], [1,0,4], [0,-1,0]])

print(np.linalg.solve(A,b))

A = np.array([[1,-2,-3], [1,0,4], [0,0,-1]])

print(np.linalg.solve(A,b))

A = np.array([[1,-2,-3], [-1,0,0], [0,-1,0]])

print(np.linalg.solve(A,b))

A = np.array([[1,-2,-3], [-1,0,0], [0,0,-1]])

print(np.linalg.solve(A,b))

A = np.array([[1,-2,-3], [0,-1,0], [0,0,-1]])

print(np.linalg.solve(A,b))

A = np.array([[1,0,4], [-1,0,0], [0,-1,0]])

print(np.linalg.solve(A,b))

A = np.array([[1,0,4], [0,-1,0], [0,0,-1]])

print(np.linalg.solve(A,b))

A = np.array([[-1,0,0], [0,-1,0], [0,0,-1]])

print(np.linalg.solve(A,b))