#include <stdio.h>
#include <string.h>
#define SIZE 20

char **cut(char arr[], char ch)
{
    int raw = 0;
    int j = 0;
    for (int i = 0; i < strlen(arr); i++)
    {
        if (arr[i] == ch)
        {
            raw++;
        }
    }
    char output[raw][SIZE];
    for (int i = 0; i < raw; i++)
    {
        while (j < strlen(arr))
        {
            if (arr[j] == ch)
            {
                output[i][j] = '\0';
                j++;
                break;
            }
            output[i][j] = arr[j];
            j++;
        }
    }
    return output;
}

char *s_get(char *st, int n)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
        {
            i++;
        }
        if (st[i] == '\n')
            st[i] = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}

int main()
{
    char arr1[SIZE];
    char **aftercut;
    char ch = ' ';
    printf("Please input a string.\n");
    s_get(arr1, SIZE);
    aftercut = cut(arr1, ch);
    puts(aftercut);

    return 0;
}
