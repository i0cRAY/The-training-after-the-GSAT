// AI 程度 : 1

#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int n;
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            pq.push(x);
        }

        int cost = 0;
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            cost += a + b;

            pq.push(a + b);
        }

        cout << cost << '\n';
    }

    return 0;
}
