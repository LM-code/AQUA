#include <stdio.h>
#include <math.h>
#include <gtk/gtk.h>
#include "fonction.h"

void switch_unite (GtkWidget *Widget, gpointer p_data){
   const gchar *p_text_1 = NULL;
   const gchar *p_text_2 = NULL;
   const gchar *p_text_3 = NULL;
   gdouble Tmp = 0;
	p_text_1 = gtk_entry_get_text (GTK_ENTRY(p_data));
	p_text_2 = gtk_button_get_label(GTK_BUTTON(Widget)); 
	Tmp = g_strtod (p_text_1,0);
	// converti la chaine en numérique
   if (strcmp (p_text_2,"L/S") == 0 ){
      gtk_button_set_label(GTK_BUTTON(Widget), "M3/S"); 
      Tmp = Tmp / 1000; 
		p_text_3 = g_strdup_printf("%.3f",Tmp);
   } 
   else{
      gtk_button_set_label(GTK_BUTTON(Widget), "L/S"); 
      Tmp = Tmp * 1000; 
		p_text_3 = g_strdup_printf("%.0f",Tmp);
   } 
	// converti la chaine en caractère
	gtk_entry_set_text(GTK_ENTRY (p_data),p_text_3);
}

