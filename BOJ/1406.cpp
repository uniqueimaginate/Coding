#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio();
	cin.tie(0);

	string S;
	int num;
	cin >> S;
	cin >> num;

	list<char> L;
	
	for(auto ch : S){
		L.push_back(ch);
	}

	list<char>::iterator t = L.end();
	
	for(int i=0; i<num; i++){
		char temp1;
		cin >> temp1;
		if(temp1 == 'P'){
			char temp2;
			cin >> temp2;
			L.insert(t,temp2);
		}
		else if(temp1 == 'L'){
			if(t != L.begin())
				t--;
		}
		else if(temp1 == 'B'){
			if(t != L.begin()){
				t--;
				t = L.erase(t);
			}
		}
		else{
			if(t != L.end())
				t++;
		}
	}
	for(auto i : L){
		cout << i;
	}

	return 0;
}
