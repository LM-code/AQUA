CC=gcc
CC_win=i586-mingw32msvc-gcc
GTK=`pkg-config --libs --cflags gtk+-2.0`
NOM_PROG_LINUX=Water.x
NOM_PROG_WIN=Water.exe

Water.x :  
	@echo "/**********************************/";
	@echo "/     Compilation du programme     /";
	@echo "/    Création des fichiers objet   /";
	@echo "/**********************************/\n";
	$(CC) $(GTK) -c map.c formule.c main.c -lm;
	@echo "/**********************************/";
	@echo "/    Linkage des fichiers objet    /";
	@echo "/   pour création de l'éxecutable  /";
	@echo "/**********************************/\n";
	$(CC) $(GTK) -o $(NOM_PROG_LINUX) map.o formule.o main.o;

clean :
	@echo "Efface les fichiers de compilation et d'éxécution";
	rm -f *.o *core* $(NOM_PROG_LINUX) $(NOM_PROG_WIN);
    
win :
	@echo "/**********************************/";
	@echo "/     Compilation du programme     /";
	@echo "/           pour windows           /";
	@echo "/**********************************/\n";
	export PKG_CONFIG_PATH=/home/laurent/gtk_win32/lib/pkgconfig;$(CC_win) *.c -o $(NOM_PROG_WIN) $(GTK) -lm
