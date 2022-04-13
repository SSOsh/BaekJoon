#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string A, B;
    cin >> A >> B;
    int sizeA = A.length();
    //길이 같아질때까지 반복
    while(sizeA < B.length()) {
        if(B.back() == 'A') {
            B.pop_back();
        }
        else {
            B.pop_back();
            reverse(B.begin(), B.end());
        }
    }
    if(A == B) cout << "1\n";
    else  cout << "0\n";
    return 0;
}
