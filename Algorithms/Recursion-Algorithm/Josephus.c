#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
    int position;
    struct person *next;
} person;

int findWinner(int n, int k)
{
    int i, count;
    person *p, *q, *r;

    p = (person *)malloc(sizeof(person));
    p->position = 1;
    p->next = p;
    q = p;

    for (i = 2; i <= n; i++)
    {
        r = (person *)malloc(sizeof(person));
        r->position = i;
        r->next = p;
        q->next = r;
        q = r;
    }

    while (p->next != p)
    {
        q = p;
        r = q;
        for (count = 1; count < k; count++)
        {
            r = q;
            q = q->next;
        }
        r->next = q->next;
        p = r->next;
        q->next = NULL;
        free(q);
        q = NULL;
    }

    return p->position;
}

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int w = findWinner(n, k);
    printf("%d", w);
    return 0;
}
