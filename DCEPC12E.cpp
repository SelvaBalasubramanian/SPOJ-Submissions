#include<iostream>
#include<string>
#include <map>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	long long int a[n][n],b[n][n];
	for(int i = 0 ; i< n ;i++){
		for(int j = 0 ; j<n; j++){
			scanf("%lld",&a[i][j]);
		}
	}

	for(int i = 0 ; i< n ;i++){
		for(int j = 0 ; j<n; j++){
			scanf("%lld",&b[i][j]);
		}
	}

	map<string , long long int> m;
	long long int sum = 0; 
	for(int i = 0; i< n; i++){
		for(int j = 0 ; j<n;j++){
				string s ;
			for(int k = 0; k<n;k++){
				long long int val = 0;
				s += to_string(i);
				s += to_string(k);
				s += to_string(k);
				s += to_string(j);
				val = a[i][k] * b[k][j];
				sum += val;
				m[s] = val;
			}
		}
	}


	long int q;
	scanf("%ld",&q);
	char aa;
	int i , j;
	long long int k;
	cout<<q;
	while(q--){
		scanf("%c%d%d%lld",&aa,&i,&j,&k);	
		string s ;
		if(aa == 'A'){
			a[i][j] = k;
			long long int val = 0;
			int t = n;
			s += to_string(i);
			s += to_string(j);
			s += to_string(j);

			for(int l = 0; l< n;l++){
				string ss;
				ss = s;
				ss += to_string(l);
				val = m[ss];
				sum -= val;
				m[s] =  a[i][j] * b[l][j]; 
				sum += m[ss];
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
}


