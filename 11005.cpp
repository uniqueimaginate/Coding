#include <iostream>
#include <stack>
#include <string>
using namespace std;

int N,B;
stack<int> result;

char arr[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int main(){
    cin >> N >> B;

    while(N){
        int temp = N % B;
        result.push(temp);
        N /= B;
    }
    while(!result.empty()){
        int temp = result.top();
        result.pop();
        if(temp > 9){
            cout << arr[temp-10];
        }
        else{
            cout << temp;
        }
    }
    cout << endl;
    return 0;
}