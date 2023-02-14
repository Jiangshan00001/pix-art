#ifndef PYINTERFACE_H
#define PYINTERFACE_H

extern "C"{


void* pix_create_interface(char* file_name, int output_wdth, int output_height, int max_palette_size);
void pix_delete_interface(void* inst);
int pix_set_bilateral_params(void* inst, double sig_color, double sig_pos);
int pix_set_laplacin_factor(void* inst, double f);
int pix_set_slic_fact(void * inst, double factor);
int pix_set_saturation(void * inst, double saturation);
int pix_initialize(void* inst);
int pix_save_region_image(void * inst, char* file_name);
int pix_save_superpixel_image(void * inst, char* file_name);
int pix_iterate(void * inst, int is_print, int is_save_dbg_img);
int pix_iterate_all(void * inst, int is_print, int is_save_dbg_img);
int pix_has_converged(void * inst);
int pix_save_output_image(void * inst, char* file_name);
int pix_associate_palette(void *inst);
void pix_save_to_file(void *inst,char *file_name);
}

#endif // PYINTERFACE_H
