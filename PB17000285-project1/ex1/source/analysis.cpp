#include"sort.h"
void analysis_counting_sort(){
	double ave_time[][7] = {
		#include"E:\\Ëã·¨»ù´¡ ¹ËÄË½Ü\\PB17000285-project1\\ex1\\output\\counting_sort\\time.txt"
	};
	for(int i = 0;i<7;i++){
		for(int j = 1;j<Ntime;j++){
			ave_time[0][i] = ave_time[0][i] + ave_time[j][i];
		}
		printf("\n");
	}
		printf("counting_sort average time(for 2^3 to 2^15):\n") ;

	for(int i = 0;i<7;i++){
		ave_time[0][i] = ave_time[0][i] / Ntime;
		printf("%lf\n",ave_time[0][i]);
	}	
}
void analysis_quick_sort(){
	double ave_time[][7] = {
		#include"E:\\Ëã·¨»ù´¡ ¹ËÄË½Ü\\PB17000285-project1\\ex1\\output\\quick_sort\\time.txt"
	};
	for(int i = 0;i<7;i++){
		for(int j = 1;j<Ntime;j++){
			ave_time[0][i] = ave_time[0][i] + ave_time[j][i];
		}
		printf("\n");
	}
		printf("quick_sort average time(for 2^3 to 2^15):\n") ;

	for(int i = 0;i<7;i++){
		ave_time[0][i] = ave_time[0][i] / Ntime;
		printf("%lf\n",ave_time[0][i]);
	}	
}
void analysis_heap_sort(){
	double ave_time[][7] = {
		#include"E:\\Ëã·¨»ù´¡ ¹ËÄË½Ü\\PB17000285-project1\\ex1\\output\\heap_sort\\time.txt"
	};
	for(int i = 0;i<7;i++){
		for(int j = 1;j<Ntime;j++){
			ave_time[0][i] = ave_time[0][i] + ave_time[j][i];
		}
		printf("\n");
	}
		printf("heap_sort average time(for 2^3 to 2^15):\n") ;

	for(int i = 0;i<7;i++){
		ave_time[0][i] = ave_time[0][i] / Ntime;
		printf("%lf\n",ave_time[0][i]);
	}	
}
void analysis_merge_sort(){
	double ave_time[][7] = {
		#include"E:\\Ëã·¨»ù´¡ ¹ËÄË½Ü\\PB17000285-project1\\ex1\\output\\merge_sort\\time.txt"
	};
	for(int i = 0;i<7;i++){
		for(int j = 1;j<Ntime;j++){
			ave_time[0][i] = ave_time[0][i] + ave_time[j][i];
		}
		printf("\n");
	}
		printf("merge_sort average time(for 2^3 to 2^15):\n") ;

	for(int i = 0;i<7;i++){
		ave_time[0][i] = ave_time[0][i] / Ntime;
		printf("%lf\n",ave_time[0][i]);
	}	
}
int main(){
	analysis_merge_sort();
	analysis_heap_sort();
	analysis_quick_sort();
	analysis_counting_sort();
}
