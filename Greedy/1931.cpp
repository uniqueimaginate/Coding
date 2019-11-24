#include <iostream>
#include <algorithm>
#include <utility>
#define SIZE 100000
#define ll long long
using namespace std;
int N, c;
ll fin;
pair< ll, ll >  arr[SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr, arr+N);

    fin = arr[0].first;
    c++;
    for(int i=1; i<N; i++){
        if(arr[i].second >= fin){
            fin = arr[i].first;
            c++;
        }
    }
    cout << c << '\n';
    return 0;
}