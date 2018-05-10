#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define inf 1<<28
#define ll long long
#define pb push_back

using namespace std;
vector<vector<int>> v,path;
vector<int> dp;
void apsp(int n){
        for(int i=0;i<n;i++) v[i][i]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    v[j][k]=min(v[j][k],v[j][i]+v[i][k]);
}
int min_matching(int mask,int n){
    if(mask == (1<<n)-1) return 0;
    int ans = dp[mask];
    if(ans != -1) return ans;
    ans = inf;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        if(i == j) continue;
        if(mask&(1<<i) || mask&(1<<j)) continue;
        int m = (mask|(1<<i))|(1<<j);
        ans = min(ans,min_matching(m,n)+path[i][j]);
    }
    dp[mask]=ans;
    return ans;
}
int main(){
    int tc;cin>>tc;
    while(tc--){
        int N,M;
        cin>>N>>M;
        v.clear();path.clear(),dp.clear();
        v.resize(N,vector<int>(N,inf));
        vector<int> n(N,0);
        int ans =0;
        for(int i = 0;i<M;i++){
            int x,y,c;
            cin>>x>>y>>c;
            v[x][y]=v[y][x]=c;
            n[x]++;n[y]++;
            ans+=c;
        }
        apsp(N);
        vector<int>odd;
        for (int i =0;i<n.size();i++)if(n[i]%2)odd.pb(i);
        if(odd.empty()){
                cout<<ans<<endl;
                continue;
        }
        path.resize(odd.size(),vector<int>(odd.size()));
        for(int i=0;i<odd.size();i++)
            for(int j=i+1;j<odd.size();j++)
                path[i][j]=path[j][i]=v[odd[i]][odd[j]];
        dp.resize(1<<odd.size(),-1);
        cout<<ans+min_matching(0,odd.size())<<endl;
    }
}
