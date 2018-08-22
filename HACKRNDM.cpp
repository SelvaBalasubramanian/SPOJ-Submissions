// http://www.spoj.com/problems/HACKRNDM/


#include<iostream>
#include<algorithm>

using namespace std;
int main(){

	long int n , k , count = 0;
	scanf("%ld %ld" , &n ,&k);
	long int ar[n];
	for(long int i = 0 ;i< n ; i++)scanf("%ld" , &ar[i]);
		sort(ar , ar+n);
	long int j = 1;
	for(long int i = 0 ; i<n-1; i++){
		while(ar[i] + k > ar[j] && j<n)j++;
		if(ar[i] + k == ar[j]){
			count++;
		}
	}
	printf("%ld\n",count);
	return 0;
}