#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;  

//kiểm tra stack rỗng
int isEmpty() {
    return top == NULL;
}

//thêm phần tử vào stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Không đủ bộ nhớ để thêm phần tử!\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Đã thêm %d vào stack\n", value);
}

//loại bỏ phần tử khỏi stack
int pop() {
    if (isEmpty()) {
        printf("Stack rỗng, không thể lấy phần tử!\n");
        return -1;
    } else {
        struct Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        free(temp);
        return poppedValue;
    }
}

//lấy giá trị đỉnh stack mà không xoá
int peek() {
    if (isEmpty()) {
        printf("Stack rỗng!\n");
        return -1;
    } else {
        return top->data;
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    
    printf("Giá trị đỉnh của stack: %d\n", peek());
    
    printf("Đã lấy %d từ stack\n", pop());
    printf("Giá trị đỉnh của stack sau khi lấy phần tử: %d\n", peek());

    return 0;
}
