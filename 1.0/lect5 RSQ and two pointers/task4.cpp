#include <iostream>
#include <vector>

using namespace std;

/*
 * https://www.youtube.com/watch?v=de28y8Dcvkg&t=2275s, 37:00
 */

vector<int> v;
vector<int> rsq;

void setVector() {
    int n;
    cin >> n;
    v.resize(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
}

void setRSQ() {
    rsq.resize(v.size()+1, 0);
    for (int i = 1; i < rsq.size(); i++) rsq[i] = rsq[i-1] + v[i-1];
}

int getRangeSum(int ind1, int ind2) {
    return rsq[ind2+1] - rsq[ind1];
}

int res() {
    int L = v.size() - 1;
    int mx = 0;
    for (int R = v.size() - 1; R >= 0; R--) {
        while (v[L] + v[L-1] >= v[R] && L > 0) {
            L--;
        }
        if (getRangeSum(L, R) > mx) mx = getRangeSum(L, R);
    }
    return mx;
}

int main() {
    setVector();
    setRSQ();
    cout << res();
    return 0;
}
