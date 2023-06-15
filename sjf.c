#include<stdio.h>
void main(){
    int n,min_br,time=0;
    printf("Enter the number of process :");
    scanf("%d",&n);

    int p[6][n];
    printf("Enter the arrival time :\n");
    for(int i=0;i<n;i++){
        printf("%d:",i+1);
        scanf("%d",&p[1][i]);
    }
    printf("Enter the burst time :\n");
    for(int i=0;i<n;i++){
        printf("%d:",i+1);
        scanf("%d",&p[2][i]);
        p[0][i]=i+1;
        p[5][i]=1;
    }

    min_br=p[2][0];
    for(int i=0;i<n+n;i++){
        
        for(int j=0;j<n;j++){
            if(p[2][j]<min_br && p[5][j]==1 && time>=p[1][j]){
                min_br=p[2][j];
            }
        }

        for(int j=0;j<n;j++){
            if(min_br==p[2][j] && time>=p[1][j] && p[5][j]==1){
                p[3][j]=time-p[1][j];
                time=time+p[2][j];
                p[5][j]=0;
                p[4][j]=p[3][j]+p[2][j];
                break;
            }
            
        }
        min_br++;
    }
    printf("\nProcess ID   Arrival time   Burst time   Waiting time   Turnaround time\n");
    for(int i=0;i<n;i++){
        printf("P %d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[0][i],p[1][i],p[2][i],p[3][i],p[4][i]);

    }
}