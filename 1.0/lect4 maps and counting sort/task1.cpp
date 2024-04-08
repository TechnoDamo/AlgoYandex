#include <iostream>
using namespace std;

/*
 * Дано два числа X и Y без ведущих нулей
 * Необходимо проверить, можно ли получить перво ечисло из второго
 * перестановкой цийфр
 */

bool f(int X, int Y) {
    int countX[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int countY[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while (X != 0 && Y != 0) {
        countX[X%10]++;
        countY[Y%10]++;
        X /= 10;
        Y /= 10;
    }
    if (X != 0 || Y != 0) return false;
    for (int i = 0; i < 10; i++) {
        if (countX[i] != countY[i]) return false;
    }
    return true;
}


int main() {
    int x, y;
    cin >> x >> y;
    cout << f(x, y);
    return 0;
}
