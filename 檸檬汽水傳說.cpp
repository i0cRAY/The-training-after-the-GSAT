// AI 程度 : 1

#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        int ans = 0;
        stack<pair<int, int>> st;
        for (int i = 0; i < N; i++) {
            int cnt = 1;
            while (!st.empty() && st.top().first <= a[i]) {
                ans += st.top().second;

                if (st.top().first == a[i]) {
                    cnt += st.top().second;
                }

                st.pop();
            }

            if (!st.empty()) {
                ans++;
            }

            st.emplace(a[i], cnt);
        }

        cout << ans << '\n';
    }

    return 0;
}
