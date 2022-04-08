#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//-는 두개 묶어서 다 빼내는데 값이 가장 큰거부터 
//+도 두개 묶어서 값 큰거부터 곱

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<long long> minus;
    vector<int> zero;
    vector<long long> plus;

    int n;
    long long value;
    long long result = 0;
    cin >> n;
    
    for(int i=0;i<n;i++) {
        cin >> value;
        if(value == 1) result += 1;
        else if(value > 1) plus.push_back(value);
        else if(value == 0) zero.push_back(0);
        else minus.push_back(value);
    }
    sort(plus.begin(), plus.end());
    sort(minus.rbegin(), minus.rend());
    
    while(plus.size() > 0) {
        if(plus.size() == 1) {
            result += plus.back();
            plus.pop_back();
        }
        else if(plus.size() > 1) {
            long long first = plus.back();
            plus.pop_back();
            long long second = plus.back();
            plus.pop_back();
            result += first * second;
        }
    }
    while(minus.size() > 0) {
        if(minus.size() > 1) {
            long long first = minus.back();
            minus.pop_back();
            long long second = minus.back();
            minus.pop_back();
            //두개씩
            result += first * second;
        }
        else if(minus.size() == 1){
            if(zero.size() == 0) {
                result += minus.back();
            }
            minus.pop_back();
        }
    }

    cout << result;
    return 0;
}