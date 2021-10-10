#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Stack {
    int* A;
    int MAXSIZE;
    int top;

public:
    Stack();
    ~Stack();
    void print();
    bool push(int item);
    bool pop(int& retval);
    bool peek(int& retval);
    bool is_empty();
};

Stack::Stack() {
    MAXSIZE = 2;
    A = (int*)malloc(MAXSIZE*sizeof(int));
    top = 0;
}

Stack::~Stack() {
    free(A);
}

void Stack::print() {
    for(int i=0; i<top; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

bool Stack::push(int item) {
    if(top == MAXSIZE) {
        int* temp = (int*)malloc(2*MAXSIZE*sizeof(int));
        if(temp == NULL)
            return false;
        for(int i=0; i<MAXSIZE; i++)
            temp[i] = A[i];
        free(A);
        A = temp;
        MAXSIZE = 2*MAXSIZE;
    }
    A[top] = item;
    top++;
    return true;
}

bool Stack::pop(int& retval) {
    if(top > 0) {
        retval = A[top-1];
        top--;
        return true;
    }
    else
        return false;
}

bool Stack::peek(int& retval) {
    if(top > 0) {
        retval = A[top-1];
        return true;
    }
    else
        return false;
}

bool Stack::is_empty() {
    if(top == 0)
        return true;
    else
        return false;
}

int applyOp(int val1, int val2, char op)
{
    if(op == '+')
        return val1 + val2;
    else if(op == '-')
        return val1 - val2;
    else if(op == '*')
        return val1 * val2;
    else if(op == '/')
        return val1 / val2;
}

int evaluate(char expr[]) {
    int len = strlen(expr);
    Stack val_stack;
    Stack op_stack;

    for(int i=0; i<len; i++) {
        char token = expr[i];

        if('0' <= token && token <= '9') {
            val_stack.push(token-'0');
        }
        else if(token == '(') {
            op_stack.push(token);
        }
        else if(token == ')') {
			int temp;
			while(op_stack.peek(temp) && temp != '(') {
                int op, val1, val2;
                op_stack.pop(op);
                val_stack.pop(val1);
                val_stack.pop(val2);
                val_stack.push(applyOp(val2,val1,op));
            }
            op_stack.pop(temp);
        }
        else if(token == '+' || token == '-') {
			int temp;
			while(!op_stack.is_empty() && op_stack.peek(temp) && temp != '(') {
                int op, val1, val2;
                op_stack.pop(op);
                val_stack.pop(val1);
                val_stack.pop(val2);
                val_stack.push(applyOp(val2,val1,op));
            }
            op_stack.push(token);
        }
        else if(token == '*' || token == '/') {
            int temp;
			while(!op_stack.is_empty() && op_stack.peek(temp) && (temp == '*' || temp == '/')) {
                int op, val1, val2;
                op_stack.pop(op);
                val_stack.pop(val1);
                val_stack.pop(val2);
                val_stack.push(applyOp(val2,val1,op));
            }
            op_stack.push(token);
        }
    }

	while(!op_stack.is_empty()) {
        int op, val1, val2;
        op_stack.pop(op);
        val_stack.pop(val1);
        val_stack.pop(val2);
        val_stack.push(applyOp(val2,val1,op));
    }

	int result;
	val_stack.pop(result);
	return result;
}

int main() {
    char expr[100];
    gets(expr);
    int result = evaluate(expr);
    printf("%d\n", result);

    return 0;
}
