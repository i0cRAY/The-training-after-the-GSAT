// AI 程度 : 1

#include <bits/stdc++.h>
#define int long long

using namespace std;

int k;
int l[15];

void dfs(int idx, int now, vector<int>& a, vector<bool>& vis) {
    if (idx == 6) {
        
        for (int i : a) {
            cout << i << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i = now; i < k; i++) {
        if (!vis[l[i]]) {
            a.emplace_back(l[i]);
            vis[l[i]] = true;

            dfs(idx + 1, i, a, vis);
            
            a.pop_back();
            vis[l[i]] = false;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> k;

        memset(l, 0, sizeof(l));

        for (int i = 0; i < k; i++) {
            cin >> l[i];
        }

        vector<int> a;
        vector<bool> vis(50);
        dfs(0, 0, a, vis);
    }

    return 0;
}
