#include<bits/stdc++.h>
using namespace std;

//#define p 1000003
#define x 256

vector<int>arr;

void rabinkarb(string txt,string pat,int q)
{
    int i,j;
    long long int p =0;
    long long int t =0;
    long long int h = 1;
    int m = pat.size();
    int n = txt.size();
    for (i = 0; i < m - 1; i++)
        h = (h * x) % q;

    for(i=0;i<m;i++)
    {
        p = (p*x + pat[i])%q;
        t = (t*x + txt[i])%q;
    }
    for(i=0;i<= n-m;i++)
    {
        if(p==t)
        {
            for(j=0;j<m;j++)
            {
                if(txt[j+i]!=pat[j])
                    break;
            }
            if(j==m)
                cout<<i<<" ";
                else
                    cout<<"no";
        }
        if(i<n-m)
        {
            t = (x*(t-(txt[i]*h))+txt[i+m])%q;
            if(t<0)
                t = t+q;
        }
    }
}

int main()
{
    string p,t;
    cin>>p>>t;
    int q = 10000003;
    rabinkarb(t,p,q);
    return 0;
}
