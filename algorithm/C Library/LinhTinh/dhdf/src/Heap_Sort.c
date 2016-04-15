/*
 * --------------------
 *      �� ���� #1    *
 * --------------------
 */

#include <stdio.h>

void swap(int *,int *);

int main(void)
{
    static int heap[100];
    int n,i,s,p,m;

    n=1;                              /* �ʱ� �� ���� */
    while (scanf("%d",&heap[n])!=EOF) {
        s=n;p=s/2;
        while (s>=2 && heap[p]>heap[s]) {
            swap(&heap[p],&heap[s]);
            s=p;p=s/2;
        }
        n++;
    }
    n--;                /* ������ ���� */
    m=n;                /* n�� ���� */
    while (n>1) {
        swap(&heap[1],&heap[n]);
        n--;               /* Ʈ���� ������ ��带 �и��Ѵ�. */

        p=1; s=2*p;
        while (s<=n) {
            /* ���ʰ� ������ ��� �߿� ���� ��� */
            if (s<n && heap[s+1]<heap[s])
                s++;
            if (heap[p]<=heap[s])
                break;
            swap(&heap[p],&heap[s]);
            /* �θ���� �ڽĳ���� ��ġ ���� */
            p=s; s=2*p;
        }
    }
    for (i=1;i<=m;i++)
        printf("%d ",heap[i]);

    printf("\n");

    return 0;
}

void swap(int *a,int *b)
{
    int w;
    w=*a; *a=*b; *b=w;
}
