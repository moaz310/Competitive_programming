#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 10;
vector<char> perm;
vector<vector<char> > res;
char s[MAX];
int main(){
    scanf("%s", s);
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        perm.push_back(s[i]);
    }
    sort(perm.begin(), perm.end());
    do{
        res.push_back(perm);
    }while (next_permutation(perm.begin(), perm.end()));
    printf("%d\n", res.size());
    for(auto u: res){
        for(char c: u){
            printf("%c", c);
        }
        puts("");
    }
    return 0;
}
