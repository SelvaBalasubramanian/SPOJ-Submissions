#include<iostream>
#include<vector>
#include<queue>

using namespace std;


struct city{
	int c;
	int cost;
};

struct compare{

	int operator()(city a, city b){
		return a.cost > b.cost;
	}
};

int main(){

	int n , a , b , w; 
	scanf("%d",&n);
	vector <city> g[1050];
	bool visited[1050];
	int dist[1050];
	bool found = true;
	bool v[1050][1050] ;

	for(int i = 0; i<n; i++){
		scanf("%d%d%d" , &a,&b,&w);

		if(!v[a][b] && !v[b][a]){
			g[a].push_back((city){b,w});
			g[b].push_back((city){a,w});
			
		}
		visited[i] = false;
	}

	for(int i = 0; i<= 1050 ; i++){
		visited[i] = false;
		dist[i] = INT_MAX;
	}

	int root , t;
	scanf("%d" ,&root);
	scanf("%d" ,&t);
	if(root <= 500){
		dist[root] = 0;
		priority_queue< city , vector < city > , compare > q;
		q.push((city){root , 0});
		while(!q.empty()){
			city e = q.top();
			q.pop();
				visited[e.c] = true;
				int len = g[e.c].size();
				for(int i = 0; i< len ;i++){
					 int k = g[e.c][i].c;
					 int w = g[e.c][i].cost;
					 if(dist[k] > dist[e.c] + w){
					 	dist[k] = dist[e.c] + w;
					 	q.push((city){k,dist[k]});
					 }
				}
		}
	}
	while(t--){
		scanf("%d" ,&b);
		if(root > 500 || b > 500 || dist[b] == INT_MAX)printf("NO PATH\n");
		else printf("%d\n",dist[b]);
	}



	return 0;
}