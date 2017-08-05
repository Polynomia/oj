#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def computeAvg(n, k, a, ans=0.):
    for i in range(n):
        ans+=float(min(k,n-k+1,n-i,i+1))*a[i]
    return ans/(n-k+1)

if __name__ == "__main__":
    n, k = list(map(int, input().split()))
    a = list(map(int, input().split()))
    print('%.8f' % computeAvg(n,k,a))