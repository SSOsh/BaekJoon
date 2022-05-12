#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> result;
int visit[13];
int n, tmp;

void back(int cnt, int goal) {
    if(cnt == goal) {
        for(int i=0;i<goal;i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=cnt;i<n - 5 + cnt;i++) {
        if(!visit[i]) {
            if(!result.empty()) {
                if(result.back() < arr[i]){
                    visit[i] = true;
                    result.push_back(arr[i]);
                    back(cnt+1, goal);
                    result.pop_back();
                    visit[i] = false;
                }
            }
            else {
                visit[i] = true;
                result.push_back(arr[i]);
                back(cnt+1, goal);
                result.pop_back();
                visit[i] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    while(true) {
        if(n == 0) break;
        for(int i=0;i<n;i++) {
            cin >> tmp;
            arr.push_back(tmp);
        }
        sort(arr.begin(), arr.end());
        unique(arr.begin(), arr.end());

        back(0, 6);
        cin >> n;
        if(n != 0) cout << "\n";
        arr.clear();
    }
    
    
    return 0;
}