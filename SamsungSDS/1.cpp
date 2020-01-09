#include <cstdio>
#include <iostream>
#define SIZE 3

using namespace std;

int N;

class Arrs{
	public:
		int A[SIZE][SIZE] = {{1,2,3}, {4,5,6}, {7,8,9}};
		int B[SIZE][SIZE] = {{10,11,12}, {13,14,15}, {16,17,18}};
		int C[SIZE][SIZE] = {{19,20,21}, {22,23,24}, {25,26,27}};
		int D[SIZE][SIZE] = {{28,29,30}, {31,32,33}, {34,35,36}};
		int E[SIZE][SIZE] = {{37,38,39}, {40,41,42}, {43,44,45}};
		int F[SIZE][SIZE] = {{46,47,48}, {49,50,51}, {52,53,54}};
	
	
		void print(int (*arr)[SIZE]){
			for(int i=0; i<SIZE; i++){
				for(int j=0; j<SIZE; j++){
					cout << arr[i][j] << " ";
				}
			}
		}
	
		void choice(int a){
			switch(a){
				case 1:
					print(A);
					break;
				case 2:
					print(B);
					break;
				case 3:
					print(C);
					break;
				case 4:
					print(D);
					break;
				case 5:
					print(E);
					break;
				case 6:
					print(F);
					break;
			}
		}
};

void print(int (*arr)[SIZE], int a){
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			cout << arr[i][j] << " ";
		}
	}
}

void move(Arrs &arr, int c){
	int Temp[12];
	int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;
	int s1, s2, s3, s4, s5, s6, s7, s8;
	switch(c){
		case 1:
			t1 = arr.A[0][0]; t2 = arr.A[1][0]; t3 = arr.A[2][0];
			t4 = arr.B[0][0]; t5 = arr.B[1][0]; t6 = arr.B[2][0];
			t7 = arr.C[0][0]; t8 = arr.C[1][0]; t9 = arr.C[2][0];
			t10 = arr.D[0][0]; t11 = arr.D[1][0]; t12 = arr.D[2][0];
			
			arr.A[0][0] = t4; arr.A[1][0] = t5; arr.A[2][0] = t6;
			arr.D[0][0] = t1; arr.D[1][0] = t2; arr.D[2][0] = t3;
			arr.C[0][0] = t10; arr.D[1][0] = t11; arr.D[2][0] = t12;
			arr.B[0][0] = t7; arr.B[1][0] = t8; arr.B[2][0] = t9;
			
			s1 = arr.E[0][0]; s2 = arr.E[0][1]; s3 = arr.E[0][2];
			s4 = arr.E[1][0]; s5 = arr.E[1][2];
			s6 = arr.E[2][0]; s7 = arr.E[2][1]; s8 = arr.E[2][2];
			
			arr.E[0][0] = s3; arr.E[0][1] = s5; arr.E[0][2] = s8;
			arr.E[1][0] = s2; arr.E[1][2] = s7;
			arr.E[2][0] = s1; arr.E[2][1] = s4; arr.E[2][2] = s6; 
			
			break;
		case 2:
			t1 = arr.A[0][1]; t2 = arr.A[1][1]; t3 = arr.A[2][1];
			t4 = arr.B[0][1]; t5 = arr.B[1][1]; t6 = arr.B[2][1];
			t7 = arr.C[0][1]; t8 = arr.C[1][1]; t9 = arr.C[2][1];
			t10 = arr.D[0][1]; t11 = arr.D[1][1]; t12 = arr.D[2][1];
			
			arr.A[0][1] = t4; arr.A[1][1] = t5; arr.A[2][1] = t6;
			arr.D[0][1] = t1; arr.D[1][1] = t2; arr.D[2][1] = t3;
			arr.C[0][1] = t10; arr.D[1][1] = t11; arr.D[2][1] = t12;
			arr.B[0][1] = t7; arr.B[1][1] = t8; arr.B[2][1] = t9;
			
			break;
		case 3:
			t1 = arr.A[0][2]; t2 = arr.A[1][2]; t3 = arr.A[2][2];
			t4 = arr.B[0][2]; t5 = arr.B[1][2]; t6 = arr.B[2][2];
			t7 = arr.C[0][2]; t8 = arr.C[1][2]; t9 = arr.C[2][2];
			t10 = arr.D[0][2]; t11 = arr.D[1][2]; t12 = arr.D[2][2];
			
			arr.A[0][2] = t4; arr.A[1][2] = t5; arr.A[2][2] = t6;
			arr.D[0][2] = t1; arr.D[1][2] = t2; arr.D[2][2] = t3;
			arr.C[0][2] = t10; arr.D[1][2] = t11; arr.D[2][2] = t12;
			arr.B[0][2] = t7; arr.B[1][2] = t8; arr.B[2][2] = t9;
			
			s1 = arr.F[0][0]; s2 = arr.F[0][1]; s3 = arr.F[0][2];
			s4 = arr.F[1][0]; s5 = arr.F[1][2];
			s6 = arr.F[2][0]; s7 = arr.F[2][1]; s8 = arr.F[2][2];
			
			arr.F[0][0] = s6; arr.F[0][1] = s4; arr.F[0][2] = s1;
			arr.F[1][0] = s7; arr.F[1][2] = s2;
			arr.F[2][0] = s8; arr.F[2][1] = s5; arr.F[2][2] = s3; 
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> N;
	while(N--){
		Arrs arr;
		int M;
		cin >> M;
		
		
		while(M--){
			int C;
			cin >> C;
			move(arr, C);
		}
		
		
		int P;
		cin >> P;
		arr.choice(P);
	}
    
    return 0;
}
