// This program goes from task 4.3 to 4.10, implementing a calculator with variables and additional commands.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 1000
#define MAXOP 100
#define MAXVAL 100
#define NUMBER 1
#define NAME 2

double val[MAXVAL];
double variables[26];
double last_printed = 0.0;

int sp = 0;
int last_variable = -1;

int get_line(char line[], int limit);
int getop(char s[], char** line);
void push(double f);
double pop(void);
void print_top(void);
void duplicate(void);
void swap(void);
void clear(void);
void process_line(char line[]);

int main(void)
{
    char line[MAXLINE];

    while (get_line(line, MAXLINE) > 0)
        process_line(line);

    return 0;
}

int get_line(char line[], int limit)
{
    int c, i;

    for (i = 0; i < limit - 1 &&
        (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    if (c == '\n')
        line[i++] = c;

    line[i] = '\0';

    return i;
}

int getop(char s[], char** line)
{
    char* start;
    char* end;
    int i;

    while (isspace((unsigned char)**line))
        (*line)++;

    if (**line == '\0')
        return '\n';

    start = *line;

    if (isalpha((unsigned char)**line))
    {
        i = 0;

        while (isalpha((unsigned char)**line))
            s[i++] = *(*line)++;

        s[i] = '\0';

        return NAME;
    }

    if (isdigit((unsigned char)**line) ||
        **line == '.' || **line == '-')
    {
        end = *line;

        strtod(*line, &end);

        if (end != *line)
        {
            i = end - *line;

            if (i >= MAXOP)
                i = MAXOP - 1;

            strncpy(s, start, i);
            s[i] = '\0';

            *line = end;

            return NUMBER;
        }
    }

    return *(*line)++;
}

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full\n");
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];

    printf("error: stack empty\n");
    return 0.0;
}

void print_top(void)
{
    if (sp > 0)
    {
        last_printed = val[sp - 1];
        printf("\t%.8g\n", last_printed);
    }
    else
        printf("error: stack empty\n");
}

void duplicate(void)
{
    if (sp > 0)
        push(val[sp - 1]);
    else
        printf("error: stack empty\n");
}

void swap(void)
{
    double temp;

    if (sp < 2)
    {
        printf("error: not enough elements\n");
        return;
    }

    temp = val[sp - 1];
    val[sp - 1] = val[sp - 2];
    val[sp - 2] = temp;
}

void clear(void)
{
    sp = 0;
}

void process_line(char line[])
{
    char s[MAXOP];
    char* linep = line;

    int type;
    int index;

    double op1, op2;

    while ((type = getop(s, &linep)) != '\n')
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;

        case NAME:
            if (strlen(s) == 1 &&
                s[0] >= 'A' && s[0] <= 'Z')
            {
                index = s[0] - 'A';
                last_variable = index;
                push(variables[index]);
            }
            else if (strcmp(s, "sin") == 0)
            {
                if (sp >= 1)
                    push(sin(pop()));
                else
                    printf("error: stack empty\n");
            }
            else if (strcmp(s, "exp") == 0)
            {
                if (sp >= 1)
                    push(exp(pop()));
                else
                    printf("error: stack empty\n");
            }
            else if (strcmp(s, "pow") == 0)
            {
                if (sp >= 2)
                {
                    op2 = pop();
                    op1 = pop();
                    push(pow(op1, op2));
                }
                else
                    printf("error: not enough elements\n");
            }
            else if (strcmp(s, "dup") == 0)
                duplicate();
            else if (strcmp(s, "swap") == 0)
                swap();
            else if (strcmp(s, "clear") == 0)
                clear();
            else if (strcmp(s, "print") == 0)
                print_top();
            else
                printf("error: unknown name %s\n", s);

            break;

        case '+':
            if (sp >= 2)
            {
                op2 = pop();
                op1 = pop();
                push(op1 + op2);
            }
            else
                printf("error: not enough elements\n");
            break;

        case '-':
            if (sp >= 2)
            {
                op2 = pop();
                op1 = pop();
                push(op1 - op2);
            }
            else
                printf("error: not enough elements\n");
            break;

        case '*':
            if (sp >= 2)
            {
                op2 = pop();
                op1 = pop();
                push(op1 * op2);
            }
            else
                printf("error: not enough elements\n");
            break;

        case '/':
            if (sp >= 2)
            {
                op2 = pop();
                op1 = pop();

                if (op2 != 0.0)
                    push(op1 / op2);
                else
                    printf("error: zero divisor\n");
            }
            else
                printf("error: not enough elements\n");
            break;

        case '%':
            if (sp >= 2)
            {
                op2 = pop();
                op1 = pop();

                if (op2 != 0.0)
                    push(fmod(op1, op2));
                else
                    printf("error: zero divisor\n");
            }
            else
                printf("error: not enough elements\n");
            break;

        case '=':
            if (last_variable >= 0 && sp >= 2)
            {
                pop();
                variables[last_variable] = pop();
                last_variable = -1;
            }
            else
                printf("error: invalid assignment\n");
            break;

        case '@':
            push(last_printed);
            break;

        case '?':
            print_top();
            break;

        default:
            printf("error: unknown command %c\n", type);
            break;
        }
    }

    if (sp > 0)
    {
        last_printed = val[sp - 1];
        printf("\t%.8g\n", last_printed);
    }
}
