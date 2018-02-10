#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T,x,N,a,t,o;
	cin>>T;
	while(T--){
		cin>>x>>N;
	  	int arr[1000002]={0};
	 	if(N%2==0 && x%2==1){
			t=1;
			o=(N/2)-1;
	 	}
		else if(N%2==0 && x%2==0){
			t=0;
			o=N/2;
		}
		else if(N%2==1 && x%2==0){
			t=1;
			o=(N/2)-1;
		}
		else
		{
			t=0;
			o=N/2;
		}
		vector<int> v;
		for(int i=N;i>=1;i--)
		{
			if(i!=x)
				v.push_back(t);
		}
		v.push_back(0);

		vector<pair<int,int > > op;
	 	for(int i=0;i<v.size()-1;i+=2)
			op.push_back(make_pair(v[i],v[i+1]));

		if(o%2==0&&o!=0){
			if(t==0){
				for(int i=0;i<o>>1;i++){
					arr[op[i].first]=0;
					arr[op[i].second]=1;
				}
				for(int i=o>>1;i<op.size();i++){
					arr[op[i].first]=1;
					arr[op[i].second]=0;
				}
			}
			else{
				int j=0;
				for(int i=0;i<op.size();i++){
					if(t<(o>>1)-1  && op[i].first-op[i].second==1){
						arr[op[i].first]=0;
						arr[op[i].second]=1;
						++j;
					}
					else if(op[i].first-op[i].second==2){
						arr[op[i].first]=0;
						arr[op[i].second]=1;
					}
					else
					{
						arr[op[i].first]=1;
						arr[op[i].second]=0;
					}
				}
			}
			arr[x]=2;
			for(int i=1;i<=N;i++)
				cout<<arr[i];
			cout<<endl;
		}
		else
			cout<<"impossible"<<endl;
	}
}




