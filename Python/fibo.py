def fib(n):
    first, second = 0,1
    while first < n:
        print(first, end=' ')
        first, second = second, first + second
    print()

def fib2(n):
    result = []
    first, second = 0, 1
    while first < n:
        result.append(first)
        first, second = second, first + second
    return result

if __name__=='__main__':
    import sys
    fib(int(sys.argv[1]))

def fib3(n):
    s=""
    first, second = 0,1
    while first < n:
        s+=str(first)+" "
        first, second = second, first + second
    return s