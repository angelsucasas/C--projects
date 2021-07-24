#include <stdlib.h>
#include <stdio.h>

//esta es ladoblemente enlazada
struct lista{
	int valor;
	lista*prox,*ant;
};


void burbuja(lista*a){
	lista*aux=a;
	do{
	  if (((aux->valor)>(aux->prox->valor))&&((aux->prox)!=(a))){
	  	int temp=aux->valor;
	  	aux->valor=aux->prox->valor;
	  	aux->prox->valor=temp;
	  }
	  aux=aux->prox;
	}while(aux!=a);
	
	
	
}


int nivelar_l(int x, int y){
	int alm=y;
	while(x>y){
	 y+=alm;	
	}
	
	return y-x;
}

void mover (lista**a,int x){
	while(x!=0){
		(*a)=(*a)->prox;
		x--;
	}
}

int longitud(lista*a){
	lista*aux=a;
	int ans=0;
	if (a){
	do{
	  ans++;
	  aux=aux->prox;
	}while(aux!=a);
	}
	return ans;
}

void insertar (lista**a,int x){
	lista*aux=(*a);
	
	if (!(*a)){
		aux=new lista;
		aux->valor=x;
		aux->prox=aux;
		aux->ant=aux;
		(*a)=aux;
	}
	 else{
	 	while(aux->prox!=(*a))
	 	  aux=aux->prox;
	 	  
	 	lista*aux2=new lista;
		aux2->valor=x;
		aux2->prox=aux->prox;
		aux->prox=aux2;  
		aux2->ant=aux;
		(*a)->ant=aux2;
	 }
}

void mostrar(lista*a){
	lista*aux=a;
	if (a){
	do{
	  printf("[%i]->",aux->valor);
	  aux=aux->prox;
	}while(aux!=a);
	}
	 printf("NULL\n");
}



void mostrar_ant(lista*a){
	lista*aux=a;
	if (a){
	do{
	  printf("[%i]->",aux->valor);
	  aux=aux->ant;
	}while(aux!=a);
	}
	 printf("NULL\n");
}

int buscar(lista*a,int x){
	lista*aux=a;
	int ans=0;
	do{
	 	if ((aux->valor)==(x))
	 	  ans++;
	 	  
      aux=aux->prox;
	}while(aux!=a);
	
	return ans;
}

void eliminar(lista**a,int x){
	lista*aux=(*a);
	
	if(((*a)->prox)==(*a)){
		(*a)=NULL;
		delete aux;
		aux=(*a);
		printf("\ncaso especial-ultimo!\n");
	}
	 else{
	while((aux->prox->valor)!=(x))
	   aux=aux->prox;
	
	
	printf("\n[%i]->\n",aux->valor);
	printf("\n[%i]->\n",(*a)->valor);
	if((aux->prox==(*a))){
		(*a)=(*a)->prox;
		printf("adelanto puntero!\n");
	}
	
	lista*aux2=aux->prox;
	aux->prox=aux2->prox;
	aux2->prox->ant=aux;
	delete aux2;
	aux2=aux;	
}
	
}

int main(){
   int option=0,x=0,des,bus,res=0;
   lista*p=NULL;


   do{
	printf("bienvenido al menu de lista circular doblemente enlazada");
	printf("\n1.insertar por cola en la lista doblemente circular"); //en proceso
	printf("\n2.mostrar la lista circular");	
	printf("\n3.eliminar un elemento en la lista circular");	
	printf("\n4.buscar elemento en la lista");
	printf("\n5.ejercicio emergencia!- emparejar rondas");
	printf("\n6.longitud");

	printf("\n7.ordenar(menor a mayor)");
	printf("\n8.mostrar por anteriores");
	printf("\n\nopcion=");
	

    scanf("%i",&option);
	system("cls");
	switch(option){
		
		case 1:{printf("\n introduzca el digito a introducir en la lista=");
		        scanf("%i",&x);
		        
			    insertar(&p,x);
			    break;
		      }
		      
		case 2:{printf("\n\n");
		        mostrar(p);
		        system("pause");
		        system("cls");
			    break;
		       }   
			   
	   case 3:{printf("\n introduzca el digito a eliminar en la lista=\n");
		       scanf("%i",&x);
		        if (buscar(p,x))
		         eliminar(&p,x);
		          else 
		           printf("\n el numero que introdujo no se encuentra en la lista circular...\n");
		       break;
	   }
	   
	   case 4:{printf("\n introduzca el digito a buscar en la lista=\n");
		       scanf("%i",&x);
		        if (buscar(p,x))
		         printf("\nse encuentra en la lista!!\n");
		          else 
		           printf("\nno se encuentra en la lista...\n");
		       break;
	         }	
			 
	   case 5:{ int der=0,izq=0; 
	            lista*auxd=p,*auxi=p;
	   
	            while (p){
	   	         fflush(stdin);
				 printf("cuantos espacios se quiere mover a la derecha?");
	             scanf("%i",&der);
	             mover(&auxd,der);
	             
	             printf("cuantos espacios se quiere mover a la izquierda?");
	             scanf("%i",&izq);
	             int lon=longitud(p);
	             int movi=nivelar_l(izq,lon);
	             mover(&auxi,movi);
	             
	              if (auxd==auxi){
	              	auxi=auxi->prox;
				  }
	             printf("\nPareja:\n");
	             printf("[%i]-vs-[%i]",auxd->valor,auxi->valor);	
				 eliminar(&p,auxd->valor);
				 eliminar(&p,auxi->valor);      
				 auxd=p;
				 auxi=p;       
	             }
		      break;
	   }
	   
	   case 6:{if (p){
	            int lon=longitud(p);
	            printf("longitud=%i\n",lon);
	   	   }else
			  printf("la lista esta vacia , llenela primero...\n");
			  
		       break;
	   }
	   
	  case 7:{int lon=longitud(p);
	          for(int i=0;i!=lon;i++){	  
	  	       burbuja(p);
	  	       }
		      break;
	  } 	    
	  
	  
	  case 8:{printf("\n\n");
		        mostrar_ant(p);
		        system("pause");
		        system("cls");
		      break;
	  }  

}
   }while(option!=0);
   }
