

#include <stdlib.h>
#include <stdio.h>


struct lista{
int valor;
lista*prox;
};



int mayor (lista*p,lista*imp,int x){
int may=0;
do{
if ((imp->valor)>x){
may++; 
}
imp=imp->prox;
}while(imp!=(p));

return may;

}
 

int menor (lista*p,lista*imp,int x){
int may=0;
do{
	
	//cuidado con el copia y pega!!
	
	
if (p->prox==imp){
if ((p->valor)>x){
may++; 
}
}
p=p->prox;
}while(p!=(imp));

return may;

}

void insertar_pos_par(lista**p,lista*a,int x){
lista*aux=(*p);
lista*aux2=(*p);

if (((*p)==a)&&(a->valor%2)){
//quiere decir que solo hay impares en la lista o que solo hay un solo numero
printf("caso igual-par....\n");
do{
aux=aux->prox;
}while(aux!=(*p));
//aux queda en el ultimo aqui
//error:si hay un solo valor, no pregunta si es mayor o menor , solo lo introduce y ya, claro el caso fue hecho para el caso que solo este lleno de impar
aux2=new lista;
aux2->valor=x;
aux2->prox=aux->prox;
aux->prox=aux2;
(*p)=aux2;



}

else{

if ((menor(*p,a,x))){
printf("caso menor par!....\n\n");
while (aux->prox!=(a))
aux=aux->prox;

aux2=new lista;
aux2->valor=x;
aux2->prox=aux->prox;
aux->prox=aux2;


}
else{

	
//habia que hacer un caso especial para cuando era el mayor , ya que hay que correr el puntero
if(((*p)->valor)<x){
	printf("par mayor..\n");
	lista*aux=(*p);
	while((aux->prox)!=(*p))
	 aux=aux->prox;
	
	aux2=new lista;
    aux2->valor=x;
	aux2->prox=(*p);
	aux->prox=aux2;
	(*p)=aux2;
	}
	else{
	
do{	
	


if ((aux->valor)>x){
if (((aux->prox->valor)<x)){
aux2=new lista;
aux2->valor=x;
aux2->prox=aux->prox;
aux->prox=aux2;
}
}
aux=aux->prox;
}while(aux!=(a));

}
}



}

 

 

}

void insertar (lista**a,int x){
lista*aux=(*a);

if (!(*a)){
aux=new lista;
aux->valor=x;
aux->prox=aux;
(*a)=aux;
}
else{
while(aux->prox!=(*a))
aux=aux->prox;

lista*aux2=new lista;
aux2->valor=x;
aux2->prox=aux->prox;
aux->prox=aux2; 
}
}


void insertar_pos_imp(lista**a,lista**imp,int x){
lista*aux=(*a);
lista*auxim=(*imp);
lista*aux2=(*a);
while (aux->prox!=(*imp))
aux=aux->prox;
//aux va a quedar detras del primer impar, que seria el ultimo par

if (x<((*imp)->valor)){
printf("here...\n\n");
aux2=new lista;
aux2->valor=x;
aux2->prox=(*imp);
aux->prox=aux2;
if ((*imp)==(*a)){
(*imp)=aux2;
(*a)=(*imp);
}
else
(*imp)=aux2;
}
else{
printf("doko...\n");
if (!(mayor(*a,*imp,x))){
printf("se ha insertado un mayor impar...");
insertar(a,x);
} 
else{
do{
if ((auxim->valor)<x){
printf("primer int impar");
if ((auxim->prox->valor)>x){
printf("intento exitoso..");
aux2=new lista;
aux2->valor=x;
aux2->prox=auxim->prox;
auxim->prox=aux2;
}
}
auxim=auxim->prox;
}while(auxim!=(*a));
}



}


}

 

void ubicar_ini_imp(lista*a,lista**apuntador){
int cont=0;
lista*aux=a;

do{
if ((aux->valor%2)&&(cont==0)){
(*apuntador)=aux;
cont++;
}
aux=aux->prox;
}while(aux!=a);


}

 

int existe_im(lista*a){
int ans=0;
lista*aux=a;
do{
if ((aux->valor)%2)
ans++; 
aux=aux->prox;
}while(aux!=a);

return ans;
}

 

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
delete aux2;
aux2=aux; 
}

}

int main(){
int option=0,x=0,des,bus,res=0;
lista*p=NULL;


do{
printf("bienvenido al menu de lista circular simplemente enlazada");
printf("\n1.insertar por cola en la lista circular");
printf("\n2.mostrar la lista circular"); 
printf("\n3.eliminar un elemento en la lista circular"); 
printf("\n4.buscar elemento en la lista");
printf("\n5.ejercicio emergencia!- emparejar rondas");
printf("\n6.longitud");
printf("\n7.ordenar(menor a mayor)");
printf("\n8.insertar por ejercicio (taller 22-02-2018)");
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
break;
}
}

case 8:{ //si siempre mandamos al final los impares no habra necesidad de enviar los pares al comienzo 
printf("\n introduzca el digito a introducir en la lista=");
scanf("%i",&x);


lista*apunt_imp=p;
if (!(p)){
insertar(&p,x);
}
else{ 

if (buscar(p,x)){
printf("ya se encuentra el numero");
}
else{
if ((existe_im(p)&&((x%2)))){
printf("impar");
ubicar_ini_imp(p,&apunt_imp);
insertar_pos_imp(&p,&apunt_imp,x);
}
else if (x%2){
printf("this is worng");
insertar(&p,x);
}

if (!(x%2)){
if (existe_im(p))
ubicar_ini_imp(p,&apunt_imp);
else
apunt_imp=(p);


insertar_pos_par(&p,apunt_imp,x);

}

 

}
}
break;
}
}
}while(option!=0);
}
