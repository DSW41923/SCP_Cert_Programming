/*
 * fqlib.h              Matt Bishop		April 4, 2005
 *
 * Header file for fragile queue library
 */

/*
 * the queue structure
 */
typedef struct queue {
	int *que;		/* the actual array of queue elements */
	int head;		/* head index in que of the queue */
	int count;		/* number of elements in queue */
	int size;		/* max number of elements in queue */
} QUEUE;

/*
 * the library functions
 */
void qmanage(QUEUE **, int, int);	/* create or delete a queue */
void put_on_queue(QUEUE *, int);	/* add to queue */
void take_off_queue(QUEUE *, int *);	/* pull off queue */

