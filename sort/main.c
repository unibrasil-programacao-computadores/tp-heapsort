#include "sort.h"
#include "input.h"

int main()
{
//    sort_base_array(quicksort, "Quicksort");
//    sort_ordered_arrays(quicksort, "Quicksort");
//    sort_reverse_ordered_arrays(quicksort, "Quicksort");
//    sort_uniform_arrays(quicksort, "Quicksort");

    sort_base_array(heapsort, "Heapsort");
    sort_ordered_arrays(heapsort, "Heapsort");
    sort_reverse_ordered_arrays(heapsort, "Heapsort");
    sort_uniform_arrays(heapsort, "Heapsort");

    return 0;
}
