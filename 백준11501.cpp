#include <iostream>
using namespace std;

#define MAX 1000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[MAX];
    int T, N;
    cin >> T;
    int maxValue;
    long long result;
    for(int t =0;t<T;t++) {
        cin >> N;
        result = 0;
        for(int i=0;i<N;i++) {
            cin >> arr[i];
        }
        maxValue = arr[N-1];
        for(int i=N-1;i>=0;i--) {
            if(maxValue > arr[i]) {
                result += maxValue - arr[i];
            }
            else {
                maxValue = arr[i];
            }
        }
        cout << result << "\n";
    }
    return 0;
}