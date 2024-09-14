#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    int n = s.size(), cnt = 0;
    bool all = (s[0] == 'B' || s[n-1] == 'B');
    
    for (int i = 0; i < n-1; i++){
        if (s[i] == s[i+1] && s[i] == 'B') { all = true; }
    }
}

int main(){
    int t;
    cin >> t;

    while (t--) { solve(); }
    return 0;
}