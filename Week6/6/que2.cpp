#include<bits/stdc++.h>
using namespace std;
bool bipartite(int src,vector<int>adj[],int col[]){
	queue<int> q;
	q.push(src);
	col[src]=1;
	while(!q.empty()){
		int node=q.front();
		q.pop();

		for(auto it : adj[node]){
			if(col[it]==-1){
				col[it]=1-col[node];
				q.push(it);
			}
			else if(col[it]==col[node])
				return false;
		}
	}
	return true;
}
bool isBipartite(int n,vector<int>adj[]){
	int col[n];
	memset(col,-1,sizeof col);

	for(int i=0;i<n;i++){
		if(col[i]==-1){
			if(!bipartite(i,adj,col))
				return false;
		}
	}
	return true;
}
int main()
{
	int n;
	int m;
	
	cin >> n >> m;
	vector<int>adj[n+1];
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	if(isBipartite(n,adj))
		cout << "True" << endl;
	else
		cout << "False" << endl;


	return 0;
}