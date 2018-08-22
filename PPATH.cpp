// http://www.spoj.com/problems/PPATH/

// #primepath #PPATH #spojprimepath


#include<iostream>
#include<limits>
#include<vector>
#include<queue>
using namespace std;

void seive(bool *prime , int n){
	for(int i = 2 ; i<n+1 ; i++){
		prime[i] = true;
	}
	for(int i = 2 , j; i < (n/2) ; ){
		j = i+i;
		while(j <= n){
			prime[j] = false;
			j += i;
		}
		i++;
		while(!prime[i])i++;
	}
}

vector<int> getAdj(int e ,int start,  int end ,bool *prime ){

	vector<int>adj;
	int k = e;
	int a, b, c, d;
	a = e%10;
	e /= 10;
	b = e%10;
	e /= 10;
	c = e%10;
	e /= 10;
	d = e%10;
	e = k;
	k -= a;
	for(int i = 0 ;i<=9;i++){
		int j = k + i;
		if(prime[j])adj.push_back(j);
	}
	k = e - (b*10);
	for(int i = 0 ;i<=90;i+=10){
		int j = k + i;
		if(prime[j]   )adj.push_back(j);
	}
	k = e - (c*100);
	for(int i = 0 ;i<=900;i+=100){
		int j = k + i;
		if(prime[j]  )adj.push_back(j);
	}
	k = e - (d*1000);
	for(int i = 1000 ;i<=9000;i+=1000){
		int j = k + i;
		if(prime[j])adj.push_back(j);
	}
	return adj;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool prime[10000];
	seive(prime,10000);
	int t;
	cin>>t;
	while(t--){
		int start,end;
		cin>>start>>end;
		if(start == end)cout<<0<<endl;
		else{
			int visited[10000];
			int level[10000];
			for(int i = 1000;i <= 10000;i++){
				level[i] = 0;
				visited[i] = 0;
			}
			queue< int> q;
			q.push(start);
			bool flag = false;
			visited[start] = 1;
			while(!q.empty()){
				int e = q.front();
				q.pop();
					vector<int>adj = getAdj(e, start , end , prime );
					vector<int>::iterator it;
					// cout<<e<<" "<<level[e]<<" : "<<endl;
					for(it = adj.begin() ; it != adj.end() ; it++){
						// cout<<*it<<" ";
						if(visited[*it] == 0){
							q.push(*it);
							level[*it] = level[e] + 1;
							visited[*it] = 1;	
						}
						if(*it == end){
							 flag = true;
							 break;
						}
					}
					// cout<<endl;
					if(flag)break;
				
				
			}

			if(flag)cout<<level[end]<<endl;
			else cout<<"Impossible"<<endl;
		}
}

	return 0;
}