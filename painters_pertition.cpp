#include<bits/stdc++.h>
using namespace std;

  bool isPossible(int arr[],int n,int k,int mid){
      long long int count = 1;
      long long int sum=0;
      for(int i=0;i<n;i++){
          if(sum + arr[i]<=mid){
              sum = sum + arr[i];
          }
          else{
              count++;
              if(count>k || arr[i]>mid){
                  return false;
              }
              sum = arr[i];
          }
      }
      return true;
  }
long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        
        long long int start = 0;
        long long int sum = 0;
        
        for(int i=0;i<n;i++){
            sum = sum+arr[i];
        }
        long long int end = sum;
        long long int ans = -1;
        
        while(start<=end){
            long long int mid = start + (end-start)/2;
            
            if(isPossible(arr,n,k,mid)==true){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
                
            }
            
        }
        return ans;
    }

    int main(){
        int arr[30];
        int n,k;

        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<minTime( arr, n, k);
    }
