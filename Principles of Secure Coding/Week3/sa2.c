#include <stdio.h>
#include <stdlib.h>
#include "fqlib.h"

int main(int argc, char const *argv[])
{
    QUEUE *test_queue;
    int queue_size = 10;
    qmanage(&test_queue, 1, queue_size);
    int count = 10;
    for (int i = 0; i < count; ++i)
    {
        put_on_queue(test_queue, i);
    }
    for (int i = 0; i < count/2; ++i)
    {
        take_off_queue(test_queue, &i);
    }
    printf("%i\n", test_queue->que[test_queue->head]);


    QUEUE *test_1;
    queue_size = 2;
    qmanage(&test_1, 1, queue_size);
    take_off_queue(test_1, &queue_size);
    put_on_queue(test_1, 1);
    printf("%i\n", test_1->head);
    printf("%i\n", test_1->que[test_1->head]);
    return 0;
}
