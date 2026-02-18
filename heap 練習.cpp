// AI 程度 : 1

#include <bits/stdc++.h>
#define int long long

using namespace std;


signed main() {
    int T;
    cin >> T;

    priority_queue<int, vector<int>, greater<int>> pq;

    while (T--) {
        int op;
        cin >> op;

        if (op == 1) {
            int x;
            cin >> x;
            pq.push(x);
        } else {
            if (pq.empty()) {
                cout << "empty!" << '\n';
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}
