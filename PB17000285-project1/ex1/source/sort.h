#ifndef SORT_H
#define SORT_H
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>


#define Ntime 50//����ʵ������������ƽ��ֵ 
#define MAX_INT 2147483647
#define time(a1,a2,a3,a4,a5,a6,a7) {a1,a2,a3,a4,a5,a6,a7}, //����time.txt�Ĵ�Ÿ�ʽ���к�չ�� 
/*������ʱ��ȫ�ֱ���*/ 
LARGE_INTEGER litmp;
double frequency,runTime,minus;
LONGLONG timeStart,timeEnd;

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
/*��������int��Ԫ������*/ 
void exchange(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
#include"merge_sort.cpp"
#include"heap_sort.cpp"
#include"quick_sort.cpp"
#include"counting_sort.cpp"
#endif 
