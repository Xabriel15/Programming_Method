#define MAXVAL 100      /* maximu depth of val stack*/
double val[MAXVAL];     /* value stack*/
int sp = 0;             /* stack pointer : defined outside of funcion*/

/* push : push f onto  value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error:stack full, cant push %g\n", f);
}

/* pop and return top value from stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}