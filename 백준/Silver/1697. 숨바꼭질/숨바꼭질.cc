#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 100001
bool visit[MAX];

int BFS(int current, int goal) {
    //위치와 시간
    queue<pair<int, int>> queue;
    vector<int> arr;
    queue.push({current, 0});
    visit[current] = true;
    while(!queue.empty()) {
        int location = queue.front().first;
        int time = queue.front().second;
        queue.pop();
        if(location == goal) {
            return time;
        }
        if((location * 2) <= MAX && !visit[location * 2]) {
            queue.push({location * 2, time + 1});
            visit[location * 2] = true;
        }
        if((location + 1) <= goal && !visit[location + 1]) {
            queue.push({location + 1, time + 1});
            visit[location + 1] = true;
        }
        if((location - 1) >= 0 && !visit[location - 1]) {
            queue.push({location - 1, time + 1});
            visit[location - 1] = true;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    cout << BFS(n,k) << "\n";
    return 0;
}