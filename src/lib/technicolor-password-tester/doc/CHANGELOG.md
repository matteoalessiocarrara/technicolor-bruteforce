# Change Log #

All notable changes to this project will be documented in this file.
This project adheres to [Semantic Versioning](http://semver.org/).


## 2016/02/28 1.4.0 ##

Added
 - Migliorato codice e documentazione
 - Aggiunto filtro funzionante con password numeriche (ora il filtro per le stringhe
   si basa su questo)

Fixed
 - Risolto bug: considerava come valide le password che erano valide nei primi 10
   caratteri, MA erano più lunghe di 10 caratteri (e le password non possono essere
   più lunghe di 10 caratteri)
   
   
## 2016/02/07 1.3.1 ##

Fixed
 - Rinominato un define per evitare conflitti con i software che usano la libreria


## 2016/02/07 1.3.0 ##

Added
 - Aggiunta libreria readability
 - Migliorato il codice, ora è più bello


## 2016/01/11 1.2.1 ##

Changed
 - Cambiate alcune variabili da short a unsigned char

Fixed
 - Vengono controllati i caratteri della stringa, prima di passarla alle funzioni
   per verificare se è una password valida


## 2016/01/11 1.1.0 ##

Changed
 - Migliorato algoritmo in filter.c 


## 2016/01/10 1.0.0 ##

 - Prima versione
