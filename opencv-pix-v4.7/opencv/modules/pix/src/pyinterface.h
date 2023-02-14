#ifndef PYINTERFACE_H
#define PYINTERFACE_H
#include "opencv2/core.hpp"

namespace cv
{
typedef unsigned long long pix_inst_type;


CV_EXPORTS_W pix_inst_type  pix_create_interface(char* file_name, int output_wdth, int output_height, int max_palette_size);
CV_EXPORTS_W void pix_delete_interface(pix_inst_type  inst);
CV_EXPORTS_W int pix_set_bilateral_params(pix_inst_type  inst, double sig_color, double sig_pos);
CV_EXPORTS_W int pix_set_laplacin_factor(pix_inst_type  inst, double f);
CV_EXPORTS_W int pix_set_slic_fact(pix_inst_type  inst, double factor);
CV_EXPORTS_W int pix_set_saturation(pix_inst_type  inst, double saturation);
CV_EXPORTS_W int pix_initialize(pix_inst_type  inst);
CV_EXPORTS_W int pix_save_region_image(pix_inst_type  inst, char* file_name);
CV_EXPORTS_W int pix_save_superpixel_image(pix_inst_type  inst, char* file_name);
CV_EXPORTS_W int pix_iterate(pix_inst_type  inst, int is_print, int is_save_dbg_img);
CV_EXPORTS_W int pix_iterate_all(pix_inst_type  inst, int is_print, int is_save_dbg_img);
CV_EXPORTS_W int pix_has_converged(pix_inst_type  inst);
CV_EXPORTS_W int pix_save_output_image(pix_inst_type  inst, char* file_name);
CV_EXPORTS_W int pix_associate_palette(pix_inst_type inst);
CV_EXPORTS_W void pix_save_to_file(pix_inst_type inst,char *file_name);

}
#endif // PYINTERFACE_H
