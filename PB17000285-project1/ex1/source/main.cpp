#include"sort.h"
/*计算四种排序对2^n规模的数据所用时间*/ 
double n_time(int n, int index){
	FILE* f;
	f = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\input\\input_strings.txt","r");
	if(!f)
		printf("file open error!\n");
	
	int t = (int)pow(2,(double)n);
	int *A = (int*)malloc(sizeof(int) * (t + 1) );
	int *B = (int*)malloc(sizeof(int) * (t + 1) );//计数排序所用输出数组 
	
	for(int i=1;i<=t;i++){
		fscanf(f,"%d\n",&A[i]);
	}
	fclose(f);
	
	time_count_start();
	switch(index){
		case 1: heapsort(A,t);break;
		case 2: merge_sort(A,1,t);break;
		case 3: quick_sort(A,1,t);break;
		case 4: counting_sort(A,B,t);break;//略有修改，t表示数据规模 
		default: return 0;
	}
	time_count_end();

	FILE *ff;
	switch(index){
		case 1: {
			switch(n){
				case 3: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\heap_sort\\result_3.txt","w");break;
				case 5: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\heap_sort\\result_5.txt","w");break;
				case 7: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\heap_sort\\result_7.txt","w");break;
				case 9: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\heap_sort\\result_9.txt","w");break;
				case 11: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\heap_sort\\result_11.txt","w");break;
				case 13: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\heap_sort\\result_13.txt","w");break;
				case 15: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\heap_sort\\result_15.txt","w");break;
				default :return 0;
			}
			break;
		}break;
		case 2:{
			switch(n){
				case 3: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\merge_sort\\result_3.txt","w");break;
				case 5: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\merge_sort\\result_5.txt","w");break;
				case 7: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\merge_sort\\result_7.txt","w");break;
				case 9: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\merge_sort\\result_9.txt","w");break;
				case 11: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\merge_sort\\result_11.txt","w");break;
				case 13: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\merge_sort\\result_13.txt","w");break;
				case 15: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\merge_sort\\result_15.txt","w");break;
				default :return 0;
			}
			break;
		}break;
		case 3:{
			switch(n){
				case 3: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\quick_sort\\result_3.txt","w");break;
				case 5: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\quick_sort\\result_5.txt","w");break;
				case 7: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\quick_sort\\result_7.txt","w");break;
				case 9: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\quick_sort\\result_9.txt","w");break;
				case 11: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\quick_sort\\result_11.txt","w");break;
				case 13: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\quick_sort\\result_13.txt","w");break;
				case 15: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\quick_sort\\result_15.txt","w");break;
				default :return 0;
			}
			break;
		}break;
		case 4:{
			switch(n){
				case 3: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\counting_sort\\result_3.txt","w");break;
				case 5: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\counting_sort\\result_5.txt","w");break;
				case 7: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\counting_sort\\result_7.txt","w");break;
				case 9: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\counting_sort\\result_9.txt","w");break;
				case 11: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\counting_sort\\result_11.txt","w");break;
				case 13: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\counting_sort\\result_13.txt","w");break;
				case 15: ff = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\counting_sort\\result_15.txt","w");break;
				default :return 0;
			}
			break;
		}break;
		default:return 0;
	}
	
	if(index == 4){
		for(int i=1;i<=t;i++){
	//	printf("%d\n",A[i]);
		fprintf(ff,"%d\n",B[i]);
		}
	}
	else{
		for(int i=1;i<=t;i++){
	//	printf("%d\n",A[i]);
		fprintf(ff,"%d\n",A[i]);
		}
	
	}
	fclose(ff);
	free(A);
	free(B);
	return runTime;
}
/*四种算法运行过程*/ 
void pro(int index){//index表示选用的算法 
	FILE* f;
	switch(index){
		case 1:f = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\heap_sort\\time.txt","a");break;
		case 2:f = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\merge_sort\\time.txt","a");break;
		case 3:f = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\quick_sort\\time.txt","a");break;
		case 4:f = fopen("E:\\算法基础 顾乃杰\\PB17000285-project1\\ex1\\output\\counting_sort\\time.txt","a");break;
		default:break;
	}
	/*时间数据存放格式为：time（a1,a2,a3,a4,a5,a6） 其中an为2^n规模下的运行时间*/ 
	/*该存放格式有利于宏展开的实现^-^*/ 
	if(!f)
		printf("file open error!\n");
	int temp = 2;
	fprintf(f,"%s%c","time",'(');
	for(int i=1;i<7;i++){
		fprintf(f,"%lf%c",n_time(i*temp+1,index),',');
	}
	fprintf(f,"%lf",n_time(7*temp+1,index));
	fprintf(f,"%c\n",')');
	fclose(f);
}
int main(){
	
	for(int j = 0;j<Ntime;j++){
		for(int i = 1;i<5;i++){
			pro(i);
		}
	}

}
