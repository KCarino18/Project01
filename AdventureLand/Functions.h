#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED


class ThrowingWeapons
{
public:
    bool throws()
    {
        if (axe)
        {
            return 1;
        }
       else return 0;
    }
    bool pickUp()
    {
        axe = 1;
        return axe;
    }
    bool dropped()
    {
        axe = 0;
        return axe;
    }
    bool haveAxe()
    {
        return axe;
    }
private:
    bool axe = 0;
};

class Treasure : ThrowingWeapons
{
public:
    void pickupTreasure()
    {
        treasure = 1;

    }
    void dropTreasure()
    {
        treasure = 0;
    }
    void haveTreasure()
    {
        if (treasure == 1)
        {
            cout << "\nYou currenty have the " << TreasureNames[nameOfTreasure];
        }
        else
        {
            cout << "\nYou currenty do not have the " << TreasureNames[nameOfTreasure];
        }
    }
    bool treasures()
    {
        if(treasure)
        {
            return 1;
        }
        else
            return 0;
    }
    void setName(int x)
    {
        nameOfTreasure = x;
    }
private:
    bool treasure = 0;
    string TreasureNames[14] = {"Pot of Rubies.\n","Golden Fish.\n","Golden Net.\n","Royal Honey.\n",
                                   "Thick Persian Rug.\n","Gold Crown.\n","Magic Mirror.\n","Dragon Eggs.\n",
                                   "Jeweled Fruit.\n","Blue Ox.\n","Firestone.\n","Diamond Ring.\n","Diamond Bracelet.\n","Axe.\n"};
    int nameOfTreasure = 0;
};

class player
{
public:
    ThrowingWeapons axe;
    int settreasures(int x)
    {
        totalTreasures = x;
    }
    int howmany()
    {
        int yuppers;
        for(int i=0; i<13;i++)
        {
            if (allTreasures[i].treasures())
            yuppers++;
        }
        return yuppers;
    }
    void nameSetup()
    {
    rubies.setName(0);
    fish.setName(1);
    net.setName(2);
    honey.setName(3);
    rug.setName(4);
    crown.setName(5);
    mirror.setName(6);
    eggs.setName(7);
    fruit.setName(8);
    ox.setName(9);
    firestone.setName(10);
    ring.setName(11);
    bracelet.setName(12);
    }
    vector<Treasure> allTreasures{rubies,fish,net,honey,rug,crown,mirror,eggs,fruit,ox,firestone,ring,bracelet};

private:
    int totalTreasures = 0;
    Treasure rubies,fish,net,honey,rug,crown,mirror,eggs,fruit,ox,firestone,ring,bracelet;

};
signed int yes_no(void);
void empty_keyboardbuffer(void);
void welcome(void);
int get_input(void);
void look(void);
int get_item_string(int);
void turn(void);
void action(int ac, int *ip, player you);
int get_action_variable(int *ip, int x);
void carry_drop(player you);
int length(const char *s);
void copystring(char *dest, const char *source);
int comparestring(const char *s1, const char *s2);
int check_logics(void);


/* dynamic global variables */
char     IA[IL];                 /* object locations */
int      NV[2];                  /* word numbers, NV[0] = first, NV[1] = second */
int      loadflag, endflag;      /* should we load or end? */
int      f,f3,f2;
int      r, lx, df, sf;
char   tps[80];                /* input string */
int      x,y;

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
  cout << ch << "\n";
  return(ch==89);  /* 1 if Y, 0 if N */
}

/* Welcome */
void welcome(void)
{
  ClearScreen();
  cout << " W E L C O M E   T O \n A D V E N T U R E L A N D \n\n\n\n\n";
  cout << "The object of your adventure is to find treasures and return them\n";
  cout << "to the proper place for you to accumulate points.  I'm your clone.  Give me\n";
  cout << "commands that consist of a verb & noun, i.e. GO EAST, TAKE KEY, CLIMB TREE,\n";
  cout << "SAVE GAME, TAKE INVENTORY, FIND AXE, etc.\n\n";
  cout << "You'll need some special items to do some things, but I'm sure that you'll be\n";
  cout << "a good adventurer and figure these things out (which is most of the fun of\n";
  cout << "this game).\n\n";
  cout << "Note that going in the opposite direction won't always get you back to where\n";
  cout << "you were.\n\n\n";
  cout << "HAPPY ADVENTURING!!!\n\n\n\n\n";
  empty_keyboardbuffer();
  cout << "************************** Press any key to continue **************************";
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

  cout << "\nTell me what to do? ";
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
    cout << "You use word(s) I don't know.!\n";
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

  if (df && (IA[9]!=-1 && IA[9]!=r)) cout << "I can't see.  It's too dark!\n";
  else
  {
    if (RSS[r][0] == '*') cout << RSS[r]+1;
    else
    {
      cout << "I'm in a " << RSS[r];
    }
    k = -1;
    for (i=0;i<IL;i++)
    {
      if (k && (IA[i]==r))
      {
	cout << "\n\nVISIBLE ITEMS HERE:\n";
	k = 0;
      }
      if (IA[i] == r)
      {
	j = get_item_string(i);
	if ((wherex() + j + 3) > MAXLINE) cout << "\n";
	cout << IAS[i] << endl;
      }
    }
    k = -1;
    for (i=0;i<6;i++)
    {
      if (k && (RM[r][i]!=0))
      {
	cout << "\nObvious exits: \n";
	k = 0;
      }
      if (RM[r][i]!=0)
      {
	cout  << NVS[1][i + 1] << " ";
      }
    }
    cout << "\n\n";
  }
}

void turn(player you)
{
  int i,j,ac;

  if (NV[0] == 1 && NV[1] < 7)
  {
    i = (df) && (IA[9] != r) && (IA[9] != -1);
    if (i) cout << "Dangerous to move in the dark!\n";
    if (NV[1] < 1) cout << "Give me a direction too.\n";
    else
    {
      j = RM[r][NV[1] - 1];
      if (j == 0 && !i) cout << "I can't go in that direction.\n";
      else
      {
	if (j == 0 && i)
	{
	  cout << "I fell down and broke my neck.\n";
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
		action(ac,&i, you);
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
    if (NV[0] != 0) carry_drop(you);
  }
}

/* externals:
   MSS[], IA[], NV[], x, y, r, df, sf ... */
void action(int ac, int *ip, player you)
{
  FILE *fd;
  int i,j,p;

  if (ac > 101) cout << "\n" << MSS[ac - 50];    /* Messages 52 and up */
  if (ac > 0 && ac < 52) cout << "\n" << MSS[ac];  /* Messages 1 - 51 */
  if (ac == 52)
  {
    j = 0;
    for (i=1;i<IL;i++)
        if (IA[i] == -1)
        {
            j++;
        }
            if (j >= MX)
    {
      cout << "I've too much to carry!\n";
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
    cout << "I'm dead...\n";
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
    cout << "The game is now over.\nAnother game? ";
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
    cout << "I've stored " << j <<  " treasures.  On a scale\nof 0 to 100, that rates a " << j*100/TT << "." << endl;
    //cout << "I've stored " << you.howmany() <<  " treasures.  On a scale\nof 0 to 100, that rates a " << you.howmany()*100/TT << "." << endl;
    if (j == TT)
    {
      cout << "Well done.\nThe game is now over.\nAnother game? ";
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
    cout << "I'm carrying:\n";
    j = -1;
    for (i=0;i<IL;i++)
    {

      if (IA[i] == -1)
      {
	p = get_item_string(i);
	if ((p + wherex() + 2) > MAXLINE)
        cout << endl;

	cout <<IAS[i];
	you.allTreasures[i].haveTreasure();

	j = 0;
      }
    }
    if (j) cout << "Nothing!\n";
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
    cout << "Is the current drive ready to receive the saved game? ";
    if (yes_no())
    {
      fd = fopen("ADVEN-1.DAT","wb");
      putc(sf,fd);
      putc(lx,fd);
      putc(df,fd);
      putc(r,fd);
      putc(you.howmany(),fd);
      for (i=0;i<IL;i++) putc(IA[i],fd);
      fclose(fd);
    }
    cout << endl;
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
  return p;
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
void carry_drop(player x)
{
  int ll,i,j,l,k;

  if ((NV[0] == 10 || NV[0] == 18) && (!f3))
  {
    if (NV[1] == 0)
    {
      cout << "What?\n";
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
	cout << "I've too much to carry!\n";
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

		      cout << "OK,\n";//PICKING UP
		      x.allTreasures[j].pickupTreasure();
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
		      cout << "OK,\n";//DROPPING
		      x.allTreasures[j].dropTreasure();
		      j = IL;
		    }
		  }
		}
		ll = 1;
	      }
	    }
	  }
	}
	if (k == 1) cout << "I'm not carrying it!\n";
	if (k == 2) cout << "I don't see it here.\n";
	if (k == 0)
	{
	  if (!f3)
	  {
	    cout << "It's beyond my power to do that.\n";
	    f = 0;
	  }
	}
	else f = 0;
      }
    }
  }
  if (f) cout << "I don't understand your command.\n";
  else if (!f2) cout << "I can't do that yet.\n";
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
// 1 = west. 2 = north/up. 3 = east. 4 = south/down. 5 = look, 6 = jump
// 7 = swim, 8 = climb, 9 = throw, 10 = find, 11 = take, 12 = inventory, 13 = score
int movement(int x)
{
    switch(getch()) {
case 65: //up
    x = 2;
    break;
case 66://down
    x = 4;
    break;
case 67://right/east
    x = 3;
    break;
case 68://left/west
    x = 1;
    break;
}
return x;
}

#endif // FUNCTIONS_H_INCLUDED
