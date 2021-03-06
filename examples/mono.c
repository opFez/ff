#include <stdlib.h>
#include <assert.h>
#include "../ff.h"

int
main(int argc, char *argv[])
{
    uint32_t i, j, width, height;

    assert(argc == 5);

    pixel p = { atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]) };
    width = 1000;
    height = 500;

    ff_write_header(width, height);

    for (j = 0; j < height; j++)
        for (i = 0; i < width; i++) {
            p.r = i % 255;
            p.g = j % 255;
            ff_write_rgba(p);
            // coordinate of pixel = (i, j)
        }
}
