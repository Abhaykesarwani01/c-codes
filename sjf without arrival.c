#include<stdio.h>
void main(){
    int n,min_br,time=0;
    printf("Enter the number of process :");
    scanf("%d",&n);

    int p[5][n];
    printf("Enter the burst time :\n");
    for(int i=0;i<n;i++){
        printf("%d:",i+1);
        scanf("%d",&p[1][i]);
        p[0][i]=i+1;
        p[4][i]=1;
    }

    min_br=p[1][0];
    for(int i=0;i<n+n;i++){
        
        for(int j=0;j<n;j++){
            if(p[1][j]<min_br && p[4][j]==1){
                min_br=p[1][j];
            }
        }

        for(int j=0;j<n;j++){
            if(min_br==p[1][j]){
                p[2][j]=time;
                time=time+p[1][j];
                p[4][j]=0;
                p[3][j]=p[2][j]+p[1][j];
            }
        }
        min_br++;
    }
    printf("\nProcess ID   Burst time   Waiting time   Turnaround time\n");
    for(int i=0;i<n;i++){
        printf("P %d\t\t%d\t\t%d\t\t%d\n",p[0][i],p[1][i],p[2][i],p[3][i]);

    }
}