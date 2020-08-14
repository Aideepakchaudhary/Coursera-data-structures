#include<bits/stdc++.h>
using namespace std;

#define m1 1000000007
#define m2 1000000009
#define x  256
void Search(string s,int a, int b,int l)
{
    vector<char>str1;
    vector<char>str2;
    int final1 = (l+a)-1;
    int final2 = (l+b)-1;
    for(int i=a;i<=final1;i++)
        str1.push_back(s[i]);
    for(int i=b;i<=final2;i++)
        str2.push_back(s[i]);
    int length1 = str1.size();
    int length2 = str2.size();
    long long int h1[length1],h2[length2],h11[length1],h22[length2];
    for(int i=0;i<length1;i++)
    {
        h1[i] = 0;
        h11[i] = 0;
    }
    for(int i=0;i<length2;i++)
    {
        h2[i] = 0;
        h22[i] = 0;
    }
    for(int i=1;i<length1;i++)
    {
        h1[i] = (x * h1[i - 1] + str1[i])%m1;
        h11[i] = (x * h11[i - 1] + str1[i])%m2;
    }
    for(int i=1;i<length2;i++)
    {
        h2[i] = (x * h2[i - 1] + str2[i])%m2;
        h22[i] = (x * h22[i - 1] + str2[i])%m1;
    }
    if((h1[final1]==h2[final2]) && (h11[final1]==h22[final2]))
        cout<<"Yes\n";
    else
        cout<<"No\n";
}

int main()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    int a[n],b[n],l[n];
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i]>>l[i];
    for(int i=0;i<n;i++)
    {
        Search(s,a[i],b[i],l[i]);

    }

    return 0;
}
