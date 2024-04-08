#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * Определить количество бьющих друг друга ладей на шахматной доске
 */
vector<int> line(8, 0);
vector<vector<int>> board(8, line);

void setBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }
}

int f() {
    map<int, int> columns;
    map<int, int> rows;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] != 0) {
                rows[i]++;
                columns[j]++;
            }
        }
    }
    int k = 0;
    for (auto & column : columns) {
        k += column.second;
        k--;
    }
    for (auto & row : rows) {
        k += row.second;
        k--;
    }
    return k;
}

int main() {
    setBoard();
    cout << f();
    return 0;
}
