#include <stdio.h>
#include <math.h>
#include <gtk/gtk.h>
#include "fonction.h"

void switch_unite (GtkWidget *Widget, gpointer p_data){
   static gboolean change = TRUE;
   const gchar *p_text_1 = NULL;
   const gchar *p_text_2 = NULL;
   gdouble Tmp = 0;
	p_text_1 = gtk_entry_get_text (GTK_ENTRY(p_data));
	Tmp = g_strtod (p_text_1,0);
	// converti la chaine en numérique
   if (change){
      gtk_button_set_label(GTK_BUTTON(Widget), "M3/S"); 
      Tmp = Tmp / 1000; 
		p_text_2 = g_strdup_printf("%.3f",Tmp);
      change = FALSE;
   } 
   else{
      gtk_button_set_label(GTK_BUTTON(Widget), "L/S"); 
      Tmp = Tmp * 1000; 
		p_text_2 = g_strdup_printf("%.0f",Tmp);
      change = TRUE;
   } 
	// converti la chaine en caractère
	gtk_entry_set_text(GTK_ENTRY (p_data),p_text_2);
}

