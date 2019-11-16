bool binary_search(int arr[], int l, int r, int x){//iterative

	while(l <= r){
		int mid=(l + r)/2;

     if(a[mid]<x)  l = mid+1;

     else if(a[mid]>x){
         r=mid-1;
     }

     else{
         return mid;
     }
   }
   return -1;                
 }



bool exotic_binary_search(int x[], int n, int x) {//other implementation
    int p = 0;
    for (int a = n; a >= 1; a /= 2) {
        while (p+a < n && x[p+a] <= x) p += a;
    }
    return x[p] == x;
}

//ternary search

int ternary_search(int arr[], int n, int x){//iterative
	int low = 0, high = n - 1;
	while (low <= high){

		int l_mid = low + (high - low) / 3;
		int r_mid = high - (high - low) / 3;

		if (arr[l_mid] == x)
			return l_mid;

		else if (arr[r_mid] == x)
			return r_mid;

		else if (arr[l_mid] > x)
			high = l_mid - 1;

		else if (arr[r_mid] < x)
			low = r_mid + 1;

		else
			low = l_mid + 1, high = r_mid - 1;
	}

	return -1;
}
