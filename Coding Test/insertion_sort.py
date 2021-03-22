import re
import collections
import itertools
import heapq
import bisect
import sys
import functools

A = [5,4,3,2,1]

def insertion_sort(arr):
    i = 1
    while i < len(arr):
        j = i
        while j > 0 and arr[j-1] > arr[j]:
            arr[j-1], arr[j] = arr[j], arr[j-1]
            j -= 1
        i += 1



insertion_sort(A)

print(A)