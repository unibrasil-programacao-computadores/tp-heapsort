#include "sort.h"
#include "input.h"

int main()
{
//    sort_base_array(quicksort, "Quicksort");
//    sort_ordered_arrays(quicksort, "Quicksort");
//    sort_reverse_ordered_arrays(quicksort, "Quicksort");
//    sort_uniform_arrays(quicksort, "Quicksort");

//    sort_base_array(selectionsort, "Selectionsort");
//    sort_ordered_arrays(selectionsort, "Selectionsort");
//    sort_reverse_ordered_arrays(selectionsort, "Selectionsort");
//    sort_uniform_arrays(selectionsort, "Selectionsort");

    sort_base_array(insertionsort, "Insertionsort");
//    sort_ordered_arrays(insertionsort, "Insertionsort");
//    sort_reverse_ordered_arrays(insertionsort, "Insertionsort");
    sort_uniform_arrays(insertionsort, "Insertionsort");

//    sort_base_array(heapsort, "Heapsort");
//    sort_ordered_arrays(heapsort, "Heapsort");
//    sort_reverse_ordered_arrays(heapsort, "Heapsort");
//    sort_uniform_arrays(heapsort, "Heapsort");

    return 0;
}
