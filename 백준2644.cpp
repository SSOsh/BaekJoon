#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 101
//노드당 거리
int dist[MAX] = {0, };

vector<int> v[MAX];

int bfs(int start, int endd) {
  queue<int> queue;
  queue.push(start);

  while(!queue.empty()) {
    int front = queue.front();
    queue.pop();

    if(front == endd) {
      return dist[endd];
    }
    int size = v[front].size();
    
    for(int i=0;i<size;i++) {
      int value = v[front][i];
      if(!dist[value]) {
        queue.push(value);
        dist[value] = dist[front] + 1;
      }
    }
  }
  return -1;
}

int main() {
  int n, start, endd, m, x, y;
  cin >> n;
  cin >> start >> endd;
  cin >> m;
  for(int i=0;i<m;i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  cout << bfs(start, endd) << "\n";
    return 0;
}