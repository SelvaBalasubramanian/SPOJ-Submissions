/*

http://www.spoj.com/problems/HOTELS/

Author : Selva Balasubramanian

*/


#include<iostream>
#include<queue>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long int n, k;
	cin>>n>>k;
	queue< long int > window;
	long int sum = 0 , curr = 0 , val;
	for(long int i = 0; i< n;i++){
		cin>>val;
		curr += val;
		window.push(val);
		if(curr > k){
			while(curr > k){
				val = window.front();
				curr -= val;
				window.pop();
			}
		}
		if(curr > sum && curr<=k){
			sum = curr;
			if(sum == k){
				break;
			}
		}
	}
	cout<<sum;


	return 0;
}