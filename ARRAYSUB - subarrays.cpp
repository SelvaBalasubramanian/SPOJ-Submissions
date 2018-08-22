/*

http://www.spoj.com/problems/ARRAYSUB/

Author : Selva Balasubramanian

*/




#include<iostream>
#include<deque>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long int n, k ,max ;
	cin>>n;
	long int ar[n];
	for(long int i = 0; i< n ;i++){
		cin>>ar[i];
	}
	cin>>k;
	deque< long int > q;
	long int i = 0;
	while(i<k){
		while(!q.empty() && ar[q.back()]<ar[i])q.pop_back();
		q.push_back(i);
		i++;
	} 

	for(i = k ; i< n; i++){
		cout<<ar[q.front()]<<" ";
		while(!q.empty() && q.front() <= i-k)q.pop_front();
		while(!q.empty() && ar[q.back()] < ar[i])q.pop_back();
		q.push_back(i);
	}
	cout<<ar[q.front()];

	return 0;
}