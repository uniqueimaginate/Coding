#include <iostream>

using namespace std;

// using divide & conquer + matrix multiplication

class SquareMatrix{
    public:
        int n1, n2, n3, n4;

        SquareMatrix(int _n1, int _n2, int _n3, int _n4) : n1(_n1), n2(_n2), n3(_n3), n4(_n4){}

        SquareMatrix operator * (const SquareMatrix& matrix){
            int nt1 = this->n1 * matrix.n1 + this->n2 * matrix.n3;
            int nt2 = this->n1 * matrix.n2 + this->n2 * matrix.n4;
            int nt3 = this->n3 * matrix.n1 + this->n4 * matrix.n3;
            int nt4 = this->n3 * matrix.n2 + this->n4 * matrix.n4;
            return SquareMatrix(nt1, nt2, nt3, nt4);
        }

        void print(){
            cout << this->n1 << " " << this->n2 << "\n" << this->n3 << " " << this->n4 << endl;
        }
};

SquareMatrix identity(){
    return SquareMatrix(1, 0, 0, 1);
}

SquareMatrix pow(const SquareMatrix& matrix, int m){
    if(m == 0) return identity();
    if(m % 2 > 0) return pow(matrix, m-1) * matrix;
    SquareMatrix half = pow(matrix, m/2);
    return half * half;
}

int main(){
    /*
    matrix = |3 1|
             |4 2|
    */
    SquareMatrix matrix = SquareMatrix(3,1,4,2);
    
    // multiply by 4
    pow(matrix, 4).print();
}