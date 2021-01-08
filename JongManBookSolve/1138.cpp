#include <cstdio>
using namespace std;

int main() {
    
    int n, i, j, left;
    int arr[10] = { 0, };

    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &left);

        for (j = 0; j < n; j++) {
            if (!left && arr[j] == 0) {
                
                arr[j] = i + 1;
                break;
            }
            else if (arr[j] == 0) {
                left--;
            }
        }
    }

    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}