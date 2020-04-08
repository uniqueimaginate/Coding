#include <cstdio>

using namespace std;

int result;

int main(){
    bool flag = false;
    scanf("%d", &result);


    int temp = 0;
    while(1){
        char c;
        if(scanf("%c", &c) == -1){
            printf("%d\n", result-temp);
            break;
        }
        if(c == '-' && !flag){
            flag = true;
            scanf("%d", &temp);
        } else if(c == '-' && flag){
            result -= temp;
            scanf("%d", &temp);
        } else if(c == '+' && flag){
            int num;
            scanf("%d", &num);
            temp += num;
        } else if(c == '+'){
            int num;
            scanf("%d", &num);
            result += num;
        }
    }
}