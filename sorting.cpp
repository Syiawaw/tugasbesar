#include <iostream>
using namespace std;

//mungkin untuk sorting enaknya buat ngurutin pemesanan tempat duduk di bioskop
//semisal pemesanan acak dan butuh diurutin bisa lah
void BubbleSort(int array[], int n) {
	// Ascending
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(array[j] > array[j+1])
                swap(array[j], array[j+1]);

	//descending
	for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(array[j] < array[j+1])
                swap(array[j], array[j+1]);

}
void selectionSort(int array[],int n)
{
	//ascending
	for(int i = 0; i < n-1; i++) {
        int min_index = i;
        for(int j = i+1; j < n; j++)
            if(array[j] < array[min_index])
                min_index = j;
        swap(array[i], array[min_index]);
}

	//descending
	    for(int i = 0; i < n-1; i++) {
        int max_index = i;
        for(int j = i+1; j < n; j++)
            if(array[j] > array[max_index])
                max_index = j;
        swap(array[i], array[max_index]);
    }
}