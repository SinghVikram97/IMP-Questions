Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.

#include<bits/stdc++.h>
using namespace std;
bool isPerfectSquare(int n){
    
    
    if(sqrt(n)==floor(sqrt(n))){
        return true;
    }
    else{
        return false;
    }
    
    
}
int minCount(int n){

    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
 
    // Find closest square
    if(isPerfectSquare(n)){
        return minCount(0)+1;
    }
    
    else{
        
        int temp=n-1;
        
        while(true){
            
            if(isPerfectSquare(temp)){
                break;
            }
            else{
                temp--;
            }
            
            
        }
        return 1+minCount(n-temp);
    }


}
