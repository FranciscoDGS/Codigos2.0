#include<conio.h>
#include<stdio.h>
#include<cmath>

int main(){
float valorfut, pago, n, val;
float interes;


printf("¿cuál es el pago mensual?: ");
scanf("%f", &pago);

printf("¿Cual es la tasa de interes mensual? (decimales): ");
scanf("%f", &interes);

printf("¿cual es el total de pagos?:  ");
scanf("%f", &n);
val = pow(1+interes,n);
valorfut=pago*(val-1)/interes;

printf("La cantidad ahorrada es un estimado de: %f", valorfut);

}
