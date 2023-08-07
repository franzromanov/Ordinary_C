#include <stdio.h>
#include <stdlib.h>
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

    Copyright (C) 2023  Moh.Naufal Hizbullah

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
double opr1,opr2,ACM;
char op;

//Function_Declaration

//addition------------------------[1]
int ADD_CALC(int opr1,int opr2){
 return opr1+opr2;
}

//substraction--------------------[2]


//main
int main(){
//user_input
 //title_
 fprintf(stdout,"\e[0;91m-----\e[0;97mBASIC \e[0;94mCALCULATOR\e[0;91m-----\n\n"); 
 fprintf(stdout,"\e[0;91m[INPUT]\e[0;97m:\n");
 //ask
 fscanf(stdin,"%lf%c%lf",&opr1,&op,&opr2);

//operation
 switch(op){
  case '+':
   ACM=ADD_CALC(opr1,opr2);
   break;
}

//out
 fprintf(stdout,"= %f\n",ACM);
 
//esc
 return 0;
}
