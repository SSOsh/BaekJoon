#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pair<int, int> arr[MAX];
    int t, n;
    cin >> t;
    for(int i=0;i<t;i++) {
        //첫번째 지원자는 무조건 합격하니 result는 1로 시작
        int result = 1;
        cin >> n;
        for(int j=0;j<n;j++) {
            int first, second;
            cin >> arr[j].first >> arr[j].second;
        }
        sort(arr, arr + n);
        //두번째의 최저점
        int value = arr[0].second;        
        for(int j=0;j<n;j++) {
            if(value > arr[j].second) {
                result++;
                value = arr[j].second;
            }
        }
        cout << result << "\n";
    }
    return 0;
}
