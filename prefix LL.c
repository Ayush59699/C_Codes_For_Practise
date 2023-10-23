#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure for the linked list implementation
typedef struct node {
    int data;
    struct node* next;
} Node;

// Stack structure
typedef struct stack {
    Node* top;
} Stack;

// Function to create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to check if the stack is empty
int is_empty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push a new element onto the stack
void push(Stack* stack, int data) {
    Node* new_node = create_node(data);
    new_node->next = stack->top;
    stack->top = new_node;
}

// Function to pop the top element off the stack
int pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to peek at the top element of the stack
int peek(Stack* stack) {
    if (is_empty(stack)) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return stack->top->data;
}

// Function to evaluate a prefix expression
int evaluate_prefix(char* expression) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;

    int i, len = strlen(expression);
    for (i = len - 1; i >= 0; i--) {
        if (isdigit(expression[i])) {
            int operand = expression[i] - '0';
            push(stack, operand);
        } else {
            int operand1 = pop(stack);
            int operand2 = pop(stack);
            switch (expression[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }
    }
    int result = pop(stack);
    free(stack);
    return result;
}

// Function to evaluate a postfix expression
int evaluate_postfix(char* expression) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;

    int i, len = strlen(expression);
    for (i = 0; i < len; i++) {
        if (isdigit(expression[i])) {
            int operand = expression[i] - '0';
            push(stack, operand);
        } else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            switch (expression[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }
    }
    int result = pop(stack);
    free(stack);
    return result;
}

// Main function to test the implementations
