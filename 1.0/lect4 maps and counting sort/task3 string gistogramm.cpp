#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * сделать гисторамму по строке
 */
string s;
map<char, int> m;
vector<vector<char>> gist;

void setMap() {
    for (char i : s) {
        m[i]++;
    }
}

void setGist() {
    vector<char> v(s.size(), ' ');
    gist.resize(s.size(), v);
    int k = 0;
    for (auto & it : m) {
        for (int i = s.size() - 1; i >= s.size() - it.second; i--) {
            gist[i][k] = '#';
        }
        k++;
    }
}

void showGist() {
    for (const auto& v: gist) {
        for (auto el: v) {
            cout << el;
        }
        cout << endl;
    }
    for (auto & it : m) {
        cout << (char)it.first;
    }
}


int main() {
    //cin >> s;
    s = "Hello, world!";
    setMap();
    setGist();
    showGist();
    return 0;
}
