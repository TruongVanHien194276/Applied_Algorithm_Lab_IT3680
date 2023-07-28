#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char** argv) {
    vector <int> zero; vector <int> positive; vector <int> negative;

    int n, zero_start;
    scanf("%d", &n);

    vector <int> A(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);


    sort(A.begin(), A.end());

    if(A.back() > 0){
        positive.push_back(A.back());
        A.pop_back();

        negative.push_back(A.front());

        zero_start = 1;
    }else{
        positive.push_back(A[0]);
        positive.push_back(A[1]);

        negative.push_back(A[2]);

        zero_start = 3;
    }

    for (int i = zero_start; i < A.size(); i++)
        zero.push_back(A[i]);

    printf("1 %d\n",negative.back());

    printf("%u ", positive.size());
    for (int i = 0; i < positive.size(); i++)
        printf("%d ",positive[i]);

    printf("\n%u ", zero.size());
    for (int i = 0; i < zero.size(); i++)
        printf("%d ",zero[i]);

    return 0;
}