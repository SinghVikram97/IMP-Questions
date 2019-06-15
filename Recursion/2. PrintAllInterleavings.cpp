#include <bits/stdc++.h>
using namespace std;

void inter(string s1,string s2,int i,int j,string temp){

    if(i==s1.length() && j==s2.length()){
        cout<<temp<<endl;
        return;
    }

    if(i==s1.length()){

        while(j!=s2.length()){
            temp=temp+s2[j];
            j++;
        }
        cout<<temp<<endl;
        return;
    }

    if(j==s2.length()){

        while(i!=s1.length()){
            temp=temp+s1[i];
            i++;
        }
        cout<<temp<<endl;
        return;
    }


    /// Take either from s1 or from 2

    inter(s1,s2,i+1,j,temp+s1[i]);
    inter(s1,s2,i,j+1,temp+s2[j]);

}

void interleaving(char* first, char* second) {

	string s1(first);
	string s2(second);


	inter(s1,s2,0,0,"");


}
