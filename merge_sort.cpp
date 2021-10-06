/*
* @File      :   merge_sort.cpp
* @Date      :   2021/10/02 21:19:18
* @Author    :   Quiser
* @Email     :   qs0714@foxmail.com
*/
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int random(int a, int b)
{
    /*
    #include <ctime>
    srand((int)time(NULL));
    */
    return rand() % (b - a) + a;
}

vector<int> merge(vector<int> &left, vector<int> &right)
{
    vector<int> result = {};
    while (!left.empty() && !right.empty())
    {
        if (left[0] < right[0])
        {
            result.push_back(left[0]);
            left.erase(left.begin());
        }
        else
        {
            result.push_back(right[0]);
            right.erase(right.begin());
        }
    }
    if (!left.empty())
    {
        for (auto &&i : left)
        {
            result.push_back(i);
        }
    }
    if (!right.empty())
    {
        for (auto &&i : right)
        {
            result.push_back(i);
        }
    }
    return result;
}

vector<int> merge_sort(vector<int> &l)
{
    if (l.size() < 2)
        return l;
    int mid = l.size() / 2;
    vector<int> left(l.begin(), l.begin() + mid), right(l.begin() + mid, l.end());
    left = merge_sort(left);
    right = merge_sort(right);
    l = merge(left, right);
    return l;
}

void showvec(vector<int> &v)
{
    for (auto &&i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    srand((int)time(NULL));
    cout << "Hello World" << endl;
    vector<int> l = {};
    for (int i = 0; i < 100; i++)
    {
        l.push_back(random(0, 100));
    }

    showvec(l);
    merge_sort(l);
    showvec(l);
    return 0;
}