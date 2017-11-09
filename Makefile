# Makefile pour UE SIN5U3 "Reseau et Communication"
#
# 23/10/2013 - Edouard.Thiel@lif.univ-mrs.fr
#Modifié par Gaëtan Perrot et Lucas Moragues

SHELL  = /bin/bash
CC     = gcc
CFLAGS = -Wall -W -std=c99 -pedantic
LIBS   =

# Rajouter le nom des executables apres '=', separes par un espace.

# Mettre ici la liste des fichiers .c separes par un espace ;
# si besoin on peut eclater la liste sur plusieurs lignes avec "\".
CFILES  = main.c edge.c node.c graphe.c kruskal.c prim.c
EXECS = rebourfils

# pour compiler avec bor-util.c
EXECSUTIL =  

# pour compiler avec bor-util.c et bor-timer.c
EXECSTIMER = triosig


%.c%.o :
	$(CC) -c $(CFLAGS) $*.c

help ::
	@echo "Options du make : help all clean distclean"

all :: $(EXECS) $(EXECSUTIL) $(EXECSTIMER)

$(EXECS) : %: %.o
	$(CC) -o $@ $@.o $(LIBS)

$(EXECSUTIL) : %: %.o bor-util.o
	$(CC) -o $@ $@.o bor-util.o $(LIBS)

$(EXECSTIMER) : %: %.o bor-util.o bor-timer.o
	$(CC) -o $@ $@.o bor-util.o bor-timer.o $(LIBS)

clean ::
	\rm -f *.o core

distclean :: clean
	\rm -f *% $(EXECS) $(EXECSUTIL) $(EXECSTIMER)
	
zip :: distclean
	@N=$$(pwd) ; N=$$(basename "$$N") ;\
	(cd .. && zip -r "$$N.zip" "$$N" --exclude='svg*' --exclude='*.tgz' --exclude='*.zip' && \
	echo "DONE ../$$N.zip")
