#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
inline int gcd(int a,int b){
	if(a==0)
		return b;
	if(b==0)
		return a;
	return gcd(b%a,a);
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int t,n,m,d,c1,c2,an,am,dis,hcf;
	cin>>t;
	while(t--){
		cin>>m>>n>>d;
		hcf=gcd(n,m);
		if(d%hcf==0&&d<=n){
			c1=1;
			an=n;
			am=0;
			while(true){
				if(an==d||am==d)
					break;
				if(am<m){
					dis=min(m-am,an);
					am+=dis;
					an-=dis;
					c1++;
					if(an==d||am==d)
						break;
				}
				if(am==m){
					am=0;
					c1++;
					if(an==d||am==d)
						break;
				}
				if(an==0){
					an=n;
					c1++;
					if(an==d||am==d)
						break;
				}
				if(an==d||am==d)
					break;
			}
			c2=1;
			an=0;
			am=m;
			while(true){
				if(an==d||am==d)
					break;
				if(an<n){
					dis=min(am,n-an);
					an+=dis;
					am-=dis;
					c2++;
					if(an==d||am==d)
						break;
				}
				if(an==n){
					an=0;
					c2++;
					if(an==d||am==d)
						break;
				}
				if(am==0){
					am=m;
					c2++;
					if(an==d||am==d)
						break;
				}
				if(an==d||am==d)
					break;
			}
			cout<<min(c1,c2)<<endl;
		}
		else
			cout<<-1<<endl;
	}
}