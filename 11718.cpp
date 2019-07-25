#include <cstdio>


using namespace std;

int main() {
    char *name = new char[100];

    while(scanf("%c", name) != -1){
        printf("%s", name);
    }


    return 0;
}