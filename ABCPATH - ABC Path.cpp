#include<bits/stdc++.h>

using namespace std;


vector<pair<int,int>> isValid(char **ar , int x ,int y , int i , int j , char a){

	vector<pair<int,int>> adj;
	if(x+1 < i && ar[x+1][y]== a)adj.push_back(make_pair(x+1,y));
	if(x-1 >= 0 && ar[x-1][y]== a)adj.push_back(make_pair(x+1,y));
	if(y+1 < j && ar[x][y+1]== a)adj.push_back(make_pair(x+1,y));
	if(y-1 >= 0  && ar[x][y-1]== a)adj.push_back(make_pair(x+1,y));

	return adj;
}


int main(){

	int tcount = 1;
	while(1){
		cin>>n>>m;
		if(a == 0 && b == 0 )return;
		else{
			char ar[n][m];
			int si ,sj;
			vector<pair<int ,int>>v;
			for(int i = 0 ; i< n; i++){
				for(int j = 0 ;j<m ; j++){
					cin>>ar[i][j];
					if(ar[i][j] == 'A'){
						v.push_back(make_pair(i,j));
					}
				}
			}

			if(v.size() == 0){
    			cout<<"Case "<<tcount<<": 0\n";       
			}
		 	
		 	else{
		 		char a = 'B';
				int visited[n][m] = {0};
				int len = v.size();
				int count = 1 , max = 1;
				int l = 0;
				while(l <len){
					count = 1;
					int i , j ;
					visited[v[l].first][v[l].second] = 1;
					stack<pair<int , int>>st;
					st.push(v[l]);
					while(!st.empty()){
						int x = st.top().first;
						int y = st.top().second;
						st.pop();
						vector<pair<int ,int >> adj = getAdj((char**)ar , x, y , n , m ,a);
						int size = adj.size();
						if(a == 'Z' && size){
							max = 26;
							break;
						}
						if(size == 0){
							break;
						}
						else{
							for(int t = 0 ;t< size ; t++){
								int xa = adj[t].first;
								int ya  = adj[t].second;
								if(!visited[xa][ya]){
									count++;
									if(count > max )max = count;
									a = a+1;
									st.push(adj[t]);
									visited[xa][ya]= 1;
								}
							}
						}
						
					}
					if(max == 26){
						break;
					}
				l++;
				}//while
				cout<<"Case "<<tcount<<": "<<max<<endl; 
		 	}
		 	tcount++;
		}
	}


	return 0;
}