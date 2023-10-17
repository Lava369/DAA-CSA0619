#include<stdio.h>
int factorial(int n);
int main()
{
	int n;
	printf("enter any number: ");
	scanf("%d", &n);
	printf("the factorial of %d is %d", n, factorial(n));
}
int factorial(int n){
     if(n>1){
     	return n*factorial(n-1);
	 }
	 else{
	 	return 1;
	 }
}
