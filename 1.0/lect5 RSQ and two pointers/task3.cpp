#include <iostream>
#include <vector>

using namespace std;

/*
 * Дана отсортированная последовательность чисел и число К
 * Определить количество пар чисел А и В, таких что В - А > K
 */

vector<int> v;

void setVector() {
    int n;
    cin >> n;
    v.resize(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
}


int res(int k) {
    int c = 0;
    int A = 0;
    for (int B = 0; B < v.size(); B++) {
        if (v[B] - v[A] > k) {
            c += v.size() - B;
            A++;
            while (v[B] - v[A] > k) {
                c++;
                A++;
            }
        }
    }
    return c;
}

int main() {
    setVector();
    cout << res(4);
    return 0;
}
