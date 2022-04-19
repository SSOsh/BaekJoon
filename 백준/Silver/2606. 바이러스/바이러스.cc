#include <iostream>
#include <vector>
using namespace std;

#define MAX 1001

vector<int> map[MAX];
bool visit[MAX];
bool isInfection[MAX];
int result;
void DFS(int v) {
	if (visit[v]) return;
	visit[v] = true;
	isInfection[v] = true;
	++result;
	while (!map[v].empty()) {
		int val = map[v].back();
		map[v].pop_back();
		DFS(val);
	}
}

int main() {
	int n, m;
	result = -1;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < MAX; i++) {
		visit[i] = false;
		isInfection[i] = false;
	}
	isInfection[1] = true;
	int val1, val2;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &val1, &val2);
		map[val1].push_back(val2);
		map[val2].push_back(val1);
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i] && isInfection[i]) {
			DFS(i);
		}
	}
	printf("%d", result);
	return 0;
}