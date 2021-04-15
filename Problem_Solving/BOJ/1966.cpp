#include <bits/stdc++.h>

using namespace std;

int C, n, m;


int main(){
    cin >> C;
    
    while(C--){
        int result = 0;
        cin >> n >> m;
        priority_queue< int, vector<int>, less<int> > pq;
        queue< pair < int, int > >  q;

        for(int i=0; i<n; i++){
            int temp; cin >> temp;
            pq.push(temp);
            if(i == m)
                q.push(make_pair(temp, 1));
            else
                q.push(make_pair(temp, 0));
        }

        while(1){
            if(q.front().first < pq.top()){
                q.push(make_pair(q.front().first, q.front().second));
                q.pop();
            }
            else{
                if(q.front().second == 1){
                    ++result;
                    break;
                }
                q.pop(); pq.pop();
                ++result;
            }
            
        }
        cout << result << endl;
    }
}