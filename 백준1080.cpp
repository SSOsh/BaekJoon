#include <iostream>
#include <string>
using namespace std;
#define MAX 51
int start[MAX][MAX];
int endd[MAX][MAX];
int n,m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt = 0;
    cin >> n >> m;
    //입력
    string splitter;
    for(int i=0;i<n;i++) {
        cin >> splitter;
        for(int j=0;j<m;j++) {
            start[i][j] = splitter[j] - '0';
        }
    }
    for(int i=0;i<n;i++) {
        cin >> splitter;
        for(int j=0;j<m;j++) {
            endd[i][j] = splitter[j] - '0';
        }
    }
    
    //크기가 3 이하일때 바꿀 필요가 없다면 0 아니면 -1
    if(n < 3 || m < 3) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(start[i][j] != endd[i][j]) {
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    }
    else {
        //for문으로 돌면서 바꿀 부분이 있는지 체크
        for(int i=0;i<n - 2;i++) {
            for(int j=0;j<m - 2;j++) {
                //값이 다르면 switch
                if(start[i][j] != endd[i][j]) {
                    for(int k = i;k <=i + 2;k++) {
                        for(int l = j;l <= j + 2;l++) {
                        start[k][l] = 1 - start[k][l];
                        }
                    }
                    cnt++;
                }
            }
        }
        //시작 값과 끝 값의 동일여부 확인
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(start[i][j] != endd[i][j]) {
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
