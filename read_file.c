#include <stdio.h>
#include <string.h>

int main() {
    FILE *f = fopen("text.txt", "r");
    if (!f) {
        printf("Error with openig the file\n");
        return 1;
    }

    char cmd[10];
    float a, b;
    int code;

    while (fscanf(f, "%s %f %f", cmd, &a, &b) == 3) {

        if      (strcmp(cmd, "ADD") == 0) code = 1;
        else if (strcmp(cmd, "SUB") == 0) code = 2;
        else if (strcmp(cmd, "MUL") == 0) code = 3;
        else if (strcmp(cmd, "DIV") == 0) code = 4;
        else code = -1;

        switch (code) {
            case 1:
                printf("%f\n", a + b);
                break;
            case 2:
                printf("%f\n", a - b);
                break;
            case 3:
                printf("%f\n", a * b);
                break;
            case 4:
                if (b == 0)
                    printf("division by zero\n");
                else
                    printf("%f\n", a / b);
                break;
            default:
                printf("Unknown command: %s\n", cmd);
        }
    }

    fclose(f);
    return 0;
}

