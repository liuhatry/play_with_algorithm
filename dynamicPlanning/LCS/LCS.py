#!/usr/bin/env python2

def LCSLength(x, y, c, b):
    m = len(x)
    n = len(y)
    for i in range(m+1):
        c[i][0] = 0
    for j in range(n+1):
        c[0][j] = 0

    for i in range(1, m+1):
        for j in range(1, n+1):
            if x[i-1] == y[j-1]:
                c[i][j] = c[i-1][j-1] + 1
                b[i][j] = 0
            elif c[i-1][j] >= c[i][j-1]:
                c[i][j] = c[i-1][j]
                b[i][j] = 1
            else:
                c[i][j] = c[i][j-1]
                b[i][j] = -1

def printLCS(b, x, i, j):
    if i == 0 or j == 0:
        return None
    if b[i][j] == 0:
        printLCS(b, x, i-1, j-1)
        print x[i-1]
    elif b[i][j] == 1:
        printLCS(b, x, i-1, j)
    else:
        printLCS(b, x, i, j-1)

if __name__ == '__main__':
    x = ['a', 'f' , 'c','d']
    y = ['a', 'b' , 'c','d']
    c = [[0 for col in range(5)] for row in range(5)]
    b = [[0 for col in range(5)] for row in range(5)]
    LCSLength(x, y, c, b)
    print c[4][4]
    for i in range(5):
        print b[i]
    print
    for i in range(5):
        print c[i]
    printLCS(b,x,4,4)
