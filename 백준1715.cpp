#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 100000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<long long, vector<long long>, greater<int>> arr;
    int N;
    cin >> N;
    long long value;
    for(int i=0;i<N;i++) {
        cin >> value;
        arr.push(value);
    }
    long long result = 0;

    while(arr.size() > 1) {
        long long first = arr.top();
        arr.pop();
        long long second = arr.top();
        arr.pop();
        result += first + second;
        arr.push(first + second);
    }
    cout << result << "\n";
    return 0;
}
