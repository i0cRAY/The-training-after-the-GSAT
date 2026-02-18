// AI 程度 : 1

#include <bits/stdc++.h>
#define int long long

using namespace std;

int siz[100005];
int fa[100005];

int dfs(int p, vector<vector<int>>& child) {
    siz[p] = 1;

    for (auto c : child[p]) {
        dfs(c, child);
        siz[p] += siz[c];
    }

    return siz[p];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> child(n + 1);
        
        memset(siz, 0, sizeof(siz));
        memset(fa, -1, sizeof(fa));

        while (m--) {
            int x, y;
            cin >> x >> y;

            child[x].emplace_back(y);
            fa[y] = x;
        }

        for (int i = 1; i <= n; i++) {
            if (fa[i] == -1) {
                dfs(i, child);
            }
        }

        int q;
        cin >> q;
        
        while (q--) {
            int x;
            cin >> x;
            cout << siz[x] << '\n';
        }
    }

    return 0;
}
