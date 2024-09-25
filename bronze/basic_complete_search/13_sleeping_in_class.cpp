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

vector<int> get_divisors(int num){
    vector<int> div;
    for (int i = 1; i*i <= num; i++){
        if (num % i == 0){
            div.push_back(i);
            int dd = num / i;
            if (i != dd ){ div.push_back(dd); }
        }
    }
    return div;
}

int main(){
    setIO();
    int T, n;
    cin >> T;

    while (T--){
        int total = 0;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) { 
            cin >> arr[i];
            total += arr[i]; 
        }

        // then we find the search through its divisors to see which of them gives us the smallest
        vector<int> factors = get_divisors(total);

        int ans = n-1;
        for (int fact: factors){
            if (fact == 1) continue;

            int l = 0, tot = 0, joins = 0;

            for (int r = 0; r < n; r++){
                tot+= arr[r];

                while(tot > fact){}
            }
            ans = min(joins, ans);
        }
        cout << ans << endl;
    }
    
    return 0;
}