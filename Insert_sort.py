#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Mar 13 08:35:51 2020

@author: ravisane
"""
iteration = 0
def insert_sort(A):
    #global iteration
    for j in range(1, len(A)):
        key = A[j]
        i = j - 1
        while i>=0 and A[i] > key:
    #        iteration += 1
            A[i+1] = A[i]
            i -= 1
        A[i+1] = key
        
    return A

#%%
def selection_sort(A):
    #global iteration
    for j in range(0, len(A)-1):
        smallest = j
        for i in range(j+1, len(A)):
    #        iteration += 1
            if A[i] < A[smallest]:
                smallest = i
        A[smallest], A[j] = A[j], A[smallest]
    
    return A

#%%
def bubble_sort(A):
    # Traverse through all array elements
    for i in range(len(A)): 
        # Last i elements are already in place
        for j in range(0, len(A)-i-1):
            if A[j] > A[j+1]:
                A[j], A[j+1] = A[j+1], A[j]
    return A
 
#%%
import numpy as np
Array = np.linspace(100, 1, 100)
print(f"worst case scenario:\n{Array}")
print(bubble_sort(Array))
#print(f"worst case scenario iteration: {iteration}")

#%% Merging
iteration = 0
def Merge(A, p, q, r):
    global iteration
    n1 = q - p + 1
    n2 = r - q
    L = np.zeros((n1 + 1))
    R = np.zeros((n2 + 1))
    
    for i in range(n1):
        L[i] = A[i + p] 
        
    for i in range(n2):
        R[i] = A[i + q + 1] 
    
    L[n1] = 1000
    R[n2] = 1000
    i = 0
    j = 0
    for k in range(p, r+1):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    iteration += 1
    return A

def Merge_sort(A, low, high):
    global iteration
    if low < high:
        mid = (low + high)// 2
        A = Merge_sort(A, low, mid)
        A = Merge_sort(A, mid+1, high)
        A = Merge(A, low, mid, high)
    iteration += 1
    return A

A = np.linspace(1000, 1, 1000) 
print(f"worst case scenario:\n{A}")
print(Merge_sort(A, 0, len(A)-1))
print(iteration)

#%% linear search
def linear_search(A, x):
    for i in range(len(A)):
        if A[i] == x:
            return i
    return None
A = np.linspace(1000, 1, 1000)
print(linear_search(A, 90))
print(linear_search(A, 90.5))

#%%
