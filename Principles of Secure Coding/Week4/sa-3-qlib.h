/*
 * This file contains the definitions for the qlib library;
 * only the ones external programs need to know about lie here.
 *
 * See qlib.c for ma full explanation of all these
 */
/*
 * queue identifier; actually contains internal, uninteresting junk
 */
typedef unsigned int QTICKET;

/*
 * error return values
 * all the queue manipulation functions return these;
 * you can interpret them yourself, or print the error
 * message in qe_errbuf, which describes these codes
 */
#define QE_ISERROR(x)	((x) < 0)	/* true if x is a qlib error code */
#define QE_NONE		 0		/* no errors */
#define QE_BADPARAM	-1		/* bad parameter (ie, NULL pointer) */
#define QE_BADTICKET	-3		/* bad ticket for the queue */
#define QE_EMPTY	-4		/* take it off an empty queue */
#define QE_FULL		-5		/* append it to a full queue */
#define QE_NOROOM	-6		/* can't allocate space (sys err) */
#define QE_TOOMANYQS	-7		/* too many queues in use (max 100) */
#define QE_INTINCON	-8		/* internal inconsistency */
#define	QE_TOOFULL	-9		/* queue is too full */

/*
 * the error buffer; contains a message describing the last queue
 * error (but is NUL if no error encountered); not cleared on success
 */
extern char qe_errbuf[256];

/*
 * forward declarations, for K&R and ANSI C
 */
#ifdef __STDC__
QTICKET create_queue(void);		/* create a queue */
int delete_queue(QTICKET);		/* delete a queue */
int put_on_queue(QTICKET, int);		/* put number on end of queue */
int take_off_queue(QTICKET);		/* pull number off front of queue */
#else
QTICKET create_queue();			/* create a queue */
int delete_queue();			/* delete a queue */
int put_on_queue();			/* put number on end of queue */
int take_off_queue();			/* pull number off front of queue */
#endif

