#include<cstdio>
 
 
using namespace std;
 
int n, m;
char a[50][51], b[50][51];
 
 
void toggle(int i, int j) {
    for (int ii = i-1; ii <= i+1; ii++)
        for (int jj = j-1; jj <= j+1; jj++)
            a[ii][jj] = '0' + '1' - a[ii][jj];
}
 
 
bool check_same(void) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] != b[i][j])
                return false;
    return true;
}
 
 
int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", a[i]);
    for (int i = 0; i < n; i++)
        scanf("%s", b[i]);
        
    int cnt = 0;
    for (int i = 1; i < n-1; i++)
        for (int j = 1; j < m-1; j++)
            if (a[i-1][j-1] != b[i-1][j-1]) {
                toggle(i, j);
                cnt++;
            }
                
    printf("%d", check_same()? cnt : -1);
    
    return 0;
}