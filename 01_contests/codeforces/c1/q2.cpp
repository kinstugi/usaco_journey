#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void solve(){
    int num_models, max_lim;
    cin >> num_models >> max_lim;

    vector<int> cars(num_models);
    for (int i = 0; i < num_models; i++) { cin >> cars[i]; }

    ll mx = 0, total = 0;
    for (int num : cars){
        mx = max(mx, (ll) num);
        total += num; 
    }

}

int main(){
    setIO();
    int t;
    cin >> t;

    while (t--){
        solve();
    }
    return 0;
}