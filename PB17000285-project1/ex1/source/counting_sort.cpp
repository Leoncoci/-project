
counting_sort(int* A,int* B, int t){
	int *C = (int*)malloc(sizeof(int) * 65537 ); 
	for(int i = 0;i<=65535;i++){
		C[i] = 0;
	} 
	for(int j = 1;j<=t;j++){
		C[A[j]] = C[A[j]] + 1;
	}//C[i] ���ڴ�Ÿ���Ԫ�صĸ���
	for(int i = 1;i<=65535;i++){
		C[i] = C[i] + C[i-1];
	} //C[i] ���ڴ��С��i��Ԫ�صĸ���
	for(int j = t;j>0;j--){
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]] - 1;
	} 
	
}
