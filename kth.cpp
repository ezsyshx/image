#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define in(x) x=read()
using namespace std;
inline int read()
{
	int num=0; char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) {num=num*10+ch-'0'; ch=getchar();}
	return num;
}
class subtask1
{
	#define maxN 5000
	public:
		void work(int n,int k)
		{
			int tot=0;
			for(register int i=1;i<=n;i++) in(a[i]),in(b[i]);
			for(register int i=1;i<=n;i++)
				for(register int j=1;j<=n;j++)
					c[++tot]=a[i]*b[j];
			sort(c+1,c+tot+1);
			printf("%d",c[tot-k+1]);
		}
	private:
		int a[maxN+1],b[maxN+1];
		long long c[maxN*maxN+10];
	#undef maxN
}s1;
class subtask2
{
	#define maxN 50000
	public:
		void work(int n,int k)
		{
			for(register int i=1;i<=n;i++) in(a[i]),in(b[i]);
			sort(a+1,a+n+1); sort(b+1,b+n+1);
			if(2*k<n*n)
			{
				priority_queue<long long>q;
				for(register int i=n;i>=1;i--)
					for(register int j=n;j>=1;j--)
					{
						q.push(a[i]*b[j]);
						if(q.size()>60000000)
						{
							for(register int i=1;i<k;i++) q.pop();
							printf("%d",q.top());
							return;
						}
					}
				for(register int i=1;i<k;i++) q.pop();
				printf("%d",q.top());
				return;
			}
			else
			{
				priority_queue<long long,deque<long long>,greater<long long> >q;
				k=n*n-k+1;
				for(register int i=1;i<=n;i++)
					for(register int j=1;j<=n;j++)
					{
						q.push(a[i]*b[j]);
						if(q.size()>60000000)
						{
							for(register int i=1;i<k;i++) q.pop();
							printf("%d",q.top());
							return;
						}
					}
				for(register int i=1;i<k;i++) q.pop();
				printf("%d",q.top());
				return;
			}
		}
	private:
		int a[maxN+1],b[maxN+1];
	#undef maxN
}s2;
int n,k;
int main()
{
	freopen("kth.in","r",stdin);
	freopen("kth.out","w",stdout);
	in(n); in(k);
	if(n<=5000) s1.work(n,k);
	else s2.work(n,k);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
