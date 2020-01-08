/*
    Thanks to kafeman's article! URL: https://habr.com/ru/post/136922/
    Simple program which convert glade file to functional interface
*/
#include <gtk/gtk.h>
#define NAME "Draw Your Own Object"
#include <gmodule.h>
GtkBuilder *builder;
gpointer *user_data;
/* создание окна в этот раз мы вынесли в отдельную функцию */
static GtkWidget* find_interface (void)
{
        /* это виджет окна */
        GtkWidget *window;
        /* это тот волшебный объект, который сделает за нас окошко */
        /* сюда будем складывать ошибки */
        GError* error = NULL;

        /* тут загружаем файл с интерфейсом */
        builder = gtk_builder_new ();
        if (!gtk_builder_add_from_file (builder, "interface.glade", &error))
        {
                /* загрузить файл не удалось */
                g_critical ("Can't load file: %s", error->message);
                g_error_free (error);
        }

        /* помните, мы подключали сигналы вручную? теперь это происходит автоматически! */
        gtk_builder_connect_signals (builder, user_data);

        /* получаем виджет окна, чтобы его показать */
        window = GTK_WIDGET (gtk_builder_get_object (builder, "Main_Window"));
        if (!window)
        {
                /* что-то не так, наверное, ошиблись в имени */
                g_critical ("Error to get main window id ");
        }
        g_object_unref (builder);

        return window;
}
extern "C" {
G_MODULE_EXPORT void a_look(GtkEntry *entry,gpointer user_data){
    const gchar *text;
    text = gtk_entry_get_text(entry);
    gtk_label_set_text(GTK_LABEL(user_data),text);
}}
int main (int argc, char *argv[])
{
        /* виджет окна */
        GtkWidget *window;
        /* запускаем GTK+ */
        gtk_init (&argc, &argv);

        /* вызываем нашу функцию для создания окна */
        window = find_interface();
        gtk_window_set_title(GTK_WINDOW(window),NAME);
        gtk_widget_show (window);

        g_signal_connect (window, "destroy",G_CALLBACK (gtk_main_quit),NULL);
        /* передаём управление GTK+ */
        gtk_main ();
        return 0;
}
