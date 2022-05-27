#include<stdio.h>
#include<math.h>

int main()
{
        int AS;   // address space size
        float VS;  // virtual address 
        float PS=0;    //physical Address
        int base;
        printf("enter size of address space : ");
        scanf("%d",&AS);
        printf("enter virtual address size in bytes : ");
        scanf("%e",&VS);
        printf("enter base size in KB : ");
        scanf("%d",&base);
        VS=VS/1024.0;
        if(VS>AS)
        	printf("address out of bound\n");
        else
		{
        	PS=VS+base;
        	printf("\nphysical address : %f",PS);
        }
return 0;
}
