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

/* Funzioni che lavorano su una password rappresentata come numero */

# include <stdbool.h>
# include <stdint.h>

# include "lib/readability/src/readability.h"

# include "filter_int.h"
# include "filter_str.h"
# include "debug.h"


/* Controlla se il numero num è 'A', 'B', 'C', 'D', 'E' o 'F' in esadecimale */
# define is_af(num) (((num) >= 0xA) and ((num) <= 0xF))

/* Controlla se il numero num è un numero compreso fra 0 e 9 */
# define is_09(num) (((num) >= 0) and ((num) <= 9))

/* Equivalente di pass[n] con pass di tipo char *, per pass di tipo uint64_t */
# define get_char(n, pass) ((pass >> ((PASS_LEN - (n + 1)) * 4)) & 0xF)

 
/* Funzione equivalente al define get_char, più lenta ma più comprensibile
 * ATTENZIONE: Non restituisce un carattere ASCII, ma un numero compreso fra 0 e 15
 * (che può essere rappresentato come un carattere in esadecimale)  
 */
static inline unsigned char get_char_func(const byte n, const uint64_t pass)
{
	/* Il tipo uint64_t è un tipo numerico: ogni "carattere" della password è un
	 * numero compreso fra 0x0 e 0xF, e corrisponde ad un gruppo di 4 bit partendo
	 * da destra.
	 * 
	 * 0xC1A0
	 * 0b1100000110100000
	 * 
	 * C    1    A    0
	 * 1100 0001 1010 0000
	 * 
	 * 
	 * Per ottenere il carattere n, come si intende per una stringa, andiamo a fare:
	 * * uno shift verso destra di (PASS_LEN - (n + 1)) * 4, in questo
	 *   modo i quattro bit in fondo a destra corrisponderanno al carattere scelto
	 * * poi si fa un and con una maschera per i quattro bit a destra, ovvero 0xF
	 * 
	 * 
	 * Esempio con password 0xC1A0, PASS_LEN 4, e n 2
	 * 
	 * shift = (4 - (2 + 1)) * 4 = 4 
	 * 0b110000011010 >> 4 = 0b0000110000011010
	 *      
	 *      C    1    A
	 * 0000 1100 0001 1010
	 * 
	 * Come si vede, il carattere in fondo a destra è il 3°, A. Ricordiamoci che
	 * n parte da 0, come negli array.
	 * 
	 * Adesso dobbiamo prendere solo A, quindi si fa un and con 0xF
	 * 
	 * 0b0000110000011010 & 0xF = 0b0000000000001010
	 * 
	 *                A
	 * 0000 0000 0000 1010
	 */
	 
	byte shift = (PASS_LEN - (n + 1)) * 4;
	byte mask = 0xF;
	
	return (pass >> shift) & mask;
}


/* Algoritmi di alcune funzioni presi da https://github.com/emanueleforestieri/technicolor_bruteforce
 * Grazie a Emanuele Forestieri <forestieriemanuele@gmail.com>
 */


/* There can be no more than two consecutive identical characters
 * Restituisce true se la password è corretta, false altrimenti
 */
static inline bool test0(const uint64_t pass)
{

	/* (PASS_LEN - 2): il codice sotto da sempre per scontato che dopo il
	 * carattere attuale (i) ce ne siano altri due (i + 1, i + 2), quindi scorriamo
	 * la passowrd dall'inizio alla fine - 2, in questo modo i + 2 sarà l'ultimo
	 * carattere della password (e non oltre la fine della password!!)
	 */

	for (byte i = 0; i < (PASS_LEN - 2); i++)
	{
		if (get_char(i, pass) == get_char(i + 1, pass))
		{
			if (get_char(i + 1, pass) == get_char(i + 2, pass))
				return false;
			else
				/* per evitare che l'if esterno ricontrolli inutilmente i due
				 * caratteri già controllati da questo if */
				i++;
		}
	}

	return true;
}


/* There can be no more than 5 characters A-F and 9 numbers
 * Restituisce true se la password è corretta, false altrimenti
 */
static inline bool test1(const uint64_t pass)
{
	byte af = 0, numbers = 0;

	for (byte i = 0; i < PASS_LEN; i++)
		is_af(get_char(i, pass))? af++ : numbers++;

	return ((af > 5) or (numbers > 9))? false : true;
}


/* There can be no more than three identical characters
 * Restituisce true se la password è corretta, false altrimenti
 */
static inline bool test2(const uint64_t pass)
{
	/* Ogni elemento di questo array rappresenta un carattere del charset
	 * L'indice si ottiene semplicemente traducendo il carattere da esadecimale
	 * a decimale
	 * Per es, l'indice per 'F' sarà 15, mentre per 'A' 10, e per '2' 2
	 */
	byte times[16];

	/* Azzeriamo ogni elemento dell'array times */
	for (byte i = 0; i < 16; i ++)
		times[i] = 0;

	/* Contiamo quante volte ogni carattere è nella password */
	for (byte i = 0; i < PASS_LEN; i++)
	{
		times[get_char(i, pass)] += 1;

		if (times[get_char(i, pass)] > 3)
			return false;
	}

	return true;
}


/* Prende in input una password rappresentata come int
 * Per es 0xABCDEF1234
 * Restituisce true se la password è corretta, false altrimenti 
 */ 
inline bool is_valid_pass_int(const uint64_t pass)
{

	/* Test ordinati per velocità (i nomi sono a caso, non indicano la velocità)
	 * Meglio fare prima i test più veloci per vedere se non è valida, così non
	 * si perde tempo inutilmente
	 */
			if (test0(pass) is true)
				if (test1(pass) is true)
					if (test2(pass) is true)
						return true;

	/* Qualche test sopra non ha restituito true */
	return false;
}
