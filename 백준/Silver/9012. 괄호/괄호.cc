#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    stack<char> stack;
    int n;
    bool dist = false;
    string str;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> str;
        for(int j=0;j<str.length();j++) {
            if(str[j] == '(') {
                stack.push('(');
            }
            else {
                if(stack.empty()) {
                    dist = true;
                    break;
                }
                stack.pop();
            }
        }
        if(dist) {
            cout << "NO\n";
            dist = false;
        }
        else {
            if(stack.size() == 0) {
                cout << "YES\n";
            }else {
                cout << "NO\n";
            }
        }
        while(stack.size() > 0) {
            stack.pop();
        }
    }    
    return 0;
}