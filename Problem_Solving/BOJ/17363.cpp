#include<iostream>
#include<string>
using namespace std;
int N, M;
char map[101][101];
char map2[101][101];
int main() {
	cin >> N >> M;
	for (int i = 0; i<N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j<M; j++) {
			map[i][j] = s[j];
		}
	}

	for (int i = 0; i<M; i++) {
		for (int j = 0; j<N; j++) {
			//map2[i][j]=map[j][M-1-i];
			if (map[j][M - 1 - i] == '.')    map2[i][j] = '.';
			else if (map[j][M - 1 - i] == 'O')    map2[i][j] = 'O';
			else if (map[j][M - 1 - i] == '-')    map2[i][j] = '|';
			else if (map[j][M - 1 - i] == '|')    map2[i][j] = '-';
			else if (map[j][M - 1 - i] == '/')    map2[i][j] = '\\';
			else if (map[j][M - 1 - i] == '\\')    map2[i][j] = '/';
			else if (map[j][M - 1 - i] == '^')    map2[i][j] = '<';
			else if (map[j][M - 1 - i] == '<')    map2[i][j] = 'v';
			else if (map[j][M - 1 - i] == 'v')    map2[i][j] = '>';
			else if (map[j][M - 1 - i] == '>')    map2[i][j] = '^';
		}
	}
	


	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << map2[i][j];
		}
		cout << '\n';
	}

	return 0;
}