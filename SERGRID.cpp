#include<iostream>
#include<queue>

using namespace std;

struct node{
	int x , y;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n , m;
	cin>>n>>m;
	int ar[n][m];
	bool visited[n][m];
	int level[n][m];
	string s;
	for(int i = 0; i< n; i++){
		cin>>s;
		for(int j = 0; j< m; j++){
			ar[i][j] = s[j] - 48;
			visited[i][j] = false;
			level[i][j] = 0;
		}
	}

	queue< node >q;
	q.push((node){0,0});
	level[0][0] = 0;
	bool found = false;
				visited[0][0] = true;
	
	while(!q.empty()){

		int x , y , k ; 
		x = q.front().x;
		y = q.front().y;
		k = ar[x][y];
		q.pop();		
		if(x  == n-1 && y == m-1){
					found = true;
					break;
				}


			
			if(x+k < n && !visited[x+k][y]){
				q.push((node){x+k,y});
				level[x+k][y] = level[x][y] + 1;
				visited[x+k][y] = true;
			
			}

			if(x-k >= 0  && !visited[x-k][y]){
				q.push((node){x-k,y});
				level[x-k][y] = level[x][y] + 1;
								visited[x-k][y] = true;
				
			}

			if(y+k < m && !visited[x][y+k]){
				q.push((node){x,y+k});
				level[x][y+k] = level[x][y] + 1;
				visited[x][y+k] = true;
						}

			if(y-k >= 0  && !visited[x][y-k]){
				q.push((node){x,y-k});
				level[x][y-k] = level[x][y] + 1;
				visited[x][y-k] = true;
		
			}
	}
	if(found){
		cout<<level[n-1][m-1];
	}
	else{
		cout<<-1;
	}

	return 0;
}



