#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxN=60000;
ll a[maxN+1],b[maxN+1];
int n,k;
bool check(ll t)
{
    int tot=0;
    for(register int i=1;i<=n;i++)
    {
        int pos=n;
        while(pos && a[i]*b[pos]>t) pos--;
        tot+=pos;
    }
    return tot<k;
}
int main()
{
    freopen("kth.in","r",stdin);
    freopen("kth.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(register int i=1;i<=n;i++) scanf("%lld%lld",&a[i],&b[i]);
    sort(a+1,a+n+1); sort(b+1,b+n+1); k=n*n-k+1;
    ll l=a[1]*b[1],r=a[n]*b[n];
    while(l<r)
    {
        ll mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    printf("%lld",r);
    fclose(stdin);
    fclose(stdout);
    return 0;
}