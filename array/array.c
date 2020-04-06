#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Array {
    int * pBase; // 首地址
    int length;
    int size;
}* PARR;

void init_arr(PARR, int);
void clear_arr();
bool append(struct Array *, int);
bool insert(struct Array *, int, int);
bool delete(struct Array *, int);
int get(struct Array * pArr, int pos);
bool is_empty(struct Array *);
bool is_full(struct Array *);
void sort_arr(struct Array *);
void show_arr(struct Array *);
void inversion_arr(struct Array *);



int main(void) {

    PARR pArr;
    init_arr(pArr, 10);
    
    append(pArr, 1);
    append(pArr, 5);
    append(pArr, 7);
    append(pArr, 456);
    append(pArr, 632);
    append(pArr, 87);
    append(pArr, 65);
    append(pArr, 26);
    append(pArr, 32);

    insert(pArr, 3, 100);

    show_arr(pArr);
    inversion_arr(pArr);
    show_arr(pArr);
    sort_arr(pArr);
    show_arr(pArr);

    return 0;
}

void init_arr(PARR  pArr, int len) {

    pArr->pBase = (int *)malloc(sizeof(int) * len);
    if (NULL == pArr->pBase) {
        printf("动态内存分配失败。\n");
        exit(-1); // 终止程序
    }
    
    pArr->length = len;
    pArr->size = 0;
    return;
}


bool append(struct Array * pArr, int ele) {
    if (is_full(pArr)) {
        printf("数组满了。\n");
        return false;
    }

    pArr->pBase[pArr->size++] = ele;
    return true;
}


bool insert(struct Array * pArr, int pos, int ele) {

    if (is_full(pArr)) {
        printf("数组满了。\n");
        return false;
    }

    if (pos < 0 || pos > pArr->size) {
        printf("pos参数不合法。\n");
        return false;
    }

    int i;
    for (i=pArr->size-1; i>=pos; i--) {
        pArr->pBase[i+1] = pArr->pBase[i];
    }
    pArr->pBase[pos] = ele;
    pArr->size++;

    return true;
}

bool delete(struct Array * pArr, int pos) {

    if (is_empty(pArr)) return false;

    if (pos < 0 || pos > pArr->size-1) return false;

    for (int i = pos; i < pArr->size; i++) {
        pArr->pBase[i] = pArr->pBase[i+1]; 
    }
    pArr->size--;
    return true;
}

void clear_arr(struct Array * pArr) {
    pArr->size = 0;
    return;
}   

int get(struct Array * pArr, int pos) {
    return pArr->pBase[pos];
}

bool is_empty(struct Array * pArr) {
    return 0 == pArr->size
         ? true : false;
}


bool is_full(struct Array * pArr) {
    return pArr->size == pArr->length 
         ? true : false;
}

void show_arr(struct Array * pArr) {
    
    if (is_empty(pArr)) {
        printf("数组为空。\n");
        return;
    } 

    int i;
    for (i=0; i<pArr->size; i++) {
        printf("%d ", pArr->pBase[i]);
    }
    printf("\n");
    return;
}

void inversion_arr(struct Array * pArr) {

    int tmp;
    int low = 0;
    int high = pArr->size-1;

    while (high > low) {
        tmp = pArr->pBase[low];
        pArr->pBase[low] = pArr->pBase[high];
        pArr->pBase[high] = tmp;

        low++;
        high--;
    }
    
    return;
}

void sort_arr(struct Array * pArr) {

    int tmp;
    for (int i=0; i<pArr->size; i++) {
        for (int j=i+1; j<pArr->size; j++) {
            if (pArr->pBase[i] > pArr->pBase[j]) {
                tmp = pArr->pBase[i];
                pArr->pBase[i] = pArr->pBase[j];
                pArr->pBase[j] = tmp;
            }
        }
    }

    return;
}






