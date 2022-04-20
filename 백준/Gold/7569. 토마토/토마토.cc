#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 101
//가로 세로 높이
int n,m,h;
int visit[MAX][MAX][MAX];
int arr[MAX][MAX][MAX];

//동서남북상하
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,-1,1};

//안익은게 있는지 확인
bool check() {
    for(int i=0;i<h;i++) {
        for(int j=0;j<n;j++) {
            for(int k=0;k<m;k++) {
                if(arr[k][j][i] == 0) return false;
            }
        }
    }
    return true;
}

int BFS(vector<vector<int>> start) {
    //x, y, z, 시간
    queue<vector<int>> queue;
    while(start.size() > 0) {
        queue.push(start.back());
        start.pop_back();
    }
    vector<int> value;
    while(queue.size() > 0) {
        value = queue.front();
        queue.pop();
        visit[value[0]][value[1]][value[2]] = true;

        int nextX, nextY, nextZ;
        //동서남북상하 확인
        for(int i=0;i<6;i++) {
            nextX = value[0] + dx[i];
            nextY = value[1] + dy[i];
            nextZ = value[2] + dz[i];    
            //범위체크
            if(0 <= nextX && nextX < m && 0 <= nextY && nextY < n && 0 <= nextZ && nextZ < h) {
                //익지않고 이미 탐색하지 않았는지 확인
                if((arr[nextX][nextY][nextZ] == 0) && !visit[nextX][nextY][nextZ]) {
                    vector<int> input;
                    input.push_back(nextX);
                    input.push_back(nextY);
                    input.push_back(nextZ);
                    input.push_back(value[3] + 1);
                    arr[nextX][nextY][nextZ] = 1;
                    queue.push(input);
                }
            }
        }
    }
    return value[3];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> start;
    cin >> m >> n >> h;
    for(int i=0;i<h;i++) {
        for(int j=0;j<n;j++) {
            for(int k=0;k<m;k++) {
                cin >> arr[k][j][i];
                if(arr[k][j][i] == 1) {
                    vector<int> tmp;
                    tmp.push_back(k);
                    tmp.push_back(j);
                    tmp.push_back(i);
                    tmp.push_back(0);
                    start.push_back(tmp);
                }
            }
        }
    }
    if(start.size() == 0) {
        cout << "-1\n";
    }
    else {
        int result = BFS(start);
        if(check()) {
            cout << result << "\n";
        }
        else {
            cout << "-1\n";
        }
    }
    return 0;
}
