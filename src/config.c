#include <gtk/gtk.h>
#include <libconfig.h>
#include <math.h>
#include <libintl.h>
#include <locale.h>
#include "ui.h"
#include "config.h"

#define _(String) gettext(String)


config_t cfg;
config_setting_t *setting;
config_setting_t *root;

void init_config()
{
    config_init(&cfg);
    root = config_root_setting(&cfg);
}

void destroy_config()
{
    config_destroy(&cfg);
}

void show_config_error(int save)
{
    char message[256];
    if (save == 0)
    {
        if (config_error_file(&cfg))
        {
            snprintf(message, sizeof message, _("Config load failed: %s (%s:%d)\n"), config_error_text(&cfg), config_error_file(&cfg), config_error_line(&cfg));
        }
        else
        {
            snprintf(message, sizeof message, _("Config load failed: %s (%s)\n"), config_error_text(&cfg), get_config_file());
        }
    }
    else
    {
        snprintf(message, sizeof message, _("Config save failed: %s (%s:%d)\n"), config_error_text(&cfg), config_error_file(&cfg), config_error_line(&cfg));
    }
    show_error_dialog(message);
    destroy_config();
    exit(EXIT_FAILURE);
}

void open_config_file()
{
    if (config_read_file(&cfg, get_config_file()) == CONFIG_FALSE)
    {
        show_config_error(0);
    }
    root = config_root_setting(&cfg);
}

void write_config_file()
{
    if (config_write_file(&cfg, get_config_file()) == CONFIG_FALSE)
    {
        show_config_error(1);
    }
}

const char *get_config_file()
{
    char *config_file;
    char *config_folder;
    config_folder = getenv("XDG_CONFIG_HOME");
    if (config_folder == NULL)
    {
        char *home_folder = getenv("HOME");
        config_folder = malloc(strlen(home_folder) + strlen("/.config") + 1);
        strcpy(config_folder, home_folder);
        strcat(config_folder, "/.config");
    }
    config_file = malloc(strlen(config_folder) + strlen("/picom.conf") + 1);
    strcpy(config_file, config_folder);
    strcat(config_file, "/picom.conf");
    if (access(config_file, F_OK) != 0)
    {
        FILE *config_file_ptr = fopen(config_file, "w");
        fclose(config_file_ptr);
    }
    return strdup(config_file);
}

char *read_config_str_value(const char *value, const char *defaultval)
{
    const char *retval;
    char *retvalact;
    if (config_lookup_string(&cfg, value, &retval) != CONFIG_FALSE)
    {
        retvalact = malloc(strlen(retval) + 1);
        strcpy(retvalact, retval);
    }
    else
    {
        retvalact = malloc(strlen(defaultval) + 1);
        strcpy(retvalact, defaultval);
    }
    return strdup(retvalact);
}

void write_config_str_value(const char *value, const char *value2)
{
    if (config_lookup(&cfg, value) == NULL)
    {
        setting = config_setting_add(root, value, CONFIG_TYPE_STRING);
    }
    else
    {
        setting = config_lookup(&cfg, value);
    }
    config_setting_set_string(setting, value2);
}

int does_config_value_exist(const char *value)
{
    int retval = 1;
    if (config_lookup(&cfg, value) == NULL)
    {
        retval = 0;
    }
    return retval;
}

void wipe_config_value(const char *value)
{
    if (config_lookup(&cfg, value) != NULL)
    {
        config_setting_remove(root, value);
    }
}

int read_config_bool_value(const char *value)
{
    int retval = 0;
    config_lookup_bool(&cfg, value, &retval);
    return retval;
}

void write_config_bool_value(const char *value, int value2)
{
    if (config_lookup(&cfg, value) == NULL)
    {
        setting = config_setting_add(root, value, CONFIG_TYPE_BOOL);
    }
    else
    {
        setting = config_lookup(&cfg, value);
    }
    config_setting_set_bool(setting, value2);
}

double read_config_float_value(const char *value, double defaultval)
{
    double retval = defaultval;
    config_lookup_float(&cfg, value, &retval);
    return retval;
}

void write_config_float_value(const char *value, double value2)
{
    if (config_lookup(&cfg, value) == NULL)
    {
        setting = config_setting_add(root, value, CONFIG_TYPE_FLOAT);
    }
    else
    {
        setting = config_lookup(&cfg, value);
    }
    config_setting_set_float(setting, value2);
}

int read_config_int_value(const char *value, int defaultval)
{
    int retval = defaultval;
    config_lookup_int(&cfg, value, &retval);
    return retval;
}

void write_config_int_value(const char *value, int value2)
{
    if (config_lookup(&cfg, value) == NULL)
    {
        setting = config_setting_add(root, value, CONFIG_TYPE_INT);
    }
    else
    {
        setting = config_lookup(&cfg, value);
    }
    config_setting_set_int(setting, value2);
}

void save_geometry(config_xgeo geo, const char *value)
{
    char strc[256];

    if (geo.sy == 1)
    {
        if (geo.sz == 1)
        {
            snprintf(strc, sizeof strc, "x%d+%d+%d", geo.x, geo.y, geo.z);
        }
        else
        {
            snprintf(strc, sizeof strc, "x%d+%d-%d", geo.x, geo.y, geo.z);
        }
    }
    else
    {
        if (geo.sz == 1)
        {
            snprintf(strc, sizeof strc, "x%d-%d+%d", geo.x, geo.y, geo.z);
        }
        else
        {
            snprintf(strc, sizeof strc, "x%d-%d-%d", geo.x, geo.y, geo.z);
        }
    }

    write_config_str_value(value, strc);
}

config_xgeo read_geometry(const char *value)
{
    const char *geostr;
    config_xgeo retval;
    int tempintlength = 0;

    // Try loading the value from the config file. If the value is blank or it does not exist, return a blank value.
    if (config_lookup(&cfg, value) == NULL)
    {
        retval.x = 0;
        retval.y = 0;
        retval.z = 0;
        retval.sy = 0;
        retval.sz = 0;
        return retval;
    }
    else
    {
        config_lookup_string(&cfg, value, &geostr);
    }

    // Skip the "x" that is present at the beginning of the string.
    geostr++;
    // Get the first number and parse it as an integer.
    retval.x = atoi(geostr);
    // After we parse the number with atoi, we first need to skip the first number so we can parse the first sign.
    tempintlength = floor(log10(abs(retval.x))) + 1;
    for (int i = 0; i < tempintlength; ++i)
    {
        geostr++;
    }
    if (geostr[0] == '+')
    {
        retval.sy = 1;
    }
    else
    {
        retval.sy = 0;
    }

    retval.y = atoi(geostr);

    // This code does the exact same skipping operation as last time but zeros can't be positive or negative so we are checking for that.
    if (retval.y != 0)
    {
        tempintlength = floor(log10(abs(retval.y))) + 1;
        for (int i = 0; i < tempintlength; ++i)
        {
            geostr++;
        }
        geostr++;
    }
    else
    {
        geostr = geostr + 2;
    }

    if (geostr[0] == '+')
    {
        retval.sz = 1;
    }
    else
    {
        retval.sz = 0;
    }

    retval.z = atoi(geostr);
    return retval;
}

GdkRectangle convert_picom_rect_to_normal(config_xgeo picom_rect)
{

    GdkRectangle result_rect;
    GdkRectangle monitor_rect;
    int gdk_scale;

    GdkMonitor *monitor = gdk_display_get_primary_monitor(gdk_display_get_default());
    gdk_monitor_get_geometry(monitor, &monitor_rect);
    gdk_scale = gdk_monitor_get_scale_factor(monitor);
    monitor_rect.width = monitor_rect.width * gdk_scale;
    monitor_rect.height = monitor_rect.height * gdk_scale;

    result_rect.width = monitor_rect.width - abs(picom_rect.y);
    result_rect.height = abs(picom_rect.x);

    if (picom_rect.sy == 1)
    {
        result_rect.x = abs(picom_rect.z) + abs(picom_rect.y);
    }
    else
    {
        result_rect.x = monitor_rect.x - abs(picom_rect.z);
    }

    if (picom_rect.sz == 1)
    {
        result_rect.y = abs(picom_rect.z);
    }
    else
    {
        result_rect.y = monitor_rect.height - picom_rect.x - abs(picom_rect.z);
    }
    return result_rect;
}

// this function is currently very broken.
/*config_exclude read_exclude_array()
{

    config_exclude ret;

    const char *item;
    char *token;

    int index = 0, cindex = 0, len = 0, i = 0;
    if (config_lookup(&cfg, "shadow-exclude") == NULL)
    {
        setting = config_setting_add(root, "shadow-exclude", CONFIG_TYPE_ARRAY);
    }
    else
    {
        setting = config_lookup(&cfg, "shadow-exclude");
    }

    len = config_setting_length(setting);

    if (len == 0)
    {
        ret.len = 0;
        return ret;
    }

    config_exclude_data configexclude[len];

    for (i = 0; i < len; ++i)
    {
        cindex = 0;
        item = config_setting_get_string_elem(setting, i);
        token = strtok(item, ":");
        while (token != NULL)
        {
            switch (cindex)
            {
            case 0:
                strcpy(configexclude[index].target, token);
                break;
            case 1:
                strcpy(configexclude[index].type, token);
                break;
            case 2:
                configexclude[index].pattern = malloc(strlen(token) + 1);
                strcpy(configexclude[index].pattern, token);
                break;
            }
            token = strtok(NULL, ":");
            cindex++;
        }
        index++;
    }
    ret.data = configexclude;
    ret.len = index;

    return ret;
} */

void write_config_wintypes_value_bool_internal(const char *value, int val)
{
    config_setting_t *csetting = config_setting_get_member(setting, value);

    if (val != 2)
    {
        if (csetting == NULL)
        {
            csetting = config_setting_add(setting, value, CONFIG_TYPE_BOOL);
        }
        config_setting_set_bool(csetting, val);
    }
    else
    {
        if (csetting != NULL)
        {
            config_setting_remove(setting, value);
        }
    }
}

void write_config_wintypes_value_float_internal(const char *value, double val)
{
    config_setting_t *csetting = config_setting_get_member(setting, value);

    if (val != 2)
    {
        if (csetting == NULL)
        {
            csetting = config_setting_add(setting, value, CONFIG_TYPE_FLOAT);
        }
        config_setting_set_float(csetting, val);
    }
    else
    {
        if (csetting != NULL)
        {
            config_setting_remove(setting, value);
        }
    }
}

void write_config_wintypes_value(config_wintype wt, const char *wintype)
{
    setting = config_setting_get_member(root, "wintypes");
    if (setting == NULL)
    {
        setting = config_setting_add(root, "wintypes", CONFIG_TYPE_GROUP);
    }

    setting = config_setting_get_member(setting, wintype);
    if (setting == NULL)
    {
        setting = config_setting_add(config_setting_get_member(root, "wintypes"), wintype, CONFIG_TYPE_GROUP);
    }

    write_config_wintypes_value_bool_internal("fade", wt.fade);
    write_config_wintypes_value_bool_internal("shadow", wt.shadow);
    write_config_wintypes_value_bool_internal("full-shadow", wt.full_shadow);
    write_config_wintypes_value_bool_internal("clip-shadow-above", wt.clip_shadow_above);
    write_config_wintypes_value_bool_internal("focus", wt.force_focus);
    write_config_wintypes_value_bool_internal("redir-ignore", wt.redir_ignore);
    write_config_wintypes_value_float_internal("opacity", wt.opacity);
}

gboolean write_config_exclude_array_temp_ind(GtkTreeModel *model, GtkTreePath *path, GtkTreeIter *iter, gpointer data)
{
    char *condition;

    gtk_tree_model_get(model, iter, 0, &condition, -1);
    config_setting_set_string_elem(setting, -1, condition);
    return FALSE;
}

void write_config_exclude_array_temp(GtkWidget *list, const char *array)
{
    GtkListStore *store;
    GtkTreeModel *model;

    setting = config_setting_get_member(root, array);

    if (setting != NULL)
    {
        config_setting_remove(root, array);
    }

    setting = config_setting_add(root, array, CONFIG_TYPE_ARRAY);

    store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(list)));
    model = gtk_tree_view_get_model(GTK_TREE_VIEW(list));

    gtk_tree_model_foreach(model, write_config_exclude_array_temp_ind, NULL);
}

void read_config_exclude_array_temp(GtkWidget *list, const char *array)
{
    GtkListStore *store;
    GtkTreeIter iter;

    store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(list)));

    setting = config_setting_get_member(root, array);

    if (setting == NULL)
    {
        return;
    }

    int exclude_condition_len = config_setting_length(setting);
    if (exclude_condition_len == 0)
    {
        return;
    }

    for (int i = 0; i < exclude_condition_len; i++)
    {
        // printf("%s\n", config_setting_get_string_elem(setting, i));
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, 0, config_setting_get_string_elem(setting, i), -1);
    }
}

config_wintype read_config_wintypes_value(const char *wintype)
{
    config_wintype retval;
    int fade = 2, shadow = 2, full_shadow = 2, clip_shadow_above = 2, force_focus = 2, redir_ignore = 2;
    double opacity = 2;

    setting = config_setting_get_member(root, "wintypes");
    if (setting == NULL)
    {
        goto wtreturn;
    }

    setting = config_setting_get_member(setting, wintype);
    if (setting == NULL)
    {
        goto wtreturn;
    }

    config_setting_lookup_bool(setting, "fade", &fade);
    config_setting_lookup_bool(setting, "shadow", &shadow);
    config_setting_lookup_bool(setting, "full-shadow", &full_shadow);
    config_setting_lookup_bool(setting, "clip-shadow-above", &clip_shadow_above);
    config_setting_lookup_bool(setting, "focus", &force_focus);
    config_setting_lookup_bool(setting, "redir-ignore", &redir_ignore);
    config_setting_lookup_float(setting, "opacity", &opacity);

wtreturn:
    retval.fade = fade;
    retval.shadow = shadow;
    retval.full_shadow = full_shadow;
    retval.clip_shadow_above = clip_shadow_above;
    retval.force_focus = force_focus;
    retval.redir_ignore = redir_ignore;
    retval.opacity = opacity;
    return retval;
}
