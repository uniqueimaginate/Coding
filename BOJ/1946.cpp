#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i=0; i<N; ++i){
        int result = 1;
        int num; cin >> num;
        vector<pair <int, int> > vec;

        for(int j=0; j<num; ++j){
            int a, b; cin >> a >> b;
            vec.push_back(make_pair(a, b));
        }
        sort(vec.begin(), vec.end());
        int interview = vec[0].second;
        for(int j=1; j<num; ++j){
            if(vec[j].second < interview){
                ++result;
                interview = vec[j].second;
            }
        }
        cout << result << '\n';

        
    }

}