// AI 程度 : 1

#include <bits/stdc++.h>
#define int long long

using namespace std;


signed main() {
    int N, M;
    cin >> N >> M;

    vector<list<int>> q(N + 1);

    while (M--) {
        string s;
        cin >> s;

        if (s == "ADD") {
            int i, j;
            cin >> i >> j;
            q[i].emplace_back(j);
        } else if (s == "LEAVE") {
            int i;
            cin >> i;
            if (q[i].empty()) {
                cout << "queue " << i << " is empty!" << '\n';
            } else {
                q[i].pop_front();
            }
        } else {
            int i, j;
            cin >> i >> j;
            q[j].splice(q[j].end(), q[i]);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << "queue " << i << ": ";
        if (q[i].empty()) {
            cout << "empty" << '\n';
        } else {
            for (auto x : q[i]) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
