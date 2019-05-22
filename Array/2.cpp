Largest Unique Substring

Given a string S,
find the largest substring with no repetition i.e.largest substring which contain all unique characters.

// input - given string
// output - output string that contains largest unique substring
#include<bits/stdc++.h>
using namespace std;
void findLargestUniqueSubstring(char input[], char output[]){

    string s(input);
    int n=s.length();
    
    int i=0;
    int j=1;
    
    unordered_set<char> mySet;
    mySet.insert(s[0]);
    int maxLength=-1;
    int length=1;
    int st;
    int end;
    int maxSt;
    int maxEnd;
    st=0;
    end=0;
    
    while(i<=j && j<n){
        
        if(mySet.find(s[j])!=mySet.end()){
            // Cut our window from length
            auto it=mySet.find(s[j]);
            mySet.erase(it);
            i++;
            length--;
            st++;
        }
        else{
            // Increase our window
            mySet.insert(s[j]);
            j++;
            length++;
            end++;
            if(length>maxLength){
                maxLength=length;
                maxSt=st;
                maxEnd=end;
            }
        }
    }
    string ans="";
    for(int i=maxSt;i<=maxEnd;i++){
        ans=ans+s[i];
    }

    strcpy(output,ans.c_str());
}
