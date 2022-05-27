//Paging In Operating System.

#include<stdio.h>
#include<math.h>

int bit = 0;
int binaryNum[20];

void decToBinary(int n)
{    
    
    while (n > 0) 
	{
        binaryNum[bit] = n % 2;
        n = n / 2;
        bit++;
    }
}

int BinaryToDec(long long num) 
{
	int decimal_num = 0, base = 1, rem;  
    while ( num > 0)  
    {  
        rem = num % 10; 
        decimal_num = decimal_num + rem * base;  
        num = num / 10;
        base = base * 2;  
    }  

    return decimal_num;
}


int main()
{	
	int VA;
	int PA;
	int offset;
	int LA;
	int PS;
	int m,n,k,pno;
	int p = 0;

	
	long long dec = 0;
	
	printf("Enter the Logical address : ");
	scanf("%d" , &LA);
	m = log2(LA) + 10;
	
	printf("Enter the Page Size : ");
	scanf("%d" , &PS);
	n = log2(PS) + 10;
	
	pno = m-n;
	
	
	printf("Enter the Page table size : ");
	scanf("%d",&k);
	
	int ptable[k];       //Declare page table.
	
	printf("Enter the Page Table Entry with base addresses\n");
	for(int i=0;i<k;i++)
	{
		printf("P %d : ",i);
		scanf("%d" ,&ptable[i]);
	}
		
	
	printf("Enter the Virtual address(in Bytes) : ");
	scanf("%d" , &VA);
	decToBinary(VA);
    
    for(int i=bit-pno-1;i>=0;i--)          //convert remaining 12 bit into decimal 
    {
   		dec = (dec*10) + binaryNum[i]; 
	}
	
 	offset = BinaryToDec(dec);            //to find Offset.
 	
 	for(int i=bit-1;i>=bit-pno;i--)
 	{
 		p = (p*10) + binaryNum[i];
	}
 	pno = BinaryToDec(p);                 //to find page number.
 	
 	PA = ptable[pno]*PS + offset/1024;
		
	printf("\nPhysical Address : %d KB",PA);
	
	return 0;
}

