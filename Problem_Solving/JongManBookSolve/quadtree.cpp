#include <bits/stdc++.h>

using namespace std;
int C;

string reverse(string::iterator& it){
    char head = *it;
    ++it;
    if(head == 'b' || head == 'w')
        return string(1, head);
    
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(){
    cin >> C;
    while(C--){
        string temp; cin >> temp;
        string::iterator it = temp.begin();
        cout << reverse(it) << endl;
    }

}