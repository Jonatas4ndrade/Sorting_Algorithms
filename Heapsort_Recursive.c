#include <stdio.h>

void heap_assembler(int i, int end, int heap[], int direction);
void heap_sort(int end, int heap[]); //  Uses heap_assembler to reverse sort an array.

int main()
{
    int mess[15] = {5, 2, 13, 4, 6, 1, 7, 9, 11, 8, 10, -22, 12, 3, -2};
    heap_sort(15, mess);

    //Prints sorted array.
    for (int c = 0; c < 15; c++)
    {
        printf("%d ", mess[c]);
    }
}

void heap_sort(int end, int heap[])
{

    // Recursion maketh the heap.
    for (int c = end; c > 0; c--)
    {
        heap_assembler(c, end, heap, 0);
    }

    // Sorts the heap.
    for (int c = end; c > 0; c--)
    {
        // Swaps first and last.
        int swapper = heap[end -1];

        heap[end -1] = heap[0];
        heap[0] = swapper;

        // Reduces heap size and puts the swapped element in correct position.
        end--;
        heap_assembler(1, end, heap, 1);

    }
}

void heap_assembler(int i, int end, int heap[], int direction)
{

// This functions receives:
// a) target element of heap (int) | b) heap size (int) | c) an array | d) direction flag – 0 for down-top or positive int for top-down
// It will swap given element to correct position, regarding a min-heap. Works in-place.

//Starts with recursion check to avoid chance of segmentation fault during variables declarations.

    // Root reached, ends recursive call.
    if (direction == 0 && i == 1)
    {
        return;
    }

    // Last leaf reached, ends recursive call (if reverse flag is set)
    if (direction > 0 && i * 2 > end)
    {
        return;
    }

    int parent;
    direction == 0 ? (parent = i/2) : (parent = i);

    int child;
    direction == 0 ? (child = i) : (child = i * 2);

    int sibling = 0;
    int swapper = heap[parent-1];

    // Checks if child has no siblings.
    if (!(child == end && child % 2 == 0))
    {
        // If the sibling is smaller, takes child's place.
        child % 2 !=  0 ? (sibling = child - 1) : (sibling = child + 1);
        heap[child -1] > heap[sibling-1] ? child = sibling : 0;
    }

    // If parent is bigger, swaps with child.
    if (heap[parent - 1] > heap[child -1])
    {
        heap[parent -1] = heap[child -1];
        heap[child - 1] = swapper;
    }

    // Recursive call until root / deepest level if reverse flag is set.
    direction == 0 ? heap_assembler(i/2, end, heap, 0) : heap_assembler(child, end, heap, 1);
}
