#include<stdio.h>
int abs(int a)
{
    return (a>0)?a:-a;
}
int main()
{
    int queue[20], n, i, j, head, seek=0, diff, max, min, pos, temp, queue1[20], queue2[20], temp1=0, temp2=0;
    float avg;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    printf("Enter the queue elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&queue[i]);
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    queue[n]=head;
    n=n+1;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(queue[i]>queue[j])
            {
                temp=queue[i];
                queue[i]=queue[j];
                queue[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(queue[i]==head)
        {
            pos=i;
            break;
        }
    }
    min=queue[0];
    max=queue[n-1];
    for(i=pos;i>=1;i--)
    {
        queue1[temp1]=queue[i-1];
        temp1++;
    }
    for(i=pos;i<n-1;i++)
    {
        queue2[temp2]=queue[i+1];
        temp2++;
    }
    printf("Disk head movement:\n");
    for(i=0;i<temp1;i++)
    {
        diff=abs(queue1[i]-head);
        seek+=diff;
        head=queue1[i];
        printf("Disk head moves to %d with seek %d\n", head, diff);
    }
    printf("Disk head moves to %d with seek %d\n", min, abs(min-head));
    seek+=abs(min-head);
    head=min;
    for(i=0;i<temp2;i++)
    {
        diff=abs(queue2[i]-head);
        seek+=diff;
        head=queue2[i];
        printf("Disk head moves to %d with seek %d\n", head, diff);
    }
    printf("\nTotal seek time = %d\n", seek);
    avg=seek/(float)(n-1);
    return 0;
}
