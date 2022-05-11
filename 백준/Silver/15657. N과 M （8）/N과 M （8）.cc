#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 8
int m,n;
int arr[MAX];
vector<int> result;

void back(int cnt, int current) {
    if(cnt == m) {
        for(int i=0;i<m;i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=current;i<n;i++) {
        result.push_back(arr[i]);
        back(cnt+1, i);
        result.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    back(0, 0);
    
    return 0;
}