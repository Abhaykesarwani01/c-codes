#include<stdio.h>
void main(){
    int q,n,time=0,min_ar,time_process_count=0;
    printf("Enter the number of quanta :");
    scanf("%d",&q);
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

    int time_arr[100],stack[100];
    int stack_count=0,stack_out=0,temp;
    min_ar=p[1][0];
    int time_process_count_copy=time_process_count;

    for(int x=0;x<n;x++){
        if(min_ar>p[1][x] && p[5][x]==1){
            min_ar=p[1][x];
        }
    }

    for(int x=0;x<n;x++){
        if(min_ar==p[1][x]){
            p[5][x]=0;
            stack[stack_count]=p[0][x];
            stack_count++;
            break;
        }
    }

    printf("Gantt Chart :\n");

    while(time_process_count!=0){

        temp=stack[stack_out];
        for(int x=0;x<q;x++){
            if(p[3][temp-1]!=0){
                time_arr[time]=stack[stack_out];
                p[3][temp-1]=p[3][temp-1]-1;
                time++;
                time_process_count=time_process_count-1;
                printf("%d ",p[0][temp-1]);
            }
        }
        printf(" | ");
        for(int x=0;x<n;x++){
            if(time>=p[1][x] && p[5][x]==1){
                stack[stack_count]=p[0][x];
                p[5][x]=0;
                stack_count++;
            }
        }
        stack_out++;
        
        if(p[3][temp-1]!=0){
            stack[stack_count]=p[0][temp-1];
            stack_count++;
        }
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