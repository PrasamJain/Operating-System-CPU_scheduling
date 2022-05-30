#include <stdio.h>

int main()
{
    int i = 0, j = 0, count = 0, size, n, str[100], flag = 1,x=0;
    printf("Enter the no. of frames:");
    scanf("%d", &n);
    int frame[n];
    int str[n];
    printf("Enter the reference string and add -1 to end the string :");
    while (1)
	{
        scanf("%d", &str[i]);
        if (str[i] == -1)
            break;
        i++;
    }
    size = i;
    
    for (j = 0; j < n; j++)
    {
    	frame[j] = 0;    //Initially all frames are NULL
    	str[j] = 0;
	}
    
	for (i = 0; i < size; i++)
    {
        flag = 1;
        for (j = 0; j < n; j++)
            if (frame[j] == str[i])
            {
                printf("HIT\n");
                flag = 0;
                str[j] = j
                break;
            }
        if (flag == 1)
        {
            
            
            for (j = 0; j < n; j++)
            {
                printf("  %d", frame[j]);
                if (frame[j] == str[i])
                    printf("*");
            }
            printf("\n\n");
            count++;  //calculate faults.
        }
    }
    printf("\nTotal no. of page faults : %d", count);
}
