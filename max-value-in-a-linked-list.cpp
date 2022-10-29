#include <iostream>
#include <cstdlib>

struct Node {
    int val;
    struct Node *next;
}*first = NULL;

// create linked list
void createLinkedList(int a[], int n) {
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->val = a[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->val = a[i];
        t->next=NULL;
        last->next = t;
        last = t;

    }
}

// display full linked list recursively
void displayLinkedList(struct Node *p) {
    if (p != NULL) {
        printf("%d -> ", p->val);
        // recursive call
        displayLinkedList(p->next);
    }
}

// iterative method
int returnMaxValueInLinkedList(struct Node *p) {
    int maxVal = INT32_MIN;
    while (p) {
        if(p->val > maxVal) {
            maxVal = p->val;
        }
        p = p->next;
    }
    return maxVal;
}

// recursive method
int returnMaxValueInLinkedListRecursively(struct Node *p) {
    int x = 0;

    if (p == 0) {
        return INT32_MIN;
    }
    x = returnMaxValueInLinkedListRecursively(p->next);
    if (x > p->val) {
        return x;
    } else {
        return p->val; 
    }
}


int main() {

    int a[] = {1, 5, 3, 7, 8, 2};

    createLinkedList(a, 6);

    int maxVal = returnMaxValueInLinkedList(first);
    printf("The largest value in the linked list is %d ", maxVal);

}
