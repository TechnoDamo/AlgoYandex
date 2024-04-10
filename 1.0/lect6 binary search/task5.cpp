#include <iostream>
#include <vector>

using namespace std;

/*
 * Задана отсортированная по неубыванию последовательность из N чисел и число X
 * Задача: необходимо определить, сколько раз число Х входит в последовательность.
 * */

int X;
vector<int> v;

int findFirstX(int l, int r) {
    int M;
    while (l < r) {
        M = (l + r) / 2;
        if (v[M] >= X) {
            r = M;
        } else {
            l = M + 1;
        }
    }
    return l;
}

int findLastX(int l, int r) {
    int M;
    while (l < r) {
        M = (l + r + 1) / 2;
        if (v[M] <= X) {
            l = M;
        } else {
            r = M - 1;
        }
    }
    return r;
}

int main()
{
    v = {1, 2, 3, 4, 4, 5, 6, 6, 6, 7, 8};
    X = 6;
    int ans = findLastX(0, v.size()-1) - findFirstX(0, v.size()-1) + 1;
    cout << ans;
    return 0;
}
