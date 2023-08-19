#include "frank_talk.h"

//banner------------------------------------------------------------------------[1]
void banner(){
//declare
 int c=0;

//form_banner
 char line_1[]="\n\e[0;97m:::::::::::::::::::::::::::::::::::::\n";
 char line_2[]="::::-----------------------------::::\n";
 char line_3[]=":::\e[0;30m\e[47m WELCOME TO ROCK PAPER SCISSOR \e[0;97m:::\n";
 char line_4[]="::::*****************************::::\n";
 char line_5[]=":::-----------\e[0;30m\e[47m THE GAME \e[0;97m----------:::\n";
 char line_6[]="::::-----------------------------::::\n";
 char line_7[]=":::::::::::::::::::::::::::::::::::::\n\n";

//mem_manage
 char **paragraph;
 char *dump;
 paragraph=malloc(sizeof(char*)*7);
 paragraph[0]=line_1;
 paragraph[1]=line_2;
 paragraph[2]=line_3;
 paragraph[3]=line_4;
 paragraph[4]=line_5;
 paragraph[5]=line_6;
 paragraph[6]=line_7;

//printout
 for(int i=0;i<7;i++){
  fprintf(stdout,"%s",paragraph[i]);
  fflush(stdout);
  usleep(75000);
}

//free_memory
 free(paragraph);
}


//greet---------------------------------------------------------------------------[2]
int frank_greet(){

//declare
 char ask;
 char **paragraph;

//sentences
 char line_1[]="[^ _ ^]/ : \"Greetings, my merry friend!\"\n";
 char line_2[]="[^ .^]-  : \"Welcome To Rock Paper Scissor game!\"\n";
 char line_3[]="[o 3o]\\  : \"Now shall I and thou engage in play?\"\n";
 char line_4[]="[You]    : (Y for we shall play, N for tis thou fly away)\n";

//mem_manage
 paragraph=malloc(sizeof(char*)*4);
 paragraph[0]=line_1;
 paragraph[1]=line_2;
 paragraph[2]=line_3;
 paragraph[3]=line_4;

 for(int i=0; i<4; i++){
  fprintf(stdout,"%s",paragraph[i]);
  fflush(stdout);
  sleep(1);
}
 //asking_input
 fscanf(stdin,"%c",&ask);

//esc
 if(ask=='Y'||ask=='y')return 1;
 else return 0;
}

//play_react-----------------------------------------------------------------------[3]
int frank_react(int frank,int player){

 //hit
 if(frank>player){
  //dialog
  char gotcha[]="[> 3 o]/ : \"Aye, Gotcha Lad!\"\n";
  fprintf(stdout,"%s",gotcha);
  //esc
  return 1;
}
 //parry
 if(frank==player){
  //dialog
  char focus[]="[o .o]   : \"A splendid move thou hast made!\"\n";
  fprintf(stdout,"%s",focus);
  //esc
  return 0;
}

//damaged
 if(frank<player){
  //dialog
  char ouch[]="[T o T]  : \"OUCH,Tis Hurts!!!\"\n";
  fprintf(stdout,"%s",ouch);
 //esc
 return (-1);
}

}
