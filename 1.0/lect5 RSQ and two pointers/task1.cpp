#include <iostream>
#include <vector>

using namespace std;

/*
 * Определить количество нулей на интервале [L, R)
 */

vector<int> rsq;
vector<int> v;

void setVector() {
    int n;
    cin >> n;
    v.resize(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
}

void setRSQ() {
    rsq.resize(v.size()+1, 0);
    for (int i = 1; i < rsq.size(); i++) {
        if (v[i-1] == 0) rsq[i] = rsq[i-1] + 1;
        else rsq[i] = rsq[i-1];
    }
}

int getRangeSum(int ind1, int ind2) {
    return rsq[ind2] - rsq[ind1];
}

void showVector(const vector<int> &vec) {
    cout << endl;
    for (auto i: vec) cout << i << " ";
    cout << endl;
}

int main() {
    setVector();
    setRSQ();
    showVector(v);
    showVector(rsq);
    cout << getRangeSum(2, 4);
    return 0;
}
