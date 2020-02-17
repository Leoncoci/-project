int* build(FILE *f){
	int length = 0;
	int *A;
	fscanf(f,"%d",&length);
	A = (int*)malloc(sizeof(int)*(600));
	A[0] = length;//length保存在A[0] 
	for(int i = 1;i<=length;i++){
		fscanf(f,"%d",&A[i]);
		
	}
	return A;
}
void min_heapify(int* A,int i){
	int l=left(i);
	int r = right(i);
	int smallest;
	if(l<=A[0]&&A[l]<A[i])
		smallest = l;
	else smallest = i;
	if(r<=A[0]&&A[r]<A[smallest])
		smallest = r;
	
	
	if(smallest!=i){
		exchange(&A[i],&A[smallest]);
		min_heapify(A,smallest);
	}
		
}

void build_min_heap(int *A){
	for(int i = A[0]/2;i>=1;i--){
		min_heapify(A,i);
	} 
}
int heap_extract_min(int *A){
	if(A[0]<1)
		printf("heap overflow!\n");
	int min = A[1];
	A[1] = A[A[0]];
	A[0]=A[0]-1;
	min_heapify(A,1);
	return min;
}
int find_k(int *A, int k){//找到关键字为k的数据位置 
	for(int i = 1;i<=A[0];i++){
		if(A[i]==k)
			return i;
	}
}
void heap_decrease_key(int *A, int i,int key){
	if(key>A[i])
		printf("new key is larger than current key\n");
	A[i] = key;
	while(i>1&&A[parent(i)]>A[i]){
		exchange(&A[i],&A[parent(i)]);
		i = parent(i);
	}
		
}
void heap_delete_key(int *A,int i){
	heap_decrease_key(A,i,-1);
	heap_extract_min(A);
} 
void min_heap_insert(int *A,int key){
	A[0] = A[0]+1;
	A[A[0]] = MAX_INT;
	heap_decrease_key(A,A[0],key);
}
void min_heap_delete(int *A,int i,int key){

	if(A[i]==key){
		heap_delete_key(A,i);
		return;
	}
	else{
		if(left(i)<=A[0])
			min_heap_delete(A,left(i),key);
		if(right(i)<=A[0])
			min_heap_delete(A,right(i),key);
	}
} 
