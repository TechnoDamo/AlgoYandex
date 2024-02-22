#include <bits/stdc++.h>
using namespace std;

int main() {
    int tRoom, tDes;
    string s;
    cin >> tRoom >> tDes;
    cin >> s;
    int ans;
    if (tRoom == tDes) {
        ans = tRoom;
    }
    else if (tRoom > tDes) {
        if (s == "auto" || s == "freeze") ans = tDes;
        else ans = tRoom;
    }
    else {
        if (s == "auto" || s == "heat") ans = tDes;
        else ans = tRoom;
    }
    cout << ans;
    return 0;
}
