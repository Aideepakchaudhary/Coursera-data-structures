#include<bits/stdc++.h>
using namespace std;

#define p 100000007
#define x 263


class Hash
{
private:
    int Bucket;
    list<string>*table;
public:
    Hash(int V);
    int hashfunction(int m,string key);
    void insertItem(int m,string name);
    void removeItem(int m, string name);
    string findItem(int key,string name);
    string checkItem(int key);
};
Hash::Hash(int b)
{
    this->Bucket = b;
    table = new list<string>[Bucket];
}
void Hash::insertItem(int m,string name)
{
    int index = hashfunction(m,name);
    table[index].push_back(name);
}
int Hash::hashfunction(int m,string key)
{
    unsigned long long value=0;
    for(int i =0; i<key.size();i++)
    {
        value += (int)key[i]*pow(x,i);
    }
    value = (value%1000000007)%m;
    return  value;
}
void Hash::removeItem(int m, string name)
{
    int index = hashfunction(m, name);
    list<string>::iterator i;
    for(i=table[index].begin();i!=table[index].end();i++)
    {
        if(*i==name)
            break;
    }
    if(i!=table[index].end())
        table[index].erase(i);
}
string Hash::findItem(int m, string name)
{
    int index = hashfunction(m, name);
    list<string>::iterator i;
    for(i=table[index].begin();i!=table[index].end();i++)
    {
        if(*i==name)
            break;
    }
    if(i!=table[index].end())
        cout<<"yes";
    else
        cout<<"no";
}

string Hash::checkItem(int key)
{
    list<string>::iterator i;
    for(i=table[key].begin();i!=table[key].end();i++)
    {
        cout<<"yes"<<"\n";
        cout<<table<<"\n";
    }
   /* for(auto r: table[i])
        cout<<r<<"\n";*/
}

int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        string a;
    cin>>a;

    Hash h(m);
    if(a=="add")
    {
        string b;
    cin>>b;
        h.insertItem(m,b);
    }
    else if(a == "del")
    {
        string b;
    cin>>b;
        h.removeItem(m,b);
    }
    else if(a == "find")
    {
        string b;
    cin>>b;
        h.findItem(m,b);
    }
    else if(a == "check")
    {
        int key;
        cin>>key;
        h.checkItem(key);
    }
    }

    return 0;
}

