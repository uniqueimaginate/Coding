#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> num;
    while(num--){
        int count=0;
        string temp;
        cin >> temp;
        for(int i=0; i < temp.length(); i++){
            if(temp[i] == '(')
                count++;
            else if(temp[i] == ')' && count > 0)
                count--;
            else
            {
                count--;
                break;
            }
        }
        if(count == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
    return 0;
}