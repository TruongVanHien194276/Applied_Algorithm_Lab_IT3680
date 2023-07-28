#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char** argv) {
    string str;
    cin >> str;

    stack<char> AC;
    for (int i = 0; i < str.size(); i++){
        char ch = str[i];

        if (!AC.empty() && ch == AC.top())
            AC.pop();
        else AC.push(ch);
    }
    if (AC.empty())
        cout << "Yes";
    else cout << "No";
    return 0;
}