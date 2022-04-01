#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int cnt;
  long long value;
  cin >> cnt;
  long long prev1 = 0, prev2 = 1, current = 1;
  if(cnt == 0) {
    cout << 0;
  }
  else if(cnt == 1) {
    cout << 1;
  }
  else if(cnt == 2) {
    cout << 1;
  }
  else {
    for(int i=0;i<cnt - 1;i++) {
      current = prev1 + prev2;
      prev1 = prev2;
      prev2 = current;
    }
    cout << current;
  }
  
   
  return 0;
}