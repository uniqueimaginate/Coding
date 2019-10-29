#include <iostream>
#include <string>
#include <queue>
#include <cstdio>

using namespace std;

int main(){
    int count;
    scanf("%d", &count);
    while(count--){
        string str;
        char c1;
        int num, flag = 0;
        string temp;
        deque<int> deq;
        bool reverse = false;

        cin >> str;
        scanf("%d", &num);
        scanf(" %c", &c1);
        for(int j=0; j<num; j++){
            int n;
            scanf(" %d,", &n);
            deq.push_back(n);
        }
        scanf(" %c", &c1);
        
        for(int j=0; j<str.length(); j++){
            if(str[j] == 'R'){
                reverse = !reverse;
            }
            else if(str[j] == 'D'){
                if(deq.empty()){
                    flag = 1;
                    break;
                }
                if(reverse)
                    deq.pop_back();
                else
                {
                    deq.pop_front();
                }
            }
        }
        if (flag == 1) {
			printf("error\n");
			continue;
		}
        printf("[");
        if(deq.empty()){
            printf("]\n");
            continue;
        }
        if(reverse){
            while(!deq.empty()){
                if(deq.size() == 1)
                    printf("%d]\n", deq.back());
                else
                    printf("%d,", deq.back());
                deq.pop_back();
            }
        }
        else{
            while(!deq.empty()){
                if(deq.size() == 1)
                    printf("%d]\n", deq.front());
                else
                    printf("%d,", deq.front());
                deq.pop_front();
            }
        }
        
    }
    return 0;
}
