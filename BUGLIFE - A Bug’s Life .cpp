/*

http://www.spoj.com/problems/BUGLIFE/

Author : Selva Balasubramanian

*/


#include<iostream>
#include<queue>
#include<vector>


using namespace std;

int isallVisited(int *visited , int n){
	for(int i = 1; i<=n; i++){
		if(!visited[i]){
			return i;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long int t;
	cin>>t;
	long int case1 = 1;
	while(case1<=t){
		 int v , a , b ; 
		long int e;
		cin>>v>>e;
		vector<int>graph[v+1];
		vector<int>::iterator it;
		int color[v+1];
		int visited[v+1];
		for(int i = 0; i<v+1 ;i++){
			color[i] = visited[i] = 0;
		}
		for(long int i = 0; i<e; i++){		
			cin>>a>>b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		queue<int>q;
		color[1] = 1;
		bool found = false;
		q.push(1);
		while(1){

			while(!q.empty()){
				a = q.front();
				q.pop();
				visited[a] = 1;
				for(it = graph[a].begin() ; it != graph[a].end() ;it++){
					 b = *it;
					 if(color[b] == 0){
					 	color[b] = color[a] + 1; 
					 	q.push(b);
					  }
					 else if(color[b]%2 == color[a]%2){
					 	found = true;
					 	break;
					 }
				}
				if(found)break;
			}
			if(found)break;
			a = isallVisited(visited , v);
			if(a == 0)break;
			else{
				q.push(a);
			}
		}
		cout<<"Scenario #"<<case1<<":"<<endl;
		if(found){
			cout<<"Suspicious bugs found!"<<endl;
		}else{
			cout<<"No suspicious bugs found!"<<endl;
		}

		case1++;
	}

	return 0;
}
