#include"sort.h"
/*�������������2^n��ģ����������ʱ��*/ 
double n_time(int n, int index){
	FILE* f;
	f = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\input\\input_strings.txt","r");
	if(!f)
		printf("file open error!\n");
	
	int t = (int)pow(2,(double)n);
	int *A = (int*)malloc(sizeof(int) * (t + 1) );
	int *B = (int*)malloc(sizeof(int) * (t + 1) );//������������������� 
	
	for(int i=1;i<=t;i++){
		fscanf(f,"%d\n",&A[i]);
	}
	fclose(f);
	
	time_count_start();
	switch(index){
		case 1: heapsort(A,t);break;
		case 2: merge_sort(A,1,t);break;
		case 3: quick_sort(A,1,t);break;
		case 4: counting_sort(A,B,t);break;//�����޸ģ�t��ʾ���ݹ�ģ 
		default: return 0;
	}
	time_count_end();

	FILE *ff;
	switch(index){
		case 1: {
			switch(n){
				case 3: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\heap_sort\\result_3.txt","w");break;
				case 5: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\heap_sort\\result_5.txt","w");break;
				case 7: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\heap_sort\\result_7.txt","w");break;
				case 9: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\heap_sort\\result_9.txt","w");break;
				case 11: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\heap_sort\\result_11.txt","w");break;
				case 13: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\heap_sort\\result_13.txt","w");break;
				case 15: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\heap_sort\\result_15.txt","w");break;
				default :return 0;
			}
			break;
		}break;
		case 2:{
			switch(n){
				case 3: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\merge_sort\\result_3.txt","w");break;
				case 5: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\merge_sort\\result_5.txt","w");break;
				case 7: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\merge_sort\\result_7.txt","w");break;
				case 9: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\merge_sort\\result_9.txt","w");break;
				case 11: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\merge_sort\\result_11.txt","w");break;
				case 13: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\merge_sort\\result_13.txt","w");break;
				case 15: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\merge_sort\\result_15.txt","w");break;
				default :return 0;
			}
			break;
		}break;
		case 3:{
			switch(n){
				case 3: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\quick_sort\\result_3.txt","w");break;
				case 5: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\quick_sort\\result_5.txt","w");break;
				case 7: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\quick_sort\\result_7.txt","w");break;
				case 9: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\quick_sort\\result_9.txt","w");break;
				case 11: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\quick_sort\\result_11.txt","w");break;
				case 13: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\quick_sort\\result_13.txt","w");break;
				case 15: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\quick_sort\\result_15.txt","w");break;
				default :return 0;
			}
			break;
		}break;
		case 4:{
			switch(n){
				case 3: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\counting_sort\\result_3.txt","w");break;
				case 5: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\counting_sort\\result_5.txt","w");break;
				case 7: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\counting_sort\\result_7.txt","w");break;
				case 9: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\counting_sort\\result_9.txt","w");break;
				case 11: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\counting_sort\\result_11.txt","w");break;
				case 13: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\counting_sort\\result_13.txt","w");break;
				case 15: ff = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\counting_sort\\result_15.txt","w");break;
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
/*�����㷨���й���*/ 
void pro(int index){//index��ʾѡ�õ��㷨 
	FILE* f;
	switch(index){
		case 1:f = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\heap_sort\\time.txt","a");break;
		case 2:f = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\merge_sort\\time.txt","a");break;
		case 3:f = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\quick_sort\\time.txt","a");break;
		case 4:f = fopen("E:\\�㷨���� ���˽�\\PB17000285-project1\\ex1\\output\\counting_sort\\time.txt","a");break;
		default:break;
	}
	/*ʱ�����ݴ�Ÿ�ʽΪ��time��a1,a2,a3,a4,a5,a6�� ����anΪ2^n��ģ�µ�����ʱ��*/ 
	/*�ô�Ÿ�ʽ�����ں�չ����ʵ��^-^*/ 
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
