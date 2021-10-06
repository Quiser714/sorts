#!/usr/bin/env python
# _*_ coding: utf-8 _*_

# @File    :   heap_sort.py
# @Author  :   Quiser
# @Email   :   qs0714@foxmail.com
# @Time    :   2021/10/06 19:06:46
from random import randint


def heapify(tree, length, n):
    c1 = n*2+1
    c2 = n*2+2
    maxpos = n
    if c1 < length and tree[c1] > tree[maxpos]:
        maxpos = c1
    if c2 < length and tree[c2] > tree[maxpos]:
        maxpos = c2
    if maxpos != n:
        tree[n], tree[maxpos] = tree[maxpos], tree[n]
        heapify(tree, length, maxpos)


def build_heap(tree, length):
    finalParent = int((length-2)/2)
    for i in range(finalParent, -1, -1):
        heapify(tree, length, i)


def heap_sort(tree):
    for i in range(len(tree), 0, -1):
        build_heap(tree, i)
        tree[0], tree[i-1] = tree[i-1], tree[0]


def main():
    print('hello world')
    l = [randint(1, 200) for _ in range(200)]
    print(l)
    heap_sort(l)
    print(l)


if __name__ == '__main__':
    main()
