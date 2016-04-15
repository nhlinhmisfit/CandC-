/*
	완전 이진 트리
		모든 부모 노드는 2개의 자식 노드를 갖는다.
		왼쪽에서 오른쪽으로 생성되어 간다.

	Heap 구조는 완전 이진 트리의 일종
		단, 마지막 노드는 하나 자식을 가질 수도 있다.
		조건1 : 부모는 자식보다 작다.
		조건2 : 부모는 자식보다 크다.

	힙의 생성 (상향 이동)
		배열에 저장된 요소들을 힙 구조로 다룬다.
		root 노드를 배열 요소 [1]로 하는 경우
		왼쪽 자식 노드 기준
			오른쪽 노드 : right_child = left_child+1;
			부모 노드 : parent = left_child/2

		부모 노드 기준
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
		/* 힙의 마지막 요소에 저장 */
        left_child=n;
        parent=left_child/2;	/* 부모 노드의 위치 */
		current=left_child;	
        while (current>=2 && heap[parent]>heap[current]) {/* 상향 이동 */
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
