#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> graph;
set<string> seen;


void bfs(string node ){
    if (seen.count(node)) return;
    cout << node << "\n";
    seen.insert(node);

    for (string nei: graph[node]){
        if (seen.count(nei)) continue;
        bfs(nei);
    }
}

int main(){
    
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

    for (auto &item: graph){
        cout << item.first << " : ";
        for (string cow: item.second){
            cout << cow << " ";
        }
        cout << endl;
    }

    for (string cow: cows){
        if (seen.count(cow)) continue;
        bfs(cow);
    }
    return 0;
}