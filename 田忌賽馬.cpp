// AI 程度 : 1

#include <bits/stdc++.h>
#define int long long

using namespace std;

int N, K;

bool check(int mid, vector<pair<int, int>>& me, vector<int>& enemy) {
    vector<int> me_final(N);
    for (int i = 0; i < N; i++) {
        me_final[i] = me[i].first + me[i].second * mid;
    }

    sort(me_final.begin(), me_final.end());

    int cnt = 0, now = 0;
    for (int i = 0; i < N; i++) {
        if (me_final[i] > enemy[now]) {
            cnt++;
            now++;
        }
    }

    return cnt >= K;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> N >> K;

        vector<pair<int, int>> me(N);
        vector<int> enemy(N);

        for (int i = 0; i < N; i++) {
            cin >> me[i].first >> me[i].second;
        }

        for (int i = 0; i < N; i++) {
            cin >> enemy[i];
        }

        sort(enemy.begin(), enemy.end());

        int l = 0, r = 2e9, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid, me, enemy)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
