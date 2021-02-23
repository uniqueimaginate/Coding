#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int num;
    cin >> num;
    
    long **DP = new long*[1001];
    for(int i=0; i<1001; i++){
        DP[i] = new long[11];
        memset(DP[i], 0, sizeof(long)*11);
    }
    
    for(int i=0; i<10; i++){
        DP[1][i] = 1;
    }
    
    for(int i=2; i<1001; i++){
        for(int j=0; j<10; j++){
            for(int k=j; k<10; k++){
                DP[i][k] = (DP[i][k] + DP[i-1][j]) % 10007;
            }
        }
    }
    
    
    long sum = 0;
    for(int i=0; i<10; i++){
        sum = (sum+DP[num][i]) % 10007;
    }
    
    cout << sum << endl;
    
    
    for(int i=0; i<1001; i++){
        delete [] DP[i];
    }
    delete [] DP;
    
}
