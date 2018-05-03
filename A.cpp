#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--){
		int n;cin>>n;
		vector<ll> v(n);
		for(int i = 0;i<n;i++)cin>>v[i];
		vector<int> ans(n,0);
		stack<int> s;
		ans[n-1]= 0;s.push(n-1);
		for(int i=n-2;i>=0;i--){
			int x = n-1-i;
			while(!s.empty() && v[s.top()]<v[i])s.pop();			
			if(s.empty())ans[i]=x;
			else ans[i]=s.top()-1-i;
			s.push(i);
		}
		for(auto i:ans)cout<<i<<" ";cout<<endl;
		
	}
	
}
