#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> books,int m,int mid){
    
    int students=1;
    int total = 0;
    
    for(int i=0;i<books.size();i++){
        
        if(books[i]+total <= mid){
            total += books[i];
        }
        else{
            students++;
            if(students>m or books[i]>mid){
                return false;
            }
            total=books[i];
        }
    }
    
    return true;
    
    
}

int minPages(vector<int> books, int m){
    
    
    int sum=0;
    int minimum = INT_MAX;
    for(int i=0;i<books.size();i++){
        sum+=books[i];
        minimum = min(books[i],minimum);
        
    }
    
    int s=minimum;
    int e=sum;
    int ans=0;
    
    
    while(s<=e){
        int mid = (s+e)/2;
        
        
        bool p = isPossible(books,m,mid);
        if(p==true){
            
            ans = mid;
            e=mid-1;
            
        }else{
            s=mid+1;
        }
    }
    
    return ans;
  
}