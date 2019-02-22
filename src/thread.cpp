#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *t_function(void *data)
{
    int id;
    int i = 0;
    id = *((int *)data);

    while(++i < 2003)
    {
        printf("%d : %d\n", id, i);
        sleep(1);
    }
}

int main()
{
    pthread_t p_thread[2];
    int thr_id;
    int status;
    int a = 1;
    int b = 2;

    thr_id = pthread_create(&p_thread[0], NULL, t_function, (void *)&a);
    if (thr_id < 0)
    {
        perror("thread create error : ");
        exit(0);
    }

    thr_id = pthread_create(&p_thread[1], NULL, t_function, (void *)&b);
    if (thr_id < 0)
    {
        perror("thread create error : ");
        exit(0);
    }

    return 0;
}
