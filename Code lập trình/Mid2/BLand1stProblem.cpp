#include<bits/stdc++.h>
 
using namespace std;
 
const int MAX = 20010;
 
int n, k;
int x[MAX], y[MAX];
bool visited[MAX];
 
void inputData(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
		visited[i] = false;
	}
}
 
void DFS(int u){
    visited[u] = true;
    for (int i = 2; i <= n; i++){
    	if (!visited[i]){
    	    if(floor(sqrt((double)((x[i]-x[u])*(x[i]-x[u])+(y[i]-y[u])*(y[i]-y[u])))) <= k){
            	DFS(i);
            }
        }
	}
}
 
int main(int argc, const char** argv) {
	inputData();
	DFS(1);
 
	if (visited[n]) cout << "YES";
	else cout << "NO";
 
    return 0;
}