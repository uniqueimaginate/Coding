#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;
    cin >> a;
    // cout << str <<'\n';
    while(a--){
        string str;
        cin >> str;
        list<char> lst;
        list<char>::iterator it = lst.begin();
        for(int j=0; j < str.size(); j++){
            if(str[j] == '<'){
                if(it != lst.begin())
                    it--;
            }
            else if(str[j] == '>'){
                if(it != lst.end())
                    it++;
            }
            else if(str[j] == '-'){
                if(it != lst.begin()){
                    it = lst.erase(--it);
                }
            }
            else{
                lst.insert(it, str[j]);
            }
        }
        for(auto x : lst){
            cout << x;
        }
        cout << '\n';
    }
    return 0;
}