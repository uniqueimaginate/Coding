#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack< pair< int, int > > s;
    int num;
    int count = 0;
    cin >> num;

    for(int i=1; i<=num; i++){
        int temp;
        cin >> temp;
        if(s.empty()){
            s.push(make_pair(temp, i));
            cout << "0" << " ";
        }
        else{
            if(s.top().first < temp){
                while(!s.empty() && (s.top().first < temp)){
                    s.pop();
                }
                if(s.empty()){
                    cout << "0" << " ";
                }
                else{
                    cout << s.top().second << " ";
                }
                s.push(make_pair(temp, i));
            }
            else{
                cout << s.top().second << " ";
                s.push(make_pair(temp, i));
            }
        }
    }
    cout << '\n';
    return 0;
}