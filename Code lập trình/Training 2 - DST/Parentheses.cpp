#include<bits/stdc++.h>
 
using namespace std;
 
bool check(char a, char b){
    if (a == '(' && b == ')') return true;
    if (a == '[' && b == ']') return true;
    if (a == '{' && b == '}') return true;
    return false;
}
 
bool Solve(string x){
    int n = x.length();
    stack<char> S;
    for (int i = 0; i < n; i++){
        if (x[i] == '(' || x[i] == '[' || x[i] == '{'){
            S.push(x[i]);
        }else{
            if (S.empty()) return false;
            else{
                char c = S.top();
                S.pop();
                if (!check(c, x[i])) return false;
            }
        }
    }
    return S.empty();
}
 
int main(int argc, const char** argv) {
    int T;
    cin >> T;
    string str;
    for (int i = 1; i <= T; i++){
        cin >> str;
        cout << Solve(str) << endl;
    }
    return 0;
}