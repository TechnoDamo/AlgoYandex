#include <iostream>

using namespace std;

/*
 * Михаил читает лекции по алгоритмам. За кадром стоит доска размером W * H см.
 * Михаилу нужно разместить на доске N квадратных стикеров со шпаргалками, при этом
 * длина стороны стикера в сантиметрах должна быть целым числом.
 * Задача: определите максимальную длину стороны стикера, чтобы все стикеры поместились на доске.
 * */

int W, H, N;

bool check(int size) {
    return (W / size) * (H / size) >= N;
}

int f(int l, int r) {
    int M;
    while (l < r) {
        M = (l + r + 1) / 2;
        if (check(M)) {
            l = M;
        } else {
            r = M - 1;
        }
    }
    return r;
}

int main()
{
    N = 5;
    W = 10;
    H = 10;
    int ans = f(0, W);
    cout << ans;
    return 0;
}
