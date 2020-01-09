#include <iostream>
#include <string>
#include <vector>

using namespace std;

string stringChannel;
int channel;
int M;

vector<int> vec;


int main(){
    cin >> stringChannel >> M;
    channel = stoi(stringChannel);

    for(int i=0; i<10; i++){
        vec.push_back(i);
    }

    while(M--){
        int temp; cin >> temp;
        for(int i=0; i<vec.size(); i++){
            if(vec[i] == temp){
                vec.erase(vec.begin() + i);
            }
        }
    }


    for(int i=0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }


    return 0;
}