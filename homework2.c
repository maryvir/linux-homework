#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Stack {
    struct Node* first;
    int size;         
};

struct Stack obj;


void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = obj.first;
    obj.first = newNode;

    obj.size++;
}

void pop() {
    if (obj.size == 0) {
        printf("Stack is empty!\n");
        return;
    }

    struct Node* temp = obj.first;

    obj.first = obj.first->next;
    free(temp);
    obj.size--;
}

void top() {
    if (obj.size == 0) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top: %d\n", obj.first->value);
}

int getSize() {
    return obj.size;
}

int main() {
    obj.first = NULL;
    obj.size = 0;

    push(1);
    push(2);
    push(3);

    top();
    printf("Size = %d\n", getSize());

    pop();
    top();
    printf("Size = %d\n", getSize());

    pop();
    pop();
    top();
    printf("Size = %d\n", getSize());
    return 0;
}
