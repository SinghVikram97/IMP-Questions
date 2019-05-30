#include<bits/stdc++.h>
using namespace std;
void printPairs(int *input, int n, int k) {
	
    vector<int> v(input,input+n);
    
    unordered_map<int,int> mp;
    
    for(int i=0;i<n;i++){

        int num1=v[i]+k;
        int num2=v[i]-k;
        
        
        
        if(mp.find(num1)!=mp.end()){
            
            auto it=mp.find(num1);
            
            int freq=it->second;
            
            int a=min(v[i],num1);
            int b=max(v[i],num1);
            
            for(int i=0;i<freq;i++){
                
                cout<<a<<" "<<b<<endl;
                
            }
            
        }
        
        if(num1!=num2){

            if(mp.find(num2)!=mp.end()){
            
            auto it=mp.find(num2);
            
            int freq=it->second;
            
            int a=min(v[i],num2);
            int b=max(v[i],num2);
            
            for(int i=0;i<freq;i++){
                
                cout<<a<<" "<<b<<endl;
                
            }
        }
        
        
        }
    
        
        
        
        mp[v[i]]++;
    }
    

}


