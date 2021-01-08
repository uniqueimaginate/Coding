#include <iostream>
#include <string>
#define SIZE 5

using namespace std;

int c;
char arr[SIZE][SIZE];

const int dx[8] = { -1, -1, -1,  1,  1,  1,  0, 0 };
const int dy[8] = { -1,  0,  1, -1,  0,  1, -1, 1 };

bool notInRange(int y, int x);

bool hasWord(int y, int x, const string& word){
    if(notInRange(y,x)) return false;
    if(arr[y][x] != word[0]) return false;
    if(word.size() == 1) return true;

    for(int direction = 0; direction < 8; ++direction){
        int nextY = y + dy[direction], nextX = x + dx[direction];
        if(hasWord(nextY, nextX, word.substr(1)))
            return true;
    }
    return false;
}

bool notInRange(int y, int x){
    if(x < 0 || y < 0 || x > 4 || y > 4)
        return true;
    else
        return false;    
}

int main(){
    cin >> c;
    while(c--){
        for(int i=0; i<5; ++i){
            for(int j=0; j<5; ++j){
                cin >> arr[i][j];
               
            }
        }
        int n;
        cin >> n;
        while(n--){
            string temp;
            bool flag = false;
            cin >> temp;
            for(int i=0; i<SIZE; ++i){
                for(int j=0; j<SIZE; ++j){
                    if(hasWord(i,j,temp)){
                        flag = true;
                        break;
                    }
                }
                if(flag)
                    break;
            }
            if(flag)
                cout << temp << " " << "YES" << endl;
            else
                cout << temp << " " << "NO" << endl;
            
        }
    }
}