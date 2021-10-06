/*
* @File      :   count_sort.cpp
* @Date      :   2021/10/06 19:49:38
* @Author    :   Quiser
* @Email     :   qs0714@foxmail.com
*/
#include <iostream>
#include <ctime>
#include <vector>
#define random(a, b) (rand() % (b - a) + a)
using namespace std;

void showvec(vector<int> &v)
{
    for (auto &&i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void count_sort(vector<int> &l)
{
    int minnum = l[0], maxnum = l[0];
    for (auto &&i : l)
    {
        if (minnum > i)
            minnum = i;
        if (maxnum < i)
            maxnum = i;
    }
    vector<int> tmp(maxnum - minnum + 1, 0);
    for (int i = 0; i < l.size(); i++)
    {
        tmp[l[i] - minnum]++;
    }
    for (int i = 0, pos = 0; i < tmp.size(); i++)
    {
        for (int j = 0; j < tmp[i]; j++)
        {
            l[pos++] = i + minnum;
        }
    }
}

int main()
{
    srand((int)time(NULL));
    cout << "Hello World" << endl;
    vector<int> l;
    for (int i = 0; i < 100; i++)
    {
        l.push_back(random(0, 100));
    }
    showvec(l);
    count_sort(l);
    showvec(l);
    return 0;
}