#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * Определить количество префиксных сумм, равных 0
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
    for (int i = 1; i < rsq.size(); i++) rsq[i] = rsq[i-1] + v[i-1];
}

int getRangeSum(int ind1, int ind2) {
    return rsq[ind2+1] - rsq[ind1];
}

int k() {
    map<int, int> m;
    m[0] = 1;
    for (int i = 0; i < rsq.size(); i++) {
        m[getRangeSum(0, i)]++;
    }
    int count = 0;
    for (auto i: m) {
        count += (i.second*(i.second-1)) / 2;
    }
    return count;
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
    cout << k();
    return 0;
}
