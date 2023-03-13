#include<bits/stdc++.h>
Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    // Write your code here.
    vector<int>v;
    for(auto i : listArray)
    {
        while(i != NULL)
        {
            v.push_back(i->data);
            i = i->next;
        }
    }
    if(v.size() == 0) return NULL;
    
    sort(v.begin(),v.end());
    
    Node<int>*head = new Node<int>(v[0]);
    Node<int>*temp = head;
    
    for(int i = 1;i<v.size();i++)
    {
        Node<int>*num = new Node<int>(v[i]);
        temp->next = num;
        temp = temp->next;
    }
    
    return head;
}
