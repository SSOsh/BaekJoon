#include <iostream>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, result = 0;
//value가 세로값
int queen[15];

bool check(int x) {
    for(int i=0;i<x;i++) {
            //y축 확인 값이 같음
        if((queen[i] == queen[x]) || 
            //우상향 확인 x차이 + y차이 == 0
            ((i - x) + (queen[i] - queen[x]) == 0) || 
            //우하향 확인 x-y 차이값이 같음
            (queen[i] - i == queen[x] - x)) {
            return false;
        }
    }
    return true;
}

//가로 0부터 끝까지 하나씩 놓는걸 목표
void dfs(int cnt) {
    if(cnt == n) {
        result++;
        return;
    }
    for(int i=0;i<n;i++) {
        //안되는거 체크
        queen[cnt] = i;
        if(check(cnt)) {
            dfs(cnt + 1);
        }
    }
}

int main() {
    init();
    cin >> n;
    dfs(0);
    cout << result;
    return 0;
}