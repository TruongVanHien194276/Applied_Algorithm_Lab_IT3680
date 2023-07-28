#include<bits/stdc++.h>

using namespace std;

void wayString(string s){
    int lg = s.length();
    if (lg > 10){
        int count = lg-2;
        cout << s[0] << count << s[lg-1];
    }else{
        cout << s;
    }
}

int main(int argc, const char** argv) {
    int n;
    cin >> n;
    cin.ignore(32767, '\n');
    for (int i = 1; i <= n; i++){
        string s;
        getline(cin, s);
        wayString(s);
        cout << endl;
    }
    return 0;
}