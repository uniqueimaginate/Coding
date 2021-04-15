#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> vec;
string str;

int main(){
    cin >> str;
    int size = str.size();
    vec.push_back(str);
    for(int i=0; i<size-1; i++){
        str.erase(str.begin());
        vec.push_back(str);
    }

    sort(vec.begin(), vec.end());

    for(int i=0; i<vec.size(); i++){
        cout << vec[i] << endl;
    }
    
    return 0;
}