#include"head.h"



void print(int *A){
	for(int i = 1;i<=A[0];i++){
		printf("%d ",A[i]);
	}
}
void build_progress(int *&A,int index){//index为第几组数据对应的二叉堆,限制1-5 
	char c[] = {"E:\\算法基础 顾乃杰\\PB17000285-project3\\ex1\\input\\data9\\build.txt"};
	/*data[x] x位于c[53]*/
	c[53] = '0'+index;

	FILE *f;
	f = fopen(c,"r");
	
	A = build(f);
	build_min_heap(A);
	fclose(f);
	
}
double insert_progress(int *A,int index){//index为第几组数据对应的二叉堆,限制1-5 
	char c[] = {"E:\\算法基础 顾乃杰\\PB17000285-project3\\ex1\\input\\data9\\insert.txt"};
	/*data[x] x位于c[53]*/
	c[53] = '0'+index; 
	FILE *f;
	f = fopen(c,"r");
	int insert_num = 0,temp;
	double total_insert_time = 0;
	fscanf(f,"%d",&insert_num);
	for(int i = 0;i<insert_num;i++){
		fscanf(f,"%d",&temp);
		time_count_start();
		min_heap_insert(A,temp);
		time_count_end();
		total_insert_time = total_insert_time + runTime;
		
	}
	fclose(f);
	return(total_insert_time/insert_num);
}
double decrease_progress(int *A,int index){
	char c[] = {"E:\\算法基础 顾乃杰\\PB17000285-project3\\ex1\\input\\data9\\decrease.txt"};
	c[53] = '0'+index; 
	FILE *f;
	f = fopen(c,"r");
	int decrease_num = 0,temp;
	double total_decrease_time = 0;
	fscanf(f,"%d",&decrease_num);
	for(int i = 0;i<decrease_num;i++){
		fscanf(f,"%d",&temp);
		time_count_start();
		heap_decrease_key(A,find_k(A,temp),temp-10);
		time_count_end();
		total_decrease_time = total_decrease_time + runTime;
		
	}
	fclose(f);
	return(total_decrease_time/decrease_num);
}

double delete_progress(int *A,int index){
	char c[] = {"E:\\算法基础 顾乃杰\\PB17000285-project3\\ex1\\input\\data9\\delete.txt"};
	c[53] = '0'+index; 
	FILE *f;
	f = fopen(c,"r");
	int delete_num = 0,temp;
	double total_delete_time = 0;
	fscanf(f,"%d",&delete_num);
	for(int i = 0;i<delete_num;i++){
		fscanf(f,"%d",&temp);
		time_count_start();
		heap_delete_key(A,find_k(A,temp));
		time_count_end();
		total_delete_time = total_delete_time + runTime;
		
	}
	fclose(f);
	return(total_delete_time/delete_num);	
}

double extract_progress(int *A,int index){
	char c1[] = {"E:\\算法基础 顾乃杰\\PB17000285-project3\\ex1\\input\\data9\\extract.txt"};
	c1[53] = '0'+index; 
	FILE *f;
	f = fopen(c1,"r");
	int extract_num = 0;
	double total_extract_time = 0;
	fscanf(f,"%d",&extract_num);
	fclose(f);
	
	char c2[]={"E:\\算法基础 顾乃杰\\PB17000285-project3\\ex1\\output\\result.txt"};
	f = fopen(c2,"a");
	fprintf(f,"data%d:\n",index);
	for(int i = 0;i<extract_num;i++){
		time_count_start();
		fprintf(f,"%d\n",heap_extract_min(A)); 
		time_count_end();
		total_extract_time = total_extract_time + runTime;
		
	}
	fclose(f);
	return(total_extract_time/extract_num);	
}

void pro(){
	int *A;
	FILE *f;
	f = fopen("E:\\算法基础 顾乃杰\\PB17000285-project3\\ex1\\output\\time.txt","w");
	for(int i =1;i<6;i++){
		fprintf(f,"data%d:\n",i);
		build_progress(A,i);
		fprintf(f,"insert:%.10lf\n",insert_progress(A,i));
		fprintf(f,"decrease:%.10lf\n",decrease_progress(A,i));
		fprintf(f,"delete:%.10lf\n",delete_progress(A,i));
		fprintf(f,"extract:%.10lf\n",extract_progress(A,i));
		fprintf(f,"\n");
	}
	fclose(f);
}

void test(){//一个验证四个操作正确性的例子 
	int A[] = {10,5,4,9,8,12,15,10,3,25,19,0,0,0,0,0,0};
	for(int i =1;i<=A[0];i++){
		printf("%d ",A[i]);
		
	}
	printf("\n");
	build_min_heap(A);
		for(int i =1;i<=A[0];i++){
		printf("%d ",A[i]);
		
	}
	printf("\n");
	printf("extract min %d\n",heap_extract_min(A));
		for(int i =1;i<=A[0];i++){
		printf("%d ",A[i]);
		
	}
	printf("\n");
	printf("extract min %d\n",heap_extract_min(A));
		for(int i =1;i<=A[0];i++){
		printf("%d ",A[i]);
		
	}
	printf("\n");
	min_heap_insert(A,1);
		for(int i =1;i<=A[0];i++){
		printf("%d ",A[i]);
		
	}
	printf("\n");
	min_heap_insert(A,11);
		for(int i =1;i<=A[0];i++){
		printf("%d ",A[i]);
		
	}
	printf("\n");
	min_heap_delete(A,1,25);
		for(int i =1;i<=A[0];i++){
		printf("%d ",A[i]);
		
	}
	printf("\n");
	min_heap_delete(A,1,11);
		for(int i =1;i<=A[0];i++){
		printf("%d ",A[i]);
		
	}
	printf("\n");
}
int main(){	
	pro();
}
