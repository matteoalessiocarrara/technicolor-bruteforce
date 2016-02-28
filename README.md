# Technicolor Bruteforce #

Il più veloce generatore di password per router technicolor


## Esempio ##

```
richard(beta|✚ 5…)% ./technicolor-bruteforce-generic | head --lines=10
001011223A
001011223B
001011223C
001011223D
001011223E
001011223F
001011224A
001011224B
001011224C
001011224D
```

## Compilazione ##

Dalla root del repo, dare `make --directory=src`.

Il Makefile può generare varie versioni del software:
 
 * generic: è l'eseguibile predefinito
 * native: genera un eseguibile ottimizzato per la propria cpu
 * debug_: crea un eseguibile per il debug
 * dev: la configurazione migliore sul mio sistema (e forse anche sul tuo, prova)


## Funzionamento ##

Questo software fa una cosa sola, ma la fa bene: stampa password valide per router
technicolor, dalla prima all'ultima. Non fa nient'altro, altre funzioni devono 
essere aggiunte esternamente.

Per esempio, per stampare solo X password si può passare l'output a head, in questo
modo:   
`./technicolor-bruteforce-generic | head --lines=X`


## Obbiettivo ##

L'obbiettivo è scrivere il più veloce generatore di password per router technicolor,
senza però rendere illeggibile il codice e seguendo la filosofia unix.


## Benchmark ##
 
In doc c'è un [file](doc/BENCHMARK.md) con i benchmark di questo ed altri software.  
In futuro pubblicherò gli script che uso per generare i benchmark, in modo che 
tutti possano verificare qual è il più veloce sul proprio sistema.

Se conoscete software più veloci inviatemi un'email, o segnalatelo su github.
Aggiungerò i benchmark nella versione successiva.


## Altre informazioni ##

> This is the Unix philosophy: Write programs that do one thing and do it well.
Write programs to work together. Write programs to handle text streams, because
that is a universal interface.

Aggiornamenti: [GitHub](https://github.com/matteoalessiocarrara/technicolor-bruteforce)  
Email: sw.matteoac@gmail.com
