
/*

http://www.spoj.com/problems/AGGRCOW/

Author : Selva Balasubramanian

*/



#include<iostream>
#include<algorithm>
using namespace std;

	
long int findDistance(long int *ar , long int num , long int cows , long int n){

	long int cur = ar[0];
	long int c = 1;
	for(long int i = 1 ; i< n; i++){
		if(ar[i]-cur >= num){
			c++;
			if(c == cows)return 1;
			cur = ar[i];
		}
	}
	return 0;

}




long int binarySearch(long int *ar , long int n , long int cows){

	long int start = 0  , end = ar[n-1] ,mid =0 , max = -1;

	while(start < end){
		mid = (start + end) / 2;

		if(findDistance(ar , mid , cows , n)){
			if(mid > max)
				max = mid;
			start = mid + 1;
		}
		else{
			end = mid;
		}

	}
	return max;

}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int t;
	cin>>t;
	while(t--){
		long int n , c;
		cin>>n>>c;
		long int stall[n];

		for(long int i = 0; i< n;i++)cin>>stall[i];

		sort(stall ,stall + n);

		long int max = binarySearch(stall , n , c);
		cout<<max<<endl;
	}

	return 0;
}