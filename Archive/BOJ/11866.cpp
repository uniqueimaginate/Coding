#include <iostream>
#include <vector>

using namespace std;

int arr[1001];
vector<int> result;

int main(){
    int N,K;
    cin >> N >> K;
    for(int i=1; i<=N; ++i){
        arr[i] = i;
    }

    int repeat = 0;
    int check = 0;
    while(1){
        for(int i=1; i<=N; ++i){
            if(arr[i] != 0) check++;
            if(check == K){
                arr[i] = 0; check = 0;
                result.push_back(i);
                repeat++;
            }
        }
        if(repeat == N)
            break;
    }
    
    cout << "<";
    for(int i=0; i<result.size(); ++i){
        if(i == result.size()-1)
            cout << result[i];
        else{
            cout << result[i] << ", ";
        }
    }
    cout << ">" << endl;
}