#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 100001 ,mod = 1e9+7,sz_max = 1003;
int n,sz;
ll f[sz_max];
string seq[sz_max],seqm,s;
void gen(){
    f[0]=f[1]=1;
    seq[0]="B";
    seq[1]="R";
    for(sz = 2;seq[sz-1].length() <MAX;sz++) seq[sz] = seq[sz-1] + seq[sz-2];
    for(int i = 0;i<4;i++,sz++) seq[sz] = seq[sz-1] + seq[sz-2];
    for(int i = 2;i<sz_max;i++)f[i] = (f[i-1] + f[i-2])%mod;
}
int find() {
    if (s.empty()) return 0;
    vector<int> pi(s.size(), 0);
    for (int i = 1, k = 0; i < s.size(); ++i) {
    while (k && s[k] != s[i]) k = pi[k - 1];
    if (s[k] == s[i]) ++k;
    pi[i] = k;
    }
    int cc = 0;
    for (int i = 0, k = 0; i < seqm.size(); ++i) {
    while (k && s[k] != seqm[i]) k = pi[k - 1];
    if (s[k] == seqm[i]) ++k;
    if (k == s.size()) cc++,k=0;
    }
    return cc;
}
int main(){
    ios::sync_with_stdio(false);
    gen();
    int tc;cin>>tc;
    while(tc--){
        cin>>n>>s;
        if(s.length()>f[n])cout<<"0"<<endl;
        else if(s=="B") cout<<f[n-2]<<endl;
        else if(s=="R") cout<<f[n-1]<<endl;
        else {
            int m = 2;
            for(;m<n && seq[m].length()< s.length() ;m++);
            unordered_map<int,ll> dp;
            int x,y,z;
            seqm = seq[m-1]+seq[m-2];
            x = find();
            seqm = seq[m-2]+seq[m-1];
            y = find();
            seqm = seq[m-1]+seq[m-1];
            z = find();
            dp[m] = x;
            dp[m+1] = x+y;
            for(int i = 2;m+i<=n;i++)
                dp[m+i]=(dp[m+i-1]+dp[m+i-2]+(i%2==0 ? z : y))%mod;
            cout<<dp[n]<<endl;
        }
    }

}
