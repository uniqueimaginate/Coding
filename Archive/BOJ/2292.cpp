#include <bits/stdc++.h>

using namespace std;
int c;
int main(){
    cin >> c;
    int start = 1;
    int i = 1;
    while(1){
        if(c <= start) break;
        start += (6*i++);
    }

    cout << i << endl;
    return 0;
}