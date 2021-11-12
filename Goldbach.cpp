#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void goldbach(long long g);
int primo (long long p,int n);
long long modulo(long long base, long long exponent, long long mod);
long long mulmod(long long a, long long b, long long mod);

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
    int n = 5;
    for (long long  j = g-i; j > 2; j--)
    {
        if(primo(i,n) == 1 && primo(j,n) == 1)
        {
            printf("La conjetura es cierta para %lld\n",g);
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

int primo(long long p,int n)
{
 
    int i;
    long long s;
    if (p < 2)
    {
        return 0;
    }
    if (p != 2 && p % 2==0)
    {
        return 0;
    }
     s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (i = 0; i < n; i++)
    {
        long long a = rand() % (p - 1) + 1, temp = s;
        long long mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return 0;
        }
    }
    return 1;
}

long long modulo(long long base, long long exponent, long long mod)
{
    long long x = 1;
    long long y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}
 
long long mulmod(long long a, long long b, long long mod)
{
    long long x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {    
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}



