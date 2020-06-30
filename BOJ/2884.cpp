#include <cstdio>

int main(){
    int h,m;
    bool flag = false;
    scanf("%d %d", &h, &m);

    if(m < 45){
        flag = true;
        int temp = 45 - m;
        m = 60 - temp;
    }else{
        m = m - 45;
    }

    if(flag){
        h == 0 ? h = 23 : h--;
    }


    printf("%d %d\n", h, m);
}