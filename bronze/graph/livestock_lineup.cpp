#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> graph;
set<string> seen;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("lineup");

    string cows[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(cows, cows + 8);

    for (string cow: cows){
        graph[cow];
    }

    int n;
    cin >> n;
    string cowA, cowB, tmp;
    for (int i = 0; i < n; i++){
        cin >> cowA >> tmp >> tmp >> tmp >> tmp >> cowB;
        
        if (cowA < cowB)
        graph[cowA].push_back(cowB);
        else
        graph[cowB].push_back(cowA);
    }

    vector<vector<string>> order;
    for(string cow: cows){
        if (graph[cow].size() > 1){
            string mn = min(graph[cow][0], graph[cow][1]);
            string mx = max(graph[cow][1], graph[cow][0]);
            order.push_back({mn, cow, mx});
            // seen.insert(cow); seen.insert(mx); seen.insert(mn);
        }else if (graph[cow].size() == 1){
            order.push_back({cow, graph[cow][0]});
        }else{
            order.push_back({cow});
        }
    }

    sort(order.begin(), order.end(), [&](vector<string> &a, vector<string> &b){ 
        if (a[0] == b[0]){
            return a.size() > b.size();
        }
        return a[0] < b[0];     
    });
    for (vector<string> &v: order){
        for (string s: v){
            if (seen.count(s)) continue;
            cout << s << endl;
            seen.insert(s);
        }
    }
    return 0;
}