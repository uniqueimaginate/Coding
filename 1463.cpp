#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    cin >> num;
    int arr[1000001];
    memset(arr, 0, sizeof(int) * num);

    arr[1] = 0;

    for(int i=2; i<=num; i++){
        arr[i] = arr[i-1] + 1;
        if(i%2 == 0)
            arr[i] = min(arr[i], arr[i/2]+1);
        if(i%3 ==0)
            arr[i] = min(arr[i], arr[i/3] + 1);
    }

    cout << arr[num];
}
