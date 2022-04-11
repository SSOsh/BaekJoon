#include <iostream>
using namespace std;
#define MAX 10
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int coin[MAX];
    int result = 0;
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> coin[i];
    }
    for(int i=n-1;i>=0;i--) {
        if(coin[i] <= k) {
            result += k / coin[i];r
            k = k % coin[i];
        }
    }
    cout << result;
    return 0;
}