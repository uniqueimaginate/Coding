#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#define SIZE 9

using namespace std;

int N;
int num;
int arr[SIZE][SIZE];
int cc;
queue< pair < int , int > > q;
vector< pair < int , int > > vec;


bool checkRow(int i, int j){
	int count = 0;
    for(int k=0; k<SIZE; k++){
        if(arr[i][k] == arr[i][j]){
            count++;
        }
    }
	if(count > 1)
		return true;
	else
		return false;
}

bool checkCol(int i, int j){
	int count = 0;
	for(int k=0; k<SIZE; k++){
        if(arr[k][j] == arr[i][j])
            count++;
    }
	if(count > 1)
		return true;
	else
		return false;
}

bool checkSquare(int i, int j){
	int count = 0;
	for(int x = i - i%3; x < i-i%3 + 3; x++){
		for(int y = j- j%3; y < j-j%3 + 3; y++){
			if(arr[x][y] == arr[i][j])
				count++;
		}
	}
	
	if(count > 1)
		return true;
	else
		return false;
}

void findMissedNum(){
	int row[9] = {0,};
	int col[9] = {0,};
	// int square[9] = {0,};
	// int missed;
	// bool mis = false;
	// bool sF = false;
	// cout << "??";

	while(cc){
		for(int i=0; i < vec.size(); i++){
			for(int k=0; k<SIZE; k++){
				row[arr[vec[i].first][k]-1]++; // 세로
				col[arr[k][vec[i].second]-1]++;	// 가로
			}
			cout << vec[i].first << " " << vec[i].second <<" row///////////////" << endl;
			for(int k=0; k<SIZE; k++){
				cout << row[k] << " ";
			}
			cout << endl;
			cout << "col///////////////" << endl;
			for(int k=0; k<SIZE; k++){
				cout << col[k] << " ";
			}
			cout << endl;
			// cout << "!!";
			for(int k=0; k<SIZE; k++){
				if(row[k] == 0 && col[k] == 0){
					cc--;
					arr[vec[i].first][vec[i].second] = k+1;
					cout << vec[i].first << vec[i].second << k+1;
				}
			}
			for(int k=0; k<SIZE; k++){
				row[k] = 0;
				col[k] = 0;
			}
		}
	}
}

void check(){
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			// 가로 확인하기
			bool row = checkRow(i,j);
			// 세로 확인하기
			bool col = checkCol(i,j);
			bool sq = checkSquare(i,j);

		}
	}
}

void madeToZero(){
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			// 가로 확인하기
			bool row = checkRow(i,j);
			// 세로 확인하기
			bool col = checkCol(i,j);
			bool sq = checkSquare(i,j);

			if(row || col){
				q.push(make_pair(i,j));
				cc++;
				vec.push_back(make_pair(i,j));
			}
		}
	}
	while(!q.empty()){
		int x; int y;
		x = q.front().first;
		y = q.front().second;
		arr[x][y] = 0;
		q.pop();
	}
}

void print(){
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
    cin >> N;
    int count = 0;
    while(N--){
        cin >> num;
		// num++;
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
                cin >> arr[i][j];
            }
        }
        cout << "#" << ++count << " ";
        // check();
		madeToZero();
		for(int i=0; i<vec.size(); i++){
			cout << vec[i].first << " " << vec[i].second << endl;
		}
		print();
		findMissedNum();
        cout << endl;
		// print();
    }
    return 0;
}

