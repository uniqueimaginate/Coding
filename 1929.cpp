#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[1000010]= {0,};
	int a;
	int b;

	cin >> a >> b;

	for(int i=2; i<=b; i++){
		for(int j=1; j*i <= b; j++){
			if(j==1 && arr[j*i] == 0){
				arr[j*i] = 1;
			}
			else
				arr[j*i] = -1;
		}
	}

	for(int i=a; i<=b; i++){
		if(arr[i] == 1)
			cout << i << '\n';
	}
	return 0;
}
