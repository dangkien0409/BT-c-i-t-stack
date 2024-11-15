#include <stdio.h>
#define MAX_SIZE 100  

int stack[MAX_SIZE];
int top = -1;  

//kiểm tra stack rỗng
int isEmpty() {
    return top == -1;
}

//kiểm tra stack đầy
int isFull() {
    return top == MAX_SIZE - 1;
}

//thêm phần tử vào stack
void push(int value) {
    if (isFull()) {
        printf("Stack đầy, không thể thêm phần tử!\n");
    } else {
        stack[++top] = value;
        printf("Đã thêm %d vào stack\n", value);
    }
}

//loại bỏ phần tử khỏi stack
int pop() {
    if (isEmpty()) {
        printf("Stack rỗng, không thể lấy phần tử!\n");
        return -1;  // về -1 nếu rỗng
    } else {
        return stack[top--];
    }
}

//lấy giá trị đỉnh stack mà không xoá
int peek() {
    if (isEmpty()) {
        printf("Stack rỗng!\n");
        return -1;
    } else {
        return stack[top];
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
