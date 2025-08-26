#include "ArrayUtils.h"

#include <stdio.h>
#include <stdlib.h>

void Sort(float arr[], int size) {
    // simple bubble sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void CopyArray(float source[], float copy[], int size) {
    for (int i = 0; i < size; i++) {
        copy[i] = source[i];
    }
}

void Factor(float arr[], int size, float value) {
    // arr transferred by reference (same value, by pointer)
    for (int i = 0; i < size; ++i) {
        arr[i] += value;
    }
}

float Average(float arr[], int size) {
    float sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    float avg = sum / (float) size;
    return avg;
}

void PrintArr(float arr[], int size) {
    printf("[");

    if (size > 0) {
        printf("%.2f", arr[0]);
        for (int i = 1; i < size; ++i) {
            printf(", %.2f", arr[i]);
        }
    }

    printf("]\n");
}

float Median(float arr[], int size) {
    float copyArr[size];
    CopyArray(arr, copyArr, size);

    Sort(copyArr, size);

    float median;
    if (size % 2 == 0) {
        // even: average of two middle values
        median = (copyArr[size / 2 - 1] + copyArr[size / 2]) / 2.0f;
    } else {
        // odd: the middle value
        median = copyArr[size / 2];
    }

    return median;
}

int Find(float arr[], int size, float value) {
    int i = 0;
    while (i < size) {
        if (arr[i] == value) {
            return 1;
        }
        i++;
    }

    return 0;
}

void Hit(float arr[], int size, float value) {
    int i = 0;
    while (i < size) {
        if (arr[i] == value) {
            printf("Hit\n");
            return;;
        }
        i++;
    }

    printf("Sorry\n");
}

// return -1 if array is empty
// return -2 if someone not tested
// return -3 if found fake grade
float Above60Percent(float arr[], int size) {
    if (size <= 0) {
        return -1;
    }

    int isEveryoneTested = 1;
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            isEveryoneTested = 0;
            break;
        }
    }
    if (isEveryoneTested == 0) {
        return -2;
    }

    int foundFakeGrade = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 100) {
            foundFakeGrade = 1;
            break;
        }
    }
    if (foundFakeGrade == 1) {
        return -3;
    }

    int above60Sum = 0;
    for (int i = 0; i < size; ++i) {
        above60Sum += (arr[i] >= 60) ? 1 : 0;
    }

    float above60Percent = (float) above60Sum / (float) size;
    above60Percent *= 100.0;

    return above60Percent;
}

void MergeArray(float a[], int sa, float b[], int sb, float merged[]) {
    for (int i = 0; i < sa; ++i) {
        merged[i] = a[i];
    }

    for (int i = 0; i < sb; ++i) {
        merged[i + sa] = b[i];
    }
}

void MergeSortedArrays(float a[], int sa, float b[], int sb, float merged[]) {
    int i = 0; // index a
    int j = 0; // index b
    int m = 0; // index merged

    while (i < sa && j < sb) {
        if (a[i] > b[j]) {
            merged[m++] = b[j++]; // increase j after insert
        } else {
            merged[m++] = a[i++];
        }
    }

    // for (    ; j < sb;     ) {
    //     merged[m++] = b[j++];
    // }

    while (i < sa) { merged[m++] = a[i++]; }
    while (j < sb) { merged[m++] = b[j++]; }
}


//
// get two arrays and return 1 oor 2 depends on which array's average is greater
