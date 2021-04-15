#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
    string a, b, c, d;

    cin >> a >> b >> c >> d;
    string A = a + b;
    string B = c + d;
    long long result = atoll(A.c_str()) + atoll(B.c_str());
    cout << result << endl;
    return 0;
}