#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    n--;
    int result = 0;
    int num = n % 8;
    // cout << num << endl;
    switch(num){
        case 0:
            result = 1;
            break;
        case 1:
            result = 2;
            break;
        case 2:
            result = 3;
            break;
        case 3:
            result = 4;
            break;
        case 4:
            result = 5;
            break;
        case 5:
            result = 4;
            break;
        case 6:
            result = 3;
            break;
        case 7:
            result = 2;
            break;
    }

    cout << result << endl;
}