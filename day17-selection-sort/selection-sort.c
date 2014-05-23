
//Selection Sort

int selection_sort(int size, int vec[]){
	int i,j,min,aux,L=0;
	while(L<size){
		min=vec[L];
		for(i=L;i<size;i++)
			if(vec[i]<min){
				min=vec[i];
				j=i;
			}
		aux=vec[j];
		vec[j]=vec[L];
		vec[L]=aux;
		L++;
	}
	return vec;
}
