#include<bits/stdc++.h>
using namespace std;

template<typename T>
class OurMap{

    private:

        struct MapNode{

            string key;
            T value;
            MapNode *next;

            MapNode(string k,T v){
                key=k;
                value=v;
                next=NULL;
            }

            ~MapNode(){
                delete next;
            }

        };

        vector<MapNode> buckets;
        int totalSize;
        int numBuckets;
        int getBucketIndex(string k){

            int hashCode;
            int currentCoeff=1;

            for(int i=k.length();i>=0;i--){
                hashCode+=k[i]*currentCoeff;
                hashCode%=numBuckets;
                currentCoeff*=37;
                currentCoeff%=numBuckets; /// To prevent from integer overflow
            }

            return hashCode%numBuckets;

        }

    public:
        OurMap();
        ~OurMap();
        int getSize();
        void insertKeyVal(string k,T v);
        T getVal(string k);
        T removeVal(string k);

};

template<typename T>
OurMap<T>::OurMap(){

    totalSize=0;
    numBuckets=5;
    buckets=vector<MapNode> (5);
    for(int i=0;i<numBuckets;i++){
        buckets[i]=NULL;
    }

}
template<typename T>
OurMap<T>::~OurMap(){
    for(int i=0;i<numBuckets;i++){
        delete buckets[i];
    }
}
template<typename T>
int OurMap<T>::getSize(){
    return totalSize;
}
template<typename T>
void OurMap<T>::insertKeyVal(string k,T val){

    int bucketIndex=getBucketIndex(k);

    /// Agar key pehle se hai toh update value
    MapNode *head=buckets[bucketIndex];


    while(head!=NULL){

        if(head->key==k){
            head->value=val;
            return;
        }
        head=head->next;
    }

    head=buckets[bucketIndex];

    MapNode *newNode=new MapNode(k,val);

    newNode->next=head;

    buckets[bucketIndex]=newNode;

    totalSize++;

    return;

}
template<typename T>
T OurMap<T>::getVal(string k){

    int bucketIndex=getBucketIndex(k);
    MapNode *head=buckets[bucketIndex];
    int value;
    while(head!=NULL){

        if(head->key==k){

            value=head->value;
            return value;

        }
        prev=head;
        head=head->next;

    }
    return 0;
}

template<typename T>
T OurMap<T>::removeVal(string k){

    int bucketIndex=getBucketIndex(k);
    MapNode *head=buckets[bucketIndex];
    MapNode *prev=NULL;
    T value;

    while(head!=NULL){

        if(head->key==k){

            value=head->value;

            if(prev==NULL){
                buckets[bucketIndex]=head->next;
            }
            else{
                prev->next=head->next;
            }

            head->next=NULL;
            totalSize--;
            delete head;
            return value;

        }
        prev=head;
        head=head->next;

    }
    return 0;
}

