#include <bits/stdc++.h>

using namespace std;

// const int INT_MAX = numeric_limits<int>::max();
// const int INT_MIN = numeric_limits<int>::min();

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

    int update(int index, int newValue){
        return update(index, newValue, 1, 0, n-1);
    }

private:
    int query(int left, int right, int node, int nodeLeft, int nodeRight){
        if(right < nodeLeft || nodeRight < left) return INT_MAX;

        if(left <= nodeLeft && nodeRight <= right) return rangeMin[node];

        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node * 2, nodeLeft, mid),
                query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }

    int update(int index, int newValue, int node, int nodeLeft, int nodeRight){
        if(index < nodeLeft || nodeRight < index)
            return rangeMin[node];
        if(nodeLeft == nodeRight) return rangeMin[node] = newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeMin[node] = min(update(index, newValue, node*2, nodeLeft, mid),
                                update(index, newValue, node*2+1, mid+1, nodeRight));
    }
};

// 이러한 형태를 이제 각 문제에 맞게 변형을 해야 한다.