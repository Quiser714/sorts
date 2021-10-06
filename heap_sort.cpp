/*
* @File      :   heap_sort.cpp
* @Date      :   2021/10/06 19:22:06
* @Author    :   Quiser
* @Email     :   qs0714@foxmail.com
*/
#include <iostream>
#include <ctime>
#include <vector>
#define random(a, b) (rand() % (b - a) + a)
using namespace std;

template <class T>
void showvec(vector<T> &v)
{
    for (auto &&i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

template <class T>
void heapify(vector<T> &tree, int length, int pos)
{
    int c1 = pos * 2 + 1, c2 = pos * 2 + 2, maxpos = pos;
    if (c1 < length && tree[c1] > tree[maxpos])
        maxpos = c1;
    if (c2 < length && tree[c2] > tree[maxpos])
        maxpos = c2;
    if (maxpos != pos)
    {
        swap(tree[pos], tree[maxpos]);
        heapify(tree, length, maxpos);
    }
}

template <class T>
void build_heap(vector<T> &tree, int length)
{
    int finalParent = static_cast<int>((length - 2) / 2);
    for (int i = finalParent; i >= 0; i--)
    {
        heapify(tree, length, i);
    }
}

template <class T>
void heap_sort(vector<T> &tree)
{
    for (int i = tree.size() - 1; i >= 0; i--)
    {
        build_heap(tree, i + 1);
        swap(tree[0], tree[i]);
    }
}

int main()
{
    srand((int)time(NULL));
    cout << "Hello World" << endl;
    vector<int> l = {};
    for (int i = 0; i < 50; i++)
    {
        l.push_back(random(1,100));
    }
    showvec(l);
    heap_sort(l);
    showvec(l);
    return 0;
}