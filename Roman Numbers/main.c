/*
BAO DOAN
Convert a natural number (from 1 - 3000) to a Roman number
    Symbol	Value
        I	1
        V	5
        X	10
        L	50
        C	100
        D	500
        M	1,000

*/

#include<stdio.h>

// Global variables
char roman[100];
int i=0;

/* i is global variable to be the position of the newest symbol we just put it in the array*/


/* A function used to repeat filling a roman symbol depend on it value */
void filling_roman(char c,int n)
{
    int j;
    for(j=0;j<n;j++)
         roman[i++] = c;
}


int main()
{
    int j;
    long int number;

    /*Input a natural number */

    printf("Enter an natural number (1 to 3000): ");
    scanf("%d",&number);

    /* Check number from 0 to 3000*/
    if ( (number <= 0) || (number >3000))
    {
         printf("Invalid number");
         return 0;
    }

    while( (number > 0) && (number <=3000))
        {
         if(number >= 1000)
         {
             filling_roman('M',number/1000);
             number = number - (number/1000) * 1000;
         }

         else if(number >=500)
        {
             if(number < 900)
             {
                 roman[i++]='D';
                 number = number - (number/500) * 500;
             }
             else
             {
                 roman[i++]='C';
                 roman[i++]='M';
                 number = number - (900);
             }
        }

         else if(number >=100)
        {
             if(number < (400))
             {
                 filling_roman('C',number/100);
                 number = number - (number/100) * 100;
             }
             else
             {
                 roman[i++]='L';
                 roman[i++]='D';
                 number = number - (400);
             }
         }

         else if(number >=50)
        {
             if(number < (90))
             {
                 filling_roman('L',number/50);
                 number = number - (number/50) * 50;
             }
             else
             {
                 roman[i++]='X';
                 roman[i++]='C';
                 number = number - (90);
             }
         }

         else if(number >=10)
        {
             if(number < (40))
             {
                filling_roman('X',number/10);
                 number = number - (number/10) * 10;
             }
             else
             {
                 roman[i++]='X';
                 roman[i++]='L';
                 number = number - (40);
             }
         }

         else if(number >=5)
        {
             if(number < (9))
             {
                 filling_roman('V',number/5);
                 number = number - (number/5) * 5;
             }
             else
             {
                 roman[i++]='I';
                 roman[i++]='X';
                 number = number - (9);
             }
         }

         else if(number >=1)
        {
             if(number < 4)
             {
                 filling_roman('I',number/1);
                 number = number - (number/1) * 1;
             }
             else
             {
                 roman[i++]='I';
                 roman[i++]='V';
                 number = number - (4);
             }
         }

    }

    /* Print out the Roman number (all symbols in the array of Roman[i])  */

    printf("Roman number: ");
    for(j=0;j<i;j++)
         printf("%c",roman[j]);

		//getchar();
    return 0;

}


