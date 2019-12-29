#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int>entry;

void swap(int index1, int index2) {
	int tmp = entry[index1];
	entry[index1] = entry[index2];
	entry[index2] = tmp;

}


int partition(int low, int high)
/* Pre: low and high are valid positions of the Sortable list, with low <= high.
Post: The center (or left center) entry in the range between indices low and high of
the Sortable list has been chosen as entry pivot. All entries of the Sortable list
between indices low and high, inclusive, have been rearranged so that those
with keys less than the pivot come before the pivot and the remaining entries
come after the pivot. The final position of the pivot is returned.
Uses: swap(int i, int j) (interchanges entries in positions i and j of entry Sortable list),
the contiguous List implementation of Chapter 6, and methods for the class
int. */
{
	int pivot;
	int i, // used to scan through the list
		last_small; // position of the last key less than pivot
	pivot = entry[low]; // First entry is now pivot.
	last_small = low;
	for (i = low + 1; i <= high; i++)
		/* At the beginning of each iteration of this loop, we have the following conditions:
		If low < j <= last_small then entry[j].key < pivot.
		If last_small < j < i then entry[j].key >= pivot. */
		if (entry[i] < pivot) {
			last_small = last_small + 1;
			swap(last_small, i); // Move large entry to right and small to left.
		}
	swap(low, last_small); // Put the pivot into its proper position.
	return last_small;
}





void  recursive_quick_sort(int low, int high)
/* Pre: low and high are valid positions in the Sortable list.
Post: The entries of the Sortable list have been rearranged so that their keys
are sorted into nondecreasing order.
Uses: Contiguous List implementation of Chapter 6, recursive quick sort,
and partition. */
{
	int pivot_position;
	if (low < high) { // Otherwise, no sorting is needed.
		pivot_position = partition(low, high);
		for (int i = 0; i < entry.size(); i++)
			cout << entry[i] << ' ';
		cout << endl;

		recursive_quick_sort(low, pivot_position - 1);
		recursive_quick_sort(pivot_position + 1, high);
	}




}



int main()
{
	int tmp;
	while (cin >> tmp)
		entry.push_back(tmp);
	
	recursive_quick_sort(0, entry.size() - 1);


	return 0;
}
