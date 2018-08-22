#include<iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t , n , k , i = 1;
	cin>>t;
	while(i <= t){
		cin>>n>>k;
		int sum = 0 , val;
		for(int j = 0; j< n; j++){
			cin>>val;
			sum+=val;
		}
		n++;
		k = (k*n)-sum;
		cout<<"Case "<<i<<": "<<k<<endl<<endl;
		i++;
	}


	return 0;
}