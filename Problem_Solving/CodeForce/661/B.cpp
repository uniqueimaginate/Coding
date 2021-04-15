#include <bits/stdc++.h>
#define bb ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

using namespace std;

int C;

int minA;
int minB;

vector<int> vecA;
vector<int> vecB;

long long result;

int main(){
    bb;
    cin >> C;
    
    while(C--){
        int num; cin >> num;
        minA = numeric_limits<int>::max();
        minB = numeric_limits<int>::max();
        for(int i=0; i<num; ++i){
            int temp; cin >> temp;
            vecA.push_back(temp);
            minA = min(temp, minA);
        }
        for(int i=0; i<num; ++i){
            int temp; cin >> temp;
            vecB.push_back(temp);
            minB = min(temp, minB);
        }

        for(int i=0; i<num; ++i){
            result += max(abs(minA-vecA[i]), abs(minB-vecB[i]));
        }

        cout << result << endl;

        vecA.clear();
        vecB.clear();
        result = 0;
    }
}