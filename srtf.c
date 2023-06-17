#include<stdio.h>
void main(){
    int n,time=0,min_br,time_process_count=0;
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
        time_process_count=time_process_count+p[2][i];
        p[3][i]=p[2][i];
        p[0][i]=i+1;
        p[5][i]=1;
    }

    int time_arr[100];
    int temp;
    min_br=p[3][0];
    int time_process_count_copy=time_process_count;

    
    while(time_process_count!=0){
        for(int x=0;x<n;x++){
            if(min_br>p[3][x] && p[5][x]==1 && time>=p[1][x] && p[3][x]!=0){
                min_br=p[3][x];
            }
        }

        for(int x=0;x<n;x++){
            if(min_br==p[3][x] && time>=p[1][x] && p[3][x]>0){
                time_arr[time]=p[0][x];
                p[3][x]=p[3][x]-1;
                time++;
                time_process_count--;
                break;
            }
        }
        min_br++;
    }
    for(int i=0;i<time;i++){
        printf("%d ",time_arr[i]);
    }

    //calculating waiting time
    int process_count=0,y;
    for(int x=0;x<n;x++){
        process_count=0;
        for(y=time_process_count_copy-1;y>=0;y--){
            if(x+1==time_arr[y]){
                if(time_arr[y]==time_arr[y-1]){
                    continue;
                }
                for(int z=y-1;z>=0;z--){
                    if(time_arr[z]==x+1){
                        process_count++;
                    }
                }
                break;
            }
            
        }
        p[3][x]=y-process_count-p[1][x];
        //calculating turnarround time
        p[4][x]=p[2][x]+p[3][x];
    }
    
    printf("\nProcess ID   Arrival time   Burst time   Waiting time   Turnaround time\n");
    for(int i=0;i<n;i++){
        printf("P %d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[0][i],p[1][i],p[2][i],p[3][i],p[4][i]);

    }
}
