#include <bits/stdc++.h>

using namespace std;

int N, M, B, height[257], minTime = 987654321, level;

int main(){
    cin >> N >> M >> B;
    int repeat = N*M;
    for(int i=0; i<repeat; ++i){
        int temp;
        cin >> temp;
        height[temp]++;
    }

    int tt;
    for(int i=256; i>=0; --i){
        int blocks = B;
        int tempMin = 0;
        bool flag = false;
        for(int j=256; j>=0; --j){
            flag = false;
            blocks -= height[j] * (i - j);
            if(blocks < 0){
                break;
            }
            else{
                flag = true;
                if(i-j < 0){
                    tempMin += (2 * height[j] * abs(i-j));
                }
                else if(i-j > 0){
                    tempMin += (1 * height[j] * abs(i-j));
                }
                else{
                    tempMin += 0;
                }
            }
        }
        if(flag){
            if(tempMin < minTime){
                minTime = tempMin;
                level = i;
            }
        }
    }

    cout << minTime << " " << level << endl;
}