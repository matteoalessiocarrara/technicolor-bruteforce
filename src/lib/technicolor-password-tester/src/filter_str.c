/*
 * Copyright 2016 Matteo Alessio Carrara <sw.matteoac@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

/* Funzioni che lavorano su una password rappresentata come stringa */

# include <stdbool.h>

# include "lib/readability/src/readability.h"

# include "filter_str.h"
# include "filter_int.c"
# include "debug.h"


/* Controlla se il carattere ch è 'A', 'B', 'C', 'D', 'E' o 'F' */
# define is_af(ch) (((ch) >= 'A') and ((ch) <= 'F'))

/* Controlla se il carattere ch è un numero, in ASCII */
# define is_09(ch) (((ch) >= '0') and ((ch) <= '9'))


/* La stringa può essere composta solo da caratteri 0-9 A-F
 * Restituisce true se la password è corretta, false altrimenti
 */
static inline bool str_test0(const char * pass)
{
	for (byte i = 0; i < PASS_LEN; i++)
		if (not (is_09(pass[i]) or is_af(pass[i])))
			return false;
	
	return true;
}


/* Restituisce true se la password è corretta, false altrimenti */
inline bool is_valid_pass_str(const char * pass)
{
	 
	if (str_test0(pass) is true)
	{
		/* Si passa il controllo alla versione per int, che ha i veri test */
		return is_valid_pass_int(strtoll(pass, NULL, 16));
	}
	else
	{		
		return false;
	}
}
