#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*
    Basic_Calc: Basic calculator for c language project starter
    this calculator include:

    *-----------------------------------------------*
    * -Addition                                     *
    * -Substraction                                 *
    * -Division                                     *
    * -Multiplication                               *
    * -Modulo                                       *
    * -Exponent                                     *
    *-----------------------------------------------*

    Copyright (C) 2023  Michael Navallo Higgins

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


//declare
bool stat=false;
int stop=1;
double opr1,opr2,ACM;
char op;

//Function_Declaration

//addition------------------------[1]
float ADD_CALC(float opr1,float opr2){
 return opr1+opr2;
}

//substraction--------------------[2]
float SUB_CALC(float opr1,float opr2){
 return opr1-opr2;
}

//multiplication------------------[3]
float MLTPLY_CALC(float opr1, float opr2){
 return opr1*opr2;
}

//division------------------------[4]
float DIV_CALC(float opr1, float opr2){ 
 return opr1/opr2;
}

//modulo--------------------------[5]
float MOD_CALC(float opr1, float opr2){
 return opr1/opr2;
}

//exponent------------------------[6]
float EXP_CALC(float opr1,float opr2){
 opr2=(int)opr2;
 float dump=1;
 for(int i=0;i<opr2;i++)dump*=opr1;
 return dump;
}


//main
int main(){

//user_input
 //title_
 fprintf(stdout,"\e[0;91m-----\e[0;97mBASIC \e[0;94mCALCULATOR\e[0;91m-----\n\n"); 
 while(1){
   if(stop==0)break;
   fprintf(stdout,"\n\e[0;91m[INPUT]\e[0;97m:\n");
   //ask
   fscanf(stdin,"%lf%c%lf",&opr1,&op,&opr2);
   printf("%c\n",op);
  //operation
   switch(op){
    //---------------------------[1]
    case '+':
     ACM=ADD_CALC(opr1,opr2);
     break;
    //---------------------------[2]
    case '-':
     ACM=SUB_CALC(opr1,opr2);
     break; 
    //---------------------------[3]
    case '*':
     ACM=MLTPLY_CALC(opr1,opr2);
     break;
    //---------------------------[4]
    case '/':
     ACM=DIV_CALC(opr1,opr2);
     break;
    //---------------------------[5]
    case '%':
     ACM=MOD_CALC(opr1,opr2);
     break;
    //---------------------------[6]
    case '^':
     ACM=EXP_CALC(opr1,opr2);
     break;
  //-----------------------------------------------------------//
    default:
     fprintf(stdout,"\e[0;91mWRONG INPUT!!!\n\n");
     stat= ~stat;//toggled
     break;
  }

  //out
   if(stat!=true)fprintf(stdout,"= %f\n",ACM);
   if(stat==true)stat=false;//toggled
   printf("%d\n",stat);
   fprintf(stdout,"\e[0;91mEXIT-->PRESS 0\n\e[0;94mCONTINUE-->PRESS 1.......\n");
   stop=1;
   fscanf(stdin,"%d",&stop);
   op=0;
}
//esc
 return 0;
}
