#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 50

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K, cnt = 0, result = 0;
    int values[MAX];
    
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        cin >> values[i];
        if(values[i] < 0) cnt++;
    }
    sort(values, values + N);
    for(int i=0;i<cnt;i+=K) {
        result += abs(values[i]) * 2;
    }
    for(int i=N-1;i>=cnt;i-=K) {
        result += values[i] * 2;
    }
    if(abs(values[0]) > values[N-1]) {
        result -= abs(values[0]);
    }
    else {
        result -= values[N-1];
    }
    cout << result << "\n";
    return 0;
}