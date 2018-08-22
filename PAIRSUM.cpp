#include<iostream>

using namespace std;

int main(){

	long long int val ,a, b;
	int  n ,q;
	scanf("%d" , &n);
	long long int sum[n] ,prodsum[n],currsum[n]  ;
	scanf("%lld" , &val);
	sum[0] = val;
	prodsum[0] = sum[0] * val;
	currsum[0] = prodsum[0];
	for( int i = 1 ;i< n; i++){
		scanf("%lld" , &val);
		sum[i] = val + sum[i-1];
		prodsum[i] = val * sum[i];
		currsum[i] = prodsum[i] + currsum[i-1];
	}


	long long int res = 0;
	scanf("%d" , &q);
	while(q--){
		scanf("%lld %lld" , &a ,&b);
		if(a){
		res = (currsum[b]-currsum[a-1]-(sum[a-1]*(sum[b]-sum[a-1])));
		printf("%lld\n" , res);
		}
		else 
		printf("%lld\n" , currsum[b]);
	}
	return 0;
}