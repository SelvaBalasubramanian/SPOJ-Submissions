/*

http://www.spoj.com/problems/BUSYMAN/

Author : Selva Balasubramanian

*/

#include<bits/stdc++.h>

using namespace std;

int  compare(pair< long int , long int >a , pair< long int , long int >b){
		return a.second < b.second ;
	}
	

 int main(){

 	int t;
 	cin>>t;
 	while(t--){
 		long int n;
 		cin>>n;
 		long int c , d;
 		vector< pair<long int , long int> > a;
 		for(int i = 0 ; i< n;i++){
 			cin>>c>>d;
 			a.push_back(make_pair(c,d));
 		}

 		sort(a.begin() , a.end() , compare);
 		long int count =1;
 		int i = 0 , j = 0;
 		for(j =1 ; j< n ; j++){
 			if(a[j].first >= a[i].second){
 				count++;
 				i = j;
 			}
 		}
 		cout<<count<<endl;

 	}	

 	return 0;
 }