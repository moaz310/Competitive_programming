#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e6+6;
char s[MAX];
int main(){
    scanf("%s", s);
    int n = strlen(s);
    int res = 1, cnt = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]){
            cnt++;
        }
        else{
            cnt = 1;
        }
        res = max(res, cnt);
    }
    printf("%d", res);
    return 0;
}
