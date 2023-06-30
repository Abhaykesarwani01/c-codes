// LRU Page Replacemnt algorithm
#include <stdio.h>
void least(int *,int *,int,int);
int search(int *,int,int);
int main() {
    printf("LRU Page Replacemnt algorithm*******");
    int refstr[50],i,n,f,frame[10],j,pf=0,c[10];
    printf("\nenter the length of reference string:-");
    scanf("%d",&n);
    printf("\nenter the reference string:-");
    for (i=0;i<n;i++)
    {scanf("%d",&refstr[i]); }
    printf("\nenter the frame size:-");
    scanf("%d",&f);
    pf=0; // nos. of page fault 
    for(j=0;j<f;j++)
    {
    frame[j]=-1; // initial all frames are EMPTY
    c[j]=0;// initial all frame counts are 0
    }
    printf("\nInitial frames status---->");
    for (i=0;i<f;i++)
    {printf("%d\t",frame[i]); }
    int k=0;
    for(i=0;i<n;i++)  // consider each reference page
    {   for (j=0;j<f;j++) c[j]=c[j]+1;
        k=search(frame,f,refstr[i]); 
        if (k>0) {c[k-1]=-1;
        printf("\nPage HIT...%d in Main Memory....",refstr[i]);
        continue;}
        else
        {pf++;
        printf("\nPage Fault (%d) Occured at %d",pf,refstr[i]);
        least(frame,c,f,refstr[i]);}
    }
    printf("\n\nTotal Page Fault occured=%d",pf);
    printf("\nFinal frames status---->");
    for (i=0;i<f;i++)
    {printf("%d\t",frame[i]); }
    return 0;
}
void least(int a[],int c1[],int n,int curpage)
{   int i,c,loc=0,lru;
    for (c = 1; c < n; c++){
    if (c1[c] > c1[loc] )
      loc = c;}
        printf("\nLeast recently used page=%d\n",a[loc]);
    a[loc]=curpage; c1[loc]=-1;
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
  