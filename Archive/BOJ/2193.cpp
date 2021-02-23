#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int num;
    scanf("%d", &num);
    
    long DP[91][2] = {0,};
    
    DP[1][0] = 0;
    DP[1][1] = 1;
    
    for(int i=2; i<91; i++){
        DP[i][0] += DP[i-1][0] + DP[i-1][1];
        DP[i][1] += DP[i-1][0];
    }
    
    long sum = 0;
    sum = DP[num][0] + DP[num][1];
    
    printf("%ld\n", sum);
    
}
