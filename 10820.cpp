#include <iostream>
#include <string>

using namespace std;
int arr[4];

string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        getline(cin, s);
        if(s=="") break;
        for(int i=0; i<s.size(); i++){
            if('A' <= s[i] && s[i] <='Z'){
                arr[0]++;
            }
            else if('a' <= s[i] && s[i] <= 'z'){
                arr[1]++;
            }
            else if('0' <= s[i] && s[i] <= '9'){
                arr[2]++;
            }
            else{
                arr[3]++;
            }
        }
        cout << arr[1] << " " << arr[0] << " " << arr[2] << " " << arr[3] << '\n';
        arr[0] = 0;
        arr[1] = 0;
        arr[2] = 0;
        arr[3] = 0;
    }
    

    return 0;
}