//FRANKLIN_TALK_MOD
//theme:MONOCHROME[B&W]
#include "frank_talk.h"

//declare
int c=0;

//banner
void banner(){
//form_banner
 char line_1[]="\e[0;97m:::::::::::::::::::::::::::::::::::::\n";
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
/*
//greet
void frank_greet(){


}

//play_chat
void frank_play(){




}
*/
