OPTIMIZE = -O3 -funroll-loops
CFLAGS = -pipe -w
DEBUG_CFLAGS = -pipe -Og -g -Wall -Wextra -DDEBUG

BIN_DIR = ./../bin/
NAME = technicolor-bruteforce
CC = c99


generic: 
	$(CC) main.c -o $(BIN_DIR)$(NAME)-generic $(OPTIMIZE) $(CFLAGS) 

native:
	$(CC) main.c -o $(BIN_DIR)$(NAME)-native $(OPTIMIZE) $(CFLAGS) -march=native

# HACK FIXME Se si chiama debug, "make debug" non funziona... dice sempre
# make: 'debug' is up to date.
debug_:
	$(CC) main.c -o $(BIN_DIR)$(NAME)-debug $(DEBUG_CFLAGS)

# La configurazione migliore sul mio sistema	
dev:
	$(CC) main.c -o $(BIN_DIR)$(NAME)-dev $(CFLAGS) -O3 -funroll-loops

clean:
	rm -f $(BIN_DIR)*


# Questo lo uso per creare gli eseguibili quando pubblico una nuova versione
# Probabilmente crea eseguibili per linux solo quando si compila da linux


new: linux-64 linux-32

linux-64:
	$(CC) main.c -o $(BIN_DIR)$(NAME)-linux-64 $(OPTIMIZE) $(CFLAGS)

linux-32:
	$(CC) main.c -o $(BIN_DIR)$(NAME)-linux-32 $(OPTIMIZE) $(CFLAGS) -m32
