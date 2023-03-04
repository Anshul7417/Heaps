#include<iostream>
#include<queue>

using namespace std;

int main()
{
    priority_queue<int> pq;
    //default is max heap


    pq.push(5);
    pq.push(26);
    pq.push(50);
    pq.push(89);
    pq.push(9);

    cout<<pq.top();


    priority_queue<int, vector<int>, greater<int>> minheap;     //min heap 
    return 0;
}