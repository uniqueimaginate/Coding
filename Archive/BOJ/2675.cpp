#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;

    while(n--){
        int temp; string str;
        cin >> temp;
        cin >> str;
        for(int i=0; i<str.size(); ++i){
            for(int j=0; j<temp; ++j){
                cout << str[i];
            }
        }
        cout << endl;
    }
}