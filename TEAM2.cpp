#include<iostream>
#include<algorithm>
using namespace std;

int main(){

	long long int size , ar[4];
	int  j = 1;

	while( scanf("%lld" ,&size) != EOF){
		ar[0] = size;
		int  i = 1 ;
		while(i<4){
			scanf("%lld" ,&size);
			ar[i] = size;
			i++;
		}
		sort(ar, ar+4);
		printf("Case %d: %lld\n",j,ar[3] + ar[2]);
		j++;
	}


	return 0;
}