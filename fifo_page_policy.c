#include <stdio.h>
int main(){
    int i = 0, j = 0, count = 0, size, n, str[100], flag = 1;
    printf("Enter the no. of frames:");
    scanf("%d", &n);
    int frame[n];
    printf("Enter the reference string and add -1 to end the string :");
    while (1){
        scanf("%d", &str[i]);
        if (str[i] == -1)
            break;
        i++;
    }
    size = i;
    for (j = 0; j < n; j++)
        frame[j] = -1;
    for (i = 0; i < size; i++)
    {
        flag = 1;
        for (j = 0; j < n; j++)
            if (frame[j] == str[i])
            {
                printf("Hit\n");
                flag = 0;
                break;
            }
        if (flag == 1)
        {
            int temp = frame[n-1];
            frame[n-1] = str[i];
            for(int q=1;q<n-1;q++){
                frame[q-1] = frame[q];                
            }
            frame[n-2] = temp;
            count++;
            for (j = 0; j < n; j++)
            {
                printf("\nPage %d:%d", j + 1, frame[j]);
                if (frame[j] == str[i])
                    printf("*");
            }
            printf("\n\n");
        }
    }
    printf("\nTotal no page faults %d", count);
}