#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector< pair <int, int> > vec;

    int num;
    cin >> num;

    while(num--){
        int n1, n2;
        cin >> n1 >> n2;
        vec.push_back(make_pair(n1, n2));
    }

    sort(vec.begin(), vec.end());
    for(int i=0; i<vec.size(); i++){
        cout << vec[i].first << " " << vec[i].second << '\n';
    }
    return 0;
}