#include<bits/stdc++.h>
using namespace std;
bool pathLook(int node,vector<int>ad[],int s,int d,vector<int>&vis){
	vis[node]=1;
	for(auto it : ad[s]){
		if(it==d)
			return true;

		if(!vis[it]){
			vis[it]=1;
			if(pathLook(it,ad,s,d,vis))
				return true;
		}
	}
	return false;
}
bool isDFS(int n,vector<int>ad[],int s,int d){
	if(s==d) return true;
	vector<int>vis(n+1,0);

	for(int i=1;i<=n;i++){
		if(pathLook(i,ad,s,d,vis))
			return true;
	}
	return false;
}
int main(){
	int n;
	int m;
	cin >> n >> m;
	vector<int>ad[n+1];
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}
	int s,d;
	cin >> s >> d;
	if(isDFS(n,ad,s,d))
		cout << "True" << endl;
	else
		cout << "False" << endl;


	return 0;
}