#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e6;
int frq[27];
char s[MAX];
int main(){
    scanf("%s", s);
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        frq[s[i] - 'A']++;
    }
    int cntOdd = 0, idxOdd = 26;
    for(int i = 0; i < 26; i++){
        if(frq[i]&1){
            cntOdd++;
            idxOdd = i;
        }
    }
    if(cntOdd > 1){
        puts("NO SOLUTION");
    }
    else{
        stringstream ss;
        for(int i = 0; i < 26; i++){
            if(frq[i] && frq[i]%2 == 0){
                frq[i]/=2;
                for(int j = 0; j < frq[i]; j++){
                    ss << (char)(i + 'A');
                }
            }
        }
        string x = ss.str();
        printf("%s", x.c_str());
        char c = idxOdd + 'A';
        while(true){
            if(frq[idxOdd] <= 0) break;
            frq[idxOdd]--;
            printf("%c", c);
        }
        n = x.size();
        for(int i = n-1; i >= 0; i--) printf("%c", x[i]);
    }
    return 0;
}
