#ifndef SORT_H
#define SORT_H
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>


#define Ntime 50//定义实验次数，最后求平均值 
#define MAX_INT 2147483647
#define time(a1,a2,a3,a4,a5,a6,a7) {a1,a2,a3,a4,a5,a6,a7}, //利用time.txt的存放格式进行宏展开 
/*申明计时用全局变量*/ 
LARGE_INTEGER litmp;
double frequency,runTime,minus;
LONGLONG timeStart,timeEnd;

void time_count_start(){//开始计时 
	QueryPerformanceFrequency(&litmp);
  	frequency=(double) litmp.QuadPart;
  	QueryPerformanceCounter(&litmp);
  	timeStart=litmp.QuadPart;
}
void time_count_end(){	//计算从上次计时到结束的运行时间 
	QueryPerformanceCounter(&litmp);
 	timeEnd=litmp.QuadPart;
 	minus=(double)(timeEnd-timeStart);
 	runTime=minus/frequency;
}
/*交换俩个int单元的数据*/ 
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
