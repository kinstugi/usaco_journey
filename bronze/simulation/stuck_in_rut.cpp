#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

struct Cow{
    int dr, dc, r, c;
};


int main(){
    int n;
    cin >> n;

    vector<Cow> cows(n);
    char dxn;
    for (int i = 0; i < n; ++i){
        cin >> dxn >> cows[i].r >> cows[i].c;
        if (dxn == 'E'){
            cows[i].dr = 0;
            cows[i].dc = 1;
        }
    }

    set<pair<int, int>> seen;

    while (true){
         
    }
    return 0;
}