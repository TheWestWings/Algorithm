//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
int n,m,k,fa[N],sum[N];
pair<int,pair<int,int> > eds[N];
ll ans=0;
int getf(int x){return x==fa[x]?x:fa[x]=getf(fa[x]);}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&eds[i].S.F,&eds[i].S.S,&eds[i].F);
		eds[i].S.F--,eds[i].S.S--;
	}
	sort(eds,eds+m);
	for(int i=0;i<k;i++){
		int x;
		scanf("%d",&x);
		x--;
		sum[x]++;
	}
	for(int i=0;i<k;i++){
		int x;
		scanf("%d",&x);
		x--;
		sum[x]--;
	}
	for(int i=0;i<n;i++) fa[i]=i;
	for(int i=0;i<m;i++){
		int w=eds[i].F,x=eds[i].S.F,y=eds[i].S.S;
		x=getf(x),y=getf(y);
		if(x==y) continue;
		if(sum[x]>0&&sum[y]<0){
			int d=min(sum[x],-sum[y]);
			ans+=1ll*w*d;
			sum[x]-=d,sum[y]+=d;
		}
		else if(sum[x]<0&&sum[y]>0){
			int d=min(-sum[x],sum[y]);
			ans+=1ll*w*d;
			sum[x]+=d,sum[y]-=d;
		}
		sum[x]+=sum[y];
		fa[y]=x;
	}
	printf("%lld\n",ans);
	return 0;
}