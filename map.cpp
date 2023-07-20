#include<map>
#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    //creation 
    unordered_map<string,int> m;
    //insertion 
    //1
    pair<string,int> p=make_pair("abhay",3);
    m.insert(p);
    //2
    pair<string,int> pair2("Deopa",5);
    m.insert(pair2);
    //3
    m["mera"]=1;
    //4
    m["mera"]=2;

    //search
    cout<<m["mera"]<<endl;
    cout<<m.at("abhay")<<endl;
    return 0;
}