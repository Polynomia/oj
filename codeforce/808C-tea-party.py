#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import numpy as np


def pourTea(a, b, w, n):
    last = a - b
    w -= sum(b)
    ranked = np.argsort(-a)
    for i in range(n):
        if w > last[ranked[i]]:
            w -= last[ranked[i]]
            b[ranked[i]] = a[ranked[i]]
            last[ranked[i]] = 0
        else:
            b[ranked[i]] += w
            last[ranked[i]] -= w
            return


if __name__ == "__main__":
    n, w = list(map(int, input().split()))
    a = np.array(list(map(int, input().split())))
    b = np.array(list(map(lambda x: np.math.ceil(float(x) / 2.0), a)))
    if sum(b) > w:
        print(-1)
    else:
        pourTea(a, b, w, n)
        for i in b:
            print(i, end=' ')
