#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Mar 21 10:36:20 2020

@author: ravisane
"""
import numpy as np
Array = np.random.random((10))*100 - 50

def insert_sort(A):
    for j in range(1, len(A)):
        key = A[j]
        i = j - 1
        while i >= 0 and A[i] > key:
            A[i+1] = A[i]
            i -= 1
        A[i+1] = key
    return A

print(insert_sort(Array))

#%%
Array = np.random.random((10))*100

def merge(A, p, q, r):
    #left = np.zeros((q-p+2)) + 1000
    #right = np.zeros((r-q+1)) + 1000
    #left[0:-1] = A[p:q+1]
    #right[0:-1] = A[q+1:r+1]
    left = np.concatenate((A[p:q+1], np.array([10000])))
    right = np.concatenate((A[q+1:r+1], np.array([10000])))
    
    i = 0
    j = 0
    
    for k in range(p, r+1):
        if left[i] <= right[j]:
            A[k] = left[i]
            i += 1
        else:
            A[k] = right[j]
            j += 1
    return A

def merge_sort(A, low, high):
    if low < high:
        mid = (low + high)//2
        A = merge_sort(A, low, mid)
        A = merge_sort(A, mid+1, high)
        A = merge(A, low, mid, high)
    return A

print(merge_sort(Array, 0, len(Array)-1))

#%%