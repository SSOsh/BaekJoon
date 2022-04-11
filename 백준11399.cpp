#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, basket = 0, result = 0;
    cin >> n;
    int arr[1000];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for(int i=0;i<n;i++) {
        basket += arr[i];
        result += basket;
    }
    cout << result << "\n";
    return 0;
}