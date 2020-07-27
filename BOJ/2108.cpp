#include <bits/stdc++.h>

using namespace std;

int c, sum;
vector<int> vec;
vector<int> most;
int arr[8002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> c;
    for(int i=0; i<c; ++i){
        int temp; cin >> temp;
        arr[temp+4000]++;
        sum += temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());

    int maxNum = *max_element(arr, arr+8002);
    for(int i=0; i<8002; ++i){
        if(arr[i] == maxNum) most.push_back(i-4000);
    }
    
    sort(most.begin(), most.end());
    cout << round((float)sum / c) << endl;
    cout << vec[c/2] << endl;
    if(most.size() > 1) cout << most[1] << '\n';
    else cout << most[0] << '\n';
    cout << vec[c-1] - vec[0] << '\n';
}   