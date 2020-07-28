#include <stdlib.h>
#include <assert.h>

#include <math.h>
#include <complex.h>
#include "ff.h"

int
main(int argc, char *argv[])
{
    uint32_t x, y, width, height, iter, rgb;
    double complex c;
    double complex z;

    width = atoi(argv[1]);
    height = atoi(argv[2]);

    ff_write_header(width, height);

    z = 0 + 0 * I;

    for (y = 0; y < height; y++)
        for (x = 0; x < width; x++) {
            z = 0;
            iter = 0;
            c = ((float)x / (float)width) + ((float)y / (float)height) * I;
            c -= 0.5 + 0.5 * I;
            c *= 3;
            c -= 0.5;

            while (1) {
                if (cabs(z) > 4.0) {
                    rgb = (iter * 255) / 1000;
                    ff_write_rgba((pixel) { rgb, rgb, rgb, 255 });
                    break;
                }

                z = z * z + c;

                if (++iter == 1000) {
                    ff_write_rgba((pixel){ 255, 255, 255, 255 });
                    break;
                }
            }
        }
}
