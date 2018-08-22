#include<iostream>
using namespace std;

void seive(bool *prime , int n){

	for(int i = 2 ; i<n+1 ; i++){
		prime[i] = false;
	}

	for(int i = 2 , j; i < (n/2) ; ){
		j = i+i;
		while(j <= n){
			prime[j] = true;
			j += i;
		}
		i++;
		while(prime[i])i++;
	}

}


int main(){
	int n;
	cin>>n;
	bool prime[n+1];
	seive(prime , n);
	for(int i = 2 ; i<n+1 ; i++){
		if(!prime[i])cout<<i<<" ";
	}
	return 0;
}