
void merge(int* A, int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L,*R;
	int i,j,k;
	L = (int*)malloc(sizeof(int) * (n1+2));
	R = (int*)malloc(sizeof(int) * (n2+2));
	for(i=1;i<=n1;i++){
		
		L[i] = A[p+i-1];
	}
	for(j=1;j<=n2;j++){
		R[j] = A[q+j];
	}
	L[n1+1]=MAX_INT;
	R[n2+1]=MAX_INT;
	i = 1;
	j = 1;
	for(k=p;k<=r;k++){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i=i+1;
		}
		else{
			A[k] = R[j];
			j=j+1;
		}
	}
	free(L);
	free(R);
}
void merge_sort(int* A,int p, int r){//从1到2^n的归并排序 
	if(p<r){
		int q = (p+r)/2;
	//	printf("%d,%d,%d\n",p,r,q);
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		
		merge(A,p,q,r);
		
	}
}/*
double n_time(int n){
	FILE* f;
	f = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\input\\input_strings.txt","r");
	if(!f)
		printf("file open error!\n");
	
	int t = (int)pow(2,(double)n);
	int *A = (int*)malloc(sizeof(int) * (t + 1) );
	
	for(int i=1;i<=t;i++){
		fscanf(f,"%d\n",&A[i]);
	}
	fclose(f);
	
	time_count_start();
	merge_sort(A,1,t);
	time_count_end();
	
	printf("%lf\n",runTime);
	FILE *ff;
	
	
	for(int i=1;i<=t;i++){
	//	printf("%d\n",A[i]);
		fprintf(ff,"%d\n",A[i]);
	}
	fclose(ff);
	free(A);
	return runTime;
}*/
/*
int main(){


	pro();
}*/
