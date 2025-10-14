#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *arg[]) 
{

    double length = atof(arg[1]);
    double width = atof(arg[2]);
    double area = length * width;

    printf("Rectangle area: %.2f\n", area);
    return 0;
}
