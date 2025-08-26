#include "L8.h"
#include <stdio.h>
#include "ArrayUtils.h"



void startL8() {
    printf("▧ ▧ ▧ ▧ L8 ▧ ▧ ▧ ▧\n");

    float grades[] = {70, 80, 40, 90, 70, 90, 70, 30, 30, 40, 87, 89, 100};
    int sz = sizeof(grades) / sizeof(grades[0]);
    printf("sz:%d\n", sz);

    float average = Average(grades, sz);
    printf("average:%.2f\n", average);

    PrintArr(grades, sz);
    Factor(grades, sz, 5.0);
    PrintArr(grades, sz);


    float median = Median(grades, sz);
    printf("median:%.2f\n", median);
    PrintArr(grades, sz);

    Sort(grades, sz);
    PrintArr(grades, sz);

    int found75 = Find(grades, sz, 74.0);
    printf("found75: %d\n", found75);

    Hit(grades, sz, 74.0);

    float above60Percent = Above60Percent(grades, sz);
    printf("above60Percent:%.2f\n%", above60Percent);



    float arrA[] = {1, 3, 5};
    float arrB[] = {2, 4, 6, 8, 10};
    int sizeA = sizeof(arrA) / sizeof(arrA[0]);
    int sizeB = sizeof(arrB) / sizeof(arrB[0]);
    float merged[sizeA + sizeB];
    float mergedSorted[sizeA + sizeB];

    MergeArray(arrA, sizeA, arrB, sizeB, merged);
    PrintArr(merged, sizeA + sizeB);

    printf("MergeSortedArrays\n");
    MergeSortedArrays(arrA, sizeA, arrB, sizeB, mergedSorted);
    PrintArr(mergedSorted, sizeA + sizeB);

}
