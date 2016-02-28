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
  
/* Funzioni che lavorano su una password rappresentata come stringa
 * 
 * DEPRECATED Questo file verrà rimosso nella prossima versione.
 * Usare filter_str.c o filter_int.c al suo posto
 */

# include <stdbool.h>
# include "filter_str.c"


/* DEPRECATED Funzione mantenuta per compatibilità con la versione 1.x.x, verrà 
 * rimossa nella prossima versione. Usare is_valid_pass_str() di filter_str.c
 * al suo posto
 */ 
inline bool is_valid_pass(const char * pass)
{
	return is_valid_pass_str(pass);
}
