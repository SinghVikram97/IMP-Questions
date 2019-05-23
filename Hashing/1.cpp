https://www.geeksforgeeks.org/print-all-pairs-with-given-sum/
#include<bits/stdc++.h>
using namespace std;
void PairSum(int a[],int n) {
   
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        
        int numToSearch=(-1*a[i]);
        int num1=a[i];
        
        if(mp.find(numToSearch)!=mp.end()){
            
            for(int i=1;i<=mp[numToSearch];i++){
                if(num1<numToSearch){
                    cout<<num1<<" "<<numToSearch<<endl;
                }    
                else{
                    cout<<numToSearch<<" "<<num1<<endl;
                }
            }
            
        }
        mp[a[i]]++;       
        
    }
    
}
