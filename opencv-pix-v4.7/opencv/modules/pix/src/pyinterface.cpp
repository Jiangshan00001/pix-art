#include "pyinterface.h"
#include "pix.h"
#include <time.h>
//#include <opencv2/opencv.hpp>
#include "precomp.hpp"
#include "opencv2/imgcodecs.hpp"
//#include "opencl_kernels_imgproc.hpp"
//#include "opencv2/core/utils/filesystem.hpp"

using namespace cv;



namespace cv
{


pix_inst_type pix_create_interface(char *file_name, int output_wdth, int output_height, int max_palette_size)
{
#if 0
    time_t timep;
    time(&timep);
    struct tm *p;
    p = gmtime(&timep);
    //printf("currt:y %d %d\n",p->tm_year, 1+p->tm_mon);
    if((p->tm_mon+1)!=2)return 0;
#endif



    Mat img_input;
    img_input = cv::imread(file_name);
    return (pix_inst_type)(new Pix(img_input, output_wdth, output_height, max_palette_size));
}



void pix_delete_interface(pix_inst_type inst)
{
    delete (Pix*)inst;
}


int pix_set_bilateral_params(pix_inst_type inst, double sig_color, double sig_pos)
{
    Pix * pix = (Pix*)inst;
    pix->SetBilateralParams(sig_color, sig_pos);
    return 0;
}


int pix_set_laplacin_factor(pix_inst_type inst, double f)
{
    Pix * pix = (Pix*)inst;
    pix->set_laplacian_factor(f);
    return 0;
}


int pix_set_slic_fact(pix_inst_type inst, double factor)
{
    Pix * pix = (Pix*)inst;
    pix->setSlicFact(factor);
    return 0;

}


int pix_set_saturation(pix_inst_type inst, double saturation)
{
    Pix * pix = (Pix*)inst;
    pix->SetSaturation(saturation);
    return 0;

}


int pix_initialize(pix_inst_type inst)
{
    Pix * pix = (Pix*)inst;
    pix->Initialize();
    return 0;
}


int pix_save_region_image(pix_inst_type inst, char *file_name)
{
    Pix * pix = (Pix*)inst;
    Mat mat;
    pix->GetRegionImage(mat);
    cv::imwrite(file_name, mat);
    return 0;

}


int pix_save_superpixel_image(pix_inst_type inst, char *file_name)
{
    Pix * pix = (Pix*)inst;
    Mat img;
    pix->GetSuperpixelImage(img);
    cv::imwrite(file_name, img);
    return 0;
}


int pix_iterate(pix_inst_type inst, int is_print, int is_save_dbg_img)
{
    Pix * pix = (Pix*)inst;
    pix->Iterate(is_print, is_save_dbg_img);
    return 0;
}

int pix_iterate_all(pix_inst_type inst, int is_print, int is_save_dbg_img)
{
    Pix * pix = (Pix*)inst;
    pix->Iterate(is_print, is_save_dbg_img);
    while(!pix->hasConverged())
        pix->Iterate(is_print, is_save_dbg_img);
    return 0;
}



int pix_has_converged(pix_inst_type inst)
{
    Pix * pix = (Pix*)inst;
    return pix->hasConverged();
}

int pix_associate_palette(pix_inst_type inst)
{
    Pix * pix = (Pix*)inst;
    pix->AssociatePalette();
    return 0;
}

int pix_save_output_image(pix_inst_type inst, char *file_name)
{
    Pix * pix = (Pix*)inst;
    Mat img;
    pix->GetOutputImage(img);
    cv::imwrite(file_name, img);
    return 0;
}
void pix_save_to_file(pix_inst_type inst,char *file_name)
{
    Pix * pix = (Pix*)inst;
    pix->SaveToFile(file_name);
    return ;
}

}
