#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Mar 21 12:37:59 2020

@author: ravisane
"""

import numpy as np
array = np.random.random((100))*100

#%%
'''
The procedure H IRE -A SSISTANT , given below, expresses this strategy for hiring
in pseudocode. It assumes that the candidates for the office assistant job are num-
bered 1 through n. The procedure assumes that you are able to, after interviewing
candidate i, determine whether candidate i is the best candidate you have seen so
far. To initialize, the procedure creates a dummy candidate, numbered 0, who is
less qualified than each of the other candidates.
'''
def linear(A):
    cost = 0
    great = 0
    for i in range(len(A)):
        cost += 10        # cost of interviewing
        if A[i] > great:
            great = A[i]
            cost += 100 # cost of hiring
    print(great)    
    print(cost,'\n\n')

#%%
'''
In the hiring problem, it may seem as if the candidates are being presented to us
in a random order, but we have no way of knowing whether or not they really are.
Thus, in order to develop a randomized algorithm for the hiring problem, we must
have greater control over the order in which we interview the candidates. We will,
therefore, change the model slightly. We say that the employment agency has n
candidates, and they send us a list of the candidates in advance. On each day, we
choose, randomly, which candidate to interview. Although we know nothing about
the candidates (besides their names), we have made a significant change. Instead
of relying on a guess that the candidates come to us in a random order, we have
instead gained control of the process and enforced a random order.
'''



def random_algo(A):
    cost = 0
    great = 0
    while len(A):
        index = np.random.randint(0, len(A), size = 1)
        cost += 10             # cost of interviewing
        if A[index] > great:
            great = A[index]
            cost += 100        # cost of hiring
        A = np.delete(A, index)
                  
    print(great[0])       
    print(cost,'\n\n')

#%%
#print(array,'\n\n')    
random_algo(array)
linear(array)

random_algo(np.sort(array))
linear(np.sort(array))

print(max(array))            
        
    
