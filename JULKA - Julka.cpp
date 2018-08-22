/*

http://www.spoj.com/problems/JULKA/

Author : Selva Balasubramanian

*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> subtract(vector<int> a , vector<int>b){
	vector<int>::reverse_iterator ait , bit , cit;
	vector<int>::iterator rit;
	vector<int>result;

	ait = a.rbegin();
	bit = b.rbegin();

	for(; bit != b.rend() ; bit++ , ait++){

		if(*ait >= *bit){
			rit = result.begin();
			result.insert(rit, *ait - *bit);
		}
		else{
			cit = ait;cit++;
			while(*cit == 0){ *cit = 9;cit++; }
			*cit -= 1;
			*ait += 10;
			rit = result.begin();
			result.insert(rit, *ait - *bit);
			
		}
	}
	while(ait != a.rend()){
		rit = result.begin();
		result.insert(rit, *ait);
		ait++;
	}


	for(rit = result.begin() ;rit != result.end()  ;){
		if( *rit == 0)
			result.erase(rit);  //removing leading zeros
		else break;
		rit = result.begin();
	}
	if(result.size() == 0)result.push_back(0);
	
	return result;
}


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


vector<int> divide(vector<int> a){
	vector<int>::iterator it , rit;
	it = a.begin();
	vector<int> result;
		int temp  = 0;
		int carry ;
	while(it != a.end()){
		temp *= 10;
		temp += *it;
		if(temp == 1){
			temp = temp * 10;
			it++;
			result.push_back(0);
			temp += *it;
		}
		result.push_back(temp/2);
		temp %= 2;
		it++;

	}


	
	return result;
}

int main(){

	int t = 10;
	while(t--){

	string apples , k;
	vector<int>klaudia , natalia ,app ,app2, kvector;
	vector<int>::iterator rit ;
	vector<int>add1 ;
	klaudia.clear();
	natalia.clear();
	app.clear();
	app2.clear();
	kvector.clear();
	add1.clear();
	cin>>apples>>k;
	int len = apples.length();
	int klen = k.length();

	for(int i = 0; i<len ; i++){app.push_back(int(apples[i]-'0'));  }
	for(int i = 0; i<klen ; i++)kvector.push_back(int(k[i]-'0'));

	if(app.size()>= kvector.size())
	add1 = add(app , kvector);
	else
	add1 = add(kvector , app);
	klaudia = divide(add1) ;
	natalia = subtract(app , klaudia);

	for(rit = klaudia.begin() ;rit != klaudia.end()  && *rit == 0 ;){
		klaudia.erase(rit);  
		rit = klaudia.begin();
	}


	for(rit = klaudia.begin() ; rit != klaudia.end() ; rit++)cout<<*rit;
		cout<<endl;
	for(rit = natalia.begin() ; rit != natalia.end() ; rit++)cout<<*rit;
		cout<<endl;


	}
	return 0;
}