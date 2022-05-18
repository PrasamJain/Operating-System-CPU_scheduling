#include<stdio.h>
#include<math.h>

int bit = 14;
int binaryNum[14];

void decToBinary(int n)
{    
    for(int i=0;i<bit;i++)
    	binaryNum[i] = 0;
 

    int i = bit-1;
    while (n > 0) 
	{
        binaryNum[i] = n % 2;
        n = n / 2;
        i--;
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
	int code = 32*1024;      //In Bytes
	int heap = 34*1024;
	int stack = 28*1024;
	
	int VA,PA,offset;
	
	long long dec = 0;
	
	printf("Enter the Virtual address(in Bytes) : ");
	scanf("%d" , &VA);
	decToBinary(VA);
    
    for(int i=2;i<bit;i++)        //convert remaining 12 bit into decimal 
    {
   		dec = (dec*10) + binaryNum[i]; 
	}
 	offset = BinaryToDec(dec);
        
    if(binaryNum[0]==0 && binaryNum[1] == 0)
    	PA = offset + code;

	else if(binaryNum[0]==0 && binaryNum[1] == 1)
		PA = offset + heap;

	else if(binaryNum[0]==1 && binaryNum[1] == 1)
	{
		if(offset > 0)
		{
			offset = offset-(4*1024);
			PA = offset + stack;
		}
		else if(offset == 0)
			PA = stack;
	}

	else
		printf("Address not exist in Physical memory!!");
		
	printf("\nPhysical Address : %d Bytes OR %f KB",PA,PA/1024.0);
	
	return 0;
}

