
int partition(int* A, int p, int r){
	int x = A[r];
	int i = p - 1,j;
	for(j = p;j<=r-1;j++){
		if(A[j]<=x){
			i = i+1;
			exchange(&A[i],&A[j]);
		}
	}
	exchange(&A[i+1],&A[r]);
	return (i+1);
}

void quick_sort(int* A, int p, int r){
	if(p<r){
		int q = partition(A,p,r);
		quick_sort(A,p,q-1);
		quick_sort(A,q+1,r);
	}
}
