#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    
    int DP[15] = {0,};
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    
    for(int i = 4; i<15; i++){
        DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
    }
    
    for(int i=0; i<num; i++){
        int temp;
        cin >> temp;
        cout << DP[temp] << endl;
    }
    
}
