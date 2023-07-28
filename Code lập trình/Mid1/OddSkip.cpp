#include<bits/stdc++.h>

using namespace std;

long long L, R;

long long OddSkip(){
    if (L % 2 == 1 && R % 2 == 1){
        return (R - L)/2;
    }else if (L % 2 == 0 && R % 2 == 0){
        return (R - L)/2 + 1;
    }else{
        return (R - L + 1)/2;
    }
}

int main(int argc, const char** argv) {
    cin >> L >> R;
    cout << OddSkip();
    return 0;
}