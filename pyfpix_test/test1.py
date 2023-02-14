import time
import pyfpix


def to_test():

    # read file set params
    inst = pyfpix.pix_create_interface("test_images/firefox.jpg", 246, 256, 8)
    # inst = lib.pix_create_interface(b"obb1.png", 32, 32, 8)
    pyfpix.pix_set_bilateral_params(inst, 4.5, 0.87)
    pyfpix.pix_set_laplacin_factor(inst, 0.4)
    pyfpix.pix_set_slic_fact(inst, 45.0)
    pyfpix.pix_set_saturation(inst, 1.1)
    pyfpix.pix_initialize(inst)

    # do interate. mode1--iterate once and check
    #              mode2--iterate until finish
    while (not pyfpix.pix_has_converged(inst)):
        # instance, is_print is_save_debug_img
        pyfpix.pix_iterate(inst, 1, 0)
    # lib.pix_iterate_all(inst, 0)

    # associate palette and write the result image
    pyfpix.pix_associate_palette(inst)
    pyfpix.pix_save_output_image(inst, "test_images/firefox_out.bmp")
    pyfpix.pix_save_region_image(inst, "test_images/firefox_region.bmp")
    pyfpix.pix_save_superpixel_image(inst, "test_images/firefox_super.bmp")
    pyfpix.pix_save_to_file(inst, 'test_images/firefox_save.pix')
    # delete the interface
    pyfpix.pix_delete_interface(inst)


if __name__=='__main__':
    t1=time.time()
    to_test()
    #lp = LineProfiler()
    #lp_wrapper = lp(to_test)
    #lp_wrapper()
    #lp.print_stats()
    print('time:', time.time()-t1)
