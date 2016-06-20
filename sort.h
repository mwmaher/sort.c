/* SORT.H

   By Michael W. Maher

   Ver 1.0 6/12/93      for MCS 5.1

   The following functions provide general purpose sorting routines.

	 description: implementations of various sorting algorithms

     basic operators: ssort()
		      msort()

*/

void *ssort(void *base,
	    size_t num,
	    size_t width,
	    int (*compare) (const void *elem1, const void *elem2));

void *msort(void *base,
	    size_t num,
	    size_t width,
	    int (*compare) (const void *elem1, const void *elem2));


