#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
	return b ? gcd(b, a%b) : a;
}

long long lcm(long long a, long long b){
	return (a*b) / gcd(a,b);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a;
	long long b;

	cin >> a >> b;
	long long c;
	if(a>b){
		c = gcd(a,b);
		cout << (a*b) / c << '\n';
	}
	else if(a==b){
		cout << a << '\n';
	}
	else{
		c= gcd(b,a);
		cout << (a*b) / c << '\n';
	}
	return 0;
}
