#!/usr/bin/env python
# _*_ coding: utf-8 _*_

# @File    :   bubble_sort.py
# @Author  :   Quiser
# @Email   :   qs0714@foxmail.com
# @Time    :   2021/10/02 21:57:03
from random import randint


def bubble_sort(l):
    changed = True
    while changed:
        changed = False
        for i in range(len(l)-1):
            if l[i] > l[i+1]:
                l[i], l[i+1] = l[i+1], l[i]
                changed = True


def main():
    l = [randint(0, 100) for i in range(100)]
    print(l)
    bubble_sort(l)
    print(l)


if __name__ == '__main__':
    main()
