#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr[32010];
    int indegree[32010] = {0,};
    int result[32010];
    queue<int> q;

    int N,M;
    cin >> N >> M;

    for(int i=0; i < M; i++){
        int n1,n2;
        cin >> n1 >> n2;
        arr[n1-1].push_back(n2-1);
        indegree[n2-1]++;
    }

    for(int i=0; i<N; i++){
        if(indegree[i] == 0) q.push(i);
    }

    for(int i=0; i<N; i++){
        if(q.empty()){
            cout << "wrong" << '\n';
            return 0;
        }
        int front = q.front();
        q.pop();
        // cout << front << " ";
        result[i] = front+1;
        for(int j=0; j<arr[front].size(); j++){
            if(--indegree[arr[front][j]] == 0) q.push(arr[front][j]);
        }
    }

    for(int i=0; i<N; i++){
        cout << result[i] << " ";
    }
    cout << '\n';
    return 0;
}