#include <bits/stdc++.h>

using namespace std;

bool Palin(string str) {
    vector<int> vt(1000);
    for (int i = 0; i < str.length(); i++){
        vt[str[i] - 'a']++;
    }

    int cnt = 0;
    for (int i = 0; i < vt.size(); i++){
        if(vt[i] % 2) cnt++;
    }

    return str.length()%2 == cnt;
}


int main(int argc, const char** argv) {
   int n;
   string str;
   cin >> n;
   cin >> str;
   int ans = n;
    for (int i = 2; i <= n; i++){
        for (int j = 0; j <= n - i; j++){
            string p = str.substr(j, i);
            if(Palin(p)) ans++;
        }
   }
   cout << ans;
}