Longest Consecutive Subsequence

#include<bits/stdc++.h>
using namespace std;

vector<int> longestSubsequence(int *arr, int n){
	
    unordered_set<int> ms;
    
    for(int i=0;i<n;i++){
        ms.insert(arr[i]);
    }
    int maxS;
    int maxE;
    int count;
    int maxCount=-1;
    
    for(int i=0;i<n;i++){
        
        if(ms.find(arr[i]-1)==ms.end()){
            // Start of a sequence
            
            count=0;
            int j=arr[i];
            
            while(ms.find(j)!=ms.end()){
                count++;
                j++;                
            }
            
            if(count>maxCount){
                maxCount=count;
                maxS=arr[i];
                maxE=j-1;
            }
        }
    }
    vector<int> ans;
    for(int i=maxS;i<=maxE;i++){
        ans.push_back(i);
    }
    return ans;
}
