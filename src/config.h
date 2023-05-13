typedef struct config_exclude_data
{
    char* str;
    int isblank;
    int size;
} config_exclude_data;

typedef struct config_xgeo
{
    int x;
    int y;
    int z;
    int sy;
    int sz;
} config_xgeo;

typedef struct config_wintype
{
	// note, this struct uses the value "2" to specify a default value
    int fade;
    int shadow;
    int full_shadow;
    int clip_shadow_above;
    int force_focus;
    int redir_ignore;
    double opacity;
} config_wintype;



char *read_config_str_value(const char *value, const char *defaultval);
void write_config_str_value(const char *value, const char *value2);
void init_config();
void destroy_config();
void open_config_file();
void write_config_file();
void wipe_config_value(const char *value);
int read_config_bool_value(const char *value);
void write_config_bool_value(const char *value, int value2);
double read_config_float_value(const char *value, double defaultval);
void write_config_float_value(const char *value, double value2);
int read_config_int_value(const char *value, int defaultval);
void write_config_int_value(const char *value, int value2);
GdkRectangle convert_picom_rect_to_normal(config_xgeo picom_rect);
const char *get_config_file();
int does_config_value_exist(const char *value);
//config_exclude read_exclude_array();
config_xgeo read_geometry();
config_wintype read_config_wintypes_value(const char *wintype);
void write_config_wintypes_value(config_wintype wt, const char *wintype);
void read_config_exclude_array_temp(GtkWidget *list, const char* array);
void write_config_exclude_array_temp(GtkWidget *list, const char *array);
gboolean write_config_exclude_array_temp_ind(GtkTreeModel *model, GtkTreePath *path, GtkTreeIter *iter, gpointer data);
void save_geometry(config_xgeo geo, const char *value);
