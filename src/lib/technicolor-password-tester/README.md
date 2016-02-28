# Technicolor Password Tester #

Controlla se una password è valida per i router technicolor. Libreria in c.

## Sinossi ##

```c
# include "src/filter_str.c"
# include "src/filter_int.c"

inline bool is_valid_pass_str(const char * pass);
inline bool is_valid_pass_int(const uint64_t pass);
```

## Descrizione ##

Le funzioni is_valid_pass_qualcosa() controllano se pass è una password valida
per i router technicolor.

La funzione is_valid_pass_int() prende in input una password rappresentata come
numero, per es 0xABCDEF1234; mentre l'altra funzione prende in input stringhe,
come "ABCDEF1234".

La stringa pass *dovrebbe* essere lunga 10 caratteri, con charset 0-9 A-F. 
Questo è il formato delle password valide. Se così non fosse, semplicemente sarà
sicuramente non valida.


## Return ##

Le funzion restituiscono true o false (stdbool.h)


## Esempio ##

Ho scritto un interfaccia basata su questa libreria, è disponibile 
[qui](https://github.com/matteoalessiocarrara/technicolor-password-tester)


## Altre informazioni ##

> This is the Unix philosophy: Write programs that do one thing and do it well.
Write programs to work together. Write programs to handle text streams, because
that is a universal interface.

Aggiornamenti: [GitHub](http://github.com/matteoalessiocarrara/lib-technicolor-password-tester)  
Email: sw.matteoac@gmail.com  
