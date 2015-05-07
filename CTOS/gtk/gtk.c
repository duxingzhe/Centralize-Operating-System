#include <gtk/gtk.h>

gdouble value1=0.0;
gdouble value2=0.0;
gdouble value3=0.0;
gint finished=0;
GtkWidget *table;
GtkWidget *progressBar1,*progressBar2,*progressBar3;
gint timer1,timer2,timer3;
GtkWidget *button1,*button2;

gint timeout_callback3(gpointer data) {
    GString *text;
    if(value3 < 1.0){
      value3 += 0.01;
      if(value3>1.0)
	value3=1.0;
      gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(data), value3);
      text = g_string_new(
			  gtk_progress_bar_get_text(GTK_PROGRESS_BAR(data)));
      g_string_sprintf(text, "%d %%", (int) (value3 * 100));
      gtk_progress_bar_set_text(GTK_PROGRESS_BAR(data), text->str);
    }
    if(value3 == 1.0) {
      finished++;
      if(finished==2)
	gtk_button_set_label(GTK_BUTTON(button2),"OK");
      return 0;
    }
    return TRUE;
}

gint timeout_callback2(gpointer data) {
    GString *text;
    if(value2 < 1.0){
      value2 += 0.02;
      if(value2>1.0)
	value2=1.0;
      gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(data), value2);
      text = g_string_new(
			  gtk_progress_bar_get_text(GTK_PROGRESS_BAR(data)));
      g_string_sprintf(text, "%d %%", (int) (value2 * 100));
      gtk_progress_bar_set_text(GTK_PROGRESS_BAR(data), text->str);
    }
    if(value2==1.0){
      finished++;
      return 0;
    }
    return TRUE;
}

gint timeout_callback1(gpointer data) {
    GString *text;
    if(value1 < 1.0){
      value1 += 0.04;
      if(value1>1.0)
	value1=1.0;
      gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(data), value1);
      text = g_string_new(
			  gtk_progress_bar_get_text(GTK_PROGRESS_BAR(data)));
      g_string_sprintf(text, "%d %%", (int) (value1 * 100));
      gtk_progress_bar_set_text(GTK_PROGRESS_BAR(data), text->str);
    }
    if(value1 == 1.0) {
      return 0;
    }
    return TRUE;
}

void callback( GtkWidget *widget,gpointer data )
{
    timer1 = gtk_timeout_add(100, timeout_callback1, progressBar1);
    timer2 = gtk_timeout_add(100, timeout_callback2, progressBar2);
    timer3 = gtk_timeout_add(100, timeout_callback3, progressBar3);
}

void delete_event( GtkWidget *widget,GdkEvent *event,gpointer data )
{
  gtk_main_quit ();
}

int main(int argc,char *argv[])
{
  GtkWidget *window;
  GtkWidget *lblTest;

  gtk_init (&argc, &argv);
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "CTOS Backdoor Install Wizard");
  gtk_signal_connect (GTK_OBJECT (window), "delete_event",
		      GTK_SIGNAL_FUNC (delete_event), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (window), 20);
  table = gtk_table_new (4, 6, TRUE);
  gtk_container_add (GTK_CONTAINER (window), table);
  button1 = gtk_button_new_with_label ("Install");
  gtk_signal_connect (GTK_OBJECT (button1), "clicked",
		      GTK_SIGNAL_FUNC (callback), (gpointer) "button 1");
  gtk_table_attach_defaults (GTK_TABLE(table), button1, 2, 3, 3, 4);
  gtk_widget_show (button1);
  button2 = gtk_button_new_with_label ("Cancel");
  gtk_signal_connect (GTK_OBJECT (button2), "clicked",
		      GTK_SIGNAL_FUNC (delete_event), (gpointer) "button 2");
  gtk_table_attach_defaults (GTK_TABLE(table), button2, 3, 4, 3, 4);
  gtk_widget_show (button2);
  progressBar1 = gtk_progress_bar_new();
  gtk_table_attach_defaults (GTK_TABLE(table), progressBar1, 3, 6, 0, 1);
  gtk_widget_show(progressBar1);
  progressBar2 = gtk_progress_bar_new();
  gtk_table_attach_defaults (GTK_TABLE(table), progressBar2, 3, 6, 1, 2);
  gtk_widget_show(progressBar2);
  progressBar3 = gtk_progress_bar_new();
  gtk_table_attach_defaults (GTK_TABLE(table), progressBar3, 3, 6, 2, 3);
  gtk_widget_show(progressBar3);
  lblTest = gtk_label_new("Hacking");
  gtk_table_attach_defaults (GTK_TABLE(table), lblTest, 0, 3, 0, 1);
  gtk_widget_show(lblTest);
  lblTest = gtk_label_new("Sub Module");
  gtk_table_attach_defaults (GTK_TABLE(table), lblTest, 0, 3, 1, 2);
  gtk_widget_show(lblTest);
  lblTest = gtk_label_new("Main");
  gtk_table_attach_defaults (GTK_TABLE(table), lblTest, 0, 3, 2, 3);
  gtk_widget_show(lblTest);
  gtk_widget_show (table);
  gtk_widget_show (window);
  gtk_main ();
  return 0;
}
