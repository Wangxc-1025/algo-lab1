#include <stdio.h>

long long lfg(double x);

int main()
{
	double x;
	scanf("%lf", &x);
	printf("%lld\n", lfg(x));   
	return 0;
}

long long lfg(double x)
{
	int neg = 0;
	long long ans = 0;          
	
	if (x == 0) return 0;       
	
	if (x < 0) { neg = 1; x = -x; }
	
	long long low = 0;
	long long high = (long long)x + 1;
	while (low <= high)         
	{
		long long mid = low + (high - low) / 2;
		long long cube = mid * mid * mid;
		if ((double)cube <= x)
		{
			ans = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	
	return neg ? -ans : ans;
}

