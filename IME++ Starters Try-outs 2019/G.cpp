#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
const int N = 1<<16;

struct segTree_sum{
    int tree[N<<1];
    int I = 0;

    int op(int a, int b){
        return a + b;
    }

    segTree_sum(){
        memset(tree, I, sizeof tree);
    }

    void build(){
        for(int i = N-1; i; i--){
            tree[i] = op(tree[i<<1], tree[i<<1|1]);
        }
    }

    void update(int idx, int val){
        idx += N;
        tree[idx] = op(tree[idx], val);
        for(idx >>= 1; idx; idx >>= 1){
            tree[idx] = op(tree[idx<<1], tree[idx<<1|1]);
        }
    }

    int get(int l, int r){
        int res = I;
        l += N; r += N;
        while(l <= r){
            if(l&r) res = op(res, tree[l++]);
            if(!(r&1)) res = op(res, tree[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

struct segTree_max{
    int tree[N<<1];
    int I = 0;

    int op(int a, int b){
        return max(a, b);
    }

    segTree_max(){
        memset(tree, I, sizeof tree);
    }

    void build(){
        for(int i = N-1; i; i--){
            tree[i] = op(tree[i<<1], tree[i<<1|1]);
        }
    }

    void update(int idx, int val){
        idx += N;
        tree[idx] = op(tree[idx], val);
        for(idx >>= 1; idx; idx >>= 1){
            tree[idx] = op(tree[idx<<1], tree[idx<<1|1]);
        }
    }

    int get(int l, int r){
        int res = I;
        l += N; r += N;
        while(l <= r){
            if(l&r) res = op(res, tree[l++]);
            if(!(r&1)) res = op(res, tree[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

struct segTree_min{
    int tree[N<<1];
    int I = 10;

    int op(int a, int b){
        return min(a, b);
    }

    segTree_min(){
        for(int i = 0; i < N<<1; i++) tree[i] = I;
    }

    void build(){
        for(int i = N-1; i; i--){
            tree[i] = op(tree[i<<1], tree[i<<1|1]);
        }
    }

    void update(int idx, int val){
        idx += N;
        tree[idx] = op(tree[idx], val);
        for(idx >>= 1; idx; idx >>= 1){
            tree[idx] = op(tree[idx<<1], tree[idx<<1|1]);
        }
    }

    int get(int l, int r){
        int res = I;
        l += N; r += N;
        while(l <= r){
            if(l&r) res = op(res, tree[l++]);
            if(!(r&1)) res = op(res, tree[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
};
int main(){
    segTree_max seg_max;
    segTree_min seg_min;
    segTree_sum seg_sum;
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++){
        scanf("%d", &seg_min.tree[N+i]);
        seg_sum.tree[N+i] = seg_max.tree[N+i] = seg_min.tree[N+i];
    }
    seg_max.build();
    seg_min.build();
    seg_sum.build();
    int t, l, r;
    while(q--){
        scanf("%d %d %d", &t, &l, &r);
        if(t == 2){
            l--, r--;
            seg_max.update(l, r);
            seg_min.update(l, r);
            seg_sum.update(l, r);
        }
        else{
            l--, r--;
            cout << seg_max.get(l, r) << endl;
            printf("%d\n", seg_sum.get(l, r) - seg_max.get(l, r) - seg_min.get(l, r));
        }
    }
    return 0;
}
