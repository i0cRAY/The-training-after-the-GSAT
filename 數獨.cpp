// AI 程度 : 1

#include <bits/stdc++.h>
#define int long long

using namespace std;

string s, res;
bool can;

bool check(vector<vector<char>>& test, int h, int w) {
    // 檢查直行
    for (int H = 0; H < 9; H++) {
        if (test[H][w] == test[h][w] && H != h) {
            return false;
        }
    }

    // 檢查橫行
    for (int W = 0; W < 9; W++) {
        if (test[h][W] == test[h][w] && W != w) {
            return false;
        }
    }

    // 檢查九宮格
    int i_start = 0, j_start = 0;
    if (h < 3) i_start = 0;
    else if (3 <= h && h < 6) i_start = 3;
    else i_start = 6;

    if (w < 3) j_start = 0;
    else if (3 <= w && w < 6) j_start = 3;
    else j_start = 6;

    bool appear[10];
    memset(appear, false, sizeof(appear));
    for (int i = i_start; i <= i_start + 2; i++) {
        for (int j = j_start; j <= j_start + 2; j++) {
            if (isdigit(test[i][j]) && appear[test[i][j] - '0']) {
                return false;
            } else if (isdigit(test[i][j])) {
                appear[test[i][j] - '0'] = true;
            }
        }
    }

    return true;
}

void dfs(int idx, vector<vector<char>>& a) {
    if (can) return;
    
    if (idx == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                res += a[i][j];
            }
        }
        can = true;
        return;
    } else {
        if (s[idx] == '.') {
            for (int n = 1; n <= 9; n++) {
                int h = idx / 9;
                int w = idx % 9;
                a[h][w] = n + '0';

                if (check(a, h, w)) {
                    dfs(idx + 1, a);
                    if (can) return;
                }        

                a[h][w] = '.';
            }
        } else {
            dfs(idx + 1, a);
        }
    }
}

signed main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> s;

        vector<vector<char>> a(9, vector<char>(9));
        res = "";
        can = false;

        int idx = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                a[i][j] = s[idx];
                idx++;
            }
        }

        dfs(0, a);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!check(a, i, j)) {
                    can = false;
                }
            }
        }

        if (!can) {
            cout << "No solution." << '\n';
        } else {
            cout << res << '\n';
        }
    }

    return 0;
}
