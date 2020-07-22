#include <iostream>

using namespace std;

const int ALPHABETS = 26;
int toNumber(char ch){ return ch - 'A';}

struct TrieNode{
    TrieNode* children[ALPHABETS];
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
        if(*key == 0)
            terminal = true;
        else{
            int next = toNumber(*key);

            if(children[next] == NULL){
                children[next] = new TrieNode();
            }
            children[next]->insert(key + 1);
        }
    }

    TrieNode* find(const char* key){
        if(*key == 0) return this;
        int next = toNumber(*key);
        if(children[next] == NULL) return NULL;
        return chilren[next]->find(key+1);
    }
}

// terminal 변수를 정수형으로 바꾸면 간단하게 문자열을 정수로 대응하는 사전 자료 구조가 되므로, map<string, int> 로 대체할 수 있다.