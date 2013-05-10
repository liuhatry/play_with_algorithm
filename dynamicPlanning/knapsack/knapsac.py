#!/usr/bin/env python2

def max(a, b):
    if a > b:
        return a
    else:
        return b

if __name__ == "__main__":
    nPack = 3
    nMaxVolume = 10
    weight = [3,4,5]
    value = [4,5,6]
    record = [0,0,0,0,0,0,0,0,0,0,0]
    for i in range(nPack):
        for j in range(nMaxVolume, 0, -1):
            if j-weight[i] >= 0:
                record[j] = max(record[j], record[j-weight[i]]+value[i])
        for j in range(nMaxVolume+1):
            print record[j],
        print

