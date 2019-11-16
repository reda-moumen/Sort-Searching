//swap -> STL
//insertion sort

void insertion_sort1(int arr[], int n){//iterative
	for (int i = 1; i < n; i++){
		int value = arr[i];
		int j = i;
		while (j > 0 && arr[j - 1] > value){
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = value;
	}
}

void insertion_sort2(int arr[], int i, int n){ //recursive
	int value = arr[i];
	int j = i;
	while (j > 0 && arr[j - 1] > value){
		arr[j] = arr[j - 1];
		j--;
	}
	arr[j] = value;
	if (i + 1 <= n) {
		insertion_sort2(arr, i + 1, n);
	}
}

//selection sort

void selection_sort1(int arr[], int n){//iterative
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++){
			if (arr[j] < arr[min])
				min = j;
		}
		swap(arr[min],arr[i]);
	}
}

void selection_sort2(int arr[], int i, int n){//recursive

	int min = i;
	for (int j = i + 1; j < n; j++){
		if (arr[j] < arr[min])
			min = j;
	}
	swap(arr[min], arr[i]);
	if (i + 1 < n) {
		selection_sort2(arr, i + 1, n);
	}
}

//bubble sort

void bubble_sort1(int arr[], int n){//iterative

	for (int k = 0; k < n - 1; k++){
		for (int i = 0; i < n - 1 - k; i++){
			if (arr[i] > arr[i + 1]) {
				swap(arr[i],arr[i + 1]);
			}
		}
	}
}

void bubble_sort2(int arr[], int n){//recusive

	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			swap(arr[i],arr[i + 1]);
		}
	}
	if (n - 1 > 1) {
		bubble_sort2(arr, n - 1);
	}
}

//merge sort

void merge(int *arr, int l, int r, int mid){//helper

    int i = l, j = mid + 1, t = 0;
	int temp[r - l + 1];

	while (i <= mid && j <= r) {
		if (arr[i] < arr[j])
			temp[t++] = arr[i++];
		else
			temp[t++] = arr[j++];
	}

	while (j <= r)	temp[t++] = arr[j++];
	while (i <= mid)	temp[t++] = arr[i++];

	for (t = 0; t < r-l+1; t++)
		arr[l+t] = temp[t];

}

void merge_sort1(int *arr, int l, int r){//recursive

    if(l >= r) return;

    int mid=(l + r)/2;
    merge_sort1(arr,l,mid);
    merge_sort1(arr,mid+1,r);
    merge(arr,l,r,mid);

}

void merge_sort2(int arr[], int n){//iterative

   int curr_size;
   int l;
   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size) {

       for (l=0; l<n-1; l += 2*curr_size){

           int mid = min(l + curr_size - 1, n-1);
           int r = min(l + 2*curr_size - 1, n-1);
           merge(arr, l, r, mid);
       }
   }
}

//quick_sort

int partition_(int a[], int start, int end){//helper

    int pivot = a[end];
	int pIndex = start; //pIndex = partition index

	for (int i = start; i < end; i++){
		if (a[i] <= pivot){
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}

	swap (a[pIndex], a[end]);
	return pIndex;
}



void quick_sort(int a[] ,int start, int end){//recursive

	if (start >= end) return;

	int pivot = partition_(a, start, end);
	quick_sort(a, start, pivot - 1);
	quick_sort(a, pivot + 1, end);

}
