#include <stdlib.h>
#include <stdio.h>



int main(){
	
	int N,M,Q;
	int R;
	int pm;
	int cuenta=0;
	vector<int> P(M);
	
	
	printf("inserte el valor de numero de paginas del libro \n");
	scanf("%d",&N);
	//scanf("%d%d%d", &N,&N,&Q  )
	printf("inserte el valor de paginas recortadas \n");
	scanf("%d",&M);	
	printf("inserte el valor de numero de lectores \n");
	scanf("%d",&Q);
	
	
	//p son las paginas recortadas
	
	for(int& x :P){
		scanf("%d",&x)
	}
	

	

	//por cada lector dame cuantas paginas leyo
	int flag;
	while(q--){
	int z=1;
	//de cada lector dime cual es el multiplo
		scanf("%d",&pm); 
	while (z*pm<N){
		//que no hayan sido arrancadas
	flag=0;
	
		for (x:p){
			if(x=(z*pm)){
				flag=1;	
			}
		}
	if (flag!=1){
		cuenta++;		
	}
	z++;
	}
	}
	
	printf(cuenta);
}
