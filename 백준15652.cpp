#include <iostream>
#include <vector>
#define MAX 8

using namespace std;

int* arr;
vector<int> result;
int m, n;

void print() {
  for(int i=0;i<result.size();i++) {
    cout << result[i] << " ";
  }
  cout << "\n";
}

void dfs(int current, int prev) {
  if(current == n) {
    print();
    return;
  }
  for(int i=prev;i<m;i++) {
    result.push_back(arr[i]);
    dfs(current+1, i);
    result.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  arr = new int[MAX];
  cin >> m >> n;
  for(int i=0;i<m;i++) {
    arr[i] = i+1;
  }
  
  dfs(0, 0);
  return 0;
}