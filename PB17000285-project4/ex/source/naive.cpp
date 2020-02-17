int naive_string_matcher(int index){
	int temp = tlen[index]-plen[index];
	for(int i = 0;i<=temp;i++){
		if(strncmp(P[index],&T[index][i],plen[index])==0){
			return i;
		}
	}
	return -1;
}
