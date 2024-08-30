#include <bits/stdc++.h>
using namespace std;

int n, m, k;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

bool check(vector<int> &order, vector<int> &hierarchy){
    vector<int> cow_to_pos(n+1, -1);
    for (int i = 1; i <= n; ++i){
        if (order[i] != -1) { cow_to_pos[order[i]] = i; }
    }

    int h_idx = 0;
    
    return true;
}

int main() {
    setIO("milkorder");
   
    vector<int> hierachy(m);

    for (int i = 0; i < m; ++i)
    cin >> hierachy[i];

    vector<int> order(n+1, -1);

    for (int i = 0; i < k; ++i){
        int cow, pos;
        cin >> cow >> pos;
        order[pos] = cow;

        if (cow == 1){
            cout << pos << '\n';
            return 0;
        }
    }

    for (int i = 1; i <= n; ++i){
        if (order[i] == -1){
            order[i] = 1;
            if (check(order, hierachy, n)){
                cout << i << '\n';
                break;
            }
            order[i] = -1;
        }
    }
    return 0;
}
