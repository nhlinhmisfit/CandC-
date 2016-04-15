/*
	���� ���� Ʈ��
		��� �θ� ���� 2���� �ڽ� ��带 ���´�.
		���ʿ��� ���������� �����Ǿ� ����.

	Heap ������ ���� ���� Ʈ���� ����
		��, ������ ���� �ϳ� �ڽ��� ���� ���� �ִ�.
		����1 : �θ�� �ڽĺ��� �۴�.
		����2 : �θ�� �ڽĺ��� ũ��.

	���� ���� (���� �̵�)
		�迭�� ����� ��ҵ��� �� ������ �ٷ��.
		root ��带 �迭 ��� [1]�� �ϴ� ���
		���� �ڽ� ��� ����
			������ ��� : right_child = left_child+1;
			�θ� ��� : parent = left_child/2

		�θ� ��� ����
			left_child = 2*parent;
			right_child= 2*parent+1;
 */

#include <stdio.h>
void	swap(int *a, int *b){
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
int main(void)
{
    int heap[100];
    int n;
	int parent;
	int left_child, current;
	int i;
    n=1;
	while (printf("[%d] data > ", n ), scanf("%d",&heap[n])!=EOF) {
		/* ���� ������ ��ҿ� ���� */
        left_child=n;
        parent=left_child/2;	/* �θ� ����� ��ġ */
		current=left_child;	
        while (current>=2 && heap[parent]>heap[current]) {/* ���� �̵� */
            swap(heap+parent,heap+current);
            current=parent;
			parent=current/2;
        }
        n++;
     }
     for (i=1;i<n;i++)
        printf("%d ",heap[i]);

     printf("\n");
     return 0;
}
