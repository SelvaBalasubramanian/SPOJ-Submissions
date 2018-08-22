#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
#include<set>
#include<map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int q  , k ;
	while(cin>>q>>k){
		if(cin.eof())return 0;
		map<string , long long int> m;
		map<string , long long int> ::iterator mi;

		vector<long long int> s;
		m.clear();
		s.clear();
		vector <long long int> ::reverse_iterator it;
		string str;
		long long int val;
		for(long long int i = 0; i<q;i++){
			cin>>str>>val;
			m[str] += val;
		}

		for(mi = m.begin();mi != m.end() ;mi++)
			s.push_back(mi->second);
		long long int ans =0; 
		sort(s.begin(),s.end());
		for(it = s.rbegin() ; it != s.rend() ; it++){
			if(k>0){
				ans += *it;
				k--;
			}
			else break;
		}
		cout<<ans<<endl;
	}

	return 0;
}