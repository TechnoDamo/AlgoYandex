#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <set>

using namespace std;

set<int> intersec(const unordered_set<int> &s1, const unordered_set<int> &s2) {
    set<int> res;
    for (auto i: s1) {
        if (s2.find(i) != s2.end()) res.insert(i);
    }
    return res;
}

void printSet(const set<int> &container) {
    for (auto i: container) cout << i << " ";
}

int main() {
    int x;
    unordered_set<int> s1;
    unordered_set<int> s2;
    set<int> res;
    string line;
    getline(cin, line);
    istringstream iss(line);
    while (iss >> x) {
        s1.insert(x);
    }
    getline(cin, line);
    istringstream iss1(line);
    while (iss1 >> x) {
        s2.insert(x);
    }
    res = intersec(s1, s2);
    printSet(res);
    return 0;
}
