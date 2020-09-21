#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, res, cnt;
vector<pair <int, int > > vec;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i=0; i<N; ++i){
        int a, b;
        cin >> a >> b;
        vec.push_back(make_pair(a, 1)); vec.push_back(make_pair(b, -1));
    }

    sort(vec.begin(), vec.end());

    for(auto i : vec){
        cnt += i.second;
        res = max(res, cnt);
    }

    cout << res << endl;
}