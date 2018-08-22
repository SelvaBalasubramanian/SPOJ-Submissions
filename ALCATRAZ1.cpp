#include<iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int len = s.length();
		int sum = 0;
		for(int i = 0 ; i<len ; i++){
			sum += s[i]-48;
		}
		cout<<sum<<endl;
	}


	return 0;
}