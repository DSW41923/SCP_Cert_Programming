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
    for (int i = 0; i < 1000; ++i)
    {
        take_off_queue(test_queue, &i);
    }
    printf("%i\n", test_queue->que[test_queue->head]);
	return 0;
}
