#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void goldbach(long long g);
int primo (long long p);

int main(int argc, char** argv){
    long long number = 0;
        number = atof(argv[1]);
        if(number>2 && number%2==0){
            goldbach(number);
        }
        else{
            printf("El número debe ser par\n");
        }
    
    return 0;
}

void goldbach(long long  g){
    long long  i = 2;
    for (long long  j = g-i; j > 2; j--)
    {
        if(primo(i) == 1 && primo(j) == 1)
        {
            printf("La conjetura es cierta para %lld\n",g);
            /** Puede usar este bloque si quiere ver las sumas */
            /**
            printf("%lld + %lld\n",i,j);
            if(i>j)
            {
            break;
            }
            */
            break;
        }
        if(i == 2)
        {
        	i++;
        }else
        {
        	i+=2;
        }
        
    }
}

int primo(long long p)
{
    int flag = 1;
    for (int i = 2; i < p/2; i++)
    {
        if((p%i) == 0){
            return flag-1;
        }
    }
    return flag;
}
