
int parent(int i){
	return(i/2);
}

int left(int i){

	return 2*i;
}

int right(int i){

	return 2*i+1;
}
void max_heapify(int* A, int i){
	int l = left(i);
	int r = right(i);
	int largest;
	if(l<=A[0]&&A[l]>A[i]){//A[0]存放此时A的size，A[1]开始存放数据 
		largest = l;

	}
	else largest = i;
	if(r<=A[0]&&A[r]>A[largest]){

		largest = r;
	} 
	if(largest!=i){

		exchange(&A[i],&A[largest]);
		max_heapify(A,largest);
	}
}

void build_max_heap(int* A, int t){
	A[0] = t;
	for(int i = t/2;i>0;i--){
		max_heapify(A,i);
	}
}

void heapsort(int* A, int t){
	build_max_heap(A,t);
	for(int i=t;i>1;i--){
		exchange(&A[1],&A[i]);
		A[0] = A[0] - 1;
		max_heapify(A,1);
	}
}

