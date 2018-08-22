#include<iostream>

using namespace std;

long long int Merge(long long int start , long long int end, long long int mid , long long int *ar){
    long long int pairs = 0 , count = 0;
    long long int p  = start ;
    long long int q = mid +1 ;
    long long int no = end - start +1;
    long long int d[no] , i = 0 ;
    while(i<no){
        if(p > mid){
            d[i++] =  ar[q++];
        }
        else if(q > end){
            d[i++]  =  ar[p++];
            pairs += count;
        }
        else if (ar[p] > ar[q]){
            d[i++] =  ar[q++];
            count++;
        }
        else{
            d[i++] = ar[p++];
            pairs += count; 
            
        }
    }
    int l = 0;
    for(start ; start <= end; l++,start++){
        ar[start] = d[l];
        // cout<<ar[start]<<" ";
    }
    // cout<<endl;
    
    return pairs;
}

long long int MergeSort(long long int start ,long long int end , long long int *ar){
    long long int pairs = 0;
    
    if (start < end){
        long long int mid = (start + end)/2;
        pairs += MergeSort(start , mid , ar);
        pairs += MergeSort(mid + 1 , end , ar);
        pairs += Merge(start , end , mid , ar);
    }
    
    
    return pairs;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int t ,i = 1 ;
    cin>>t;
    while( i<= t){
    long long int n;
    cin>>n;
    long long int ar[n];
    for(long long int i = 0 ;i<n ; i++){
        cin>>ar[i];
    }
   
    long long int k = MergeSort(0, n-1 , ar);
    k  %= 10000007;
    cout<<"Case "<<i<<": "<<k<<endl;
    i++;
    }
    return 0;
}