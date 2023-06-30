#include<stdio.h>// preemptive priority scheduling
void main()
{
  int sum=0,s,n,i,t,c1[10],a[10],b[10],w[10],p[i],index=0;
  float avgwt=0.0;
  printf("\nEnter the no of process=");
  scanf("%d",&n);
  printf("\nEnter the Arrival time, Priority and Burst time of (%d) processes=",n);
  for(i=0;i<n;i++)
  { scanf("%d",&a[i]);scanf("%d",&p[i]);
   scanf("%d",&b[i]);sum=sum+b[i];
c1[i]=0;
      }
  s=32000;
  for(t=0;t<sum;t++)
  {
  for(i=0;i<n;i++)
  {
  if(p[i]<s && b[i]>0 && a[i]<=t)
  { s=p[i];index=i;
  }}
  b[index]=b[index]-1;
  c1[index]=c1[index]+1;
  s=p[index];
    if (b[index]==0)
    {
    s=32765;p[index]=s;
    w[index]=(t)-(c1[index]-1)-a[index]; avgwt+=w[index];
    }
    }
  printf("\nWaiting time of processes=\n");
    for(i=0;i<n;i++){ printf("P[%d] = %d\n",i,w[i]);}
printf("\nWt = %f",avgwt/n);
      }
