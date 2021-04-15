#include <bits/stdc++.h>
#define bb ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
using namespace std;


int N;
int arr[12];
vector< pair< char, bool> > op;
vector<int> vec;
char tmp[12];


int maxN = numeric_limits<int>::min();
int minN = numeric_limits<int>::max();

int calculate(int a, int b, char op){
    if(op == '+') return a + b;
    else if(op == '-') return a - b;
    else if(op == '*') return a * b;
    else return a / b;
}

void solve(int start, int cnt){
    if(cnt == N-1){
        int answer = vec[0];
        for(int i=1; i<N; ++i){
            answer = calculate(answer, vec[i], tmp[i-1]);
            
        }
        maxN = max(maxN, answer);
        minN = min(minN, answer);
        return;
    }

    for(int i=0; i<op.size(); ++i){
        if(op[i].second == false){
            tmp[cnt] = op[i].first;
            op[i].second = true;
            solve(i+1, cnt + 1);
            op[i].second = false;
        }
        
    }
}



int main(){
    cin >> N;
    for(int i=0; i<N; ++i){
        int temp; cin >> temp;
        vec.push_back(temp);
    }
    for(int i=0; i<4; ++i){
        int temp; cin >> temp;
        switch(i){
            case 0:
                while(temp--){
                    op.push_back(make_pair('+', false));
                }
                break;
            case 1:
                while(temp--){
                    op.push_back(make_pair('-', false));
                }
                break;
            case 2:
                while(temp--){
                    op.push_back(make_pair('*', false));
                }
                break;
            case 3:
                while(temp--){
                    op.push_back(make_pair('/', false));
                }
                break;
        }
    }

    solve(0,0);

    cout << maxN << endl;
    cout << minN << endl;
}