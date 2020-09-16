#include <bits/stdc++.h>

using namespace std;

bool broken[10];
int N, M;

int check(int num){
    int len = 0;
    if(num == 0){
        if(!broken[0])
            return 1;
    }
    else{
        while(num){
            if(!broken[num % 10]){
                len++;
                num /= 10;
            }
            else return 0;
        }
    }
    return len;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<M; ++i){
        int temp; cin >> temp;
        broken[temp] = true;
    }


    int naive = abs(N - 100);
    int answer = 987654321;

    for(int i=0; i<=1000000; ++i){
        int temp = check(i);
        int tempA;
        if(temp){
            tempA = temp + abs(i-N);
            answer = min(answer, tempA);
        }
    }

    cout << min(naive, answer) << endl;
}