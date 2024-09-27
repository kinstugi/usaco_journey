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

int main(){
    setIO();
    int n;
	cin >> n;
	vector<pair<int, char>> arr(n);

	for (int i = 0; i < n; i++) { cin >> arr[i].second >> arr[i].first; }

	//we will consider the ith cow is telling the truth
	int ans = INT_MAX;
	for (const pair<int, char> &cur_cow: arr){
		int lb = INT_MIN, rb = INT_MAX;
		if (cur_cow.second == 'G'){ lb = cur_cow.first;}
		else{ rb = cur_cow.first; }

		int cnt = 0;

		for (const pair<int, char> &pp: arr){
			int llb = INT_MIN, rrb= INT_MAX;
			if (pp.second == 'G') { llb = pp.first;}
			else{ rrb = pp.first; }

			if ((lb <= llb && llb <= rb) || (llb <= lb && lb <= rrb)) {continue;}
			cnt++;
		}

		ans = min(ans, cnt);
	}
	cout << ans << endl;
    return 0;
}