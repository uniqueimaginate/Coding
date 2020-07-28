#include <bits/stdc++.h>

using namespace std;

int K,N;
vector<int> vec;
vector<int> results;

bool find(int mid){
    long long sum = 0;
    for(int i=0; i<K; ++i){
        sum += (vec[i] / mid);
    }
    if(sum >= N){ 
        return true;
    }
    else{
        return false;
    }
}


int main(){
    cin >> K >> N;
    for(int i=0; i<K; ++i){
        int temp; cin >> temp;
        vec.push_back(temp);
    }

    long long minN = 1;
    long long maxN = *max_element(vec.begin(), vec.end());

    while(minN <= maxN){
        long long mid = (minN + maxN) / 2;
        if(find(mid)){
            results.push_back(mid);
            minN = mid + 1;
        }
        else{
            maxN = mid - 1;
        }
    }

    int maxResult = *max_element(results.begin(), results.end());

    cout << maxResult << endl;
    return 0;
}