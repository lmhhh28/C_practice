#include <stdio.h>
int main(){
    int n,a;scanf("%d %d",&n,&a);
    int count = 0;
    for(int i = 1;i <= n;i ++){
        int temp = i;
        while(temp > 0){
            if(temp % 10 == a){
                count ++;
            }
            temp /= 10;
        }
    }
    printf("%d",count);
}