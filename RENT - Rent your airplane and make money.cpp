
/*

http://www.spoj.com/problems/RENT/

Author : Selva Balasubramanian

*/


//sryy guyss...this solution  gives correct ans for all testcase in spojkit still WA in spoj....

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int compare(pair < pair < long int , long int > , long int >a , pair < pair < long int , long int > , long int >b ){
	return a.first.second > a.first.second;
}

int main(){
		ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; 
	cin>>t;

	while(t--){
		int n ; 
		long int a , b ,w;
		cin>>n;
		vector< pair < pair <long int , long int > , long int > >  jobs;
			long int weight[n];
		for(int i = 0 ; i< n ; i++){
			cin>>a>>b>>w;
			jobs.push_back(make_pair(make_pair(a , a+b) , w));
		}

		sort(jobs.begin() , jobs.end() , compare);

		long int i , j;
		
		for(i =0;i<n ; i++){
			weight[i] =  jobs[i].second;
		}

		long int max = 0;

		for(int i = 0 ; i< n-1; i++){
			for(int j = i+1 ; j<n ; j++){
				if(jobs[i].first.second <= jobs[j].first.first){
					 w= weight[i]+ jobs[j].second;
					if(w > weight[j]){
						weight[j] = w;
						if(weight[j] > max)max = weight[j];
					}
				}
			}
		}
		cout<<max<<endl;

	}


	return 0;
}

