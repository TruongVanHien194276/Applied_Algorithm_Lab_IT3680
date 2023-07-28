#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char** argv) {
    stack<int> s;
    string a;
    int sum[100005];
    map<char, int> m;
    m['('] = 1;
    m[')'] = -1;
    m['['] = 2;
    m[']'] = -2;

    cin >> a;
    sum[0] = (a[0] == '[');

    for(int i = 1; i < a.length(); i++){
        sum[i] = sum[i-1] + (a[i] == '[');
    }

    for(int i = 0; i < a.length(); i++){
        if (a[i] == '(' || a[i] == '[' || s.empty())
            s.push(i);
        else if (m[a[i]] + m[a[s.top()]] == 0)
            s.pop();
        else s.push(i);

    }

    if (s.empty()){
        int ans=0;
        ans = sum[a.length() - 1];
        cout << sum[a.length() - 1] << endl;
        if(ans){
            cout << a << endl;
        }
    }else{
        int ans=0;
        int ss, e, ns, ne;
        e = a.length() - 1;
        if (sum[e] - sum[s.top()] > ans){
            ans = sum[e] - sum[s.top()];
            ns = s.top() + 1;
            ne = e;
        }
        while(s.size() > 1){
            e = s.top()-1;
            s.pop();
            ss = s.top();
            if (sum[e] - sum[ss] > ans){
                ans = sum[e] - sum[ss];
                ns = ss+1;
                ne = e;
            }
        }
        e = s.top();
        if (s.top() > 0)
            e = e - 1;
        if (e == 0)
            sum[0] = 0;
        if (sum[e] > ans){
            ans = sum[e];
            ns = 0;
            ne = e;
        }
        if (ans){
            cout << ans << endl;
            for (int i = ns; i <= ne; i++){
                cout << a[i];
            }
            cout<<endl;
        }else cout << 0 << endl;
    }

    return 0;

}