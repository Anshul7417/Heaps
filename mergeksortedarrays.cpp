//User function Template for C++

class node{
    public:
        int data;
        int i;
        int j;
        
        node(int dat, int row, int col){
            data=dat;
            i=row;
            j=col;
            
        }
};


class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<node*,vector<node*>,compare> minheap;
        
        for(int i=0;i<K;i++){
            node* tmp=new node(arr[i][0], i, 0);
            minheap.push(tmp);
        }
        
        
        vector<int> ans;
        
        while(minheap.size()>0){
            node * tmp=minheap.top();
            ans.push_back(tmp->data);
            minheap.pop();
            
            
            int i=tmp->i;
            int j=tmp->j;
            
            
            if(j+1<arr[i].size()){
                node* next = new node(arr[i][j+1], i, j+1);
                minheap.push(next);
            }
        }
        
        
        return ans;
    }
};