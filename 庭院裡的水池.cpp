// AI 程度 : 1

#include <bits/stdc++.h>
#define int long long

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int H, W;

void bfs(int sx, int sy, vector<vector<char>>& a, vector<vector<bool>>& vis) {
    queue<pair<int, int>> q;
    q.emplace(sx, sy);
    vis[sx][sy] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (0 <= nx && nx < H && 0 <= ny && ny < W && !vis[nx][ny] && a[nx][ny] == '.') {
                q.emplace(nx, ny);
                vis[nx][ny] = true;
            }
        }
    }
}


signed main() {
    int T;
    cin >> T;

    while (T--) {
        int cnt = 0;
        cin >> H >> W;

        vector<vector<char>> a(H, vector<char>(W));
        vector<vector<bool>> vis(H, vector<bool>(W));

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> a[i][j];
            }
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (a[i][j] == '.' && !vis[i][j]) {
                    bfs(i, j, a, vis);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }


    return 0;
}
