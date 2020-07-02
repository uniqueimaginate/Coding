#include <iostream>
#include <string>
using namespace std;

int n;

int getScore(const string& str){
    int temp = 0;
    int score = 0;
    for(int i=0; i<str.size(); ++i){
        if(str[i] == 'O'){
            score += ++temp;
        }
        else{
            temp = 0;
        }
    }
    return score;
}

int main(){
    cin >> n; string temps; getline(cin,temps);
    while(n--){
        string str;
        getline(cin, str);
        cout << getScore(str) << endl;
    }
}