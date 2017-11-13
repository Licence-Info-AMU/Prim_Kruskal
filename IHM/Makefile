# Makefile for EZ-Draw, on Unix and Windows
# Par Gaëtan Perrot et Lucas Moragues

# Default system type. Override this on command line: make SYSTYPE=WIN32 ...
SYSTYPE = UNIX

#-------------------------- C O N F I G U R A T I O N -------------------------

ifeq ($(SYSTYPE),UNIX)

    # Unix/X11 systems (linux, Mac OS X, Cygwin, etc)               # SECTION A
    SHELL  = /bin/bash
    CC     = gcc
    CFLAGS = -Wall -W -std=c99 -pedantic -O2 -g 
    MKDEP   = gcc -MM
    LIBS   = -lX11 -lXext -lm
    LIBS_I =

else ifeq ($(SYSTYPE),WIN32)

    # Windows, all versions                                         # SECTION B
    CC     = gcc
    CFLAGS = -Wall -W -std=c99 -pedantic -O2
    LIBS   = -lgdi32
    LIBS_I = -lmsimg32

endif

CFILES  = node.c edge.c graphe.c BinariHeap.c kruskal.c prim.c ez-draw.c main.c

# Mettre ici le nom de l'executable.
EXEC    = main

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

help ::
	@ echo "       make all       pour tout compiler"
	@ echo "       make clean     pour tout nettoyer"
	@ echo "       make distclean     pour tout nettoyer"
	@ echo "       make zip       pour tout sauvegarder"
	@ echo "       make tar       pour tout sauvegarder"

clean ::
	\rm -f *.o core depend

distclean :: clean
	\rm -f *% $(EXEC) depend
	
zip :: distclean
	@N=$$(pwd) ; N=$$(basename "$$N") ;\
	(cd .. && zip -r "$$N.zip" "$$N" --exclude='svg*' --exclude='*.tgz' --exclude='*.zip' && \
	echo "DONE ../$$N.zip")

tar :: clean
	@N=$$(pwd) ; N=$$(basename "$$N") ;\
	(cd .. && tar cvfz "$$N.tgz" "$$N" --exclude='svg*' --exclude='*.tgz' && \
	 echo "DONE ../$$N.tgz")
