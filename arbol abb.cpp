#include <stdlib.h>
#include <stdio.h>

struct nodo{
int valor,fe;
nodo*der,*izq;};





void postorden(nodo*a){
		if (a){
	   postorden(a->izq);
	   postorden(a->der);
	   printf("(%i)",a->valor);
	}
	
}


void insertar(nodo**a,int x){
	if (!(*a)){
	 (*a)=new nodo;
	 (*a)->valor=x;
	 (*a)->der=NULL;
	 (*a)->izq=NULL;
	}
	else{
		if((*a)->valor>x)
		 insertar(&(*a)->izq,x);
		
		else if ((*a)->valor<x)
		 insertar(&(*a)->der,x);
	    
		else 
		  printf("\n el numero ya se encuentra en el arbol");
	}

}


void inorden(nodo*a){
	if (a){
	   inorden(a->izq);
	   printf("(%i)",a->valor);
	   inorden(a->der);
	}
}

void inorden_2(nodo*a,int*x,int y,int*imp){
	if (a){
	   (*x)++;
	   inorden_2(a->izq,x,y,imp);
	   if ((*x)==y){
	   	(*imp)++;
	    printf("\nNIVEL (%i)=(-%i-)\n",(*x),(a->valor));
	   }
	   
	   inorden_2(a->der,x,y,imp);
	   (*x)--;
	}
}

int mayor_de_menores(nodo**b,nodo**aux){
	printf("\n mayor de menores...");
	if ((*b)->der){
	return mayor_de_menores(&((*b)->der),aux);
	}
	else {
	  (*aux)=(*b);
	  (*b)=(*aux)->izq;
	  return ((*aux)->valor);	
	}
}



void eliminar(nodo**a,int x){
	if (*a){
	  if((*a)->valor>x)
		  eliminar(&(*a)->izq,x);
	  else if((*a)->valor<x)
	      eliminar(&(*a)->der,x);
	  else if ((*a)->valor==x){
		  nodo*aux=(*a);
		  if ((!((*a)->der))&&(!((*a)->izq)))   
			(*a)=NULL;
		  else if(!((*a)->der))
			  (*a)=aux->izq;
		  else if(!((*a)->izq))
			  (*a)=aux->der;
		  else 
		 (*a)->valor=mayor_de_menores(&(*a)->izq,&aux);

	      delete aux;
	  }
	}
}





int main(){
   int option=0,x=0,des,bus,res=0,cont=1;
   nodo*p=NULL;
  

   do{
	printf("bienvenido al menu");
	printf("\n1.insertar clave");
	printf("\n2.mostrar el arbol");	
	printf("\n3.eliminar clave en el arbol");
	printf("\n4.imprimir arbol por niveles");
    printf("=\n\n");
    scanf("%i",&option);
	system("cls");
	switch(option){

	case 1:{printf("\nintroduzca el valor a introducir=");
		    scanf("%i",&x);	
			insertar(&p,x);
		    break;
		   }

	case 2:{printf("INORDEN=");
	        inorden(p);
	        printf("\n\nPOSTORDEN=");
	        postorden(p);
	        printf("\n\n");
	        system("pause");
	        system("cls");
			break;
		   }

	case 3:{printf("\nintroduzca el valor a eliminar=");
		    scanf("%i",&x);	
			eliminar(&p,x);
		    break;
		   }

	case 4:{cont=0;
		    res=1;
			int nivel=1,imp=1;		
		   while (imp!=0){
		   	imp=0;
		    inorden_2(p,&cont,nivel,&imp);
			nivel++;
			cont=0;
		   }  
		system("pause");
		system("cls");
   
		break;
		   }
		    

}
   }while(option!=0);
   }
