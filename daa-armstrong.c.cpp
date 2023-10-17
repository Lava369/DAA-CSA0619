#include<stdio.h>
#include<math.h>
int main()
{
	int originalnum, remainder , result=0, num;
	printf("enter the number to be checked:" );
	scanf("%d", &originalnum);
	num = originalnum;
	while(num > 0)
	{
		remainder = num%10;
		result = result + remainder*remainder*remainder;
		num /= 10;
	}
	
	if(result == originalnum)
	{
		printf("the number  is an armstrong number");
	}
	else{
		printf("the number  is not an armstrong number");
	}
}
