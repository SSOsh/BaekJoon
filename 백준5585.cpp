#include <iostream>

using namespace std;

int result=0;
int yen[6] = {500, 100, 50, 10, 5, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int money;
    cin >> money;
    money = 1000 - money;
    while(true) {
        if(money == 0) break;

        for(int i=0;i<6;i++) {
            if(money >= yen[i]) {
                money -= yen[i];
                result++;
                break;
            }
            
        }
    }
    cout << result;
    return 0;
}