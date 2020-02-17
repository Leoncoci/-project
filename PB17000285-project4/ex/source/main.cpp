#include"head.h"

void data_get(){	//获取第index组数据 
	FILE *f;
	char skip;
	f = fopen("E:\\算法基础 顾乃杰\\PB17000285-project4\\ex\\input\\input_strings.txt","r");
	for(int i = 0;i<5;i++){
		for(int j = 0;j<tlen[i];j++){
			fscanf(f,"%c",&T[i][j]);
		}
		fscanf(f,"%c",&skip);
		for(int j = 0;j<plen[i];j++){
			fscanf(f,"%c",&P[i][j]);
		}
		fscanf(f,"%c",&skip);
	}
	fclose(f);
}
void pro(){
	FILE *f1,*f2,*f3,*f4;
	f1 = fopen("E:\\算法基础 顾乃杰\\PB17000285-project4\\ex\\output\\naive\\result.txt","w");
	f2 = fopen("E:\\算法基础 顾乃杰\\PB17000285-project4\\ex\\output\\rabin_karp\\result.txt","w");
	f3 = fopen("E:\\算法基础 顾乃杰\\PB17000285-project4\\ex\\output\\kmp\\result.txt","w");
	f4 = fopen("E:\\算法基础 顾乃杰\\PB17000285-project4\\ex\\output\\horspool\\result.txt","w");
	for(int i = 0;i<5;i++){
		int temp;
		time_count_start();
		temp = naive_string_matcher(i);
		time_count_end();
		fprintf(f1,"%d %d %d %.10lf\n",tlen[i],plen[i],temp,runTime);
		
		time_count_start();
		temp = rabin_karp_matcher(i);
		time_count_end();
		fprintf(f2,"%d %d %d %.10lf\n",tlen[i],plen[i],temp,runTime);
		
		time_count_start();
		temp = kmp_matcher(i);
		time_count_end();
		fprintf(f3,"%d %d %d %.10lf\n",tlen[i],plen[i],temp,runTime);
		
		time_count_start();
		temp = horspool_matcher(i);
		time_count_end();
		fprintf(f4,"%d %d %d %.10lf\n",tlen[i],plen[i],temp,runTime);
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
} 
int main(){
	data_get();
	pro();
} 
