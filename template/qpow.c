#include <stdio.h>

long long qpow(long long base,long long power);
long long recur_qpow(long long base,long long power,long long fact);

int main(){
	long long base,power;
	scanf("%lld %lld",&base,&power);
	printf("%lld %lld\n",qpow(base,power),recur_qpow(base,power,1));
}

long long qpow(long long base,long long power){
	long long fact = 1;
	while(power != 1){
		if(power % 2 == 1)
			fact *= base;
		base *= base;
		power /= 2;
	}
	return base * fact;
}

long long recur_qpow(long long base,long long power,long long fact){
	return power == 1 ? base * fact : power % 2 ? recur_qpow(base * base,power / 2,fact * base) : recur_qpow(base * base,power / 2,fact);
}

