#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[100];

typedef struct {
    int a;
    int b;
} Range;

void* part_sum(void *arg)
{
    Range *r = (Range*)arg;
    int *s = malloc(sizeof(int));
    *s = 0;

    for (int i = r->a; i < r->b; i++)
        *s += arr[i];

    return s;
}

int main()
{
    int normal = 0;
    for (int i = 0; i < 100; i++) {
        arr[i] = rand() % 50;
        normal += arr[i];
    }

    pthread_t th[10];
    int total = 0;

    for (int i = 0; i < 10; i++) {
        Range *r = malloc(sizeof(Range));
        r->a = i * 10;
        r->b = r->a + 10;
        pthread_create(&th[i], NULL, part_sum, r);
    }

    for (int i = 0; i < 10; i++) {
        int *res;
        pthread_join(th[i], (void**)&res);
        total += *res;
        free(res);
    }

    printf("normal sum   = %d\n", normal);
    printf("threaded sum = %d\n", total);

    return 0;
}

