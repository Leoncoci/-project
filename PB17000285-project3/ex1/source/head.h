#ifndef HEAD_H
#define HEAD_H
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>



#define BIG_DOUBLE 10000
#define N 50
/*����״̬*/ 
#define ZS 111
#define Z 121
#define S 131
#define MAX_INT 2147483647
/*������ʱ��ȫ�ֱ���*/ 
LARGE_INTEGER litmp;
double frequency,runTime,minus;
LONGLONG timeStart,timeEnd;
int flag;
void time_count_start(){//��ʼ��ʱ 
	QueryPerformanceFrequency(&litmp);
  	frequency=(double) litmp.QuadPart;
  	QueryPerformanceCounter(&litmp);
  	timeStart=litmp.QuadPart;
}
void time_count_end(){	//������ϴμ�ʱ������������ʱ�� 
	QueryPerformanceCounter(&litmp);
 	timeEnd=litmp.QuadPart;
 	minus=(double)(timeEnd-timeStart);
 	runTime=minus/frequency;
}

FILE *f;

int parent(int i){
	return i/2;
}
int left(int i){
	return 2*i;
}
int right(int i){
	return 2*i+1;
}
void exchange(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
//	printf("%d,%d\n",*a,*b);
}

#include"min_heap.cpp"
#endif 
