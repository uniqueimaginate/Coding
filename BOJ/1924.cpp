#include <cstdio>
#include <cstring>
#include <string>

int main()
{
    int month, day;

    scanf("%d %d", &month, &day);

    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string arr1[7] = {"MON", "TUE", "WED","THU", "FRI", "SAT", "SUN"};


    int sub = month - 1;
    int result = 0;
    if(sub == 0){
        result = day - 1;
    }
    else{
        for(int i=0; i<sub; i++){
            result += arr[i];
        }
        result += day - 1;
    }

    result %= 7;
    printf("%s", arr1[result].c_str());

}
