int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here
    unordered_map<int,int> mp;

    // for(int i=0;i<n;i++){       it does not preserve order
    //     mp[arr[i]]++;
    // }

    // int maxi = INT_MIN;
    // int ans = -1;
    // for(auto i:mp) {
    //   if (i.second > maxi) {
    //     maxi = i.second;
    //     ans = i.first;
    //   }
    // }

    // return ans;


    int maxFreq = 0;
    int maxAns = 0;
    for(int i=0; i<arr.size(); i++){
    mp[arr[i]]++;
    maxFreq = max(maxFreq, mp[arr[i]]);
    }
    for(int i=0; i<arr.size(); i++){
    if(maxFreq == mp[arr[i]]){
    maxAns = arr[i];
    break;
    }
    }
    return maxAns;
}