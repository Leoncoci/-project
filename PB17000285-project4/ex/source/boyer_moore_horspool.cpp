int f(char c){
	return c-'0';
}
char Totalchar[] = {0+'0',1+'0',2+'0',3+'0',4+'0',5+'0',6+'0',7+'0',8+'0',9+'0',
						'A','B','C','D','E','F','G',
						'H','I','J','K','L','M','N',
						'O','P','Q','R','S','T','U','V','W','X','Y','Z',
						'a','b','c','d','e','f','g',
						'h','i','j','k','l','m','n',
						'o','p','q','r','s','t','u','v','w','x','y','z'
					};
void pre_Bc(int index, int *Bc){
	for(int i = 0;i<62;i++){
		int j;
		for(j = plen[index]-2;j>=0;j--){
			if(f(P[index][j])==f(Totalchar[i])){
				Bc[f(Totalchar[i])] = plen[index]-j-1;
				break;
			}
		}
		if(j<0)
			Bc[f(Totalchar[i])] = plen[index];
	}
	/*Êä³öBcÊý×é 
	for(int i = 0;i<62;i++){
		printf("%d ",Bc[f(Totalchar[i])]);
	}*/
}
int horspool_matcher(int index){
	int Bc[80];
	pre_Bc(index,Bc);
	char c;
	int j = 0,temp = tlen[index] - plen[index];
	while(j<=temp){
		c = T[index][j+plen[index]-1];
		if(P[index][plen[index]-1]==c&&strncmp(P[index],&T[index][j],plen[index])==0){
			return j;
		}
		j+=Bc[f(c)];
	}
	return -1;
}

