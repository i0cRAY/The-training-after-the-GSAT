// AI 程度 : 2 (提示到要用 team queue)

#include <bits/stdc++.h>
#define int long long

using namespace std;

int group[1000005];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    for (int L = 1; L <= T; L++) {
        cout << "Line #" << L << '\n';
        int n;
        cin >> n;

        vector<queue<int>> sub_q(n + 1);
        queue<int> main_q; // 存的是 sub_q 的 id or 沒朋友的人

        memset(group, 0, sizeof(group));

        for (int i = 1; i <= n; i++) {
            int total;
            cin >> total;
            while (total--) {
                int people;
                cin >> people;
                group[people] = i;
            }
        }

        int m;
        cin >> m;

        while (m--) {
            string s;
            cin >> s;

            if (s == "ENQUEUE") {
                int x;
                cin >> x;

                // 1. 有朋友
                // 2. 沒朋友

                int id = group[x];
                if (id != 0) {
                    if (!sub_q[id].empty()) { // 前面有團夥
                        sub_q[id].push(x);
                    } else { // 前面沒團夥
                        main_q.push(id);
                        sub_q[id].push(x);
                    }
                } else {
                    main_q.push(n + x); // 乖乖排到最後面
                }
            } else {
                if (main_q.front() <= n) {
                    int id = main_q.front();
                    cout << sub_q[id].front() << '\n';
                    sub_q[id].pop();
                    if (sub_q[id].empty()) {
                        main_q.pop();
                    }
                } else {
                    cout << main_q.front() - n << '\n';
                    main_q.pop();
                }
            }
        }
    }
}
