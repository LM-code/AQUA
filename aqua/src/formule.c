/*****************************************************************
*                                                                *
*                                                                *
*****************************************************************/
#include <stdio.h>
#include <math.h>
#include <gtk/gtk.h>
#include "formule.h"

void Calcul (GtkWidget *p_Fenetre,gpointer p_data){
   // Variable pour récupérer les données du formulaire 
   donnee *recup = (donnee *) p_data;
   const gchar *p_text_1 = NULL;
   const gchar *p_text_2 = NULL;
   const gchar *p_text_3 = NULL;
   const gchar *p_text_4 = NULL;
   const gchar *p_text_5 = NULL;
   const gchar *p_text_10 = NULL;
   const gchar *p_text_11 = NULL;
   gchar text[80]="";
   gint Region_num = 0;
   gint Duree_num = 0;
   // Variable de calcul pour le débit 
   gint Chemin = 0, a = 0, x = 0;
   gfloat Surface = 0, Debit_brute = 0, Debit_corrige = 0; 
   gfloat Pente = 0, Coef_allong = 0;
   gfloat Tmp_1 = 0, Tmp_2 = 0, Coef_cor = 0;
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
      GTK_COMBO_BOX (recup->p_Liste_reg));
   p_text_2 = gtk_combo_box_get_active_text (
      GTK_COMBO_BOX (recup->p_Liste_duree));
   p_text_3 = gtk_combo_box_get_active_text (
      GTK_COMBO_BOX (recup->p_Liste_type));
   Surface = gtk_spin_button_get_value (
      GTK_SPIN_BUTTON (recup->p_Num_surface));
   Chemin = gtk_spin_button_get_value (
      GTK_SPIN_BUTTON (recup->p_Num_chemin));
   Pente = gtk_spin_button_get_value (
      GTK_SPIN_BUTTON (recup->p_Num_pente));
   p_text_4 = gtk_button_get_label(GTK_BUTTON(recup->p_Unite));
   p_text_5 = gtk_button_get_label(GTK_BUTTON(recup->p_Unite_2));
	/*g_strlcat (text,p_text_1,200);
	g_strlcat (text," - ",200);
	g_strlcat (text,p_text_2,200);
	g_strlcat (text," - ",200);
	g_strlcat (text,p_text_3,200);*/
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
	// Conversion de la variable pente de mm en m
   Pente = Pente/100;
	// Calcul la colonne du tableau de caquot
   x = ( 4 * Region_num ) - 1 - sqrt ( Duree_num - 1); 
	/* calcul le débit brute

   Paramètres :
   ------------
   a     : tableau caquot
   b     : tableau caquot
   Kbéta : 0,5 ^ b x a / 6,6
   Alpha : 0,287 x b + 1
   Béta  : 0,41 x b
   Gamma : 0,95 + 0,507 x b

   formule débit brute de l'orage int 77-284 :
   -------------------------------------------

   Q = Kbéta x (Pente moy Bas ^ Alpha) x (coef ruis ^ Béta) x (Aire ^ Gamma)
   
   */
   Puis_1 = pow(Pente,Tab_caquot[5][x]); 
   Puis_2 = pow(C_strickler[a],Tab_caquot[6][x]); 
   Puis_3 = pow((Surface/10000),Tab_caquot[7][x]); 
	Debit_brute = Tab_caquot[4][x] * Puis_1 * Puis_2 * Puis_3;
   if (strcmp(p_text_4,"L/S") == 0){
		p_text_10 = g_strdup_printf("%.0f",Debit_brute*1000);
   }
   if (strcmp(p_text_4,"M3/S") == 0){
		p_text_10 = g_strdup_printf("%.3f",Debit_brute);
   }
	//g_strlcat (text,p_text_10,200);
		//p_text_10 = g_strdup_printf("%.4f",/10000);
	gtk_entry_set_text(GTK_ENTRY (recup->p_Resultat),p_text_10);
	/*  formule du coefficient d'allongement

   Paramètres :
   ------------
   L : longueur maximal de cheminement par rapport à l'éxutoire
   A : Aire de la surfarce à reprendre

   Formule :
   ---------
   M = L / ( A ^ 0.5 )
   */
   Coef_allong = pow(Surface,0.5); 
   Coef_allong = Chemin / Coef_allong;
	/*  formule du coefficient correctif

   Paramètres :
   ------------
   M : Coefficient d'allongement
   b : tableau caquot

   Formule :
   ---------
   m = ( M / 2 ) ^ ( 0.84 x b / ( 1 + 0.29 x b ))
   */
   Tmp_1 = Coef_allong / 2; 
   Tmp_2 = (0.84 * Tab_caquot[3][x]) / (1 + 0.29 * Tab_caquot[3][x]); 
   Coef_cor = pow(Tmp_1,Tmp_2);
	Debit_corrige = Debit_brute * Coef_cor;
   if (strcmp(p_text_5,"L/S") == 0){
		p_text_11 = g_strdup_printf("%.0f",Debit_corrige*1000);
   }
   if (strcmp(p_text_5,"M3/S") == 0){
		p_text_11 = g_strdup_printf("%.3f",Debit_corrige);
   }
	gtk_entry_set_text(GTK_ENTRY (recup->p_Resultat_2),p_text_11);
}
