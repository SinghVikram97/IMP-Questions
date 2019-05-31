/// Longest subarray with given sum

#include<bits/stdc++.h>
using namespace std;
int max(int arr[], int n) {
	
    // Replace 0 with -1
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            arr[i]=-1;
        }
    }
    
    // Find longest subarray with sum=0
    
    // Maps sum of previous subarray to it's last index
    
    unordered_map<int,int> mp ;
    
    // Empty subarray with 0 sum
    int targetSum=0;
    mp.insert({0,-1});

    
    int currentSum=0;  
    int maxLength=-1;
    for(int i=0;i<n;i++){
        
        currentSum=currentSum+arr[i];
        int target=currentSum-targetSum;
        
        if(mp.find(target)!=mp.end()){
            
            int startIndex=mp[target]+1;
            int endIndex=i;
            
            int length=endIndex-startIndex+1;
            
            maxLength=max(maxLength,length);
                
        }
        
        mp.insert({currentSum,i});
        
    }
    return maxLength;
}
