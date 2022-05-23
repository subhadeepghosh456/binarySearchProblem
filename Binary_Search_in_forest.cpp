#include<bits/stdc++.h>
using namespace std;

 int totalWood(int tree[],int n,int mid){
        int count = 0;
        
        for(int i=0;i<n;i++){
            
            if(tree[i]>=mid){
                count += (tree[i]-mid);
            }
            
        }
        return count;
    }
    
    int find_height(int tree[], int n, int k)
    {
        // code here
        int start = 0;
        int maxi = INT_MIN;
        int ans = 0;
        int end=0;
        
        for(int i=0;i<n;i++){
            maxi = max(tree[i],maxi);
        }
        end = maxi;
        
        while(start<=end){          
            int mid = (start+end)/2;
            ans = totalWood(tree,n,mid);
            if(k==ans){
                return mid;
            }           
            else if(ans < k){              
                end = mid-1;                
            }
            else if(ans > k){
                start = mid+1;
            }           
        }
        return -1;
    }

    int main(){
        int tree[20];
        int n , k;
        cin >> n >> k;
        for(int i=0;i<n;i++){
           cin>>tree[i];
        }

        cout<<find_height(tree, n, k);

    }