#include <stdio.h>

void BestFit(int b[],int str[],int n,int m){
// b array stores block size str stores process size n stores no of blocks m stores no of process
    int res[m];
    int occupied[n];
    for(int i=0;i<m;i++){
        res[i]=-1;
    }
    for(int i=0;i<n;i++){
        occupied[i]=0;
    }
    
   
   for(int i=0;i<n;i++){
       int indexplaced=-1;
       for(int j=0;j<m;j++){
           if(b[j]>=str[i] && !occupied[j]){
               if(indexplaced==-1){
                   indexplaced=j;
               }
               else if(b[indexplaced]<b[j]){
                   indexplaced=j;
               }
           }
       }
       if(indexplaced!=-1){
         res[i]=indexplaced;
         occupied[indexplaced]=1;
         b[indexplaced]=b[indexplaced]-str[i];
        }
   }
   
   
   
   printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i=0;i<n;i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, str[i]);
        if (res[i] != -1)
            printf("%d\n",res[i] + 1);
        else
            printf("Not Allocated\n");
    }
   
   printf("\nProcess no\tProcess Size\tBlock no\n");
   for(int i=0;i<n;i++){
       printf("%d \t\t\t %d \t\t\t",i+1,str[i]);
       if(res[i]!=-1){
           printf("%d\n",res[i]+1);
       }
       else{
           printf("Not Allocated\n");
       }
   }
}
int main()
{
    int n;
    printf("Enter no of blocks : ");
    scanf("%d",&n);
    
    int m;
    printf("Enter no of process : ");
    scanf("%d",&m);
    
    int b[n];
    int str[m];
    printf("Enter size of blocks : ");
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    printf("Enter size of process : ");
    for(int i=0;i<m;i++){
        scanf("%d",&str[i]);
    }
    
    
    BestFit(b,str,n,m);
}
