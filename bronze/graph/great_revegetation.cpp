#include <bits/stdc++.h>
using namespace std;

vector<int> graph[151];
int seen[151], field_color[151], N, M;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("revegetate");
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> colors(N+1, 1);
    for (int node = 1; node <= N; node++){
        for (int nei: graph[node]){

            if (colors[nei] == colors[node]){
                colors[nei]++;
           

                for (int j = 1; j < node; j++){
                    for (int i: graph[j]){
                        if (colors[i] == colors[j]) { colors[nei]++; }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    cout << colors[i];
    cout << endl;
    return 0;
}