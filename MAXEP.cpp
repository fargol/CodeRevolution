#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long
#define M 1000000007
int main(){
	srand(time(NULL));
	ios::sync_with_stdio(true);
	int N,c,y,r,x;
	cin>>N>>c;
	int budget=1000;
	int low=1,high=N,mid1,mid2,mid3,mid4;
	while(low<high){
		if((high-low+1+c)<=budget){
			cout<<"1 "<<low<<endl;
			budget--;
			cin>>r;
			if(r==0){
				low++;
			}
			else if(r==1){
				cout<<2<<endl;
				budget-=c;
				break;
			}
			else{
				return 0;
			}
		}
		else{
			mid1=low+(high-low)/5;
			mid2=low+(2*(high-low))/5;
			mid3=low+(3*(high-low)/5);
			mid4=low+(4*(high-low)/5);
			cout<<"1 "<<mid1<<endl;
			budget--;
			cin>>r;
			if(r==0){
				cout<<"1 "<<mid2<<endl;
				budget--;
				cin>>r;
				if(r==0){
					cout<<"1 "<<mid3<<endl;
					budget--;
					cin>>r;
					if(r==0){
						cout<<"1 "<<mid4<<endl;
						budget--;
						cin>>r;
						if(r==0){
							low=mid4+1;
						}
						else if(r==1){
							cout<<2<<endl;
							budget-=c;
							low=mid3+1;
							high=mid4;
						}
						else{
							return 0;
						}
					}
					else if(r==1){
						cout<<2<<endl;
						budget-=c;
						low=mid2+1;
						high=mid3;
					}
					else{
						return 0;
					}
				}
				else if(r==1){
					cout<<2<<endl;
					budget-=c;
					low=mid1+1;
					high=mid2;
				}
				else{
					return 0;
				}
			}
			else if(r==1){
				cout<<2<<endl;
				budget-=c;
				high=mid1;
			}
			else{
				return 0;
			}
		}
	}
	cout<<"3 "<<low<<endl;
}