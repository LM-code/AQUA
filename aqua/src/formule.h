#ifndef FORMULE_H
#define FORMULE_H
typedef struct {
	GtkWidget *p_Nom_bassin;
	GtkWidget *p_Liste_reg;
	GtkWidget *p_Liste_duree;
	GtkWidget *p_Liste_type;
	GtkWidget *p_Num_surface;
	GtkWidget *p_Num_chemin;
	GtkWidget *p_Num_pente;
	GtkWidget *p_Resultat;
   GtkWidget *p_Unite;
	GtkWidget *p_Resultat_2;
   GtkWidget *p_Unite_2;
} donnee;

extern void Calcul (GtkWidget *p_Fenetre,gpointer p_data);

#endif
