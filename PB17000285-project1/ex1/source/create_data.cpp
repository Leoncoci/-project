#include<stdio.h>
#include<stdlib.h>



int main()
{
	FILE *f = fopen("e:\\Ëã·¨»ù´¡ ¹ËÄË½Ü\\PB17000285-project1\\ex1\\input\\input_strings.txt","a");
	if(!f){
		printf("open file error!\n");
		return 0;
	}
		
		
    for(int x=0;x<32768;x++)
     fprintf(f,"%d\n",(long long)((double)(rand()*65536)/RAND_MAX));
     fclose(f);
}
