/* sorttest.c

   By Michael W. Maher

   Ver 1.0 6/15/92      for MCS 5.1

   The following program will test the general purpose sorting functions.
   These functions are found in the sort.h header file.  The source code
   is located in sort.c.

   The function is ANSI C complient.  It was tested for complience with
   the Microsoft C compiler V5.51 using the /Za switch. Example:

	CL /Za sorttest.c

*/


/******************************** includes *********************************/
#include<stdio.h>
#include<string.h>
#include<time.h>
#include"sort.h"
#include"sort.c"

#define TESTARRAYSIZE 1000
#define PASS 1
#define FAIL 0

/**************************** function prototypes **************************/
void main(void);
char test_1(FILE *output);
char *testout(char passfail, char *out);
int  comp_desc_int(const void *elem1, const void *elem2);

void main()
  {
  FILE *output;
  char buf[5];

  output = stderr;                     /* direct output to a stream */
  fprintf(output, "\n\n"
		  "sorttest.c By Michael W. Maher 9/1/92\n"
		  "Testing the sort.c C function suite...\n\n");

  /* Test the ssort() function.  */
  fprintf(output, "TEST #%d: %s\n", 1, testout(test_1(output), buf));

  }

/****************************************************************************
   function: testout()

 parameters: passfail - boolean value (PASS or FAIL)
		  out - 5 character string

    returns: "PASS" is returned in the string (out) if passfail contains
	     a PASS char value.
	     "FAIL" is returned in the string (out) if passfail contains
	     a FAIL char value.

    purpose: This function converts a boolean PASS or FAIL value to a
	     string value "PASS" or "FAIL".
****************************************************************************/
char *testout(char passfail, char *out)
  {
  if (passfail == PASS)
    strcpy(out, "PASS");
  else
    strcpy(out, "FAIL");
  return(out);
  }


/****************************************************************************
   function: test_1
 parameters:
    returns: if successful
	       TRUE
	     else
	       FALSE
    purpose: Test the selection sort ssort() function by sorting an array
	     of integers();
****************************************************************************/
char test_1(FILE *output)
  {
  time_t start,
	 finish;
  char status = PASS;
  int i,
      j,
      int_array[TESTARRAYSIZE];

  /* load array in ascending order */
  for (i = 0; i < TESTARRAYSIZE; i++)
    int_array[i] = i;

  /* sort with selection sort function in descending order */
  time(&start);
  ssort(int_array, TESTARRAYSIZE, sizeof(int), comp_desc_int);
  time(&finish);
  fprintf(output, "\nsort time: %f ", difftime(finish, start)/1000);
  /* check array for descending order */
  for (i = 0, j = TESTARRAYSIZE - 1; i < TESTARRAYSIZE; i++, j--)
    {
    if (int_array[i] != j)
      {
      status = FAIL;
      break;
      }
    }
  if (status == FAIL)
    fprintf(output, "\nERROR: Unexpected array element (%.0d, %.0d)\n", i, j);
  return(status);
  }


int comp_desc_int(const void *elem1, const void *elem2)
  {
  if ((* (int *) elem1) < (* (int *) elem2))
    return(1);
  if ((* (int *) elem1) > (* (int *) elem2))
    return(-1);
  else
    return(0);
  }
