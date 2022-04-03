#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<int> result;
int maximum;

void print() {
  for(int i=0;i<result.size();i++) {
    cout << result[i] << " ";
  }
  cout << "\n";
}

bool check(int value){
  for(int i=0;i<result.size();i++) {
    if(value == result[i]) {
      return false;
    }
  }
  return true;
}

void dfs(int current, int destination) {
  if(current == destination) {
    print();
    return;
  }
  for(int i=0;i<maximum;i++) {
    if(check(arr[i])) {
      result.push_back(arr[i]);
      dfs(current + 1, destination);
      result.pop_back();
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, tmp;
  cin >> maximum >> n;
  for(int i=0;i<maximum;i++) {
    cin >> tmp;
    arr.push_back(tmp);
  }
  sort(arr.begin(), arr.end());
  dfs(0, n);
  return 0;
}