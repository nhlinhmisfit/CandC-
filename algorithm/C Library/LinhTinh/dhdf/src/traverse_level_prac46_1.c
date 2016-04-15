/*
 * ----------------------------------------
 *      ���� Ž�� Ʈ���� ������ ��ȸ      *
 * ----------------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

struct tnode {
    struct tnode *left;     /* ���� �κ� Ʈ���� ����Ű�� ������ */
    char name[12];          /* �̸� */
    struct tnode *right;    /* ������ �κ� Ʈ���� ����Ű�� ������ */
};

struct tnode *talloc(void);
struct tnode *gentree(struct tnode *,char *);
void treewalk(struct tnode *);
int	RandomString(char *dest, int max){
	int i;
	for(i=0;i<rand()%max;i++){
		dest[i] = rand()%26 + 'a';
	}
	dest[i] = 0;
	return 0;
}
int main(void)
{
    char dat[12];
    struct tnode *root;
	int i;

	root=NULL;
//    while (scanf("%s",dat)!=EOF) {
	for(i=0;i<10;i++){
		RandomString(dat, 12);
        root=gentree(root,dat);
    }
    treewalk(root);

	return 0;
}

void treewalk(struct tnode *p)  /* ���̿� ���� ��ȸ */
{
    struct connect {            /* ������踦 ��Ÿ���� ����ü */
        struct tnode *node;     /* �ڽ� ��� */
        char *parent;           /* �θ� ����� �̸� */
        char direct;            /* ���� �ڽ� ������� ������ �ڽ� ������� ǥ�� */
    } q[128],w[128];
    int i,child,n,level;

    child=1; level=0;           /* �ʱⰪ */
    q[0].node=p; q[0].parent="root"; q[0].direct=' ';
    do {
        n=0;
        printf("level %d :\n",level);
        for (i=0;i<child;i++) {
            printf("%12s->%c:%12s\n",q[i].parent,q[i].direct,q[i].node->name);
            /* �ٷ� �Ʒ� ������ �ڽ� ��带 ����Ű�� �����͸� ���ÿ� ���� */
            if (q[i].node->left!=NULL) {
                w[n].parent=q[i].node->name;
                w[n].direct='l';
                w[n].node=q[i].node->left;
                n++;
            }
            if (q[i].node->right!=NULL) {
                w[n].parent=q[i].node->name;
                w[n].direct='r';
                w[n].node=q[i].node->right;
                n++;
            }
        }
        child=n;            /* �ٷ� �Ʒ� ������ �ڽ� ��� �� */
        for (i=0;i<child;i++)
            q[i]=w[i];
        level++;
    } while (child!=0);
}

struct tnode *gentree(struct tnode *p,char *w) 
	/* Ʈ���� �����ϴ� ��� �Լ� */
{
    if (p==NULL) {
        p=talloc();
        strcpy(p->name,w);
        p->left=p->right=NULL;
    }
    else if (strcmp(w,p->name)<0)
        p->left=gentree(p->left,w);
    else
        p->right=gentree(p->right,w);
    return p;
}

struct tnode *talloc(void)     /* �޸� �Ҵ� */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

