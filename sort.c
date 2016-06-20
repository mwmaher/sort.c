/* Sort.C

   By Michael W. Maher

   Ver 1.0 6/12/93      for MCS 5.1

   The following functions provide general purpose sorting routines.

	 description: implementations of various sorting algorithms

     basic operators: ssort()

*/

/****************************************************************************
   function: ssort()

 parameters: base    - a pointer to the base of the array to be sorted
	     num     - the number of elements in the array
	     width   - the number of bytes in a single element
	     campare - a pointer to a comparison function

    returns: a pointer to the base of the sorted array

    purpose: ssort() is selection sorting routine that can be called in the
	     same fashion as the ANSI qsort().  This is a non-recursive
	     function with N^2 complexity.
****************************************************************************/
void *ssort(void *base,
	   size_t num,
	   size_t width,
	   int (*compare) (const void *elem1, const void *elem2))
  {
  char temp,
       *p1,
       *p2;
  size_t i = 0,
	 j = 0,
	 k = 0,
	 s = 0;

  for (i = 0; i < num; i++)
    {
    /* find the smallest item in remaining array */
    s = i;
    p1 = (char *) base + i*width;
    for (j = i+1; j < num; j++)
      {
      p2 = (char *) base + j*width;
      if (compare(p2, p1) < 0)
	s = j;
      }                                /* end for */
    /* swap the smallest item with the current, 1 character at a time */
    if (s != i)
      {
      p2 = (char *) base + s*width;
      for (k = 0; k < width; k++)
	{
	temp = p1[k];
	p1[k] = p2[k];
	p2[k] = temp;
	}                              /* end for */
      }                                /* end if */
    }                                  /* end for */
  return((void *) base);
  }                                    /* ssort() */


/****************************************************************************
   function: msort()

 parameters: base    - a pointer to the base of the array to be sorted
	     num     - the number of elements in the array
	     width   - the number of bytes in a single element
	     campare - a pointer to a comparison function

    returns: a pointer to the base of the sorted array

    purpose: msort() is an implementation of a merge sort.  The routine can
    be called in the same fashion as the ANSI qsort().  This implementation
    of the merge sort is recursive in nature.
****************************************************************************/
void *msort(void *base,
	    size_t num,
	    size_t width,
	    int (*compare) (const void *elem1, const void *elem2))
  {
  return((void *) base);
  }                                    /* msort() */


