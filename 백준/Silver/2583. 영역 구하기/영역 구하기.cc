#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100
//1은 영역포함 X
int arr[MAX][MAX] = {0, };
bool visit[MAX][MAX];
int M,N,K, cnt = 0;
vector<int> output;

//동서남북
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void DFS(int x, int y) {
    cnt++;
    visit[x][y] = true;
    for(int i=0;i<4;i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if(0 <= nextX && nextX < N && 0 <= nextY && nextY < M) {
            if(arr[nextX][nextY] == 0 && !visit[nextX][nextY]) {
                DFS(nextX, nextY);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int startX, startY, endX, endY;
    cin >> M >> N >> K;

    for(int k=0;k<K;k++) {
        cin >> startX >> startY >> endX >> endY;
        for(int i=startX;i<endX;i++) {
            for(int j=startY;j<endY;j++) {
                arr[i][j] = -1;
            }
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(arr[i][j] != -1 && !visit[i][j]) {
                cnt = 0;
                DFS(i,j);
                output.push_back(cnt);
            }
        }
    }
    
    sort(output.begin(), output.end());
    cout << output.size() << "\n";
    for(int i=0;i<output.size();i++) {
        cout << output[i] << " ";
    }
    return 0;
}