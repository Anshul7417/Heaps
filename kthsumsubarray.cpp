//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int k){
        priority_queue<int,vector<int>,greater<int>> mini;
        
        int n=Arr.size();
        
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=Arr[j];
                if(mini.size()<k){
            
                    mini.push(sum);
                }
                else{
                    if(sum>mini.top()){
                        mini.pop();
                        mini.push(sum);
                    }
                }
            }
        }
        
        return mini.top();
    }
};