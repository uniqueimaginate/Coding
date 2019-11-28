#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

char arr[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
string str;
int B;
int total = 0;

int main(){
    cin >> str >> B;
    int cnt = 0;
    for(int i=str.size()-1; i>=0; i--){
        int pw=0;
        if('A' <= str[i] && str[i] <= 'Z'){

            for(int k=0; k<26; k++){
                if(arr[k] == str[i]){
                    pw = k + 10;
                    break;
                }
            }
            total += pow(B,cnt++)*pw;
        }
        else{
            pw = str[i] - '0';
            total += pow(B,cnt++)*pw;
        }
    }

    cout << total << endl;
    return 0;
}