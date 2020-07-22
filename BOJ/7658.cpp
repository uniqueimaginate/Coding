#include <bits/stdc++.h>

using namespace std;

int c;

vector< pair < int, int > > vec;
int arr[51];

int main(){

    memset(arr, 0, sizeof(arr));
    cin >> c;
    for(int i=0; i<c; ++i){
        int a, b;
        cin >> a >> b;
        vec.push_back( make_pair(a, b));
    }

    for(int i=0; i<vec.size(); ++i){
        for(int j=0; j<vec.size(); ++j){
            if(vec[i].first < vec[j].first && vec[i].second < vec[j].second)
                arr[i]++;
        }
    }

    for(int i=0; i<c; ++i){
        cout << arr[i]+1 << " ";
    }
    cout << endl;
}