CC=gcc
GTK=`pkg-config --libs --cflags gtk+-2.0`

CBV.x :  
	@echo "Compilation du programme";
	@echo "Création des fichiers objet";
	$(CC) $(GTK) -c formule.c main.c -lm;
	@echo "linkage des fichiers objet pour création de l'éxecutable";
	$(CC) $(GTK) -o CBV.x formule.o main.o ;

clean:
	@echo "Efface les fichiers de compilation et d'éxécution";
	rm -f *.o *core* CBV.x
    
