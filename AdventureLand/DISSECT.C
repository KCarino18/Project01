/* DISSECT.C */

/* This is a quick-and-dirty source for making more sense out of */
/* the dataset in Adventureland.                                 */

/* You can redirect output to file by typing "DISSECT >filename" */
/* Morten Lohre (edb_morten@debet.nhh.no)                        */

#define CL      151+1

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
const char *NVS[2][60] =
{
  "AUTOMATIC","GO","*ENT","*RUN","*WAL","*CLI","JUMP","BEAR","CHOP","*CUT",
  "TAKE","*GET","*PIC","*CAT","LIGHT","*TUR","*LAM","*BUR","DROP","*REL",
  "*SPI","*LEA","STOP","AWAY","THROW","TOSS","QUIT","SWIM","RUB","LOOK",
  "*SHO","*SEE","DRAGON","SCORE","INVENTORY","SAVE","WAKE","UNLOCK","READ","OPEN",
  "ATTACK","*KIL","DRINK","*GAT","BUNYON","FIND","*LOC","HELP","SAY","WINDOW",
  "DOOR","SCREAM","*YEL","*HOL"," "," "," "," "," "," ",
  "ANY","NORTH","SOUTH","EAST","WEST","UP","DOWN","NET","FISH","AWAY",
  "MIRROR","AXE","AXE","WATER","BOTTLE","GAME","HOLE","LAMP","*ON","OFF",
  "DOOR","MUD","*MED","BEES","SCORE","GAS","FLINT","EGGS","OIL","*SLI",
  "KEYS","HELP","BUNYON","INVENTORY","LEDGE","THRONE","CROWN","BRICKS","BEAR","DRAGON",
  "RUG","RUBIES","HONEY","FRUIT","OX","RING","CHIGGERS","*BIT","BRACELET","SIGN",
  "BLADDER","WEB","*WRI","SWAMP","LAVA","AROUND","HALL","TREE","*STU","FIRESTONE"
};

char *ac[] = {
/* 52 */  "GET(%u)",
/* 53 */  "DROP(%u)",
/* 54 */  "GOTO_ROOM(%u)",
/* 55 */  "DELETE(%u)",
/* 56 */  "DARK(ON)",
/* 57 */  "DARK(OFF)",
/* 58 */  "SET_FLAG(%u)",
/* 59 */  "DELETE(%u)",
/* 60 */  "CLEAR_FLAG(%u)",
/* 61 */  "KILL_PLAYER",
/* 62 */  "MOVE(%u) TO LOCATION(%u)",
/* 63 */  "GAME_OVER",
/* 64 */  "LOOK",
/* 65 */  "SCORE",
/* 66 */  "INVENTORY",
/* 67 */  "SET_FLAG(1)",
/* 68 */  "CLEAR_FLAG(1)",
/* 69 */  "REFILL_LAMP",
/* 70 */  "CLEAR_SCREEN",
/* 71 */  "SAVE_GAME",
/* 72 */  "SWAP(%u) WITH (%u)"
  };

char *log[] = {
/* 1 */   "CARRIED(%u)",
/* 2 */   "PRESENT(%u)",
/* 3 */   "PRESENT_OR_CARRIED(%u)",
/* 4 */   "IS_IN(%u)",
/* 5 */   "NOT_PRESENT(%u)",
/* 6 */   "NOT_CARRIED(%u)",
/* 7 */   "IS_NOT_IN(%u)",
/* 8 */   "FLAG_SET(%u)",
/* 9 */   "FLAG_CLEARED(%u)",
/* 10 */  "OBJECTS_CARRIED",
/* 11 */  "NO_OBJECTS_CARRIED",
/* 12 */  "NOT_PRESENT_OR_CARRIED(%u)",
/* 13 */  "NOT_DELETED(%u)",
/* 14 */  "DELETED(%u)"
  };

#include <stdio.h>
#include <conio.h>

main()
{
  int i,j,k,v,v1,v2,v3,v4,p,flag;
  int x[10];

  for (i=0;i<CL;i++)
  {
    for (j=0;j<10;j++) x[j]=0;
    p = 0;
    flag = 0;
    for (j=0;j<8;j++)
    {
      v1 = C[i][j] / 150;
      v2 = C[i][j] % 150;
      v3 = C[i][j] / 20;
      v4 = C[i][j] % 20;
      if (j==0)
      {
	if (v1==0)
	  printf("At %u%% chance",v2);
	else
	{
	  printf("If command '%s",NVS[0][v1]);
	  if (v2!=0) printf(" %s'",NVS[1][v2]); else printf("'");
	}
      }
      else
      {
	if (j==6 || j==7)
	{
	  for (k=0;k<2;k++)
	  {
	    if (k==0) v=v1; else v=v2;
	    if (v!=0)
	    {
	      if (!flag)
	      {
		flag++;
		p = 0;
		printf(" do");
	      }
	      if (v>0 && v<52) printf(" MESSAGE(%u)",v);
	      if (v>101) printf(" MESSAGE(%u)",v-50);
	      if (v>51 && v<73)
	      {
		printf(" ");
		printf(ac[v-52],x[p],x[p+1]);
		if (v<61 && v!=57 && v!=56) p++;
		if (v==62 || v==72) p = p + 2;
	      }
	    }
	  }
	}
	else
	{
	  if (v4!=0)
	  {
	    printf(" and ");
	    printf(log[v4-1],v3);
	  }
	  else
	  {
	    if (v3!=0)
	    {
	      x[p]=v3;
	      p++;
	    }
	  }
	}
      }
    }
    printf("\n");
  }
}

