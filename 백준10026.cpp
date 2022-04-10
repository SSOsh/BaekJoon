#include <iostream>
#include <string>
using namespace std;

#define MAX 100
bool visit[MAX][MAX];
bool bVisit[MAX][MAX];
string arr[MAX][MAX];
int n;
//동서남북
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

//R과 G를 하나로
void blindDFS(int x, int y, string value) {
    bVisit[x][y] = true;

    for(int i=0;i<4;i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if(value == "R" || value == "G") {
            if(0 <= nextX  && nextX < n && 0 <= nextY && nextY < n) {
                if((arr[nextX][nextY] == "R") || (arr[nextX][nextY] == "G")) {
                    if(!bVisit[nextX][nextY])
                    blindDFS(nextX, nextY, value);
                }
            }
        }
        else {
            if(0 <= nextX  && nextX < n && 0 <= nextY && nextY < n) {
                if(arr[nextX][nextY] == value && !bVisit[nextX][nextY]) {
                    blindDFS(nextX, nextY, value);    
                }
            }
        }
    }
}
void DFS(int x, int y, string value) {
    visit[x][y] = true;
    for(int i=0;i<4;i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if(0 <= nextX && nextX < n && 0 <= nextY && nextY < n) {
            if(arr[nextX][nextY] == value && !visit[nextX][nextY]) {
                DFS(nextX, nextY, value);
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string tmp;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> tmp;
        for(int j=0;j<n;j++) {
            arr[i][j] = tmp[j];
        }
    }
    int result=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(!visit[i][j]) {
                DFS(i,j, arr[i][j]);
                result++;
            }
        }
    }
    cout << result << " ";
    result = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(!bVisit[i][j]) {
                blindDFS(i,j, arr[i][j]);
                result++;    
            }
        }
    }
    cout << result << "\n";
    
    return 0;
}