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




int& median3(int left, int right)
{
	int center = (left + right) / 2;
	if (entry[center] < entry[left])
		swap(left, center);
	if (entry[right] < entry[left])
		swap(left, right);
	if (entry[right] < entry[center])
		swap(right, center);
	swap(center, right - 1);
	return entry[right - 1];
}


void myqsort(int left, int right)
{
	if (left + 3 <= right)
	{
		const int& pivot = median3(left, right);
		int i = left, j = right - 1;
		for (;;)
		{
			while (entry[++i] < pivot);
			while (entry[--j] > pivot);
			if (i < j)
				swap(i, j);
			else
				break;
		}
		swap(i, right - 1);

		for (int i = 0; i < entry.size(); i++)
			cout << entry[i] << ' ';
		cout << endl;

		myqsort(left, i - 1);
		myqsort(i + 1, right);

	}
	else
		sort(entry.begin() + left, entry.begin() + right + 1);
}


int main()
{
	int tmp;
	while (cin >> tmp)
		entry.push_back(tmp);
	
	myqsort(0, entry.size() - 1);


	return 0;
}
