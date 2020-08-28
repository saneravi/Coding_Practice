#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Mar 13 10:27:23 2020

@author: ravisane
"""
def bit_add(A, B):
    carry = 0
    C = []
    for i in range(len(A)):
        C.append((A[i] + B[i] + carry)%2)
        carry = (A[i] + B[i] + carry)//2
    C.append(carry)
    return C

num1 = [0, 1, 0, 1, 1, 1, 0, 0, 0]
num2 = [0, 1, 0, 1, 0, 1, 1, 1, 1]
print(num1[::-1])
print(num2[::-1])
print(bit_add(num1, num2)[::-1])