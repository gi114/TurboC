
#include <stdio.h>
#include <stdlib.h>

/************************************************************************************************
 *                                                                                              *
 * PROBLEM DEFINITION:                                                                          *
 * Given a set (or multiset) of integers, find all the different subsets of a given total sum   *
 *                                                                                              *
 ************************************************************************************************/


typedef unsigned long long int s64;  /* unsigned keyword for +ve numbers allows to access more space, 1 - 65535. Long keyword indicates extra precision needed*/

int SIZE = 10;                       /* Set Cardinality, hence number of elements in the dSet array */
int FINAL_SIZE = 17;                 /* Example: C30 = 947, C35 = 3236, C25 = 530, C36 = 3387. C20 = 173, C15 = 52, C10 = 17, C5 = 1 */
static int HEAD = 0;
s64 SUM = 29;                        /* Set total sum */

s64 * additionOp(int i, const s64* val, const s64 set[], s64 result[], int indx, s64 final_res[]);
int is_a_sum(const s64 * n);
s64 * print(const s64 result[], s64 final_res[]);


int main()
{
    /** Data structure initialization: static memory allocation is preferred as variables allocated on the stack are stored
     * directly to the memory and access to this memory is very fast, and it's allocation is dealt with when the program is
     * compiled. Variables stored on the stack have their memory allocated at run time
     **/

    s64 dSet[SIZE];
    int indx = 0;
    s64 *result;
    s64 *final_result = calloc(FINAL_SIZE, sizeof(*result));
    result = calloc(SIZE, sizeof(*result));

    /** You can manually select the numbers to include in the subset sum problem. We use prime numbers for the current case
     * By increasing the size of the dSet array we can add extra numbers. A static array dSet was used for performance purposes
     **/

    dSet[0] = 2;
    dSet[1] = 3;
    dSet[2] = 5;
    dSet[3] = 7;
    dSet[4] = 11;
    dSet[5] = 13;
    dSet[6] = 17;
    dSet[7] = 19;
    dSet[8] = 23;
    dSet[9] = 29;

    for (int n = SIZE - 1; n>0; n--)
    {
        s64 res = dSet[n];
        *result = res;

        if (is_a_sum(&res) == 1) {
            final_result = print(result, final_result);
        }

        if (n > 0) {
            result = additionOp( n-1, &res,  dSet, result, indx+1, final_result);
        }
    }

    return 0;
}


/** Function: recursively evaluates all possible subsets and momentarily stores them on a temporary array called 'result'
 *  at each cycle. The result array is freed and overwritten at each cycle. The first cycle evaluates all numbers in dSet array,
 *  and after that numbers start being excluded from the calculation until only the last 2 are evaluated. Successful subsets
 *  are saved, while unsuccessful ones are deleted **/

s64 * additionOp(int i, const s64* val, const s64 set[], s64 result[], int indx, s64 final_res[]) {

    for (int j = i ; j>=0; j--)
    {
        s64 res = *val + set[j];
        *(result + indx) = set[j];

        if (is_a_sum(&res) == 1) {
            final_res = print(result, final_res);
            free(result);
            result = calloc(SIZE, sizeof(*result));
            indx = 0;
        }

        if (j > 0) {
            result = additionOp(j - 1, &res, set, result, indx+1, final_res);
        }

        result[indx] = 0;
    }

    return result;
}


/** Function: saves successful subsets on the final_res array and logs them out on the console **/

s64 * print(const s64 result[], s64 final_res[]) {

    if (result != NULL)
    {
        for (int indx = 0; indx < SIZE; indx++) {
            if (result[indx] != 0) {
                if (FINAL_SIZE == HEAD) {
                    printf("Exception -> final result out of bound");
                }
                final_res[HEAD] = result[indx];
                printf("%llu\n", final_res[HEAD]);   /* Logs out successful subsets */
                HEAD++;
            }
        }
    }

    return final_res;
}


/** Function: checks if the numbers currently evaluates are successful subsets **/

int is_a_sum(const s64 * n) {       /* if false 0, else 1 */

    if (*n == SUM) {
        return 1;
    }

    return 0;
}
