#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    if(k<max(n,m)){
        cout<<"-1\n";
        return ;
    }
    vector<vector<int>>a(n+1,vector<int>(m+1,0));
    if(n>=m){
        int g=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(j==g){
                   a[i][j]=1;
                }else{
                    a[i][j]=0;
                }
            }
            if(g<m)g++;
           
        }
        a[1][1]+=k-max(n,m);
    }else{
        int g=1;
        for(int j=1;j<=m;j++){
            for(int i=1;i<=n;i++){
                if(i==g){
                    a[i][j]=1;
                }else{
                    a[i][j]=0;
                }
            }
            if(g<n)g++;
        }
        a[1][1]+=k-max(n,m);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }   
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;

    while(t--){
        solve();
    }
    return 0;
}