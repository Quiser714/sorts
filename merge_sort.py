#!/usr/bin/env python
# _*_ coding: utf-8 _*_

# @File    :   merge_sort.py
# @Author  :   Quiser
# @Email   :   qs0714@foxmail.com
# @Time    :   2021/10/02 20:02:02

from random import randint

def merge(left, right):
    result = []
    while left and right:
        if(left[0] < right[0]):
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))
    while left:
        result.append(left.pop(0))
    while right:
        result.append(right.pop(0))
    return result


def merge_sort(l):
    if len(l) < 2:
        return l
    mid = int(len(l)/2)
    left = l[:mid]
    right = l[mid:]
    return merge(merge_sort(left), merge_sort(right))


def main():
    l = [randint(0,100) for i in range(100)]
    print(merge_sort(l))


if __name__ == '__main__':
    main()
