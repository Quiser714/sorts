/*
* @File      :   bubble_sort.cpp
* @Date      :   2021/10/02 22:00:57
* @Author    :   Quiser
* @Email     :   qs0714@foxmail.com
*/
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
int random(int a, int b)
{
    return rand() % (b - a) + a;
}
void showvec(vector<int> &v)
{
    for (auto &&i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void bubble_sort(vector<int> &l)
{
    bool changed = true;
    while (changed)
    {
        changed = false;
        for (int i = 0; i < l.size() - 1; i++)
        {
            if (l[i] > l[i + 1])
            {
                swap(l[i], l[i + 1]);
                changed = true;
            }
        }
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
    bubble_sort(l);
    showvec(l);
    return 0;
}