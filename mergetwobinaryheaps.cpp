// User function Template for C++

class Solution{
    public:
    
    
    void heapify(vector <int> &arr, int n, int i){
     
     int largest = i;
     int left = 2*i+1;
     int right= 2*i+2;


     if(left<n && arr[largest]<arr[left]){
        largest=left;
     }if(right<n && arr[largest]< arr[right]){
        largest=right;
     }


     if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
     }
     
}

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> ans;
        
        //step 1 merge both arrays into one
        for(auto i : a )
            ans.push_back(i);
            
        for(auto i: b)
            ans.push_back(i);
            
        
        int s=ans.size();
        for(int i=(s/2)-1;i>=0;i--){
            heapify(ans,s,i);
        }
        
        
        return ans;
    }
};