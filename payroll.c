#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define SalMin 1212.00		//SalC!rio minimo vingente

 char name[25];

int end, hed, hen, nd, fal, i;

float desc_e, ref, val, sal, time_ex, family_sal, gross_sal, inamps, faults,
  incomeTax, t_discount, net_salary;

 
void
InfoFunc ()
{
  
 
time_ex = (hed * sal / 160) + (hen * 1.2 * sal / 160);
  
family_sal = nd * 0.05 * SalMin;
  
gross_sal = sal + time_ex + family_sal;

} 
 
void

Descouts ()
{
  
 
inamps = 0.08 * sal;
  
faults = (fal * sal) / 160;
  
incomeTax = 0.08 * gross_sal;
  
t_discount = inamps + faults + ref + val + desc_e + incomeTax;
  
net_salary = gross_sal - t_discount;

} 
 
void

imprimir ()
{				// Imprime as informaC'C5es do funcionC!rio na tela
  
printf
    ("\n\n ---------------------------------------------------------------------\n\n");
  
printf
    ("\n  ================ INFORMACCES DO FUNCIONCRIO ================\n");
  
printf ("\n | Nome: %s", name);
  
printf ("\n | SC!lario: R$%.2f\n", sal);
  
printf ("\n | Horas Extras: R$%.2f\n", time_ex);
  
printf ("\n | SalC!rio FamC-lia: R$%.2f\n", family_sal);
  
printf ("\n | SalC!rio Bruto: R$%.2f\n", gross_sal);
  
printf ("\n\n  =============== DESCONTOS EFETUADOS ===============\n");
  
printf ("\n | INAMPS: R$%.2f\n", inamps);
  
printf ("\n | Faltas: R$%.2f\n", faults);
  
printf ("\n | RefeiC'C5es: R$%.2f\n", ref);
  
printf ("\n | Vales: R$%.2f\n", val);
  
printf ("\n | Descontos Eventuais: R$%.2f\n", desc_e);
  
printf ("\n | Imposto de Renda: R$%.2f\n", incomeTax);
  
printf ("\n | SalC!rio LC-quido: R$%.2f\n", net_salary);
  
printf
    ("\n\n ---------------------------------------------------------------------\n");

} 
 
int

main ()
{
  
setlocale (LC_ALL, "Portuguese");
  
 
  do
    {				//Coleta as informC'C5es do empregado
      printf
	("\n =============== EMISSCO DA FOLHA DE PAGAMENTO ===============\n");
      
printf ("\n Nome do funcionC!rio: ");
      
fgets (name, 25, stdin);
      
printf ("\n SalC!rio: R$");
      
scanf ("%f", &sal);
      
printf ("\n Horas extras diurnas: ");
      
scanf ("%d", &hed);
      
printf ("\n Horas extras noturnas: ");
      
scanf ("%d", &hen);
      
printf ("\n NC:mero de dependentes: ");
      
scanf ("%d", &nd);
      
printf ("\n Faltas em horas: ");
      
scanf ("%d", &fal);
      
printf ("\n Descontos eventuais: R$");
      
scanf ("%f", &desc_e);
      
printf ("\n Gastos com refeiC'C5es na empresa: R$");
      
scanf ("%f", &ref);
      
printf ("\n Vales retirados durante o mC*s: R$");
      
scanf ("%f", &val);
      
 
InfoFunc ();		//Trablha com as informaC'C5es do funcionC!rio
      Descouts ();		//Trabalha com os valores dos descontos eventuais
      imprimir ();		//Imprime dados da folha de pagamento
      
printf
	("\n\n Deseja emitir uma nova folha de pagamento? [1 - Sim, 0 - NC#o]: ");
      
scanf ("%d", &end);
    
 
}
  while (end != 0);
  
 
return 0;

}


 
 
