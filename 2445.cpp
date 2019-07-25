#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;
    string str = "*";
    cin >> num;
    int temp = num;

    for(int i=0; i<num; i++){
        for(int k=-1; k<i; k++)
            cout << str;
        for(int j=2*((temp--)-1); j>0; j--){
            cout << " ";
        }
        for(int k=-1; k<i; k++)
            cout << str;
        cout << endl;
    }
    temp = 1;
    for(int i=num-1; i>0; i--){
        for(int k=0; k<i; k++)
            cout << str;
        for(int j=0; j<2*(temp); j++){
            cout << " ";
        }
        temp++;
        for(int k=0; k<i; k++)
            cout << str;
        if(i > 1)
            cout << endl;
    }
}
