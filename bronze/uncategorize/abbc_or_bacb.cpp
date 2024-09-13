#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    //setIO("test");
    int t;
    cin >> t;
    string input;

    while(t--){
        cin >> input;
        int ans = 0;

        string tmp = "";
        for (int i = 0; i < input.size(); i++){
            char ch = input[i], tail = 0;

            while (!tmp.empty()){
                if (ch == 'A' && tmp.back() == 'B'){
                    ch = 'C'; 
                    tail = tail ? tail :'B';
                }else if (ch == 'B' && tmp.back() == 'A'){
                    ch = 'B'; tail = tail ? tail : 'C';
                }else{
                    break;
                }
                tmp.pop_back();
                ans++;
            }
            tmp.push_back(ch);
            if (tail) { tmp.push_back(tail); }
        }
        cout << ans << endl;
    }

    return 0;
}