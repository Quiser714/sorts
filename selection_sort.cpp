/*
* @File      :   selection_sort.cpp
* @Date      :   2021/10/02 22:08:49
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

void selection_sort(vector<int> &l)
{
    int m;
    for (int i = 0; i < l.size() - 1; i++)
    {
        m = i;
        for (int j = i; j < l.size(); j++)
        {
            if (l[j] < l[m])
                m = j;
        }
        swap(l[i], l[m]);
    }
}

int main()
{
    srand((int)time(NULL));
    // cout << "Hello World" << endl;
    vector<int> l = {};
    for (int i = 0; i < 100; i++)
    {
        l.push_back(random(0, 100));
    }
    showvec(l);
    selection_sort(l);
    showvec(l);
    return 0;
}