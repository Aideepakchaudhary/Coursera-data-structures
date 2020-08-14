#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s,name;
    map<int, string>m;
    std::map<int,string>::iterator it;
    int key;
    for(int i=0;i<n;i++)
    {
        cin.ignore();
        cin>>s;
        if(s=="add")
        {
            cin>>key>>name;
          it = m.find(key);
          if(it != m.end())
          {
              m.erase(it);
              m.insert(pair<int,string>(key,name));
          }
            else
                m.insert(pair<int,string>(key,name));
        }
        else if(s=="find")
        {
            cin>>key;
            it = m.find(key);
            if(it != m.end())
            cout<< m.find(key)->second <<"\n";
            else
                cout<<"not found"<<"\n";
        }
        else{
                cin>>key;
            it = m.find(key);
            if(it != m.end())
              m.erase(it);
        }
    }
    return 0;
}

