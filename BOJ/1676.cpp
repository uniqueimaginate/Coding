#include <bits/stdc++.h>

using namespace std;
int n;

int arr[3] = {125, 25, 5};
int main(){
    cin >> n;
    int result = 0;

    for(int i=1; i<=n; ++i){
        if((i % arr[0]) == 0) result = result + 3;
        else if((i % arr[1]) == 0) result = result + 2;
        else if((i % arr[2]) == 0) result = result + 1;
    }

    cout << result << endl;
}