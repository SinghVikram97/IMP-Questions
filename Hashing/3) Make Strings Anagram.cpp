
#include<bits/stdc++.h>
using namespace std;
int makeAnagram(char str1[], char str2[]){
	
    string s1(str1);
    string s2(str2);
    
    unordered_map<char,int> mp;
    
    for(int i=0;i<s1.length();i++){
        mp[s1[i]]++;
    }
    
    unordered_map<char,int> mp1;
    
    for(int i=0;i<s2.length();i++){
        mp1[s2[i]]++;
    }
    
    int count=0;
    
    for(int i=0;i<26;i++){
        
        char ch='a'+i;
        
        count=count+abs(mp[ch]-mp1[ch]);
        
        
    }
    
    return count;
    
}
