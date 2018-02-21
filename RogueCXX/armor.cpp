/*
 * This file contains misc functions for dealing with armor
 * @(#)armor.c	3.9 (Berkeley) 6/15/81
 */

#include "curses.h"
#include "rogue.h"
#include "pack.cpp"
/*
 * wear:
 *	The player wants to wear something, so let him/her put it on.
 */
void
wear()
{
    thing *obj;
    register char *sp;

    if ((obj = get_item("wear", ARMOR)) == NULL)
	return;
    if (cur_armor != NULL)
    {
	addmsg("you are already wearing some");
	if (!terse)
	    addmsg(".  You'll have to take it off first");
	endmsg();
	after = false;
	return;
    }
    if (obj->o_type != ARMOR)
    {
	msg("you can't wear that");
	return;
    }
    waste_time();
    obj->o_flags |= ISKNOW;
    sp = inv_name(obj, TRUE);
    cur_armor = obj;
    if (!terse)
	addmsg("you are now ");
    msg("wearing %s", sp);
}

/*
 * take_off:
 *	Get the armor off of the players back
 */
void
take_off()
{
    register THING *obj;

    if ((obj = cur_armor) == NULL)
    {
	after = FALSE;
	if (terse)
		msg("not wearing armor");
	else
		msg("you aren't wearing any armor");
	return;
    }
    if (!dropcheck(cur_armor))
	return;
    cur_armor = NULL;
    if (terse)
	addmsg("was");
    else
	addmsg("you used to be");
    msg(" wearing %c) %s", obj->o_packch, inv_name(obj, TRUE));
}

/*
 * waste_time:
 *	Do nothing but let other things happen
 */
void
waste_time()
{
    do_daemons(BEFORE);
    do_fuses(BEFORE);
    do_daemons(AFTER);
    do_fuses(AFTER);
}
