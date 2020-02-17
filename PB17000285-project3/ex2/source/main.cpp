#include"head.h"
void print_rootlist(fib_node *H){
	printf("%d ",H->key);
		if(H->child!=NULL){
			print_rootlist(H->child);
		}
	for(fib_node *t = H->right;t!=H;t = t->right){	
		printf("%d ",t->key);
		if(t->child!=NULL){
			print_rootlist(t->child);
		}
	}
	printf("\n");
}
void build_progress(rootlist *&H,int index){//index为第几组数据,限制1-5 
	char c[] = {"E:\\算法基础 顾乃杰\\PB17000285-project3\\ex2\\input\\data9\\build.txt"};
	/*data[x] x位于c[53]*/
	c[53] = '0'+index;

	FILE *f;
	f = fopen(c,"r");
	int num = 0;
	fscanf(f,"%d",&num);
	
	H = make_heap();
	for(int i = 0;i<num;i++){
		fib_node *x = (fib_node*)malloc(sizeof(fib_node));
		fscanf(f,"%d",&(x->key));
		fib_heap_insert(H,x);
		
	}
	
	fclose(f);
}
double insert_progress(rootlist *H,int index){//index为第几组数据 限制1-5 
	char c[] = {"E:\\算法基础 顾乃杰\\PB17000285-project3\\ex2\\input\\data9\\insert.txt"};
	/*data[x] x位于c[53]*/
	c[53] = '0'+index; 
	FILE *f;
	f = fopen(c,"r");
	int insert_num = 0,temp;
	double total_insert_time = 0;
	fscanf(f,"%d",&insert_num);
	for(int i = 0;i<insert_num;i++){
		fscanf(f,"%d",&temp);
		fib_node *x = (fib_node*)malloc(sizeof(fib_node));
		x->key = temp;
		time_count_start();
		fib_heap_insert(H,x);
		time_count_end();
		
		total_insert_time = total_insert_time + runTime;
		
	}
	fclose(f);
	return(total_insert_time/insert_num);
}
double decrease_progress(rootlist *H,int index){
	char c[] = {"E:\\算法基础 顾乃杰\\PB17000285-project3\\ex2\\input\\data9\\decrease.txt"};
	c[53] = '0'+index; 
	FILE *f;
	f = fopen(c,"r");
	int decrease_num = 0,temp;
	double total_decrease_time = 0;
	fscanf(f,"%d",&decrease_num);
	for(int i = 0;i<decrease_num;i++){
		fscanf(f,"%d",&temp);
		time_count_start();
		fib_heap_decrease_key(H,find_node(H->min,temp),temp-10);
		time_count_end();
		total_decrease_time = total_decrease_time + runTime;
		
	}
	fclose(f);
	return(total_decrease_time/decrease_num);
}

double delete_progress(rootlist *H,int index){
//	printf("min is %d\n",H->min->key);
	char c[] = {"E:\\算法基础 顾乃杰\\PB17000285-project3\\ex2\\input\\data9\\delete.txt"};
	c[53] = '0'+index; 
	FILE *f;
	f = fopen(c,"r");
	int delete_num = 0,temp;
	double total_delete_time = 0;
	fscanf(f,"%d",&delete_num);
	for(int i = 0;i<delete_num;i++){
		fscanf(f,"%d",&temp);
		time_count_start();
		//printf("%d\n",H->min->key);
		fib_heap_delete(H,find_node(H->min,temp));
		time_count_end();
		total_delete_time = total_delete_time + runTime;
		
	}
	fclose(f);
	return(total_delete_time/delete_num);	
}

double extract_progress(rootlist *H,int index){
	
	char c1[] = {"E:\\算法基础 顾乃杰\\PB17000285-project3\\ex2\\input\\data9\\extract.txt"};
	c1[53] = '0'+index; 
	FILE *f;
	f = fopen(c1,"r");
	int extract_num = 0;
	double total_extract_time = 0;
	fscanf(f,"%d",&extract_num);
	fclose(f);
	
	char c2[]={"E:\\算法基础 顾乃杰\\PB17000285-project3\\ex2\\output\\result.txt"};
	f = fopen(c2,"a");
	fprintf(f,"data%d:\n",index);
	for(int i = 0;i<extract_num;i++){
		time_count_start();
		fib_node *tt = fib_heap_extract_min(H);
		fprintf(f,"%d\n",tt->key); 
		free(tt);
		time_count_end();
		total_extract_time = total_extract_time + runTime;
		
	}
	fclose(f);
	return(total_extract_time/extract_num);	
}

void pro(){
	rootlist *A;
	FILE *f;
	f = fopen("E:\\算法基础 顾乃杰\\PB17000285-project3\\ex2\\output\\time.txt","w");
	for(int i =1;i<6;i++){
		fprintf(f,"data%d:\n",i);
		build_progress(A,i);
		
		fprintf(f,"insert:%.10lf\n",insert_progress(A,i));
		
		fprintf(f,"decrease:%.10lf\n",decrease_progress(A,i));
		
		fprintf(f,"delete:%.10lf\n",delete_progress(A,i));
		//print_rootlist(A->min);
		fprintf(f,"extract:%.10lf\n",extract_progress(A,i));
		fprintf(f,"\n");
	}
	fclose(f);
}

int main(){	
	pro();
	
}
