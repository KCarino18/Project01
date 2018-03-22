/* ADVLAND.C */

/* This file is a port of ADVEN1.BAS found on PC-SIG disk #203 */
/* The port is done by Morten Lohre (edb_morten@debet.nhh.no)  */
/* It has been successfully compiled with Borland Turbo C 2.0  */

/* It's not clean, but it works. Comments included in the file */
/* are made for my personal use. If you make modifications,    */
/* please mail me a copy stating the changes.                  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <cstdio>
#include <windows.h>

class throwingWeapon // going to be the axe that you throw at the dragon.
{
public:
    throwingWeapon();
    setWeapons(bool x)
    {
        weapon = x;
    }
    getWeapons()
    {
        return weapon;
    }

private:
    bool weapon = 0;
};
signed int yes_no(void);
void empty_keyboardbuffer(void);
void welcome(void);
int get_input(void);
void look(void);
int get_item_string(int);
void turn(void);
void action(int ac, int *ip);
int get_action_variable(int *ip, int x);
void carry_drop(void);
int length(const char *s);
void copystring(char *dest, const char *source);
int comparestring(const char *s1, const char *s2);
int check_logics(void);

/* read static global data */
//#include "ADVLAND.h"



/* ADVLAND.H */
//#include "main.cpp"
/* Part of port of ADVEN1.BAS found on PC-SIG disk #203. */
/* Port done by Morten Lohre (edb_morten@debet.nhh.no)   */
/* See ADVLAND.C for more comments.                      */

#define CL      151+1
#define NL      59+1
#define RL      33+1
#define ML      71+1
#define IL      60+1
#define MX      5       /* max number of items allowed to carry */
#define AR      11      /* start location */
#define TT      13      /* number of treasures */
#define LN      3       /* number of characters in commands in item strings */
#define LT      125     /* number of steps before light goes out */
#define TR      3       /* treasure depository location */
#define MAXLINE 79      /* max number of characters on one line */

/* C0%(151), C1%(151), C2%(151), C3%(151),
   C4%(151), C5%(151), C6%(151), C7%(151) action */
const unsigned int C[CL][8] =
{
  75,161,386,160,200,0,17612,0,
  10,401,420,400,146,0,1852,8850,
  8,421,0,0,0,0,2011,0,
  8,521,520,260,0,0,2609,7800,
  100,108,760,820,420,100,8312,9064,
  100,484,0,0,0,0,5613,0,
  5,141,140,20,246,0,6062,0,
  5,406,426,400,442,146,7845,0,
  8,482,152,0,0,0,2311,0,
  100,104,0,0,0,0,8550,0,
  50,161,246,160,1100,0,7259,7800,
  100,148,140,940,500,0,9062,9900,
  30,841,426,406,400,0,7845,0,
  50,542,141,0,0,0,10504,9150,
  100,248,642,720,640,700,8005,7950,
  100,248,542,1040,540,0,8005,0,
  100,28,49,20,40,0,6360,8700,
  100,288,260,280,0,0,7860,9150,
  100,248,240,0,0,0,9660,0,
  100,269,260,0,0,0,16558,17357,
  100,28,48,20,40,0,4110,9000,
  4366,22,0,0,0,0,6900,0,
  4374,0,0,0,0,0,9750,0,
  4404,682,0,0,0,0,6900,0,
  4407,82,0,0,0,0,6900,0,
  1521,142,421,420,140,0,8902,450,
  1542,462,146,482,0,0,2311,0,
  1521,142,401,400,140,0,8902,450,
  2742,461,460,502,780,500,8864,8005,
  2742,461,460,0,0,0,7950,0,
  1523,482,146,0,0,0,2311,0,
  1523,482,141,266,0,0,2400,0,
  1523,482,141,261,260,520,8902,0,
  1533,0,0,0,0,0,9900,0,
  4350,0,0,0,0,0,10564,0,
  5100,0,0,0,0,0,9900,0,
  3450,581,344,460,0,0,8118,8614,
  2125,623,566,0,0,0,2850,0,
  2125,621,561,620,0,0,3021,9209,
  6794,0,0,0,0,0,17100,0,
  2125,622,561,620,240,0,10555,8720,
  184,404,702,380,0,0,8170,9600,
  1525,24,806,0,0,0,2400,0,
  1525,24,801,800,620,0,8902,0,
  2725,621,620,800,0,0,8902,3450,
  2125,362,561,0,0,0,3300,0,
  6803,0,0,0,0,0,17100,0,
  185,384,0,0,0,0,3750,0,
  1510,762,760,505,0,0,7800,0,
  2710,761,760,582,20,0,7986,8700,
  6343,921,920,0,0,0,509,0,
  1513,122,261,260,240,0,8902,0,
  900,384,420,726,0,0,8164,0,
  900,424,380,0,0,0,8164,0,
  185,424,502,0,0,0,3900,0,
  185,424,505,440,0,0,8170,9600,
  5265,0,0,0,0,0,10650,0,
  204,682,0,0,0,0,7650,0,
  2723,521,502,520,480,280,4259,8008,
  1513,122,266,0,0,0,2400,0,
  5751,62,0,0,0,0,300,0,
  207,40,102,0,0,0,8170,9600,
  2713,241,240,260,0,0,8902,4350,
  1528,442,440,200,0,0,8319,8294,
  1257,100,102,292,80,221,8303,1050,
  5870,104,322,286,0,0,900,0,
  5570,104,322,286,0,0,900,0,
  3611,221,60,220,0,0,4558,7950,
  5870,322,281,320,340,0,8303,9600,
  2737,721,685,720,0,0,7950,0,
  900,384,721,0,0,0,5011,0,
  2737,721,1120,900,680,720,8003,8309,
  1537,722,720,0,0,0,4852,0,
  3300,0,0,0,0,0,5100,0,
  3900,0,0,0,0,0,9813,0,
  1510,762,502,0,0,0,3900,0,
  2710,761,585,820,760,0,5303,8850,
  1050,68,765,60,0,0,16710,0,
  4800,68,60,542,0,0,5910,0,
  4950,0,0,0,0,0,9750,0,
  7050,401,0,0,0,0,16613,15750,
  7050,421,0,0,0,0,16613,15750,
  184,364,0,0,0,0,15300,0,
  1554,682,0,0,0,0,7650,0,
  7650,502,860,360,500,0,6212,8250,
  2723,521,542,480,880,540,8003,8293,
  7350,68,60,0,0,0,9001,16607,
  5870,342,0,0,0,0,9600,0,
  166,702,380,0,0,0,10554,9600,
  1050,68,760,100,80,502,8308,4710,
  6761,0,0,0,0,0,16614,0,
  5400,0,0,0,0,0,197,0,
  207,82,60,0,0,0,8170,9600,
  1257,102,221,100,80,281,8303,1200,
  6038,502,0,0,0,0,3947,0,
  6039,542,0,0,0,0,5897,0,
  6313,241,240,260,0,0,509,7800,
  6313,122,0,0,0,0,450,0,
  6342,461,460,0,0,0,509,0,
  7500,322,68,320,340,60,8303,810,
  4050,524,10,0,0,0,4950,0,
  4050,524,11,200,0,0,8170,9600,
  1200,226,0,0,0,0,5700,0,
  6600,943,221,220,500,140,2762,8700,
  6600,221,527,220,500,0,2762,9900,
  4217,183,0,0,0,0,7650,0,
  1521,142,140,0,0,0,7800,0,
  4217,203,169,960,160,0,7403,8700,
  4217,203,228,0,0,0,150,0,
  4217,203,208,220,660,960,7558,8159,
  4217,203,188,200,660,980,7558,8159,
  4217,203,168,980,180,0,7403,8700,
  7650,401,400,420,0,0,462,8902,
  7650,421,0,0,0,0,463,9150,
  4050,527,0,0,0,0,15300,0,
  3450,586,0,0,0,0,150,0,
  6600,0,0,0,0,0,150,0,
  2117,183,0,0,0,0,1500,0,
  6807,0,0,0,0,0,15450,0,
  2723,521,480,520,260,0,8009,7800,
  6780,0,0,0,0,0,15450,0,
  6771,0,0,0,0,0,15450,0,
  7200,0,0,0,0,0,15600,0,
  207,224,560,0,0,0,8170,9600,
  7050,524,0,0,0,0,16605,16350,
  7050,224,0,0,0,0,16605,0,
  7050,384,0,0,0,0,16605,0,
  7050,464,0,0,0,0,16606,0,
  7050,264,0,0,0,0,16609,0,
  7050,344,0,0,0,0,16609,0,
  7050,304,0,0,0,0,16609,0,
  7050,424,0,0,0,0,16605,0,
  7050,164,0,0,0,0,16608,0,
  5570,281,322,340,320,0,8005,0,
  206,342,120,0,0,0,8156,10564,
  2117,201,200,180,0,0,8902,1500,
  2119,181,180,200,0,0,8902,1350,
  1551,62,0,0,0,0,1711,0,
  166,1042,480,0,0,0,8170,9600,
  1549,0,0,0,0,0,16611,0,
  2100,561,365,0,0,0,3600,0,
  7650,0,0,0,0,0,150,0,
  3450,581,347,340,0,0,8118,8464,
  7050,24,0,0,0,0,16605,0,
  3611,226,0,0,0,0,5700,0,
  7050,404,0,0,0,0,16616,15450,
  6774,0,0,0,0,0,9750,0,
  166,84,100,0,0,0,8170,9600,
  1542,462,460,0,0,0,7800,0,
  7050,0,0,0,0,0,150,0,
  1200,0,0,0,0,0,197,0,
  3600,0,0,0,0,0,16800,0
};

/* NV$(59,1) commands */
const char *NVS[2][NL] =
{
  "AUT","GO","*ENT","*RUN","*WAL","*CLI","JUM","BEA","CHO","*CUT",
  "TAK","*GET","*PIC","*CAT","LIG","*TUR","*LAM","*BUR","DRO","*REL",
  "*SPI","*LEA","STO","AWA","THR","TOS","QUI","SWI","RUB","LOO",
  "*SHO","*SEE","DRA","SCO","INV","SAV","WAK","UNL","REA","OPE",
  "ATT","*KIL","DRI","*GAT","BUN","FIN","*LOC","HEL","SAY","WIN",
  "DOO","SCR","*YEL","*HOL"," "," "," "," "," "," ",
  "ANY","NORTH","SOUTH","EAST","WEST","UP","DOWN","NET","FIS","AWA",
  "MIR","AXE","AXE","WAT","BOT","GAM","HOL","LAM","*ON","OFF",
  "DOO","MUD","*MED","BEE","SCO","GAS","FLI","EGG","OIL","*SLI",
  "KEY","HEL","BUN","INV","LED","THR","CRO","BRI","BEA","DRA",
  "RUG","RUB","HON","FRU","OX","RIN","CHI","*BIT","BRA","SIG",
  "BLA","WEB","*WRI","SWA","LAV","ARO","HAL","TRE","*STU","FIR"
};

/* RM(33,5) room travel */
const unsigned char RM[RL][6] =
{
  0,7,10,1,0,24,
  23,1,1,25,0,0,
  0,0,0,0,0,1,
  1,1,1,1,1,4,
  0,0,0,0,3,5,
  0,0,0,0,4,0,
  0,0,0,0,5,7,
  8,9,0,27,6,12,
  0,7,0,0,0,0,
  7,0,0,0,20,0,
  11,10,0,1,0,26,
  11,11,23,11,0,0,
  13,15,15,0,0,13,
  0,0,0,14,12,0,
  17,12,13,16,16,17,
  12,0,13,12,13,0,
  0,17,0,0,14,17,
  17,12,12,15,14,18,
  0,0,0,0,17,0,
  0,0,0,20,0,0,
  0,0,0,0,0,9,
  0,0,0,0,0,0,
  0,0,0,21,0,0,
  10,1,10,11,0,0,
  0,0,0,0,0,0,
  11,0,1,11,0,0,
  0,0,0,0,0,0,
  0,0,7,0,0,0,
  0,0,0,0,0,11,
  0,0,0,0,0,0,
  0,0,0,0,0,0,
  0,0,0,0,0,0,
  0,0,0,0,0,0,
  0,24,11,24,28,24
};

/* RS$(33) room description */
const char *RSS[RL] = {
  " ",
  "dismal swamp.",
  "*I'm in the top of a tall cypress tree.",
  "large hollow damp stump in the swamp.",
  "root chamber under the stump.",
  "semi-dark hole by the root chamber.",
  "long down-sloping hall.",
  "large cavern.",
  "large 8-sided room.",
  "royal anteroom.",
  "*I'm on the shore of a lake.",
  "forest.",
  "maze of pits.",
  "maze of pits.",
  "maze of pits.",
  "maze of pits.",
  "maze of pits.",
  "maze of pits.",
  "bottom of a chasm.  Above 2 ledges.  One has a bricked up window.",
  "*I'm on a narrow ledge by a chasm.  Across the chasm is a throne room.",
  "royal chamber.",
  "*I'm on a narrow ledge by the throne room-across chasm-ledge.",
  "throne room.",
  "sunny meadow.",
  "*I think I'm in real trouble.  Here's a guy with a pitchfork!",
  "hidden grove.",
  "quick-sand bog.",
  "memory RAM of an IBM-PC.  I took a wrong turn!",
  "branch on the top of an old oak tree.\nTo the east I see a meadow beyond a lake.",
  " ",
  " ",
  " ",
  " ",
  "large misty room with strange letters over the exits."
};

/* MS$(71) messages */
const char *MSS[ML] =
{
  " ",
  "Nothing happens",
  "CHOP IT DOWN!",
  "Boy that really hit the spot!",
  "Dragon smells something - awakens - attacks me!",
  "Lock shatters.",
  "I can't.  It's locked.",
  "TIMBER...  Something fell from the treetop and vanished!",
  "TIMBER...",
  "Lamp is off",
  "Flameless lamp is on.",
  "I'm bit by a spider.",
  "My chigger bites are now infected.",
  "The bites have rotted my whole body.",
  "The bear eats the honey and falls asleep.",
  "Bees sting me",
  "I've no container.",
  "The bees all suffocated.",
  "Something I'm holding vibrated and...",
  "Nothing to light it with.",
  "Gas bladder blew up.",
  "in my hands!",
  "Gas needs to be contained before it will burn.",
  "Gas dissipates.",
  "That won't ignite.",
  "How?  Jump?",
  "The bear won't let me.",
  "Don't waste *HONEY*.  Get mad instead.  Dam lava!",
  "Bees madden the bear.  Bear then attacks me!",
  "It soaks into the ground.",
  "In one word tell me what.",
  "Oh no...Bear dodges...CRASH!",
  "It's heavy!",
  "Something's too heavy.  I fall.",
  "To stop game say -QUIT-",
  "The mirror hits the floor and shatters into a million pieces.",
  "Mirror lands softly on the rug - lights up and says:",
  "You lost *ALL* treasures.",
  "Not carrying the axe.  TAKE INVENTORY!",
  "It doesn't bother him at all.",
  "The mud dried up and fell off.",
  "The bear got startled and fell off the ledge!",
  "*DRAGON STINGS* and fades.  I don't get it - hope you do.",
  "The bees attack the dragon which gets up and flies away...",
  "Magic oil attracts magic lamp.  Lamp is now full.",
  "I'm bit by chiggers.",
  "There's something there all right!  Maybe I should go there?",
  "Maybe if I threw something?...",
  "Too dry.  Fish die.",
  "A glowing genie appears - drops something - then vanishes.",
  "A genie appears - says 'boy you're selfish' - takes something - then vanishes!",
  "NO!  It's too hot.",
  "Not here.",
  "Try the swamp",
  "Use one word.",
  "Try:  LOOK,JUMP,SWIM,CLIMB,THROW,FIND,GO,TAKE,INVENTORY,SCORE.",
  "Only 3 things will wake the dragon.  One of them is dangerous!",
  "If you need a hint on something, try 'HELP'.",
  "Read the sign in the meadow!",
  "You may need magic words here.",
  "A voice booms out ...",
  "PLEASE LEAVE IT ALONE!",
  "Can only throw axe.",
  "Medicine is good for bites.",
  "I don't know where it is.",
  "Treasures have an * in their name.  Say 'SCORE'",
  "Blow it up.",
  "Fish escape back to the lake.",
  " ",
  " ",
  " ",
  " "
};

/* IA$(60) item descriptions */
const char *IAS[IL] =
{
  " ",
  "dark hole",
  "*POT OF RUBIES*/RUB/",
  "spider web with writing on it.",
  "Hollow stump and remains of a felled tree.",
  "cypress tree",
  "water",
  "evil smelling mud/MUD/",
  "*GOLDEN FISH*/FIS/",
  "lit brass lamp/LAM/",
  "old fashoned brass lamp/LAM/",
  "rusty axe (magic word- BUNYON -on it)/AXE/",
  "bottle of water/BOT/",
  "empty bottle/BOT/",
  "ring of skeleton keys/KEY/",
  "sign- LEAVE TREASURE HERE - (say 'SCORE')",
  "locked door",
  "open door with a hallway beyond",
  "swamp gas",
  "*GOLDEN NET*/NET/",
  "chigger bites",
  "infected chigger bites",
  "floating patch of oily slime",
  "*ROYAL HONEY*/HON/",
  "large african bees",
  "thin black bear",
  "bees in a bottle/BOT/",
  "large sleeping dragon",
  "flint and steel/FLI/",
  "*THICK PERSIAN RUG*/RUG/",
  "sign- MAGIC WORD IS AWAY. LOOK LA -(rest of sign is missing)",
  "distended gas bladder/BLA/",
  "bricked up window",
  "sign here says- IN SOME CASES MUD IS GOOD, IN OTHERS...",
  "stream of lava",
  "bricked up window with a hole in it.  Beyond is a ledge.",
  "loose fire bricks",
  "*GOLD CROWN*/CRO/",
  "*MAGIC MIRROR*",
  "sleeping bear",
  "empty wine bladder/BLA/",
  "broken glass",
  "chiggers/CHI/",
  "dead bear",
  "*DRAGON EGGS* (very rare)/EGG/",
  "lava stream with a brick dam",
  "*JEWELED FRUIT*/FRU/",
  "*SMALL STATUE OF A BLUE OX*/OX/",
  "*DIAMOND RING*/RIN/",
  "*DIAMOND BRACELET*/BRA/",
  "strange scratchings on rock reveals- ALADDIN WAS HERE -",
  "sign says- LIMBO.  FIND RIGHT EXIT AND LIVE AGAIN!",
  "smoking hole.  Pieces of dragon and gore.",
  "sign says- NO SWIMMING ALLOWED -",
  "arrow pointing down",
  "dead fish/FIS/",
  "*FIRESTONE* (cold now)/FIR/",
  "sign says- PAUL'S PLACE -",
  "trees",
  " ",
  " "
};

/* I2(60) item locations */
const signed char I2[IL] =
{
  0,4,4,2,0,1,10,1,10,0,
  3,10,3,0,2,3,5,0,1,18,
  0,0,1,8,8,21,0,23,13,17,
  18,0,20,23,18,0,0,22,21,0,
  9,0,1,0,0,0,25,26,0,0,
  14,33,0,10,17,0,0,25,11,0,
  0
};




/* dynamic global variables */
signed char     IA[IL];                 /* object locations */
signed int      NV[2];                  /* word numbers, NV[0] = first, NV[1] = second */
signed int      loadflag, endflag;      /* should we load or end? */
signed int      f,f3,f2;
signed int      r, lx, df, sf;
char   tps[80];                /* input string */
signed int      x,y;

/* externals:
   IA[], I2[], loadflag, endflag, lx, df, sf, r, NV[] */

//HAD TO ADD THESE FUNCTIONS
void ClearScreen()
  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }

  int wherex()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.X;
}
//---------------------
int main()
{
  int i;        /* counting variable */
  FILE *fd;     /* load file handle */

  for (i=0;i<IL;i++) IA[i]=I2[i];       /* reset object locations */
  loadflag = 1;
  endflag = 0;
  srand((unsigned)time(NULL));  /* randomize */
  welcome();

  while (!endflag)
  {
    while (loadflag)
    {
      loadflag = 0;
      r = AR;
      lx = LT;
      df = 0;
      sf = 0;
      printf("\nUse saved game (Y or N)? ");
      if (yes_no()) /* yes */
      {
	printf("Is previously saved game now on the current disk? ");
	if (yes_no()) /* yes */
	{
	  fd = fopen("ADVEN-1.DAT","rb");
	  sf = fgetwc(fd);
	  lx = fgetwc(fd);
	  df = fgetwc(fd);
	  r = fgetwc(fd);
	  for (i=0;i<IL;i++) IA[i]=fgetwc(fd);
	  fclose(fd);
	}
	else loadflag = 1;      /* HERE WE GO AGAIN... */
      }
      if (!loadflag)
      {
	ClearScreen();
	look();
	NV[0] = 0;
	turn();
      }
    }
    if (!get_input())
    {
      turn();
      if (!loadflag && !endflag)
      {
	if (IA[9] == -1)
	{
	  lx--;
	  if (lx < 0)
	  {
	    printf("light has run out!\n");
	    IA[9] = 0;
	  }
	  else if (lx < 25) printf("light runs out in %u turns!",lx);
	}
	NV[0] = 0;
	turn();
      }
    }
  }
}

/* Empty keyboard buffer */
void empty_keyboardbuffer(void)
{
  while (kbhit()!=0) getch();
}

/* Empty keyboard, get Y(es) or N(o), printf character with carriage return */
int yes_no(void)
{
  int ch;

  empty_keyboardbuffer();  /* empty keyboardbuffer */
  do
  {
    ch = getch();
    if (ch > 96) ch = ch - 32;
  } while (ch!=89 && ch!=78);
  printf("%c\n",ch);
  return(ch==89);  /* 1 if Y, 0 if N */
}

/* Welcome */
void welcome(void)
{
  ClearScreen();
  printf(" W E L C O M E   T O \n A D V E N T U R E - 1 \n\n\n\n\n");
  printf("The object of your adventure is to find treasures and return them\n");
  printf("to the proper place for you to accumulate points.  I'm your clone.  Give me\n");
  printf("commands that consist of a verb & noun, i.e. GO EAST, TAKE KEY, CLIMB TREE,\n");
  printf("SAVE GAME, TAKE INVENTORY, FIND AXE, etc.\n\n");
  printf("You'll need some special items to do some things, but I'm sure that you'll be\n");
  printf("a good adventurer and figure these things out (which is most of the fun of\n");
  printf("this game).\n\n");
  printf("Note that going in the opposite direction won't always get you back to where\n");
  printf("you were.\n\n\n");
  printf("HAPPY ADVENTURING!!!\n\n\n\n\n");
  empty_keyboardbuffer();
  printf("************************** Press any key to continue **************************");
  while (getch()==0);
  ClearScreen();
}

/* Evaluate user input */
/* Externals:
   tps, NV[], NVS[][] */

int get_input(void)
{
  int i,j;              /* counting variables */
  char *word[2];        /* first and second string */
  const char  *s;

  printf("\nTell me what to do? ");
  gets(tps);
  for (i=0;i<length(tps);i++) tps[i]=toupper(tps[i]);
  i = 0;
  while (tps[i]==' ' && tps[i]!='\0') i++;  /* go to first word */
  word[0] = tps+i;
  while (tps[i]!=' ' && tps[i]!='\0') i++;  /* go to next space */
  while (tps[i]==' ' && tps[i]!='\0') i++;  /* go to next word */
  word[1] = tps+i;
  for (j=0;j<2;j++) /* no more than LN chars */
  {
    i = 0;
    while(word[j][i]!=' ' && word[j][i]!='\0' && i<LN) i++;
    word[j][i]='\0';
  }
  for (i=0;i<2;i++)
  {
    NV[i] = 0;
    if (word[i][0]!='\0')
    {
      for (j=0;j<NL;j++)
      {
	s = NVS[i][j];
	if (s[0] == '*') s++;  /* skip special char */
	if (comparestring(word[i],s)==0)
	{
	  NV[i] = j;
	  j = NL;
	  while (NVS[i][NV[i]][0] == '*') NV[i]--;
	}
      }
    }
  }
  if ((NV[0] < 1) || (word[1][0]!='\0' && NV[1] < 1))
  {
    printf("You use word(s) I don't know.!\n");
    return(1);
  }
  else return(0);
}

/* Print location description, exits and visible items */
/* Externals:
   df, IA[], RSS[][], tps, r, RM[][], NVS[][] */

void look(void)
{
  int k;        /* Flag */
  int i,j;

  if (df && (IA[9]!=-1 && IA[9]!=r)) printf("I can't see.  It's too dark!\n");
  else
  {
    if (RSS[r][0] == '*') printf(RSS[r]+1);
    else
    {
      printf("I'm in a %s",RSS[r]);
    }
    k = -1;
    for (i=0;i<IL;i++)
    {
      if (k && (IA[i]==r))
      {
	printf("\n\nVISIBLE ITEMS HERE:\n");
	k = 0;
      }
      if (IA[i] == r)
      {
	j = get_item_string(i);
	if ((wherex() + j + 3) > MAXLINE) printf("\n");
	printf("%.*s.  ",j,IAS[i]);
      }
    }
    printf("\n");
    k = -1;
    for (i=0;i<6;i++)
    {
      if (k && (RM[r][i]!=0))
      {
	printf("\nObvious exits: \n");
	k = 0;
      }
      if (RM[r][i]!=0)
      {
	printf("%s ",NVS[1][i + 1]);
      }
    }
    printf("\n\n");
  }
}

void turn(void)
{
  int i,j,ac;

  if (NV[0] == 1 && NV[1] < 7)
  {
    i = (df) && (IA[9] != r) && (IA[9] != -1);
    if (i) printf("Dangerous to move in the dark!\n");
    if (NV[1] < 1) printf("Give me a direction too.\n");
    else
    {
      j = RM[r][NV[1] - 1];
      if (j == 0 && !i) printf("I can't go in that direction.\n");
      else
      {
	if (j == 0 && i)
	{
	  printf("I fell down and broke my neck.\n");
	  j = RL;
	  df = 0;
	}
	if (!i) ClearScreen();
	r = j;
	look();
      }
    }
  }
  else
  {
    f = -1;
    f2 = -1;
    f3 = 0;
    x = 0;
    do
    {
      i = C[x][0] / 150;
      if ((NV[0] == 0) && (i != 0)) x = CL;
      else
      {
	if (NV[0] == i)
	{
	  i = C[x][0] % 150;
	  if ((i == NV[1] || i == 0) || (NV[0] == 0 && (rand()%100+1) <= i))
	  {
	    f = 0;
	    f3 = -1;
	    f2 = check_logics();
	    if (f2)
	    {
	      i = 0;
	      y = 1;
	      do
	      {
		j = (y - 1) / 2 + 6;
		ac = C[x][j] / 150;
		if (y == 2 || y == 4) ac = C[x][j] % 150;
		action(ac,&i);
		if (loadflag == 1 || endflag == 1)
		{
		  y = 10;
		  x = CL;
		}
		y++;
	      } while (y <= 4);
	      if (y < 10) if (NV[0]!= 0) x = CL;
	    }
	  }
	}
      }
      x++;
    } while (x < CL);
    if (NV[0] != 0) carry_drop();
  }
}

/* externals:
   MSS[], IA[], NV[], x, y, r, df, sf ... */
void action(int ac, int *ip)
{
  FILE *fd;
  int i,j,p;

  if (ac > 101) printf("%s\n",MSS[ac - 50]);    /* Messages 52 and up */
  if (ac > 0 && ac < 52) printf("%s\n",MSS[ac]);  /* Messages 1 - 51 */
  if (ac == 52)
  {
    j = 0;
    for (i=1;i<IL;i++) if (IA[i] == -1) j++;
    if (j >= MX)
    {
      printf("I've too much to carry!\n");
      if (NV[0] != 0) x = CL;
      y = 10;
    }
    else IA[get_action_variable(ip,x)] = -1;
  }
  if (ac == 53) IA[get_action_variable(ip,x)] = r;
  if (ac == 54) r = get_action_variable(ip,x);
  if (ac == 55 || ac == 59) IA[get_action_variable(ip,x)] = 0;
  if (ac == 56) df = -1;
  if (ac == 57) df = 0;
  if (ac == 58) sf = 1<<get_action_variable(ip,x) | sf;
  if (ac == 60) sf = sf ^ 1<<get_action_variable(ip,x);
  if (ac == 61)
  {
    printf("I'm dead...\n");
    r = RL-1;
    df = 0;
    look();
  }
  if (ac == 62)
  {
    i = get_action_variable(ip,x);
    IA[i] = (get_action_variable(ip,x));
  }
  if (ac == 63)
  {
    printf("The game is now over.\nAnother game? ");
    if (!yes_no())  /* No */ endflag = 1;
    else /* Yes */
    {
      for (i=0;i<IL;i++) IA[i] = I2[i];
      loadflag = 1;
    }
  }
  if (ac == 64) look();
  if (ac == 65)
  {
    j = 0;
    for (i=1;i<IL;i++) if (IA[i] == TR) if (IAS[i][0] == '*') j++;
    printf("I've stored %u treasures.  On a scale\nof 0 to 100, that rates a %u.\n",j,j*100/TT);
    if (j == TT)
    {
      printf("Well done.\nThe game is now over.\nAnother game? ");
      if (!yes_no())  /* No */ endflag = 1;
      else
      {
	for (i=0;i<IL;i++) IA[i] = I2[i];
	loadflag = 1;
      }
    }
  }
  if (ac == 66)
  {
    printf("I'm carrying:\n");
    j = -1;
    for (i=0;i<IL;i++)
    {
      if (IA[i] == -1)
      {
	p = get_item_string(i);
	if ((p + wherex() + 2) > MAXLINE) printf("\n");
	printf("%.*s. ",p,IAS[i]);
	j = 0;
      }
    }
    if (j) printf("Nothing!\n");
  }
  if (ac == 67) sf = 1 | sf;
  if (ac == 68) sf = sf ^ 1;
  if (ac == 69)
  {
    lx = LT;
    IA[9] = -1;
  }
  if (ac == 70) ClearScreen();
  if (ac == 71)
  {
    printf("Is the current drive ready to receive the saved game? ");
    if (yes_no())
    {
      fd = fopen("ADVEN-1.DAT","wb");
      putc(sf,fd);
      putc(lx,fd);
      putc(df,fd);
      putc(r,fd);
      for (i=0;i<IL;i++) putc(IA[i],fd);
      fclose(fd);
    }
    printf("\n");
  }
  if (ac == 72)
  {
    j = get_action_variable(ip,x);
    p = get_action_variable(ip,x);
    i = IA[j];
    IA[j] = IA[p];
    IA[p] = i;
  }
}

/* Discard unwanted string at end of item description */
/* Externals:
   IAS[] */
/* Returns number of printable characters in item description */

int get_item_string(int i)
{
  int p;

  p = length(IAS[i]); /* points to back of string */
  if (IAS[i][p-1] == '/')
  {
    do
      p--;
    while (p>0 && IAS[i][p-1]!='/');
    if (IAS[i][p-1]!='/') p = length(IAS[i]); else p--;
  }
  return(p);
}

/* Externals: C[][] */
int get_action_variable(int *p, int x)
{
  do
  {
    (*p)++;
    if (*p < 1 || *p > 5) *p = 1;
  } while (C[x][*p] % 20!=0);
  return(C[x][*p] / 20);
}

/* Can I carry or drop it? If so, do it. */
void carry_drop(void)
{
  int ll,i,j,l,k;

  if ((NV[0] == 10 || NV[0] == 18) && (!f3))
  {
    if (NV[1] == 0)
    {
      printf("What?\n");
      f = 0;
    }
    else
    {
      if (NV[0] == 10)
      {
	l = 0;
	for (i=0;i<IL;i++) if (IA[i] == -1) l++;
      }
      if (NV[0] == 10 && l >= MX)
      {
	printf("I've too much to carry!\n");
	f = 0;
      }
      else
      {
	k = 0;
	for (j=0;j<IL;j++)
	{
	  ll = length(IAS[j]) - 1;
	  if (IAS[j][ll] == '/')
	  {
	    copystring(tps,IAS[j]);
	    tps[ll] = '\0';     /* get one shorter */
	    while (ll>1)
	    {
	      ll--;
	      if (tps[ll] == '/')
	      {
		ll++;   /* first char in item name */
		tps[ll+LN] = '\0';      /* make sure string is no longer than 3 chars */
		if (comparestring(tps+ll,NVS[1][NV[1]])==0)
		{
		  if (NV[0] == 10)
		  {
		    if (IA[j] != r) k = 2;
		    else
		    {
		      IA[j] = -1;
		      k = 3;
		      printf("OK, \n");
		      j = IL;
		    }
		  }
		  else
		  {
		    if (IA[j] != -1) k=1;
		    else
		    {
		      IA[j] = r;
		      k = 3;
		      printf("OK, \n");
		      j = IL;
		    }
		  }
		}
		ll = 1;
	      }
	    }
	  }
	}
	if (k == 1) printf("I'm not carrying it!\n");
	if (k == 2) printf("I don't see it here.\n");
	if (k == 0)
	{
	  if (!f3)
	  {
	    printf("It's beyond my power to do that.\n");
	    f = 0;
	  }
	}
	else f = 0;
      }
    }
  }
  if (f) printf("I don't understand your command.\n");
  else if (!f2) printf("I can't do that yet.\n");
}

int length(const char *s)
{
  int i;

  i = 0;
  while (s[i] != '\0') i++;
  return(i);
}

void copystring(char *dest, const char *source)
{
  int i;

  i = 0;
  while (source[i]!='\0')
  {
    dest[i] = source[i];
    i++;
  }
  dest[i] = '\0';
}

int comparestring(const char *s1, const char *s2)
{
  int i;

  i = 0;
  while (s1[i]==s2[i] && s1[i]!='\0') i++;
  if (s1[i]=='\0' || s2[i]=='\0') return(0); else return(1);
}

/* externals:
   C[][], x, r, IA[], sf, f2 */
int check_logics(void)
{
  int y,ll,k,i,f1;

  f2 = -1;
  y = 1;
  do
  {
    ll = C[x][y] / 20;
    k = C[x][y] % 20;
    f1 = -1;
    if (k == 1) f1 = -(IA[ll] == -1);
    if (k == 2) f1 = -(IA[ll] == r);
    if (k == 3) f1 = -(IA[ll] == r || IA[ll] == -1);
    if (k == 4) f1 = -(r == ll);
    if (k == 5) f1 = -(IA[ll] != r);
    if (k == 6) f1 = -(IA[ll] != -1);
    if (k == 7) f1 = -(r != ll);
    if (k == 8)
    {
      f1 = sf & 1<<ll;
      f1 = -(f1 != 0);
    }
    if (k == 9)
    {
      f1 = sf & 1<<ll;
      f1 = -(f1 == 0);
    }
    if (k == 10)
    {
      f1 = 0;
      for (i=0;i<IL;i++)
      {
	if (IA[i] == -1)
	{
	  f1 = -1;
	  i = IL;
	}
      }
    }
    if (k == 11)
    {
      f1 = -1;
      for (i=0;i<IL;i++)
      {
	if (IA[i] == -1)
	{
	  f1 = 0;
	  i = IL;
	}
      }
    }
    if (k == 12) f1 = -(IA[ll] != -1 && IA[ll] != r);
    if (k == 13) f1 = -(IA[ll] != 0);
    if (k == 14) f1 = -(IA[ll] == 0);
    f2 = -(f2 && f1);
    y++;
  } while ((y <= 5) && f2);
  return(f2);
}


