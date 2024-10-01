#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// incorrect solution i need to check again
void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

ll helper(ll num1, ll num2, char op){
    if (op == '*') return num1 * num2;
    else if (op == '+') return num1 + num2;
    else if (op == '-') return num1 - num2;
    else if (num2 == 0) return -9999;
    else if (num1 % num2) return -9999;
    return num1 / num2; 
}

ll evaluate(ll num1, char op1, ll num2, char op2, ll num3, char op3, ll num4){
    ll res = helper(num1, num2, op1);
    if (res != -9999){
        res = helper(res, num3, op2);
        if (res != -9999){
            res = helper(res, num4, op3);
        }
    }

    ll first = helper(num1, num2, op1), second = helper(num3, num4, op3);
    if (first != -9999 && second != -9999){
        res = max(res, helper(first, second, op2));
    }
    return res;
}

int main(){
    ll n, c1, c2, c3, c4;
    cin >> n;
    
    string operators = "*/+-";
    
    for (int i = 0; i < n; i++){
        cin >> c1 >> c2 >> c3 >> c4;
        ll res = -1;

        for (char op1: operators){
            for (char op2: operators){
                for (char op3: operators){

                    ll res1 = evaluate(c1, op1, c2, op2, c3, op3, c4);
                    if (res1 < 25)
                    res = max(res,  res1);
                }
            }
        }

        cout << res << endl;
    }
    
    return 0;
}