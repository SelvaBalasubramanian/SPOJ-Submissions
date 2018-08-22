/*

// http://www.spoj.com/problems/YODANESS/

Author : Selva Balasubramanian

*/


#include<iostream>
#include<map>

using namespace std;

int merge(int *ar , int start ,int mid,  int end){
	int pairs = 0 , count = 0;
	int n = end - start + 1;	
	int arr[n];
	int i = 0 , a = start , b = mid+1;
	while(i<n){
		if(a>mid){
			arr[i++] = ar[b++];
		}
		else if (b>end){

			arr[i++] = ar[a++];
						pairs += count;
		}
		else if(ar[a] > ar[b]){
			arr[i++] = ar[b++];
			count++;	
		}
		else{
			arr[i++] = ar[a++];
			pairs += count;
		}
	}
	
	for( i=0 ;start <= end; start++ , i++){
		ar[start] = arr[i];
	}

	return pairs;

}


int mergesort(int *ar , int start , int end ){
	int pairs = 0;
	if(start < end){
		int mid = (start + end) / 2;
		pairs += mergesort(ar , start , mid );
		pairs += mergesort(ar ,mid+1 , end );
		pairs += merge(ar , start , mid , end);
	}
	return pairs;
}

int main(){
	int t ; 
	cin>>t;

	map<string , int >m;

	while(t--){
		int n;
		string s;
		cin>>n;
		int ar[n];
		int i = 0;
		while(i<n){
			cin>>s;
			m[s] = i;
			i++;
		}
		i=0;
		while(i<n){
			cin>>s;
			ar[m[s]] = i;
			i++;
		}
		cout<<mergesort(ar,0,n-1)<<endl;
	}


}