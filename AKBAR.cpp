// #include<bits/stdc++.h>

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node
{
	long int element;
	long int level;
	
};


int main(){

	int t;
	scanf("%d",&t);
	while(t--){
		long int n ,r , m, count = 0;
		scanf("%ld%ld%ld" , &n ,&r,&m);
		vector< long int > g[n+1];
		bool visited[n+1] , found ;
		long int parent[n+1];
			long int root[n+1];
		long int a, b , l , len;
		for(long int i = 0;i<= n;i++){
			visited[i] = false;
			parent[i] = i;
			root[i] = i;
		}
		for(long int i = 0; i< r;i++){
			scanf("%ld%ld",&a ,&b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		
		while(m--){
			scanf("%ld%ld" , &a ,&l);
			queue< node >q;
			found = false;
			if(!visited[a]){
				q.push((node){a , 0});
				visited[a] = true;
				count++;
				while(!q.empty()){
					node  h = q.front();
					long int e = h.element;
					q.pop();
					if(l > h.level){
						len = g[e].size();
						for(long int i = 0; i< len ; i++){
							long int k = g[e][i];
							if(parent[e] != k){
								parent[k] = e;
									if(!visited[k]){
										if(l - h.level > 1) q.push((node){k , h.level + 1 });
										visited[k] = true;
										root[k] = a;
										count++;
									}
									else{
										if(root[k] != a){
											found = true;
											break;
										}
									}

							}
						}
				}
				if(found)break;
				}

			}
			else found = true;
			if(found) break;
		}
			if(found)printf("No\n");
			else{
				if(count != n)printf("No\n");
				else printf("Yes\n");
			}
	}

	return 0;
}