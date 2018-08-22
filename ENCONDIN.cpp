#include<iostream>
using namespace std;

int main(){

	string s;
	while(getline(cin,s)){
			if(cin.eof()){return 0;}

		int len = s.length();
	
		if(len == 1){
			printf("1%c1\n",s[0]);
			continue;
		}
		for(int i = 0; i< len ;){
			if(s[i] != s[i+1]){
				printf("1");
				while(s[i]!=s[i+1] && i<len){
					if(s[i] == '1')printf("1");
					printf("%c",s[i]);
					i++;
				}
				printf("1");
			}
			else{
				int c = 1;
				while(s[i] == s[i+1] && i<len && c<9){
					c++;
					i++;
				}
				printf("%d%c",c,s[i]);	
				i++;			
			}
		}
		printf("\n");
	}


	return 0;
}