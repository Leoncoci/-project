#ifndef HEAD_H
#define HEAD_H
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>



#define BIG_DOUBLE 10000
#define N 50 
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

//全局数组存储数据 
double datas_5[2][6];
double datas_9[2][10];
double datas_13[2][14];
double datas_17[2][18];
double datas_21[2][22];

double e_5[7][7];
double e_9[11][11];
double e_13[15][15];
double e_17[19][19];
double e_21[23][23];

double root_5[7][7];
double root_9[11][11];
double root_13[15][15];
double root_17[19][19];
double root_21[23][23];
//文件输入到全局数组 
void set_data(){
	FILE* f;
	f = fopen("E:\\算法基础 顾乃杰\\PB17000285-project2\\ex1\\input\\input.txt","r");
	for(int i = 0;i<5;i++){
		int datasize = 0;
		fscanf(f,"%d\n",&datasize);
		for(int j = 1;j<=datasize;j++){
			switch(datasize){
				case 5: {
					fscanf(f,"%lf",&datas_5[0][j]);
					break;
				}
				case 9: {
					fscanf(f,"%lf",&datas_9[0][j]);
					break;
				}
				case 13: {
					fscanf(f,"%lf",&datas_13[0][j]);
					break;
				}
				case 17: {
					fscanf(f,"%lf",&datas_17[0][j]);
					break;
				}
				case 21: {
					fscanf(f,"%lf",&datas_21[0][j]);
					break;
				}
				default:{
					break;
				}
			}
		}
		for(int j = 0;j<datasize+1;j++){
			switch(datasize){
				case 5: {
					fscanf(f,"%lf",&datas_5[1][j]);
					break;
				}
				case 9: {
					fscanf(f,"%lf",&datas_9[1][j]);
					break;
				}
				case 13: {
					fscanf(f,"%lf",&datas_13[1][j]);
					break;
				}
				case 17: {
					fscanf(f,"%lf",&datas_17[1][j]);
					break;
				}
				case 21: {
					fscanf(f,"%lf",&datas_21[1][j]);
					break;
				}
				default:{
					break;
				}
			}
		}
	}
	fclose(f);
/*
//data5
		for(int j = 0;j < 6;j++){
			printf("%lf ",datas_5[0][j]);
		}
		printf("\n");
		for(int j = 0;j < 6;j++){
			printf("%lf ",datas_5[1][j]);
		}
		printf("\n");
		printf("\n");
//data9		
		for(int j = 0;j < 9;j++){
			printf("%lf ",datas_9[0][j]);
		}
		printf("\n");
		for(int j = 0;j < 10;j++){
			printf("%lf ",datas_9[1][j]);
		}
		printf("\n");
		printf("\n");
//data13
		for(int j = 0;j < 13;j++){
			printf("%lf ",datas_13[0][j]);
		}
		printf("\n");
		for(int j = 0;j < 14;j++){
			printf("%lf ",datas_13[1][j]);
		}
		printf("\n");
		printf("\n");
//data17
		for(int j = 0;j < 17;j++){
			printf("%lf ",datas_17[0][j]);
		}
		printf("\n");
		for(int j = 0;j < 18;j++){
			printf("%lf ",datas_17[1][j]);
		}
		printf("\n");
		printf("\n");
//data21
		for(int j = 0;j < 21;j++){
			printf("%lf ",datas_21[0][j]);
		}
		printf("\n");
		for(int j = 0;j < 22;j++){
			printf("%lf ",datas_21[1][j]);
		}
		printf("\n");
		printf("\n");	*/
}
#endif 
