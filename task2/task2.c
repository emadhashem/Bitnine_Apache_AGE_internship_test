#include <stdio.h>

int f_recursive(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return f_recursive(n - 3) + f_recursive(n - 2);
}

int f_iterative(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    int a = 0, b = 1, c = 2;
    for (int i = 3; i <= n; i++)
    {
        int d = a + b;
        a = b;
        b = c;
        c = d;
    }
    return c;
}

int f_dynamic_programming(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 3] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int value;
    printf("Please enter the value you want calculate: ");
    scanf("%d", &value);

    int type;
    printf("\n enter \n 1 for recursive \n 2 for iterative \n 3 for dynamic programming \n=> ");
    scanf("%d", &type);

    switch (type)
    {
    case 1:
    {
        printf("The result = %d\n", f_recursive(value));
    }
    break;
    case 2:
    {
        printf("The result = %d\n", f_iterative(value));
    }
    break;
    case 3:
    {
        printf("The result = %d\n", f_dynamic_programming(value));
    }
    break;
    default:
        printf("\nInvalid input.\n");
        break;
    }

    return 0;
}