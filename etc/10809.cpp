#include <iostream>
#include <string>
#define ARR_SIZE 26

using namespace std;
string s;
int arr[ARR_SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for(int i=0; i<ARR_SIZE; i++){
        arr[i] = -1;
    }

    for(int i=0; i<s.size(); i++){
        if(arr[s[i]-'a'] != -1) continue;
        else{
            arr[s[i]-'a'] = i;
        }
    }

    for(int i=0; i<ARR_SIZE; i++){
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}