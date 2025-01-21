#include <stdio.h>
int cir(int n, int k);
int main(){
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    printf("%d\n",cir(n,m));
}
int cir(int n,int m)
{
	int p=0;
	for(int i=2;i<=n;i++)
	{
		p=(p+m)%i;
	}
	return p+1;
}