#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int time;
    int inside;
    
    cin >> time;
    while(time--){
        int total=0;
        cin >> inside;
        int temp = inside;
        
        while(inside--){
            int num;
            cin >> num;
            total += num;
        }
        float val = (float)total / temp;
        if((float)(val - (int)val) > 0)
            cout << (int)val + 1 << '\n';
        else
            cout << (int)val << '\n';
        
    }
    return 0;
}