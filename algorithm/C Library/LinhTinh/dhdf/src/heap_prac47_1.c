/*
 * ---------------------------------
 *      ���� ���� (���� �̵�)      *
 * ---------------------------------
 */

#include <stdio.h>

void swap(int *,int *);

int main(void)
{
    static int heap[100];
    int i,n,p,s;

    n=1;                     /* �����͸� Ʈ���� �Ҵ� */
    while (scanf("%d",&heap[n])!=EOF)
        n++;
    n--;                     /* ������ ���� */
    for (i=n/2;i>=1;i--) {
        p=i;                 /* �θ� ����� ��ġ */
        s=2*p;               /* ���� �ڽ� ����� ��ġ */
        while (s<=n) {
            if (s<n && heap[s+1]<heap[s])    /* ����, ������ �ڽ� ��� �� ���� �� */
                s++;
            if (heap[p]<=heap[s])
                break;
            swap(&heap[p],&heap[s]);
            p=s; s=2*p;                      /* �θ�, �ڽ� ����� ��ġ ���� */
        }
    }
    for (i=1;i<=n;i++)
        printf("%d ",heap[i]);

	printf("\n");
	return 0;
}

void swap(int *a,int *b)
{
    int w;
    w=*a; *a=*b; *b=w;
}

