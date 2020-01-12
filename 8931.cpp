#include <iostream>
#include <stack>

using namespace std;

int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++){
        int num;
        cin >> num;
        stack<int> s;
        while(num--){
            int temp;
            cin >> temp;
            if(temp == 0){
                s.pop();
            }
            else{
                s.push(temp);
            }
        }
        int result = 0;
        while(!s.empty()){
            result += s.top();
            s.pop();
        }
        cout << "#" << i << " " << result;
        cout << endl;
    }
    return 0;
}