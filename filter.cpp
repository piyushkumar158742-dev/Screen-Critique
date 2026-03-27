#include <emscripten.h>
#include <stdint.h>

extern "C" {

EMSCRIPTEN_KEEPALIVE
void process_image(uint8_t* image_data, int width, int height) {
    int num_pixels = width * height;
    
    for (int i = 0; i < num_pixels; i++) {
        int r = image_data[i * 4];
        int g = image_data[i * 4 + 1];
        int b = image_data[i * 4 + 2];
        
        uint8_t gray = (uint8_t)(0.299 * r + 0.587 * g + 0.114 * b);
        
        int contrast = (gray - 128) * 1.2 + 128;
        if (contrast > 255) contrast = 255;
        if (contrast < 0) contrast = 0;
        
        image_data[i * 4] = contrast;
        image_data[i * 4 + 1] = contrast;
        image_data[i * 4 + 2] = contrast;
    }
}

}
