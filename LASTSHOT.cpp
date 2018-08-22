#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){

	int n , m ,a,b;
	scanf("%d%d",&n,&m);
	vector<int>g[n+1];


	for(int i = 0; i< m; i++){
		scanf("%d%d",&a,&b);
		printf("%d%d\n",a,b );
		g[a].push_back(b);
	}

	bool visited[n+1];
			stack<int>st;

	int max = -1;
	for(int i = 1; i<=n; i++){
			for(int i = 0; i<=n ; i++)visited[i] = false;
			st.push(i);
			visited[i] = true;
			int curr = 1;
			while(!st.empty()){
				int e = st.top();
				st.pop();
				int len = g[e].size();
				for(int j = 0; j<len ; j++){
					int k = g[e][j];
					if(!visited[k]){
						visited[k] = true;
						st.push(k);
						curr++;
					}
				}
			}
			if(curr > max)max = curr;
		
	}
	printf("%d\n",max);


	return 0;
}
