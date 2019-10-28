#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    int num;
    int count=0;
    cin >> N >> M;

    deque<int> deq;
    for(int i=1; i<=N; i++){
        deq.push_back(i);
    }

    for(int i=0; i<M; i++){
        cin >> num;
        int pos = 0;
        for(int i=0; i<deq.size(); i++){
            if(deq.at(i) == num){
                pos = i;
                break;
            }
        }
        int temp;
        if(pos < deq.size() - pos){
            for(int j=0; j<pos; j++){
                temp = deq.front();
                deq.pop_front();
                deq.push_back(temp);
                count++;
            }
        }
        else{
            for(int j=0; j<deq.size()-pos; j++){
                temp = deq.back();
                deq.pop_back();
                deq.push_front(temp);
                count++;
            }
        }
        deq.pop_front();
    }

    cout << count << endl;
    return 0;
}