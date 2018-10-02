#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int MX = (1<<21);
typedef long long ll;
bitset < MX > ans;
int T , arr[MX];
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n < 8){
            if(n == 1 || n == 2 || n == 3 || n == 6) puts("Siroj");
            else puts("Ghayeeth");
        }
        else{
            n %= 8;
            if(n == 0 || n == 2 || n == 3 || n == 5) puts("Siroj");
            else puts("Ghayeeth");
        }
    }
}
