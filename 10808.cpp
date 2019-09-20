#include <bits/stdc++.h>

using namespace std;
int arr[26];

int main(){
    ios::sync_with_stdio();
    cin.tie(0);
    
    string S;
    cin >> S;
    
    for(int i=0; i<S.size(); i++){
	int temp = S[i] - 'a';
	arr[temp]++;
    }
    for(int i=0; i<26; i++){
	cout << arr[i] << " ";
    }
    return 0;
}
