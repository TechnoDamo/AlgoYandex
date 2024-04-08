#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * сгруппировать строки
 */
map<string, vector<string>> groups;
vector<string> input = {"ate", "eat", "tae", "nat", "tan", "ban"};

// для коротких строк
string sortedString(string s) {
    sort(s.begin(), s.end());
    return s;
}

// для очень длинных строк
string sortedString(string s, int ifSisBig) {
    map<char, int> m;
    for (int i = 0; i < s.size(); i++) {
        m[s[i]]++;
    }
    int k = 0;
    for (auto i: m) {
        for (int j = k; j < k + i.second; j++) {
            s[j] = i.first;
        }
        k += i.second;
    }
    return s;
}

void groupStrings() {
    for (const auto& s: input) {
        groups[sortedString(s)].push_back(s);
        //groups[sortedString(s, 1)].push_back(s);
    }
}

void showGroups() {
    cout << endl;
    for (const auto& i: groups) {
        for (const auto& j: i.second) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    groupStrings();
    showGroups();
    return 0;
}
