// FIFO Page Replacemnt algorithm
#include <stdio.h>
void oldest(int *,int, int);
int search(int *,int,int);
int main() {
    // Write C code here
    printf("FIFO Page Replacemnt algorithm");
    int refstr[50],i,n,f,frame[10],j,flag=0,pf=0;
    printf("\nenter the length of reference string:-");
    scanf("%d",&n);
    printf("\nenter the reference string:-");
    for (i=0;i<n;i++)
    {scanf("%d",&refstr[i]); }
    printf("\nenter the frame size:-");
    scanf("%d",&f);
    pf=f;
    for(j=0;j<f;j++)
    {
    frame[j]=refstr[j]; flag++;   
    }
    printf("\nInitial frames status----");
    for (i=0;i<f;i++)
    {printf("%d\t",frame[i]); }
    int k=0;
    for(i=flag;i<n;i++)
    {  
        k=search(frame,f,refstr[i]); 
        if (k>0) continue;
        else
        {pf++;printf("\nPage Fault Occured=%d",pf);
        oldest(frame,f,refstr[i]);}
    }
    printf("\nTotal Page Fault=%d",pf);
    printf("\n\nFinal frames status----");
    for (i=0;i<f;i++)
    {printf("%d\t",frame[i]); }
    return 0;
}
void oldest(int a[],int n,int x)
{
    int old=a[0],i;
    printf("\noldest page=%d\n",a[0]);
    for(i=0;i<n-1;i++) {
    a[i]=a[i+1];    }
    a[i]=x;
}
int search(int a[],int n,int search)
{ int c;
    for (c = 0; c < n; c++)
  {
    if (a[c] == search)    /* If required element is found */
    {
      return c+1;
      break;
    }
  }
  if (c == n)
    return 0;
  }