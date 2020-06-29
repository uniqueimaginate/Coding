#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#define ARR_SIZE 100000

using namespace std;

int N;
pair<int, int> arr[ARR_SIZE];
string s[ARR_SIZE];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arr[i].first;
        cin >> s[i];
        arr[i].second = i;
    }

    sort(arr, arr+N);

    for(int i=0; i<N; i++){
        cout << arr[i].first << " " << s[arr[i].second] << "\n";
    }

    return 0;
}
