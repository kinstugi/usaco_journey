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

struct Cow{
    int l, r;
    bool operator<(Cow &other){
        return l < other.l;
    }
};

int main(){
    setIO("lifeguards");
    int n;
    cin >> n;

    vector<Cow> cows(n);

    for (int i = 0; i < n; i++){ cin >> cows[i].l >> cows[i].r; }
    sort(cows.begin(), cows.end());

    return 0;
}