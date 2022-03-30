#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int* value;
void print() {
  for(int i=0;i<arr.size();i++)   {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

void dfs(int max, int cnt, int current) {
  if(cnt == current) {
    print();
    return;
  }
  for(int i=0;i<max;i++) {
    arr.push_back(value[i]);
    dfs(max, cnt, current + 1);
    arr.pop_back();
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int m,n;
  cin >> m >> n;
  value = new int[m];
  for(int i=0;i<m;i++) {
    value[i] = i+1;
  }
  dfs(m, n, 0);
  return 0;
}