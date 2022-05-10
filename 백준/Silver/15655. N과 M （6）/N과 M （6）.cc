#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 8

int arr[MAX];
bool visit[MAX];
vector<int> result;
int n,m;

void back(int cnt, int current) {
    if(cnt == m) {
        for(int i=0;i<result.size();i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=current;i<n;i++) {
        if(!visit[i]) {
            visit[i] = true;
            result.push_back(arr[i]);
            back(cnt+1, i);
            result.pop_back();
            visit[i] = false;
        }
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