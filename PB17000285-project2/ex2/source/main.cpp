#include"head.h"

void setdata(){
	FILE *f;
	char t;
	f = fopen("E:\\Ëã·¨»ù´¡ ¹ËÄË½Ü\\PB17000285-project2\\ex2\\input\\inputA.txt","r");
	for(int j = 0;j<6;j++){
		for(int i = 1;i<=16;i++){
			fscanf(f,"%c",&data16[j][i]);
		//	printf("%c",data16[j][i]);
		}
		fscanf(f,"%c",&t);
	//	printf("\n");
		for(int i = 1;i<=10*j+10;i++){
			fscanf(f,"%c",&data60[j][i]);
		//	printf("%c",data60[j][i]);
		}	
		fscanf(f,"%c",&t);
	//	printf("\n");
	}
	
	fclose(f);
	f = fopen("E:\\Ëã·¨»ù´¡ ¹ËÄË½Ü\\PB17000285-project2\\ex2\\input\\inputB.txt","r");
	for(int j = 0;j<6;j++){
		for(int i = 1;i<=15*j+15;i++){
			fscanf(f,"%c",&data90[j][i]);
		//	printf("%c",data90[j][i]);
		}
		fscanf(f,"%c",&t);
	//	printf("\n");
		for(int i = 1;i<=26;i++){
			fscanf(f,"%c",&data26[j][i]);
		//	printf("%c",data26[j][i]);
		}	
		fscanf(f,"%c",&t);
	//	printf("\n");
	}
	
	fclose(f);
} 

void cs_length(char x[], char y[], int m, int n){//mÊÇx³¤¶È£¬nÊÇy³¤¶È 
	 for(int i = 1;i<=m;i++){
		c[i][0] = 0;
	}
	for(int j = 0;j<=n;j++){
		c[0][j] = 0;
	}
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=n;j++){
			if(x[i]==y[j]){
				c[i][j] = c[i-1][j-1]+1;
				b[i][j] = ZS;
			}
			else if(c[i-1][j]>=c[i][j-1]){
				c[i][j] = c[i-1][j];
				b[i][j] = S;
			}
			else{
				c[i][j] = c[i][j-1];
				b[i][j] = Z;
			}
		}
	}
}
 void print_lcs(char x[], int i, int j){
 	if(i<=0||j<=0){
 		return;
	}
	if(b[i][j] == ZS){
		print_lcs(x,i-1,j-1);
		fprintf(f,"%c",x[i]);
		flag++;
	}
	else if(b[i][j] == S){
		print_lcs(x,i-1,j);
	}
	else{
		print_lcs(x,i,j-1);
	}
 }
void n_time(){
	for(int i = 0;i<N;i++){
		f = fopen("E:\\Ëã·¨»ù´¡ ¹ËÄË½Ü\\PB17000285-project2\\ex2\\output\\result.txt","w");
		FILE *ft = fopen("E:\\Ëã·¨»ù´¡ ¹ËÄË½Ü\\PB17000285-project2\\ex2\\output\\time.txt","a");

		for(int i = 0;i<6;i++){
			flag=0;
			time_count_start();
			cs_length(data16[i],data60[0],16,10*i+10);
			time_count_end();
			fprintf(ft,"(%d,%d) %lf\n",16,10*i+10,runTime);
			fprintf(f,"(%d,%d)",16,10*i+10);
			print_lcs(data16[i],16,10*i+10);
			fprintf(f," %d\n",flag);
		}
		for(int i = 0;i<6;i++){
			flag=0;
			time_count_start();
			cs_length(data90[i],data26[0],15*i+15,26);
			time_count_end();
			fprintf(ft,"(%d,%d) %lf\n",15*i+15,26,runTime);
			fprintf(f,"(%d,%d)",15*i+15,26);
			print_lcs(data90[i],15*i+15,26);
			fprintf(f," %d\n",flag);
		}	
		fclose(f);
		fclose(ft);
	}
} 
int main(){
	setdata();
	n_time();
	
}
