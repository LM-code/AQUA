#include <stdio.h>
#include <gtk/gtk.h>
#include "map.h"

void Calcul (GtkWidget *p_Fenetre,gpointer p_data){
   // Variable pour récupérer les données du formulaire 
   donnee *recup = (donnee *) p_data;
   const gchar *p_text_1 = NULL;
   const gchar *p_text_2 = NULL;
   const gchar *p_text_3 = NULL;
   const gchar *p_text_4 = NULL;
   const gchar *p_text_10 = NULL;
   gchar text[80]="";
   gint Region_num = 0;
   gint Duree_num = 0;
   // Variable de calcul pour le débit 
   gint Chemin = 0, a = 0, x = 0;
   gfloat Surface =0, Debit = 0, Pente = 0;
   gfloat Puis_1 = 0, Puis_2 = 0, Puis_3 = 0;
	// région de pluie Int77
	// tableau région des pluies selon la formule de caquot
	const float Tab_caquot [8][12] = 
		{{1,1,1,1,2,2,2,2,3,3,3,3}
		,{10,5,2,1,10,5,2,1,10,5,2,1}
		,{5.9,5,3.7,3.1,6.7,5.5,4.6,3.5,6.1,5.9,5,3.8}
		,{-0.59,-0.61,-0.62,-0.64,-0.55,-0.57,-0.62,-0.62,-0.44,-0.51,-0.54,-0.53}
		,{1.43,1.192,0.834,0.682,1.601,1.209,1.087,0.78,1.296,1.327,1.121,0.804}
		,{0.29,0.3,0.31,0.32,0.27,0.28,0.31,0.31,0.21,0.24,0.2,0.26}
		,{1.2,1.21,1.22,1.28,1.19,1.2,1.22,1.22,1.14,1.17,1.18,1.18}
		,{0.78,0.78,0.77,0.77,0.8,0.79,0.77,0.77,0.83,0.81,0.8,0.8}};
	// Coefficient de ruissellement
		const float C_strickler [4] = {1,0.9,0.7,0.3} ;
   // Récupération des données du formulaire 
   p_text_1 = gtk_combo_box_get_active_text (

void carte_france (GtkWidget *p_Button, gpointer p_data)
{
 // Désactive le bouton de la carte
   gtk_widget_set_sensitive( p_Button, FALSE );
 // widget GTK
   GtkWidget *p_Fenetre_carte = NULL;
   GtkWidget *p_Image_carte = NULL;
   GtkWidget *p_Vboite_carte = NULL;
   GtkWidget *p_Bouton_carte = NULL;
 // création de la fenêtre
	p_Fenetre_carte = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(p_Fenetre_carte), 700, 700);
	gtk_window_set_title(
	   GTK_WINDOW(p_Fenetre_carte),
      " Carte de france des regions pluviomètriques ");
 // création des boites  
   p_Vboite_carte = gtk_vbox_new(FALSE,0);
   gtk_container_add(GTK_CONTAINER(p_Fenetre_carte), p_Vboite_carte);
 // chargement de l'image 
	p_Image_carte = gtk_image_new_from_file
	   ("image/carte_france.png");
	gtk_box_pack_start(GTK_BOX(p_Vboite_carte), p_Image_carte, FALSE, FALSE, 0);
 // création du bouton fermer
   p_Bouton_carte = gtk_button_new_with_label("FERMER");  
	gtk_box_pack_start(GTK_BOX(p_Vboite_carte), p_Bouton_carte,FALSE,FALSE, 5);
 // fonction de callback
	g_signal_connect(
	G_OBJECT(p_Fenetre_carte), "destroy",G_CALLBACK(gtk_widget_destroy), NULL
   );
	g_signal_connect(
	G_OBJECT(p_Bouton_carte),"clicked",G_CALLBACK(quitter),p_Fenetre_carte
   );
	gtk_widget_show_all(p_Fenetre_carte);
};
void quitter (GtkWidget* widget, gpointer p_data)
{
   GtkWidget *recup;
   recup = p_data;
   gtk_widget_destroy(recup); 
}
