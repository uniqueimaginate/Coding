#include <bits/stdc++.h>

using namespace std;

bool compare(pair<double, int> A, pair<double, int> B){
    if(A.first == B.first)
        return A.second < B.second;
    return A.first > B.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector< pair< double, int> > temp;
    vector<int> vec(N+2);
    int total = stages.size();
    for(auto i : stages){
        vec[i]++;
    }


    for(int i=1; i<N+1; ++i){
        if(total == 0){
            temp.push_back(make_pair(0, i));
            continue;
        }
        temp.push_back(make_pair((double)vec[i] / (double)total, i));
        total -= vec[i];
    }

    sort(temp.begin(), temp.end(), compare);

    vector<int> answer;
    return answer;
}