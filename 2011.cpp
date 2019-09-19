#include <iostream>
#include <string>
#define DIV 1000000

using namespace std;

int main(void)
{
    int DP[5002]{0,};
    DP[0] = 1;
    string a;
    cin >> a;
    a = ' ' + a;
    
    for(int i = 1; i < a.size(); i++) {
        if(a[i] - '0' >= 1){
            DP[i] = (DP[i-1] + DP[i]) % DIV;
        }
        int temp = (a[i-1] - '0') * 10 + (a[i]-'0');

        if(10 <= temp && temp < 27){
            DP[i] = (DP[i] + DP[i-2]) % DIV;
        }
    }

    cout << DP[a.size()-1] << endl;
    return 0;
}

