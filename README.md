# 0-1-Array-Connected-Components_Memory-Efficient_C-Pointers
An algorithm in C for finding connected components (based on side and corner neighbourings) that is efficient in memory usage for most cases.

## What is in the code?
cells.c: Contains the definitions of the used functions. The primary function is the "BiggestComponentSize" function, that takes in a 2D array (its dimensions given), and after finding each (disjoint) component in the matrix, returns the size of the biggest one.
... TBA

cells.h: Contains the declarations of the used functions, and the structs.
A main.c file with a main function, that tests the component finding algorithm with a few <img src="https://latex.codecogs.com/svg.image?&space;N&space;\times&space;M" /> matrices.

## How the algorithm works:

-First, we make a linked list of the cells that contain 1. (GetOnes)

-Then, we reorder them in the list such that cells in one blob are packed together in the list(CoupleCellsTogether). The list is continuosly rearranged until all cells in one blob are "neighbours" in the list, making up a "blob" in the linked list, this way we're filling up blobs until there are no more neighbours. After completing a blob (no more cells can be added to it), the last cell added will be the "border", its index is stored in another list. 

-The biggest size then can be easily evaluated from the differences of consecutive borders.

### (Visualization) More soon...
