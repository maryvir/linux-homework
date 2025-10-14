#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *arg[]) 
{

    double base = atof(arg[1]);
    double height = atof(arg[2]);
    double area = 0.5 * base * height;

    printf("Triangle area: %.2f\n", area);
    return 0;
}
