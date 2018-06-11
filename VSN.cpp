#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef struct node{
	double x;
	double y;
	double z;
}VECTOR;
VECTOR cp(VECTOR U,VECTOR V){
	VECTOR R;
	R.x=U.y*V.z-U.z*V.y;
	R.y=U.z*V.x-U.x*V.z;
	R.z=U.x*V.y-U.y*V.x;
	return R;
}
double mag(VECTOR V){
	double mg=pow(V.x,2);
	mg+=pow(V.y,2);
	mg+=pow(V.z,2);
	return mg;
}
VECTOR sum(VECTOR v1,VECTOR v2){
	VECTOR R;
	R.x=v1.x+v2.x;
	R.y=v1.y+v2.y;
	R.z=v1.z+v2.z;
	return R;
}
VECTOR prod(double r,VECTOR v2){
	VECTOR R;
	R.x=r*v2.x;
	R.y=r*v2.y;
	R.z=r*v2.z;
	return R;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(false);
	int T;
	VECTOR P,Qo,C,d,CP;
	int r;
	double t,PC,LHS,cotx,coty,cotz,ct,ct2,constx,consty,constz,cons,r1,r2,D;
	VECTOR RHSc,RHSt,LHSc,LHSt;
	cin>>T;
	while(T--){
		cin>>P.x>>P.y>>P.z;
		cin>>Qo.x>>Qo.y>>Qo.z;
		cin>>d.x>>d.y>>d.z;
		cin>>C.x>>C.y>>C.z>>r;

		CP.x=C.x-P.x;CP.y=C.y-P.y;CP.z=C.z-P.z;

		LHSc.x=Qo.x-P.x;LHSc.y=Qo.y-P.y;LHSc.z=Qo.z-P.z;
		LHSt=d;
		LHSc=prod(r,LHSc);
		LHSt=prod(r,LHSt);

		RHSc=cp(CP,Qo);
		RHSc=sum(RHSc,cp(P,CP));
		RHSt=cp(CP,d);

		ct2=mag(LHSt);
		ct2-=mag(RHSt);

		ct=2*LHSt.x*LHSc.x;
		ct+=2*LHSt.y*LHSc.y;
		ct+=2*LHSt.z*LHSc.z;
		ct-=2*RHSt.x*RHSc.x;
		ct-=2*RHSt.y*RHSc.y;
		ct-=2*RHSt.z*RHSc.z;

		cons=mag(LHSc);
		cons-=mag(RHSc);

		if(ct2!=0){
			D=pow(ct,2);
			D-=4*ct2*cons;
			if(D>=0){
				D=sqrt(D);
			}
			else{
				D*=-1;
				D=sqrt(D);
			}
			r1=-1*ct+D;
			r1/=2*ct2;
			r2=-1*ct-D;
			r2/=2*ct2;
			if(r1>0&&r2>0){
				if(r2<r1){
					cout<<r1<<endl;
				}
				else{
					cout<<r2<<endl;
				}
			}
			else if(r1>0){
				printf("%.6lf\n",r1);
			}
			else{
				printf("%.6lf\n",r2);
			}
		}
		else{
			r1=-1*cons;
			r1/=ct;
			printf("%.6lf\n",r1);
		}
	}
}