#!/usr/bin/env python3

from random import randint

def qsort(l,left,right):
    if right - left <= 0:
        return
    for i in range(left,right):
        if l[i+1]<l[i]:
            break
        if i == right-1:
            return
    key = l[randint(left,right)]
    i=left
    j=right
    while True:
        while i < j and l[i] < key:
            i+=1
        while i < j and l[j] >= key:
            j-=1
        if j <= i:
            break
        l[i],l[j]=l[j],l[i]
    #print(left,right,key,i,j,l)
    qsort(l,left,i-1)
    qsort(l,i,right)
l = [randint(1,200) for i in range(200)]
print(l)
qsort(l,0,len(l)-1)
print(l)

