#include <iostream>

using namespace std;

int main(){
    int num;
    cin >> num;
    while(num--){
        int H,W,N;
        cin >> H >> W >> N;
        int quotient = N / H + 1;
        int remainder = N % H;
        if(!remainder){
            remainder = H;
            quotient--;
        }
        if(remainder < 10){
            if(quotient < 10){
                cout << remainder << "0" << quotient << endl;
            }
            else{
                cout << remainder << quotient << endl;
            }
        }
        else{
            if(quotient < 10){
                cout << remainder << "0" << quotient << endl;
            }
            else{
                cout << remainder << quotient << endl;
            }
        }
    }
    return 0;
}