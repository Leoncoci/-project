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
	runTime = 0;
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

/*����������**/
char T[5][132000];
char P[5][65]; 
int plen[5] = {4,8,16,32,64};
int tlen[5] = {32,256,2048,16384,131072};
#endif 
#include"naive.cpp"
#include"rabin_karp.cpp"
#include"kmp.cpp"
#include"boyer_moore_horspool.cpp" 
