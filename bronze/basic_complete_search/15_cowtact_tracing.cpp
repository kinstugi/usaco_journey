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


struct Contact{
    int time, cowA, cowB;
    bool operator<(Contact &other){
        return time < other.time;
    }
};

int main(){
    setIO();
    int num_cows, records;
    cin >> num_cows >> records;
    string health_record = "";
    cin >> health_record;

    

    vector<Contact> contacts(num_cows);

    for (int i = 0; i < records; i++){
        cin >> contacts[i].time >> contacts[i].cowA >> contacts[i].cowB;
    }

    sort(contacts.begin(), contacts.end());
    

    int patient_z = 0, min_k = INT_MAX, max_k = INT_MIN;
    int cur_patient = 0;
    for (char ch: health_record){
        cur_patient++;
        if (ch == '0') continue;
        // verify is this sick patient is probable patient zero
        
        for (Contact &contact: contacts){
            
        }
    }
    return 0;
}