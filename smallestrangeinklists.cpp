// you are required to complete this function 
// function should print the required range
#include<bits/stdc++.h>

class node{
     public:
        int data;
        int row;
        int col;
        
        
        node(int d,int r,int c){
            data=d;
            row=r;
            col=c;
        }
};

class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data>b->data;
        }
};
class Solution{
    public:
        pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
        {
              //code here
              int mini=INT_MAX;
              int maxi=INT_MIN;
              
              priority_queue<node*, vector<node*>, compare> minHeap;
              
              
              for(int i=0;i<k;i++){
                  int element=KSortedArray[i][0];
                  mini=min(mini,element);
                  maxi=max(maxi, element);
                  minHeap.push(new node(element, i, 0));
              }
              
              
              int start=mini; 
              int end=maxi;
              
              while(!minHeap.empty()){
                  node * temp = minHeap.top();
                  minHeap.pop();
                  
                  mini=temp->data;
                  
                  
                  if(maxi-mini<end-start){
                      start=mini;
                      end=maxi;
                  }
                  
                  
                  if(temp->col+1<n){
                      maxi=max(maxi,KSortedArray[temp->row][temp->col+1]);
                      minHeap.push(new node(KSortedArray[temp->row][temp->col+1],temp->row,temp->col+1));
                  }else{
                      break;
                  }
              }
              
              pair<int,int> ans=make_pair(start,end);
              
              return ans;
        }
};