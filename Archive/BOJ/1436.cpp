#include <iostream>

using namespace std;

int num;

int main(){
    cin >> num;
    
    int count = 0;
    int i = 0;
    while(1){
        if(count == num) break;
        ++i;
        int temp = i;
        while(temp != 0){
            if((temp % 1000) == 666){
                ++count; break;
            }else{
                temp /= 10;
            }
        }
    }
    cout << i << endl;
}