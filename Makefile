# Makefile de compilation avec GTK3 - 21/02/2016

SHELL   = /bin/bash
CC      = gcc
MKDEP   = gcc -MM
RM      = rm -f

# Si vous voulez utiliser gdb, rajouter "-g" a la fin de CFLAGS ;
# Si vous utilisez des fonctions de <math.h>, rajoutez "-lm" a la fin de LIBS.
CFLAGS  = $$(pkg-config gtk+-3.0 --cflags) -Wall -std=c99 -pedantic -O2
LIBS    = $$(pkg-config gtk+-3.0 --libs) -lm

# Mettre ici la liste des fichiers .c separes par un espace ;
# si besoin on peut eclater la liste sur plusieurs lignes avec "\".
CFILES  = main.c edge.c node.c graphe.c kruskal.c prim.c

# Mettre ici le nom de l'executable.
EXEC    = main-app

# Calcul automatique de la liste des fichiers ".o" a partir de CFILES.
OBJECTS := $(CFILES:%.c=%.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $*.c -g

all :: $(EXEC)

$(EXEC) : $(OBJECTS)
	$(CC) -o $@ $^ $(LIBS)

clean ::
	$(RM) *.o *~ $(EXEC) depend

depend : *.c *.h
	$(MKDEP) *.c >| depend

# Inclut le fichier des dependances. 
# Le "-" devant include supprime l'erreur si le fichier est absent.
-include depend

tar :: clean
	@N=$$(pwd) ; N=$$(basename "$$N") ;\
	(cd .. && tar cvfz "$$N.tgz" "$$N" --exclude='svg*' --exclude='*.tgz' --exclude='*.zip' && \
	 echo "DONE ../$$N.tgz")
	 
zip :: clean
	@N=$$(pwd) ; N=$$(basename "$$N") ;\
	(cd .. && zip -r "$$N.zip" "$$N" --exclude='svg*' --exclude='*.tgz' --exclude='*.zip' && \
	echo "DONE ../$$N.zip")
