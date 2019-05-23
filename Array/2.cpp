Largest Unique Substring
https://leetcode.com/submissions/detail/162924558/

Given a string S,
find the largest substring with no repetition i.e.largest substring which contain all unique characters.

// input - given string
// output - output string that contains largest unique substring
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_set<char> st;
        /// Windows from [start,end) i=start and j=end
        int i=0,j=0; /// Intially window from [0,0) so no element included 
        int maxCount=0;
        while(i<n && j<n){
            // If element doesn't exist in current substring
            if(st.find(s[j])==st.end()){
                // Move window to the right ie. include j in window
                st.insert(s[j]);
                j++;
                maxCount=max(maxCount,j-i);  // Current window is [i,j)
            }
            else{
                // Remove that element from map
                st.erase(s[i]);
                // Increase the start
                i++;
                // Now we can add s[j] as it's duplicate has been removed
            }
        }
        return maxCount;
    }
};


// Printing longest unique substring
// input - given string
// output - output string that contains largest unique substring
#include<bits/stdc++.h>
using namespace std;
void findLargestUniqueSubstring(char input[], char output[]){

    string s(input);
    int n=s.length();
    unordered_set<char> st;
    /// Windows from [start,end) i=start and j=end
    int i=0,j=0; /// Intially window from [0,0) so no element included 
    int maxCount=0;
    int maxSt;
    int maxEnd;
    int start=0;
    int end;
    while(i<n && j<n){
    // If element doesn't exist in current substring
    if(st.find(s[j])==st.end()){
    // Move window to the right ie. include j in window
        st.insert(s[j]);
        j++;
        end=j-1;
        if(j-i>maxCount){
            maxCount=j-i;  // Current window is [i,j)
            maxSt=start;
            maxEnd=end;
        }
        
     }
     else{
        // Remove that element from map
        st.erase(s[i]);
        // Increase the start
        i++;
        // Now we can add s[j] as it's duplicate has been removed
        start++;
     }
   }
    string ans="";
    for(int i=maxSt;i<=maxEnd;i++){
        ans=ans+s[i];
    }
    strcpy(output,ans.c_str());
}
