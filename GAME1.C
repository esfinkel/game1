#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for usleep

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

const char cheat_codes[6][5] = {".   ", "bbbf", "gdfg", "asdj", "h4h4", "erft"};

struct Player{
    int lives, hp, rank, x, y, h;
};


void stp(){
  // Standardized pause.
  usleep(500000);
}

char std(){
  // Standardized pause.
  // Also requires user input. Returns the given character.
  char c = getchar();
  stp();
  return(c);
}

void gprint(char str[]) {
  // prints in the "game" way - lots of pausing and newlines
  printf("%s",str); std(); printf("\n");
}



void printpos(struct Player p1) {
  printf("You are at position (%d, %d) with elevation %d.\n", p1.x, p1.y, p1.h);
  printf("You have %d lives, %d hp.\n", p1.lives, p1.hp);
  printf("You are currently a rank %d player.\n", p1.rank);
}

void play1(struct Player p1) {
  printf("level 1\n");

  stp(); printf("\nto be continued!\n\n"); sleep(2);
}

void play0intro(){
    stp();
  printf("level 0\n\npress enter to continue; s to skip ");
    if ('s'==std()) return;
  printf("\nyou wake up. the ground is shaking.\nwhat could it be? ");
    if ('s'==std()) return;
  printf("\na voice calls to you. ");
    if ('s'==std()) return;
  printf("\nMom: 'get up! get up! the aliens are landing!' ");
    if ('s'==std()) return;
  printf("\nRumble!\n  Rumble!\n\b\bRumble! ");
    if ('s'==std()) return;
  printf("\nfwooosh..."); getchar();
}

void play0(struct Player p1) {
  play0intro();
  
  printf("What do you do?\n");
  
  char act;
  while(!(p1.x==0 && p1.y>=4)) {
    //if (act!='\n') printf("\b\b\b\b\b\bNSEW: ");
    //scanf("%c",&act);
    if (act!='\n') printf("\b\b\b\b\b\bNSEW: ");
    scanf("%c",&act);
    switch(act) {
      case '?': printpos(p1); break;
      case 'N': p1.y += 1; break;
      case 'E': printf("Your desk is in the way.\n"); break;
      case 'S':
        if (p1.y>0) p1.y -= 1;
        else printf("Your bed is in the way.\n");
        break;
      case 'W': printf("Your bedroom wall is in the way.\n"); break;
    }
  }
  printf("\n"); fpurge(stdin); 
  printf("You stand in the entrance to your home..."); std();
  printf("\nYou blink into the sun..."); std();
  printf("\nThe light wavers as spaceships cross the sky.");
  printf("\nIt's an alien invasion!"); std(); printf("\n");
  gprint("Press enter to begin!");
  
  stp(); printf("cheat code %s\n\n", cheat_codes[1]); stp();
  play1(p1);
}


void play(int startpos, struct Player p1) {
  int x = startpos;
  
  printf("starting at level %d.\n",x);

  switch(x) {
    case 0: play0(p1); break;
    case 1: play1(p1); break;
    default: printf("level not yet constructed.\n");
  }
}

struct Player new_player() {
  struct Player p1;
  p1.lives = 3;
  p1.hp = 100;
  p1.rank = 1;
  p1.x = 0;
  p1.y = 0;
  p1.h = 0;
  return(p1);
}

int main(){
  printf("\n\n\nhello, and welcome to the game!\n");
  int startpos = 0;
  
  int num_c_codes = NELEMS(cheat_codes);
  printf("do you have a cheat code? (y/n) ");
  int has_cheat_code = (getchar()=='y'); fpurge(stdin);
  if (has_cheat_code) {
    printf("what is your cheat code? ");
    char code[4];
    scanf("%4s",code);     
    for (int i = 0; i < num_c_codes; i++) {
      if (strcmp(cheat_codes[i],code)==0) {startpos = i;}
    }
  }
  
  struct Player p1 = new_player();
  play(startpos,p1);

  return(0);
}













// some dead code
    //char action[10];
    //scanf("%10s",action);
    //while ((getchar()) != '\n');
    // fpurge(stdin);
    //for (int c = 0; c < NELEMS(action) && action[c]!='\0'; c++) {
      //printf("character %d is %c\n", c, action[c]);
    
    //if (act=='\n') printf("act is newline\n"); else printf("act is %c\n", act);
      //switch(action[c]) {

