#include <iostream>
using namespace std;

bool mod[42];

int main(){
    while(!cin.eof()){
        int temp;
        cin >> temp;
        mod[temp % 42] = true;
    }
    int count = 0;
    for(int i=0; i<42; ++i){
        if(mod[i])
            count++;
    }
    cout << count << endl;
}