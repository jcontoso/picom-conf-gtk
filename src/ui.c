#include <gtk/gtk.h>
#include <libconfig.h>
#include <math.h>
#include <libintl.h>
#include <locale.h>
#include "ui.h"
#include "config.h"

#define _(String) gettext(String)

GtkWidget *window;
GtkWidget *abutton;
GtkWidget *sbutton;
GtkWidget *cbutton;
GtkWidget *box;
GtkWidget *bgrid;
GtkWidget *bsgrid;
GtkWidget *notebook;
GtkWidget *shadow_page_box;
GtkWidget *shadow_page_label;
GtkWidget *shadow_page_enable_shadow_cb;
GtkWidget *shadow_page_enable_xinerama_crop_cb;
GtkWidget *shadow_page_spinnersandcolor_grid;
GtkWidget *shadow_page_blur_spinner;
GtkWidget *shadow_page_leftoffset_spinner;
GtkWidget *shadow_page_topoffset_spinner;
GtkWidget *shadow_page_translucency_spinner;
GtkWidget *shadow_page_shadow_color_button;
GtkWidget *shadow_page_bs_label;
GtkWidget *shadow_page_lo_label;
GtkWidget *shadow_page_to_label;
GtkWidget *shadow_page_ts_label;
GtkWidget *shadow_page_sc_label;
GtkAdjustment *shadow_page_bsa;
GtkAdjustment *shadow_page_losa;
GtkAdjustment *shadow_page_tosa;
GtkAdjustment *shadow_page_tsa;
GtkWidget *opacity_page_box;
GtkWidget *opacity_page_label;
GtkWidget *opacity_page_spinners_grid;
GtkWidget *opacity_page_inactive_spinner;
GtkWidget *opacity_page_active_spinner;
GtkWidget *opacity_page_frame_spinner;
GtkWidget *opacity_page_inactived_spinner;
GtkWidget *opacity_page_combo_spinner;
GtkWidget *opacity_page_dnd_spinner;
GtkWidget *opacity_page_dock_spinner;
GtkWidget *opacity_page_toolbar_spinner;
GtkWidget *opacity_page_tooltip_spinner;
GtkWidget *opacity_page_notification_spinner;
GtkWidget *opacity_page_menu_spinner;
GtkWidget *opacity_page_dmenu_spinner;
GtkWidget *opacity_page_pmenu_spinner;
GtkWidget *opacity_page_is_label;
GtkWidget *opacity_page_as_label;
GtkWidget *opacity_page_fs_label;
GtkWidget *opacity_page_ids_label;
GtkWidget *opacity_page_combos_label;
GtkWidget *opacity_page_dnds_label;
GtkWidget *opacity_page_docks_label;
GtkWidget *opacity_page_tbs_label;
GtkWidget *opacity_page_tts_label;
GtkWidget *opacity_page_notifs_label;
GtkWidget *opacity_page_ms_label;
GtkWidget *opacity_page_dms_label;
GtkWidget *opacity_page_pms_label;
GtkAdjustment *opacity_page_isa;
GtkAdjustment *opacity_page_asa;
GtkAdjustment *opacity_page_fsa;
GtkAdjustment *opacity_page_idsa;
GtkAdjustment *opacity_page_combosa;
GtkAdjustment *opacity_page_dndsa;
GtkAdjustment *opacity_page_docksa;
GtkAdjustment *opacity_page_tbsa;
GtkAdjustment *opacity_page_ttsa;
GtkAdjustment *opacity_page_notifsa;
GtkAdjustment *opacity_page_msa;
GtkAdjustment *opacity_page_dmsa;
GtkAdjustment *opacity_page_pmsa;
GtkWidget *fade_page_box;
GtkWidget *fade_page_label;
GtkWidget *fade_page_spinners_grid;
GtkWidget *fade_page_enable_fade_cb;
GtkWidget *fade_page_avoid_fading_on_oc_cb;
GtkWidget *fade_page_avoid_destroyed_argb_cb;
GtkWidget *fade_page_delta_spinner;
GtkWidget *fade_page_finsteps_spinner;
GtkWidget *fade_page_foutsteps_spinner;
GtkWidget *fade_page_delta_label;
GtkWidget *fade_page_finsteps_label;
GtkWidget *ser_cb;
GtkWidget *fade_page_foutsteps_label;
GtkAdjustment *fade_page_foutsteps_adj;
GtkAdjustment *fade_page_finsteps_adj;
GtkAdjustment *fade_page_delta_adj;
GdkRGBA shadow_color;
GtkWidget *rounded_corners_page_label;
GtkWidget *rounded_corners_page_box;
GtkWidget *rounded_corners_page_grid;
GtkWidget *rounded_corners_page_radius_label;
GtkAdjustment *rounded_corners_page_radius_adj;
GtkWidget *rounded_corners_page_radius_spinner;
GtkWidget *rounded_corners_page_enable_cb;
GtkWidget *shadow_page_exclude_label;
GtkWidget *shadow_page_exclude_button;
GtkWidget *shadow_page_clip_over_label;
GtkWidget *shadow_page_clip_over_button;
GtkWidget *shadow_page_shadow_exclude_region_label;
GtkWidget *shadow_page_shadow_exclude_region_button;
GtkWidget *shadow_page_shadow_exclude_region_window;
GtkWidget *shadow_page_shadow_exclude_region_dr;
GtkWidget *shadow_page_shadow_exclude_adj_grid;
GtkWidget *shadow_page_shadow_exclude_btn_cgrid;
GtkWidget *shadow_page_shadow_exclude_btn_grid;
GtkWidget *shadow_page_shadow_exclude_apply_btn;
GtkWidget *shadow_page_shadow_exclude_cancel_btn;
GtkWidget *shadow_page_shadow_exclude_xl;
GtkWidget *shadow_page_shadow_exclude_xc;
GtkWidget *shadow_page_shadow_exclude_xa;
GtkWidget *shadow_page_shadow_exclude_yl;
GtkWidget *shadow_page_shadow_exclude_yc;
GtkWidget *shadow_page_shadow_exclude_ya;
GtkWidget *shadow_page_shadow_exclude_zl;
GtkWidget *shadow_page_shadow_exclude_zc;
GtkWidget *shadow_page_shadow_exclude_za;
GtkWidget *blurring_page_label;
GtkWidget *blurring_page_box;
GtkWidget *blurring_page_grid;
GtkWidget *blurring_page_bm_label;
GtkWidget *blurring_page_bm;
GtkWidget *blurring_page_bm_enable_cb;
GtkWidget *blurring_page_bsize;
GtkWidget *blurring_page_bsize_label;
GtkWidget *blurring_page_convkern_label;
GtkWidget *blurring_page_convkern;
GtkWidget *blurring_page_stwb_enable_cb;
GtkWidget *blurring_page_bgb_enable_cb;
GtkWidget *blurring_page_fbs_enable_cb;
GtkWidget *blurring_page_exclude_edit;
GtkWidget *blurring_page_exclude_edit_label;
GtkWidget *blurring_page_deviation_label;
GtkWidget *blurring_page_deviation;
GtkWidget *blurring_page_ccbkern_label;
GtkWidget *blurring_page_ccbkern;
GtkWidget *opacity_page_rules;
GtkWidget *opacity_page_focus;
GtkWidget *opacity_page_rules_label;
GtkWidget *opacity_page_focus_label;
GtkWidget *opacity_page_netwm_cb;
GtkAdjustment *blurring_page_deviation_adj;
GtkAdjustment *blurring_page_bsize_adj;
GtkWidget *rendering_options_page_label;
GtkWidget *rendering_options_page_box;
GtkWidget *rendering_options_page_grid;
GtkWidget *rendering_options_page_b;
GtkWidget *rendering_options_page_b_label;
GtkWidget *rendering_options_page_dither_cb;
GtkWidget *rendering_options_page_vsync_cb;
GtkWidget *rendering_options_page_stbuf_cb;
GtkWidget *rendering_options_page_rebindpix_cb;
GtkWidget *rendering_options_page_xsync_cb;
GtkWidget *rendering_options_page_nodamage_cb;
GtkWidget *rendering_options_page_forceblend_cb;
GtkWidget *rendering_backend_gl_box;
GtkWidget *rendering_backend_gl_grid;
GtkWidget *rendering_backend_gl_shader_rules_button;
GtkWidget *rendering_backend_gl_shader_rules_label;
GtkWidget *rendering_backend_gl_shader_label;
GtkWidget *rendering_backend_gl_shader;
GtkAdjustment *rendering_options_page_max_bright_adj;
GtkWidget *rendering_options_page_max_bright_label;
GtkWidget *rendering_options_page_max_bright;
GtkWidget *rendering_backend_color_invert;
GtkWidget *rendering_backend_color_invert_label;
GtkWidget *win_det_window_grouping_frame;
GtkWidget *win_det_mark_wmwin_focused_cb;
GtkWidget *win_det_mark_ovredir_focused_cb;
GtkWidget *win_det_detect_rounded_corners_cb;
GtkWidget *win_det_detect_client_opacity_cb;
GtkWidget *win_det_use_ewmh_active_win_cb;
GtkWidget *win_det_no_ewmh_fullscreen_cb;
GtkWidget *win_det_unredir_if_possible_cb;
GtkWidget *win_det_page_label;
GtkWidget *rendering_tranclip_ex;
GtkWidget *rendering_tranclip_ex_label;
GtkWidget *rendering_options_page_tranclip_cb;
GtkWidget *win_det_page_box;
GtkWidget *win_det_window_grouping_frame;
GtkWidget *win_det_window_grouping_box;
GtkWidget *win_det_window_grouping_detect_transient_win;
GtkWidget *win_det_window_grouping_none;
GtkWidget *win_det_window_grouping_detect_client_leader;
GtkWidget *win_det_page_grid;
GtkWidget *win_det_unredir_delay;
GtkWidget *win_det_unredir_exclude_label;
GtkWidget *win_det_unredir_delay_label;
GtkWidget *win_det_unredir_exclude;
GtkWidget *win_det_resize_label;
GtkWidget *win_det_resize;
GtkWidget *misc_page_label;
GtkWidget *fade_page_exclude_label;
GtkWidget *fade_page_exclude_button;
GtkWidget *rounded_corners_page_exclude_button;
GtkWidget *rounded_corners_page_exclude_label;
GtkWidget *misc_page_box;
GtkWidget *misc_page_dbus_cb;
GtkWidget *misc_page_daemon_cb;
GtkWidget *misc_page_xerr_cb;
GtkWidget *misc_page_logfile_cb;
GtkWidget *misc_page_pidfile_cb;
GtkWidget *misc_page_grid;
GtkWidget *misc_page_log_level_label;
GtkWidget *misc_page_log_level;
GtkWidget *misc_page_log_file_label;
GtkWidget *misc_page_log_file;
GtkWidget *misc_page_pid_file_label;
GtkWidget *misc_page_log_file_dialog;
GtkWidget *misc_page_pid_file_dialog;
GtkWidget *misc_page_pid_file_box;
GtkWidget *misc_page_pid_file;
GtkWidget *misc_page_pid_file_browse_button;
GtkWidget *misc_page_log_file_browse_button;
GtkWidget *misc_page_log_file_box;
GtkWidget *window_type_specific_overrides_box;
GtkWidget *window_type_specific_overrides_label;
GtkWidget *window_type_specific_overrides_list;
GtkWidget *window_type_specific_overrides_list_label;
GtkWidget *window_type_specific_overrides_edit;
GtkWidget *fade_frame_no;
GtkWidget *fade_frame_force_off;
GtkWidget *fade_frame_force_on;
GtkWidget *shadow_frame_force_on;
GtkWidget *shadow_frame_force_off;
GtkWidget *shadow_frame_no;
GtkWidget *cshadow_frame_force_on;
GtkWidget *cshadow_frame_force_off;
GtkWidget *cshadow_frame_no;
GtkWidget *fshadow_frame_force_on;
GtkWidget *fshadow_frame_force_off;
GtkWidget *fshadow_frame_no;
GtkWidget *ig_frame_no;
GtkWidget *ig_frame_force_on;
GtkWidget *ig_frame_force_off;
GtkWidget *ff_frame_force_off;
GtkWidget *ff_frame_no;
GtkWidget *ff_frame_force_on;
GtkWidget *opacity_frame_cb;
GtkWidget *opacity_frame_s;
GtkWidget *wtdialog;
GtkWidget *cedialog;
GtkWidget *mbtn;
GtkWidget *pbtn;
GtkWidget *condition_edit_temp_list;
GtkWidget *condition_edit_temp_ent;
GtkWidget *shadow_page_shadow_exclude_pos_label;
GtkWidget *shadow_page_shadow_exclude_pos;
GtkWidget *shadow_page_shadow_exclude_h_label;
GtkWidget *shadow_page_shadow_exclude_h;
GtkWidget *shadow_page_shadow_exclude_y_label;
GtkWidget *shadow_page_shadow_exclude_x_label;
GtkWidget *shadow_page_shadow_exclude_y;
GtkWidget *shadow_page_shadow_exclude_x;
GtkAdjustment *shadow_page_shadow_exclude_h_a;
GtkAdjustment *shadow_page_shadow_exclude_x_a;
GtkAdjustment *shadow_page_shadow_exclude_y_a;
GtkAdjustment *win_det_resize_adj;
GtkAdjustment *win_det_unredir_delay_adj;
GdkRectangle shadow_ser_preview_gdk;
config_xgeo shadow_ser_preview_se_geo;
const char *blurring_page_pm_friendlynames[] = {"Gaussian", "Box", "Convolution", "Dual kawase"};
const char *blurring_page_pm_actualnames[] = {"gaussian", "box", "kernel", "dual_kawase"};
const char *blurring_page_ck_friendlynames[] = {"3x3 box", "5x5 box", "3x3 gaussian", "5x5 gaussian", "7x7 gaussian", "9x9 gaussian", "11x11 gaussian"};
const char *blurring_page_ck_actualnames[] = {"3x3box", "5x5box", "7x7box", "3x3gaussian", "5x5gaussian", "7x7gaussian", "9x9gaussian", "11x11gaussian"};
const char *rendering_options_page_backend_friendlynames[] = {"XRender", "OpenGL", "EGL"};
const char *rendering_options_page_backend_actualnames[] = {"xrender", "glx", "egl", "xr_glx_hybrid"};
const char *misc_page_level_actualnames[] = {"trace", "debug", "info", "warn", "error"};
const char *window_type_specific_overrides_types_actualnames[] = {"unknown", "desktop", "dock", "toolbar", "menu", "utility", "splash", "dialog", "normal", "dropdown_menu", "popup_menu", "tooltip", "notification", "combo", "dnd"};
const char *window_type_specific_overrides_types_friendlynames[] = {"Unknown", "Desktop", "Dock", "Toolbar", "Menu", "Utility", "Splash", "Dialog", "Normal", "Dropdown menu", "Popup menu", "Tooltip", "Notification", "Combo", "Drag and drop"};
float shadow_ser_preview_scale, shadow_ser_preview_cscale, shadow_ser_preview_w, shadow_ser_preview_h;
int is_a_preset_kernel = 0, blurring_enabled = 0, bpcbc_enabled = 0, c_config = 0, p_blurring = 1;
enum
{

    LIST_ITEM = 0,
    N_COLUMNS
};

void show_error_dialog(char *message)
{
    GtkWidget *dialog;
    GtkWidget *dwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    dialog = gtk_message_dialog_new(GTK_WINDOW(dwindow), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, message);
    gtk_window_set_title(GTK_WINDOW(dialog), _("Error"));
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    gtk_widget_destroy(dwindow);
}

void toggle_fade_page(int value)
{
    if (value == 0)
    {
        gtk_widget_hide(fade_page_enable_fade_cb);
        gtk_widget_hide(fade_page_avoid_fading_on_oc_cb);
        gtk_widget_hide(fade_page_avoid_destroyed_argb_cb);
        gtk_widget_hide(fade_page_spinners_grid);
    }
    else
    {
        gtk_widget_show(fade_page_enable_fade_cb);
        gtk_widget_show(fade_page_avoid_fading_on_oc_cb);
        gtk_widget_show(fade_page_avoid_destroyed_argb_cb);
        gtk_widget_show(fade_page_spinners_grid);
    }
}

void toggle_shadow_page(int value)
{
    if (value == 0)
    {
        gtk_widget_hide(shadow_page_enable_shadow_cb);
        gtk_widget_hide(shadow_page_enable_xinerama_crop_cb);
        gtk_widget_hide(shadow_page_spinnersandcolor_grid);
    }
    else
    {
        gtk_widget_show(shadow_page_enable_shadow_cb);
        gtk_widget_show(shadow_page_enable_xinerama_crop_cb);
        gtk_widget_show(shadow_page_spinnersandcolor_grid);
    }
}

void rounded_corners_page_cb_checked(GtkWidget *widget, gpointer window)
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(rounded_corners_page_enable_cb)))
    {
        gtk_widget_set_sensitive(rounded_corners_page_radius_spinner, TRUE);
    }
    else
    {
        gtk_widget_set_sensitive(rounded_corners_page_radius_spinner, FALSE);
    }
}

void update_customck()
{
    gtk_widget_set_sensitive(blurring_page_ccbkern, FALSE);
    gtk_entry_set_text(GTK_ENTRY(blurring_page_ccbkern), "");

    if (gtk_combo_box_get_active(GTK_COMBO_BOX(blurring_page_convkern)) == 7)
    {
        gtk_widget_set_sensitive(blurring_page_ccbkern, TRUE);
    }

    if (is_a_preset_kernel != 1)
    {
        if (c_config == 1)
        {
            init_config();
            open_config_file();
        }
        char *kernel = read_config_str_value("blur-kern", "3x3box");
        gtk_entry_set_text(GTK_ENTRY(blurring_page_ccbkern), kernel);
        free(kernel);
        if (c_config == 1)
        {
            destroy_config();
        }
    }
}


void blurring_update_ispk()
{
    is_a_preset_kernel = 0;

    if (c_config == 1)
    {
        init_config();
        open_config_file();
    }
    char *kernel = read_config_str_value("blur-kern", "3x3box");

    if (strcmp("", kernel) == 0)
    {
        is_a_preset_kernel = 2;
        free(kernel);
        destroy_config();
        return;
    }

    for (int i = 0; i < G_N_ELEMENTS(blurring_page_ck_actualnames); i++)
    {
        if (strcmp(blurring_page_ck_actualnames[i], kernel) == 0)
        {
            is_a_preset_kernel = 1;
        }
    }
    free(kernel);
    if (c_config == 1)
    {
        destroy_config();
    }
}


void toggle_blurring_page(int value)
{
    if (value == 0)
    {
        gtk_widget_hide(blurring_page_bm_enable_cb);
        gtk_widget_hide(blurring_page_stwb_enable_cb);
        gtk_widget_hide(blurring_page_bgb_enable_cb);
        gtk_widget_hide(blurring_page_fbs_enable_cb);
        gtk_widget_hide(blurring_page_grid);
    }
    else
    {
        gtk_widget_show(blurring_page_bm_enable_cb);
        gtk_widget_show(blurring_page_stwb_enable_cb);
        gtk_widget_show(blurring_page_bgb_enable_cb);
        gtk_widget_show(blurring_page_fbs_enable_cb);
        gtk_widget_show(blurring_page_grid);
    }
}

void do_blurring_method_control_settings()
{
    blurring_update_ispk();
    gtk_widget_set_sensitive(blurring_page_bsize, FALSE);
    gtk_widget_set_sensitive(blurring_page_deviation, FALSE);
    gtk_widget_set_sensitive(blurring_page_convkern, FALSE);
    gtk_widget_set_sensitive(blurring_page_ccbkern, FALSE);

    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(blurring_page_bm)))
    {
    case 0:
        if (p_blurring == 1)
        {
            gtk_widget_set_sensitive(blurring_page_deviation, TRUE);
        }
    case 1:
        if (p_blurring == 1)
        {
            gtk_widget_set_sensitive(blurring_page_bsize, TRUE);
        }
        break;
    case 2:
        gtk_widget_set_sensitive(blurring_page_convkern, TRUE);
        update_customck();
        break;
    }
}

void close_condition_edit_temp(GtkWidget *widget, gpointer data)
{
    gtk_widget_destroy(cedialog);
}

void condition_edit_temp_changed(GtkEditable *self, gpointer user_data)
{
    gtk_widget_set_sensitive(pbtn, FALSE);
    if (strcmp(gtk_entry_get_text(GTK_ENTRY(condition_edit_temp_ent)), "") != 0)
    {
        gtk_widget_set_sensitive(pbtn, TRUE);
    }
}

void condition_edit_temp_on_changed(GtkWidget *widget, gpointer label)
{
    GtkTreeIter iter;
    GtkTreeModel *model;
    gtk_widget_set_sensitive(GTK_WIDGET(label), FALSE);

    if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(widget), &model, &iter))
    {
        gtk_widget_set_sensitive(GTK_WIDGET(label), TRUE);
    }
}

void create_condition_edit_temp_add(GtkWidget *widget, gpointer data)
{
    GtkListStore *store;
    GtkTreeIter iter;

    store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(condition_edit_temp_list)));

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, LIST_ITEM, gtk_entry_get_text(GTK_ENTRY(condition_edit_temp_ent)), -1);
}

void create_condition_edit_temp_remove(GtkWidget *widget, gpointer selection)
{

    GtkListStore *store;
    GtkTreeModel *model;
    GtkTreeIter iter;
    gtk_window_set_resizable(GTK_WINDOW(cedialog), TRUE);

    store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(condition_edit_temp_list)));
    model = gtk_tree_view_get_model(GTK_TREE_VIEW(condition_edit_temp_list));

    if (gtk_tree_model_get_iter_first(model, &iter) == FALSE)
    {
        return;
    }

    if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), &model, &iter))
    {
        gtk_list_store_remove(store, &iter);
    }
    gtk_window_resize(GTK_WINDOW(cedialog), 2, 2);
    gtk_window_set_resizable(GTK_WINDOW(cedialog), FALSE);
}

void save_condition_edit_temp(GtkWidget *widget, const char *data)
{
    init_config();
    open_config_file();
    write_config_exclude_array_temp(condition_edit_temp_list, data);
    write_config_file();
    destroy_config();
    gtk_widget_destroy(cedialog);
}

void create_condition_edit_temp_init_list(GtkWidget *list)
{

    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkListStore *store;

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("List Items", renderer, "text", LIST_ITEM, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

    store = gtk_list_store_new(N_COLUMNS, G_TYPE_STRING);

    gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(store));

    g_object_unref(store);
}

void create_condition_edit_temp(GtkWidget *widget, const char *type)
{
    init_config();
    open_config_file();
    GtkWidget *action_area;
    GtkWidget *content_area;
    GtkWidget *dbox;
    GtkWidget *hgrid;
    GtkWidget *lgrid;
    GtkWidget *mgrid;
    GtkWidget *gbtn;
    GtkWidget *kbtn;
    GtkWidget *scrollwin;

    cedialog = gtk_dialog_new();
    g_signal_connect_swapped(cedialog, "response", G_CALLBACK(gtk_widget_destroy), cedialog);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(cedialog));
    action_area = gtk_dialog_get_action_area(GTK_DIALOG(cedialog));
    gtk_window_set_resizable(GTK_WINDOW(cedialog), FALSE);
    gtk_window_set_modal(GTK_WINDOW(cedialog), TRUE);
    gtk_window_set_transient_for(GTK_WINDOW(cedialog), GTK_WINDOW(window));
    gtk_window_set_title(GTK_WINDOW(cedialog), _("Condition editor"));
	gtk_window_set_default_size (GTK_WINDOW (cedialog), 300, 100);
	scrollwin = gtk_scrolled_window_new (NULL, NULL);
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrollwin), GTK_POLICY_AUTOMATIC,  GTK_POLICY_AUTOMATIC);



    dbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
    gtk_widget_set_margin_bottom(dbox, 5);
    gtk_widget_set_margin_top(dbox, 5);
    gtk_widget_set_margin_start(dbox, 18);
    gtk_widget_set_margin_end(dbox, 15);
	gtk_widget_set_size_request(dbox, 300, 200);
	
    condition_edit_temp_list = gtk_tree_view_new();
    gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(condition_edit_temp_list), FALSE);

    create_condition_edit_temp_init_list(condition_edit_temp_list);
    read_config_exclude_array_temp(condition_edit_temp_list, type);

    // grid for the buttons
    hgrid = gtk_grid_new();
    gtk_widget_set_hexpand(hgrid, TRUE);
    lgrid = gtk_grid_new();
    gtk_grid_attach(GTK_GRID(hgrid), lgrid, 1, 0, 1, 1);
    gtk_widget_set_hexpand(lgrid, TRUE);
    gtk_widget_set_halign(lgrid, GTK_ALIGN_END);
    mgrid = gtk_grid_new();
    gtk_grid_attach(GTK_GRID(hgrid), mgrid, 0, 0, 1, 1);
    gtk_widget_set_hexpand(mgrid, TRUE);
    gtk_widget_set_halign(mgrid, GTK_ALIGN_END);

    // apply button
    kbtn = gtk_button_new_with_label(_("Apply"));
    gtk_button_set_image(GTK_BUTTON(kbtn), gtk_image_new_from_stock("gtk-apply", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_margin_end(kbtn, 8);
    gtk_widget_set_margin_bottom(kbtn, 2);
    gtk_grid_attach(GTK_GRID(lgrid), kbtn, 0, 0, 1, 1);
    g_signal_connect(G_OBJECT(kbtn), "clicked", G_CALLBACK(save_condition_edit_temp), (void*)type);
    // cancel button
    gbtn = gtk_button_new_with_label(_("Cancel"));
    gtk_button_set_image(GTK_BUTTON(gbtn), gtk_image_new_from_stock("gtk-cancel", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_margin_bottom(gbtn, 2);
    gtk_grid_attach(GTK_GRID(lgrid), gbtn, 1, 0, 1, 1);
    g_signal_connect(G_OBJECT(gbtn), "clicked", G_CALLBACK(close_condition_edit_temp), G_OBJECT(window));

    condition_edit_temp_ent = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(mgrid), condition_edit_temp_ent, 0, 0, 1, 1);
    gtk_widget_set_margin_end(condition_edit_temp_ent, 8);
    gtk_widget_set_margin_bottom(condition_edit_temp_ent, 2);
    g_signal_connect(G_OBJECT(condition_edit_temp_ent), "changed", G_CALLBACK(condition_edit_temp_changed), G_OBJECT(window));

    // apply button
    pbtn = gtk_button_new_with_label(_("Add"));
    gtk_button_set_image(GTK_BUTTON(pbtn), gtk_image_new_from_stock("gtk-add", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_margin_end(pbtn, 8);
    gtk_widget_set_margin_bottom(pbtn, 2);
    gtk_grid_attach(GTK_GRID(mgrid), pbtn, 1, 0, 1, 1);
    g_signal_connect(G_OBJECT(pbtn), "clicked", G_CALLBACK(create_condition_edit_temp_add), G_OBJECT(window));
    // cancel button
    mbtn = gtk_button_new_with_label(_("Remove"));
    gtk_button_set_image(GTK_BUTTON(mbtn), gtk_image_new_from_stock("gtk-remove", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_margin_end(mbtn, 8);
    gtk_widget_set_margin_bottom(mbtn, 2);
    gtk_grid_attach(GTK_GRID(mgrid), mbtn, 2, 0, 1, 1);
    g_signal_connect(G_OBJECT(mbtn), "clicked", G_CALLBACK(create_condition_edit_temp_remove), gtk_tree_view_get_selection(GTK_TREE_VIEW(condition_edit_temp_list)));

    gtk_widget_set_sensitive(pbtn, FALSE);
    gtk_widget_set_sensitive(mbtn, FALSE);

    g_signal_connect(gtk_tree_view_get_selection(GTK_TREE_VIEW(condition_edit_temp_list)), "changed", G_CALLBACK(condition_edit_temp_on_changed), mbtn);

	gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrollwin), condition_edit_temp_list);
    gtk_box_pack_start(GTK_BOX(dbox), scrollwin, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(action_area), hgrid, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(content_area), dbox);
    gtk_widget_show_all(cedialog);
    destroy_config();
}

void blurring_ckernel_onchanged(GtkComboBox *widget, gpointer user_data)
{
    do_blurring_method_control_settings();
}

void blurring_bmethod_onchanged(GtkComboBox *widget, gpointer user_data)
{
    do_blurring_method_control_settings();
}

void save_blurring_page()
{

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(blurring_page_bm_enable_cb)) == FALSE)
    {
        write_config_str_value("blur-method", "none");
    }
    else
    {
        write_config_str_value("blur-method", blurring_page_pm_actualnames[gtk_combo_box_get_active(GTK_COMBO_BOX(blurring_page_bm))]);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(blurring_page_stwb_enable_cb)) == TRUE)
    {
        write_config_bool_value("blur-background", 1);
    }
    else
    {
        write_config_bool_value("blur-background", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(blurring_page_bgb_enable_cb)) == TRUE)
    {
        write_config_bool_value("blur-background-frame", 1);
    }
    else
    {
        write_config_bool_value("blur-background-frame", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(blurring_page_fbs_enable_cb)) == TRUE)
    {
        write_config_bool_value("blur-background-fixed", 1);
    }
    else
    {
        write_config_bool_value("blur-background-fixed", 0);
    }

    if (gtk_combo_box_get_active(GTK_COMBO_BOX(blurring_page_convkern)) != 7)
    {
        write_config_str_value("blur-kern", blurring_page_ck_actualnames[gtk_combo_box_get_active(GTK_COMBO_BOX(blurring_page_convkern)) + 1]);
    }
    else
    {
        write_config_str_value("blur-kern", gtk_entry_get_text(GTK_ENTRY(blurring_page_ccbkern)));
    }

    write_config_int_value("blur-size", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(blurring_page_bsize)));
    write_config_float_value("blur-deviation", gtk_spin_button_get_value(GTK_SPIN_BUTTON(blurring_page_deviation)));
}

void blurring_page_cb_checked_actual()
{
    if (bpcbc_enabled == 1)
    {
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(blurring_page_bm_enable_cb)))
        {
            gtk_widget_set_sensitive(blurring_page_stwb_enable_cb, TRUE);
            gtk_widget_set_sensitive(blurring_page_bgb_enable_cb, TRUE);
            gtk_widget_set_sensitive(blurring_page_fbs_enable_cb, TRUE);
            gtk_widget_set_sensitive(blurring_page_bm, TRUE);
            gtk_widget_set_sensitive(blurring_page_convkern, TRUE);
            gtk_widget_set_sensitive(blurring_page_ccbkern, TRUE);
            gtk_widget_set_sensitive(blurring_page_bsize, TRUE);
            gtk_widget_set_sensitive(blurring_page_exclude_edit, TRUE);
            gtk_widget_set_sensitive(blurring_page_deviation, TRUE);
            do_blurring_method_control_settings();
        }
        else
        {
            gtk_widget_set_sensitive(blurring_page_stwb_enable_cb, FALSE);
            gtk_widget_set_sensitive(blurring_page_bgb_enable_cb, FALSE);
            gtk_widget_set_sensitive(blurring_page_fbs_enable_cb, FALSE);
            gtk_widget_set_sensitive(blurring_page_bm, FALSE);
            gtk_widget_set_sensitive(blurring_page_convkern, FALSE);
            gtk_widget_set_sensitive(blurring_page_ccbkern, FALSE);
            gtk_widget_set_sensitive(blurring_page_bsize, FALSE);
            gtk_widget_set_sensitive(blurring_page_exclude_edit, FALSE);
            gtk_widget_set_sensitive(blurring_page_deviation, FALSE);
        }
    }
}

void blurring_page_cb_checked(GtkWidget *widget, gpointer window)
{
    blurring_page_cb_checked_actual();
}

void create_blurring_page()
{
    char *blurring_method = read_config_str_value("blur-method", "none");
    blurring_page_label = gtk_label_new(_("Blurring"));

    p_blurring = 0;
    // BOX
    blurring_page_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_bottom(blurring_page_box, 5);
    gtk_widget_set_margin_top(blurring_page_box, 5);
    gtk_widget_set_margin_start(blurring_page_box, 5);
    gtk_widget_set_margin_end(blurring_page_box, 5);

    // GRID
    blurring_page_grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(blurring_page_grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(blurring_page_grid), 5);

    // CHECKBOXES
    blurring_page_bm_enable_cb = gtk_check_button_new_with_label(_("Enable window background blurring"));
    g_signal_connect(blurring_page_bm_enable_cb, "clicked", G_CALLBACK(blurring_page_cb_checked), (gpointer)window);
    blurring_page_stwb_enable_cb = gtk_check_button_new_with_label(_("Enable semi-transparent window background blurring"));
    blurring_page_bgb_enable_cb = gtk_check_button_new_with_label(_("Enable window background blurring when the frame is not opaque"));
    blurring_page_fbs_enable_cb = gtk_check_button_new_with_label(_("Use a fixed blurring strength"));

    if (strcmp(blurring_method, "none") != 0)
    {
        blurring_enabled = 1;
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(blurring_page_bm_enable_cb), TRUE);
    }
    if (read_config_bool_value("blur-background") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(blurring_page_stwb_enable_cb), TRUE);
    }
    if (read_config_bool_value("blur-background-frame") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(blurring_page_bgb_enable_cb), TRUE);
    }
    if (read_config_bool_value("blur-background-fixed") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(blurring_page_fbs_enable_cb), TRUE);
    }

    // BLURRING METHOD
    blurring_page_bm_label = gtk_label_new(_("Blurring method"));
    gtk_widget_set_margin_start(blurring_page_bm_label, 5);
    gtk_label_set_xalign(GTK_LABEL(blurring_page_bm_label), 0.0);

    blurring_page_bm = gtk_combo_box_text_new();
    for (int i = 0; i < G_N_ELEMENTS(blurring_page_pm_friendlynames); i++)
    {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(blurring_page_bm), _(blurring_page_pm_friendlynames[i]));
    }

    if (blurring_enabled == 1)
    {
        for (int i = 0; i < G_N_ELEMENTS(blurring_page_pm_actualnames); i++)
        {
            if (strcmp(blurring_page_pm_actualnames[i], blurring_method) == 0)
            {
                gtk_combo_box_set_active(GTK_COMBO_BOX(blurring_page_bm), i);
            }
        }
    }
    else
    {
        gtk_combo_box_set_active(GTK_COMBO_BOX(blurring_page_bm), 0);
    }

    gtk_widget_set_hexpand(blurring_page_bm, TRUE);
    gtk_widget_set_margin_start(blurring_page_bm, 100);
    g_signal_connect(blurring_page_bm, "changed", G_CALLBACK(blurring_bmethod_onchanged), NULL);
    gtk_grid_attach(GTK_GRID(blurring_page_grid), blurring_page_bm_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(blurring_page_grid), blurring_page_bm, 1, 0, 1, 1);

    // CONVOLUTION BLURRING KERNEL
    blurring_page_convkern_label = gtk_label_new(_("Convolution blurring kernel"));
    gtk_widget_set_margin_start(blurring_page_convkern_label, 5);
    gtk_label_set_xalign(GTK_LABEL(blurring_page_convkern_label), 0.0);

    blurring_page_convkern = gtk_combo_box_text_new();
    for (int i = 0; i < G_N_ELEMENTS(blurring_page_ck_friendlynames); i++)
    {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(blurring_page_convkern), blurring_page_ck_friendlynames[i]);
    }
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(blurring_page_convkern), _("Custom"));

    char *blurring_kernel = read_config_str_value("blur-kern", "3x3box");

    if (strcmp("", blurring_kernel) == 0)
    {
        is_a_preset_kernel = 2;
        gtk_combo_box_set_active(GTK_COMBO_BOX(blurring_page_convkern), 0);
    }
    else
    {
        for (int i = 0; i < G_N_ELEMENTS(blurring_page_ck_actualnames); i++)
        {
            if (strcmp(blurring_page_ck_actualnames[i], blurring_kernel) == 0)
            {
                is_a_preset_kernel = 1;
                gtk_combo_box_set_active(GTK_COMBO_BOX(blurring_page_convkern), i - 1);
            }
        }
    }

    if ((blurring_enabled == 1) && (gtk_combo_box_get_active(GTK_COMBO_BOX(blurring_page_bm)) == 2))
    {
        if (is_a_preset_kernel == 0)
        {
            gtk_combo_box_set_active(GTK_COMBO_BOX(blurring_page_convkern), 7);
        }
    }
    else
    {
        gtk_widget_set_sensitive(blurring_page_convkern, FALSE);
    }

    g_signal_connect(blurring_page_convkern, "changed", G_CALLBACK(blurring_ckernel_onchanged), NULL);
    gtk_widget_set_hexpand(blurring_page_convkern, TRUE);
    gtk_widget_set_margin_start(blurring_page_convkern, 100);
    gtk_grid_attach(GTK_GRID(blurring_page_grid), blurring_page_convkern_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(blurring_page_grid), blurring_page_convkern, 1, 1, 1, 1);

    // CUSTOM KERNEL
    blurring_page_ccbkern_label = gtk_label_new(_("Custom convolution blurring kernel"));
    gtk_widget_set_margin_start(blurring_page_ccbkern_label, 5);
    gtk_label_set_xalign(GTK_LABEL(blurring_page_ccbkern_label), 0.0);

    blurring_page_ccbkern = gtk_entry_new();
    gtk_widget_set_hexpand(blurring_page_ccbkern, TRUE);
    gtk_widget_set_margin_start(blurring_page_ccbkern, 100);

    gtk_grid_attach(GTK_GRID(blurring_page_grid), blurring_page_ccbkern_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(blurring_page_grid), blurring_page_ccbkern, 1, 2, 1, 1);

    gtk_widget_set_sensitive(blurring_page_ccbkern, FALSE);
    if (is_a_preset_kernel == 0)
    {
        gtk_entry_set_text(GTK_ENTRY(blurring_page_ccbkern), blurring_kernel);
        gtk_widget_set_sensitive(blurring_page_ccbkern, TRUE);
    }

    // BLURRING SIZE
    blurring_page_bsize_label = gtk_label_new(_("Size"));
    gtk_widget_set_margin_start(blurring_page_bsize_label, 5);
    gtk_label_set_xalign(GTK_LABEL(blurring_page_bsize_label), 0.0);

    blurring_page_bsize_adj = gtk_adjustment_new(0, 0, 100000, 1, 100.0, 0.0);
    blurring_page_bsize = gtk_spin_button_new(blurring_page_bsize_adj, 1, 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(blurring_page_bsize), (double)read_config_int_value("blur-size", 12));
    gtk_widget_set_hexpand(blurring_page_bsize, TRUE);
    gtk_widget_set_margin_start(blurring_page_bsize, 100);

    gtk_grid_attach(GTK_GRID(blurring_page_grid), blurring_page_bsize_label, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(blurring_page_grid), blurring_page_bsize, 1, 3, 1, 1);

    // BLURRING DEV
    blurring_page_deviation_label = gtk_label_new(_("Gaussian blurring deviation size"));
    gtk_widget_set_margin_start(blurring_page_deviation_label, 5);
    gtk_label_set_xalign(GTK_LABEL(blurring_page_deviation_label), 0.0);

    blurring_page_deviation_adj = gtk_adjustment_new(0.00000001, 0.00000000, 1.00000000, 0.00010000, 100.0, 0.0);
    blurring_page_deviation = gtk_spin_button_new(blurring_page_deviation_adj, 0.00000001, 8);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(blurring_page_deviation), (double)read_config_float_value("blur-deviation", 0.84089642));
    gtk_widget_set_hexpand(blurring_page_deviation, TRUE);
    gtk_widget_set_margin_start(blurring_page_deviation, 100);

    if (gtk_combo_box_get_active(GTK_COMBO_BOX(blurring_page_bm)) != 0)
    {
        gtk_widget_set_sensitive(blurring_page_deviation, FALSE);
    }

    gtk_grid_attach(GTK_GRID(blurring_page_grid), blurring_page_deviation_label, 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(blurring_page_grid), blurring_page_deviation, 1, 4, 1, 1);

    // EXCLUSION RULES
    blurring_page_exclude_edit_label = gtk_label_new(_("Exclusion rules"));
    gtk_widget_set_margin_start(blurring_page_exclude_edit_label, 5);
    gtk_label_set_xalign(GTK_LABEL(blurring_page_exclude_edit_label), 0.0);

    blurring_page_exclude_edit = gtk_button_new_with_label(_("Edit"));
    gtk_button_set_image(GTK_BUTTON(blurring_page_exclude_edit), gtk_image_new_from_stock("gtk-edit", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_hexpand(blurring_page_exclude_edit, TRUE);
    gtk_widget_set_margin_start(blurring_page_exclude_edit, 100);
    g_signal_connect(G_OBJECT(blurring_page_exclude_edit), "clicked", G_CALLBACK(create_condition_edit_temp), "blur-background-exclude");

    gtk_grid_attach(GTK_GRID(blurring_page_grid), blurring_page_exclude_edit_label, 0, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(blurring_page_grid), blurring_page_exclude_edit, 1, 5, 1, 1);

    gtk_box_pack_start(GTK_BOX(blurring_page_box), blurring_page_bm_enable_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(blurring_page_box), blurring_page_stwb_enable_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(blurring_page_box), blurring_page_bgb_enable_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(blurring_page_box), blurring_page_fbs_enable_cb, TRUE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(blurring_page_box), blurring_page_grid, TRUE, TRUE, 0);

    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), blurring_page_box, blurring_page_label);
    bpcbc_enabled = 1;
    do_blurring_method_control_settings();
    blurring_page_cb_checked_actual();
    p_blurring = 1;
    free(blurring_method);
}

void init_window_type_specific_overrides_list()
{

    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkListStore *store;

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("List Items", renderer, "text", LIST_ITEM, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(window_type_specific_overrides_list), column);

    store = gtk_list_store_new(N_COLUMNS, G_TYPE_STRING);

    gtk_tree_view_set_model(GTK_TREE_VIEW(window_type_specific_overrides_list), GTK_TREE_MODEL(store));

    g_object_unref(store);
}

void add_to_window_type_specific_overrides_list(const char *str)
{

    GtkListStore *store;
    GtkTreeIter iter;

    store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(window_type_specific_overrides_list)));

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, LIST_ITEM, str, -1);
}

void window_type_specific_overrides_list_on_changed(GtkWidget *widget, gpointer data)
{

    GtkTreeIter iter;
    GtkTreeModel *model;
    gtk_widget_set_sensitive(window_type_specific_overrides_edit, FALSE);

    if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(widget), &model, &iter))
    {
        gtk_widget_set_sensitive(window_type_specific_overrides_edit, TRUE);
    }
}

void opacity_frame_cb_checked(GtkWidget *widget, gpointer window)
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
    {
        gtk_widget_set_sensitive(opacity_frame_s, TRUE);
    }
    else
    {
        gtk_widget_set_sensitive(opacity_frame_s, FALSE);
    }
}

void save_window_type_specific_overrides_edit()
{
    GtkTreeIter iter;
    GtkTreeModel *model;
    char *value;
    int cval = 0;

    gtk_tree_selection_get_selected(gtk_tree_view_get_selection(GTK_TREE_VIEW(window_type_specific_overrides_list)), &model, &iter);
    gtk_tree_model_get(model, &iter, LIST_ITEM, &value, -1);

    for (int i = 0; i < G_N_ELEMENTS(window_type_specific_overrides_types_friendlynames); i++)
    {
        if (strcmp(_(window_type_specific_overrides_types_friendlynames[i]), value) == 0)
        {
            cval = i;
        }
    }

    config_wintype wt;
    init_config();
    open_config_file();

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(fade_frame_no)))
    {
        wt.fade = 2;
    }
    else
    {
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(fade_frame_force_off)))
        {
            wt.fade = 0;
        }
        else
        {
            wt.fade = 1;
        }
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(shadow_frame_no)))
    {
        wt.shadow = 2;
    }
    else
    {
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(shadow_frame_force_off)))
        {
            wt.shadow = 0;
        }
        else
        {
            wt.shadow = 1;
        }
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cshadow_frame_no)))
    {
        wt.clip_shadow_above = 2;
    }
    else
    {
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cshadow_frame_force_off)))
        {
            wt.clip_shadow_above = 0;
        }
        else
        {
            wt.clip_shadow_above = 1;
        }
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(fshadow_frame_no)))
    {
        wt.full_shadow = 2;
    }
    else
    {
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(fshadow_frame_force_off)))
        {
            wt.full_shadow = 0;
        }
        else
        {
            wt.full_shadow = 1;
        }
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ig_frame_no)))
    {
        wt.redir_ignore = 2;
    }
    else
    {
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ig_frame_force_off)))
        {
            wt.redir_ignore = 0;
        }
        else
        {
            wt.redir_ignore = 1;
        }
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ff_frame_no)))
    {
        wt.force_focus = 2;
    }
    else
    {
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ff_frame_force_off)))
        {
            wt.force_focus = 0;
        }
        else
        {
            wt.force_focus = 1;
        }
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(opacity_frame_cb)))
    {
        wt.opacity = gtk_spin_button_get_value(GTK_SPIN_BUTTON(opacity_frame_s));
    }
    else
    {
        wt.opacity = 2;
    }

    write_config_wintypes_value(wt, window_type_specific_overrides_types_actualnames[cval]);

    free(value);

    write_config_file();
    destroy_config();
    gtk_widget_destroy(wtdialog);
}

void create_window_type_specific_overrides_edit(GtkWidget *widget, gpointer data)
{
    init_config();
    open_config_file();
    GtkWidget *content_area;
    GtkWidget *dbox;
    GtkWidget *fade_frame;
    GtkWidget *fade_frame_box;
    GtkWidget *shadow_frame;
    GtkWidget *shadow_frame_box;
    GtkWidget *fshadow_frame;
    GtkWidget *fshadow_frame_box;
    GtkWidget *cshadow_frame;
    GtkWidget *cshadow_frame_box;
    GtkWidget *ig_frame_box;
    GtkWidget *ig_frame;
    GtkWidget *kbtn;
    GtkWidget *hgrid;
    GtkWidget *lgrid;
    GtkWidget *dbbox;
    GtkWidget *ff_frame_box;
    GtkWidget *ff_frame;
    GtkWidget *opacity_frame_box;
    GtkWidget *opacity_frame;
    GtkWidget *gbtn;
    GtkAdjustment *opacity_frame_a;

    GtkTreeIter iter;
    GtkTreeModel *model;
    char *value;
    int cval = 0;

    gtk_tree_selection_get_selected(gtk_tree_view_get_selection(GTK_TREE_VIEW(window_type_specific_overrides_list)), &model, &iter);
    gtk_tree_model_get(model, &iter, LIST_ITEM, &value, -1);

    for (int i = 0; i < G_N_ELEMENTS(window_type_specific_overrides_types_friendlynames); i++)
    {
        if (strcmp(_(window_type_specific_overrides_types_friendlynames[i]), value) == 0)
        {
            cval = i;
        }
    }

    config_wintype wintypeval = read_config_wintypes_value(window_type_specific_overrides_types_actualnames[cval]);

    wtdialog = gtk_dialog_new_with_buttons( _("Override editor"), GTK_WINDOW(window), GTK_DIALOG_MODAL, GTK_STOCK_APPLY, GTK_RESPONSE_ACCEPT, GTK_STOCK_CANCEL, GTK_RESPONSE_REJECT, NULL);	
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(wtdialog));

    dbbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_bottom(dbbox, 5);
    gtk_widget_set_margin_top(dbbox, 5);
    gtk_widget_set_margin_start(dbbox, 5);
    gtk_widget_set_margin_end(dbbox, 5);

    dbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 8);
    gtk_widget_set_margin_bottom(dbox, 5);
    gtk_widget_set_margin_top(dbox, 5);
    gtk_widget_set_margin_start(dbox, 5);
    gtk_widget_set_margin_end(dbox, 5);

    // FADE
    fade_frame = gtk_frame_new(_("Fading"));
    gtk_frame_set_shadow_type(GTK_FRAME(fade_frame), GTK_SHADOW_ETCHED_IN);

    fade_frame_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_bottom(fade_frame_box, 5);
    gtk_widget_set_margin_top(fade_frame_box, 5);
    gtk_widget_set_margin_start(fade_frame_box, 5);
    gtk_widget_set_margin_end(fade_frame_box, 5);
    gtk_container_add(GTK_CONTAINER(fade_frame), fade_frame_box);

    fade_frame_no = gtk_radio_button_new_with_label(NULL, _("Do not override"));
    fade_frame_force_on = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(fade_frame_no)), _("Force enable"));
    fade_frame_force_off = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(fade_frame_no)), _("Force disable"));

    switch (wintypeval.fade)
    {
    case 0:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(fade_frame_force_off), TRUE);
        break;
    case 1:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(fade_frame_force_on), TRUE);
        break;
    case 2:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(fade_frame_no), TRUE);
        break;
    }
    gtk_box_pack_start(GTK_BOX(fade_frame_box), fade_frame_no, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(fade_frame_box), fade_frame_force_on, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(fade_frame_box), fade_frame_force_off, TRUE, TRUE, 0);

    // SHADOWS
    shadow_frame = gtk_frame_new(_("Shadows"));
    gtk_frame_set_shadow_type(GTK_FRAME(shadow_frame), GTK_SHADOW_ETCHED_IN);

    shadow_frame_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_bottom(shadow_frame_box, 5);
    gtk_widget_set_margin_top(shadow_frame_box, 5);
    gtk_widget_set_margin_start(shadow_frame_box, 5);
    gtk_widget_set_margin_end(shadow_frame_box, 5);
    gtk_container_add(GTK_CONTAINER(shadow_frame), shadow_frame_box);

    shadow_frame_no = gtk_radio_button_new_with_label(NULL, _("Do not override"));
    shadow_frame_force_on = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(shadow_frame_no)), _("Force enable"));
    shadow_frame_force_off = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(shadow_frame_no)), _("Force disable"));
    switch (wintypeval.shadow)
    {
    case 0:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(shadow_frame_force_off), TRUE);
        break;
    case 1:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(shadow_frame_force_on), TRUE);
        break;
    case 2:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(shadow_frame_no), TRUE);
        break;
    }
    gtk_box_pack_start(GTK_BOX(shadow_frame_box), shadow_frame_no, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(shadow_frame_box), shadow_frame_force_on, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(shadow_frame_box), shadow_frame_force_off, TRUE, TRUE, 0);

    // FULL SHADOWS
    fshadow_frame = gtk_frame_new(_("Full shadow drawing"));
    gtk_frame_set_shadow_type(GTK_FRAME(fshadow_frame), GTK_SHADOW_ETCHED_IN);

    fshadow_frame_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_bottom(fshadow_frame_box, 5);
    gtk_widget_set_margin_top(fshadow_frame_box, 5);
    gtk_widget_set_margin_start(fshadow_frame_box, 5);
    gtk_widget_set_margin_end(fshadow_frame_box, 5);
    gtk_container_add(GTK_CONTAINER(fshadow_frame), fshadow_frame_box);

    fshadow_frame_no = gtk_radio_button_new_with_label(NULL, _("Do not override"));
    fshadow_frame_force_on = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(fshadow_frame_no)), _("Force enable"));
    fshadow_frame_force_off = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(fshadow_frame_no)), _("Force disable"));
    switch (wintypeval.full_shadow)
    {
    case 0:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(fshadow_frame_force_off), TRUE);
        break;
    case 1:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(fshadow_frame_force_on), TRUE);
        break;
    case 2:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(fshadow_frame_no), TRUE);
        break;
    }
    gtk_box_pack_start(GTK_BOX(fshadow_frame_box), fshadow_frame_no, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(fshadow_frame_box), fshadow_frame_force_on, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(fshadow_frame_box), fshadow_frame_force_off, TRUE, TRUE, 0);

    // CLIP SHADOWS
    cshadow_frame = gtk_frame_new(_("Shadow clipping"));
    gtk_frame_set_shadow_type(GTK_FRAME(cshadow_frame), GTK_SHADOW_ETCHED_IN);

    cshadow_frame_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_bottom(cshadow_frame_box, 5);
    gtk_widget_set_margin_top(cshadow_frame_box, 5);
    gtk_widget_set_margin_start(cshadow_frame_box, 5);
    gtk_widget_set_margin_end(cshadow_frame_box, 5);
    gtk_container_add(GTK_CONTAINER(cshadow_frame), cshadow_frame_box);

    cshadow_frame_no = gtk_radio_button_new_with_label(NULL, _("Do not override"));
    cshadow_frame_force_on = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(cshadow_frame_no)), _("Force enable"));
    cshadow_frame_force_off = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(cshadow_frame_no)), _("Force disable"));
    switch (wintypeval.clip_shadow_above)
    {
    case 0:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cshadow_frame_force_off), TRUE);
        break;
    case 1:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cshadow_frame_force_on), TRUE);
        break;
    case 2:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cshadow_frame_no), TRUE);
        break;
    }
    gtk_box_pack_start(GTK_BOX(cshadow_frame_box), cshadow_frame_no, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(cshadow_frame_box), cshadow_frame_force_on, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(cshadow_frame_box), cshadow_frame_force_off, TRUE, TRUE, 0);

    // IGNORE REDIRECT
    ig_frame = gtk_frame_new(_("Ignore redirects"));
    gtk_frame_set_shadow_type(GTK_FRAME(ig_frame), GTK_SHADOW_ETCHED_IN);

    ig_frame_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_bottom(ig_frame_box, 5);
    gtk_widget_set_margin_top(ig_frame_box, 5);
    gtk_widget_set_margin_start(ig_frame_box, 5);
    gtk_widget_set_margin_end(ig_frame_box, 5);
    gtk_container_add(GTK_CONTAINER(ig_frame), ig_frame_box);

    ig_frame_no = gtk_radio_button_new_with_label(NULL, _("Do not override"));
    ig_frame_force_on = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(ig_frame_no)), _("Force enable"));
    ig_frame_force_off = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(ig_frame_no)), _("Force disable"));
    switch (wintypeval.redir_ignore)
    {
    case 0:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ig_frame_force_off), TRUE);
        break;
    case 1:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ig_frame_force_on), TRUE);
        break;
    case 2:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ig_frame_no), TRUE);
        break;
    }
    gtk_box_pack_start(GTK_BOX(ig_frame_box), ig_frame_no, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(ig_frame_box), ig_frame_force_on, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(ig_frame_box), ig_frame_force_off, TRUE, TRUE, 0);

    // Force focus
    ff_frame = gtk_frame_new(_("Force focused state"));
    gtk_frame_set_shadow_type(GTK_FRAME(ff_frame), GTK_SHADOW_ETCHED_IN);

    ff_frame_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_bottom(ff_frame_box, 5);
    gtk_widget_set_margin_top(ff_frame_box, 5);
    gtk_widget_set_margin_start(ff_frame_box, 5);
    gtk_widget_set_margin_end(ff_frame_box, 5);
    gtk_container_add(GTK_CONTAINER(ff_frame), ff_frame_box);

    ff_frame_no = gtk_radio_button_new_with_label(NULL, _("Do not override"));
    ff_frame_force_on = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(ff_frame_no)), _("Force enable"));
    ff_frame_force_off = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(ff_frame_no)), _("Force disable"));
    switch (wintypeval.force_focus)
    {
    case 0:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ff_frame_force_off), TRUE);
        break;
    case 1:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ff_frame_force_on), TRUE);
        break;
    case 2:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ff_frame_no), TRUE);
        break;
    }
    gtk_box_pack_start(GTK_BOX(ff_frame_box), ff_frame_no, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(ff_frame_box), ff_frame_force_on, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(ff_frame_box), ff_frame_force_off, TRUE, TRUE, 0);

    // Opacity
    opacity_frame = gtk_frame_new(_("Opacity"));
    gtk_frame_set_shadow_type(GTK_FRAME(opacity_frame), GTK_SHADOW_ETCHED_IN);

    opacity_frame_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_bottom(opacity_frame_box, 5);
    gtk_widget_set_margin_top(opacity_frame_box, 5);
    gtk_widget_set_margin_start(opacity_frame_box, 5);
    gtk_widget_set_margin_end(opacity_frame_box, 5);
    gtk_container_add(GTK_CONTAINER(opacity_frame), opacity_frame_box);

    opacity_frame_cb = gtk_check_button_new_with_label(_("Override"));
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(opacity_frame_cb), FALSE);
    g_signal_connect(opacity_frame_cb, "clicked", G_CALLBACK(opacity_frame_cb_checked), (gpointer)window);

    opacity_frame_a = gtk_adjustment_new(0.1, 0.1, 1.0, 0.1, 100.0, 0.0);
    opacity_frame_s = gtk_spin_button_new(opacity_frame_a, 0.1, 3);
    gtk_widget_set_hexpand(opacity_frame_s, TRUE);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(opacity_frame_s), 1);
    gtk_widget_set_sensitive(opacity_frame_s, FALSE);

    if (wintypeval.opacity != 2)
    {
        gtk_widget_set_sensitive(opacity_frame_s, TRUE);
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(opacity_frame_cb), TRUE);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(opacity_frame_s), wintypeval.opacity);
    }

    gtk_box_pack_start(GTK_BOX(opacity_frame_box), opacity_frame_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(opacity_frame_box), opacity_frame_s, TRUE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(dbox), fade_frame, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(dbox), shadow_frame, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(dbox), fshadow_frame, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(dbox), cshadow_frame, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(dbox), ig_frame, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(dbox), ff_frame, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(dbox), opacity_frame, TRUE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(dbbox), dbox, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(content_area), dbbox);
    gtk_widget_show_all(wtdialog);
	gint result = gtk_dialog_run(GTK_DIALOG(wtdialog));
    if (result == GTK_RESPONSE_ACCEPT) {
		save_window_type_specific_overrides_edit();
	}
    destroy_config();
}


void create_window_type_specific_overrides_page()
{
    window_type_specific_overrides_label = gtk_label_new(_("Overrides"));

    // BOX
    window_type_specific_overrides_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_bottom(window_type_specific_overrides_box, 5);
    gtk_widget_set_margin_top(window_type_specific_overrides_box, 5);
    gtk_widget_set_margin_start(window_type_specific_overrides_box, 5);
    gtk_widget_set_margin_end(window_type_specific_overrides_box, 5);

    // LIST
    window_type_specific_overrides_list_label = gtk_label_new(_("Window types"));
    gtk_widget_set_margin_start(window_type_specific_overrides_list_label, 5);
    gtk_label_set_xalign(GTK_LABEL(window_type_specific_overrides_list_label), 0.0);

    window_type_specific_overrides_list = gtk_tree_view_new();
    gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(window_type_specific_overrides_list), FALSE);
    init_window_type_specific_overrides_list();
    for (int i = 0; i < G_N_ELEMENTS(window_type_specific_overrides_types_friendlynames); i++)
    {
        add_to_window_type_specific_overrides_list(_(window_type_specific_overrides_types_friendlynames[i]));
    }
    g_signal_connect(gtk_tree_view_get_selection(GTK_TREE_VIEW(window_type_specific_overrides_list)), "changed", G_CALLBACK(window_type_specific_overrides_list_on_changed), (gpointer)window);

    // EDIT BUTTON
    window_type_specific_overrides_edit = gtk_button_new_with_label(_("Edit"));
    gtk_button_set_image(GTK_BUTTON(window_type_specific_overrides_edit), gtk_image_new_from_stock("gtk-edit", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_hexpand(window_type_specific_overrides_edit, TRUE);
    g_signal_connect(G_OBJECT(window_type_specific_overrides_edit), "clicked", G_CALLBACK(create_window_type_specific_overrides_edit), G_OBJECT(window));
    gtk_widget_set_sensitive(window_type_specific_overrides_edit, FALSE);

    gtk_box_pack_start(GTK_BOX(window_type_specific_overrides_box), window_type_specific_overrides_list_label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(window_type_specific_overrides_box), window_type_specific_overrides_list, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(window_type_specific_overrides_box), window_type_specific_overrides_edit, TRUE, TRUE, 0);

    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), window_type_specific_overrides_box, window_type_specific_overrides_label);
}

void create_rounded_corners_page()
{
    rounded_corners_page_label = gtk_label_new(_("Corners"));

    // BOX
    rounded_corners_page_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_bottom(rounded_corners_page_box, 5);
    gtk_widget_set_margin_top(rounded_corners_page_box, 5);
    gtk_widget_set_margin_start(rounded_corners_page_box, 5);
    gtk_widget_set_margin_end(rounded_corners_page_box, 5);

    // CHECKBOX
    rounded_corners_page_enable_cb = gtk_check_button_new_with_label(_("Round the corners of windows"));
    g_signal_connect(rounded_corners_page_enable_cb, "clicked", G_CALLBACK(rounded_corners_page_cb_checked), (gpointer)window);

    // GRID
    rounded_corners_page_grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(rounded_corners_page_grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(rounded_corners_page_grid), 5);

    // RADIUS
    rounded_corners_page_radius_label = gtk_label_new(_("Corner radius"));
    gtk_widget_set_margin_start(rounded_corners_page_radius_label, 5);
    gtk_label_set_xalign(GTK_LABEL(rounded_corners_page_radius_label), 0.0);

    rounded_corners_page_radius_adj = gtk_adjustment_new(0, 0, 1000000, 1, 100.0, 0.0);
    rounded_corners_page_radius_spinner = gtk_spin_button_new(rounded_corners_page_radius_adj, 1, 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(rounded_corners_page_radius_spinner), (double)read_config_int_value("corner-radius", 0));
    gtk_widget_set_hexpand(rounded_corners_page_radius_spinner, TRUE);
    gtk_widget_set_margin_start(rounded_corners_page_radius_spinner, 100);

    gtk_grid_attach(GTK_GRID(rounded_corners_page_grid), rounded_corners_page_radius_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(rounded_corners_page_grid), rounded_corners_page_radius_spinner, 1, 0, 1, 1);

    rounded_corners_page_exclude_label = gtk_label_new(_("Exclusion rules"));
    gtk_widget_set_margin_start(rounded_corners_page_exclude_label, 5);
    gtk_label_set_xalign(GTK_LABEL(rounded_corners_page_exclude_label), 0.0);

    rounded_corners_page_exclude_button = gtk_button_new_with_label(_("Edit"));
    gtk_button_set_image(GTK_BUTTON(rounded_corners_page_exclude_button), gtk_image_new_from_stock("gtk-edit", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_hexpand(rounded_corners_page_exclude_button, TRUE);
    gtk_widget_set_margin_start(rounded_corners_page_exclude_button, 100);
    g_signal_connect(G_OBJECT(rounded_corners_page_exclude_button), "clicked", G_CALLBACK(create_condition_edit_temp), "rounded-corners-exclude");

    gtk_grid_attach(GTK_GRID(rounded_corners_page_grid), rounded_corners_page_exclude_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(rounded_corners_page_grid), rounded_corners_page_exclude_button, 1, 1, 1, 1);

    gtk_box_pack_start(GTK_BOX(rounded_corners_page_box), rounded_corners_page_enable_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(rounded_corners_page_box), rounded_corners_page_grid, TRUE, TRUE, 0);

    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), rounded_corners_page_box, rounded_corners_page_label);

    if (read_config_int_value("corner-radius", 0) == 0)
    {
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(rounded_corners_page_radius_spinner), 0);
        gtk_widget_set_sensitive(rounded_corners_page_radius_spinner, FALSE);
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(rounded_corners_page_enable_cb), FALSE);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(rounded_corners_page_radius_spinner), (double)read_config_int_value("corner-radius-cache", 12));
    }
}

void save_rounded_corners_page()
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(rounded_corners_page_enable_cb)))
    {
        write_config_int_value("corner-radius", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(rounded_corners_page_radius_spinner)));
        write_config_int_value("corner-radius-cache", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(rounded_corners_page_radius_spinner)));
    }
    else
    {
        write_config_int_value("corner-radius", 0);
    }
}

void create_opacity_page()
{
    opacity_page_label = gtk_label_new(_("Opacity"));

    // BOX
    opacity_page_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_bottom(opacity_page_box, 5);
    gtk_widget_set_margin_top(opacity_page_box, 5);
    gtk_widget_set_margin_start(opacity_page_box, 5);
    gtk_widget_set_margin_end(opacity_page_box, 5);

    // CHECKBOX CONTROLS
    opacity_page_netwm_cb = gtk_check_button_new_with_label(_("Let windows set their own inactive opacity values"));
    if (read_config_bool_value("inactive-opacity-override") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(opacity_page_netwm_cb), TRUE);
    }

    // GRID
    opacity_page_spinners_grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(opacity_page_spinners_grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(opacity_page_spinners_grid), 5);

    // WINDOW FRAME OPACITY
    opacity_page_fs_label = gtk_label_new(_("Window frame opacity"));
    gtk_widget_set_margin_start(opacity_page_fs_label, 5);
    gtk_label_set_xalign(GTK_LABEL(opacity_page_fs_label), 0.0);

    opacity_page_fsa = gtk_adjustment_new(0.1, 0.1, 1.0, 0.1, 100.0, 0.0);
    opacity_page_frame_spinner = gtk_spin_button_new(opacity_page_fsa, 0.1, 3);
    gtk_widget_set_hexpand(opacity_page_frame_spinner, TRUE);
    gtk_widget_set_margin_start(opacity_page_frame_spinner, 100);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(opacity_page_frame_spinner), (double)read_config_float_value("frame-opacity", 1.0));

    gtk_grid_attach(GTK_GRID(opacity_page_spinners_grid), opacity_page_fs_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(opacity_page_spinners_grid), opacity_page_frame_spinner, 1, 0, 1, 1);

    // INACTIVE WINDOW OPACITY
    opacity_page_is_label = gtk_label_new(_("Inactive window opacity"));
    gtk_widget_set_margin_start(opacity_page_is_label, 5);
    gtk_label_set_xalign(GTK_LABEL(opacity_page_is_label), 0.0);

    opacity_page_isa = gtk_adjustment_new(0.1, 0.1, 1.0, 0.1, 100.0, 0.0);
    opacity_page_inactive_spinner = gtk_spin_button_new(opacity_page_isa, 0.1, 3);
    gtk_widget_set_hexpand(opacity_page_inactive_spinner, TRUE);
    gtk_widget_set_margin_start(opacity_page_inactive_spinner, 100);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(opacity_page_inactive_spinner), (double)read_config_float_value("inactive-opacity", 0.8));

    gtk_grid_attach(GTK_GRID(opacity_page_spinners_grid), opacity_page_is_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(opacity_page_spinners_grid), opacity_page_inactive_spinner, 1, 2, 1, 1);

    // ACTIVE WINDOW OPACITY
    opacity_page_as_label = gtk_label_new(_("Active window opacity"));
    gtk_widget_set_margin_start(opacity_page_as_label, 5);
    gtk_label_set_xalign(GTK_LABEL(opacity_page_as_label), 0.0);

    opacity_page_asa = gtk_adjustment_new(0.0, 0.0, 1.0, 0.1, 100.0, 0.0);
    opacity_page_active_spinner = gtk_spin_button_new(opacity_page_asa, 0.1, 3);
    gtk_widget_set_hexpand(opacity_page_active_spinner, TRUE);
    gtk_widget_set_margin_start(opacity_page_active_spinner, 100);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(opacity_page_active_spinner), (double)read_config_float_value("active-opacity", 1.0));

    gtk_grid_attach(GTK_GRID(opacity_page_spinners_grid), opacity_page_as_label, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(opacity_page_spinners_grid), opacity_page_active_spinner, 1, 3, 1, 1);

    // INACTIVE WINDOW DIMMING
    opacity_page_ids_label = gtk_label_new(_("Inactive window dimming"));
    gtk_widget_set_margin_start(opacity_page_ids_label, 5);
    gtk_label_set_xalign(GTK_LABEL(opacity_page_ids_label), 0.0);

    opacity_page_idsa = gtk_adjustment_new(0.0, 0.0, 1.0, 0.1, 100.0, 0.0);
    opacity_page_inactived_spinner = gtk_spin_button_new(opacity_page_idsa, 0.1, 3);
    gtk_widget_set_hexpand(opacity_page_inactived_spinner, TRUE);
    gtk_widget_set_margin_start(opacity_page_inactived_spinner, 100);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(opacity_page_inactived_spinner), (double)read_config_float_value("inactive-dim", 0.0));

    gtk_grid_attach(GTK_GRID(opacity_page_spinners_grid), opacity_page_ids_label, 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(opacity_page_spinners_grid), opacity_page_inactived_spinner, 1, 4, 1, 1);

    // WINDOW OPACITY RULES
    opacity_page_rules_label = gtk_label_new(_("Opacity rules"));
    gtk_widget_set_margin_start(opacity_page_rules_label, 5);
    gtk_label_set_xalign(GTK_LABEL(opacity_page_rules_label), 0.0);

    opacity_page_rules = gtk_button_new_with_label(_("Edit"));
    gtk_button_set_image(GTK_BUTTON(opacity_page_rules), gtk_image_new_from_stock("gtk-edit", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_hexpand(opacity_page_rules, TRUE);
    gtk_widget_set_margin_start(opacity_page_rules, 100);
    g_signal_connect(G_OBJECT(opacity_page_rules), "clicked", G_CALLBACK(create_condition_edit_temp), "opacity-rule");

    gtk_grid_attach(GTK_GRID(opacity_page_spinners_grid), opacity_page_rules_label, 0, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(opacity_page_spinners_grid), opacity_page_rules, 1, 5, 1, 1);

    // BOX PACKING
    gtk_box_pack_start(GTK_BOX(opacity_page_box), opacity_page_netwm_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(opacity_page_box), opacity_page_spinners_grid, TRUE, TRUE, 0);

    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), opacity_page_box, opacity_page_label);
}

void save_opacity_page()
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(opacity_page_netwm_cb)) == TRUE)
    {
        write_config_bool_value("inactive-opacity-override", 1);
    }
    else
    {
        write_config_bool_value("inactive-opacity-override", 0);
    }
    write_config_float_value("frame-opacity", gtk_spin_button_get_value(GTK_SPIN_BUTTON(opacity_page_frame_spinner)));
    write_config_float_value("inactive-opacity", gtk_spin_button_get_value(GTK_SPIN_BUTTON(opacity_page_inactive_spinner)));
    write_config_float_value("active-opacity", gtk_spin_button_get_value(GTK_SPIN_BUTTON(opacity_page_active_spinner)));
    write_config_float_value("inactive-dim", gtk_spin_button_get_value(GTK_SPIN_BUTTON(opacity_page_inactived_spinner)));
}

gboolean shadow_page_ser_dc(GtkWidget *widget, cairo_t *cr, gpointer data)
{
    GtkStyleContext *context = gtk_widget_get_style_context(widget);
    gtk_render_background(context, cr, 0, 0, (int)shadow_ser_preview_w, (int)shadow_ser_preview_h);

    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_rectangle(cr, 0, 0, shadow_ser_preview_w, shadow_ser_preview_h);
    cairo_fill(cr);

    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_rectangle(cr, shadow_ser_preview_gdk.x / shadow_ser_preview_cscale, shadow_ser_preview_gdk.y / shadow_ser_preview_cscale, shadow_ser_preview_gdk.width / shadow_ser_preview_cscale, shadow_ser_preview_gdk.height / shadow_ser_preview_cscale);
    cairo_fill(cr);

    return FALSE;
}

void ser_on_change(GtkWidget *widget, gpointer label)
{
    shadow_ser_preview_se_geo.x = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(shadow_page_shadow_exclude_h));
    shadow_ser_preview_se_geo.y = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(shadow_page_shadow_exclude_x));
    shadow_ser_preview_se_geo.z = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(shadow_page_shadow_exclude_y));

    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(shadow_page_shadow_exclude_pos)))
    {
    case 0:
        shadow_ser_preview_se_geo.sy = 1;
        shadow_ser_preview_se_geo.sz = 1;
        break;
    case 1:
        shadow_ser_preview_se_geo.sy = 0;
        shadow_ser_preview_se_geo.sz = 1;
        break;
    case 2:
        shadow_ser_preview_se_geo.sy = 0;
        shadow_ser_preview_se_geo.sz = 0;
        break;
    case 3:
        shadow_ser_preview_se_geo.sy = 1;
        shadow_ser_preview_se_geo.sz = 0;
        break;
    }
    shadow_ser_preview_gdk = convert_picom_rect_to_normal(shadow_ser_preview_se_geo);
    gtk_widget_queue_draw(shadow_page_shadow_exclude_region_dr);
}

void ser_window_save()
{
    init_config();
    open_config_file();
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ser_cb)) == TRUE)
    {
        save_geometry(shadow_ser_preview_se_geo, "shadow-exclude-reg");
    }
    else
    {
        wipe_config_value("shadow-exclude-reg");
    }
    write_config_file();
    destroy_config();
    gtk_widget_destroy(shadow_page_shadow_exclude_region_window);
}


void ser_cb_clicked(GtkWidget *widget, gpointer data)
{
    gtk_widget_set_sensitive(shadow_page_shadow_exclude_h, FALSE);
    gtk_widget_set_sensitive(shadow_page_shadow_exclude_x, FALSE);
    gtk_widget_set_sensitive(shadow_page_shadow_exclude_y, FALSE);
    gtk_widget_set_sensitive(shadow_page_shadow_exclude_pos, FALSE);

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ser_cb)) == TRUE)
    {
        gtk_widget_set_sensitive(shadow_page_shadow_exclude_h, TRUE);
        gtk_widget_set_sensitive(shadow_page_shadow_exclude_x, TRUE);
        gtk_widget_set_sensitive(shadow_page_shadow_exclude_y, TRUE);
        gtk_widget_set_sensitive(shadow_page_shadow_exclude_pos, TRUE);
    }
}

void create_shadow_page_ser_window(GtkWidget *widget, gpointer data)
{
    GtkWidget *content_area;
    GdkRectangle window_geo;
    int is_enabled = 1;
    // load the geometry information
    init_config();
    open_config_file();
    shadow_ser_preview_se_geo = read_geometry("shadow-exclude-reg");
    if ((shadow_ser_preview_se_geo.x == 0) && (shadow_ser_preview_se_geo.y == 0) && (shadow_ser_preview_se_geo.z == 0) && (shadow_ser_preview_se_geo.sy == 0) && (shadow_ser_preview_se_geo.sz == 0))
    {
        is_enabled = 0;
    }
    shadow_ser_preview_gdk = convert_picom_rect_to_normal(shadow_ser_preview_se_geo);

    // dialog setup
    shadow_page_shadow_exclude_region_window = gtk_dialog_new_with_buttons(_("Shadow cropping region editor"), GTK_WINDOW(window), GTK_DIALOG_MODAL, GTK_STOCK_APPLY, GTK_RESPONSE_ACCEPT, GTK_STOCK_CANCEL, GTK_RESPONSE_REJECT, NULL);	
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(shadow_page_shadow_exclude_region_window));
    
    // box and preview widgets
    GtkWidget *cbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    shadow_page_shadow_exclude_region_dr = gtk_drawing_area_new();

    ser_cb = gtk_check_button_new_with_label(_("Enable"));
    g_signal_connect(ser_cb, "clicked", G_CALLBACK(ser_cb_clicked), (gpointer)window);
    gtk_widget_set_margin_top(ser_cb, 8);
    gtk_widget_set_margin_start(ser_cb, 8);
    gtk_widget_set_margin_end(ser_cb, 8);

    // prepare the variables used by the preview widget
    GdkMonitor *monitor = gdk_display_get_primary_monitor(gdk_display_get_default());
    gdk_monitor_get_geometry(monitor, &window_geo);
    shadow_ser_preview_scale = gdk_monitor_get_scale_factor(monitor);
    shadow_ser_preview_w = window_geo.width / shadow_ser_preview_scale;
    shadow_ser_preview_h = window_geo.height / shadow_ser_preview_scale;
    shadow_ser_preview_cscale = nearbyintf(window_geo.height / 200);

    // setting up the UI settings and callbacks for the preview widget
    gtk_widget_set_size_request(shadow_page_shadow_exclude_region_dr, shadow_ser_preview_w / shadow_ser_preview_cscale, shadow_ser_preview_h / shadow_ser_preview_cscale);
    gtk_widget_set_margin_bottom(shadow_page_shadow_exclude_region_dr, 8);
    gtk_widget_set_margin_top(shadow_page_shadow_exclude_region_dr, 8);
    gtk_widget_set_margin_start(shadow_page_shadow_exclude_region_dr, 8);
    gtk_widget_set_margin_end(shadow_page_shadow_exclude_region_dr, 8);
    g_signal_connect(G_OBJECT(shadow_page_shadow_exclude_region_dr), "draw", G_CALLBACK(shadow_page_ser_dc), NULL);

    // grid for the actual adjustment controls
    shadow_page_shadow_exclude_adj_grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(shadow_page_shadow_exclude_adj_grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(shadow_page_shadow_exclude_adj_grid), 5);

    shadow_page_shadow_exclude_pos_label = gtk_label_new(_("Position"));
    gtk_widget_set_margin_start(shadow_page_shadow_exclude_pos_label, 5);
    gtk_label_set_xalign(GTK_LABEL(shadow_page_shadow_exclude_pos_label), 0.0);

    shadow_page_shadow_exclude_pos = gtk_combo_box_text_new();

    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(shadow_page_shadow_exclude_pos), _("Upper left corner"));

    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(shadow_page_shadow_exclude_pos), _("Upper right corner"));
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(shadow_page_shadow_exclude_pos), _("Lower left corner"));
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(shadow_page_shadow_exclude_pos), _("Lower right corner"));

    int csel;
    if ((shadow_ser_preview_se_geo.sy == 1) && (shadow_ser_preview_se_geo.sz == 1))
    {
        csel = 0;
    }
    if ((shadow_ser_preview_se_geo.sy == 0) && (shadow_ser_preview_se_geo.sz == 1))
    {
        csel = 1;
    }
    if ((shadow_ser_preview_se_geo.sy == 0) && (shadow_ser_preview_se_geo.sz == 0))
    {
        csel = 2;
    }
    if ((shadow_ser_preview_se_geo.sy == 1) && (shadow_ser_preview_se_geo.sz == 0))
    {
        csel = 3;
    }

    gtk_combo_box_set_active(GTK_COMBO_BOX(shadow_page_shadow_exclude_pos), csel);
    g_signal_connect(shadow_page_shadow_exclude_pos, "changed", G_CALLBACK(ser_on_change), NULL);

    gtk_widget_set_hexpand(shadow_page_shadow_exclude_pos, TRUE);
    gtk_widget_set_margin_end(shadow_page_shadow_exclude_pos, 8);
    gtk_widget_set_margin_start(shadow_page_shadow_exclude_pos, 100);
    gtk_grid_attach(GTK_GRID(shadow_page_shadow_exclude_adj_grid), shadow_page_shadow_exclude_pos_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(shadow_page_shadow_exclude_adj_grid), shadow_page_shadow_exclude_pos, 1, 0, 1, 1);

    // height control
    shadow_page_shadow_exclude_h_label = gtk_label_new(_("Height"));
    gtk_widget_set_margin_start(shadow_page_shadow_exclude_h_label, 5);
    gtk_label_set_xalign(GTK_LABEL(shadow_page_shadow_exclude_h_label), 0.0);

    shadow_page_shadow_exclude_h_a = gtk_adjustment_new(1, 0, 99999, 1, 100.0, 0.0);
    shadow_page_shadow_exclude_h = gtk_spin_button_new(shadow_page_shadow_exclude_h_a, 1.0, 0);
    gtk_widget_set_hexpand(shadow_page_shadow_exclude_h, TRUE);
    gtk_widget_set_margin_start(shadow_page_shadow_exclude_h, 100);
    gtk_widget_set_margin_end(shadow_page_shadow_exclude_h, 8);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(shadow_page_shadow_exclude_h), (double)shadow_ser_preview_se_geo.x);
    gtk_grid_attach(GTK_GRID(shadow_page_shadow_exclude_adj_grid), shadow_page_shadow_exclude_h_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(shadow_page_shadow_exclude_adj_grid), shadow_page_shadow_exclude_h, 1, 1, 1, 1);
    g_signal_connect(shadow_page_shadow_exclude_h, "value-changed", G_CALLBACK(ser_on_change), NULL);

    // xoff control
    shadow_page_shadow_exclude_x_label = gtk_label_new(_("X offset"));
    gtk_widget_set_margin_start(shadow_page_shadow_exclude_x_label, 5);
    gtk_label_set_xalign(GTK_LABEL(shadow_page_shadow_exclude_x_label), 0.0);

    shadow_page_shadow_exclude_x_a = gtk_adjustment_new(1, 0, 99999, 1, 100.0, 0.0);
    shadow_page_shadow_exclude_x = gtk_spin_button_new(shadow_page_shadow_exclude_x_a, 1.0, 0);
    gtk_widget_set_hexpand(shadow_page_shadow_exclude_x, TRUE);
    gtk_widget_set_margin_start(shadow_page_shadow_exclude_x, 100);
    gtk_widget_set_margin_end(shadow_page_shadow_exclude_x, 8);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(shadow_page_shadow_exclude_x), shadow_ser_preview_se_geo.y);
    g_signal_connect(shadow_page_shadow_exclude_x, "value-changed", G_CALLBACK(ser_on_change), NULL);

    gtk_grid_attach(GTK_GRID(shadow_page_shadow_exclude_adj_grid), shadow_page_shadow_exclude_x_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(shadow_page_shadow_exclude_adj_grid), shadow_page_shadow_exclude_x, 1, 2, 1, 1);

    // xoff control
    shadow_page_shadow_exclude_y_label = gtk_label_new(_("Y offset"));
    gtk_widget_set_margin_start(shadow_page_shadow_exclude_y_label, 5);
    gtk_label_set_xalign(GTK_LABEL(shadow_page_shadow_exclude_y_label), 0.0);

    shadow_page_shadow_exclude_y_a = gtk_adjustment_new(1, 0, 99999, 1, 100.0, 0.0);

    shadow_page_shadow_exclude_y = gtk_spin_button_new(shadow_page_shadow_exclude_y_a, 1.0, 0);
    gtk_widget_set_hexpand(shadow_page_shadow_exclude_y, TRUE);
    gtk_widget_set_margin_start(shadow_page_shadow_exclude_y, 100);
    gtk_widget_set_margin_end(shadow_page_shadow_exclude_y, 8);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(shadow_page_shadow_exclude_y), shadow_ser_preview_se_geo.z);
    g_signal_connect(shadow_page_shadow_exclude_y, "value-changed", G_CALLBACK(ser_on_change), NULL);

    gtk_grid_attach(GTK_GRID(shadow_page_shadow_exclude_adj_grid), shadow_page_shadow_exclude_y_label, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(shadow_page_shadow_exclude_adj_grid), shadow_page_shadow_exclude_y, 1, 3, 1, 1);

    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ser_cb), TRUE);
    if (is_enabled == 0)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ser_cb), FALSE);
    }

    // box setup
    gtk_box_pack_start(GTK_BOX(cbox), ser_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(cbox), shadow_page_shadow_exclude_region_dr, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(cbox), shadow_page_shadow_exclude_adj_grid, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(content_area), cbox);
	gtk_widget_show_all(shadow_page_shadow_exclude_region_window);
    destroy_config();
	gint dialog_result = gtk_dialog_run(GTK_DIALOG(shadow_page_shadow_exclude_region_window));
	if (dialog_result == GTK_RESPONSE_ACCEPT) {
		ser_window_save();
	}
	gtk_widget_destroy(shadow_page_shadow_exclude_region_window);

}

void create_shadow_page_cb_checked(GtkWidget *widget, gpointer window)
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(shadow_page_enable_shadow_cb)))
    {
        gtk_widget_set_sensitive(shadow_page_enable_xinerama_crop_cb, TRUE);
        gtk_widget_set_sensitive(shadow_page_blur_spinner, TRUE);
        gtk_widget_set_sensitive(shadow_page_leftoffset_spinner, TRUE);
        gtk_widget_set_sensitive(shadow_page_topoffset_spinner, TRUE);
        gtk_widget_set_sensitive(shadow_page_translucency_spinner, TRUE);
        gtk_widget_set_sensitive(shadow_page_shadow_color_button, TRUE);
        gtk_widget_set_sensitive(shadow_page_exclude_button, TRUE);
        gtk_widget_set_sensitive(shadow_page_clip_over_button, TRUE);
        gtk_widget_set_sensitive(shadow_page_shadow_exclude_region_button, TRUE);
    }
    else
    {
        gtk_widget_set_sensitive(shadow_page_enable_xinerama_crop_cb, FALSE);
        gtk_widget_set_sensitive(shadow_page_blur_spinner, FALSE);
        gtk_widget_set_sensitive(shadow_page_leftoffset_spinner, FALSE);
        gtk_widget_set_sensitive(shadow_page_topoffset_spinner, FALSE);
        gtk_widget_set_sensitive(shadow_page_translucency_spinner, FALSE);
        gtk_widget_set_sensitive(shadow_page_shadow_color_button, FALSE);
        gtk_widget_set_sensitive(shadow_page_exclude_button, FALSE);
        gtk_widget_set_sensitive(shadow_page_clip_over_button, FALSE);
        gtk_widget_set_sensitive(shadow_page_shadow_exclude_region_button, FALSE);
    }
}
void create_shadow_page()
{
    shadow_page_label = gtk_label_new(_("Shadow"));

    // BOX
    shadow_page_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_bottom(shadow_page_box, 5);
    gtk_widget_set_margin_top(shadow_page_box, 5);
    gtk_widget_set_margin_start(shadow_page_box, 5);
    gtk_widget_set_margin_end(shadow_page_box, 5);

    // CHECKBOXES
    shadow_page_enable_shadow_cb = gtk_check_button_new_with_label(_("Enable client-side shadows on windows"));
    g_signal_connect(shadow_page_enable_shadow_cb, "clicked", G_CALLBACK(create_shadow_page_cb_checked), (gpointer)window);

    if (read_config_bool_value("shadow") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(shadow_page_enable_shadow_cb), TRUE);
    }
    shadow_page_enable_xinerama_crop_cb = gtk_check_button_new_with_label(_("Crop shadows of maximized windows from extended displays"));
    if ((read_config_bool_value("xinerama-shadow-crop") == 1)  || (read_config_bool_value("crop-shadow-to-monitor") == 1))
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(shadow_page_enable_xinerama_crop_cb), TRUE);
    }

    // GRID
    shadow_page_spinnersandcolor_grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(shadow_page_spinnersandcolor_grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(shadow_page_spinnersandcolor_grid), 5);

    // BLUR RADIUS
    shadow_page_bs_label = gtk_label_new(_("Blur radius"));
    gtk_widget_set_margin_start(shadow_page_bs_label, 5);
    gtk_label_set_xalign(GTK_LABEL(shadow_page_bs_label), 0.0);

    shadow_page_bsa = gtk_adjustment_new(1, 0, 99, 1, 100.0, 0.0);
    shadow_page_blur_spinner = gtk_spin_button_new(shadow_page_bsa, 1.0, 0);
    gtk_widget_set_hexpand(shadow_page_blur_spinner, TRUE);
    gtk_widget_set_margin_start(shadow_page_blur_spinner, 100);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(shadow_page_blur_spinner), (double)read_config_int_value("shadow-radius", 12));

    gtk_grid_attach(GTK_GRID(shadow_page_spinnersandcolor_grid), shadow_page_bs_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(shadow_page_spinnersandcolor_grid), shadow_page_blur_spinner, 1, 0, 1, 1);

    // LEFT OFFSET
    shadow_page_lo_label = gtk_label_new(_("Left offset"));
    gtk_widget_set_margin_start(shadow_page_lo_label, 5);
    gtk_label_set_xalign(GTK_LABEL(shadow_page_lo_label), 0.0);

    shadow_page_losa = gtk_adjustment_new(-99, -99, 99, 1, 100.0, 0.0);
    shadow_page_leftoffset_spinner = gtk_spin_button_new(shadow_page_losa, 1.0, 0);
    gtk_widget_set_hexpand(shadow_page_leftoffset_spinner, TRUE);
    gtk_widget_set_margin_start(shadow_page_leftoffset_spinner, 100);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(shadow_page_leftoffset_spinner), (double)read_config_int_value("shadow-offset-x", -15));

    gtk_grid_attach(GTK_GRID(shadow_page_spinnersandcolor_grid), shadow_page_lo_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(shadow_page_spinnersandcolor_grid), shadow_page_leftoffset_spinner, 1, 1, 1, 1);

    // TOP OFFSET
    shadow_page_to_label = gtk_label_new(_("Top offset"));
    gtk_widget_set_margin_start(shadow_page_to_label, 5);
    gtk_label_set_xalign(GTK_LABEL(shadow_page_to_label), 0.0);

    shadow_page_tosa = gtk_adjustment_new(-99, -99, 99, 1, 100.0, 0.0);
    shadow_page_topoffset_spinner = gtk_spin_button_new(shadow_page_tosa, 1.0, 0);
    gtk_widget_set_hexpand(shadow_page_topoffset_spinner, TRUE);
    gtk_widget_set_margin_start(shadow_page_topoffset_spinner, 100);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(shadow_page_topoffset_spinner), (double)read_config_int_value("shadow-offset-y", -15));

    gtk_grid_attach(GTK_GRID(shadow_page_spinnersandcolor_grid), shadow_page_to_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(shadow_page_spinnersandcolor_grid), shadow_page_topoffset_spinner, 1, 2, 1, 1);

    // TRANSLUCENCY
    shadow_page_ts_label = gtk_label_new(_("Translucency"));
    gtk_widget_set_margin_start(shadow_page_ts_label, 5);
    gtk_label_set_xalign(GTK_LABEL(shadow_page_ts_label), 0.0);

    shadow_page_tsa = gtk_adjustment_new(0.00, 0.00, 1.00, 0.10, 100.0, 0.0);
    shadow_page_translucency_spinner = gtk_spin_button_new(shadow_page_tsa, 0.10, 2);
    gtk_widget_set_hexpand(shadow_page_translucency_spinner, TRUE);
    gtk_widget_set_margin_start(shadow_page_translucency_spinner, 100);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(shadow_page_translucency_spinner), (double)read_config_float_value("shadow-opacity", 0.75));

    gtk_grid_attach(GTK_GRID(shadow_page_spinnersandcolor_grid), shadow_page_ts_label, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(shadow_page_spinnersandcolor_grid), shadow_page_translucency_spinner, 1, 3, 1, 1);

    // COLOR
    if (does_config_value_exist("shadow-color") == 0)
    {
        shadow_color.red = read_config_float_value("shadow-red", 0);
        shadow_color.green = read_config_float_value("shadow-green", 0);
        shadow_color.blue = read_config_float_value("shadow-blue", 0);
    }
    else
    {
        uint sc_ri, sc_gi, sc_bi;
        char *hex_color = read_config_str_value("shadow-color", "#000000");
        sscanf(hex_color, "#%02x%02x%02x", &sc_ri, &sc_gi, &sc_bi);

        shadow_color.red = (double)(sc_ri / 255.0F);
        shadow_color.green = (double)(sc_gi / 255.0F);
        shadow_color.blue = (double)(sc_bi / 255.0F);
        free(hex_color);
    }
    shadow_color.alpha = 1;

    shadow_page_sc_label = gtk_label_new(_("Color"));
    gtk_widget_set_margin_start(shadow_page_sc_label, 5);
    gtk_label_set_xalign(GTK_LABEL(shadow_page_sc_label), 0.0);

    shadow_page_shadow_color_button = gtk_color_button_new_with_rgba(&shadow_color);
    gtk_widget_set_hexpand(shadow_page_shadow_color_button, TRUE);
    gtk_widget_set_margin_start(shadow_page_shadow_color_button, 100);

    gtk_grid_attach(GTK_GRID(shadow_page_spinnersandcolor_grid), shadow_page_sc_label, 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(shadow_page_spinnersandcolor_grid), shadow_page_shadow_color_button, 1, 4, 1, 1);

    // SHADOW EXCLUDE
    shadow_page_exclude_label = gtk_label_new(_("Exclusion rules"));
    gtk_widget_set_margin_start(shadow_page_exclude_label, 5);
    gtk_label_set_xalign(GTK_LABEL(shadow_page_exclude_label), 0.0);

    shadow_page_exclude_button = gtk_button_new_with_label(_("Edit"));
    gtk_button_set_image(GTK_BUTTON(shadow_page_exclude_button), gtk_image_new_from_stock("gtk-edit", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_hexpand(shadow_page_exclude_button, TRUE);
    gtk_widget_set_margin_start(shadow_page_exclude_button, 100);
    g_signal_connect(G_OBJECT(shadow_page_exclude_button), "clicked", G_CALLBACK(create_condition_edit_temp), "shadow-exclude");

    gtk_grid_attach(GTK_GRID(shadow_page_spinnersandcolor_grid), shadow_page_exclude_label, 0, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(shadow_page_spinnersandcolor_grid), shadow_page_exclude_button, 1, 5, 1, 1);

    // SHADOW PAINTING RULES
    shadow_page_clip_over_label = gtk_label_new(_("Clipping rules"));
    gtk_widget_set_margin_start(shadow_page_clip_over_label, 5);
    gtk_label_set_xalign(GTK_LABEL(shadow_page_clip_over_label), 0.0);

    shadow_page_clip_over_button = gtk_button_new_with_label(_("Edit"));
    gtk_button_set_image(GTK_BUTTON(shadow_page_clip_over_button), gtk_image_new_from_stock("gtk-edit", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_hexpand(shadow_page_clip_over_button, TRUE);
    gtk_widget_set_margin_start(shadow_page_clip_over_button, 100);
    g_signal_connect(G_OBJECT(shadow_page_clip_over_button), "clicked", G_CALLBACK(create_condition_edit_temp), "clip-shadow-above");

    gtk_grid_attach(GTK_GRID(shadow_page_spinnersandcolor_grid), shadow_page_clip_over_label, 0, 6, 1, 1);
    gtk_grid_attach(GTK_GRID(shadow_page_spinnersandcolor_grid), shadow_page_clip_over_button, 1, 6, 1, 1);

    // SHADOW CLIP OVER
    shadow_page_shadow_exclude_region_label = gtk_label_new(_("Cropping region"));
    gtk_widget_set_margin_start(shadow_page_shadow_exclude_region_label, 5);
    gtk_label_set_xalign(GTK_LABEL(shadow_page_shadow_exclude_region_label), 0.0);

    shadow_page_shadow_exclude_region_button = gtk_button_new_with_label(_("Edit"));
    gtk_button_set_image(GTK_BUTTON(shadow_page_shadow_exclude_region_button), gtk_image_new_from_stock("gtk-edit", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_hexpand(shadow_page_shadow_exclude_region_button, TRUE);
    gtk_widget_set_margin_start(shadow_page_shadow_exclude_region_button, 100);
    g_signal_connect(G_OBJECT(shadow_page_shadow_exclude_region_button), "clicked", G_CALLBACK(create_shadow_page_ser_window), G_OBJECT(window));

    gtk_grid_attach(GTK_GRID(shadow_page_spinnersandcolor_grid), shadow_page_shadow_exclude_region_label, 0, 7, 1, 1);
    gtk_grid_attach(GTK_GRID(shadow_page_spinnersandcolor_grid), shadow_page_shadow_exclude_region_button, 1, 7, 1, 1);

    // BOX PACKING
    gtk_box_pack_start(GTK_BOX(shadow_page_box), shadow_page_enable_shadow_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(shadow_page_box), shadow_page_enable_xinerama_crop_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(shadow_page_box), shadow_page_spinnersandcolor_grid, TRUE, TRUE, 0);

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(shadow_page_enable_shadow_cb)))
    {
        gtk_widget_set_sensitive(shadow_page_enable_xinerama_crop_cb, TRUE);
        gtk_widget_set_sensitive(shadow_page_blur_spinner, TRUE);
        gtk_widget_set_sensitive(shadow_page_leftoffset_spinner, TRUE);
        gtk_widget_set_sensitive(shadow_page_topoffset_spinner, TRUE);
        gtk_widget_set_sensitive(shadow_page_translucency_spinner, TRUE);
        gtk_widget_set_sensitive(shadow_page_shadow_color_button, TRUE);
        gtk_widget_set_sensitive(shadow_page_exclude_button, TRUE);
        gtk_widget_set_sensitive(shadow_page_clip_over_button, TRUE);
        gtk_widget_set_sensitive(shadow_page_shadow_exclude_region_button, TRUE);
    }
    else
    {
        gtk_widget_set_sensitive(shadow_page_enable_xinerama_crop_cb, FALSE);
        gtk_widget_set_sensitive(shadow_page_blur_spinner, FALSE);
        gtk_widget_set_sensitive(shadow_page_leftoffset_spinner, FALSE);
        gtk_widget_set_sensitive(shadow_page_topoffset_spinner, FALSE);
        gtk_widget_set_sensitive(shadow_page_translucency_spinner, FALSE);
        gtk_widget_set_sensitive(shadow_page_shadow_color_button, FALSE);
        gtk_widget_set_sensitive(shadow_page_exclude_button, FALSE);
        gtk_widget_set_sensitive(shadow_page_clip_over_button, FALSE);
        gtk_widget_set_sensitive(shadow_page_shadow_exclude_region_button, FALSE);
    }
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), shadow_page_box, shadow_page_label);
}

void save_shadow_page()
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(shadow_page_enable_shadow_cb)) == TRUE)
    {
        write_config_bool_value("shadow", 1);
    }
    else
    {
        write_config_bool_value("shadow", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(shadow_page_enable_xinerama_crop_cb)) == TRUE)
    {
        write_config_bool_value("xinerama-shadow-crop", 1);
        write_config_bool_value("crop-shadow-to-monitor", 1);
    }
    else
    {
        write_config_bool_value("xinerama-shadow-crop", 0);
        write_config_bool_value("crop-shadow-to-monitor", 0);
    }

    write_config_int_value("shadow-radius", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(shadow_page_blur_spinner)));
    write_config_int_value("shadow-offset-x", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(shadow_page_leftoffset_spinner)));
    write_config_int_value("shadow-offset-y", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(shadow_page_topoffset_spinner)));
    write_config_float_value("shadow-opacity", gtk_spin_button_get_value(GTK_SPIN_BUTTON(shadow_page_translucency_spinner)));

    gtk_color_button_get_rgba(GTK_COLOR_BUTTON(shadow_page_shadow_color_button), &shadow_color);

    if (does_config_value_exist("shadow-color") == 0)
    {
        write_config_float_value("shadow-red", shadow_color.red);
        write_config_float_value("shadow-blue", shadow_color.blue);
        write_config_float_value("shadow-green", shadow_color.green);
    }
    else
    {
        int sc_r = nearbyintf(shadow_color.red * 255.0F), sc_g = nearbyintf(shadow_color.green * 255.0F), sc_b = nearbyintf(shadow_color.blue * 255.0F);
        char hex_color[17];

        snprintf(hex_color, sizeof hex_color, "#%02x%02x%02x", sc_r, sc_g, sc_b);
        write_config_str_value("shadow-color", hex_color);
    }
}

void save_fade_page()
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(fade_page_enable_fade_cb)) == TRUE)
    {
        write_config_bool_value("fading", 1);
    }
    else
    {
        write_config_bool_value("fading", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(fade_page_avoid_fading_on_oc_cb)) == TRUE)
    {
        write_config_bool_value("no-fading-openclose", 1);
    }
    else
    {
        write_config_bool_value("no-fading-openclose", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(fade_page_avoid_destroyed_argb_cb)) == TRUE)
    {
        write_config_bool_value("no-fading-destroyed-argb", 1);
    }
    else
    {
        write_config_bool_value("no-fading-destroyed-argb", 0);
    }

    write_config_int_value("fade-delta", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(fade_page_delta_spinner)));

    write_config_float_value("fade-in-step", gtk_spin_button_get_value(GTK_SPIN_BUTTON(fade_page_finsteps_spinner)));
    write_config_float_value("fade-out-step", gtk_spin_button_get_value(GTK_SPIN_BUTTON(fade_page_foutsteps_spinner)));
}

void fade_page_cb_checked(GtkWidget *widget, gpointer window)
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(fade_page_enable_fade_cb)))
    {
        gtk_widget_set_sensitive(fade_page_avoid_fading_on_oc_cb, TRUE);
        gtk_widget_set_sensitive(fade_page_avoid_destroyed_argb_cb, TRUE);
        gtk_widget_set_sensitive(fade_page_delta_spinner, TRUE);
        gtk_widget_set_sensitive(fade_page_finsteps_spinner, TRUE);
        gtk_widget_set_sensitive(fade_page_foutsteps_spinner, TRUE);
    }
    else
    {
        gtk_widget_set_sensitive(fade_page_avoid_fading_on_oc_cb, FALSE);
        gtk_widget_set_sensitive(fade_page_avoid_destroyed_argb_cb, FALSE);
        gtk_widget_set_sensitive(fade_page_delta_spinner, FALSE);
        gtk_widget_set_sensitive(fade_page_finsteps_spinner, FALSE);
        gtk_widget_set_sensitive(fade_page_foutsteps_spinner, FALSE);
    }
}
void create_fade_page()
{
    fade_page_label = gtk_label_new(_("Fade"));

    // BOX
    fade_page_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_bottom(fade_page_box, 5);
    gtk_widget_set_margin_top(fade_page_box, 5);
    gtk_widget_set_margin_start(fade_page_box, 5);
    gtk_widget_set_margin_end(fade_page_box, 5);

    // CHECKBOXES
    fade_page_enable_fade_cb = gtk_check_button_new_with_label(_("Fade windows during opacity changes"));
    g_signal_connect(fade_page_enable_fade_cb, "clicked", G_CALLBACK(fade_page_cb_checked), (gpointer)window);
    fade_page_avoid_fading_on_oc_cb = gtk_check_button_new_with_label(_("Avoid fading windows in/out when opening/closing"));
    if (read_config_bool_value("no-fading-openclose") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(fade_page_avoid_fading_on_oc_cb), TRUE);
    }
    fade_page_avoid_destroyed_argb_cb = gtk_check_button_new_with_label(_("Avoid fading destroyed ARGB windows in/out (workaround)"));
    if (read_config_bool_value("no-fading-destroyed-argb") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(fade_page_avoid_destroyed_argb_cb), TRUE);
    }

    // GRID
    fade_page_spinners_grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(fade_page_spinners_grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(fade_page_spinners_grid), 5);

    // DELTA
    fade_page_delta_label = gtk_label_new(_("Milliseconds between steps"));
    gtk_widget_set_margin_start(fade_page_delta_label, 5);
    gtk_label_set_xalign(GTK_LABEL(fade_page_delta_label), 0.0);

    fade_page_delta_adj = gtk_adjustment_new(1, 0, 1000000, 1, 100.0, 0.0);
    fade_page_delta_spinner = gtk_spin_button_new(fade_page_delta_adj, 1, 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(fade_page_delta_spinner), (double)read_config_int_value("fade-delta", 10));
    gtk_widget_set_hexpand(fade_page_delta_spinner, TRUE);
    gtk_widget_set_margin_start(fade_page_delta_spinner, 100);

    gtk_grid_attach(GTK_GRID(fade_page_spinners_grid), fade_page_delta_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(fade_page_spinners_grid), fade_page_delta_spinner, 1, 0, 1, 1);

    // FADE IN OPACITY
    fade_page_finsteps_label = gtk_label_new(_("Change amount between steps while fading in"));
    gtk_widget_set_margin_start(fade_page_finsteps_label, 5);
    gtk_label_set_xalign(GTK_LABEL(fade_page_finsteps_label), 0.0);

    fade_page_finsteps_adj = gtk_adjustment_new(0.001, 0.000, 1.000, 0.010, 100.0, 0.0);
    fade_page_finsteps_spinner = gtk_spin_button_new(fade_page_finsteps_adj, 0.010, 3);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(fade_page_finsteps_spinner), (double)read_config_float_value("fade-in-step", 0.028));
    gtk_widget_set_hexpand(fade_page_finsteps_spinner, TRUE);
    gtk_widget_set_margin_start(fade_page_finsteps_spinner, 100);

    gtk_grid_attach(GTK_GRID(fade_page_spinners_grid), fade_page_finsteps_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(fade_page_spinners_grid), fade_page_finsteps_spinner, 1, 1, 1, 1);

    // FADE OUT OPACITY
    fade_page_foutsteps_label = gtk_label_new(_("Change amount between steps while fading out"));
    gtk_widget_set_margin_start(fade_page_foutsteps_label, 5);
    gtk_label_set_xalign(GTK_LABEL(fade_page_foutsteps_label), 0.0);

    fade_page_foutsteps_adj = gtk_adjustment_new(0.001, 0.000, 1.000, 0.010, 100.0, 0.0);
    fade_page_foutsteps_spinner = gtk_spin_button_new(fade_page_foutsteps_adj, 0.010, 3);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(fade_page_foutsteps_spinner), (double)read_config_float_value("fade-out-step", 0.03));
    gtk_widget_set_hexpand(fade_page_foutsteps_spinner, TRUE);
    gtk_widget_set_margin_start(fade_page_foutsteps_spinner, 100);

    gtk_grid_attach(GTK_GRID(fade_page_spinners_grid), fade_page_foutsteps_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(fade_page_spinners_grid), fade_page_foutsteps_spinner, 1, 2, 1, 1);

    fade_page_exclude_label = gtk_label_new(_("Exclusion rules"));
    gtk_widget_set_margin_start(fade_page_exclude_label, 5);
    gtk_label_set_xalign(GTK_LABEL(fade_page_exclude_label), 0.0);

    fade_page_exclude_button = gtk_button_new_with_label(_("Edit"));
    gtk_button_set_image(GTK_BUTTON(fade_page_exclude_button), gtk_image_new_from_stock("gtk-edit", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_hexpand(fade_page_exclude_button, TRUE);
    gtk_widget_set_margin_start(fade_page_exclude_button, 100);
    g_signal_connect(G_OBJECT(fade_page_exclude_button), "clicked", G_CALLBACK(create_condition_edit_temp), "fade-exclude");

    gtk_grid_attach(GTK_GRID(fade_page_spinners_grid), fade_page_exclude_label, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(fade_page_spinners_grid), fade_page_exclude_button, 1, 3, 1, 1);

    // BOX PACKING
    gtk_box_pack_start(GTK_BOX(fade_page_box), fade_page_enable_fade_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(fade_page_box), fade_page_avoid_fading_on_oc_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(fade_page_box), fade_page_avoid_destroyed_argb_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(fade_page_box), fade_page_spinners_grid, TRUE, TRUE, 0);

    if (read_config_bool_value("fading") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(fade_page_enable_fade_cb), TRUE);
        gtk_widget_set_sensitive(fade_page_avoid_fading_on_oc_cb, TRUE);
        gtk_widget_set_sensitive(fade_page_avoid_destroyed_argb_cb, TRUE);
        gtk_widget_set_sensitive(fade_page_delta_spinner, TRUE);
        gtk_widget_set_sensitive(fade_page_finsteps_spinner, TRUE);
        gtk_widget_set_sensitive(fade_page_foutsteps_spinner, TRUE);
    }
    else
    {
        gtk_widget_set_sensitive(fade_page_avoid_fading_on_oc_cb, FALSE);
        gtk_widget_set_sensitive(fade_page_avoid_destroyed_argb_cb, FALSE);
        gtk_widget_set_sensitive(fade_page_delta_spinner, FALSE);
        gtk_widget_set_sensitive(fade_page_finsteps_spinner, FALSE);
        gtk_widget_set_sensitive(fade_page_foutsteps_spinner, FALSE);
    }

    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), fade_page_box, fade_page_label);
}

void toggle_win_misc_page(int value)
{
    if (value == 0)
    {
        gtk_widget_hide(misc_page_dbus_cb);
        gtk_widget_hide(misc_page_daemon_cb);
        gtk_widget_hide(misc_page_xerr_cb);
        gtk_widget_hide(misc_page_logfile_cb);
        gtk_widget_hide(misc_page_pidfile_cb);
        gtk_widget_hide(misc_page_grid);
    }
    else
    {
        gtk_widget_show(misc_page_dbus_cb);
        gtk_widget_show(misc_page_daemon_cb);
        gtk_widget_show(misc_page_xerr_cb);
        gtk_widget_show(misc_page_logfile_cb);
        gtk_widget_show(misc_page_pidfile_cb);
        gtk_widget_show(misc_page_grid);
    }
}

void toggle_rendering_options_page(int value)
{
    if (value == 0)
    {
        gtk_widget_hide(rendering_options_page_grid);
        gtk_widget_hide(rendering_options_page_vsync_cb);
        gtk_widget_hide(rendering_options_page_xsync_cb);
        gtk_widget_hide(rendering_options_page_nodamage_cb);
        gtk_widget_hide(rendering_options_page_forceblend_cb);
        gtk_widget_hide(rendering_backend_gl_box);
        gtk_widget_hide(rendering_options_page_tranclip_cb);
    }
    else
    {
        gtk_widget_show(rendering_options_page_tranclip_cb);
        gtk_widget_show(rendering_options_page_grid);
        gtk_widget_show(rendering_options_page_vsync_cb);
        gtk_widget_show(rendering_options_page_xsync_cb);
        gtk_widget_show(rendering_options_page_nodamage_cb);
        gtk_widget_show(rendering_backend_gl_box);
        gtk_widget_show(rendering_options_page_forceblend_cb);
    }
}

void rendering_options_page_b_on_changed(GtkComboBox *widget, gpointer user_data)
{
    gtk_widget_set_sensitive(rendering_options_page_dither_cb, FALSE);
    gtk_widget_set_sensitive(rendering_options_page_rebindpix_cb, FALSE);
    gtk_widget_set_sensitive(rendering_options_page_stbuf_cb, FALSE);
    gtk_widget_set_sensitive(rendering_backend_gl_shader, FALSE);
    gtk_widget_set_sensitive(rendering_backend_gl_shader_rules_button, FALSE);
    gtk_widget_set_sensitive(rendering_options_page_max_bright, FALSE);
    gtk_widget_set_sensitive(rendering_options_page_tranclip_cb, FALSE);
    gtk_widget_set_sensitive(rendering_tranclip_ex, FALSE);

    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(rendering_options_page_b)))
    {
    case 1:
    case 3:
        gtk_widget_set_sensitive(rendering_options_page_dither_cb, TRUE);
        gtk_widget_set_sensitive(rendering_options_page_rebindpix_cb, TRUE);
        gtk_widget_set_sensitive(rendering_options_page_stbuf_cb, TRUE);
        gtk_widget_set_sensitive(rendering_backend_gl_shader, TRUE);
        gtk_widget_set_sensitive(rendering_backend_gl_shader_rules_button, TRUE);
        gtk_widget_set_sensitive(rendering_options_page_max_bright, TRUE);
        gtk_widget_set_sensitive(rendering_options_page_tranclip_cb, TRUE);
        gtk_widget_set_sensitive(rendering_tranclip_ex, TRUE);
        break;
    }
}

void save_rendering_options_page()
{
    write_config_str_value("backend", rendering_options_page_backend_actualnames[gtk_combo_box_get_active(GTK_COMBO_BOX(rendering_options_page_b))]);

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(rendering_options_page_vsync_cb)) == TRUE)
    {
        write_config_bool_value("vsync", 1);
    }
    else
    {
        write_config_bool_value("vsync", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(rendering_options_page_tranclip_cb)) == TRUE)
    {
        write_config_bool_value("transparent-clipping", 1);
    }
    else
    {
        write_config_bool_value("transparent-clipping", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(rendering_options_page_xsync_cb)) == TRUE)
    {
        write_config_bool_value("xrender-sync-fence", 1);
    }
    else
    {
        write_config_bool_value("xrender-sync-fence", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(rendering_options_page_nodamage_cb)) == TRUE)
    {
        write_config_bool_value("use-damage", 0);
        write_config_bool_value("no-use-damage", 1);
    }
    else
    {
        write_config_bool_value("use-damage", 1);
        write_config_bool_value("no-use-damage", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(rendering_options_page_forceblend_cb)) == TRUE)
    {
        write_config_bool_value("force-win-blend", 1);
    }
    else
    {
        write_config_bool_value("force-win-blend", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(rendering_options_page_dither_cb)) == TRUE)
    {
        write_config_bool_value("dithered-present", 1);
    }
    else
    {
        write_config_bool_value("dithered-present", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(rendering_options_page_stbuf_cb)) == TRUE)
    {
        write_config_bool_value("glx-no-stencil", 0);
    }
    else
    {
        write_config_bool_value("glx-no-stencil", 1);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(rendering_options_page_rebindpix_cb)) == TRUE)
    {
        write_config_bool_value("glx-no-rebind-pixmap", 0);
    }
    else
    {
        write_config_bool_value("glx-no-rebind-pixmap", 1);
    }

    write_config_float_value("max-brightness", gtk_spin_button_get_value(GTK_SPIN_BUTTON(rendering_options_page_max_bright)));
    write_config_str_value("window-shader-fg", gtk_entry_get_text(GTK_ENTRY(rendering_backend_gl_shader)));
}

void create_rendering_options_page()
{
    int enable_gl_options = 0;
    rendering_options_page_label = gtk_label_new(_("Rendering"));

    // BOX
    rendering_options_page_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_bottom(rendering_options_page_box, 5);
    gtk_widget_set_margin_top(rendering_options_page_box, 5);
    gtk_widget_set_margin_start(rendering_options_page_box, 5);
    gtk_widget_set_margin_end(rendering_options_page_box, 5);

    // CHECKBOXES
    rendering_options_page_vsync_cb = gtk_check_button_new_with_label(_("Use vertical synchronization"));
    rendering_options_page_xsync_cb = gtk_check_button_new_with_label(_("Use XSync to sync drawing operations"));
    rendering_options_page_nodamage_cb = gtk_check_button_new_with_label(_("Redraw the screen every time"));
    rendering_options_page_forceblend_cb = gtk_check_button_new_with_label(_("Force all windows to be drawn with blending"));

    if (read_config_bool_value("vsync") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(rendering_options_page_vsync_cb), TRUE);
    }
    if (read_config_bool_value("xrender-sync-fence") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(rendering_options_page_xsync_cb), TRUE);
    }
    int nodamage = 0;
    if ((does_config_value_exist("use-damage") == 1) && (read_config_bool_value("use-damage") == 0))
    {
        nodamage++;
    }
    if ((does_config_value_exist("no-use-damage") == 1) && (read_config_bool_value("no-use-damage") == 1))
    {
        nodamage++;
    }

    if (nodamage != 0)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(rendering_options_page_nodamage_cb), TRUE);
    }
    if (read_config_bool_value("force-win-blend") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(rendering_options_page_forceblend_cb), TRUE);
    }

    // GRID
    rendering_options_page_grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(rendering_options_page_grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(rendering_options_page_grid), 5);

    // BACKEND
    rendering_options_page_b_label = gtk_label_new(_("Backend"));
    gtk_widget_set_margin_start(rendering_options_page_b_label, 5);
    gtk_label_set_xalign(GTK_LABEL(rendering_options_page_b_label), 0.0);

    rendering_options_page_b = gtk_combo_box_text_new();

    for (int i = 0; i < G_N_ELEMENTS(rendering_options_page_backend_friendlynames); i++)
    {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(rendering_options_page_b), rendering_options_page_backend_friendlynames[i]);
    }
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(rendering_options_page_b), _("Hybrid (XRender/OpenGL)"));

    char *backend = read_config_str_value("backend", "xrender");

    if ((strcmp(backend, "glx") == 0) || (strcmp(backend, "xr_glx_hybrid") == 0))
    {
        enable_gl_options = 1;
    }

    gtk_combo_box_set_active(GTK_COMBO_BOX(rendering_options_page_b), 0);
    gtk_widget_set_hexpand(rendering_options_page_b, TRUE);
    gtk_widget_set_margin_start(rendering_options_page_b, 195);
    gtk_grid_attach(GTK_GRID(rendering_options_page_grid), rendering_options_page_b_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(rendering_options_page_grid), rendering_options_page_b, 1, 0, 1, 1);

    // COLOR INVERT
    rendering_backend_color_invert_label = gtk_label_new(_("Color inversion rules"));
    gtk_widget_set_margin_start(rendering_backend_color_invert_label, 5);
    gtk_label_set_xalign(GTK_LABEL(rendering_backend_color_invert_label), 0.0);

    rendering_backend_color_invert = gtk_button_new_with_label(_("Edit"));
    gtk_button_set_image(GTK_BUTTON(rendering_backend_color_invert), gtk_image_new_from_stock("gtk-edit", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_hexpand(rendering_backend_color_invert, TRUE);
    gtk_widget_set_margin_start(rendering_backend_color_invert, 195);
    g_signal_connect(G_OBJECT(rendering_backend_color_invert), "clicked", G_CALLBACK(create_condition_edit_temp), "invert-color-include");

    gtk_grid_attach(GTK_GRID(rendering_options_page_grid), rendering_backend_color_invert_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(rendering_options_page_grid), rendering_backend_color_invert, 1, 1, 1, 1);

    // GL BOX
    rendering_backend_gl_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    // GL BOX CHECKBOXES
    rendering_options_page_dither_cb = gtk_check_button_new_with_label(_("Use a higher color depth during rendering"));
    rendering_options_page_stbuf_cb = gtk_check_button_new_with_label(_("Use stencil buffering"));
    rendering_options_page_rebindpix_cb = gtk_check_button_new_with_label(_("Rebind pixmaps when a window is damaged"));
    rendering_options_page_tranclip_cb = gtk_check_button_new_with_label(_("Make transparent windows clip other windows"));

    if (read_config_bool_value("transparent-clipping") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(rendering_options_page_tranclip_cb), TRUE);
    }

    if (read_config_bool_value("dithered-present") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(rendering_options_page_dither_cb), TRUE);
    }
    if (read_config_bool_value("glx-no-stencil") == 0)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(rendering_options_page_stbuf_cb), TRUE);
    }
    if (read_config_bool_value("glx-no-rebind-pixmap") == 0)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(rendering_options_page_rebindpix_cb), TRUE);
    }

    gtk_box_pack_start(GTK_BOX(rendering_backend_gl_box), rendering_options_page_dither_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(rendering_backend_gl_box), rendering_options_page_stbuf_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(rendering_backend_gl_box), rendering_options_page_rebindpix_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(rendering_backend_gl_box), rendering_options_page_tranclip_cb, TRUE, TRUE, 0);

    // GL BOX GRID
    rendering_backend_gl_grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(rendering_backend_gl_grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(rendering_backend_gl_grid), 5);

    gtk_box_pack_start(GTK_BOX(rendering_backend_gl_box), rendering_backend_gl_grid, TRUE, TRUE, 0);

    // TRAN CLIPPING EXCLUDE
    rendering_tranclip_ex_label = gtk_label_new(_("Transparent window clipping rules"));
    gtk_widget_set_margin_start(rendering_tranclip_ex_label, 5);
    gtk_label_set_xalign(GTK_LABEL(rendering_tranclip_ex_label), 0.0);

    rendering_tranclip_ex = gtk_button_new_with_label(_("Edit"));
    gtk_button_set_image(GTK_BUTTON(rendering_tranclip_ex), gtk_image_new_from_stock("gtk-edit", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_hexpand(rendering_tranclip_ex, TRUE);
    gtk_widget_set_margin_start(rendering_tranclip_ex, 100);
    g_signal_connect(G_OBJECT(rendering_tranclip_ex), "clicked", G_CALLBACK(create_condition_edit_temp), "transparent-clipping-exclude");

    gtk_grid_attach(GTK_GRID(rendering_backend_gl_grid), rendering_tranclip_ex_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(rendering_backend_gl_grid), rendering_tranclip_ex, 1, 0, 1, 1);

    // MAX BRIGHTNESS
    rendering_options_page_max_bright_label = gtk_label_new(_("Max window brightness"));
    gtk_widget_set_margin_start(rendering_options_page_max_bright_label, 5);
    gtk_label_set_xalign(GTK_LABEL(rendering_options_page_max_bright_label), 0.0);

    rendering_options_page_max_bright_adj = gtk_adjustment_new(0.00, 0.00, 1.00, 0.10, 100.0, 0.0);
    rendering_options_page_max_bright = gtk_spin_button_new(rendering_options_page_max_bright_adj, 0.10, 2);
    gtk_widget_set_hexpand(rendering_options_page_max_bright, TRUE);
    gtk_widget_set_margin_start(rendering_options_page_max_bright, 100);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(rendering_options_page_max_bright), (double)read_config_float_value("max-brightness", 1.00));

    gtk_grid_attach(GTK_GRID(rendering_backend_gl_grid), rendering_options_page_max_bright_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(rendering_backend_gl_grid), rendering_options_page_max_bright, 1, 1, 1, 1);

    // GL SHADER
    rendering_backend_gl_shader_label = gtk_label_new(_("Window rendering shader"));
    gtk_widget_set_margin_start(rendering_backend_gl_shader_label, 5);
    gtk_label_set_xalign(GTK_LABEL(rendering_backend_gl_shader_label), 0.0);

    rendering_backend_gl_shader = gtk_entry_new();
    gtk_widget_set_hexpand(rendering_backend_gl_shader, TRUE);
    gtk_widget_set_margin_start(rendering_backend_gl_shader, 100);
    gtk_entry_set_text(GTK_ENTRY(rendering_backend_gl_shader), read_config_str_value("window-shader-fg", ""));
    gtk_grid_attach(GTK_GRID(rendering_backend_gl_grid), rendering_backend_gl_shader_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(rendering_backend_gl_grid), rendering_backend_gl_shader, 1, 2, 1, 1);

    // GL SHADER RULES
    rendering_backend_gl_shader_rules_label = gtk_label_new(_("Per-window shader rules"));
    gtk_widget_set_margin_start(rendering_backend_gl_shader_rules_label, 5);
    gtk_label_set_xalign(GTK_LABEL(rendering_backend_gl_shader_rules_label), 0.0);

    rendering_backend_gl_shader_rules_button = gtk_button_new_with_label(_("Edit"));
    rendering_backend_gl_shader_rules_button = gtk_button_new_with_label(_("Edit"));
    gtk_button_set_image(GTK_BUTTON(rendering_backend_gl_shader_rules_button), gtk_image_new_from_stock("gtk-edit", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_hexpand(rendering_backend_gl_shader_rules_button, TRUE);
    gtk_widget_set_margin_start(rendering_backend_gl_shader_rules_button, 100);
    g_signal_connect(G_OBJECT(rendering_backend_gl_shader_rules_button), "clicked", G_CALLBACK(create_condition_edit_temp), "window-shader-fg-rule");

    gtk_grid_attach(GTK_GRID(rendering_backend_gl_grid), rendering_backend_gl_shader_rules_label, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(rendering_backend_gl_grid), rendering_backend_gl_shader_rules_button, 1, 3, 1, 1);

    gtk_box_pack_start(GTK_BOX(rendering_options_page_box), rendering_options_page_grid, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(rendering_options_page_box), rendering_options_page_vsync_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(rendering_options_page_box), rendering_options_page_xsync_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(rendering_options_page_box), rendering_options_page_nodamage_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(rendering_options_page_box), rendering_options_page_forceblend_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(rendering_options_page_box), rendering_backend_gl_box, TRUE, TRUE, 0);

    if (enable_gl_options == 0)
    {
        gtk_widget_set_sensitive(rendering_options_page_dither_cb, FALSE);
        gtk_widget_set_sensitive(rendering_options_page_rebindpix_cb, FALSE);
        gtk_widget_set_sensitive(rendering_options_page_stbuf_cb, FALSE);
        gtk_widget_set_sensitive(rendering_backend_gl_shader, FALSE);
        gtk_widget_set_sensitive(rendering_options_page_max_bright, FALSE);
        gtk_widget_set_sensitive(rendering_backend_gl_shader_rules_button, FALSE);
        gtk_widget_set_sensitive(rendering_options_page_stbuf_cb, FALSE);
        gtk_widget_set_sensitive(rendering_options_page_tranclip_cb, FALSE);
        gtk_widget_set_sensitive(rendering_tranclip_ex, FALSE);
    }

    for (int i = 0; i < G_N_ELEMENTS(rendering_options_page_backend_actualnames); i++)
    {
        if (strcmp(rendering_options_page_backend_actualnames[i], backend) == 0)
        {
            gtk_combo_box_set_active(GTK_COMBO_BOX(rendering_options_page_b), i);
        }
    }
    free(backend);
    g_signal_connect(GTK_COMBO_BOX(rendering_options_page_b), "changed", G_CALLBACK(rendering_options_page_b_on_changed), NULL);

    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), rendering_options_page_box, rendering_options_page_label);
}

void toggle_win_det_page(int value)
{
    if (value == 0)
    {
        gtk_widget_hide(win_det_window_grouping_frame);
        gtk_widget_hide(win_det_mark_wmwin_focused_cb);
        gtk_widget_hide(win_det_mark_ovredir_focused_cb);
        gtk_widget_hide(win_det_detect_rounded_corners_cb);
        gtk_widget_hide(win_det_detect_client_opacity_cb);
        gtk_widget_hide(win_det_use_ewmh_active_win_cb);
        gtk_widget_hide(win_det_no_ewmh_fullscreen_cb);
        gtk_widget_hide(win_det_unredir_if_possible_cb);
        gtk_widget_hide(win_det_page_grid);
    }
    else
    {
        gtk_widget_show(win_det_window_grouping_frame);
        gtk_widget_show(win_det_mark_wmwin_focused_cb);
        gtk_widget_show(win_det_mark_ovredir_focused_cb);
        gtk_widget_show(win_det_detect_rounded_corners_cb);
        gtk_widget_show(win_det_detect_client_opacity_cb);
        gtk_widget_show(win_det_use_ewmh_active_win_cb);
        gtk_widget_show(win_det_no_ewmh_fullscreen_cb);
        gtk_widget_show(win_det_unredir_if_possible_cb);
        gtk_widget_show(win_det_page_grid);
    }
}

void save_win_det_page()
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(win_det_window_grouping_none)))
    {
        write_config_bool_value("detect-transient", 0);
        write_config_bool_value("detect-client-leader", 0);
    }
    else
    {
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(win_det_window_grouping_detect_transient_win)))
        {
            write_config_bool_value("detect-transient", 1);
            write_config_bool_value("detect-client-leader", 0);
        }
        else
        {
            if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(win_det_window_grouping_detect_client_leader)))
            {
                write_config_bool_value("detect-transient", 0);
                write_config_bool_value("detect-client-leader", 1);
            }
        }
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(win_det_mark_wmwin_focused_cb)) == TRUE)
    {
        write_config_bool_value("mark-wmwin-focused", 1);
    }
    else
    {
        write_config_bool_value("mark-wmwin-focused", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(win_det_mark_ovredir_focused_cb)) == TRUE)
    {
        write_config_bool_value("mark-ovredir-focused", 1);
    }
    else
    {
        write_config_bool_value("mark-ovredir-focused", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(win_det_detect_rounded_corners_cb)) == TRUE)
    {
        write_config_bool_value("detect-rounded-corners", 1);
    }
    else
    {
        write_config_bool_value("detect-rounded-corners", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(win_det_detect_client_opacity_cb)) == TRUE)
    {
        write_config_bool_value("detect-client-opacity", 1);
    }
    else
    {
        write_config_bool_value("detect-client-opacity", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(win_det_use_ewmh_active_win_cb)) == TRUE)
    {
        write_config_bool_value("use-ewmh-active-win", 1);
    }
    else
    {
        write_config_bool_value("use-ewmh-active-win", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(win_det_no_ewmh_fullscreen_cb)) == TRUE)
    {
        write_config_bool_value("no-ewmh-fullscreen", 1);
    }
    else
    {
        write_config_bool_value("no-ewmh-fullscreen", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(win_det_unredir_if_possible_cb)) == TRUE)
    {
        write_config_bool_value("unredir-if-possible", 1);
    }
    else
    {
        write_config_bool_value("unredir-if-possible", 0);
    }

    write_config_int_value("unredir-if-possible-delay", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(win_det_unredir_delay)));
    write_config_int_value("resize-damage", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(win_det_resize)));
}

void create_win_det_page()
{
    win_det_page_label = gtk_label_new(_("Window detection"));

    // BOX
    win_det_page_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_bottom(win_det_page_box, 5);
    gtk_widget_set_margin_top(win_det_page_box, 5);
    gtk_widget_set_margin_start(win_det_page_box, 5);
    gtk_widget_set_margin_end(win_det_page_box, 5);

    // WINDOW GROUPING
    win_det_window_grouping_frame = gtk_frame_new(_("Window grouping"));
    gtk_frame_set_shadow_type(GTK_FRAME(win_det_window_grouping_frame), GTK_SHADOW_ETCHED_IN);

    win_det_window_grouping_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_bottom(win_det_window_grouping_box, 5);
    gtk_widget_set_margin_top(win_det_window_grouping_box, 5);
    gtk_widget_set_margin_start(win_det_window_grouping_box, 5);
    gtk_widget_set_margin_end(win_det_window_grouping_box, 5);
    gtk_container_add(GTK_CONTAINER(win_det_window_grouping_frame), win_det_window_grouping_box);

    win_det_window_grouping_none = gtk_radio_button_new_with_label(NULL, _("Do not group windows"));
    win_det_window_grouping_detect_transient_win = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(win_det_window_grouping_none)), _("Use the 'WM_TRANSIENT_FOR' hint for grouping"));
    win_det_window_grouping_detect_client_leader = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(win_det_window_grouping_none)), _("Use the 'WM_CLIENT_LEADER' hint for grouping"));
    gtk_box_pack_start(GTK_BOX(win_det_window_grouping_box), win_det_window_grouping_none, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win_det_window_grouping_box), win_det_window_grouping_detect_transient_win, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win_det_window_grouping_box), win_det_window_grouping_detect_client_leader, TRUE, TRUE, 0);

    if ((read_config_bool_value("detect-transient") == 0) && (read_config_bool_value("detect-transient") == 0))
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(win_det_window_grouping_none), TRUE);
    }

    if (read_config_bool_value("detect-client-leader") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(win_det_window_grouping_detect_client_leader), TRUE);
    }

    if (read_config_bool_value("detect-transient") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(win_det_window_grouping_detect_transient_win), TRUE);
    }

    // CHECKBOXES
    win_det_mark_wmwin_focused_cb = gtk_check_button_new_with_label(_("Try to detect WM windows and mark them as active"));
    win_det_mark_ovredir_focused_cb = gtk_check_button_new_with_label(_("Mark override-redirect windows that doesn't have a child window with 'WM_STATE' focused"));
    win_det_detect_rounded_corners_cb = gtk_check_button_new_with_label(_("Try to detect windows with rounded corners and don't consider them shaped windows"));
    win_det_detect_client_opacity_cb = gtk_check_button_new_with_label(_("Detect the '_NET_WM_WINDOW_OPACITY' hint on client windows"));
    win_det_use_ewmh_active_win_cb = gtk_check_button_new_with_label(_("Use the '_NET_ACTIVE_WINDOW' hint to determine the currently focused window"));
    win_det_no_ewmh_fullscreen_cb = gtk_check_button_new_with_label(_("Do not use EWMH hints to detect fullscreen windows"));
    win_det_unredir_if_possible_cb = gtk_check_button_new_with_label(_("Unredirect all windows if a full-screen opaque window is detected"));

    if (read_config_bool_value("mark-wmwin-focused") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(win_det_mark_wmwin_focused_cb), TRUE);
    }

    if (read_config_bool_value("mark-ovredir-focused") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(win_det_mark_ovredir_focused_cb), TRUE);
    }

    if (read_config_bool_value("detect-rounded-corners") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(win_det_detect_rounded_corners_cb), TRUE);
    }

    if (read_config_bool_value("detect-client-opacity") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(win_det_detect_client_opacity_cb), TRUE);
    }

    if (read_config_bool_value("use-ewmh-active-win") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(win_det_use_ewmh_active_win_cb), TRUE);
    }

    if (read_config_bool_value("no-ewmh-fullscreen") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(win_det_no_ewmh_fullscreen_cb), TRUE);
    }

    if (read_config_bool_value("unredir-if-possible") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(win_det_unredir_if_possible_cb), TRUE);
    }

    // GRID
    win_det_page_grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(win_det_page_grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(win_det_page_grid), 5);

    // UNREDIR DELAY
    win_det_unredir_delay_label = gtk_label_new(_("Window unredirection delay"));
    gtk_widget_set_margin_start(win_det_unredir_delay_label, 5);
    gtk_label_set_xalign(GTK_LABEL(win_det_unredir_delay_label), 0.0);

    win_det_unredir_delay_adj = gtk_adjustment_new(0, 0, 1000000, 1, 100.0, 0.0);
    win_det_unredir_delay = gtk_spin_button_new(win_det_unredir_delay_adj, 1, 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(win_det_unredir_delay), (double)read_config_int_value("unredir-if-possible-delay", 0));
    gtk_widget_set_hexpand(win_det_unredir_delay, TRUE);
    gtk_widget_set_margin_start(win_det_unredir_delay, 100);

    gtk_grid_attach(GTK_GRID(win_det_page_grid), win_det_unredir_delay_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(win_det_page_grid), win_det_unredir_delay, 1, 0, 1, 1);

    // UNREDIR EXCLUDE
    win_det_unredir_exclude_label = gtk_label_new(_("Window unredirection rules"));
    gtk_widget_set_margin_start(win_det_unredir_exclude_label, 5);
    gtk_label_set_xalign(GTK_LABEL(win_det_unredir_exclude_label), 0.0);

    win_det_unredir_exclude = gtk_button_new_with_label(_("Edit"));
    gtk_button_set_image(GTK_BUTTON(win_det_unredir_exclude), gtk_image_new_from_stock("gtk-edit", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_hexpand(win_det_unredir_exclude, TRUE);
    gtk_widget_set_margin_start(win_det_unredir_exclude, 100);
    g_signal_connect(G_OBJECT(win_det_unredir_exclude), "clicked", G_CALLBACK(create_condition_edit_temp), "unredir-if-possible-exclude");

    gtk_grid_attach(GTK_GRID(win_det_page_grid), win_det_unredir_exclude_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(win_det_page_grid), win_det_unredir_exclude, 1, 1, 1, 1);

    // RESIZE DAMAGE
    win_det_resize_label = gtk_label_new(_("Custom damaged region margins"));
    gtk_widget_set_margin_start(win_det_resize_label, 5);
    gtk_label_set_xalign(GTK_LABEL(win_det_resize_label), 0.0);

    win_det_resize_adj = gtk_adjustment_new(-10000000, -10000000, 1000000, 1, 100.0, 0.0);
    win_det_resize = gtk_spin_button_new(win_det_resize_adj, 1, 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(win_det_resize), (double)read_config_int_value("resize-damage", 0));
    gtk_widget_set_hexpand(win_det_resize, TRUE);
    gtk_widget_set_margin_start(win_det_resize, 100);

    gtk_grid_attach(GTK_GRID(win_det_page_grid), win_det_resize_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(win_det_page_grid), win_det_resize, 1, 2, 1, 1);

    // WINDOW FOCUS CONTROLS
    opacity_page_focus_label = gtk_label_new(_("Windows focus conditions"));
    gtk_widget_set_margin_start(opacity_page_focus_label, 5);
    gtk_label_set_xalign(GTK_LABEL(opacity_page_focus_label), 0.0);

    opacity_page_focus = gtk_button_new_with_label(_("Edit"));
    gtk_button_set_image(GTK_BUTTON(opacity_page_focus), gtk_image_new_from_stock("gtk-edit", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_hexpand(opacity_page_focus, TRUE);
    gtk_widget_set_margin_start(opacity_page_focus, 100);
    g_signal_connect(G_OBJECT(opacity_page_focus), "clicked", G_CALLBACK(create_condition_edit_temp), "focus-exclude");

    gtk_grid_attach(GTK_GRID(win_det_page_grid), opacity_page_focus_label, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(win_det_page_grid), opacity_page_focus, 1, 3, 1, 1);

    gtk_box_pack_start(GTK_BOX(win_det_page_box), win_det_window_grouping_frame, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win_det_page_box), win_det_mark_wmwin_focused_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win_det_page_box), win_det_mark_ovredir_focused_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win_det_page_box), win_det_detect_rounded_corners_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win_det_page_box), win_det_detect_client_opacity_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win_det_page_box), win_det_use_ewmh_active_win_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win_det_page_box), win_det_no_ewmh_fullscreen_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win_det_page_box), win_det_unredir_if_possible_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win_det_page_box), win_det_page_grid, TRUE, TRUE, 0);

    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), win_det_page_box, win_det_page_label);
}

void create_misc_page_pid_checked(GtkWidget *widget, gpointer window)
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(misc_page_pidfile_cb)))
    {
        gtk_widget_set_sensitive(misc_page_pid_file, TRUE);
        gtk_widget_set_sensitive(misc_page_pid_file_browse_button, TRUE);
    }
    else
    {
        gtk_widget_set_sensitive(misc_page_pid_file, FALSE);
        gtk_widget_set_sensitive(misc_page_pid_file_browse_button, FALSE);
    }
}

void create_misc_page_log_checked(GtkWidget *widget, gpointer window)
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(misc_page_logfile_cb)))
    {
        gtk_widget_set_sensitive(misc_page_log_file, TRUE);
        gtk_widget_set_sensitive(misc_page_log_file_browse_button, TRUE);
    }
    else
    {
        gtk_widget_set_sensitive(misc_page_log_file_browse_button, FALSE);
        gtk_widget_set_sensitive(misc_page_log_file, FALSE);
    }
}

void save_misc_page()
{

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(misc_page_dbus_cb)) == TRUE)
    {
        write_config_bool_value("dbus", 1);
    }
    else
    {
        write_config_bool_value("dbus", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(misc_page_daemon_cb)) == TRUE)
    {
        write_config_bool_value("daemon", 1);
    }
    else
    {
        write_config_bool_value("daemon", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(misc_page_xerr_cb)) == TRUE)
    {
        write_config_bool_value("show-all-xerrors", 1);
    }
    else
    {
        write_config_bool_value("show-all-xerrors", 0);
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(misc_page_logfile_cb)) == TRUE)
    {
        write_config_str_value("log-file", gtk_entry_get_text(GTK_ENTRY(misc_page_log_file)));
    }
    else
    {
        wipe_config_value("log-file");
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(misc_page_pidfile_cb)) == TRUE)
    {
        write_config_str_value("write-pid-path", gtk_entry_get_text(GTK_ENTRY(misc_page_pid_file)));
    }
    else
    {
        wipe_config_value("write-pid-path");
    }

    write_config_str_value("log-level", misc_page_level_actualnames[gtk_combo_box_get_active(GTK_COMBO_BOX(misc_page_log_level))]);
}

void toggle_wt_page(int value)
{
    if (value == 0)
    {
        gtk_widget_hide(window_type_specific_overrides_list_label);
        gtk_widget_hide(window_type_specific_overrides_list);
        gtk_widget_hide(window_type_specific_overrides_edit);
    }
    else
    {
        gtk_widget_show(window_type_specific_overrides_list_label);
        gtk_widget_show(window_type_specific_overrides_list);
        gtk_widget_show(window_type_specific_overrides_edit);
    }
}

void show_pid_file_browse_dialog(GtkWidget *widget, gpointer data)
{
    init_config();
    open_config_file();

    char *logfile = read_config_str_value("write-pid-path", "");

    misc_page_pid_file_dialog = gtk_file_chooser_dialog_new(_("Select File"), GTK_WINDOW(window), GTK_FILE_CHOOSER_ACTION_SAVE, _("Cancel"), GTK_RESPONSE_CANCEL, _("Select"), GTK_RESPONSE_ACCEPT, NULL);
    gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(misc_page_pid_file_dialog), TRUE);

    if (strcmp("", logfile) != 0)
    {
        gtk_file_chooser_set_filename(GTK_FILE_CHOOSER(misc_page_pid_file_dialog), logfile);
    }
    else
    {
        gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(misc_page_pid_file_dialog), "picompid.txt");
    }

    gint res = gtk_dialog_run(GTK_DIALOG(misc_page_pid_file_dialog));
    if (res == GTK_RESPONSE_ACCEPT)
    {
        char *filename;
        filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(misc_page_pid_file_dialog));
        gtk_entry_set_text(GTK_ENTRY(misc_page_pid_file), filename);
        free(filename);
    }

    free(logfile);

    gtk_widget_destroy(misc_page_pid_file_dialog);
    destroy_config();
}

void show_log_file_browse_dialog(GtkWidget *widget, gpointer data)
{
    init_config();
    open_config_file();

    char *logfile = read_config_str_value("log-file", "");

    misc_page_log_file_dialog = gtk_file_chooser_dialog_new(_("Select File"), GTK_WINDOW(window), GTK_FILE_CHOOSER_ACTION_SAVE, _("Cancel"), GTK_RESPONSE_CANCEL, _("Select"), GTK_RESPONSE_ACCEPT, NULL);
    gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(misc_page_log_file_dialog), TRUE);

    if (strcmp("", logfile) != 0)
    {
        gtk_file_chooser_set_filename(GTK_FILE_CHOOSER(misc_page_log_file_dialog), logfile);
    }
    else
    {
        gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(misc_page_log_file_dialog), "picom.log");
    }

    gint res = gtk_dialog_run(GTK_DIALOG(misc_page_log_file_dialog));
    if (res == GTK_RESPONSE_ACCEPT)
    {
        char *filename;
        filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(misc_page_log_file_dialog));
        gtk_entry_set_text(GTK_ENTRY(misc_page_log_file), filename);
        free(filename);
    }

    free(logfile);

    gtk_widget_destroy(misc_page_log_file_dialog);
    destroy_config();
}

void create_misc_page()
{
    misc_page_label = gtk_label_new(_("Miscellaneous"));

    // BOX
    misc_page_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_bottom(misc_page_box, 5);
    gtk_widget_set_margin_top(misc_page_box, 5);
    gtk_widget_set_margin_start(misc_page_box, 5);
    gtk_widget_set_margin_end(misc_page_box, 5);

    // CHECKBOX
    misc_page_dbus_cb = gtk_check_button_new_with_label(_("Enable remote control via D-Bus"));
    misc_page_daemon_cb = gtk_check_button_new_with_label(_("Fork to background after initialization"));
    misc_page_xerr_cb = gtk_check_button_new_with_label(_("Show all X errors"));
    misc_page_logfile_cb = gtk_check_button_new_with_label(_("Write logs to a file"));
    misc_page_pidfile_cb = gtk_check_button_new_with_label(_("Write the process ID to a file"));
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(misc_page_logfile_cb), FALSE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(misc_page_pidfile_cb), FALSE);

    if (read_config_bool_value("dbus") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(misc_page_dbus_cb), TRUE);
    }

    if (read_config_bool_value("daemon") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(misc_page_daemon_cb), TRUE);
    }

    if (read_config_bool_value("show-all-xerrors") == 1)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(misc_page_xerr_cb), TRUE);
    }

    char *logfile = read_config_str_value("log-file", "");

    if (strcmp("", logfile) != 0)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(misc_page_logfile_cb), TRUE);
    }

    char *pidfile = read_config_str_value("write-pid-path", "");

    if (strcmp("", pidfile) != 0)
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(misc_page_pidfile_cb), TRUE);
    }

    // GRID
    misc_page_grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(misc_page_grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(misc_page_grid), 5);

    // LEVEL
    misc_page_log_level_label = gtk_label_new(_("Logging level"));
    gtk_widget_set_margin_start(misc_page_log_level_label, 5);
    gtk_label_set_xalign(GTK_LABEL(misc_page_log_level_label), 0.0);

    misc_page_log_level = gtk_combo_box_text_new();

    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(misc_page_log_level), _("Trace"));
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(misc_page_log_level), _("Debug"));
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(misc_page_log_level), _("Info"));
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(misc_page_log_level), _("Warn"));
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(misc_page_log_level), _("Error"));

    char *loglevel = read_config_str_value("log-level", "warn");

    for (int i = 0; i < G_N_ELEMENTS(misc_page_level_actualnames); i++)
    {
        if (strcmp(misc_page_level_actualnames[i], loglevel) == 0)
        {
            gtk_combo_box_set_active(GTK_COMBO_BOX(misc_page_log_level), i);
        }
    }

    gtk_widget_set_hexpand(misc_page_log_level, TRUE);
    gtk_widget_set_margin_start(misc_page_log_level, 100);

    gtk_grid_attach(GTK_GRID(misc_page_grid), misc_page_log_level_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(misc_page_grid), misc_page_log_level, 1, 0, 1, 1);

    // LOG FILE
    misc_page_log_file_label = gtk_label_new(_("Log file"));
    gtk_widget_set_margin_start(misc_page_log_file_label, 5);
    gtk_label_set_xalign(GTK_LABEL(misc_page_log_file_label), 0.0);

    misc_page_log_file_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

    misc_page_log_file = gtk_entry_new();
    gtk_widget_set_hexpand(misc_page_log_file, TRUE);
    gtk_widget_set_margin_start(misc_page_log_file, 100);

    misc_page_log_file_browse_button = gtk_button_new_with_label(_("Browse"));
    gtk_button_set_image(GTK_BUTTON(misc_page_log_file_browse_button), gtk_image_new_from_stock("gtk-open", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_hexpand(misc_page_log_file_browse_button, TRUE);
    g_signal_connect(G_OBJECT(misc_page_log_file_browse_button), "clicked", G_CALLBACK(show_log_file_browse_dialog), G_OBJECT(window));

    gtk_box_pack_start(GTK_BOX(misc_page_log_file_box), misc_page_log_file, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(misc_page_log_file_box), misc_page_log_file_browse_button, TRUE, TRUE, 0);

    gtk_grid_attach(GTK_GRID(misc_page_grid), misc_page_log_file_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(misc_page_grid), misc_page_log_file_box, 1, 1, 1, 1);

    gtk_widget_set_sensitive(misc_page_log_file_browse_button, FALSE);
    gtk_widget_set_sensitive(misc_page_log_file, FALSE);

    if (strcmp("", logfile) != 0)
    {
        gtk_widget_set_sensitive(misc_page_log_file_browse_button, TRUE);
        gtk_widget_set_sensitive(misc_page_log_file, TRUE);
    }

    // PID FILE
    misc_page_pid_file_label = gtk_label_new(_("Process ID file"));
    gtk_widget_set_margin_start(misc_page_pid_file_label, 5);
    gtk_label_set_xalign(GTK_LABEL(misc_page_pid_file_label), 0.0);

    misc_page_pid_file = gtk_entry_new();
    gtk_widget_set_hexpand(misc_page_pid_file, TRUE);
    gtk_widget_set_margin_start(misc_page_pid_file, 100);

    misc_page_pid_file_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

    misc_page_pid_file_browse_button = gtk_button_new_with_label(_("Browse"));
    gtk_button_set_image(GTK_BUTTON(misc_page_pid_file_browse_button), gtk_image_new_from_stock("gtk-open", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_hexpand(misc_page_pid_file_browse_button, TRUE);
    g_signal_connect(G_OBJECT(misc_page_pid_file_browse_button), "clicked", G_CALLBACK(show_pid_file_browse_dialog), G_OBJECT(window));

    gtk_widget_set_sensitive(misc_page_pid_file, FALSE);
    gtk_widget_set_sensitive(misc_page_pid_file_browse_button, FALSE);

    if (strcmp("", pidfile) != 0)
    {
        gtk_widget_set_sensitive(misc_page_pid_file_browse_button, TRUE);
        gtk_widget_set_sensitive(misc_page_pid_file, TRUE);
    }

    gtk_box_pack_start(GTK_BOX(misc_page_pid_file_box), misc_page_pid_file, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(misc_page_pid_file_box), misc_page_pid_file_browse_button, TRUE, TRUE, 0);

    gtk_grid_attach(GTK_GRID(misc_page_grid), misc_page_pid_file_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(misc_page_grid), misc_page_pid_file_box, 1, 2, 1, 1);

    gtk_box_pack_start(GTK_BOX(misc_page_box), misc_page_dbus_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(misc_page_box), misc_page_daemon_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(misc_page_box), misc_page_xerr_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(misc_page_box), misc_page_logfile_cb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(misc_page_box), misc_page_pidfile_cb, TRUE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(misc_page_box), misc_page_grid, TRUE, TRUE, 0);

    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), misc_page_box, misc_page_label);

    g_signal_connect(misc_page_logfile_cb, "clicked", G_CALLBACK(create_misc_page_log_checked), (gpointer)window);
    g_signal_connect(misc_page_pidfile_cb, "clicked", G_CALLBACK(create_misc_page_pid_checked), (gpointer)window);

    free(loglevel);
    free(pidfile);
    free(logfile);
}

void show_about_dialog(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog = gtk_about_dialog_new();
    gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(dialog), "picom-conf-gtk");
    gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), "1.0");
    gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog), "© Jason Contoso");
    gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), _("picom-conf-gtk is a simple graphical tool for configuring picom."));
    gtk_about_dialog_set_logo_icon_name(GTK_ABOUT_DIALOG(dialog), "picom-conf");

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void save_settings(GtkWidget *widget, gpointer data)
{
    init_config();
    open_config_file();
    save_shadow_page();
    save_opacity_page();
    save_fade_page();
    save_rounded_corners_page();
    save_blurring_page();
    save_win_det_page();
    save_rendering_options_page();
    save_misc_page();
    write_config_file();
    destroy_config();
}

void switch_page(GtkNotebook *self, GtkWidget *page, guint page_num, gpointer user_data)
{
    gtk_window_set_resizable(GTK_WINDOW(window), TRUE);
    switch (page_num)
    {
    case 0:
        gtk_widget_hide(opacity_page_spinners_grid);
        gtk_widget_hide(rounded_corners_page_grid);
        gtk_widget_hide(rounded_corners_page_enable_cb);
        toggle_fade_page(0);
        toggle_rendering_options_page(0);
        toggle_shadow_page(1);
        toggle_win_det_page(0);
        toggle_blurring_page(0);
        toggle_win_misc_page(0);
        toggle_wt_page(0);
        break;
    case 1:
        toggle_rendering_options_page(0);
        toggle_fade_page(0);
        toggle_blurring_page(0);
        toggle_win_det_page(0);
        toggle_shadow_page(0);
        toggle_win_misc_page(0);
        gtk_widget_hide(rounded_corners_page_grid);
        gtk_widget_hide(rounded_corners_page_enable_cb);
        gtk_widget_show(opacity_page_spinners_grid);
        toggle_wt_page(0);
        break;
    case 2:
        gtk_widget_hide(opacity_page_spinners_grid);
        gtk_widget_hide(rounded_corners_page_grid);
        gtk_widget_hide(rounded_corners_page_enable_cb);
        toggle_shadow_page(0);
        toggle_win_det_page(0);
        toggle_rendering_options_page(0);
        toggle_fade_page(1);
        toggle_win_misc_page(0);
        toggle_blurring_page(0);
        toggle_wt_page(0);
        break;
    case 3:
        toggle_fade_page(0);
        toggle_win_det_page(0);
        toggle_shadow_page(0);
        toggle_rendering_options_page(0);
        toggle_win_misc_page(0);
        toggle_blurring_page(0);
        gtk_widget_hide(opacity_page_spinners_grid);
        gtk_widget_show(rounded_corners_page_grid);
        gtk_widget_show(rounded_corners_page_enable_cb);
        toggle_wt_page(0);
        break;
    case 4:
        toggle_fade_page(0);
        toggle_win_det_page(0);
        toggle_rendering_options_page(0);
        toggle_shadow_page(0);
        toggle_blurring_page(1);
        toggle_win_misc_page(0);
        gtk_widget_hide(opacity_page_spinners_grid);
        gtk_widget_hide(rounded_corners_page_grid);
        gtk_widget_hide(rounded_corners_page_enable_cb);
        toggle_wt_page(0);
        break;
    case 5:
        toggle_fade_page(0);
        toggle_rendering_options_page(1);
        toggle_shadow_page(0);
        toggle_win_misc_page(0);
        toggle_blurring_page(0);
        toggle_win_det_page(0);
        gtk_widget_hide(opacity_page_spinners_grid);
        gtk_widget_hide(rounded_corners_page_grid);
        gtk_widget_hide(rounded_corners_page_enable_cb);
        toggle_wt_page(0);
        break;
    case 6:
        toggle_fade_page(0);
        toggle_rendering_options_page(0);
        toggle_shadow_page(0);
        toggle_blurring_page(0);
        toggle_win_det_page(1);
        gtk_widget_hide(opacity_page_spinners_grid);
        gtk_widget_hide(rounded_corners_page_grid);
        gtk_widget_hide(rounded_corners_page_enable_cb);
        toggle_win_misc_page(0);
        toggle_wt_page(0);
        break;
    case 7:
        toggle_fade_page(0);
        toggle_rendering_options_page(0);
        toggle_shadow_page(0);
        toggle_blurring_page(0);
        toggle_win_misc_page(1);
        toggle_wt_page(0);
        toggle_win_det_page(0);
        gtk_widget_hide(opacity_page_spinners_grid);
        gtk_widget_hide(rounded_corners_page_grid);
        gtk_widget_hide(rounded_corners_page_enable_cb);
        break;
    case 8:
        toggle_fade_page(0);
        toggle_rendering_options_page(0);
        toggle_shadow_page(0);
        toggle_blurring_page(0);
        toggle_win_misc_page(0);
        toggle_win_det_page(0);
        toggle_wt_page(1);
        gtk_widget_hide(opacity_page_spinners_grid);
        gtk_widget_hide(rounded_corners_page_grid);
        gtk_widget_hide(rounded_corners_page_enable_cb);
        break;
    }

    gtk_window_resize(GTK_WINDOW(window), 2, 2);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
}

void create_window_buttons()
{
    // GRIDS
    bgrid = gtk_grid_new();
    gtk_widget_set_hexpand(bgrid, TRUE);
    bsgrid = gtk_grid_new();
    gtk_grid_attach(GTK_GRID(bgrid), bsgrid, 1, 0, 1, 1);
    gtk_widget_set_hexpand(bsgrid, TRUE);
    gtk_widget_set_halign(bsgrid, GTK_ALIGN_END);

    // ABOUT BUTTON
    abutton = gtk_button_new_with_label(_("About"));
    gtk_button_set_image(GTK_BUTTON(abutton), gtk_image_new_from_stock("gtk-about", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_margin_bottom(abutton, 8);
    gtk_widget_set_margin_start(abutton, 8);
    gtk_widget_set_margin_end(abutton, 8);
    gtk_grid_attach(GTK_GRID(bgrid), abutton, 0, 0, 1, 1);
    g_signal_connect(G_OBJECT(abutton), "clicked", G_CALLBACK(show_about_dialog), G_OBJECT(window));

    // APPLY BUTTON
    sbutton = gtk_button_new_with_label(_("Apply"));
    gtk_button_set_image(GTK_BUTTON(sbutton), gtk_image_new_from_stock("gtk-apply", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_margin_bottom(sbutton, 8);
    gtk_widget_set_margin_end(sbutton, 8);
    gtk_grid_attach(GTK_GRID(bsgrid), sbutton, 0, 0, 1, 1);
    gtk_widget_set_halign(bsgrid, GTK_ALIGN_END);
    g_signal_connect(G_OBJECT(sbutton), "clicked", G_CALLBACK(save_settings), G_OBJECT(window));

    // CANCEL BUTTON
    cbutton = gtk_button_new_with_label(_("Cancel"));
    gtk_button_set_image(GTK_BUTTON(cbutton), gtk_image_new_from_stock("gtk-cancel", GTK_ICON_SIZE_BUTTON));
    gtk_widget_set_margin_bottom(cbutton, 8);
    gtk_widget_set_margin_end(cbutton, 8);
    gtk_grid_attach(GTK_GRID(bsgrid), cbutton, 1, 0, 1, 1);
    g_signal_connect(G_OBJECT(cbutton), "clicked", G_CALLBACK(gtk_main_quit), G_OBJECT(window));
}

void create_window()
{
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), _("Picom Configuration")); 
    gtk_window_set_icon_name(GTK_WINDOW(window), "picom-conf");
	
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    gtk_container_add(GTK_CONTAINER(window), box);

    notebook = gtk_notebook_new();
    gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook), GTK_POS_TOP);
    gtk_widget_set_margin_bottom(notebook, 8);
    gtk_widget_set_margin_top(notebook, 8);
    gtk_widget_set_margin_start(notebook, 8);
    gtk_widget_set_margin_end(notebook, 8);
    //gtk_notebook_set_scrollable(GTK_NOTEBOOK(notebook), TRUE);

    create_shadow_page();
    create_opacity_page();
    create_window_buttons();
    create_fade_page();
    create_rounded_corners_page();
    create_blurring_page();
    create_rendering_options_page();
    create_win_det_page();
    create_misc_page();
    create_window_type_specific_overrides_page();
    gtk_box_pack_start(GTK_BOX(box), notebook, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), bgrid, TRUE, TRUE, 0);

    gtk_widget_show_all(window);

    gtk_widget_hide(opacity_page_spinners_grid);
    toggle_fade_page(0);
    toggle_shadow_page(1);
    toggle_blurring_page(0);
    toggle_win_det_page(0);
    toggle_rendering_options_page(0);
    toggle_win_misc_page(0);
    toggle_wt_page(0);
    gtk_widget_hide(rounded_corners_page_grid);
    gtk_widget_hide(rounded_corners_page_enable_cb);

    gtk_window_resize(GTK_WINDOW(window), 2, 2);
    g_signal_connect(G_OBJECT(notebook), "switch-page", G_CALLBACK(switch_page), G_OBJECT(window));
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    c_config = 1;
}
