#include <bits/stdc++.h>

using namespace std;

int A, B, V;

int main(){
    int result = 0;
    cin >> A >> B >> V;
    if(V==A) {
        cout << "1" << endl;
        return 0;
    }
    V = V - A;
    result = V / (A-B);
    if(V % (A-B) != 0) result++;

    cout << result + 1 << endl;
    return 0;
}