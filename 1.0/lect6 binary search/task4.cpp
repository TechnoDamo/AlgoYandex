#include <iostream>
#include <vector>

using namespace std;

/*
 * Задана отсортированная по неубыванию последовательность из N чисел и число X
 * Задача: необходимо определить индекс первого числа в последовательности, которое
 * >= X. Если такого нет, то вернуть число N.
 * */

int X;
vector<int> v;

int f(int l, int r) {
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

int main()
{
    v = {1, 2, 3, 4, 4, 5, 6, 7, 8};
    X = 8;
    int ans = f(0, v.size()-1);
    cout << ans;
    return 0;
}
