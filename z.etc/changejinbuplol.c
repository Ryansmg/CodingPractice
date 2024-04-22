#include <stdio.h>
#include <stdlib.h>
#define l long long

struct _ptrvalpair {
    void *preptr; l val;
} typedef pv;
struct _pvarr {
    pv *block;
} typedef pvarr;
struct _pvb {
    void *preblock;
    pvarr *block;
} typedef pvblock;
struct _ast {
    pvblock *blc;
    pv *last;
    l cursize;
    l curind;
} typedef stack;
int empty(stack *ptr) {
    return (*ptr).last == NULL;
}
void push(stack *ptr, l v)
{
    if((*ptr).curind == (*ptr).cursize-1) {
        void *pre = (*ptr).last;
        pv *prebl;
        if(pre == NULL) {
            prebl = NULL;
        } else prebl = (pv*)(*ptr).blc;
        ((*ptr).cursize) = ((*ptr).cursize)==0 ? 1 : ((*ptr).cursize)<<1;
        pvarr *arr = (pvarr*) malloc(sizeof(pv*));
        (*arr).block = (pv*) malloc(sizeof(pv) * ((*ptr).cursize));
        pvblock *tblc = (pvblock*)malloc(sizeof(pvblock));
        (*tblc).preblock = prebl; (*tblc).block = arr;
        (*ptr).blc = tblc;
        (*ptr).last = (*(*(*ptr).blc).block).block;
        (*(*ptr).last).val = v;
        (*(*ptr).last).preptr = pre;
        (*ptr).curind = 0;
    } else {
        (*ptr).curind++;
        (*ptr).last++;
        (*(*ptr).last).preptr = ((*ptr).last-1);
        (*(*ptr).last).val = v;
    }
}
l top(stack *ptr) {
    return (*(*ptr).last).val;
}
void pop(stack *ptr) {
    if((*ptr).curind == 0) {
        (*ptr).last = (pv*)(*((*ptr).last)).preptr;
        (*ptr).curind = (*ptr).cursize/2-1;
        pvblock *preb = (pvblock*) (*(*ptr).blc).preblock;
        free((*(*(*ptr).blc).block).block);
        free((*(*ptr).blc).block);
        free((*ptr).blc);
        ((*ptr).blc) = (pvblock*)preb;
        (*ptr).cursize>>=1;
    } else {
        (*ptr).curind--;
        (*ptr).last = (pv*)(*((*ptr).last)).preptr;
    }
}

int main() {
    l tar, in;
    stack st = {0, 0, 0, -1};
    scanf("%lld %lld", &tar, &in);
    tar *= in;
    while(tar /= in) 
        push(&st, (tar%in)<=9 ? '0'+(tar%in) : 'a'+(tar%in)-10);
    
    while(!empty(&st)) {
        printf("%c", top(&st));
        pop(&st);
    }
}