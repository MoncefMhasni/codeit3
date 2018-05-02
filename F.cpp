#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;
const int MAX = 1e7+1;
vector<ll> ans;
void gen(){
    ans.resize(MAX);
    ans[1]=1;
    ans[2]=4;
    for(int i=3;i<MAX;i++){
        ans[i] = (i*(1+ans[i-1]));
        ans[i]%=mod;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    gen();
    int tc;cin>>tc;
    while(tc--){
        int N;cin>>N;
        cout<<1+ans[N]<<endl;
    }
}
