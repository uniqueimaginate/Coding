#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    for(int i=1; i<=a; i++){
        vec.push_back(i);
    }
    cout << "<";

    int pos = b - 1;

    while(a--){
        cout << vec[pos];

        if(a==0){
            cout << ">\n";
        }
        else{
            cout << ", ";
        }
        vec.erase(vec.begin() + pos);
        pos += b-1;
        if(vec.size() > 0)
            pos %= vec.size();
    }
    
    return 0;
}