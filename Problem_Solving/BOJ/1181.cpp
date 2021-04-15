#include <bits/stdc++.h>

using namespace std;


int num;
vector< pair < int, string> > vec;

int main(){

    cin >> num;
    while(num--){
        string str;
        cin >> str;
        vec.push_back(make_pair(str.size(), str));
    }

    sort(vec.begin(), vec.end());

    string temp = vec[0].second;
    cout << temp << endl;
    for(int i=1; i<vec.size(); ++i){
        if(temp == vec[i].second){
            continue;
        }
        else{
            temp = vec[i].second;
            cout << temp << endl;
        }
    }
}