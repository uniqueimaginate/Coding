#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            cout << " ";
        }
        else if('0' <= s[i] && s[i] <= '9'){
            cout << s[i];
        }
        else{
            if('A' <= s[i] && s[i] <= 'Z'){
                int temp = s[i] - 'A';
                temp = (temp + 13) % 26 + 'A';
                cout << (char)temp;
            }
            else{
                int temp = s[i] - 'a';
                temp = (temp + 13) % 26 + 'a';
                cout << (char)temp;
            }
        }
    }
    cout << endl;
    return 0;
}