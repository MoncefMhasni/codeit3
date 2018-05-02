#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc;cin>>tc;
    while(tc--){
        double v;cin>>v;
        int ans = ceil(3*pow((4*v*v),1.0/3.0));
        cout<<ans<<endl;
    }

}
