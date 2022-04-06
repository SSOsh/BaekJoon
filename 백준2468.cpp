#include <iostream>
#include <vector>


using namespace std;

#define MAX 100
int N, maximum;
int arr[100][100];
int visit[100][100];
int result = 0;

//동서남북
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int destination, int x, int y) {

    visit[x][y] = true;
    for(int i=0;i<4;i++) {
        int nextX = dx[i] + x;
        int nextY = dy[i] + y;
        if(0 <= nextX && nextX < N && 0 <= nextY && nextY < N && (arr[nextX][nextY] > destination) && !visit[nextX][nextY]) {
            dfs(destination, nextX, nextY);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    maximum = -1;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
            if(arr[i][j] > maximum) {
                maximum = arr[i][j];
            }
        }
    }

    for(int i=0;i<((maximum > MAX)?MAX:maximum);i++) {
        int cnt = 0;
        for(int x=0;x<N;x++) {
            for(int y=0;y<N;y++) {
                if(!visit[x][y] && arr[x][y] > i) {
                    dfs(i, x, y);
                    cnt++;
                }
            }
        }
        if(cnt > result) {
            result = cnt;
        }
        //visit초기화
        for(int x=0;x<N;x++) {
            for(int y=0;y<N;y++) {
                visit[x][y] = false;
            }
        }
    }
    cout << result << "\n";
    return 0;
}