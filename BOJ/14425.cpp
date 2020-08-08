#include <bits/stdc++.h>

using namespace std;

const int ALPHABET = 26;
int toNumber(char ch){return ch - 'a';}

struct TrieNode{
    TrieNode* children[ALPHABET];
    bool terminal;

    TrieNode() : terminal(false){
        memset(children, 0, sizeof(children));
    }

    ~TrieNode(){
        for(int i=0; i<ALPHABET; ++i){
            if(children[i])
                delete children[i];
        }
    }

    void insert(const char* key){
        if(*key == 0){
            terminal = true;
        }
        else{
            int next = toNumber(*key);
            if(children[next] == NULL){
                children[next] = new TrieNode();
            }
            children[next]->insert(key + 1);
        }
        
    }

    bool find(const char* key){
        if(*key == 0) return terminal;
        int next = toNumber(*key);
        if(children[next] == NULL) return false;
        return children[next]->find(key + 1);
    }
};

int N,M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    TrieNode* node = new TrieNode();

    for(int i=0; i<N; ++i){
        char ch[500];
        cin >> ch;
        node->insert(ch);
    }
    int cnt = 0;
    for(int i=0; i<M; ++i){
        char ch[500];
        cin >> ch;        
        if(node->find(ch)){
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}