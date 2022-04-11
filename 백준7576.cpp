#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000
int arr[MAX][MAX];
bool visit[MAX][MAX];
int m,n;

//동서남북
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int bfs(vector<vector<int>> startValue) {
    queue<vector<int>> queue;
    for(int i=0;i<startValue.size();i++) {
        vector<int> first;
        first.push_back(startValue[i][0]);
        first.push_back(startValue[i][1]);
        first.push_back(0);
        queue.push(first);
    }
    int result = 0;
    
    while(queue.size() > 0) {
        vector<int> value = queue.front();
        queue.pop();
        visit[value[0]][value[1]] = true;
        for(int i=0;i<4;i++) {
            int nextX = value[0] + dx[i];
            int nextY = value[1] + dy[i];
            if(0 <= nextX && nextX < m && 0 <= nextY && nextY < n) {
                if(!visit[nextX][nextY] && (arr[nextX][nextY] == 0)) {
                    arr[nextX][nextY] = 1;

                    vector<int> input;
                    input.push_back(nextX);
                    input.push_back(nextY);
                    input.push_back((value[2] + 1));
                    queue.push(input);
                }
            }
        }
        if(result < value[2]) result = value[2];
    }
    return result;
}

bool check() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[j][i] == 0) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    vector<vector<int>> startValue;
    int startX, startY;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> arr[j][i];
            if(arr[j][i] == 1) {
                vector<int> tmp;
                tmp.push_back(j);
                tmp.push_back(i);
                startValue.push_back(tmp);
            }
        }
    }
    int result = bfs(startValue);
    if(check()) {
        cout << result << "\n";
    }
    else {
        cout <<"-1\n";    
    }
    return 0;
}