/*

http://www.spoj.com/problems/ADDREV/

Author : Selva Balasubramanian

*/

#include<iostream>
#include<vector>

using namespace std;


vector<int>add(vector<int>a , vector<int>b){
	vector<int>::reverse_iterator ait , bit , cit;
	vector<int>::iterator rit;

	ait = a.rbegin();
	bit = b.rbegin();
	int carry = 0;

	for(; bit != b.rend() ; ait++,bit++){
		*ait = *ait + carry + *bit;
		int temp = *ait % 10;
		carry = *ait / 10;
		*ait = temp;
	}
	while(carry != 0){
		if(ait == a.rend()){
			rit = a.begin();
			a.insert(rit , carry);
		}
		else
			*ait = *ait + carry;
		carry = *ait / 10;
		*ait %= 10;
		ait++;
	}
	

	return a;
}


 int main(){

 	int t;
 	cin>>t;
 	while(t--){
 		vector<int>aa , bb;
 		vector<int>::reverse_iterator rit;
 		string a , b;
 		cin>>a>>b;
 		long int alen = a.length();
 		long int blen = b.length();

 		for(long int i = alen-1; i>=0 ; i--){aa.push_back(int(a[i]-'0')); }
 		for(long int i = blen-1; i>=0 ; i--){bb.push_back(int(b[i]-'0')); }
 		vector<int>sum  ;
 		if(alen>blen) sum = add(aa, bb);
 		else sum = add(bb,aa);


 		bool found = false;
		for(rit = sum.rbegin() ;rit != sum.rend(); rit++){
			if(*rit != 0){
				found= true;
			}
			if(found)
				cout<<*rit;
		}
		cout<<endl;

 	}


 	return 0;
 }