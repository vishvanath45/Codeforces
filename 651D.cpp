#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define M (ll)(1e9+7)
ll aage[500011],piche[500011];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll i,j,k,l,t,n,q,r,x,c,a,b;
 
    cin>>n>>a>>b>>t;
    string s;
    cin>>s;
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            if(s[i]=='w')
            {
                aage[i]=b+1;
            }
            else
            {
                aage[i]=1;
            }
        }
        else
        {
            if(s[i]=='w')
            {
                aage[i]=aage[i-1]+a+b+1;
            }
            else
            {
                aage[i]=aage[i-1]+a+1;
            }
        }
    }
    reverse(s.begin(),s.end());
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            if(s[i]=='w')
            {
                piche[i]=a+b+1;
            }
            else
            {
                piche[i]=a+1;
            }
        }
        else
        {
            if(s[i]=='w')
            {
                piche[i]=piche[i-1]+a+b+1;
            }
            else
            {
                piche[i]=piche[i-1]+a+1;
            }
        }
    }
    // for(i=0;i<n;i++)
    //     cout<<aage[i]<<" ";
    if(t<aage[0])
    {
        cout<<"0\n";
        return 0;
    }
    if(t>=aage[n-1])
    {
        // cout<<"jdcjsdhbcskdv";
        cout<<n;
        return 0;
    }
    ll low=1;
    ll high=n;
    ll ans;
    ll p=0;
    while(low<=high)
    {
        // p++;
        // if(p>=10)
        //     break;
        // cout<<low<<" "<<high<<"\n";
        ll mid=(low+high)/2;
        ll timetaken=0;
        ll temp=1,temp1=1;
        if(aage[mid-1]<=t)
        {
            // cout<<mid<<" ";
            ans=mid;
            low=mid+1;
            continue;
        }
        for(i=0;i<mid;i++)
        {
            if((mid-i-2)<0)
                continue;
            if((aage[i]+piche[mid-i-2]+i*a)<=t)
            {
                // cout<<"dfj";
                // cout<<(aage[i]+piche[mid-i-2]+i*a)<<" ";
                // cout<<i<<" "<<mid<<" ";
                ans=mid;
                low=mid+1;
                temp=0;
                temp1=0;
                break;
            }
        }
        if(temp1)
        {
            for(i=0;i<mid;i++)
            {
                if((mid-i-2)<0)
                    continue;
                if((aage[mid-i-2]+piche[i]+(i+1)*a)<=t)
                {
                    ans=mid;
                    // cout<<"dfj";
                    low=mid+1;
                    temp=0;
                    // temp1=0;
                    break;
                }
                // else if((aage[mid-i-2]+piche[i]+i*a)<=t)
                // {
                //     cout<<"dfj";
                //     cout<<mid<<" ";
                //     ans=mid;
                //     low=mid+1;
                //     temp=0;
                //     // temp1=0;
                //     break;
                // }
            }
        }
        if(temp)
        {
            high=mid-1;
        }
    }
    cout<<ans;
return 0;
} 
