#include<iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int n , ans = 0 , k;
	cin>>n;

	while(n--){
		cin>>k;
		ans ^= k;
	}

	cout<<ans;

	return 0;
}