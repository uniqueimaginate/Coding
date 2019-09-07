#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int num;
    cin >> num;

    long **DP = new long*[101];
    for(int i=0; i<101; i++){
        DP[i] = new long[11];
        memset(DP[i], 0, sizeof(long)*11);
    }

    for(int i=1; i<10; i++){
        DP[1][i] = 1;
    }

    for(int i=2; i<101; i++){
        for(int j=0; j<10; j++){
            if(j==0)
                DP[i][j] = DP[i-1][j+1] % 1000000000;
            else if(j==9)
                DP[i][j] = DP[i-1][j-1] % 1000000000;
            else
                DP[i][j] = (DP[i-1][j-1]+DP[i-1][j+1]) % 1000000000;
        }
    }
    long sum = 0;
    for(int i=0; i<10; i++){
        sum = (sum+DP[num][i]) % 1000000000;
    }

    cout << sum << endl;


    for(int i=0; i<101; i++){
        delete [] DP[i];
    }
    delete [] DP;

}