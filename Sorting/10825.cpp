#include <iostream>
#include <algorithm>
#include <string>
#define ARR_SIZE 100000
using namespace std;


class Test{
    public:
        string name;
        int kor;
        int eng;
        int math;

        Test(){};
        Test(string _name, int _kor, int _eng, int _math) : name(_name), kor(_kor), eng(_eng), math(_math)
        {}

        void setInfo(string _name, int _kor, int _eng, int _math){
            name = _name;
            kor = _kor;
            eng = _eng;
            math = _math;
        }
};

int N;
Test arr[ARR_SIZE];
string name;
int k, e, m;

bool compare(const Test &a, const Test &b){
    if(a.kor > b.kor)
        return true;
    else if(a.kor == b.kor)
    {
        if(a.eng < b.eng){
            return true;
        }
        else if(a.eng == b.eng){
            if(a.math > b.math){
                return true;
            }
            else if(a.math == b.math){
                return a.name < b.name;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> name >> k >> e >> m;
        arr[i].setInfo(name, k, e, m);
    }

    sort(arr, arr+N, compare);
    for(int i=0; i<N; i++){
        cout << arr[i].name << '\n';
    }

    return 0;
}