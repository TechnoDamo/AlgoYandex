#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
/*
    Найти два различных числа A и B из последовательности, таких что A + B = X
    или вернуть пару 0, 0, если такой пары чисел нет
*/

void f(const vector<int> &v, int x) {
    unordered_set<int> s;
    for (int i : v) {
        s.insert(i);
    }

    for (auto itr = s.begin(); itr != s.end(); ++itr) {
        int B = *itr;
        if (s.find(x - B) != s.end()) {
            cout << x - B << " " << B;
            return;
        }
    }

    cout << "0 0";
}



int main() {
    vector<int> v;
    int x;
    cin >> x;
    v.push_back(x);
    while (x != 0) {
        cin >> x;
        v.push_back(x);
    }
    cout << "X: ";
    cin >>x;
    f(v, x);
    return 0;
}
