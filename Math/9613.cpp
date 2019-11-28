#include <iostream>
#include <vector>

using namespace std;
vector<int> vec;
int N;

int gcd(int a, int b){
    return !b ? a : gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while(N--){
        int temp;
        cin >> temp;
        long long total = 0;

        while(temp--){
            int input;
            cin >> input;
            vec.push_back(input);
        }

        for(int i=0; i<vec.size()-1; i++){
            for(int j=i+1; j<vec.size(); j++){
                total += gcd(vec[i], vec[j]);
            }
        }
        cout << total << '\n';
        vec.clear();
    }
}