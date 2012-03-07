# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <gtk/gtk.h>
typedef struct {
	GtkWidget *p_Nom_bassin;
	GtkWidget *p_Liste_reg;
	GtkWidget *p_Liste_duree;
	GtkWidget *p_Liste_type;
	GtkWidget *p_Num_surface;
	GtkWidget *p_Num_chemin;
	GtkWidget *p_Resultat;
} donnee;

void Calcul (GtkWidget *p_Fenetre,gpointer p_data);
int main (int argc,char *argv[]){
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
      gtk_init(&argc, &argv);
      p_Fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
      gtk_window_set_default_size(GTK_WINDOW(p_Fenetre), 350, 300);
		gtk_window_set_title(
      GTK_WINDOW(p_Fenetre), "Dimensionnement Eaux pluviales");
		g_signal_connect(G_OBJECT(p_Fenetre), "destroy",G_CALLBACK(gtk_main_quit), NULL);
   // Création des boutons
      p_Button = gtk_button_new (); 
   // Création des entrées texte
      form.p_Nom_bassin = gtk_entry_new ();
      gtk_entry_set_text (GTK_ENTRY(form.p_Nom_bassin),"Bassin EP 01");
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
      /*gtk_table_attach(GTK_TABLE(p_Table), pEtiquette[4],
        2, 3, 4, 5,
        GTK_EXPAND, GTK_EXPAND,
        0, 0);*/
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
   // affiche la boucle évènementielle
      gtk_widget_show_all(p_Fenetre);
      gtk_main();
}
void Calcul (GtkWidget *p_Fenetre,gpointer p_data){
   // Variable pour récupérer les données du formulaire 
   donnee *recup = (donnee *) p_data;
   const gchar *p_text_1 = NULL;
   const gchar *p_text_2 = NULL;
   const gchar *p_text_3 = NULL;
   const gchar *p_text_10 = NULL;
   gchar text[50]="";
   gint Region_num = 0;
   gint Duree_num = 0;
   // Variable de calcul pour le débit 
   gint Chemin = 0, a = 0, x = 0;
   gfloat Surface =0, Debit = 0, Pente = 0.005, Puis_1 = 0, Puis_2 = 0, Puis_3 = 0;
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
      GTK_COMBO_BOX (recup->p_Liste_reg));
   p_text_2 = gtk_combo_box_get_active_text (
      GTK_COMBO_BOX (recup->p_Liste_duree));
   p_text_3 = gtk_combo_box_get_active_text (
      GTK_COMBO_BOX (recup->p_Liste_type));
   Surface = gtk_spin_button_get_value (
      GTK_SPIN_BUTTON (recup->p_Num_surface));
   Chemin = gtk_spin_button_get_value (
      GTK_SPIN_BUTTON (recup->p_Num_chemin));
	g_strlcat (text,p_text_1,200);
	g_strlcat (text," - ",200);
	g_strlcat (text,p_text_2,200);
	g_strlcat (text," - ",200);
	g_strlcat (text,p_text_3,200);
   // converti les regions en numérique pour le calcul de débit 
   Region_num = g_ascii_strtoll (p_text_1+7,0,10);
   // converti la durée en numérique pour le calcul de débit 
   Duree_num = g_ascii_strtoll (p_text_2,0,10);
   // converti le type de surface en numérique pour le calcul de débit 
   if (strcmp(p_text_3,"Voirie") == 0 ) {
      a=1;
   }
   if (strcmp(p_text_3,"Espace vert") == 0 ) {
      a=3;
   }
   if (strcmp(p_text_3,"Bâtiment") == 0 ) {
      a=0;
   }
   x = ( 4 * Region_num ) - 1 - sqrt ( Duree_num - 1); 
	// calcul le débit
   Puis_1 = pow(Pente,Tab_caquot[5][x]); 
   Puis_2 = pow(C_strickler[a],Tab_caquot[6][x]); 
   Puis_3 = pow((Surface/10000),Tab_caquot[7][x]); 
	Debit = Tab_caquot[4][x]*Puis_1*Puis_2*Puis_3;
   //g_printf("%.2f",Tab_caquot[5][0]);
   p_text_10 = g_strdup_printf("\nDébit = %.4f m3/s",Debit);
	g_strlcat (text,p_text_10,200);
	gtk_label_set_label(GTK_LABEL (recup->p_Resultat),text);
}
