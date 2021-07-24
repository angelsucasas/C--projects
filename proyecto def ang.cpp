#include <stdio.h>
#include <stdlib.h>
#include <string.h>  


struct subcategoria{
	char tipo2[20];
	char nombre [20];
	subcategoria*prox;
};

struct rubros{
	char tipo[20];
	struct subcategoria*abajo;
	rubros*prox;
};


struct almacenar{
	char nombre[20];
	char cantidad[20];
	char precio[20];
	char codigo[20];
	almacenar*prox;
};

struct lotes {
	char numero[5];
	char sucursal[10];
	char rubro[10];
	char subcategoria[20];
	char total[10];
	char exis[10];
	char peso[10];
	char costo[10];
	lotes *prox;
};

struct clientes{
	char name[20];
	clientes *prox;

};

struct sucursales{
	char nombre[20];
	sucursales *prox;

};

struct detalle_facturas{
 	char factura2[5];
 	char lote[10];
 	char unidades[10];
	char precioventa[10];
 	detalle_facturas*prox;
 };

 struct facturas{
 	char factura1[5];
 	char sucursal_[20];
 	char fecha[20];
 	char cliente[10];
 	char monto[20];
 	struct detalle_facturas*abajo;
 	facturas *prox;
 };

FILE *pf;

int existe0(lotes *e, char *v){
	lotes *a=e;
	int cont=0;
	while (a){
	if(!strcmpi(a->numero,v))
	  cont=1;
	 a=a->prox;
    }
 return cont;

 }



void consulta7(facturas *g, lotes *p) {
	facturas *aux=g;
	lotes *a=p;
	lotes*e=p;
	detalle_facturas *aux2=NULL;
	char l[20];
	int cont=0;
	
	printf("\nIndique el lote: ");
	scanf("%s",&l);
	 if (existe0(e,l)){
	 
	while (aux->prox){
	aux2=aux->abajo;
	  while(aux2){
	  	if (!strcmpi(aux2->lote,l)){
	printf("Factura= %s\n",aux2->factura2);
	printf("Lote= %s\n",aux2->lote);
	printf("Unidades= %s\n",aux2->unidades);
	printf("Precio de venta= %s\n",aux2->precioventa);
	printf("\n");
	int x=atoi(aux2->unidades);
	cont+=x; 
	}
	aux2=aux2->prox;	
	}
	aux=aux->prox;
	}
	
	while(strcmpi(a->numero,l)&&(a->prox))
	a=a->prox;
	
	
	
    int y=atoi (a->exis);
    int t=y+cont;
    
    printf("Lote= %s\n",a->numero);
    printf("Sucursal= %s\n",a->sucursal);
    printf("Rubro= %s\n",a->rubro);
    printf("Subcategoria= %s\n",a->subcategoria);
    printf("Total en existencia= %s\n",a->exis);
    printf("Peso= %s\n",a->peso);
    printf("Costo= %s\n",a->total);
    printf("----------------------------------\n");
    printf("Total de unidades= Suma de unidades vendidas + Existencia actual\n");
    printf("Total de unidades= %i + %i= %i\n",cont,y,t);
	}
	 else{
	 	printf("\n el lote no existe , intente de nuevo...");
	 }
	}

	void consulta8(lotes *p){
	lotes *aux=p;
	while(aux->prox){
	int x=atoi(aux->exis);
	if(x==0){
	printf("Lote= %s\n",aux->numero);
    	printf("Sucursal= %s\n",aux->sucursal);
    	printf("Rubro= %s\n",aux->rubro);
    	printf("Subcategoria= %s\n",aux->subcategoria);
    	printf("Total de unidades %s\n",aux->total);
    	printf("Total de existencia= %s\n",aux->exis);
    	printf("Peso= %s\n",aux->peso);
    	printf("Costo= %s\n",aux->total);
    	printf("\n");	
	}
	 aux=aux->prox;
	
	}
	
}
	
	
	
	


int existe(rubros *e, char *v){
	rubros *a=e;
	int cont=0;
	while (a){
	if(!strcmpi(a->tipo,v))
	  cont=1;
	 a=a->prox;
    }
 return cont;

 }

int existe2(clientes *e, char *v){
	clientes *a=e;
	int cont=0;
	while (a){
	if(!strcmpi(a->name,v))
	  cont=1;
	 a=a->prox;
    }
 return cont;

 }


 int existe3(sucursales *e, char *v){
	sucursales *a=e;
	int cont=0;
	while (a){
	if(!strcmpi(a->nombre,v))
	  cont=1;
	 a=a->prox;
    }
 return cont;

 }

 int existe4(rubros *e, char *v,char *u){
	rubros *a=e;
	int cont=0;
	subcategoria *b=NULL;

  while(a){
	b=a->abajo;
	while (b){
	   if(!strcmpi(b->nombre,v)&&(!strcmpi(b->tipo2,u)))
	  cont=1;
	b=b->prox;
	}
	a=a->prox;
   }
 return cont;

 }

 int existe5(rubros *e, char *v){
	rubros *a=e;
	int cont=0;
	subcategoria *b=NULL;

  while(a){
	b=a->abajo;
	while (b){
	   if(!strcmpi(b->nombre,v))
	  cont=1;

	b=b->prox;
	}
	a=a->prox;
   }
 return cont;

 }
 
 int existe6(almacenar*e,char b[20]){
 	almacenar*a=e;
 	int res=0;
 	while(a){
	  if (!(strcmpi(a->nombre,b)))
	  	res++;
	  a=a->prox;	
	 }
	 
	 return res;
 }
 
 
 
 void modificar6(sucursales**e,char*a,char*b){
	sucursales *aux=(*e);
	sucursales *aux2=(*e);
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\SUCURSALES.txt";
	char dato3[20];


	 while(strcmpi(aux->nombre,a)&&(aux->prox))
	   aux=aux->prox;

	if(!strcmpi(aux->nombre,a)){
	strcpy(aux->nombre,b);
	}

	pf = fopen(direccion_1, "w+");

	
	while (aux2->prox){
    	fwrite(aux2->nombre, 1, (strlen(aux2->nombre)), pf);
	fprintf(pf, " "); 
	
	    fprintf(pf, "\n");
	aux2=aux2->prox;
	}

    fclose(pf);


}
 
  void modificar61(sucursales**e){
	sucursales *aux=(*e);
	sucursales *aux2=(*e);
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\SUCURSALES.txt";
	char dato3[20];


	pf = fopen(direccion_1, "w+");

	
	while (aux2->prox){
    	fwrite(aux2->nombre, 1, (strlen(aux2->nombre)), pf);
	fprintf(pf, " "); 
	
	    fprintf(pf, "\n");
	aux2=aux2->prox;
	}

    fclose(pf);


}
 
 void modificar51(facturas**e){
	facturas *aux=(*e);
	facturas *aux2=(*e);
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\FACTURAS.txt";

	pf = fopen(direccion_1, "w+");
	
	while (aux2->prox){
    	fwrite(aux2->factura1, 1, (strlen(aux2->factura1)), pf);
	    fprintf(pf, " ");

	    fwrite(aux2->sucursal_, 1, (strlen(aux2->sucursal_)), pf);
	    fprintf(pf, " ");

	fwrite(aux2->fecha, 1, (strlen(aux2->fecha)), pf);
	fprintf(pf, " ");

	fwrite(aux2->cliente, 1, (strlen(aux2->cliente)), pf);
	fprintf(pf, " ");

	fwrite(aux2->monto, 1, (strlen(aux2->monto)), pf);
	fprintf(pf, " ");
	
	fprintf(pf, "\n");
	
	aux2=aux2->prox;
    	
	}
	


    fclose(pf);
	


}
 
 void modificar5(facturas**e,char*a,char*b){
	facturas *aux=(*e);
	facturas *aux2=(*e);
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\FACTURAS.txt";

	char dato3[10];
	 while(aux->prox){
	 	if(!strcmpi(aux->sucursal_,a))
	strcpy(aux->sucursal_,b);

	   aux=aux->prox;
	 }


	pf = fopen(direccion_1, "w+");
	
	while (aux2->prox){
    	fwrite(aux2->factura1, 1, (strlen(aux2->factura1)), pf);
	    fprintf(pf, " ");

	    fwrite(aux2->sucursal_, 1, (strlen(aux2->sucursal_)), pf);
	    fprintf(pf, " ");

	fwrite(aux2->fecha, 1, (strlen(aux2->fecha)), pf);
	fprintf(pf, " ");

	fwrite(aux2->cliente, 1, (strlen(aux2->cliente)), pf);
	fprintf(pf, " ");

	fwrite(aux2->monto, 1, (strlen(aux2->monto)), pf);
	fprintf(pf, " ");
	
	fprintf(pf, "\n");
	
	aux2=aux2->prox;
    	
	}
	


    fclose(pf);
	


}
 
void modificar4(lotes**e,char*a,char*b){
	lotes *aux=(*e);
	lotes *aux2=(*e);
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\LOTES.txt";

	char dato3[10];
	 while(aux->prox){
	 	if(!strcmpi(aux->sucursal,a))
	strcpy(aux->sucursal,b);

	   aux=aux->prox;
	 }
     



	pf = fopen(direccion_1, "w+");

    while (aux2->prox){
    	fwrite(aux2->numero, 1, (strlen(aux2->numero)), pf);
	    fprintf(pf, " ");

	    fwrite(aux2->sucursal, 1, (strlen(aux2->sucursal)), pf);
	    fprintf(pf, " ");

	fwrite(aux2->rubro, 1, (strlen(aux2->rubro)), pf);
	fprintf(pf, " ");

	fwrite(aux2->subcategoria, 1, (strlen(aux2->subcategoria)), pf);
	fprintf(pf, " ");

	fwrite(aux2->total, 1, (strlen(aux2->total)), pf);
	fprintf(pf, " ");

	fwrite(aux2->exis, 1, (strlen(aux2->exis)), pf);
	fprintf(pf, " ");

	fwrite(aux2->peso, 1, (strlen(aux2->peso)), pf);
	fprintf(pf, " ");

	fwrite(aux2->costo, 1, (strlen(aux2->costo)), pf);
	fprintf(pf, " ");
	
	fprintf(pf, "\n");
	
	aux2=aux2->prox;
    	
	}
  
  
  
    fclose(pf);

}

void modificar41(lotes**e){
	lotes *aux=(*e);
	lotes *aux2=(*e);
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\LOTES.txt";




	pf = fopen(direccion_1, "w+");

    while (aux2->prox){
    	fwrite(aux2->numero, 1, (strlen(aux2->numero)), pf);
	    fprintf(pf, " ");

	    fwrite(aux2->sucursal, 1, (strlen(aux2->sucursal)), pf);
	    fprintf(pf, " ");

	fwrite(aux2->rubro, 1, (strlen(aux2->rubro)), pf);
	fprintf(pf, " ");

	fwrite(aux2->subcategoria, 1, (strlen(aux2->subcategoria)), pf);
	fprintf(pf, " ");

	fwrite(aux2->total, 1, (strlen(aux2->total)), pf);
	fprintf(pf, " ");

	fwrite(aux2->exis, 1, (strlen(aux2->exis)), pf);
	fprintf(pf, " ");

	fwrite(aux2->peso, 1, (strlen(aux2->peso)), pf);
	fprintf(pf, " ");

	fwrite(aux2->costo, 1, (strlen(aux2->costo)), pf);
	fprintf(pf, " ");
	
	fprintf(pf, "\n");
	
	aux2=aux2->prox;
    	
	}
  
  
  
    fclose(pf);

}

void modificar1(rubros**e,char*a,char*b){
	rubros *aux=(*e);
	rubros *aux2=(*e);
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\rubros.txt";
	char dato3[20];


	 while(strcmpi(aux->tipo,a)&&(aux->prox))
	   aux=aux->prox;

	if(!strcmpi(aux->tipo,a)){
	strcpy(aux->tipo,b);
	}

	pf = fopen(direccion_1, "w+");

	while (aux2->prox){
    	fwrite(aux2->tipo, 1, (strlen(aux2->tipo)), pf);
	fprintf(pf, " "); 
	
	    fprintf(pf, "\n");
	aux2=aux2->prox;
	}

    fclose(pf);
	

}

void modificar11(rubros**e){
	rubros *aux=(*e);
	rubros *aux2=(*e);
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\rubros.txt";
	char dato3[20];


	pf = fopen(direccion_1, "w+");

	while (aux2->prox){
    	fwrite(aux2->tipo, 1, (strlen(aux2->tipo)), pf);
	fprintf(pf, " "); 
	
	    fprintf(pf, "\n");
	aux2=aux2->prox;
	}

    fclose(pf);
	

}

void modificar2(lotes**e,char*a,char*b){
	lotes *aux=(*e);
	lotes *aux2=(*e);
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\LOTES.txt";
    int v,i;
	char dato3[10];
	 while(aux->prox){
	 	if(!strcmpi(aux->rubro,a))
	strcpy(aux->rubro,b);

	   aux=aux->prox;
	 }



	pf = fopen(direccion_1, "w+");

     while (aux2->prox){
    	fwrite(aux2->numero, 1, (strlen(aux2->numero)), pf);
	    fprintf(pf, " ");

	    fwrite(aux2->sucursal, 1, (strlen(aux2->sucursal)), pf);
	    fprintf(pf, " ");

	fwrite(aux2->rubro, 1, (strlen(aux2->rubro)), pf);
	fprintf(pf, " ");

	fwrite(aux2->subcategoria, 1, (strlen(aux2->subcategoria)), pf);
	fprintf(pf, " ");

	fwrite(aux2->total, 1, (strlen(aux2->total)), pf);
	fprintf(pf, " ");

	fwrite(aux2->exis, 1, (strlen(aux2->exis)), pf);
	fprintf(pf, " ");

	fwrite(aux2->peso, 1, (strlen(aux2->peso)), pf);
	fprintf(pf, " ");

	fwrite(aux2->costo, 1, (strlen(aux2->costo)), pf);
	fprintf(pf, " ");
	
	fprintf(pf, "\n");
	
	aux2=aux2->prox;
    	
	}
	

    fclose(pf);


}

void modificar3(rubros**e,char*a,char*b){
	rubros *aux=(*e);
	rubros *aux2=(*e);
	subcategoria *t=NULL;
	subcategoria *m=NULL;
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\SUBCATEGORIAS.txt";
	char dato1[20];
	char dato2[20];

	while(aux->prox){
	m=aux->abajo;
	   if (!strcmpi(aux->tipo,a)){
	      while (m){
	        strcpy(m->tipo2,b); 
	    (m)=(m)->prox;
         }
       }
	aux=aux->prox;
   }

   pf = fopen(direccion_1, "w+");

    while(aux2->prox){
	t=aux2->abajo;
	      while (t){
	      	fwrite(t->tipo2, 1, (strlen(t->tipo2)), pf);
	fprintf(pf, " "); 
	
	fwrite(t->nombre, 1, (strlen(t->nombre)), pf);
	fprintf(pf, " "); 
	
	    	fprintf(pf, "\n");
	        
	    (t)=(t)->prox;
         }
       
	aux2=aux2->prox;
   }
	

    fclose(pf);
	
 

}


void modificar31(rubros**e){
	rubros *aux=(*e);
	rubros *aux2=(*e);
	subcategoria *t=NULL;
	subcategoria *m=NULL;
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\SUBCATEGORIAS.txt";
	char dato1[20];
	char dato2[20];

	

   pf = fopen(direccion_1, "w+");

    while(aux2->prox){
	t=aux2->abajo;
	      while (t){
	      	fwrite(t->tipo2, 1, (strlen(t->tipo2)), pf);
	fprintf(pf, " "); 
	
	fwrite(t->nombre, 1, (strlen(t->nombre)), pf);
	fprintf(pf, " "); 
	
	    	fprintf(pf, "\n");
	        
	    (t)=(t)->prox;
         }
       
	aux2=aux2->prox;
   }
	

    fclose(pf);
	
 

}

void mostrar(lotes *e,char *pro,char *sub,int *o,almacenar**ang){
	    almacenar*aux=(*ang);
	    almacenar*aux2=(*ang);
        lotes *t = e;
        int cont=1; 
        printf("        LOTES         \n");
        printf("   LOTES   SUCURSAL    RUBROS     SUBCATEGORIA      \n");
        while (t->prox!=NULL){
            if((!strcmpi(t->rubro,pro))&&(!strcmpi(t->subcategoria,sub))){
            fflush(stdin);
            printf("%i.[%s]->",cont,t->numero);
            printf("[%s]->",t->sucursal);
            printf("[%s]->",t->rubro);
            printf("[%s]->\n",t->subcategoria);
            printf("\n***TOTAL***=[%s]->",t->total);
            printf("\n***EXISTENCIA***=[%s]->",t->exis);
            printf("\n\n\n"); 
            
            strcpy((aux)->codigo,t->numero);
            strcpy((aux)->nombre,t->sucursal);
            strcpy((aux)->cantidad,t->exis);
            strcpy((aux)->precio,t->costo);
        
	aux=new almacenar;
	aux->prox=aux2->prox;
	aux2->prox=aux;
            aux2=aux2->prox;
	*o=1;
	  }
	 
         t = t->prox;
         cont++;
   	}
    }



void mostrar_2(lotes *e){
        lotes *t = e;
        int cont=1;
        printf("\nLOTES\n");
         printf("   LOTES   SUCURSAL    RUBROS  SUBCATEGORIA  TOTAL EXIS  PESO  COSTO  \n ");
        while (t->prox!=NULL){

            printf("%i.[%s]->",cont,t->numero);
            printf("[%s]->",t->sucursal);
            printf("[%s]->",t->rubro);
            printf("[%s]->",t->subcategoria);
            printf("[%s]->",t->total);
            printf("[%s]->",t->exis);
            printf("[%s]->",t->peso);
            printf("[%s]\n",t->costo);
            printf("\n");
            t = t->prox;
            cont++;
        }
    }

void mostrar_1(facturas*e){
        facturas *t = e;
        int cont=1;
        printf("\nFACTURAS\n");
        printf(" FACTURA ->SUCURSAL -> FECHA -> CLIENTE -> MONTO TOTAL\n\n");
        while (t->prox!=NULL){
            fflush(stdin);
            printf("%i.[%s]->",cont,t->factura1);
            printf("[%s]->",t->sucursal_);
            printf("[%s]->",t->fecha);
            printf("[%s]->",t->cliente);
            printf("[%s]",t->monto);
            printf("\n\n");
            t = t->prox;
            cont++;
        }

    }

void mostrar_6(clientes*e){
        clientes *t = e;
        int cont=1;
        printf("\nCLIENTES\n");
        while (t->prox!=NULL){

            printf("%i.[%s]",cont,t->name);
            printf("\n\n");
            t = t->prox;
            cont++;
        }
}

void mostrar_5(sucursales*e){
        sucursales *t = e;
        int cont=1;
        printf("\nSUCURSALES\n");
        while (t->prox!=NULL){

            printf("%i.[%s]",cont,t->nombre);
            printf("\n\n");
            t = t->prox;
            cont++;
        }
}

int cargar_7(rubros**e) {
	rubros *a=(*e);
    int cont=0;
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\SUBCATEGORIAS.txt";
	char dato1[20];
	char dato2[20];

	fscanf(pf, "%s %s", &dato1, &dato2);
	rubros *aux2 = a;
	subcategoria *aux1=a->abajo,*aux3;
	pf = fopen(direccion_1, "rt");
// while
// Aqui deberia haber otro while que mueve la parte superior a proximo
// Por aqui debes hacer la comparacion (strcmpi) de factura1 con factura2
//Si son iguales  haces el otro while, sino que pase a la siguiente factura

	while (!feof(pf)) {
	rubros *aux2 = a;
	cont=0;
	 while(aux2){
	 	if (!(strcmpi((aux2->tipo),dato1))){
	 	    	aux3=new subcategoria;
	 	    	if(aux2){
	 	    	aux3->prox=aux2->abajo;
	 	    	aux2->abajo=aux3;
	 	   	    }
	             aux1=aux3;
	 	      	 cont++;
	 }
	aux2=aux2->prox;
	 }
	  if (!(cont))
	   printf("\n ");
	 	else{
	 strcpy(aux1->nombre, dato2);
	 strcpy(aux1->tipo2, dato1);
	 }
	 



	 fscanf(pf, "%s %s", &dato1, &dato2);

  }
	printf("\n descarga del archivo 7 completa\n");
	fclose(pf);
	return 0;
}

int cargar_4(rubros**e)  {

    rubros *a=(*e);
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\rubros.txt";
	char dato1[20];
	/*PRIMER PARCHE :este es un parche especial para un error que me aparecio en la compu , llena la primera casilla con la direccion de los archivos , por lo tanto hare que se salte eso , si cuando corres el programa te imprime del f002 al adelante es por culpa de este parche , en ese caso , convierte el parche en un comentario*/
	/*por ahora en facturas imprime unos digitos raros , sospecho que es el puntero , pero bueno , por ahora , si los ordena en la lista de abajo por su numero , y si el numero no esta (por ahora)  no los introduce , mas adelante le hare una condicional para que cree una nueva o valide si es necesario*/
	rubros *aux2 = a;
	pf = fopen(direccion_1, "rt");
	fscanf(pf, "%s", &dato1);

	while (!feof(pf)) {

	strcpy(a->tipo, dato1);

	aux2 = new rubros;
	aux2->abajo=NULL;
	aux2->prox = a->prox;
	a->prox = aux2;
	a = aux2;

	 fscanf(pf, "%s", &dato1);

	}



	printf(" descarga del archivo 4 completa\n");
	fclose(pf);
	return 0;
}

int cargar_5(clientes**e) {
	clientes *a=(*e);
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\CLIENTES.txt";
	char dato1[20];

	clientes *aux2 = a;
	pf = fopen(direccion_1, "rt");
	fscanf(pf, "%s", &dato1);

	while (!feof(pf)) {

	strcpy(a->name, dato1);

	aux2 = new clientes;
	aux2->prox = NULL;
	a->prox = aux2;
	a= aux2;

	 fscanf(pf, "%s", &dato1);

	}

	printf(" descarga del archivo 5 completa\n");
	fclose(pf);
	return 0;
}

int cargar_6(sucursales**e) {
	sucursales *a=(*e);
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\SUCURSALES.txt";
	char dato1[20];

	sucursales *aux2 = a;
	pf = fopen(direccion_1, "rt");
	fscanf(pf, "%s", &dato1);

	while (!feof(pf)) {

	strcpy(a->nombre, dato1);

	aux2 = new sucursales;
	aux2->prox = NULL;
	a->prox = aux2;
	a= aux2;

	 fscanf(pf, "%s", &dato1);

	}

	printf(" descarga del archivo 6 completa\n");
	fclose(pf);
	return 0;
}

int cargar_2(lotes**e) {

    lotes*a=(*e);
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\LOTES.txt";
	char dato1[5];
	char dato2[10];
	char dato3[10];
	char dato4[20];
	char dato5[10];
	char dato6[10];
	char dato7[10];
	char dato8[10];


	lotes *aux2 = a;
	pf = fopen(direccion_1, "rt");
	fscanf(pf, "%s %s %s %s %s %s %s %s", &dato1, &dato2, &dato3, &dato4, &dato5, &dato6, &dato7, &dato8);

	while (!feof(pf)) {

	strcpy(a->numero, dato1);
	strcpy(a->sucursal, dato2);
	strcpy(a->rubro, dato3);
	strcpy(a->subcategoria, dato4);
	strcpy(a->total, dato5);
	strcpy(a->exis, dato6);
	strcpy(a->peso, dato7);
	strcpy(a->costo, dato8);

	aux2 = new lotes;
	aux2->prox = NULL;
	a->prox = aux2;
	a = aux2;


	 fscanf(pf, "%s %s %s %s %s %s %s %s", &dato1, &dato2, &dato3, &dato4, &dato5, &dato6, &dato7, &dato8);

	}



	printf(" descarga del archivo 1 completa\n");
	fclose(pf);
	return 0;
}

int cargar_1(facturas**e) {
    facturas *a=(*e);
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\FACTURAS.txt";
	char dato1[5];
	char dato2[10];
	char dato3[20];
	char dato4[20];
	char dato5[10];
	/*PRIMER PARCHE :este es un parche especial para un error que me aparecio en la compu , llena la primera casilla con la direccion de los archivos , por lo tanto hare que se salte eso , si cuando corres el programa te imprime del f002 al adelante es por culpa de este parche , en ese caso , convierte el parche en un comentario*/
	/*por ahora en facturas imprime unos digitos raros , sospecho que es el puntero , pero bueno , por ahora , si los ordena en la lista de abajo por su numero , y si el numero no esta (por ahora)  no los introduce , mas adelante le hare una condicional para que cree una nueva o valide si es necesario*/
	facturas *aux2 = a;
	pf = fopen(direccion_1, "rt");
	fscanf(pf, "%s %s %s %s %s", &dato1, &dato2, &dato3, &dato4, &dato5);

	while (!feof(pf)) {

	strcpy(a->factura1, dato1);
	strcpy(a->sucursal_, dato2);
	strcpy(a->fecha, dato3);
	strcpy(a->cliente, dato4);
	strcpy(a->monto, dato5);


	aux2 = new facturas;
	aux2->abajo=NULL;
	aux2->prox = a->prox;
	a->prox = aux2;
	a = aux2;



	 fscanf(pf, "%s %s %s %s %s", &dato1, &dato2, &dato3, &dato4, &dato5);

	}



	printf(" descarga del archivo 2 completa\n");
	fclose(pf);
	return 0;
}

int cargar_3(facturas**e) {
	facturas *a=(*e);
    int cont=0;
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\DETALLESFACTURAS.txt";
	char dato1[5];
	char dato2[10];
	char dato3[10];
	char dato4[10];


	fscanf(pf, "%s %s %s %s", &dato1, &dato2, &dato3, &dato4);
	facturas *aux2 = a;
	detalle_facturas *aux1=a->abajo,*aux3;
	pf = fopen(direccion_1, "rt");


	while (!feof(pf)) {
	facturas *aux2 = a;
	cont=0;
	 while(aux2){
	 	if (!(strcmpi((aux2->factura1),dato1))){
	 	    	aux3=new detalle_facturas;
	 	    	if(aux2){
	 	    	aux3->prox=aux2->abajo;
	 	    	aux2->abajo=aux3;
	 	   	    }
	             aux1=aux3;
	 	      	 cont++;
	 }
	aux2=aux2->prox;
	 }
	  if (!(cont))
	   printf("");
	 	else{
	strcpy((aux1)->factura2, dato1);
	strcpy((aux1)->lote, dato2);
	strcpy((aux1)->unidades, dato3);
	strcpy((aux1)->precioventa, dato4);}


	 fscanf(pf, "%s %s %s %s", &dato1, &dato2, &dato3, &dato4);
	}


	printf(" descarga del archivo 3 completa\n");
	fclose(pf);
	return 0;
}


void agregar(lotes*q) {

	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\LOTES.txt";
	lotes*aux= q;
	pf = fopen(direccion_1, "at");

	fflush(stdin);
	fprintf(pf, "\n");

	fwrite(aux->numero, 1, (strlen(aux->numero)), pf);
	fprintf(pf, " ");

	fwrite(aux->sucursal, 1, (strlen(aux->sucursal)), pf);
	fprintf(pf, " ");

	fwrite(aux->rubro, 1, (strlen(aux->rubro)), pf);
	fprintf(pf, " ");

	fwrite(aux->subcategoria, 1, (strlen(aux->subcategoria)), pf);
	fprintf(pf, " ");

	fwrite(aux->total, 1, (strlen(aux->total)), pf);
	fprintf(pf, " ");

	fwrite(aux->exis, 1, (strlen(aux->exis)), pf);
	fprintf(pf, " ");

	fwrite(aux->peso, 1, (strlen(aux->peso)), pf);
	fprintf(pf, " ");

	fwrite(aux->costo, 1, (strlen(aux->costo)), pf);
	fprintf(pf, " ");

	fclose(pf);
}

int crear(lotes**c, rubros *n, sucursales *m) {
	lotes *i=*c;
	rubros *ru=n;
	rubros *ra=n;
	sucursales *s=m;
	int t=0;
	char a[5];
	char k[10];
	char d[10];
	char e[20];
	char o[20];
	char f[20];
	char y[20];
	char x[20];
	int cont=0;
	fflush(stdin);


	printf("\n indique el lote:");
	scanf("%s",a);
	    if(existe0(i,a)){
	printf("Al parecer ya existe un lote con ese codigo.Intente de nuevo\n")	;
	    return 0;
	}
	printf("\n indique la sucursal:");
	scanf("%s",k);
	if(!existe3(s,k)){
	printf("Al parecer la sucursal no existe.Intente de nuevo\n");
	    return 0;
	}

	printf("\n indique el rubro:");
	scanf("%s",d);
	if(!existe(ru,d)){
	printf("Al parecer el rubro no existe.Intente de nuevo\n");
	    return 0;
	}

	printf("\n indique la subcategoria:");
	scanf("%s",e);
	if(!existe4(ra,e,d)){
	printf("Al parecer la subcategoria no existe o no concuerda con el rubro.Intente de nuevo\n");
	    return 0;
	}

   
	lotes *aux3=new lotes;
	aux3->prox = (*c);
	(*c)= aux3;
	
	strcpy(aux3->numero,a);
	strcpy(aux3->sucursal,k);
	strcpy(aux3->rubro,d);
	strcpy(aux3->subcategoria,e);
	
	printf("\n indique la existencia:");
	scanf("%s",&o);
	strcpy(aux3->exis,o);
	
	printf("\n indique el total:");
	scanf("%s",&f);
	strcpy(aux3->total,f);

	printf("\n indique el peso:");
	scanf("%s",&y);
	strcpy(aux3->peso,y);

	printf("\n indique el costo:");
	scanf("%s",&x);
	strcpy(aux3->costo,x);
	
	agregar(aux3);
	
	
	
	return 0;	

}

void agregar2(clientes*q) {
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\CLIENTES.txt";
	clientes*aux= q;
	pf = fopen(direccion_1, "at");

	fflush(stdin);
	fprintf(pf, "\n");

	fwrite(aux->name, 1, (strlen(aux->name)), pf);
	fprintf(pf, " ");

	fclose(pf);
}

void crear2(clientes**c) {
	clientes *i=*c;
	char a[20];

	fflush(stdin);
	printf("\n indique el nombre:");
	scanf("%s",&a);
	  if(existe2(i,a))
	  	printf("Ya existe un cliente con ese nombre.Intente de nuevo\n");
	  else {
	  	clientes *aux3 = new clientes;
	aux3->prox = (*c);
	(*c)= aux3;
	strcpy(aux3->name,a);
	agregar2(aux3);
	  }

}

void agregar3(sucursales*q) {
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\SUCURSALES.txt";
	sucursales*aux= q;
	pf = fopen(direccion_1, "at");

	fflush(stdin);
	fprintf(pf, "\n");

	fwrite(aux->nombre, 1, (strlen(aux->nombre)), pf);
	fprintf(pf, " ");

	fclose(pf);
}

void crear3(sucursales**c) {
	sucursales *i=*c;
    char a[20];
	fflush(stdin);
	printf("\n indique el nombre de la sucursal:");
	scanf("%s",&a);
	   if(existe3(i,a))
	   	printf("Ya existe una sucursal con ese nombre. Intente de nuevo\n") ;
	   else {
	   sucursales *aux3 = new sucursales;
	   aux3->prox = (*c);
	   (*c)= aux3;
	   strcpy(aux3->nombre,a);
	   agregar3(aux3);
	  }

}

void mostrar_3df(facturas*a){
	int cont=0;
	facturas*aux2=a;
	detalle_facturas*b=NULL;
	printf("*********************DETALLES DE FACTURAS*****************\n");
	while(aux2){
	b=aux2->abajo;
	cont=0;
	while (b){
	    printf("-------------------------------------------------\n");
	printf("|-Numero de Factura=     %s                     |\n",b->factura2);
	printf("|-Lote=                  %s                     |\n",b->lote);
	printf("|-Unidades=              %s                     |\n",b->unidades);
	printf("|-precio de venta=       %s                     |\n",b->precioventa);
	printf("-------------------------------------------------\n");
	printf("\n");
	(b)=(b)->prox;
	cont++;
	}
	printf("\n----------------------------------------------------------------------------------\n");
	printf("\n----------------------------------------------------------------------------------\n");
	printf("\n");
	aux2=aux2->prox;
   }

}

void mostrar_4(rubros*a){
	int cont=0;
	rubros *aux2=a;
	subcategoria *b=NULL;
	printf("*********************RUBROS & SUBCATEGORIAS*****************\n");
	while(aux2->prox){
	b=aux2->abajo;
	cont=0;
	printf("Rubro= %s\n",aux2->tipo);
	while (b){
	printf("Subcategoria= %s ",b->nombre);
	printf("\n");
	(b)=(b)->prox;
	cont++;
	}
	printf("--------------------------\n");
	aux2=aux2->prox;
   }


}


void agregar4(rubros*q) {
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\rubros.txt";
	rubros*aux= q;
	pf = fopen(direccion_1, "at");

	fflush(stdin);
	fprintf(pf, "\n");

	fwrite(aux->tipo, 1, (strlen(aux->tipo)), pf);
	fprintf(pf, " ");

	fclose(pf);
}

void crear4(rubros**c) {
	rubros *i=*c;
	char a[20];
	fflush(stdin);
	printf("\n indique el nombre del rubro:");
	scanf("%s",&a);
	  if(existe(i,a))
	  	printf("Ya existe un rubro con ese nombre. Intente de nuevo\n");
	  else{
	  rubros *aux3 = new rubros;
	  aux3->prox = (*c);
	  aux3->abajo=NULL;
	  (*c)= aux3;
	  strcpy(aux3->tipo,a);
	  agregar4(aux3);
	  }
}


void agregar5(subcategoria*q) {
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\SUBCATEGORIAS.txt";
	subcategoria *aux= q;
	pf = fopen(direccion_1, "at");

	fflush(stdin);
	fprintf(pf, "\n");

	fwrite(aux->tipo2, 1, (strlen(aux->tipo2)), pf);
	fprintf(pf, " ");

	fwrite(aux->nombre, 1, (strlen(aux->nombre)), pf);
	fprintf(pf, " ");

	fclose(pf);
}

void crear5(rubros**c) {
	rubros *i=*c;
	char z[20];
	rubros *a=(*c);
	subcategoria *aux7 = new subcategoria;
	aux7->prox = NULL;
	fflush(stdin);

	printf("\n indique el nombre del rubro:");
	gets(aux7->tipo2);

	  while (strcmpi(a->tipo,aux7->tipo2)&&(a->prox)) a=a->prox;

	  if(!(a->prox)){
	   printf("No existe ese rubro.Intente de nuevo\n");
	   delete aux7;
	  }

	  else {
	  	aux7->prox=a->abajo;
	a->abajo=aux7;
	printf("\n indique la subcategoria: ");
	scanf("%s",&z);
	   if(existe5(i,z)){
	   	printf("Ya existe una subcategoria con ese nombre. Intente de nuevo\n");
	   	a->abajo=aux7->prox;
	   	delete aux7;
	   }
	   else{
	   	strcpy(aux7->nombre,z);
	    agregar5(aux7);
	  	  }
	 }
}



void consulta1(facturas *e,char *a){
	facturas *aux2=e;
	detalle_facturas *b=NULL;
	while(aux2){
	b=aux2->abajo;
	   if(!strcmpi(aux2->cliente,a)){
	  printf("\nFactura= %s",aux2->factura1);
	   	  while (b){
           printf(" \n");
	      printf("Lote= %s \n",b->lote);
	      printf("Total de unidades= %s \n",b->unidades);
	      printf("Precio de venta= %s \n",b->precioventa);
	      (b)=(b)->prox;
         }
         printf("\nMonto= %s \n",aux2->monto);
         printf("----------------------------------------------");
	 aux2=aux2->prox;
	   }
	   else
	     aux2=aux2->prox;
	}

}


void consulta2(facturas *e,char *a){
	facturas *aux2=e;
	int cont=1;
	detalle_facturas *b=NULL;
	while((aux2)&&(cont==1)){
	b=aux2->abajo;
	   if(!strcmpi(aux2->cliente,a)){
	   	  while (b){
	   	  printf("\n");
	      printf("Factura= %s \n",b->factura2);
	  printf("Lote= %s \n",b->lote);
	  printf("Total de unidades= %s \n",b->unidades);
	  printf("Precio de venta= %s \n",b->precioventa);
	  (b)=(b)->prox;
         }

	 printf("\nSucursal= %s \n",aux2->sucursal_);
         printf("\nFecha= %s \n",aux2->fecha);
         printf("\nMonto= %s \n",aux2->monto);
         printf("----------------------------------------------");
	 aux2=aux2->prox;
	 cont=2;
	   }
	   else
	     aux2=aux2->prox;
	}


}


void consulta6(rubros*t,lotes*e, char*a){
	lotes *p=e;
	rubros *q=t;
	lotes *res=e;
	   while(q){
	    subcategoria *o=q->abajo;
	   	int cont=0,cont2=0;
	    int x=0,y=0;
	      while(o){
	      	if (!strcmpi(o->nombre,p->subcategoria)){
	   	   	while(p){
	   	   	  	if(!strcmpi(p->sucursal,a)){
	   	   	  	printf("Subcategoria= %s\n",p->subcategoria);
	   	   	  	  	printf("Existencia= %s\n",p->exis);
	   	   	  	  	printf("Unidades= %s\n",p->total);
	   	   	  	  	printf("Costo= %s\n",p->costo);
	   	   	  	  	printf("\n");
	   	   	  	  	x=atoi(p->exis);
	   	   	  	  	y=atoi(p->total);
	   	   	  	  	cont+=x;
	   	   	  	  	cont2+=y;
	   	   	  	  	p=p->prox;

	  	}
	  	else
	  	  p=p->prox;
	       	}

	 p=res;
	 o=o->prox;
	}
	else
	 o=o->prox;

	     }

	  q=q->prox;
	}


}


void consulta4(rubros*t,lotes*e, char*a){
	lotes *p=e;
	rubros *q=t;
	lotes *res=e;

	   while(q){
	   	int cont=0,cont2=0;
	    int x=0,y=0;
	   	   while(p){
	   	   	  if(!strcmpi(p->sucursal,a)&&(!strcmpi(q->tipo,p->rubro))){
	   	   	  	  printf("RUBRO= %s\n",q->tipo);
	   	   	  	  printf("Existencia= %s\n",p->exis);
	   	   	  	  printf("Unidades= %s\n",p->total);
	   	   	  	  printf("Costo= %s\n",p->costo);
	   	   	  	  x=atoi(p->exis);
	   	   	  	  y=atoi(p->total);
	   	   	  	  cont+=x;
	   	   	  	  cont2+=y;
	   	   	  	  p=p->prox;

	  }
	  else
	  p=p->prox;
	}
	  p=res;

	  if((cont!=0)||(cont2!=0)){
	  	printf("\n-----------------------------------\n");
	  	printf("TOTAL EN EXISTENCIA= %i\n",cont);
	  	printf("TOTAL DE UNIDADES= %i\n",cont2);
	  	printf("\n-----------------------------------\n");
	  }


	   	  q=q->prox;
	}


}


void consulta5(lotes *e,char *a){
	lotes *t=e;
	int cont=0,cont2=0,n=0,m=0,x,y,c;
	while(t){
    
	if(!strcmpi(t->rubro,a)){
	printf("Lote= %s\n",t->numero);
	printf("Sucursal= %s\n",t->sucursal);
	printf("Existencia= %s\n",t->exis);
	printf("Unidades= %s\n",t->total);
	printf("Costo= %s\n",t->costo);
	x=atoi(t->total);
	y=atoi(t->exis);
	c=x-y;
	printf("Total de compra=%i\n",c);
	printf("\n\n");
	n=atoi(t->exis);
	m=atoi(t->total);
	cont+=n;
	cont2+=m;
	t=t->prox;
	}
	else
	t=t->prox;

	}

	 if((cont!=0)||(cont2!=0)){
	  	printf("\n-----------------------------------\n");
	  	printf("TOTAL EN EXISTENCIA= %i\n",cont);
	  	printf("TOTAL DE UNIDADES= %i\n",cont2);
	  	printf("\n-----------------------------------\n");
	 }


}

void mostrar_7(rubros *e){
        rubros *t = e;
        int cont=1;
        printf("RUBROS\n");
        while (t->prox!=NULL){

            printf("%i.[%s]",cont,t->tipo);
            printf("\n\n");
            t = t->prox;
            cont++;
        }
}


void facturacion(facturas **w,rubros**t,lotes**u, clientes *a, sucursales *b,almacenar**alm,char nom[20], char dig[20],int det,facturas**ikuso,int*reser){
	char numal[20];
	facturas*aux1=(*w);
	facturas*aux2=(*w);
	detalle_facturas*help;
	almacenar*auxl=(*alm);
	char fecha[20];
	char s[20];
	char pro[20];
	char sub[20];
	char ec[20];
	int ans=0;
	int o=0,y,x=0,res=0;
	long int total=0,def=0;
	
	
	printf("\nIndique la fecha:");
	scanf("%s",&fecha);
	printf("\n");
	printf("\n********PRODUCTOS DISPONIBLES*********\n");
	mostrar_7(*t);
	printf("******************************************\n");
	mostrar_4(*t);
	
	while(!(existe(*t,pro))){
	fflush(stdin);
	printf("\nindique el rubro:");
	scanf("\n%s",&pro);
	printf("\n");
	 if(!(existe(*t,pro)))
	   printf("\nel rubro indicado no se encuentra registrado, por favor , intentelo de nuevo...");
    }
    
    while(!(existe4(*t,sub,pro))){
	printf("\nindique la subcategoria:");
	scanf("%s",&sub);
	printf("\n");
	 if(!(existe4(*t,sub,pro)))
	  printf("la subcategoria indicada no corresponde al rubro o no existe , intente de nuevo....");
    }
	system("cls");
	mostrar(*u,pro,sub,&o,alm);
	  if(o==0){
	  	fflush(stdin);
	    printf("\n no hay existencia del producto en ninguna de nuestras sucursales. Intente de nuevo...\n");	
	    system("pause");
	ans--;
	    
	    }
	     else{
	 
	printf("\n ");
	    ans--;
	
	 auxl=(*alm);   
	while(!(existe6(*alm,s))){	
	    //se me ocurre guardar lo que mostramos en una lista , y si no esta en la lista que intente de nuevo (la lista es alm)
	 printf("\nindique la sucursal de su preferencia entre las que se muestra en pantalla:");
	 scanf("%s",&s); 
	 if(!(existe6(*alm,s)))
	  printf("la sucursal indicada no se encuentra disponible  o no existe,intente de nuevo...");	
	 }
	 while((strcmpi(auxl->nombre,s))&&(auxl))
	    	auxl=auxl->prox; 
	 fflush(stdin);
	 y=atoi(auxl->cantidad);

	 if (y==0){
	  printf("actualmente no hay disponibilidad de este producto, por favor intente con otro producto\n");
	  system("pause");
	  }
	  else{
	  	
	 while(x==0){
	 printf("EXISTENCIA DEL PRODUCTO=%i",y);
	 printf("\nindique de acuerdo a la existencia actual, cuanto desea comprar:");
	 scanf("\n%i",&x);
	 system("pause");
	  if (x>y){
	    x=0;
	   printf("\nla cantidad deseada sobrepasa la existencia del producto,por favor intente de nuevo\n");
      }
  }
  y=atoi(auxl->precio);

  //25000 de ganancia por producto
   total=y+25000;
   printf("\nel precio de venta por unidad es de =%li\n",total);
   def=total*x;
   printf("\nel precio total es de=%li\n",def);
   system("pause");
   system("cls");
   	fflush(stdin);
  printf("\n*************factura******************");  
  printf("\nCODIGO DE FACTURA=%s---------------",dig);
  printf("\nN DE LOTE=%s--------------------",auxl->codigo);
  printf("\nCLIENTE=%s-----------------------",nom);
  printf("\nFECHA=%s-------------------------",fecha);
  printf("\nSUCURSAL=%s----------------------",s);
  printf("\nPRODUCTO=%s----------------------",pro);
  printf("\nSUBCATEGORIA=%s------------------",sub);
  printf("\nCANTIDAD=%i----------------------",x);
  printf("\nPRECIO POR UNIDAD DEL PRODUCTO=%li-",total);
  printf("\nPRECIO TOTAL=%li--------------------",def);
  printf("\n**************************************");
  (*reser)+=def;
  printf("\nesta usted de acuerdo con realizar la compra? si(1)-no(0)");
  scanf("\n%s",&res);
  aux1=(*w);
   if (res){
   	if(!(det)){  
   	//while(aux1->prox){printf("%s",aux1->factura1); aux1=aux1->prox;}
   	
   	
	fflush(stdin);
   	aux2=new facturas;
   	aux2->prox=aux1->prox;
   	aux1->prox=aux2;
   	(*ikuso)=aux2;
   	strcpy(aux1->prox->factura1,dig);
   	printf("\n1.-%s",aux2->factura1);
   	strcpy(aux2->sucursal_,s);
   	printf("\n2.-%s",aux2->sucursal_);
   	strcpy(aux2->fecha,fecha);
   	printf("\n3.-%s",aux2->fecha);
    strcpy(aux2->cliente,nom);
    printf("\n4.-%s",aux2->cliente);
    itoa((*reser),numal,10);
 	strcpy(aux2->monto,numal);
 	
 	help=new detalle_facturas;
 	help->prox=aux2->abajo;
 	aux2->abajo=help;
 	strcpy(help->factura2,dig);
 	strcpy(help->lote,auxl->codigo);
 	itoa(x,numal,10);
 	strcpy(help->unidades,numal);
 	itoa(def,numal,10);
 	strcpy(help->precioventa,numal);
   	}
   	 else{
   	 	detalle_facturas*extra;
   	      (*reser)+=def;
   	 	  itoa((*reser),numal,10);
 	      strcpy((*ikuso)->monto,numal);
   	 	 
   	 	 help=(*ikuso)->abajo;
   	 	
		 extra=new detalle_facturas;
		 extra->prox=(*ikuso)->abajo;
		 (*ikuso)->abajo=extra;

		 
		 strcpy(extra->factura2,dig);
 	     strcpy(extra->lote,auxl->codigo);
 	     itoa(x,numal,10);
 	     strcpy(extra->unidades,numal);
 	     itoa(def,numal,10);
 	     strcpy(extra->precioventa,numal);
		}
   	
   	
    printf("\nguardado!");
    system("pause");
     //funciones que guardan
       }
      else if((res==0)){
	   system("pause");
       printf("\nlos datos no seran guardados");
  }
  
  system("cls");
  fflush(stdin);
}
      }
	 //AQUI LO DEJE PERO UNA VEZ QUE INTRODUZCA LA SUCURSAL Y LA EXISTENCIA, TOMAS ESOS DATOS Y CREAS OTRA RUTINA...
	 //..QUE BUSQUE ESA INFORMACION Y ACTUALICE LOS DATOS DESPUES DE LA COMPRA, CREAS LA FACTURA
	 // NOTA IMPORTANTE: NO USE LISTAS AQUI PORQUE SOLO LE PEDI LOS DATOS, PERO EN EL WHILE SE DEBE CREAR UN NUEVO NODO
	 //...QUEDA EN TUS MANOS. 
	 
	 system("cls"); 
	
	
	}
	

void modificar7(rubros**e,char*a,char*b){
	rubros *aux=(*e);
	rubros *aux2=(*e);
	subcategoria *t=NULL;
	subcategoria *m=NULL;
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\SUBCATEGORIAS.txt";
	char dato1[20];
	char dato2[20];

	while(aux->prox){
	m=aux->abajo;
	      while (m){
	      	if (!strcmpi(m->nombre,a))
	        strcpy(m->nombre,b); 
	    (m)=(m)->prox;
         }
	aux=aux->prox;
	}

   pf = fopen(direccion_1, "w+");

    while(aux2->prox){
	t=aux2->abajo;
	      while (t){
	      	fwrite(t->tipo2, 1, (strlen(t->tipo2)), pf);
	fprintf(pf, " "); 
	
	fwrite(t->nombre, 1, (strlen(t->nombre)), pf);
	fprintf(pf, " "); 
	
	    	fprintf(pf, "\n");
	        
	    (t)=(t)->prox;
         }
       
	aux2=aux2->prox;
   }
	

    fclose(pf);
	
 

}

void modificar8(lotes**e,char*a,char*b){
	lotes *aux=(*e);
	lotes *aux2=(*e);
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\LOTES.txt";

	char dato3[10];
	 while(aux->prox){
	 	if(!strcmpi(aux->subcategoria,a))
	strcpy(aux->subcategoria,b);
        
	   aux=aux->prox;
	 }
     


	pf = fopen(direccion_1, "w+");

    while (aux2->prox){
    	fwrite(aux2->numero, 1, (strlen(aux2->numero)), pf);
	    fprintf(pf, " ");

	    fwrite(aux2->sucursal, 1, (strlen(aux2->sucursal)), pf);
	    fprintf(pf, " ");

	fwrite(aux2->rubro, 1, (strlen(aux2->rubro)), pf);
	fprintf(pf, " ");

	fwrite(aux2->subcategoria, 1, (strlen(aux2->subcategoria)), pf);
	fprintf(pf, " ");

	fwrite(aux2->total, 1, (strlen(aux2->total)), pf);
	fprintf(pf, " ");

	fwrite(aux2->exis, 1, (strlen(aux2->exis)), pf);
	fprintf(pf, " ");

	fwrite(aux2->peso, 1, (strlen(aux2->peso)), pf);
	fprintf(pf, " ");

	fwrite(aux2->costo, 1, (strlen(aux2->costo)), pf);
	fprintf(pf, " ");
	
	fprintf(pf, "\n");
	
	aux2=aux2->prox;
    	
	}
  
  
  
    fclose(pf);

}


void sobre_escribir(sucursales**a){
	
	char direccion_1[] = "C:\\Users\\Usuario\\Desktop\\SUCURSALES.txt";
    sucursales *aux=(*a);
	pf = fopen(direccion_1, "w");
	fflush(stdin);
  //NOTA IMPORTANTE :los archivos almacenados directamente en c// (la carpeta principal del sistema) tiene cierta proteccion ante escritura y modificaciones , y necesitan permisos especiales para poder escribirse , razon por la cual es necesario pone algunos archivos fuera de la carpeta principal del sistema
  
  
  while(aux){
  	printf("\nwriting");
	fwrite(aux->nombre, 1, (strlen(aux->nombre)), pf);
	fprintf(pf, " \n");
    aux=aux->prox;
  }	
	fclose(pf);	
	printf("\n");
	system("pause");
}




void elim_sucursales(sucursales**suc,char a[20]){
	

	sucursales*aux=(*suc);
	sucursales*aux2=(*suc);
	
	if (!(aux->prox)){
	printf("\n no se encuentran sucursales registradas en el sistema, por favor ingrese una...\n");
	system("pause");
	}
	else{
	
	
	
   if (!strcmpi(aux->nombre,a)){
   aux=(*suc);
   (*suc)=(*suc)->prox;
   delete aux;
   aux=(*suc);
   
   }
    else{
	
   while((aux->prox)&&(strcmpi(aux->prox->nombre,a)))
      aux=aux->prox;
      
   if (aux->prox){
	   aux2=aux->prox;
	   aux->prox=aux2->prox;
	   delete aux2;
	   aux2=(*suc);
	   }
 
aux=(*suc);
aux2=(*suc);
 }
 }
}
	
	
void erradicar_cliente(facturas**a, char b[20]){
	facturas*aux=(*a);
	facturas*aux2=(*a);	
	while(aux){
	
	if(!(strcmpi(aux->cliente,b))){
	    printf("\n%s",aux->cliente);
	 	strcpy(aux->cliente,"(Anonimo)");
	 }
	aux=aux->prox;	
	}	
	system("pause");
}	
	
	
void elim_clientes(clientes**a,char b[20] ){
  	
  
    clientes*aux2=(*a);
    clientes*aux=(*a);	
	if (!(aux->prox)){
	printf("\n no se encuentran clientes registrados en el sistema, por favor ingrese uno...\n");
	system("pause");
	}
	else{
	
	
	
   if (!strcmpi(aux->name,b)){
   aux=(*a);
   (*a)=(*a)->prox;
   delete aux;
   aux=(*a);
   
   }
    else{
	
   while((aux->prox)&&(strcmpi(aux->prox->name,b)))
      aux=aux->prox;
      
   if (aux->prox){
	   aux2=aux->prox;
	   aux->prox=aux2->prox;
	   delete aux2;
	   aux2=(*a);
	   }
 
aux=(*a);
aux2=(*a);
 }
 }	
	
}


void elim_rubros(rubros**a,char b [20] ){
	rubros*aux=(*a);
	rubros*aux2=(*a);
	
	if (!(aux->prox)){
	printf("\n no se encuentran rubros registrados en el sistema, por favor ingrese uno...\n");
	system("pause");
	}
	else{
	
	
	
   if (!strcmpi(aux->tipo,b)){
   aux=(*a);
   (*a)=(*a)->prox;
   delete aux;
   aux=(*a);
   
   }
    else{
	
   while((aux->prox)&&(strcmpi(aux->prox->tipo,b)))
      aux=aux->prox;
      
   if (aux->prox){
	   aux2=aux->prox;
	   aux->prox=aux2->prox;
	   delete aux2;
	   aux2=(*a);
	   }
 
aux=(*a);
aux2=(*a);
 }
 }	
}
	
	
void elim_detallesf(facturas**a,char b [20]){
	detalle_facturas*help;
	detalle_facturas*aux,*aux2;
	facturas*aux4=(*a);
	int cont=0;
	while (aux4){
	
	help=aux4->abajo;
	aux=help;
	aux2=help;
	
	while (help){	  
	
   if (!strcmpi(aux4->abajo->lote,b)){
   aux=aux4->abajo;
   aux4->abajo=aux->prox;
   cont++;
   printf("\nprimero=nelim %s- numero=%i",b,cont);
   delete aux;
   aux=(aux4->abajo);
   aux2=aux4->abajo;
   help=aux4->abajo;
   
   }else{
   	if(help)
     help=help->prox;
 }
   
    
 if (!(aux)){
 	printf("\n deadend on this one!!");
 }
  else{
  
   while((aux->prox)&&(strcmpi(aux->prox->lote,b)))
      aux=aux->prox;
      
   if (aux->prox){
	   aux2=aux->prox;
	   aux->prox=aux2->prox;
	   cont++;
	   printf("\ndespues del primero=elim=%s- numero=%i",b,cont);
	   delete aux2;
	   aux2=(aux4->abajo);
	   }
 printf("\ndespues=fallo?  %s",b);
aux=(aux4->abajo);
aux2=(aux4->abajo);
}
 }
 aux4=aux4->prox;	
}
	
	printf("\nel lote %s fue eliminado exitosamente de los detalles de factura",b);
	}


	
void elim_lote(lotes**a,char b [20],facturas**c){
   lotes*aux=(*a);
   lotes*aux2=(*a);
   lotes*aux3=(*a);
	

	
	while (aux3->prox){
	
   if (!strcmpi(aux->rubro,b)){
   aux=(*a);
   (*a)=(*a)->prox;
   //aux contiene el lote
   printf("\n entrada al ciclo infinito help");
   printf("\n 1.-actual=%s",aux->numero);
   elim_detallesf(c,aux->numero);
   
   delete aux;
   aux=(*a);
   aux3=(*a);
   
   }
    
 
   while((aux->prox)&&(strcmpi(aux->prox->rubro,b)))
      aux=aux->prox;
      
   if (aux->prox){
	   aux2=aux->prox;
	   aux->prox=aux2->prox;
	    printf("\n 2.-actual=%s",aux2->numero);
        elim_detallesf(c,aux2->numero);
	   delete aux2;
	   aux2=(*a);
	   aux3=(*a);
	   }
 
aux=(*a);
aux2=(*a);
if(aux3)
 aux3=aux3->prox;
 
 }	
}

	

void elim_lotes_suc(lotes**a,char b [20],facturas**c){
   lotes*aux=(*a);
   lotes*aux2=(*a);
   lotes*aux3=(*a);
   facturas*aux4=(*c);
	

	
	while (aux3->prox){
	
   if (!strcmpi(aux->sucursal,b)){
   aux=(*a);
   (*a)=(*a)->prox;
   //aux contiene el lote
   printf("\n entrada al ciclo infinito help");
   printf("\n 1.-actual=%s",aux->sucursal);
   elim_detallesf(c,aux->numero);
   
   delete aux;
   aux=(*a);
   aux3=(*a);
   
   }
    
 
   while((aux->prox)&&(strcmpi(aux->prox->sucursal,b)))
      aux=aux->prox;
      
   if (aux->prox){
	   aux2=aux->prox;
	   aux->prox=aux2->prox;
	    printf("\n 2.-actual=%s",aux2->sucursal);
        elim_detallesf(c,aux2->numero);
	   delete aux2;
	   aux2=(*a);
	   aux3=(*a);
	   }
 
aux=(*a);
aux2=(*a);
if(aux3)
 aux3=aux3->prox;
 
 }
 
 while (aux4){	
	if (!strcmpi(aux4->sucursal_,b))	 
	strcpy(aux4->sucursal_,"SUCURSAL ELIMINADA");	 	
	 
	 
	 	
 aux4=aux4->prox;
 }
}




void elim_lote_sub(lotes**a,char b[20],facturas**c){
   lotes*aux=(*a);
   lotes*aux2=(*a);
   lotes*aux3=(*a);
   facturas*aux4=(*c);
	

	
	while (aux3->prox){
	
   if (!strcmpi(aux->subcategoria,b)){
   aux=(*a);
   (*a)=(*a)->prox;
   //aux contiene el lote
   printf("\n entrada al ciclo infinito help");
   printf("\n 1.-actual=%s",aux->subcategoria);
   elim_detallesf(c,aux->numero);
   
   delete aux;
   aux=(*a);
   aux3=(*a);
   
   }
    
 
   while((aux->prox)&&(strcmpi(aux->prox->subcategoria,b)))
      aux=aux->prox;
      
   if (aux->prox){
	   aux2=aux->prox;
	   aux->prox=aux2->prox;
	    printf("\n 2.-actual=%s",aux2->subcategoria);
        elim_detallesf(c,aux2->numero);
	   delete aux2;
	   aux2=(*a);
	   aux3=(*a);
	   }
 
aux=(*a);
aux2=(*a);
if(aux3)
 aux3=aux3->prox;
 
 }
 
}



void elim_sub(rubros**a,char b[20]){
	subcategoria*help;
	subcategoria*aux,*aux2;
	rubros*aux4=(*a);
	int cont=0;
	while (aux4){
	
	help=aux4->abajo;
	aux=help;
	aux2=help;
	
	while (help){	  
	
   if (!strcmpi(aux4->abajo->nombre,b)){
   aux=aux4->abajo;
   aux4->abajo=aux->prox;
   cont++;
   printf("\nprimero=nelim %s- numero=%i",b,cont);
   delete aux;
   aux=(aux4->abajo);
   aux2=aux4->abajo;
   help=aux4->abajo;
   
   }else{
   	if(help)
     help=help->prox;
 }
   
    
 if (!(aux)){
 	printf("\n deadend on this one!!");
 }
  else{
  
   while((aux->prox)&&(strcmpi(aux->prox->nombre,b)))
      aux=aux->prox;
      
   if (aux->prox){
	   aux2=aux->prox;
	   aux->prox=aux2->prox;
	   cont++;
	   printf("\ndespues del primero=elim=%s- numero=%i",b,cont);
	   delete aux2;
	   aux2=(aux4->abajo);
	   }
 printf("\ndespues=fallo?  %s",b);
aux=(aux4->abajo);
aux2=(aux4->abajo);
}
 }
 aux4=aux4->prox;	
}
	
	
	
	
}


void actualizar_existencia(lotes*a,facturas*b){
facturas*aux=b;
detalle_facturas*help;
  int x=0,y=0;
  char q[20];
  while (a){
  	x=atoi(a->total);
  	//tenemos el codigo con a->numero
  	//lo buscamos en detalle factura
  	aux=b;
  	 while(aux){
	     help=aux->abajo;
  	 	while(help){
  	 	if (!(strcmpi(help->lote,a->numero))){
  	 	y=atoi(help->unidades);
  	 	    x=x-y;
	   }
	   help=help->prox;
  	    }
  	     aux=aux->prox;	
	   } 	
  	itoa(x,q,10);
  	strcpy(a->exis,q);
  	a=a->prox;
  }
}




int codigo_factura(facturas*a){
	int cont=0;
	while(a){
	cont++;
	a=a->prox;
	}
	return cont;
}

int main() {  //ALUMNOS= ANGEL SUCASAS--GABRIEL ROMERO
	int op = 0, rep = 0,i,cont=0;
	char dato1[20];
	char dato[20];
	char g[20];

    almacenar*alm1=new almacenar;
    alm1->prox=NULL;
    
	clientes *a=new clientes;
	a->prox=NULL;

	sucursales *b=new sucursales;
	b->prox=NULL;

    subcategoria *y=NULL;
    rubros *rub=new rubros;
    rub->prox=NULL;
    rub->abajo=y;

	lotes *p = new lotes;
	p->prox = NULL;
	lotes *aux=p;

	detalle_facturas *r=NULL;
    facturas *j=new facturas;
    j->prox=NULL;
    j->abajo=r;

    facturas *aux2=j;
    facturas *aux3=j;

	cargar_2(&p);
	cargar_1(&j);
	cargar_3(&j);
	cargar_4(&rub);
	cargar_5(&a);
	cargar_6(&b);
	cargar_7(&rub);
	system("cls");


	j=aux2;

  //pendiente con los codigos(f001 , etc) en la factura , falta generarle un codigo en caso de que sea nuevo
  //sucursal->sub con existencia 0
  //dado un rubro ->ingreso bruto y neto
  //la unica de dado un lote



    do{
    system("color 1F");
    printf("\a");
	printf("*********************************BIENVENIDO AL MENU DE LA EMPRESA*******************************************\n");
	printf("**********************************************************************************************************\n");
	printf("----------------------------------------------------------------------------------------------------------");
	printf("\n1.-----------Mostrar los lotes--------------------");
	printf("||8.-----------Anadir cliente-----------------------||");
	printf("\n2.-----------Mostrar las facturas-----------------");
	printf("||9.-----------Anadir lote--------------------------||");
	printf("\n3.--Mostrar los detalles de todas las facturas----");
	printf("||10.----------Anadir sucursal----------------------||");	
	printf("\n4.-----Mostrar rubros y subcategorias-------------");
	printf("||11.----------Anadir rubro-------------------------||");
	printf("\n5.-----------Mostrar rubros-----------------------");
	printf("||12.----------Anadir subcategoria------------------||");
	printf("\n6.-----------Mostrar sucursales-------------------");
	printf("||13.----------Modificar rubro----------------------||");	
	printf("\n7.-----------Mostrar clientes---------------------");
	printf("||14.----------Modificar subcategoria---------------||");
	printf("\n                                                  ");
	printf("||15.----------Modificar Sucursal-------------------||");
	printf("\n**********************************************************************************************************");

	printf("\n16.-Dado un cliente imprimir todas las facturas-");
    printf("\n17.-Dado un cliente imprimir (1) factura--------");
	printf("\n18.-Dado un cliente imprimir total de compras por rubros-"); //FALTA
	printf("\n19.-Dada una sucursal total de existencia y unidades por rubro--");
	printf("\n20.-Dada una sucursal total de existencia y unidades por Subcategoria");
	printf("\n21.-Dado un rubro total en existencia , unidades y totales en compra-"); //2 en 1
	printf("\n*************************************************");
	printf("\n22.-----------Facturacion------------------------"); //FAlTA. 70% completado
	
	printf("\n23.prueba sobre escribir sucursales");
	
	printf("\n**************************************************");
	printf("\n24.--------eliminar sucursal----------------------");
	printf("\n25.--------eliminar cliente-----------------------");
	printf("\n26.--------eliminar rubro-------------------------");
	printf("\n27.--------eliminar subcategoria------------------");
	printf("\n28.dado un lote Imprimir datos del lote y los números de factura y cantidad en ellas de susproductos");
	printf("\n29.dada una sucursal Total de subcategorías con existencia 0.");
	
	printf("\n**************************************************");
   	printf("\n0.----------------<salir>-----------------------");
   	printf("\n-------------INDIQUE SU LA OPCION:--------------");   
   	modificar51(&j);
   	modificar41(&p);
   	modificar61(&b);
   	modificar11(&rub);
   	
	actualizar_existencia(p,j);	
	fflush(stdin);
    scanf("\n%i",&op);
	system("cls");
	switch(op){
	case 1:{ mostrar_2(p);
	            system("pause");
	            system("cls");
	    break;
	}

        case 2:{mostrar_1(j);
                i=0;
                printf("\ndesea ver el detalle de alguna factura en especifico?= si(1)-no(0)=");
                scanf("\n%i",&i);
                 if (i){
                 	printf("\n indique el numero de la factura a especificar=");
                 	scanf("\n%s",&g);
                 	facturas*help=j;
                 	while (help){
                 	
                 	if (!(strcmpi(help->abajo->factura2,g))){
                 	detalle_facturas*b=help->abajo;
	                         while (b){
	                            printf("-------------------------------------------------\n");
	                            printf("|-Numero de Factura=     %s                     |\n",b->factura2);
                             	printf("|-Lote=                  %s                     |\n",b->lote);
                            	printf("|-Unidades=              %s                     |\n",b->unidades);
	                            printf("|-precio de venta=       %s                     |\n",b->precioventa);
	                            printf("-------------------------------------------------\n");
	                            printf("\n");
                            	(b)=(b)->prox;

	                        }
                 	
	 }
                 	
                 	help=help->prox;
	 }
                 	
	 }
	           system("pause");
	           system("cls");
	   break;
	}

       case 3:{mostrar_3df(j);
               system("pause");
	           system("cls");
	  break;
	   }

	   case 4:{mostrar_4(rub);
               system("pause");
	           system("cls");
	  break;
	   }

	   case 5:{mostrar_7(rub);
               system("pause");
	           system("cls");
	   break;
	   }


	   case 6:{mostrar_5(b);
               system("pause");
	           system("cls");
	  break;
	   }

	   case 7:{mostrar_6(a);
               system("pause");
	           system("cls");
	  break;
	   }

	   case 8:crear2(&a);
	          system("pause");
	          system("cls");
	          break;

	   case 9:crear(&p,rub,b);
	          system("pause");
	          system("cls");
	          break;

	   case 10:crear3(&b);
	          system("pause");
	          system("cls");
	          break;

	   case 11:crear4(&rub);
	          system("pause");
	          system("cls");
	          break;

	   case 12:crear5(&rub);
	          system("pause");
	          system("cls");
	          break;


	   case 13: printf("Indique el rubro que desea modificar:");
	scanf("%s",dato);
	printf("\n");
	 if(existe(rub,dato)){
	 printf("Indique el cambio:");
	 scanf("%s",&dato1);
	     if(!existe(rub,dato1)){
	     	modificar3(&rub,dato,dato1);
	 	modificar1(&rub,dato,dato1);
	  	 	modificar2(&p,dato,dato1);	     	
	 }
	 
	  system("pause");
	  system("cls");	 
	 }
	 
	 else{
	  printf("No se ha encontrado ningun rubro con ese nombre\n");
	  system("pause");
	  system("cls");
	}
	break;
	
	
	case 14: printf("Indique la subcategoria que desea modificar:");
	 scanf("%s",dato);
	 printf("\n");
	 if(existe5(rub,dato)){
	 printf("Indique el cambio:");
	 scanf("%s",&dato1);
	     if(!existe5(rub,dato1)){
	     	modificar7(&rub,dato,dato1);
	  	 	modificar8(&p,dato,dato1);	     	
	 }
	 
	  system("pause");
	  system("cls");	 
	 }
	 
	 else{
	  printf("No se ha encontrado ninguna subcategoria con ese nombre\n");
	  system("pause");
	  system("cls");
	}
	break;	
	
	
	
	
	
	    case 15: printf("Indique la sucursal:");
	   	 scanf("%s",dato);
	  	 printf("\n");
	   	 if(existe3(b,dato)){
	     printf("Indique el cambio:");
	 scanf("%s",&dato1);
	   if(!existe3(b,dato1)){
	   	 modificar4(&p,dato,dato1);
	 	 modificar5(&j,dato,dato1);
	 	 modificar6(&b,dato,dato1);
	   }
	
	     system("pause");
         	     system("cls");
	}
         	   else{
	  printf("No se ha encontrado ninguna sucursal con ese nombre\n");
	  system("pause");
	  system("cls");
	}
	   break;

	

	  case 16: printf("Indique el nombre del cliente:");
	   scanf("%s",dato);
	   printf("\n");
	   if(existe2(a,dato)){
	   consulta1(j,dato);
	   system("pause");
         	   system("cls");
	   }
	   else{
	  printf("No se ha encontrado ningun cliente con ese nombre\n");
	  system("pause");
	  system("cls");
	}
	   break;

	  case 17: printf("Indique el nombre del cliente:");
	   scanf("%s",dato);
	   printf("\n");
	   if(existe2(a,dato)){
	   consulta2(j,dato);
	   system("pause");
         	   system("cls");
         	   }
	else{
	  printf("No se ha encontrado ningun cliente con ese nombre\n");
	  system("pause");
	  system("cls");
	}
	   break;

	  case 18:{
	   while(!(existe2(a,dato))){
	   printf("Indique el nombre del cliente:");
	   scanf("%s",dato);
	   printf("\n");
	   system("pause");
       system("cls");
	}
	   
	  // buscar_facturas(&j,dato);
	
	   break;
}
	 case 19:  printf("Indique la sucursal:");
	   scanf("%s",dato);
	   printf("\n");
	   if(existe3(b,dato)){
	   consulta4(rub,p,dato);
	   system("pause");
         	   system("cls");
	}
         	   else{
	  printf("No se ha encontrado ninguna sucursal con ese nombre\n");
	  system("pause");
	  system("cls");
	}
	   break;


	 case 20:  printf("Indique la sucursal:");
	   scanf("%s",dato);
	   printf("\n");
	   if(existe3(b,dato)){
	   consulta6(rub,p,dato);
	   system("pause");
         	   system("cls");
	}
	else{
	  printf("No se ha encontrado ninguna sucursal con ese nombre\n");
	  system("pause");
	  system("cls");
	}
	   break;

	 case 21:  printf("Indique el rubro:");
	   scanf("%s",dato);
	   printf("\n");
	   if(existe(rub,dato)){
	   consulta5(p,dato);
	   system("pause");
         	   system("cls");
	   }
	else{
	  printf("No se ha encontrado ningun rubro con ese nombre\n");
	  system("pause");
	  system("cls");
	}
	   break;
	   
	   
	   
	case 22: { //hacer el while fuera de la funcion y asignar el numeor fuera
	int reserva=0;
	facturas*hope;
	int ans;
	int pri=0;
	char word1[10];
	char word2[10];
	char almacen[10];
 printf("Indique el nombre:");
	  scanf("\n%s",dato);
	    if(!existe2(a,dato)){
	    	/*printf("EL cliente no esta registrado. Indique su nombre para hacerlo.\n");
	    	system("pause");
	    	system("cls");
	    	crear2(&a);
	    	printf(" EL cliente esta registrado.\n");
	    	system("pause");
	    	system("cls");*/
	    	
	    	printf("\ntiene que registrarse primero para poder hacer una compra");
	    	//solucion : solo pasa un dato nuevo;
	   } 
	  int cant=codigo_factura(j); 
	  printf("\n%i",cant);
	   if (cant<10){
	      
	      strcpy(word1,"F00");
	      itoa(cant,almacen,10);
	      printf("\n%s",almacen);
	      strcat(word1,almacen);
	      printf("\n%s",word1);
	   }
	    else{
	      strcpy(word1,"F0");
	      itoa(cant,almacen,10);
	      printf("\n%s",almacen);
	      strcat(word1,almacen);
	      printf("\n%s",word1);
	}
	
    printf("\nindique cuantos productos desea adquirir:");
	scanf("%i",&ans);
	printf("\n");
	
	while(ans!=0){
	fflush(stdin);	
	
	 facturacion(&j,&rub,&p,a,b,&alm1,dato,word1,pri,&hope,&reserva);
	 pri++;
	   system("cls");
	   ans--;
	   	actualizar_existencia(p,j);	
}
	  system("pause");
	
	   break;
	    	  	
	  }   
	    
	case 23: {sobre_escribir(&b);	
	      break;
	}
	    
	    
	case 24:{printf("\nintroduzca el nombre de la sucursal a eliminar=\n");
	         scanf("\n%s",&g);
	         elim_sucursales(&b,g);
	         elim_lotes_suc(&p,g,&j);
	
	
	break;
	}
	
	
	case 25:{
	            printf("\nintroduzca el nombre del cliente a eliminar=\n");
	            scanf("\n%s",&g);
	            elim_clientes(&a,g);
	            erradicar_cliente(&j,g);
	       
	     break;
	}
	
	
	case 26:{printf("\nintroduzca el nombre del rubro a eliminar=\n");
	        scanf("\n%s",&g);
	        elim_rubros(&rub,g);
	        elim_lote(&p,g,&j);
	    break;
	       }
	
	
	case 27:{printf("\nintroduzca el nombre de la subcategoria de rubro a eliminar=\n");
	        scanf("\n%s",&g);
	elim_lote_sub(&p,g,&j);
	elim_sub(&rub,g);
	
	
	break;
	}
	
	case 28: consulta7(j,p);
	     system("pause");
	 system("cls");
	 break;
	 
	 
    case 29: consulta8(p);
             system("pause");
	 system("cls");
	 break;

	    
	    

	
	    	

    /*la descarga del archivo 3 si esta bien , solo que los archivos f006 y f007 no se encuentran en el texto ni en m7*/
	/*falta agregar la funcion de mostrar los grumos y sus sub categorias*/


	/*NOTA IMPORTANTE:al parecer el puntero cabeza j se esta perdiendo y queda en el ultimo cuadro (el que esta antes de null), ironicamente el aux2 no se pierde , por lo tanto aux2 en este punto es el puntero cabeza*/


   }
	} while (op != 0);
	
	
	

}


