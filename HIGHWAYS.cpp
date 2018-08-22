#include<bits/stdc++.h>


using namespace std;

struct edge{
	int first ; //vertex
	int second; //weight
};

struct compare{
	int operator()( struct edge a , struct edge b){
		return a.second < b.second;
	}
};
#define SIZE 100005
#define IMAX 10000000

vector< edge > graph[100005];


int main(){
	int t;
	scanf("%d" , &t);
	int n , m , source , dest ,a , b ,w;
	while(t--){
		int distance[SIZE];
		scanf("%d %d %d %d" , &n , &m , &source , &dest);
		for( int i = 0 ; i<= n ; i++){
			distance[i] = IMAX;
			graph[i].clear();
		}

 		for( int i = 0; i< m;  i++){
			scanf("%d %d %d" , &a , &b , &w );
			graph[a].push_back((edge) {b,w});
			graph[b].push_back((edge) {a,w});
		}
		priority_queue < edge , vector < edge > , compare >q;

		q.push((edge) {source,0});
		distance[source] = 0;
		edge e;
		while(!q.empty()){
			e = q.top();
			q.pop();
			int len = graph[e.first].size();

				for(int i = 0 ; i < len ; i++){
					 int v = graph[e.first][i].first;
					w = graph[e.first][i].second;
					if(distance[v] > distance[e.first] + w){
						distance[v] = distance[e.first] + w;
						q.push((edge) {v , w});
					} 
				}
			
		}
		if(distance[dest] != IMAX)printf("%d\n",distance[dest]);
		else printf("NONE\n");
	}


	return 0;
}