# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <gtk/gtk.h>
# include "formule.h"

int main (int argc,char *argv[]){
      gtk_init(&argc, &argv);
      donnee form = {NULL,NULL,NULL};
   // widget GTK
      GtkWidget *p_Fenetre = NULL;
      GtkWidget *p_Cadre_form = NULL;
      GtkWidget *p_Cadre_result = NULL;
      GtkWidget *p_Table = NULL;
      GtkWidget *pVboite[3];
      GtkWidget *pHboite[9];
      GtkWidget *pEtiquette[9];
      GtkWidget *p_Alignement[6];
      GtkWidget *p_Button;
   // initialisation GTK
      p_Fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
      gtk_window_set_default_size(GTK_WINDOW(p_Fenetre), 350, 300);
		gtk_window_set_title(
      GTK_WINDOW(p_Fenetre), "Dimensionnement Eaux pluviales");
   // Création des boutons
      p_Button = gtk_button_new (); 
   // Création des entrées texte
      form.p_Nom_bassin = gtk_entry_new ();
      gtk_entry_set_text (GTK_ENTRY(form.p_Nom_bassin),"Bassin EP 01");
gtk_widget_set_can_focus (GTK_WIDGET(form.p_Nom_bassin),1);
   // Création du tableau
      p_Table = gtk_table_new ( 5,3,FALSE );
   // Création des cadres
      p_Cadre_form = gtk_frame_new("Paramètres");  
      p_Cadre_result = gtk_frame_new("Résultat");  
	// crée les boites
      pVboite[0] = gtk_vbox_new(FALSE,0);
      pVboite[1] = gtk_vbox_new(FALSE,0);
      pVboite[2] = gtk_vbox_new(FALSE,0);
      pHboite[0] = gtk_hbox_new(TRUE,0);
      pHboite[1] = gtk_hbox_new(TRUE,0);
      pHboite[2] = gtk_hbox_new(TRUE,0);
      pHboite[3] = gtk_hbox_new(FALSE,0);
      pHboite[4] = gtk_hbox_new(TRUE,0);
   // crée les étiquettes
		pEtiquette[0]=gtk_label_new("Nom du bassin : ");
		gtk_misc_set_alignment(GTK_MISC(pEtiquette[0]), 1.0, 0.5);
		pEtiquette[1]=gtk_label_new("Région : ");
		gtk_misc_set_alignment(GTK_MISC(pEtiquette[1]), 1.0, 0.5);
		pEtiquette[2]=gtk_label_new("Période de retour : ");
		gtk_misc_set_alignment(GTK_MISC(pEtiquette[2]), 1.0, 0.5);
		pEtiquette[3]=gtk_label_new("Type de surface : ");
		gtk_misc_set_alignment(GTK_MISC(pEtiquette[3]), 1.0, 0.5);
		pEtiquette[4]=gtk_label_new("Surface Bassin versant : ");
		gtk_misc_set_alignment(GTK_MISC(pEtiquette[4]), 1.0, 0.5);
		pEtiquette[5]=gtk_label_new(" Mètre(s)");
		gtk_misc_set_alignment(GTK_MISC(pEtiquette[5]), 0.0, 0.5);
		pEtiquette[6]=gtk_label_new(" Le plus long chemin : ");
		gtk_misc_set_alignment(GTK_MISC(pEtiquette[6]), 1.0, 0.5);
		form.p_Resultat=gtk_label_new("Region 1");
		gtk_misc_set_alignment(GTK_MISC(form.p_Resultat), 0.0, 0.0);
   // crée les listes
		form.p_Liste_reg = gtk_combo_box_new_text ();
      gtk_combo_box_append_text  (GTK_COMBO_BOX (form.p_Liste_reg), "Region 1");
      gtk_combo_box_append_text  (GTK_COMBO_BOX (form.p_Liste_reg), "Region 2");
      gtk_combo_box_append_text  (GTK_COMBO_BOX (form.p_Liste_reg), "Region 3");
      gtk_combo_box_set_active (GTK_COMBO_BOX (form.p_Liste_reg), 0);
		form.p_Liste_duree = gtk_combo_box_new_text ();
      gtk_combo_box_append_text  (GTK_COMBO_BOX (form.p_Liste_duree), "10 ans");
      gtk_combo_box_append_text  (GTK_COMBO_BOX (form.p_Liste_duree), "5 ans");
      gtk_combo_box_append_text  (GTK_COMBO_BOX (form.p_Liste_duree), "2 ans");
      gtk_combo_box_append_text  (GTK_COMBO_BOX (form.p_Liste_duree), "1 ans");
      gtk_combo_box_set_active (GTK_COMBO_BOX (form.p_Liste_duree), 0);
		form.p_Liste_type = gtk_combo_box_new_text ();
      gtk_combo_box_append_text  (GTK_COMBO_BOX (form.p_Liste_type),"Espace vert");
      gtk_combo_box_append_text  (GTK_COMBO_BOX(form.p_Liste_type),"Voirie");
      gtk_combo_box_append_text  (GTK_COMBO_BOX (form.p_Liste_type),"Bâtiment");
      gtk_combo_box_set_active (GTK_COMBO_BOX (form.p_Liste_type), 1);
   // Bouton de saisie numérique
		form.p_Num_surface = gtk_spin_button_new_with_range(10,2000000, 10); 
		form.p_Num_chemin = gtk_spin_button_new_with_range(10, 100, 1); 
   // alignement
      p_Alignement[0] = gtk_alignment_new (0,0,0,0); 
      p_Alignement[1] = gtk_alignment_new (0,0,0,0); 
      p_Alignement[2] = gtk_alignment_new (0,0,0,0); 
      p_Alignement[3] = gtk_alignment_new (0,0,0,0); 
      p_Alignement[4] = gtk_alignment_new (0,0,0,0); 
      p_Alignement[5] = gtk_alignment_new (0,0,0,0); 
   // Assemblage des boites
      gtk_container_add(GTK_CONTAINER(p_Fenetre), pVboite[0]);
		gtk_box_pack_start(GTK_BOX(pVboite[0]), p_Cadre_form, FALSE, FALSE, 0);
      gtk_container_add(GTK_CONTAINER(p_Cadre_form), p_Table );
      // 1 ère ligne du tableau
      gtk_table_attach(GTK_TABLE(p_Table), pEtiquette[0],
        0, 1, 0, 1,
        GTK_FILL, GTK_EXPAND,
        0, 0);
      gtk_table_attach(GTK_TABLE(p_Table), p_Alignement[0],
        1, 3, 0, 1,
        GTK_FILL, GTK_EXPAND,
        0, 0);
      gtk_container_add(GTK_CONTAINER(p_Alignement[0]),form.p_Nom_bassin );
      // 2 ème ligne du tableau
      gtk_table_attach(GTK_TABLE(p_Table), pEtiquette[1],
        0, 1, 1, 2,
        GTK_FILL, GTK_EXPAND,
        0, 0);
      gtk_table_attach(GTK_TABLE(p_Table), p_Alignement[1],
        1, 2, 1, 2,
        GTK_FILL, GTK_EXPAND,
        0, 0);
      gtk_container_add(GTK_CONTAINER(p_Alignement[1]), form.p_Liste_reg );
      gtk_widget_set_size_request(form.p_Liste_reg, 120, 28);
      gtk_table_attach(GTK_TABLE(p_Table), p_Button,
        2, 3, 1, 2,
        GTK_EXPAND, GTK_EXPAND,
        0, 0);
      gtk_widget_set_size_request(p_Button, 28, 28);
      // 3 ème ligne du tableau
      gtk_table_attach(GTK_TABLE(p_Table), pEtiquette[2],
        0, 1, 2, 3,
        GTK_FILL, GTK_EXPAND,
        0, 0);
      gtk_table_attach(GTK_TABLE(p_Table), p_Alignement[2],
        1, 2, 2, 3,
        GTK_FILL, GTK_EXPAND,
        0, 0);
      gtk_container_add(GTK_CONTAINER(p_Alignement[2]), form.p_Liste_duree );
      gtk_widget_set_size_request(form.p_Liste_duree, 120, 28);
      // 4 ème ligne du tableau
      gtk_table_attach(GTK_TABLE(p_Table), pEtiquette[3],
        0, 1, 3, 4,
        GTK_FILL, GTK_EXPAND,
        0, 0);
      gtk_table_attach(GTK_TABLE(p_Table), p_Alignement[3],
        1, 2, 3, 4,
        GTK_FILL, GTK_EXPAND,
        0, 0);
      gtk_container_add(GTK_CONTAINER(p_Alignement[3]), form.p_Liste_type );
      gtk_widget_set_size_request(form.p_Liste_type, 120, 28);
      // 5 ème ligne du tableau
      gtk_table_attach(GTK_TABLE(p_Table), pEtiquette[4],
        0, 1, 4, 5,
        GTK_FILL, GTK_EXPAND,
        0, 0);
      gtk_table_attach(GTK_TABLE(p_Table), p_Alignement[4],
        1, 2, 4, 5,
        GTK_EXPAND, GTK_EXPAND,
        0, 0);
      gtk_container_add(GTK_CONTAINER(p_Alignement[4]),form.p_Num_surface );
      gtk_widget_set_size_request(form.p_Num_surface, 120, 28);
      gtk_table_attach(GTK_TABLE(p_Table), pEtiquette[5],
        2, 3, 4, 5,
        GTK_EXPAND, GTK_EXPAND,
        0, 0);
      // 6 ème ligne du tableau
      gtk_table_attach(GTK_TABLE(p_Table), pEtiquette[6],
        0, 1, 5, 6,
        GTK_FILL, GTK_EXPAND,
        0, 0);
      gtk_table_attach(GTK_TABLE(p_Table), p_Alignement[5],
        1, 2, 5, 6,
        GTK_EXPAND, GTK_EXPAND,
        0, 0);
      gtk_container_add(GTK_CONTAINER(p_Alignement[5]),form.p_Num_chemin );
      gtk_widget_set_size_request(form.p_Num_chemin, 120, 28);
		gtk_box_pack_start(GTK_BOX(pVboite[0]), p_Cadre_result, TRUE, TRUE, 0);
      gtk_container_add(GTK_CONTAINER(p_Cadre_result), pVboite[2]);
		gtk_box_pack_start(GTK_BOX(pVboite[2]), form.p_Resultat, TRUE,TRUE, 0);
   // Définition des callbacks
     g_signal_connect (
      G_OBJECT (form.p_Liste_reg), "changed",G_CALLBACK(Calcul),&form
      );
     g_signal_connect (
      G_OBJECT (form.p_Liste_duree), "changed",G_CALLBACK(Calcul),&form
      );
     g_signal_connect (
      G_OBJECT (form.p_Liste_type), "changed",G_CALLBACK(Calcul),&form
      );
     g_signal_connect (
      G_OBJECT (form.p_Num_surface), "changed",G_CALLBACK(Calcul),&form
      );
		g_signal_connect(
      G_OBJECT(p_Fenetre), "destroy",G_CALLBACK(gtk_main_quit), NULL
      );
   // affiche la boucle évènementielle
      gtk_widget_show_all(p_Fenetre);
      gtk_main();
}
