#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int tc;cin>>tc;
	while(tc--){
		int n,ans=1,ok=1;cin>>n;
		while(n--){
		    ll p,a;
		    cin>>p>>a;
		    if(a>20 ||ans >1e6||!ok||p>1e6)ok=0;
		    else while(a-- && ans <1e6) ans*=p;
		}
		if(ok && (ans ==1 || ans == 2 ||ans == 145 || ans == 40585))cout<<"Funny\n";
		else cout<<"Not funny\n";
	}
	return 0;
}