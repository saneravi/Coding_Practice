#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Mar 13 15:27:57 2020

@author: ravisane
"""

def max_cross_subarray(A, low, mid, high):
    left_sum = -1000
    summ = 0
    
    for i in range(mid, low-1, -1):
        summ += A[i]
        if summ > left_sum:
            left_sum = summ
            left_max = i
     
    right_sum = -1000
    summ = 0
    
    for i in range(mid+1, high+1):
        summ += A[i]
        if summ > right_sum:
            right_sum = summ
            right_max = i
            
    return left_max, right_max, left_sum+right_sum

def max_subarray(A, low, high):
    #print(A, low, high)
    if low == high:
        return low, high, A[low]
    
    else:
        mid = (low + high)//2
        left_low, left_high, left_max_sum = max_subarray(A, low, mid)
        right_low, right_high, right_max_sum = max_subarray(A, mid+1, high)
        cross_low, cross_high, cross_max_sum = max_cross_subarray(A, low, mid, high)
        
    if left_max_sum > right_max_sum and left_max_sum > cross_max_sum:
        return left_low, left_high, left_max_sum
    elif right_max_sum > left_max_sum and right_max_sum > cross_max_sum:
        return right_low, right_high, right_max_sum
    else:
        return cross_low, cross_high, cross_max_sum

#%%

import numpy as np
arr = np.random.rand(100)*100 - 50
print(arr)
l, h, s = max_subarray(arr, 0, len(arr)-1)
print(f"lower index = {l}, higher index = {h}, sum = {s}")

#%% brute force method

def brute_force(A):
    max_sum = -1000
    for j in range(len(A)):
        summ = 0
        for i in range(j, len(A)):
            summ += A[i]
            if summ > max_sum:
                max_sum = summ
                low = j
                high = i
        
    return low, high, max_sum

l, h, s = brute_force(arr)
print(f"lower index = {l}, higher index = {h}, sum = {s}")
    
#%% linear method FASTEST

def max_subarray_linear(A, low, high):
    left = 0
    right = 0
    max_sum = A[low]
    temp_sum = 0
    temp_left = 0
    
    for i in range(low, high):
        if A[i] > (temp_sum + A[i]):
            temp_sum = A[i]
            temp_left = i
        else:
            temp_sum += A[i]
        
        if temp_sum > max_sum:
            max_sum = temp_sum
            right = i
            left = temp_left
            
    return left, right, max_sum

l, h, s = max_subarray_linear(arr, 0, len(arr))
print(f"lower index = {l}, higher index = {h}, sum = {s}")

#%% compare 3 methods
import time
from datetime import timedelta

for i in range(2, 50):
    print("\n\n",i)
    arr = np.random.rand(i)*100 - 50
    
    start_time = time.monotonic()
    l, h, s = brute_force(arr)
    print(f"For Brute-Force method, \nlower index = {l}, higher index = {h}, sum = {s}")
    end_time = time.monotonic()
    print(timedelta(seconds=end_time - start_time))
    
    start_time = time.monotonic()
    l, h, s = max_subarray(arr, 0, len(arr)-1)
    print(f"For divide-n-conquere method, \nlower index = {l}, higher index = {h}, sum = {s}")
    end_time = time.monotonic()
    print(timedelta(seconds=end_time - start_time))
    
    start_time = time.monotonic()
    l, h, s = max_subarray_linear(arr, 0, len(arr))
    print(f"For linear method, \nlower index = {l}, higher index = {h}, sum = {s}")
    end_time = time.monotonic()
    print(timedelta(seconds=end_time - start_time))
