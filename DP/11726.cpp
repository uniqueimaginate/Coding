#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int num;
    cin >> num;

    long arr[1001];
    memset(arr, 0, sizeof(int)*num);
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3; i<=num; i++){
        arr[i] = (arr[i-1] + arr[i-2])%10007;
    }

    cout << arr[num] << endl;
}
