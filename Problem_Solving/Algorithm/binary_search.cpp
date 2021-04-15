#include <iostream>

using namespace std;

int binary_search(int *arr, int length, int target){
    int left = 0, right = length - 1;

    while(left < right){
        int middle = (left + right) / 2;

        if(target <= arr[middle]){
            right = middle;
        } else{
            left = middle + 1;
        }
    }

    if(target == arr[right]) return right;
    return -1;
}

int main(){

    int arr[10] = {2,4,7,12,15,21,34,35,46,57};
    int position = binary_search(arr, 10, 4);

    cout << position << endl;
    return 0;
}