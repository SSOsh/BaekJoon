#include <iostream>
#include <vector>
using namespace std;

#define MAX 50
int arr[MAX][MAX];
bool visit[MAX][MAX];
int result, w = -1, h = -1;

//북 북서 서 남서 남 남동 동 북동
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};

void DFS(int x, int y) {
    visit[x][y] = true;
    for(int i=0;i<8;i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if(0 <= nextX && nextX < w && 0 <= nextY && nextY < h) {
            if(arr[nextX][nextY] == 1 && !visit[nextX][nextY]) {
                DFS(nextX, nextY);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(true) {
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        result = 0;

        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                cin >> arr[j][i];
            }
        }
        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                if(arr[j][i]==1 && !visit[j][i]) {
                    DFS(j,i);
                    result++;
                }
            }
        }
        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                visit[j][i] = false;
            }
        }
        cout << result << "\n";
    }
    
    return 0;
}