#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    
    int arr[1001] = {0,};
    arr[0] = 1; arr[1] =1;
    for(int i=2; i<1001; i++)
        arr[i] = (arr[i-1] + arr[i-2] * 2) % 10007;
    
    cout << arr[num] << endl;
    
}
