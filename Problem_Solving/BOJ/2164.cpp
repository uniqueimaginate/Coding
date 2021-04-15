#include <iostream>
#include <vector>

using namespace std;

int main(){
    int num;
    cin >> num;
    vector<int> vec;
    vec.reserve(500000);
    for(int i=1; i<=num; ++i){
        vec.push_back(i);
    }

    int i = 0;
    int temp = vec.at(i);
    while(1){
        temp = vec.at(i++);
        if(vec.size() == i) break;
        int t = vec.at(i++);
        vec.push_back(t);
    }

    cout << temp << endl;
}