#include <stdio.h>

#define MAX 100
#define EMPTY -1

int tree[MAX];

/* Inorder Traversal */
void inorder(int i)
{
    if (i >= MAX || tree[i] == EMPTY)
        return;

    inorder(2*i + 1);
    printf("%d ", tree[i]);
    inorder(2*i + 2);
}

/* Preorder Traversal */
void preorder(int i)
{
    if (i >= MAX || tree[i] == EMPTY)
        return;

    printf("%d ", tree[i]);
    preorder(2*i + 1);
    preorder(2*i + 2);
}

/* Postorder Traversal */
void postorder(int i)
{
    if (i >= MAX || tree[i] == EMPTY)
        return;

    postorder(2*i + 1);
    postorder(2*i + 2);
    printf("%d ", tree[i]);
}

int main()
{
    int n, i;

    for (i = 0; i < MAX; i++)
        tree[i] = EMPTY;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter tree elements level-wise (-1 for no node):\n");
    for (i = 0; i < n; i++)
        scanf("%d", &tree[i]);

    printf("Inorder Traversal: ");
    inorder(0);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(0);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(0);
    printf("\n");

    return 0;
}
