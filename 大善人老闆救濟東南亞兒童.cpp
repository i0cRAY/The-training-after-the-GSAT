// AI 程度 : 1 (完全自己寫)

#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int T;
    cin >> T;

    while (T--) {
        stack<int> st;
        int n;
        cin >> n;
        bool can = true;
        vector<int> goal(n);
        for (int i = 0; i < n; i++) {
            cin >> goal[i];
        }

        int idx = 0;
        for (int num = 1; num <= n; num++) {
            if (num == goal[idx]) {
                idx++;
            } else {
                // 看看 st 有沒有
                while (!st.empty()) {
                    if (st.top() == goal[idx]) {
                        idx++;
                        st.pop();
                    } else {
                        break;
                    }
                }

                st.push(num);
            }
        }

        while (!st.empty()) {
            if (st.top() == goal[idx]) {
                idx++;
                st.pop();
            } else {
                // st 還有卻出不去就失敗了
                can = false;
                break;
            }
        }

        cout << (can ? "Yes" : "No") << "\n";
    }
}
