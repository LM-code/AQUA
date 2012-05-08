# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <gtk/gtk.h>
# include "formule.h"
# include "map.h"
# include "fonction.h"

int main (int argc,char *argv[]){
      gtk_init(&argc, &argv);
      donnee form = {};
   // widget GTK
      GtkWidget *p_Fenetre = NULL;
      GtkWidget *p_Table = NULL;
      GtkWidget *p_Table_1 = NULL;
      GtkWidget *p_Vboite[1] = {};
      GtkWidget *p_Hboite[2] = {};
      GtkWidget *p_Titre_1 = NULL;
      GtkWidget *p_Titre_2 = NULL;
      GtkWidget *p_Etiquette[10] = {};
      GtkWidget *p_Alignement[9] = {};
      GtkWidget *p_Groupe = NULL;
      GtkWidget *p_Button = NULL;
      GtkWidget *p_Button_image = NULL;
      GtkWidget *p_Ligne_separation = NULL;
      gchar *p_text_titre = NULL;
   // initialisation GTK
      p_Fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
      gtk_window_set_icon_from_file(GTK_WINDOW(p_Fenetre),
         "/usr/local/share/aqua/image/carte_france.png",NULL);
		gtk_window_set_title(
      GTK_WINDOW(p_Fenetre), " Dimensionnement Eaux pluviales ");
      gtk_window_set_resizable(GTK_WINDOW(p_Fenetre),0);
      //gtk_window_set_default_size(GTK_WINDOW(p_Fenetre), 350, 300);
   // Création de la ligne de séparation
      p_Ligne_separation = gtk_hseparator_new ();
   // Création des boutons
      p_Button = gtk_button_new (); 
      p_Button_image = gtk_image_new_from_file
          ("/usr/local/share/aqua/image/carte_france_mini.png");
      gtk_button_set_image(GTK_BUTTON(p_Button), p_Button_image);
      form.p_Unite = gtk_button_new_with_label ("L/S"); 
      form.p_Unite_2 = gtk_button_new_with_label ("L/S"); 
   // Création des entrées texte
      form.p_Nom_bassin = gtk_entry_new ();
      gtk_entry_set_text (GTK_ENTRY(form.p_Nom_bassin),"Bassin EP 01");
		gtk_entry_set_position (GTK_ENTRY(form.p_Nom_bassin),5);
      form.p_Resultat = gtk_entry_new ();
      gtk_entry_set_text (GTK_ENTRY(form.p_Resultat),"0");
      gtk_entry_set_editable (GTK_ENTRY(form.p_Resultat),FALSE);
		gtk_entry_set_alignment (GTK_ENTRY(form.p_Resultat),1);
      form.p_Resultat_2 = gtk_entry_new ();
      gtk_entry_set_text (GTK_ENTRY(form.p_Resultat_2),"0");
      gtk_entry_set_editable (GTK_ENTRY(form.p_Resultat_2),FALSE);
		gtk_entry_set_alignment (GTK_ENTRY(form.p_Resultat_2),1);
   // Création du tableau
      p_Table = gtk_table_new ( 11,3,FALSE );
		p_Table_1 = gtk_table_new ( 2,3,FALSE );
	// Création des boites
      p_Vboite[0] = gtk_vbox_new(FALSE,5);
      p_Hboite[0] = gtk_hbox_new(FALSE,5);
      p_Hboite[1] = gtk_hbox_new(FALSE,5);
	// Création du groupe caché
		p_Groupe = gtk_expander_new_with_mnemonic 
          ("cliquez ici pour + de paramètres");
   // Création des étiquettes
      p_text_titre = g_locale_to_utf8
         ("<u><b>PARAMETRES :</b></u>", -1, NULL, NULL, NULL);
		p_Titre_1 = gtk_label_new(p_text_titre);
		gtk_label_set_use_markup(GTK_LABEL(p_Titre_1), TRUE);
		gtk_misc_set_alignment(GTK_MISC(p_Titre_1), 0.0, 1.0);
      g_free(p_text_titre);
		p_Etiquette[0]=gtk_label_new("Nom bassin versant : ");
		gtk_misc_set_alignment(GTK_MISC(p_Etiquette[0]), 1.0, 0.5);
		p_Etiquette[1]=gtk_label_new("Région : ");
		gtk_misc_set_alignment(GTK_MISC(p_Etiquette[1]), 1.0, 0.5);
		p_Etiquette[2]=gtk_label_new("Période de retour : ");
		gtk_misc_set_alignment(GTK_MISC(p_Etiquette[2]), 1.0, 0.5);
		p_Etiquette[3]=gtk_label_new("Type de surface : ");
		gtk_misc_set_alignment(GTK_MISC(p_Etiquette[3]), 1.0, 0.5);
		p_Etiquette[4]=gtk_label_new("Surface Bassin versant : ");
		gtk_misc_set_alignment(GTK_MISC(p_Etiquette[4]), 1.0, 0.5);
		p_Etiquette[5]=gtk_label_new(" M2 ");
		gtk_misc_set_alignment(GTK_MISC(p_Etiquette[5]), 0.5, 0.0);
		p_Etiquette[6]=gtk_label_new("Le plus long chemin : ");
		gtk_misc_set_alignment(GTK_MISC(p_Etiquette[6]), 1.0, 0.5);
		p_Etiquette[7]=gtk_label_new("La pente du bassin : ");
		gtk_misc_set_alignment(GTK_MISC(p_Etiquette[7]), 1.0, 0.5);
      p_text_titre = g_locale_to_utf8
         ("<u><b>RESULTAT :</b></u>", -1, NULL, NULL, NULL);
		p_Titre_2 = gtk_label_new(p_text_titre);
		gtk_label_set_use_markup(GTK_LABEL(p_Titre_2), TRUE);
		p_Etiquette[8]=gtk_label_new("Débit d'orage brute : ");
      g_free(p_text_titre);
		gtk_misc_set_alignment(GTK_MISC(p_Etiquette[8]), 1.0, 0.5);
		p_Etiquette[9]=gtk_label_new("Débit d'orage corrigé : ");
		gtk_misc_set_alignment(GTK_MISC(p_Etiquette[9]), 1.0, 0.5);
   // Création des listes déroulantes
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
   // Création des des boutons de saisie numérique
		form.p_Num_surface = gtk_spin_button_new_with_range(10,2000000, 10); 
		form.p_Num_chemin = gtk_spin_button_new_with_range(10, 500, 1); 
		gtk_spin_button_set_value( GTK_SPIN_BUTTON (form.p_Num_chemin), 50);
		form.p_Num_pente = gtk_spin_button_new_with_range(0.1, 5, .1); 
		gtk_spin_button_set_value( GTK_SPIN_BUTTON (form.p_Num_pente),1);
   // alignement
      p_Alignement[0] = gtk_alignment_new (0,0,0,0); 
      p_Alignement[1] = gtk_alignment_new (0,0,0,0); 
      p_Alignement[2] = gtk_alignment_new (0,0,0,0); 
      p_Alignement[3] = gtk_alignment_new (0,0,0,0); 
      p_Alignement[4] = gtk_alignment_new (0,0,0,0); 
      p_Alignement[5] = gtk_alignment_new (0,0,0,0); 
      p_Alignement[6] = gtk_alignment_new (0,0,0,0); 
      p_Alignement[7] = gtk_alignment_new (0,0,0,0); 
      p_Alignement[8] = gtk_alignment_new (0,0.5,0,0); 
   // Assemblage des boites
      gtk_container_add(GTK_CONTAINER(p_Fenetre), p_Vboite[0]);
		gtk_box_pack_start(GTK_BOX(p_Vboite[0]), p_Table, FALSE,FALSE,5);
      // 1 ère ligne du tableau : TITRE
      gtk_table_attach(GTK_TABLE(p_Table), p_Titre_1,
        0, 1, 0, 1,
        GTK_FILL, GTK_EXPAND,
        0, 2);
      // 2 ère ligne du tableau
      gtk_table_attach(GTK_TABLE(p_Table), p_Etiquette[0],
        0, 1, 1, 2,
        GTK_FILL, GTK_EXPAND,
        0, 2);
      gtk_table_attach(GTK_TABLE(p_Table), form.p_Nom_bassin,
        1, 2, 1, 2,
		  GTK_EXPAND, GTK_EXPAND,
        0, 2);
      gtk_widget_set_size_request(form.p_Nom_bassin, 120, 28);
      // 3 ème ligne du tableau
      gtk_table_attach(GTK_TABLE(p_Table), p_Etiquette[1],
        0, 1, 2, 3,
        GTK_FILL, GTK_EXPAND,
        0, 2);
      gtk_table_attach(GTK_TABLE(p_Table), p_Alignement[0],
        1, 2, 2, 3,
        GTK_FILL, GTK_EXPAND,
        0, 2);
      gtk_container_add(GTK_CONTAINER(p_Alignement[0]), form.p_Liste_reg );
      gtk_widget_set_size_request(form.p_Liste_reg, 120, 28);
      gtk_table_attach(GTK_TABLE(p_Table), p_Button,
        2, 3, 2, 3,
        GTK_EXPAND, GTK_EXPAND,
        0, 2);
      gtk_widget_set_size_request(p_Button, 40, 28);
      // 4 ème ligne du tableau
      gtk_table_attach(GTK_TABLE(p_Table), p_Etiquette[2],
        0, 1, 3, 4,
        GTK_FILL, GTK_EXPAND,
        0, 2);
      gtk_table_attach(GTK_TABLE(p_Table), p_Alignement[1],
        1, 2, 3, 4,
        GTK_FILL, GTK_EXPAND,
        0, 2);
      gtk_container_add(GTK_CONTAINER(p_Alignement[1]), form.p_Liste_duree );
      gtk_widget_set_size_request(form.p_Liste_duree, 120, 28);
      // 5 ème ligne du tableau
      gtk_table_attach(GTK_TABLE(p_Table), p_Etiquette[3],
        0, 1, 4, 5,
        GTK_FILL, GTK_EXPAND,
        0, 2);
      gtk_table_attach(GTK_TABLE(p_Table), p_Alignement[2],
        1, 2, 4, 5,
        GTK_FILL, GTK_EXPAND,
        0, 2);
      gtk_container_add(GTK_CONTAINER(p_Alignement[2]), form.p_Liste_type );
      gtk_widget_set_size_request(form.p_Liste_type, 120, 28);
      // 6 ème ligne du tableau
      gtk_table_attach(GTK_TABLE(p_Table), p_Etiquette[4],
        0, 1, 5, 6,
        GTK_FILL, GTK_EXPAND,
        0, 2);
      gtk_table_attach(GTK_TABLE(p_Table), p_Alignement[3],
        1, 2, 5, 6,
        GTK_FILL, GTK_EXPAND,
        0, 2);
      gtk_container_add(GTK_CONTAINER(p_Alignement[3]),form.p_Num_surface );
      gtk_widget_set_size_request(form.p_Num_surface, 120, 28);
      gtk_table_attach(GTK_TABLE(p_Table), p_Etiquette[5],
        2, 3, 5, 6,
        GTK_EXPAND, GTK_EXPAND,
        0, 2);
      // 7 ème ligne du tableau
      gtk_table_attach(GTK_TABLE(p_Table), p_Groupe,
        0, 2, 6, 8,
        GTK_FILL, GTK_EXPAND,
        0, 2);
      gtk_container_add(GTK_CONTAINER(p_Groupe),p_Table_1 );
      // Tableau Paramètres supplémentaires
      // 1 ère ligne du tableau OPTION
      gtk_table_attach(GTK_TABLE(p_Table_1), p_Etiquette[6],
        0, 1, 0, 1,
        GTK_FILL, GTK_EXPAND,
        0, 2);
      gtk_table_attach(GTK_TABLE(p_Table_1), p_Alignement[4],
        1, 2, 0, 1,
        GTK_EXPAND, GTK_EXPAND,
        0, 2);
      gtk_container_add(GTK_CONTAINER(p_Alignement[4]),form.p_Num_chemin );
      gtk_widget_set_size_request(form.p_Num_chemin, 120, 28);
      // 2 ème ligne du tableau OPTION
      gtk_table_attach(GTK_TABLE(p_Table_1), p_Etiquette[7],
        0, 1, 1, 2,
        GTK_FILL, GTK_EXPAND,
        0, 2);
      gtk_table_attach(GTK_TABLE(p_Table_1), p_Alignement[5],
        1, 2, 1, 2,
        GTK_EXPAND, GTK_EXPAND,
        0, 2);
      gtk_container_add(GTK_CONTAINER(p_Alignement[5]),form.p_Num_pente );
      gtk_widget_set_size_request(form.p_Num_pente, 120, 28);
      // 8 ème ligne du tableau BARRE DE SEPARATION
      gtk_table_attach(GTK_TABLE(p_Table), p_Ligne_separation,
        0, 3, 8, 9,
        GTK_FILL, GTK_EXPAND,
        0, 2);
      // 9 ème ligne du tableau : TITRE RESULTAT
      gtk_table_attach(GTK_TABLE(p_Table), p_Alignement[6],
        0, 2, 9, 10,
        GTK_FILL, GTK_EXPAND,
        0, 2);
      gtk_container_add(GTK_CONTAINER(p_Alignement[6]), p_Titre_2 );
      // Boite Horizontale pour le débit de l'orage brute
		gtk_box_pack_start(GTK_BOX(p_Vboite[0]), p_Hboite[0], FALSE, FALSE, 5);
		gtk_box_pack_start(GTK_BOX(p_Hboite[0]), p_Etiquette[8], FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(p_Hboite[0]), form.p_Resultat, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(p_Hboite[0]), form.p_Unite, FALSE, FALSE, 0);
      gtk_widget_set_size_request(form.p_Resultat, 50, 28);
      gtk_widget_set_size_request(form.p_Unite, 50, 28);
      // Boite Horizontale pour le débit de l'orage corrigé
		gtk_box_pack_start(GTK_BOX(p_Vboite[0]), p_Hboite[1], FALSE, FALSE, 5);
		gtk_box_pack_start(GTK_BOX(p_Hboite[1]), p_Etiquette[9], FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(p_Hboite[1]), 
         form.p_Resultat_2, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(p_Hboite[1]), form.p_Unite_2, FALSE, FALSE, 0);
      gtk_widget_set_size_request(form.p_Resultat_2, 50, 28);
      gtk_widget_set_size_request(form.p_Unite_2, 50, 28);
   // Définition des callbacks
     g_signal_connect (
        G_OBJECT (form.p_Liste_reg), 
        "changed",G_CALLBACK(Calcul),&form
        );
     g_signal_connect (
        G_OBJECT (form.p_Liste_duree),
        "changed",G_CALLBACK(Calcul),&form
        );
     g_signal_connect (
        G_OBJECT (form.p_Liste_type),
        "changed",G_CALLBACK(Calcul),&form
        );
     g_signal_connect (
        G_OBJECT (form.p_Num_surface),
        "value_changed",G_CALLBACK(Calcul),&form
        );
     g_signal_connect (
        G_OBJECT (form.p_Num_chemin),
        "value_changed",G_CALLBACK(Calcul),&form
        );
     g_signal_connect (
        G_OBJECT (form.p_Num_pente),
        "value_changed",G_CALLBACK(Calcul),&form
        );
	  g_signal_connect(
        G_OBJECT(p_Fenetre), "destroy",
        G_CALLBACK(gtk_main_quit), NULL
        );
	  g_signal_connect(
        G_OBJECT(p_Button), "clicked",
        G_CALLBACK(carte_france), NULL
        );
     g_signal_connect (
        G_OBJECT (form.p_Unite),
        "clicked",G_CALLBACK(switch_unite),
        (gpointer)form.p_Resultat
        );
     g_signal_connect (
        G_OBJECT (form.p_Unite_2),
        "clicked",G_CALLBACK(switch_unite),
        (gpointer)form.p_Resultat_2
        );
   // affiche la boucle évènementielle
      gtk_widget_show_all(p_Fenetre);
      gtk_main();
}
