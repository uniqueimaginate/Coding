#include <iostream>

using namespace std;

int stack[100010];
int arr[100010];
char result[100010];
int pos;

void push(int val){
	stack[pos++] = val;
}

void pop(){
	if(pos != 0){
		pos--;
	}
	else
		return;
}

int top(){
	if(pos != 0){
		return stack[pos-1];
	}
	else{
		return -1;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int count;
	int value;
	int i=1;
	int j=0;
	cin >> count;
	for(int k=0; k<count; k++){
		cin >> arr[k];
	}
	int k =0;
	while(count--){
		while(i <= arr[k]){
			push(i++);
			result[j++] = '+';
		}
		if(top() == arr[k]){
			pop();
			result[j++] = '-';
		}
		else{
			cout << "NO" << '\n';
			return 0;
		}
		k++;
	}
	for(int i=0; i<j; i++){
		cout << result[i] << '\n';
	}
	return 0;
}
