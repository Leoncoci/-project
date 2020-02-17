void compute_prefix_function(int index, int *pai){
	pai[0] = 0;
	int k = 0;
	for(int q = 1;q<plen[index];q++){
		while(k>0&&P[index][k]!=P[index][q]){
			k = pai[k-1];
		}
		if(P[index][k]==P[index][q]){
			k = k+1;
		}
		pai[q] = k;
	}
}

int kmp_matcher(int index){
	int temp = tlen[index] - plen[index];
	int pai[plen[index]+2];
	compute_prefix_function(index,pai);
	int q = 0;
	for(int i = 0;i<tlen[index];i++){
		while(q>0&&P[index][q]!=T[index][i]){
			q = pai[q];
		}
		if(P[index][q] == T[index][i]){
			q = q+1;
		}
		if(q==plen[index]){
			return i-plen[index]+1;
	//		q = pai[q];
		}
	}
	return -1;
}
