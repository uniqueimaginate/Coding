#include <iostream>

using namespace std;
int E, S, M;
int main(){
    cin >> E >> S >> M;
    int i=1;
    while(true){
        if(((i-E) % 15 == 0) && ((i-S) % 28 == 0) && ((i-M) % 19 == 0)){
            cout << i;
            break;
        }
        i++;
    }
    return 0;
}