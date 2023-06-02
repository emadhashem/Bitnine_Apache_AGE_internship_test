#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 50
typedef struct Node Node;
int *dp;

typedef enum
{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    FIB
} TypeTag;

struct Node
{
    int num;
    struct Node *left;
    struct Node *right;
    TypeTag op; // operation
};

Node *add(int a, int b);

Node *subtract(int a, int b);

Node *multiply(int a, int b);

Node *divide(int a, int b);

Node *(*makeFunc(TypeTag op))(int, int);

Node *addNode(Node *a, Node *b);

Node *subtractNode(Node *a, Node *b);

Node *multiplyNode(Node *a, Node *b);

Node *divideNode(Node *a, Node *b);

Node *(*makeFuncNode(TypeTag op))(Node *, Node *);

int calc(Node *u);

int fibo(int x);

int main()
{

    dp = (int *)malloc(SIZE * sizeof(int));
    memset(dp, -1, SIZE * sizeof(int));
    dp[0] = dp[1] = 0;
    dp[2] = 1;

    Node *add = (*makeFunc(ADD))(10, 6);
    Node *mul = (*makeFunc(MULTIPLY))(5, 4);
    Node *sub = (*makeFuncNode(SUBTRACT))(mul, add);
    Node *fibo = (*makeFuncNode(SUBTRACT))(sub, NULL);

    printf("%d\n", calc(add));
    printf("%d\n", calc(mul));
    printf("%d\n", calc(sub));
    printf("%d\n", calc(fibo));
    free(dp);
    return 0;
}

Node *add(int a, int b)
{
    Node *result = malloc(sizeof(Node));
    result->num = a + b;
    result->op = ADD;
    return result;
}

Node *subtract(int a, int b)
{
    Node *result = malloc(sizeof(Node));
    result->num = b - a;
    result->op = SUBTRACT;
    return result;
}

Node *multiply(int a, int b)
{
    Node *result = malloc(sizeof(Node));
    result->num = a * b;
    result->op = MULTIPLY;
    return result;
}

Node *divide(int a, int b)
{
    Node *result = malloc(sizeof(Node));
    result->op = DIVIDE;
    if (a == 0)
    {
        printf("Error: Division by zero.\n");
        result->num = 0;
    }
    else
    {
        result->num = b / a;
    }

    return result;
}

Node *(*makeFunc(TypeTag op))(int, int)
{
    switch (op)
    {
    case ADD:
        return &add;
    case SUBTRACT:
        return &subtract;
    case MULTIPLY:
        return &multiply;
    case DIVIDE:
        return &divide;
    default:
        printf("Error: Invalid operation.\n");
        return NULL;
    }
}

Node *addNode(Node *a, Node *b)
{
    Node *result = malloc(sizeof(Node));
    result->left = a;
    if (b == NULL)
    {
        result->op = FIB;
        return result;
    }
    result->op = ADD;
    result->right = b;
    return result;
}

Node *subtractNode(Node *a, Node *b)
{
    Node *result = malloc(sizeof(Node));
    result->left = a;
    if (b == NULL)
    {
        result->op = FIB;
        return result;
    }
    result->op = SUBTRACT;
    result->right = b;
    return result;
}

Node *multiplyNode(Node *a, Node *b)
{
    Node *result = malloc(sizeof(Node));
    result->left = a;
    if (b == NULL)
    {
        result->op = FIB;
        return result;
    }
    result->op = MULTIPLY;
    result->right = b;
    return result;
}

Node *divideNode(Node *a, Node *b)
{
    Node *result = malloc(sizeof(Node));
    if (a == NULL || a->num == 0)
    {
        printf("Error: Division by zero.\n");
        result->num = 0;
        return result;
    }
    result->left = a;
    if (b == NULL)
    {
        result->op = FIB;
        return result;
    }
    result->op = DIVIDE;
    result->right = b;
    return result;
}

Node *(*makeFuncNode(TypeTag op))(Node *, Node *)
{

    switch (op)
    {
    case ADD:
        return &addNode;
    case SUBTRACT:
        return &subtractNode;
    case MULTIPLY:
        return &multiplyNode;
    case DIVIDE:
        return &divideNode;
    default:
        printf("Error: Invalid operation.\n");
        return NULL;
    }
}

int calc(Node *u)
{
    if (u->left == NULL && u->right == NULL)
    {
        if (u->num == (int *) NULL)
            return 0;
        return u->num;
    }
    switch (u->op)
    {
    case ADD:
        return calc(u->right) + calc(u->left);
        break;
    case SUBTRACT:
        return -1 * calc(u->left) + calc(u->right);
        break;
    case MULTIPLY:
        return calc(u->right) * calc(u->left);
        break;
    case DIVIDE:
        return calc(u->right) / calc(u->left);
        break;
    case FIB:
    {
        return fibo(abs(calc(u->left)));
    }
    break;
    default:
        return 0;
    }
    return 0;
}

int fibo(int x)
{

    if (x >= SIZE)
    {
        printf("greater than the size");
        return -1e9;
    }
    if (dp[x] != -1)
        return dp[x];
    dp[x] = fibo(x - 1) + fibo(x - 2);
    return dp[x];
}
