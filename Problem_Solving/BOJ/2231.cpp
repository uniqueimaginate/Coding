#include <bits/stdc++.h>

using namespace std;

int toNumber(char ch){ return ch - '0';}

int makeSum(int i){
    int sum = 0;
    sum += i;

    while(i){
        sum += (i % 10);
        i /= 10;
    }

    return sum;
}

int main(){
    int num;
    cin >> num;
    int result = -1;
    bool fin = false;
    for(int i=0; i<num; ++i){
        int temp = makeSum(i);
        if(temp == num) {
            fin = true;
            result = i;
            break;
        }
    }
    if(fin) cout << result << endl;
    else cout << "0" << endl;

}