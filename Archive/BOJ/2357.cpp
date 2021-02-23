#include <bits/stdc++.h>

using namespace std;

// const int INT_MAX = numeric_limits<int>::max();

struct RMQ{
public:
    int n;
    vector<int> rangeMin;
    vector<int> rangeMax;
    RMQ(const vector<int>& array){
        n = array.size();
        rangeMin.resize(n * 4);
        rangeMax.resize(n * 4);
        init(array, 0, n-1, 1);
        init2(array, 0, n-1, 1);
    }

    int init(const vector<int>& array, int left, int right, int node){
        if(left == right)
            return rangeMin[node] = array[left];
        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node * 2);
        int rightMin = init(array, mid + 1, right, node * 2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }

    int init2(const vector<int>& array, int left, int right, int node){
        if(left == right)
            return rangeMax[node] = array[left];
        int mid = (left + right) / 2;
        int leftMax = init2(array, left, mid, node * 2);
        int rightMax = init2(array, mid + 1, right, node * 2 + 1);
        return rangeMax[node] = max(leftMax, rightMax);
    }

    int query(int left, int right){
        return query(left, right, 1, 0, n-1);
    }

    int query2(int left, int right){
        return query2(left, right, 1, 0, n-1);
    }

private:
    int query(int left, int right, int node, int nodeLeft, int nodeRight){
        if(right < nodeLeft || nodeRight < left) return INT_MAX;

        if(left <= nodeLeft && nodeRight <= right) return rangeMin[node];

        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node * 2, nodeLeft, mid),
                query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }

    int query2(int left, int right, int node, int nodeLeft, int nodeRight){
        if(right < nodeLeft || nodeRight < left) return INT_MIN;

        if(left <= nodeLeft && nodeRight <= right) return rangeMax[node];

        int mid = (nodeLeft + nodeRight) / 2;
        return max(query2(left, right, node * 2, nodeLeft, mid),
                query2(left, right, node * 2 + 1, mid + 1, nodeRight));
    }
};

vector<int> vec;

int N, M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    vec.push_back(0);
    
    while(N--){
        int temp; cin >> temp;
        vec.push_back(temp);
    }
    RMQ segTree(vec);
    while(M--){
        int a, b; cin >> a >> b;
        cout << segTree.query(a,b) << " " << segTree.query2(a,b) << '\n';
    }
    return 0;
}