#include <bits/stdc++.h>
#define INT_MAX __INT_MAX__

using namespace std;

// const int INT_MAX = numeric_limits<int>::max();

struct RMQ{
public:
    int n;
    vector<int> rangeMin;
    RMQ(const vector<int>& array){
        n = array.size();
        rangeMin.resize(n * 4);
        init(array, 0, n-1, 1);
    }

    int init(const vector<int>& array, int left, int right, int node){
        if(left == right)
            return rangeMin[node] = array[left];
        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node * 2);
        int rightMin = init(array, mid + 1, right, node * 2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }

    int query(int left, int right){
        return query(left, right, 1, 0, n-1);
    }

private:
    int query(int left, int right, int node, int nodeLeft, int nodeRight){
        if(right < nodeLeft || nodeRight < left) return INT_MAX;

        if(left <= nodeLeft && nodeRight <= right) return rangeMin[node];

        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node * 2, nodeLeft, mid),
                query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }
};

vector<int> vec;
int main(){
    while(1){
        int n; cin >> n;
        if(n == 0) break;
        while(n--){
            int temp; cin >> temp;
            vec.push_back(temp);
        
        }
        RMQ rmq(vec);
        cout << rmq.query(6,7) << endl;
    }
}