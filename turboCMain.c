
#include <stdio.h>
#include <stdlib.h>

/* PROBLEM: Given a set (or multiset) of integers, find all the different combinations of subset sums */
typedef unsigned long long int s64;  //unsigned for +ve numbers and more space available, 1 - 65535. Long indicates extra precision needed

int SIZE = 1; /*__DATA */
int FINAL_SIZE = 1; //30 = 1315, C35 = 2832, C25 = 516, C36 = 3387. C20 = 175, C15 = 66, C10 = 17, C5 = 1
static int HEAD = 0;
s64 SUM = 2;


s64 * additionOp(int i, const s64* val, const s64 set[], s64 result[], int indx, s64 final_res[]);
int is_a_sum(const s64 * n);
s64 * print(const s64 result[], s64 final_res[]);


int main()
{
    /* Start timing computation. Get the value if a free running counter incremented at a specific rate
     * Stack is used for static memory allocation and Heap for dynamic memory allocation, both stored in the computer's RAM .
     * Variables allocated on the stack are stored directly to the memory and access to this memory is very fast, and it's
     * allocation is dealt with when the program is compiled. Variables stored on the stack have their memory allocated at run time*/
    s64 dSet[SIZE];
    int indx = 0;
    s64 *result;
    s64 *final_result = calloc(FINAL_SIZE, sizeof(*result));
    result = calloc(SIZE, sizeof(*result));  /* __BSS */

       dSet[0] = 2;            /* __DATA */
     /*  dSet[1] = 3;
       dSet[2] = 5;
       dSet[3] = 7;
       dSet[4] = 11;
    /*   dSet[5] = 13;
       dSet[6] = 17;
       dSet[7] = 19;
       dSet[8] = 23;
       dSet[9] = 29;
        dSet[10] = 31;
        dSet[11] = 37;
        dSet[12] = 41;
        dSet[13] = 47;
        dSet[14] = 53;
           dSet[15] = 59;
             dSet[16] = 61;
             dSet[17] = 67;
             dSet[18] = 71;
             dSet[19] = 73;
            dSet[20] = 79;
            dSet[21] = 83;
            dSet[22] = 89;
            dSet[23] = 97;
            dSet[24] = 101;
            dSet[25] = 103;
           dSet[26] = 107;
           dSet[27] = 109;
           dSet[28] = 113;
           dSet[29] = 127;
           dSet[30] = 131;
             dSet[31] = 137;
             dSet[32] = 139;
             dSet[33] = 149;
             dSet[34] = 151;
             dSet[35] = 157;
             dSet[36] = 163;
             dSet[37] = 167;
             dSet[38] = 173;
             dSet[39] = 179;
             dSet[40] = 181; */


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
    printf("%d this is ", HEAD);
    return 0;
}



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

s64 * print(const s64 result[], s64 final_res[]) {
    if (result != NULL)
    {
        for (int indx = 0; indx < SIZE; indx++) {
            if (result[indx] != 0) {
                if (FINAL_SIZE == HEAD) {
                    printf("Exception -> final result out of bound");
                }
                final_res[HEAD] = result[indx];
                //printf("%llu\n", final_res[HEAD]);
                HEAD++;
            }
        }
    }
    return final_res;
}

int is_a_sum(const s64 * n) {  // if false 0, else 1
    if (*n == SUM) {
        return 1;
    }
    return 0;
}
