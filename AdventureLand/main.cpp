/* ADVLAND.C */

/* This file is a port of ADVEN1.BAS found on PC-SIG disk #203 */
/* The port is done by Morten Lohre (edb_morten@debet.nhh.no)  */
/* It has been successfully compiled with Borland Turbo C 2.0  */

/* It's not clean, but it works. Comments included in the file */
/* are made for my personal use. If you make modifications,    */
/* please mail me a copy stating the changes.                  */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <cstdio>
#include <windows.h>
#include <vector>
#include <assert.h>
#include "assert.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;



#include "Arrays.h"
#include "Functions.h"

//---------------------
int main()
{
  srand(time(NULL));  /* randomize */
  player you;
  you.nameSetup();
  int i;        /* counting variable */
  FILE *fd;     /* load file handle */

  for (i=0;i<IL;i++)
  {
    IA[i]=I2[i];       /* reset object locations */
  }
  bool loadflag = 1;
  bool endflag = 0;

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
      cout << "\nUse saved game (Y or N)? ";
      if (yes_no()) /* yes */
      {
	cout << "Is previously saved game now on the current disk? ";
	if (yes_no()) /* yes */
	{
	  fd = fopen("ADVEN-1.DAT","rb");
	  sf = fgetwc(fd);
	  lx = fgetwc(fd);
	  df = fgetwc(fd);
	  r = fgetwc(fd);
	  save = fgetwc(fd);
	  one = fgetwc(fd);
	  two =fgetwc(fd);
	  three = fgetwc(fd);
	  four = fgetwc(fd);
	  five = fgetwc(fd);
	  six = fgetwc(fd);
	  seven =fgetwc(fd);
	  eight = fgetwc(fd);
	  nine = fgetwc(fd);
	  ten = fgetwc(fd);
	  eleven = fgetwc(fd);
	  twelve = fgetwc(fd);
	  thirteen = fgetwc(fd);
      you.allTreasures[one].pickupTreasure();
      you.allTreasures[two].pickupTreasure();
      you.allTreasures[three].pickupTreasure();
      you.allTreasures[four].pickupTreasure();
      you.allTreasures[five].pickupTreasure();
      you.allTreasures[six].pickupTreasure();
      you.allTreasures[seven].pickupTreasure();
      you.allTreasures[eight].pickupTreasure();
      you.allTreasures[nine].pickupTreasure();
      you.allTreasures[ten].pickupTreasure();
      you.allTreasures[eleven].pickupTreasure();
      you.allTreasures[twelve].pickupTreasure();
      you.allTreasures[thirteen].pickupTreasure();
	  for (i=0;i<IL;i++) IA[i]=fgetwc(fd);
	  fclose(fd);
	  you.settreasures(save);
	}

	else
    {
    loadflag = 1;      /* HERE WE GO AGAIN... */
    assert(one = -1);
    assert(two = -1);
    assert(three = -1);
    assert(four = -1);
    assert(five = -1);
    assert(six = -1);
    assert(seven = -1);
    assert(eight = -1);
    assert(nine = -1);
    assert(ten = -1);
    assert(eleven = -1);
    assert(thirteen = -1);
    assert(twelve = -1);
    }
      }
      if (!loadflag)
      {

	ClearScreen();
	look();
	NV[0] = 0;
	turn(you);
      }
    }

    if (!get_input())
    {
      turn(you);
      if (!loadflag && !endflag)
      {
	if (IA[9] == -1)
	{
	  lx--;
	  if (lx < 0)
	  {
	    cout << "light has run out!\n";
	    IA[9] = 0;
	  }
	  else if (lx < 25) cout << "light runs out in " << lx << " turns!";
	}
	NV[0] = 0;
	turn(you);
      }
    }
  }
}

/* Empty keyboard buffer */



