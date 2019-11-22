
counting_sort(int* A,int* B, int t){
	int *C = (int*)malloc(sizeof(int) * 65537 ); 
	for(int i = 0;i<=65535;i++){
		C[i] = 0;
	} 
	for(int j = 1;j<=t;j++){
		C[A[j]] = C[A[j]] + 1;
	}//C[i] 现在存放各个元素的个数
	for(int i = 1;i<=65535;i++){
		C[i] = C[i] + C[i-1];
	} //C[i] 现在存放小于i的元素的个数
	for(int j = t;j>0;j--){
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]] - 1;
	} 
	
}
