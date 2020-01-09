#include <iostream>
#define div 1000000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

class Matrix{
	public:
		ll a;
		ll b;
		ll c;
		ll d;
	public:
		Matrix(){a = 1; b = 0; c = 0; d = 1;}
		Matrix(ll _a, ll _b, ll _c, ll _d){
			a = _a; b= _b; c = _c; d = _d;
		}
		void show(){
			cout << a << " " << b << '\n' << c << " " << d << '\n';
		}
};

Matrix mul_mat(Matrix mat1, Matrix mat2){
	ll a = (mat1.a * mat2.a + mat1.b * mat2.c) % div;
	ll b = (mat1.a * mat2.b + mat1.b * mat2.d) % div;
	ll c = (mat1.c * mat2.a + mat1.d * mat2.c) % div;
	ll d = (mat1.c * mat2.b + mat1.d * mat2.d) % div;
	return Matrix(a,b,c,d);
}

ll cal_mat(Matrix &mat){
	return (mat.a + mat.c) % div;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ull a;
	cin >> a;


	switch (a){
		case 0:
			cout << "0" << '\n';
			return 0;
		case 1:
			cout << "1" << '\n';
			return 0;
		case 2:
			cout << "1" << '\n';
			return 0;
		default:
			break;
	}
	a -= 2;

	int arr[100];
	Matrix matrx[100];
    ll data[100];
    int i=0;
    while(a != 0){
        arr[i++] = a % 2;
        a /= 2;
    }
	for(int j=0; j<i; j++){
        if(j==0)
            matrx[j] = Matrix(1,1,1,0);
        else
            matrx[j] = mul_mat(matrx[j-1], matrx[j-1]);
        data[j] = cal_mat(matrx[j]);
    }
	Matrix result;
	for(int j=0; j<i; j++){
		if(arr[j] == 1){
			result = mul_mat(result, matrx[j]);
		}
	}
	cout << cal_mat(result) << '\n';
	return 0;
}


