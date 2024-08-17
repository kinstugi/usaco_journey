#include <iostream>
#include <vector>
using namespace std;


vector<int> pp[3];

bool makesSquare(vector<vector<int> > &arr){
    for (int i = 0; i < 3; ++i){
        cout << arr[i][0] << " " << arr[i][1] << " ";
    }
    cout << "\n";
    return true;
}

void printSquare(vector<vector<int> > &arr){

}

bool recur(vector<vector<int> > &arr, int i){
    if (i >= 3 ){
        // here is where we will check if this can form into a square
        if (makesSquare(arr)){
            printSquare(arr);
            return true;
        }
        return false;
    }
    // check the straigth forward implementation
    arr.push_back({pp[i][0], pp[i][1]});
    bool res = recur(arr, i+1);
    if (res) return true;
    arr.pop_back();

    // check the reverse implementation
    arr.push_back({pp[i][1], pp[i][0]});
    res = recur(arr, i+1);
    if (res) return true;
    arr.pop_back();
    return res;
}

int main(){
    int x, y;
    for (int i = 0; i < 3; i++){
        cin >> x >> y;
        pp[i] = {x, y};
    }
    vector<vector<int> > combo;
    recur(combo, 0);
    return 0;
}