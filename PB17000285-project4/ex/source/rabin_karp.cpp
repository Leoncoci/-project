int rabin_karp_matcher(int index){
	int D = 2;//选择2 作为基数
	int Q =  4751;//选择4751作为素数
	int h = D;
	/*迭代计算h*/ 
	for(int i=2;i<plen[index];i++){
		h = (h*D)%Q;
	}
	int p = 0,t = 0;
	/*准备*/ 
	for(int i = 0;i<plen[index];i++){
		p = (D*p + P[index][i])%Q;
		t = (D*t + T[index][i])%Q;
	}
	int temp = tlen[index] - plen[index];
	for(int i = 0;i<=temp;i++){
		if(p==t){
			if(strncmp(P[index],&T[index][i],plen[index])==0){
				return i;
			}
		}
		if(i<=temp){
			int tempval = t-T[index][i] * h;
			while(tempval<0){
				tempval+=Q;
			}
			t = (D*(tempval) + T[index][i+plen[index]])%Q;
		}
	}
	return -1;
}
