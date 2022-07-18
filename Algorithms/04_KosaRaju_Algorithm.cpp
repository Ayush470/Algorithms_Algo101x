// Calculate number of strongly connected component
#include <bits/stdc++.h>
using namespace std;
class KosaRaju_Algo{
public:
	map<int,list<int>> mp;

	KosaRaju_Algo(int v){
		for(int i=0;i<v;i++){
			list<int> ls;
			mp[i]=ls;
		}
	}

	void addedge(int u,int v){
		mp[u].push_back(v);
	}

	void dfs(map<int,bool> &visited,stack<int> &st,int i){
		if(visited[i]==true){
			return;
		}
		visited[i]=true;
		for(int neighbour:mp[i]){
			if(!visited[neighbour]){
				dfs(visited,st,neighbour);
			}
		}
		st.push(i);
	}

	void transposegraph(map<int,list<int>> &mpp){
		for(auto it:mp){
			list<int> lst;
			mpp[it.first]=lst;
		}
		for(auto it:mp){
			for(auto nbrs:mp[it.first]){
				mpp[nbrs].push_back(it.first);
			}
		}
	}

	void dfs2(map<int,list<int>> &mpp,map<int,bool> &visited,int src){
		visited[src]=true;
		for(auto it:mpp[src]){
			if(!visited[it]){
				dfs2(mpp,visited,it);
			}
		}
	}

	int kosarajualgo(){
		stack<int> st;
		map<int,bool> visited;
		for(auto it:mp){
			dfs(visited,st,it.first);
		}
		map<int,list<int>> mpp;
		transposegraph(mpp);
		visited.clear();
		int count=0;
		while(!st.empty()){
			int cur=st.top();
			st.pop();
			if(!visited[cur]){
				dfs2(mpp,visited,cur);
				count++;
			}
		}
		return count;
	}
};
int main(){
	int n,m;
	cin>>n>>m;
	KosaRaju_Algo ks(n);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		ks.addedge(x,y);
	}
	int ans=ks.kosarajualgo();
	cout<<ans;
}

// 9 10
// 0 1
// 1 2
// 2 3
// 3 0
// 2 4
// 4 5
// 5 6
// 6 7
// 7 4
// 8 5