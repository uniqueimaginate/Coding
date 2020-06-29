#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
	if(a>b){
		return b ? gcd(b, a%b) : a;
	}
	else if(a<b){
		return a ? gcd(a, b%a) : b;
	}
	else
		return a;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a;
	long long b;
	long long c;
	cin >> a >> b;
	c = gcd(a,b);
	for(int i=0; i<c; i++){
		cout << "1";
	}
	cout << '\n';
	return 0;
}
