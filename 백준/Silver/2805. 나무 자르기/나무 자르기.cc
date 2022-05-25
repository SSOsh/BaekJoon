#include <iostream>
using namespace std;

#define MAX 1000000
int arr[MAX];
long long n, m, mid, wood;
long long bottom = 0, top = -1;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();
    cin >> n >> m;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
        if(arr[i] > top) top = arr[i];
    }
    int result = 0;
    while(bottom <= top) {
        mid = (bottom + top) / 2;
        wood = 0;
        for(int i=0;i<n;i++) {
            if(arr[i] > mid) wood += arr[i] - mid;
        }
        if(wood < m) {
            top = mid - 1;
        }
        else {
            result = mid;
            bottom = mid + 1;
        }
    }
    cout << result;
    return 0;
}