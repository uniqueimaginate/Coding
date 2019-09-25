#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[1001] = {0,};
	int a;
	int b;

	cin >> a >> b;

	int order = 0;

	for(int i=2; i<=a; i++){
		for(int j=1; j*i <= a ; j++){
			if(arr[j*i] == 0){
				arr[j*i] = ++order;
			}
			if(order == b){
				cout << j*i << '\n';
				i = 1000;
				break;
			}
		}
	}
	return 0;
}

