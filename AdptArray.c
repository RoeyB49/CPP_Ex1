// CPP_Ex1
// Roey Biton
// 313137150

#include "AdptArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct AdptArray_ {
    int ArrSize;
    PElement* pElemArr;
    DEL_FUNC delFunc;
    COPY_FUNC copyFunc;
    PRINT_FUNC printFunc;
} AdptArray_;

// This function creates a new AdptArray object by allocating memory and initializing its fields. 
// The function returns a pointer to the new object, which can be used to store elements and perform copy, delete, and print.

PAdptArray CreateAdptArray(COPY_FUNC copy, DEL_FUNC del, PRINT_FUNC print) {
    PAdptArray arr = malloc(sizeof(struct AdptArray_));

    // allocates memory on the heap for an array of pointers to elements.
    // In this case, the array size is set to 10.
    arr->pElemArr = malloc(10 * sizeof(PElement));
    if (!arr->pElemArr) {
        perror("Could not allocate memory for AdptArray");
        exit(EXIT_FAILURE);
    }
    // Sets the size of the array to 0 and assigns the three function pointers passed as arguments to their fields.
    arr->ArrSize = 0;
    arr->delFunc = del;
    arr->copyFunc = copy;
    arr->printFunc = print;
    return arr;
}
// This function deletes an AdptArray object. 
void DeleteAdptArray(PAdptArray arr) {
    if (arr == NULL) {

        return;

    }
    for (int i = 0; i < arr->ArrSize; i++) {

        if(arr->pElemArr[i] != NULL)
           arr->delFunc(arr->pElemArr[i]);

    }
    // freeing the memory allocated for the elements and the object.
    free(arr->pElemArr);
    free(arr);
}


// This function sets an element in the array at a specified index.
Result SetAdptArrayAt(PAdptArray arr, int index, PElement data) {
    // checks if the arr pointer is NULL.
    if (arr == NULL)
        return FAIL;

    if (index >= arr->ArrSize) {
        // make sure that the array is large enough, handles any of the elements at the index, 
        PElement* newpElemArr = (PElement*)realloc(arr->pElemArr, (index + 1) * sizeof(PElement));
        if (newpElemArr == NULL)
            return FAIL;
        arr->pElemArr = newpElemArr;

        for (int i = arr->ArrSize; i <= index; i++) {
            arr->pElemArr[i] = NULL;
        }
        arr->ArrSize = index + 1;
    }
    if (arr->pElemArr[index] != NULL)
        arr->delFunc(arr->pElemArr[index]);
        // create a copy of the data to avoid modifying the original
    arr->pElemArr[index] = arr->copyFunc(data);
    return SUCCESS;
}
// This function retrieves the element at a specified index in the array, 
PElement GetAdptArrayAt(PAdptArray arr, int index) {
    // If the element at the index is NULL or the index is outside the bounds, it returns NULL.
     if(arr->pElemArr[index]==NULL || arr-> ArrSize< index)
    {

        return NULL;

    }
    PElement elemntAt;
    // create a copy of the element and returns it. 
    elemntAt=arr->copyFunc(arr->pElemArr[index]);

    return  elemntAt;
}
// This function returns the current size of the array held by the AdptArray object.
int GetAdptArraySize(PAdptArray arr)
{
    if (arr == NULL)
    {
        return -1;
    }
    return arr->ArrSize;
}
// This function prints the non-null elements of a dynamically allocated array of pointers.
void PrintDB(PAdptArray arr) {
    if (arr == NULL) {
        return;
    }

    for (int i = 0; i < arr->ArrSize; i++) {

        if (arr->pElemArr[i] != NULL) {

            arr->printFunc(arr->pElemArr[i]);

        }
    }
}
