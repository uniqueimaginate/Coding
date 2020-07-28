#include <bits/stdc++.h>

using namespace std;

vector<int> vec;
int main(){
    int a,b,c;

    while(1){
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;
        vec.push_back(a); vec.push_back(b); vec.push_back(c);
        sort(vec.begin(), vec.end());
        int i = vec[0] * vec[0];
        int j = vec[1] * vec[1];
        int k = vec[2] * vec[2];
        if(i + j == k) cout << "right" << endl;
        else cout << "wrong" << endl;
        vec.clear();
    }
}