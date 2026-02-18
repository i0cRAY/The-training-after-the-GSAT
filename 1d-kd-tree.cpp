// AI 程度 : 1

#include <bits/stdc++.h>
#define int long long

using namespace std;


signed main() {
    int N;
    cin >> N;

    set<int> st;

    while (N--) {
        string s; 
        int x;
        cin >> s >> x;

        if (s == "insert") {
            st.insert(x);
        } else if (s == "delete") {
            st.erase(x);
        } else {
            int diff1 = LLONG_MAX; // 大於等於 x 的
            auto it1 = st.lower_bound(x);
            if (it1 != st.end()) {
                diff1 = *it1 - x;
            }
            
            int diff2 = LLONG_MAX; // 小於 x 的
            if (it1 == st.begin()) { // 左邊沒東西了
                cout << *it1;
            } else {
                auto it2 = it1;
                it2--;

                diff2 = x - *it2;

                if (diff1 < diff2) {
                    cout << *it1;
                } else if (diff1 > diff2) {
                    cout << *it2;
                } else {
                    cout << *it2 << ' ' << *it1;
                }
            }

            cout << '\n';
        }
    }


    return 0;
}
