#include <stdio.h>
#include <gtk/gtk.h>
#include "map.h"

# define path_image "/usr/local/share/aqua/image/"

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
	   (path_image"carte_france.png");
	gtk_box_pack_start(GTK_BOX(p_Vboite_carte), p_Image_carte, FALSE, FALSE, 0);
 // création du bouton fermer
   p_Bouton_carte = gtk_button_new_with_label("FERMER");  
	gtk_box_pack_start(GTK_BOX(p_Vboite_carte), p_Bouton_carte,FALSE,FALSE, 5);
 // fonction de callback
	g_signal_connect(
	   G_OBJECT(p_Fenetre_carte),"destroy",
      G_CALLBACK(active_bouton_carte), p_Button
   );
	g_signal_connect(
	   G_OBJECT(p_Bouton_carte),"clicked",
      G_CALLBACK(active_bouton_carte),p_Button
   );
	g_signal_connect_swapped(
	   G_OBJECT(p_Bouton_carte),"clicked",
      G_CALLBACK(quitter),p_Fenetre_carte
   );
	gtk_widget_show_all(p_Fenetre_carte);
};
void active_bouton_carte (GtkWidget *p_Fenetre_carte, GtkWidget *p_Button )
{
  gtk_widget_set_sensitive (p_Button, TRUE);
}
void quitter (GtkWidget *p_Fenetre_carte, GtkWidget *p_Button )
{
  gtk_widget_destroy (p_Fenetre_carte);
}
