#include <iostream>

using namespace std;

int N,M,K;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> K;
    int team;
    int girl = N/2;
    int boy = M;

    if(girl > boy){
        team = boy;
        girl = boy * 2;
    }
    else{
        team = girl;
        boy = girl;
        girl *= 2;
    }

    int left = (N+M) - (girl + boy) - K;
    if(left >= 0){
        cout << team << endl;
    }
    else{
        while(left < 0){
            team--;
            left += 3;
        }
        if(team < 0)
            cout << "0" << endl;
        else
            cout << team << endl;
    }
    
    return 0;
}