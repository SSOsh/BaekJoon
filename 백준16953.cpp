#include <iostream>
#include <math.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, cnt = 1;
    cin >> a >> b;

    while(true) {
        if(b == a) break;
        if((b < a) || (b % 2 != 0 && b % 10 != 1)) {
            cout << "-1\n";
            return 0;
        }
        if(b % 10 == 1) {
            if((b / 10) < a) {
                cout << "-1\n";
                return 0;
            }
            b /= 10;   
        }
        else {
            b /= 2;
        }
        cnt++;
    }
    cout << cnt << "\n"; 
    return 0;
}