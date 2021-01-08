#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int C;

int main(){
    cin >> C;
    while(C--){
        int N,K;
        cin >> N >> K;
        list<int> lt;
        for(int i=1; i<=N; ++i)
            lt.push_back(i);
        
        list<int>::iterator it = lt.begin();


        while(N>2){
            it = lt.erase(it);
            if(it == lt.end()) it = lt.begin();
            --N;

            for(int i=0; i<K-1; ++i){
                it++;
                if(it == lt.end()) it = lt.begin();
            }
        }
        cout << lt.front() << " " << lt.back() << endl;
    }


}