/*
* @File      :   quick_sort.cpp
* @Date      :   2021/10/02 18:07:12
* @Author    :   Quiser
* @Email     :   qs0714@foxmail.com
*/
#include <iostream>
#include <vector>
#include <ctime>
#define random(x, y) (rand() % (y - x) + x)
using namespace std;


void showvec(vector<int> &l)
{
    for (auto &&i : l)
    {
        cout << i << " ";
    }
    cout << endl;
}


void quick_sort(vector<int> &l, int left, int right)
{
    if (right <= left)
        return;
    // for (int i = left; i < right; i++)
    // {
    //     if (l[i + 1] < l[i])
    //         break;
    //     if (i == right - 1)
    //         return;
    // }
    int key = l[left];
    int mark = left;
    for (int i = left+1; i <= right; i++)
    {
        if (l[i] <= key)
        {
            mark++;
            swap(l[i], l[mark]);
        }
    }
    swap(l[left], l[mark]);
    showvec(l);
    quick_sort(l, left, mark - 1);
    quick_sort(l, mark + 1, right);
}

int main()
{
    cout << "start" << endl;
    srand((int)time(0));
    // for (int  i = 0; i < 100; i++)
    // {
    //     cout<<random(5,10)<<" ";
    // }
    // cout<<endl;

    vector<int> l = {};
    for (int i = 0; i < 50; i++)
    {
        l.push_back(random(1,50));
    }

    showvec(l);
    quick_sort(l, 0, l.size() - 1);
    showvec(l);
    cout << "end" << endl;
    return 0;
}