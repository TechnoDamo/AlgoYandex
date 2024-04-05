#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
/*
    Дан словарь из N слов, длина каждого не превосходит K
    В записи каждого из M слов текста (каждое длиной до K)
    может быть пропущена одна буква. Для каждого слова сказать,
    входит ли оно (возможно, с одной пропущенной буквой), в словарь
*/

unordered_set<string> set = {"abc", "abcd", "gfr"};

unordered_set<string> setDict(const unordered_set<string> &s) {
    unordered_set<string> extended_s;
    for (const auto & itr : s) {
        for (int i = 0; i < itr.size(); i++) {
            string st = itr;
            st.erase(st.begin()+i);
            extended_s.insert(st);
        }
    }
    return extended_s;
}

bool check(const unordered_set<string> &s, const string &el) {
    for (auto i: s) {
        if (el == i) return true;
    }
    return false;
}

int main() {
    string s;
    unordered_set<string> extended_dict = setDict(set);
    cin >> s;
    cout << check(extended_dict, s);
    return 0;
}
