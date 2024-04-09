#include <iostream>
#include <vector>

using namespace std;

/*
 * соединить две отсортированные последовательности
 */

vector<int> v1;
vector<int> v2;

void setVector(vector<int> &v) {
    int n;
    cin >> n;
    v.resize(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
}

vector<int> merge() {
    vector<int> res(v1.size() + v2.size(), 0);
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] <= v2[j]) {
            res[i + j] = v1[i];
            i++;
        }
        else {
            res[i + j] = v2[j];
            j++;
        }
    }

    if (i < v1.size() - 1) {
        while (i != v1.size()) {
            res[i+j] = v1[i];
            i++;
        }
    } else {
        while (j != v2.size()) {
            res[i+j] = v2[j];
            j++;
        }
    }
    return res;
}

void showVector(const vector<int> &vec) {
    cout << endl;
    for (auto i: vec) cout << i << " ";
    cout << endl;
}

int main() {
    setVector(v1);
    setVector(v2);
    vector<int> v3 = merge();
    showVector(v3);
    return 0;
}
