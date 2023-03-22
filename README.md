# CPP_Ex1
In this assignment, I will implement a general adaptive array in the C programming language.

An adaptive array is an array that changes its size so that every non-negative index access is valid.

# A summary about the implementation of the code:

* The array holds elements of type PElement, which is a pointer to any type of data.

* The **CreateAdptArray** function allocates memory for the array and initializes its fields, including three function pointers to handle copying, deleting, and printing the elements.

* The **DeleteAdptArray** function frees the memory allocated for the array and its elements.

* The **SetAdptArrayAt** function sets an element at a specified index in the array, dynamically resizing the array if necessary.

* The **GetAdptArrayAt** function retrieves an element at a specified index in the array and returns a copy of it.

* The **GetAdptArraySize** function returns the current size of the array.

* The **PrintDB** function prints the non-null elements in the array using the print function pointer.
