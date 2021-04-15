#include <iostream>

using namespace std;

int capacity = 10;
int M = 10;
int Size = 0;
int* arr;

// dynamic array
void append(int newValue){
    if(Size == capacity){
        int newCapacity = 2 * capacity;
        int* newArray = new int[newCapacity];

        for(int i=0; i < Size; ++i)
            newArray[i] = arr[i];
        if(arr) delete [] arr;
        arr = newArray;
        capacity = newCapacity;
    }
    arr[Size++] = newValue;
}

// In C++ vector you can use reserve().

int main(){
    // dynamic array
    arr = new int[capacity];
    for(int i=0; i<300; ++i){
        append(i);
    }
    cout << capacity << endl;
}