#include <bits/stdc++.h>

using namespace std;

int cache[101][101];
string W,S;

bool match(const string& w, const string& s){
    int pos = 0;
    while(pos < s.size() && pos < w.size() &&
            (w[pos] == '?' || w[pos] == s[pos]))
        ++pos;
    
    if(pos == w.size()) return pos == s.size();

    if(w[pos] == '*')
        for(int i=0; pos + i <= s.size(); ++i){
            if(match(w.substr(pos + 1), s.substr(pos + i)))
                return true;
        }
    return false;
}

int matchMemoized(int w, int s){
    int& ret = cache[w][s];
    if(ret != -1) return ret;
    while(w < W.size() && s < S.size() &&
            (W[w] == '?' || W[w] == S[s])){
        ++w;
        ++s;
    }
    if(w == W.size()) return ret = s == S.size();


    if(W[w] == '*'){
        for(int i=0; s+i <= S.size(); ++i){
            if(matchMemoized(w+1, s+i))
                return ret = 1;
        }
    }
    return ret = 0;
}

int main(){
    memset(cache, -1, sizeof(cache));

    int C;
    cin >> C;
    while(C--){
        int n;
        
        cin >> W;
        cin >> n;
        vector<string> vec;

        while(n--){
            cin >> S;
            if(matchMemoized(0, 0))
                vec.push_back(S);
            memset(cache, -1, sizeof(cache));
        }
        sort(vec.begin(), vec.end());
        for(int i=0; i<vec.size(); ++i){
            cout << vec[i] << endl;
        }
        vec.clear();
        memset(cache, -1, sizeof(cache));
    }
}