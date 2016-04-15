/*
 * --------------------
 *      �� ���� #3    *
 * --------------------
 */

#include <stdio.h>

void swap(int *,int *);
void shiftdown(int,int,int *);

int main(void)
{
    static int heap[100];
    int i,n,m;

    n=1;                        /* Ʈ���� �����͸� �Ҵ��Ѵ� */
    while (scanf("%d",&heap[n])!=EOF)
        n++;
    n--;                        /* ������ ���� */
    for (i=n/2;i>=1;i--)        /* �ʱ� �� ���� */
        shiftdown(i,n,heap);
    m=n;                        /* n�� ���� */
    while (n>1) {
        swap(&heap[1],&heap[n]);
        n--;                        /* Ʈ���� ������ ��� �и� */
        shiftdown(1,n,heap);
    }
    for (i=1;i<=m;i++)
        printf("%d ",heap[i]);
    printf("\n");

	return 0;
}

void shiftdown(int p,int n,int heap[])   /* ���� �̵� */
{
    int s;
    s=2*p;
    while (s<=n) {
        if( s<n && heap[s+1]>heap[s])    /* ���ʰ� ������ ��� �߿� ���� ��� */
            s++;
        if (heap[p]>=heap[s])
            break;
        swap(&heap[p],&heap[s]);
        p=s; s=2*p;                      /* �θ� ���� �ڽ� ����� ��ġ ���� */
    }
}

void swap(int *a,int *b)
{
    int w;
    w=*a; *a=*b; *b=w;
}

