#include<stdio.h>
#include<stdlib.h>
#define N 8

typedef struct List{
    int data;
    struct List *next;
}SL;
SL *creatlist(char *);
void outlist(SL *);
int fun(SL *h,char ch)
{
    SL *p;
    int n=0;
    p=h->next;
    while(p!=NULL)
    {
        n++;
        if(p->data==ch)
            return n;
        else
            p=p->next;
    }
    return 0;
}

int main()
{
    SL *head;
    int k;
    char ch;
    char a[N]={'m','p','g','a','w','x','r','d'};
    head=creatlist(a);
    outlist(head);
    printf("Enter a letter:");
    scanf("%c",&ch);
    k=fun(head,ch);
    if(k==0)
        printf("\nNot found\n");
    else
        printf("The number is:%d\n",k);
    return 0;
}
SL *creatlist(char *a)
{
    SL *h,*p,*q;
    int i;
    h=p=(SL *)malloc(sizeof(SL));
    for(i=0;i<N;i++)
    {
        q=(SL *)malloc(sizeof(SL));
        q->data=a[i];
        p->next=q;
        p=q;
    }
    p->next=0;
    return h;
}
void outlist(SL *h)
{
    SL *p;
    p=h->next;
    if(p==NULL)
        printf("\nThe list is NULL\n");
    else
    {
        printf("\nHead");
        do
        {
            printf("->%c",p->data);
            p=p->next;
        }while(p!=NULL);
        printf("->End\n");
    }
}
