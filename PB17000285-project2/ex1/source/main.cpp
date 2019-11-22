#include"head.h"
FILE *f;
void optimal_bst(double p[], double q[],int n){
	double w[25][25];
	double t;
	f = fopen("E:\\算法基础 顾乃杰\\PB17000285-project2\\ex1\\output\\time.txt","a");
	
	switch(n){
		case 5: {
			time_count_start();
			for(int i = 1;i<=6;i++){
				e_5[i][i-1] = q[i-1];
				w[i][i-1] = q[i-1];
			}
			for(int l = 1;l<=n;l++){
				for(int i = 1;i<=n-l+1;i++){
					int j = i+l-1;
					e_5[i][j] = BIG_DOUBLE;
					w[i][j] = w[i][j-1] + p[j] + q[j];
					for(int r = i;r<=j;r++){
						t = e_5[i][r-1] + e_5[r+1][j] + w[i][j];
					//	printf("t : %lf\n",t);
						if(t<e_5[i][j]){
							e_5[i][j] = t;
							root_5[i][j] = r;
					//		printf("e [%d %d] : %lf\n",i,j,t);
					///		printf("root [%d %d] : %lf\n",i,j,r);
						}
					}
				}
			}
			time_count_end();
			break;
		}
		case 9: {
			time_count_start();
			for(int i = 1;i<=10;i++){
				e_9[i][i-1] = q[i-1];
				w[i][i-1] = q[i-1];
			}
			for(int l = 1;l<=n;l++){
				for(int i = 1;i<=n-l+1;i++){
					int j = i+l-1;
					e_9[i][j] = BIG_DOUBLE;
					w[i][j] = w[i][j-1] + p[j] + q[j];
					for(int r = i;r<=j;r++){
						t = e_9[i][r-1] + e_9[r+1][j] + w[i][j];
					//	printf("t : %lf\n",t);
						if(t<e_9[i][j]){
							e_9[i][j] = t;
							root_9[i][j] = r;
					//		printf("e [%d %d] : %lf\n",i,j,t);
					///		printf("root [%d %d] : %lf\n",i,j,r);
						}
					}
				}
			}
			time_count_end();
			break;
		}
		case 13: {
			time_count_start();
			for(int i = 1;i<=14;i++){
				e_13[i][i-1] = q[i-1];
				w[i][i-1] = q[i-1];
			}
			for(int l = 1;l<=n;l++){
				for(int i = 1;i<=n-l+1;i++){
					int j = i+l-1;
					e_13[i][j] = BIG_DOUBLE;
					w[i][j] = w[i][j-1] + p[j] + q[j];
					for(int r = i;r<=j;r++){
						t = e_13[i][r-1] + e_13[r+1][j] + w[i][j];
					//	printf("t : %lf\n",t);
						if(t<e_13[i][j]){
							e_13[i][j] = t;
							root_13[i][j] = r;
					//		printf("e [%d %d] : %lf\n",i,j,t);
					///		printf("root [%d %d] : %lf\n",i,j,r);
						}
					}
				}
			}
			time_count_end();
			break;
		}
		case 17: {
			time_count_start();
			for(int i = 1;i<=18;i++){
				e_17[i][i-1] = q[i-1];
				w[i][i-1] = q[i-1];
			}
			for(int l = 1;l<=n;l++){
				for(int i = 1;i<=n-l+1;i++){
					int j = i+l-1;
					e_17[i][j] = BIG_DOUBLE;
					w[i][j] = w[i][j-1] + p[j] + q[j];
					for(int r = i;r<=j;r++){
						t = e_17[i][r-1] + e_17[r+1][j] + w[i][j];
					//	printf("t : %lf\n",t);
						if(t<e_17[i][j]){
							e_17[i][j] = t;
							root_17[i][j] = r;
					//		printf("e [%d %d] : %lf\n",i,j,t);
					///		printf("root [%d %d] : %lf\n",i,j,r);
						}
					}
				}
			}
			time_count_end();
			break;
		}
		case 21: {
			time_count_start();
			for(int i = 1;i<=22;i++){
				e_21[i][i-1] = q[i-1];
				w[i][i-1] = q[i-1];
			}
			for(int l = 1;l<=n;l++){
				for(int i = 1;i<=n-l+1;i++){
					int j = i+l-1;
					e_21[i][j] = BIG_DOUBLE;
					w[i][j] = w[i][j-1] + p[j] + q[j];
					for(int r = i;r<=j;r++){
						t = e_21[i][r-1] + e_21[r+1][j] + w[i][j];
					//	printf("t : %lf\n",t);
						if(t<e_21[i][j]){
							e_21[i][j] = t;
							root_21[i][j] = r;
					//		printf("e [%d %d] : %lf\n",i,j,t);
					///		printf("root [%d %d] : %lf\n",i,j,r);
						}
					}
				}
			}
			time_count_end();
			break;
		}
		default:{
			
			break;
		}
	}
	fprintf(f,"%lf ",runTime);
	if(n==21) fprintf(f,"\n");
	fclose(f);
} 
//递归调用输出树 
void print_tree(int i,int j, int n){//切记在调用前要把文件指针f置好 
	int t = 0;
	switch(n){
		case 5:{
			t = root_5[i][j];
			break;
		}
		case 9:{
			t = root_9[i][j];
			break;
		}
		case 13:{
			t = root_13[i][j];
			break;
		}
		case 17:{
			t = root_17[i][j];
			break;
		}
		case 21:{
			t = root_21[i][j];
			break;
		}
		default:{
			
			break;
		}
	} 
	
	//printf("e[%d][%d]:%d\n",i,j,t);
	if(t!=i&&t!=j){
		fprintf(f,"k%d ",t);
		print_tree(i,t-1,n);
		print_tree(t+1,j,n);
	}
	else if(t==i&&t==j){
		fprintf(f,"k%d d%d d%d ",t,t-1,t);
	}
	else if(t==i){
		fprintf(f,"k%d d%d ",t,t-1);
		print_tree(t+1,j,n);
	}
	else {
		fprintf(f,"k%d ",t);
		print_tree(i,j-1,n);
		fprintf(f,"d%d ",t,t);
		
		
	}
}

void n_time(){//调用N次，统计时间 
	set_data();
	for(int i=0;i<N;i++){
		optimal_bst(datas_5[0], datas_5[1],5);

		optimal_bst(datas_9[0], datas_9[1],9);

		optimal_bst(datas_13[0], datas_13[1],13);

		optimal_bst(datas_17[0], datas_17[1],17);

		optimal_bst(datas_21[0], datas_21[1],21);

	}
}
int main(){
	n_time();//重复进行N次计算
	 
	f = fopen("E:\\算法基础 顾乃杰\\PB17000285-project2\\ex1\\output\\result.txt","w");
	
	//结果的输出 
	fprintf(f,"(%lf,",e_5[1][5]);
	print_tree(1,5,5);
	fprintf(f,")\n");
	
	fprintf(f,"(%lf,",e_9[1][9]);
	print_tree(1,9,9);
	fprintf(f,")\n");
	
	fprintf(f,"(%lf,",e_13[1][13]);
	print_tree(1,13,13);
	fprintf(f,")\n");
	
	fprintf(f,"(%lf,",e_17[1][17]);
	print_tree(1,17,17);
	fprintf(f,")\n");
	
	fprintf(f,"(%lf,",e_21[1][21]);
	print_tree(1,21,21);
	fprintf(f,")\n");	
	fclose(f);
	
	
	
}
