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

using std::cin;
using std::cout;
using std::endl;
using std::string;


#include "Arrays.h"
#include "Functions.h"

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
//---------------------
int main()
{

  player you;
  int i;        /* counting variable */
  FILE *fd;     /* load file handle */

  for (i=0;i<IL;i++)
  {
    IA[i]=I2[i];       /* reset object locations */
  }
  bool loadflag = 1;
  bool endflag = 0;
  srand(time(NULL));  /* randomize */
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



