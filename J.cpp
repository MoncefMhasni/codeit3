#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc;cin>>tc;
    while(tc--){
        int x,y;cin>>x>>y;
        int a,b=-1;
        for(a = 0;a<x;a++){
            if((a^(x-a))==y){
                b = x-a;
                break;
            }
        }
       if(b<0) a = -1;
        printf("(%d,%d)\n",a,b);
    }
}
