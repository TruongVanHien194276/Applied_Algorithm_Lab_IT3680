
#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000001;

int n;
int a[MAX], s[MAX];

void inputData(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

int MaxSub(){
    s[1] = a[1];
    int ans = s[1];
    for (int i = 2; i <= n; i++){
        if (s[i-1] > 0){
            s[i] = s[i-1] + a[i];
        }else{
            s[i] = a[i];
        }

        ans = max(ans, s[i]);
    }
    return ans;
}

int main(int argc, const char** argv) {
    inputData();
    cout << MaxSub();
    return 0;
}


