#ifndef HEAD_H
#define HEAD_H
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>



#define BIG_DOUBLE 10000
#define N 50
/*定义状态*/ 
#define ZS 111
#define Z 121
#define S 131

/*申明计时用全局变量*/ 
LARGE_INTEGER litmp;
double frequency,runTime,minus;
LONGLONG timeStart,timeEnd;
int flag;
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

FILE *f;
/*全局数组*/ 
char data16[6][17];
char data60[6][61];

char data90[6][91];
char data26[6][27];

int b[92][62],c[92][62];
void create_data(){
	FILE* f;
	f = fopen("E:\\算法基础 顾乃杰\\PB17000285-project2\\ex2\\input\\inputA.txt","a");
	
	for(int i = 0;i<16+10+16+20+16+30+16+40+16+50+16+60;i++){
		if(i==16||i==16+10||i==16+10+16||i==16+10+16+20||i==16+10+16+20+16||i==16+10+16+20+16+30||i==16+10+16+20+16+30+16||i==16+10+16+20+16+30+16+40||i==16+10+16+20+16+30+16+40+16||i==16+10+16+20+16+30+16+40+16+50||i==16+10+16+20+16+30+16+40+16+50+16)
			fprintf(f,"\n");	
		fprintf(f,"%c",rand()%26+'a');
		
	}
	fclose(f);
	f = fopen("E:\\算法基础 顾乃杰\\PB17000285-project2\\ex2\\input\\inputB.txt","a");
	
	for(int i = 0;i<15+26+30+26+45+26+60+26+75+26+90+26;i++){
		if(i==15||i==15+26||i==15+26+30||i==15+26+30+26||i==15+26+30+26+45||i==15+26+30+26+45+26||i==15+26+30+26+45+26+60||i==15+26+30+26+45+26+60+26||i==15+26+30+26+45+26+60+26+75||i==15+26+30+26+45+26+60+26+75+26||i==15+26+30+26+45+26+60+26+75+26+90)
			fprintf(f,"\n");	
		fprintf(f,"%c",rand()%26+'a');
		
	}
	fclose(f);
} 
#endif 
