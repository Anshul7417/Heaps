#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    //creation
    unordered_map<string, int> m;
    //insertion
    //1
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);
    //2
    pair<string, int> pair2("love", 2);
    m.insert (pair2);
    //3
    m["mera"] = 1;
    //it updates because map has only unique entries
    m["mera"] = 2;



 cout << m["mera"] << endl;
cout << m.at("babbar") << endl;
cout << m["unknownKey"] << endl;   // shows 0 and creates
cout << m.at("unknownKey") << endl;  // also shows 0 but if this line was above line 26 then error

//size
cout<<m.size();


//presence
cout<<m.count("love");


//erase
m.erase("babbar");


//iterator
unordered_map<string, int> :: iterator it = m.begin();
while(it != m.end()) {
cout << it->first <<" "<< it->second << endl;
it++;
}


//but if we print then unorderd map prints in unordered way but map prints in ordered
//complexity of ordered o(logn)  bst impl
// uno map o(1) hashtable

    return 0;
}