#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define MAX 300000
bool prime[MAX];
int eratosthenes(int num)
{
   if (num == 1)
      return 0;

   if (num == 2 || num == 3)
      return 1;

   for (int i = 2; i < sqrt(num) + 1; i++)
   {
      if (num % i == 0 && num != i)
         return 0;
   }
   return 1;
}

int main()
{
    for(int i=1;i<=MAX;i++){
        if(eratosthenes(i)){
            prime[i] = true;
        }
    }
    while(1){
        int c;
        scanf("%d",&c);
        if(c == 0) break;
        int result =0;
        for(int i=c+1;i<=2*c;i++){
            if(prime[i]) result++;
        }
        printf("%d\n",result);
    }
}