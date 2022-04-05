#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int arr[25][25];
bool visit[25][25];
vector<int> house;
int result = 1;

//동서남북
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int max, int currentX, int currentY, int value) {
    arr[currentX][currentY] = value;
    visit[currentX][currentY] = true;
    house[value - 1] += 1;
    
    for(int i=0;i<4;i++) {
        int nextX = dx[i] + currentX;
        int nextY = dy[i] + currentY;

        if(nextX > -1 && max > nextX && nextY > -1 && max > nextY && !visit[nextX][nextY] && arr[nextX][nextY] != 0) {
            dfs(max, nextX, nextY, value);
        }
    }
    
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
    
	cin >> m;
	for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
		for (int j = 0; j < m; j++) {
			arr[i][j] = tmp[j] - '0';
		}
	}
    for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
            if(!visit[i][j] && (arr[i][j] != 0)) {
                house.push_back(0);
                dfs(m, i, j, result);
                result += 1;
            }
		}
	}
    sort(house.begin(), house.end());
    cout << house.size() << "\n";
    for(int i=0;i<house.size();i++) {
        cout << house[i] << "\n";
    }
	return 0;
}