// #include <bits/stdc++.h>
#include<iostream>
#include<limits>

using namespace std;

struct node
{
   int sum,lbest;
   int rbest,max;
};

node tree[4*50010];
int ar[50010];

void build(int n,int start,int end)
{
   if(start == end)
   {
      tree[n].sum = ar[start];
      tree[n].lbest = ar[start];
      tree[n].rbest = ar[start];
      tree[n].max = ar[start];
   }
   else
   {
      int mid = (start+end)/ 2;
      build(2*n+1,start,mid);
      build(2*n+2,mid+1,end);
      
   
      tree[n].sum = tree[2*n+1].sum + tree[2*n+2].sum;
      tree[n].lbest = max(tree[2*n+1].lbest,tree[2*n+1].sum + tree[2*n+2].lbest);
      tree[n].rbest = max(tree[2*n+2].rbest,tree[2*n+2].sum + tree[2*n+1].rbest);	
      tree[n].max = max(tree[n].lbest,max(tree[n].rbest,max(tree[2*n+1].max,max(tree[2*n+2].max,tree[2*n+1].rbest +tree[2*n+2].lbest))));
   }
}

node query(int n,int start,int end,int l,int r)
{
   node result;
   result.sum=result.rbest=INT_MIN;
   result.lbest=result.max=INT_MIN;
   
   if(r<start || end<l)
      return result;
   if(l<=start && end<=r)	
      return tree[n];
   
   int mid = (start+end) / 2;
   if (l > mid)
         return query(2*n+2, mid+1, end, l, r);
   if (r <= mid)
         return query(2*n+1, start, mid, l, r);
   
   node left = query(2*n+1,start,mid,l,r);
   node right = query(2*n+2,mid+1,end,l,r);
   
   result.sum = left.sum + right.sum;
   result.lbest = max(left.lbest, left.sum + right.lbest);
   result.rbest = max(right.rbest, right.sum + left.rbest);
   result.max = max(result.lbest, max(result.rbest,  max(left.max, max(right.max,left.rbest + right.lbest))));
   return result;				
}

void update(int n , int start , int end , int val , int index){

   if(start == end){
      ar[start] = val;
      tree[n].sum = ar[start];
      tree[n].lbest = ar[start];
      tree[n].rbest = ar[start];
      tree[n].max = ar[start];
   }
   else{
      int mid = (start + end)/2;
      if(start <= index && mid >= index){
         update(2*n+1,start , mid, val , index);
      }
      else{
         update(2*n+2 ,mid+1 , end, val , index);
      }
      tree[n].sum = tree[2*n+1].sum + tree[2*n+2].sum;
      tree[n].lbest = max(tree[2*n+1].lbest,tree[2*n+1].sum + tree[2*n+2].lbest);
      tree[n].rbest = max(tree[2*n+2].rbest,tree[2*n+2].sum + tree[2*n+1].rbest);   
      tree[n].max = max(tree[n].lbest,max(tree[n].rbest,max(tree[2*n+1].max,max(tree[2*n+2].max,tree[2*n+1].rbest +tree[2*n+2].lbest))));
   }

}

int main() {
   int n,q,a,b,c;
   scanf("%d",&n);
   
   for(int i=0;i<n;++i)
      scanf("%d",&ar[i]);
   
   build(0,0,n-1);
   
   scanf("%d",&q);
   
   for(int i=0;i<q;++i)
   {
      scanf("%d",&c);
      if(c == 1){
         scanf("%d%d",&a,&b);
         printf("%d\n",query(0,0,n-1,a-1,b-1).max);
      }else{
         scanf("%d%d",&a,&b);
         update(0,0,n-1,b,a-1);
      }
   }	
   return 0;
}