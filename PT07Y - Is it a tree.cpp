
/*

http://www.spoj.com/problems/AGGRCOW/

Author : Selva Balasubramanian

*/

#include<iostream>

using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long int n , m;
	bool cycle = false;
	cin>>n>>m;
	if(m == n-1){
		long int visited[n+1];

		for(long int i = 0 ; i<= n; i++){
			visited[i]=0;
		}
		long int a , b ; 

		for(long int i = 0;i<m ;i++){
			cin>>a>>b;
			
			if(!visited[a] || !visited[b]){
					visited[a] = visited[b] =  1;
			}
			else {
				cycle = true;
				break;
			}
		}

	}

	else cycle = true;
	if(!cycle)cout<<"YES";
	else cout<<"NO";


	return 0;
}