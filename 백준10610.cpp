#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dist = 0;
    string value;
    cin >> value;
    
    sort(value.rbegin(), value.rend());
    if(value[value.length() - 1] != '0') cout << -1 << "\n";
    else {
        for(int i=0;i<value.length();i++) {
            dist += value[i];
        }
            if(dist % 3 == 0) {
            cout << value << "\n";
        }else {
            cout << -1 << "\n";
        }
    }
    return 0;
}