#include<iostream>

using namespace std;

int main(){

	int t;
	scanf("%d" , &t);

	while(t--){
		int n ;
		long long int a;
		scanf("%d" , &n);
		while(n--){
			scanf("%lld" ,&a);
			int  c , d ;
			if(a < 0 )
				printf("%lld ", a);
			else{
				if(a > 6)printf("-4 ");
				else{
					c = a%3;
					d = a%4;
					if(c < d){
						printf("%d ", c-4);
					}
					else{
						printf("%d ", d-4);
					}
				}
			}
		}
		printf("\n");
	}


	return 0;
}