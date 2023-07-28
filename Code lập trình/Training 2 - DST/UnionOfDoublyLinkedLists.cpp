#include<bits/stdc++.h>

using namespace std;

const int N = 105;

int n, head;
struct node{
    int left;
    int right;
    int value;
}a[N];

int main(int argc, const char** argv) {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].left >> a[i].right;
        a[i].value = i;
        if (!head && !a[i].left){
            head = a[i].value;
        }
    }

    int num = head;
    while (a[num].right != head){
        bool flag = true;
        if (a[num].right){
            num = a[num].right;
        }else{
            for (int i = 1; i <= n; i++){
                if (i == head) continue;
                if (!a[i].left){
                    a[i].left = a[num].value;
                    a[num].right = a[i].value;
                    num = a[i].value;
                    flag = false;
                    break;
                }
            }
            
            if (flag) break;
        }
    }

    for (int i = 1; i <= n; i++){
        cout << a[i].left << " " << a[i].right << endl;
    }
    return 0;
}