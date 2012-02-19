# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <gtk/gtk.h>
typedef struct {
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
		pEtiquette[0]=gtk_label_new("Région : ");
		gtk_misc_set_alignment(GTK_MISC(pEtiquette[0]), 1.0, 0.5);
		pEtiquette[1]=gtk_label_new("Période de retour : ");
		gtk_misc_set_alignment(GTK_MISC(pEtiquette[1]), 1.0, 0.5);
		pEtiquette[2]=gtk_label_new("Type de surface : ");
		gtk_misc_set_alignment(GTK_MISC(pEtiquette[2]), 1.0, 0.5);
		pEtiquette[3]=gtk_label_new("Surface Bassin versant : ");
		gtk_misc_set_alignment(GTK_MISC(pEtiquette[3]), 1.0, 0.5);
		pEtiquette[4]=gtk_label_new(" Mètre(s)");
		gtk_misc_set_alignment(GTK_MISC(pEtiquette[4]), 0.0, 0.5);
		pEtiquette[5]=gtk_label_new(" Le plus long chemin : ");
		gtk_misc_set_alignment(GTK_MISC(pEtiquette[5]), 1.0, 0.5);
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
      gtk_combo_box_append_text  (GTK_COMBO_BOX (form.p_Liste_type),"Chaussée");
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
        1, 2, 0, 1,
        GTK_FILL, GTK_EXPAND,
        0, 0);
      gtk_container_add(GTK_CONTAINER(p_Alignement[0]), form.p_Liste_reg );
      gtk_widget_set_size_request(form.p_Liste_reg, 120, 28);
      gtk_table_attach(GTK_TABLE(p_Table), p_Button,
        2, 3, 0, 1,
        GTK_EXPAND, GTK_EXPAND,
        0, 0);
      gtk_widget_set_size_request(p_Button, 28, 28);
      // 2 ème ligne du tableau
      gtk_table_attach(GTK_TABLE(p_Table), pEtiquette[1],
        0, 1, 1, 2,
        GTK_FILL, GTK_EXPAND,
        0, 0);
      gtk_table_attach(GTK_TABLE(p_Table), p_Alignement[1],
        1, 2, 1, 2,
        GTK_FILL, GTK_EXPAND,
        0, 0);
      gtk_container_add(GTK_CONTAINER(p_Alignement[1]), form.p_Liste_duree );
      gtk_widget_set_size_request(form.p_Liste_duree, 120, 28);
      // 3 ème ligne du tableau
      gtk_table_attach(GTK_TABLE(p_Table), pEtiquette[2],
        0, 1, 2, 3,
        GTK_FILL, GTK_EXPAND,
        0, 0);
      gtk_table_attach(GTK_TABLE(p_Table), p_Alignement[2],
        1, 2, 2, 3,
        GTK_FILL, GTK_EXPAND,
        0, 0);
      gtk_container_add(GTK_CONTAINER(p_Alignement[2]), form.p_Liste_type );
      gtk_widget_set_size_request(form.p_Liste_type, 120, 28);
      // 4 ème ligne du tableau
      gtk_table_attach(GTK_TABLE(p_Table), pEtiquette[3],
        0, 1, 3, 4,
        GTK_FILL, GTK_EXPAND,
        0, 0);
      gtk_table_attach(GTK_TABLE(p_Table), p_Alignement[3],
        1, 2, 3, 4,
        GTK_EXPAND, GTK_EXPAND,
        0, 0);
      gtk_container_add(GTK_CONTAINER(p_Alignement[3]),form.p_Num_surface );
      gtk_widget_set_size_request(form.p_Num_surface, 120, 28);
      gtk_table_attach(GTK_TABLE(p_Table), pEtiquette[4],
        2, 3, 3, 4,
        GTK_EXPAND, GTK_EXPAND,
        0, 0);
      // 5 ème ligne du tableau
      gtk_table_attach(GTK_TABLE(p_Table), pEtiquette[5],
        0, 1, 4, 5,
        GTK_FILL, GTK_EXPAND,
        0, 0);
      gtk_table_attach(GTK_TABLE(p_Table), p_Alignement[4],
        1, 2, 4, 5,
        GTK_EXPAND, GTK_EXPAND,
        0, 0);
      gtk_container_add(GTK_CONTAINER(p_Alignement[4]),form.p_Num_chemin );
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
   // affiche la boucle évènementielle
      gtk_widget_show_all(p_Fenetre);
      gtk_main();
   // variable
   unsigned int Region = 0;
   float Surface = 0;
   unsigned int Rugosite = 0;
   unsigned int Chemin_exutoire = 0;
   float Pente = 0.01;
   double Debit = 0, Puis_1 = 0, Puis_2 = 0, Puis_3 = 0;
   /*while ( Region <= 0 || Region >= 4){
	   system("clear");
	   printf ("Entrez votre région ( 1-2-3 ) : ");
		scanf ("%d",&Region);
   }
   // la surface du bassin versant
   while ( 1 ){
	   system("clear");
	   printf ("Entrez votre région ( 1-2-3 ) : %d \n",Region );
      printf ("Entrez votre surface en mètre carré :        m2");
		printf ("\33[9D");
		scanf ("%f",&Surface);
      if ( Surface < 200000 ){
         break;
      }
   }
   // le type de surface
   while ( Rugosite <= 0 || Rugosite >= 5){
	   system("clear");
	   printf ("Entrez votre région ( 1-2-3 ) : %d \n",Region );
      printf ("Entrez votre surface en mètre carré : %.0f m2\n",Surface );
      printf ("Entrez le type de surface : \n\t 1 - bâtiment " );
      printf ("\n\t 2 - chaussée\n\t 3 - Pavage\n\t 4 - Espace vert\n" );
      printf ("choix : " );
		scanf ("%d",&Rugosite);
   }
   // le chemin vers exutoire
	printf ("Entrez le plus long chemin vers l'exutoire : " );
	scanf ("%d",&Chemin_exutoire);
   // Conversion en hectare
   Surface = Surface / 10000; 
   printf ("Surface = %.3f",Surface);
   // calcul le débit
   Puis_1 = pow(Pente,Tab_caquot[5][0]); 
   Puis_2 = pow(C_strickler[Rugosite-1],Tab_caquot[6][0]); 
   Puis_3 = pow(Surface,Tab_caquot[7][0]); 
	Debit = Tab_caquot[4][0]*Puis_1*Puis_2*Puis_3;   
	printf ("\n---------------- RESULTAT ------------------\n" );
	printf ("le débit est de %.3f \n",Debit);*/
}
void Calcul (GtkWidget *p_Fenetre,gpointer p_data){
   gchar *p_text_1 = NULL;
   gchar *p_text_2 = NULL;
   gchar *p_text_3 = NULL;
   gchar text[50]="";
   donnee *recup = (donnee *) p_data;
   p_text_1 = gtk_combo_box_get_active_text (
      GTK_COMBO_BOX (recup->p_Liste_reg));
   p_text_2 = gtk_combo_box_get_active_text (
      GTK_COMBO_BOX (recup->p_Liste_duree));
   p_text_3 = gtk_combo_box_get_active_text (
      GTK_COMBO_BOX (recup->p_Liste_type));
	g_strlcat (text,p_text_1,200);
	g_strlcat (text," - ",200);
	g_strlcat (text,p_text_2,200);
	g_strlcat (text," - ",200);
	g_strlcat (text,p_text_3,200);
	gtk_label_set_label(GTK_LABEL (recup->p_Resultat),text);
   g_free(p_text_1);
   g_free(p_text_2);
} 
