#include <bits/stdc++.h>
using namespace std;

int N, M;
int si, ti, ci;
int stalls[101];
vector<int> airconditions[11];

bool isValid(vector<int> &arr){
    for (int a: arr){
        if (a != 0) return false;
    }
    return true;
}

int main(){
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        cin >> si >> ti >> ci;

        for (int j = si; j <= ti; j++)
        stalls[j] = ci;
    }

    for (int i = 0; i < M; i++){
        vector<int> tmp(4, 0);
        cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];
        airconditions[i] = tmp;
    }

    int bnd = 1 << M;
    int lowest_cost = INT_MAX;

    for (int mask = 0; mask < bnd; mask++){
        int current_cost = 0;
        vector<int> copyOfStalls(stalls, stalls+101);

        for (int i = 0; i < M; i++){
            if (mask & (1 << i) == 0)
            continue;
            current_cost += airconditions[i][3];
            for (int k = airconditions[i][0];  k <= airconditions[i][1]; k++){
                copyOfStalls[k] -= airconditions[i][2];
            }
        }

        if (isValid(copyOfStalls))
        lowest_cost = min(lowest_cost, current_cost);
    }

    cout << lowest_cost << "\n";
    return 0;
}