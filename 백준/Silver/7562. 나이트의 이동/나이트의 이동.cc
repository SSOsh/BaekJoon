#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 300

int SIZE;
int arr[MAX][MAX];
bool visit[MAX][MAX];

//8방향 12시부터 시계방향
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int bfs(vector<int> start, vector<int> end) {
    int result = 0;
    queue<vector<int>> queue;
    queue.push(start);
    visit[start[0]][start[1]] = true;
    while(queue.size() > 0) {
        vector<int> front = queue.front();
        queue.pop();
        
        if(front[0] == end[0] && front[1] == end[1]) return front[2];
        for(int i=0;i<8;i++) {
            int nextX = front[0] + dx[i];
            int nextY = front[1] + dy[i];
            if(0 <= nextX && nextX < SIZE && 0 <= nextY && nextY < SIZE) {
                if(!visit[nextX][nextY]) {
                    vector<int> value = {nextX, nextY, front[2] + 1};
                    visit[value[0]][value[1]] = true;
                    queue.push(value);
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    int x, y;
    cin >> T;
    for(int t=0;t<T;t++) {
        cin >> SIZE;
        cin >> x >> y;
        vector<int> start = {x,y,0};
        cin >> x >> y;
        vector<int> end = {x,y};
        cout << bfs(start, end) << "\n";

        for(int i=0;i<SIZE;i++) {
            for(int j=0;j<SIZE;j++) {
                visit[i][j] = false;
            }
        }
    }


    return 0;
}