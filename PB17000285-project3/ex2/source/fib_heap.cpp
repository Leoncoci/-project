
typedef  struct node{
	int degree = 0;
	int key = 0;
	bool mark = false;
	node *p;
	node *child;
	node *left;
	node *right;
} fib_node;

typedef struct list{
	fib_node *min;
	int n;
} rootlist;

fib_node* find_node(fib_node *H,int k){
	
	
	fib_node *t = H;
	fib_node *p = NULL;
	if(t==NULL){
		return t;
	}
	do{
		if(t->key==k){
			p = t;
			break;
		}
		else{
			if((p = find_node(t->child,k))!=NULL){
				break;
			}
		}
		t = t->right;
//		printf("next loop\n");
	} while(t!=H);
//	printf("find key is %d\n",p->key);
	return p;
}
rootlist* make_heap(){
	rootlist* H;
	H = (rootlist*)malloc(sizeof(rootlist));
	H->n = 0;
	H->min = NULL;
	return H;
}

void fib_heap_insert(rootlist* H, fib_node* x){//调用前应给x.key赋值 
	x->degree = 0;
	x->p = NULL;
	x->child = NULL;
	x->mark = false;
	if(H->min == NULL){//仅包含x 
		x->left = x;
		x->right = x;
		H->min = x;	
	}
	else{
		/*将x插入到rootlist*/ 
		x->left = H->min;
		x->right = H->min->right;
		H->min->right->left = x;
		H->min->right = x;
		if(x->key<H->min->key){
			H->min = x;
		}
	}
	H->n = H->n + 1;
	//printf("success insert %d\n",x->key);
} 

rootlist* fib_heap_union(rootlist* H1,rootlist* H2){
	rootlist* H = make_heap();
	H->min = H1->min;
	/*拼接 H1,H2*/ 
	if(H2->min!=NULL&&H1->min!=NULL){
		fib_node *temp = H1->min->right;
		H1->min->right = H2->min->right;
		H2->min->left = H1->min;
	
		H2->min->right = temp;
		temp->left = H2->min;
	}
	
	if(H1->min==NULL||(H2->min!=NULL&&H2->min->key<H1->min->key)){
		H->min = H2->min;
	}
	H->n = H1->n + H2->n;
	return H;
}

void fib_heap_link(rootlist *H,fib_node *y, fib_node *x){\
/*remove y from the root list H*/
	y->right->left = y->left;
	y->left->right = y->right;
/*make y a child of x, incrementing x.degree*/
	x->degree = x->degree + 1;
	y->p = x;
	if(x->child==NULL){
		x->child = y;
	}
	else{
		y->right = x->child->right;
		y->left = x->child;
		x->child->right->left = y;
		x->child->right = y;
	}
	y->mark = false;	
	
}
fib_node* fib_heap_remove_min(rootlist *H){
	fib_node *min = H->min;
	if(H->min==min->right){
		H->min=NULL;
	}
	else{
		min->right->left = min->left;
		min->left->right = min->right;
		H->min = min->right;
	}
	min->left = min->right = min;
	return min;
}
void consolidate(rootlist *H){
	fib_node *A[D(H,n)],*x,*y,*tmp;
	int d;
	for(int i = 0;i<D(H,n);i++){
		A[i] = NULL;
	}
	while(H->min!=NULL){
		x = fib_heap_remove_min(H);
		d = x->degree;
		while(A[d]!=NULL){
			y = A[d];
			if(x->key > y->key){
				tmp = x;
				x = y;
				y = tmp;
			}
			fib_heap_link(H,y,x);
			A[d] = NULL;
			d++;
		}
		A[d] = x;
	}
	H->min = NULL;

	for(int i = 0;i<D(H,n);i++){
		if(A[i]!=NULL){
			if(H->min==NULL){
				H->min = A[i];
				A[i]->left = A[i];
				A[i]->right = A[i];
			}
			else{
				/*insert A[i] into H rootlist*/
				A[i]->right = H->min->right;
				A[i]->left = H->min;
				H->min->right->left = A[i];
				H->min->right = A[i];
				if(A[i]->key<H->min->key){
					H->min = A[i];
				}
			}
		}
	}
	//printf("min is %d",H->min->key);
}
fib_node* fib_heap_extract_min(rootlist *H){
	fib_node *z = H->min,*child = NULL;
	if(H==NULL||H->min==NULL){
		return NULL;
	}
	while(z->child!=NULL){
		child = z->child;
		child->right->left = child->left;
		child->left->right = child->right;
		if(child->right==child){
			z->child = NULL;
		}
		else{
			z->child = child->right;
		}
		/*加到rootlist*/
		child->left = z->left;
		z->left->right = child;
		child->right = z; 
		z->left = child;
		
		child->p = NULL;
	}
	
		/*移除 z*/
		z->left->right = z->right;
		z->right->left = z->left;
/*
		int tt = 1;
		for(fib_node *ttt = z->right->right;ttt!=z->right;ttt=ttt->right) tt++;
		printf("node num %d\n",tt);
*/
		if(z==z->right){//只有一个结点 
			H->min = NULL;
		}
		else{
			H->min = z->right;
			consolidate(H);
		}
		H->n = H->n - 1; 
	
	return z;
}
void cut(rootlist *H, fib_node *x,fib_node *y){
/*remove x from the child list if y, decrementing y.degree*/
	x->right->left = x->left;
	x->left->right = x->right;	
	y->degree = y->degree - 1;
/*add x to the rootlist if H*/
	x->right = H->min->right;
	x->left = H->min;
	H->min->right->left = x;
	H->min->right = x;
	
	x->p = NULL;
	x->mark = false;
}

void cascading_cut(rootlist *H,fib_node *y){
	fib_node *z = y->p;
	if(z!=NULL){
		if(y->mark==false){
			y->mark = true;
		}
		else{
			cut(H,y,z);
			cascading_cut(H,z);
		}
	}
}
void fib_heap_decrease_key(rootlist *H,fib_node *x, int k){
	if(k>x->key){
		printf("new key is greater than current key\n");
	}
	x->key = k;
	fib_node *y = x->p;
	if(y!=NULL&&x->key < y->key){
		cut(H,x,y);
		cascading_cut(H,y);
	}
	if(x->key<H->min->key){
		H->min = x;
	}
	
}

void fib_heap_delete(rootlist *H,fib_node *x){
//	printf("delete , %d\n",x->key);
	fib_heap_decrease_key(H,x,-1);
	//printf("min is %d\n",H->min->key);
	fib_heap_extract_min(H);
	
}/*
int main(){
	
}*/
