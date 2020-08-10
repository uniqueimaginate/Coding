#include <bits/stdc++.h>
using namespace std;

int n, m,result;
string S;

int main()
{
	cin >> n >> m;
	cin >> S;

	int io = 0;

	for (int i = 1; i < m; i++) {
		if (S[i-1]=='I' && S[i]=='O') {
			io++;
		}
		else if(S[i-1]=='O' && S[i]=='I'){
			if (io >= n) result++;
		}
		else {
			io = 0;
		}
	}

	cout << result <<"\n";
	return 0;
}