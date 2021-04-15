#include <bits/stdc++.h>

using namespace std;

map<string, int> m;
int cnt;

int main(){
    string str;

    while(1){
        getline(cin, str);

        if(str.length() == 0) break;
        ++cnt;
        m[str]++;
    }

    map<string, int>::iterator it;

    for(it = m.begin(); it != m.end(); ++it){
        cout << (it->first) << " ";
        printf("%0.4f\n", 100 * (float)(it->second)/cnt);
    }
}