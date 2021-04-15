#include <bits/stdc++.h>
#define bb ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

using namespace std;

int C;

int main(){
    cin >> C;
    while(C--){
        int temp; cin >> temp;
        multiset<int, greater<int>> ms;
        for(int i=0; i<temp; ++i){
            char C; int N;
            cin >> C >> N;
            if(C == 'I') ms.insert(N);
            if(C == 'D'){
                if(ms.empty()) continue;
                if(N == 1){
                    ms.erase(ms.begin());
                }
                else{
                    ms.erase(--ms.end());
                }
            }
        }

        if(ms.empty()) cout << "EMPTY" << endl;
        else{
            cout << *ms.begin() << " " << *ms.rbegin() << endl;
        }
        ms.clear();
    }
}
