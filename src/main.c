#include <gtk/gtk.h>
#include <libconfig.h>
#include <math.h>
#include <libintl.h>
#include <locale.h>
#include "ui.h"
#include "config.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    bindtextdomain("picom-conf-gtk", "/usr/share/locale");
    bind_textdomain_codeset("picom-conf-gtk", "UTF-8");
    textdomain("picom-conf-gtk");
    gtk_init(&argc, &argv);
    init_config();
    open_config_file(); 
    create_window();
    destroy_config();
    gtk_main();
    return 0;
}
