#include  <iostream>

using namespace std;

int main(){
    int temp;
    cin >> temp;
    if(90 <= temp && temp <=100)
        cout << "A" << endl;
    else if(80 <= temp && temp <= 90)
        cout << "B" << endl;
    else if(70 <= temp && temp <= 79)
        cout << "C" << endl;
    else if(60 <= temp && temp <= 69)
        cout << "D" << endl;
    else
        cout << "F" << endl;
    
}