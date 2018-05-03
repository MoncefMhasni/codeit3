#include<bits/stdc++.h>
#define ll long long
#define um unordered_map
#define pb push_back
using namespace std;
const int mod = 1e9+7,MAX = 1e5+7;
um<int,int> parent,lvl;
um <int,ll> f;
um <int,vector<int>> g;
um <int,um<int,int>> P;
int N,Q;
struct mat{
    ll a,b,c,d;
    mat operator*(mat m){
        mat ans;
        ans.a = (a*m.a + b*m.c)%mod;
        ans.b = (a*m.b + b*m.d)%mod;
        ans.c = (c*m.a + d*m.c)%mod;
        ans.d = (c*m.b + d*m.d)%mod;
        return ans;
    }
};
mat u = {1,1,1,0};
mat pow(int n){
    if(n<=1)return u;
    if(n&1)return u*pow(n-1);
    else {
        mat ans = pow(n/2);
        return ans*ans;
    }
}
void dfs(int p,int c){
    parent[c]=p;
    f[c]=(f[c]+f[p])%mod;
    lvl[c]=lvl[p]+1;
    for(auto i:g[c])
        if(parent[i]==-1)dfs(c,i);
}
void preprocess(){
    for(int i=0;i<MAX;i++)
        parent[i]=-1;
    dfs(0,1);
    for(int i=1;i<=N;i++){
        P[i][0]=parent[i];
        for(int j=1;(1<<j)<N;j++)
            P[i][j] = -1;
    }
    for(int j = 1;(1<<j) <N;j++){
        for(int i=1;i<=N;i++){
            if(P[i][j-1]!=-1)
            P[i][j]=P[P[i][j-1]][j-1];
        }
    }
}
int LCA(int u,int v){
    if(lvl[u]<lvl[v])swap(u,v);
    int d = lvl[u]-lvl[v];
    while(d>0){
        int leftmost = log2(d);
        u = P[u][leftmost];
        d-= 1<<leftmost;
    }
    if(u==v)return u;
    for(int j = log2(N);j>=0;j--){
       if((P[u][j] != -1) && (P[u][j] != P[v][j])){
            u = P[u][j] ;
            v = P[v][j] ;
        }
    }
    return parent[v] ;
}
int main(){
    ios::sync_with_stdio(false);
    int tc;cin>>tc;
    while(tc--){
        cin>>N>>Q;
        for(int i=0;i<N;i++){
          int n;cin>>n;
          if(n>2){
          mat x = pow(n-2);
          f[i+1]=(x.a+x.b)%mod;
          }
          else f[i+1] = 1;
        }
        g.clear();
        for(int i=1;i<N;i++){
            int u,v;cin>>u>>v;
            g[u].pb(v);g[v].pb(u);
        }
        preprocess();
        while(Q--){
            int u,v;cin>>u>>v;
            int x = LCA(u,v);
            cout<<((f[u]+f[v]-f[x]-f[parent[x]])+2*mod)%mod<<endl;
        }
    }
}
