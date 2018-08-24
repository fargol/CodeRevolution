{
#include<bits/stdc++.h>
using namespace std;
struct petrolPump
{
    int petrol;
    int distance;
};
int tour(petrolPump [],int );
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/
/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
   //Your code here
   int N=n;
   vector<pair<int,int> > arr(N);
		//vector<pair<int,int> > cum(N+1);
		for(int i=0;i<N;i++){
			arr[i].first=p[i].petrol;
			arr[i].second=p[i].distance;
		}
		//cum[0]=make_pair(0,0);
		/*for(int i=0;i<N;i++){
			cum[i+1].first=cum[i].first+arr[i].first;
			cum[i+1].second=cum[i].second+arr[i].second;
		}*/
		//unordered_map<int,bool> hm;
		int start=-1,petrol_tank=0;
		int id;
		int count=0;
		for(int i=0;i<2*N;i++){
		    if(count==N)
				break;
			id=i%N;
			//cout<<"start = "<<start<<" && id = "<<id<<" && petrol_tank = "<<petrol_tank<<endl;
			if(start==-1){
				start=id;
				//cout<<"start = "<<start<<endl;
				if(arr[id].first>=arr[id].second){
					petrol_tank=arr[id].first-arr[id].second;
					count=1;
					continue;
				}
				else{
					start=-1;
					count=0;
					petrol_tank=0;
					continue;
				}
			}
			/*if(id==3)
				cout<<petrol_tank+arr[id].first<<" & id=3 & "<<arr[id].second<<endl;*/
			if(petrol_tank+arr[id].first>=arr[id].second){
				petrol_tank+=arr[id].first;
				petrol_tank-=arr[id].second;
				//cout<<"petrol_tank = "<<petrol_tank<<endl;
				//cout<<"start ="<<start<<" & continuing by = "<<id<<endl;
				count++;
			}
			else{
				start=-1;
				count=0;
				petrol_tank=0;
				continue;
			}
		}
		if(count!=N){
			return -1;
		}
		else{
			return start;
		}
}