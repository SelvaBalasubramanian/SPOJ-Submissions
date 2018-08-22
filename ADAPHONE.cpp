#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stack>
//SRY GUYS THIS ONE FAILS AT TESTCASE 15
using namespace std;

long getroot(long int *parent ,long int i){
	while(parent[i] != i){
		i = parent[i];
	}
	return i;
}

int main(){

	long int n , q;
	scanf("%ld%ld" , &n , &q);
	vector< long int >graph[n+1];
	long int visited[n+2];
	for(long int i = 0 , a, b ; i< n-1 ; i++){
		scanf("%ld%ld" , &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	long int parent[n+2];
	while(q--){

			for(long int i = 0 ; i<= n+2; i++){visited[i] = 0;parent[i] = 0;}
			long int start , end;
			scanf("%ld%ld",&start , &end);
			// cout<<"start : end"<<endl;
			// cout<<start<<" "<<end<<endl;
			stack<long int > st;
			
			if(start != end){
				st.push(start);
				visited[start] = 1;
				bool found = false;
				bool subNode = false;
				while(!st.empty()){
					bool subNode = false;
					long int e = st.top();
					long int len = graph[e].size();
					for(long  int i = 0; i<len ; i++ ){
						long int a = graph[e][i];
						if(!visited[a]){
							visited[a] = 1;
							parent[a] = a;
							st.push(a);
							subNode = true;
						}
						if(end == a){
							found = true;
							break;		 
						}
					}
					if(found)break;
					if(!subNode){
						parent[st.top()] = 0;
						st.pop();
					}
				}
				long int setCount = 0;
					found = false;
					long int e = st.top();
					st.pop();
					while(!found){
						long int len = graph[e].size();
						for(long int i = 0 ;i< len ; i++){
							parent[graph[e][i]] = 0;
							if(st.top() == graph[e][i]){
								found = true;
								parent[graph[e][i]] = graph[e][i];
							}
						}
						if(!found){
							parent[st.top()] = 0 ;
							st.pop();
						}
					
					}
					st.push(e);
					setCount = st.size();
				
				// cout<<endl;
				// cout<<"ThridLop\n";
				int temp = setCount;
				while(!st.empty()){
					long int e = st.top();
					// cout<<"("<<e<<visited[e]<<") - ";
					st.pop();
					if(e+1 <= n && parent[e+1]){
						long int roota = getroot(parent,e+1) , rootb = getroot(parent ,e);
						if(roota != rootb){
							setCount--;
							parent[rootb] = roota;
						}
					}
					if(parent[e-1] && e-1 !=0){
						long int roota = getroot(parent,e-1) , rootb = getroot(parent ,e);
						if(roota != rootb){
							setCount--;
							parent[rootb] = roota;
						}
					}
					// cout<<"("<<e<<visited[e]<<") - ";


				}

				// cout<<temp<<" : "<<setCount<<endl;
				printf("%ld\n",setCount);

		}
		else{
				printf("1\n");
		}

	}
	return 0;
}
