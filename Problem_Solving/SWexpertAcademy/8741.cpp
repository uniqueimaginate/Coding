#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    for(int i=1; i<=N; i++){
        char *a = (char*)malloc(sizeof(char)*20);
        char *b = (char*)malloc(sizeof(char)*20);;
        char *c = (char*)malloc(sizeof(char)*20);;
        scanf("%s %s %s", a, b, c);
        printf("#%d %c%c%c\n", i ,a[0]-32, b[0]-32, c[0]-32);
        free(a);
        free(b);
        free(c);
    }
    return 0;
}