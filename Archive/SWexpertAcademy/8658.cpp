// SW expert Academy
#include <iostream>
#include <string>
using namespace std;

int N;


int sum(string str){
    int result = 0;
    for(int i=0; i < str.size(); i++){
        result += str[i] - '0';
    }
    return result;
}

int main(){
    cin >> N;
    int count = 1;
    while(N--){
        
        int min = 1000001;
        int max = 0;
        for(int i=0; i<10; i++){
            string str;
            cin >> str;
            int result = sum(str);
            if(result < min)
                min = result;
            if(result > max)
                max = result;
        }
        cout << "#" << count++ << " " << max << " " << min << endl;
    }
    return 0;
}