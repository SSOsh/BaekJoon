#include <iostream>
#include <cmath>
using namespace std;

int arr[21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k, result = 0, max = -1, maxValue = -1;
    cin >> k;
    for(int i=20;i>=0;i--) {
        arr[i] = pow(2,i);
        if(k <= arr[i]) {
            max = i;
            maxValue = arr[i];
        }
    }
    while(true) {
        if(k % maxValue == 0) {
            break;
        }
        else {
            maxValue /= 2;
            result++;
        }
    }
    cout << arr[max] << " " << result << "\n";
    return 0;
}
