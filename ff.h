#include <stdio.h>
#include <stdint.h>
#include <string.h>     // strcmp
#include <arpa/inet.h>  // htonl

typedef struct {
    uint16_t r;
    uint16_t g;
    uint16_t b;
    uint16_t a;
} pixel;

int
is_ff(char *f)
{
    FILE *a;
    char buf[9];
    a = fopen(f, "r");

    fgets(buf, 9, a);

    fclose(a);

    if (strcmp("farbfeld", buf))
        return 0;
    else
        return 1;
}

void
ff_write_header(uint32_t width, uint32_t height)
{
    uint32_t w, h;

    printf("farbfeld");

    w = htonl(width);   // farbfeld requires this htonl stuff
    h = htonl(height);  // i think its something to do with endian?

    fwrite(&w, sizeof(w), 1, stdout);
    fwrite(&h, sizeof(h), 1, stdout);
}

int
ff_write_rgba(pixel p)
{
    uint16_t q[4];
    q[0] = p.r;
    q[1] = p.g;
    q[2] = p.b;
    q[3] = p.a;

    if (fwrite(&q, sizeof(uint16_t), 4, stdout) != 4)
        return 1;

    return 0;
}

uint32_t
ff_get_width(char *f)
{
    FILE *a;
    unsigned char buf[4];
    uint32_t width;
    int i;
    a = fopen(f, "r");

    fseek(a, 8, 0);
    for (i = 0; i < 4; i++) {
        buf[i] = fgetc(a);
    }

    fclose(a);

    width = (buf[3] << 24) | (buf[2] << 16) | (buf[1] << 8) | (buf[0]);

    return ntohl(width);
    // ntohl ser ut til å gjøre motsatte av htonl, brukt til å skrive fila
}

uint32_t
ff_get_height(char *f)
{
    FILE *a;
    unsigned char buf[4];
    uint32_t height;
    int i;
    a = fopen(f, "r");

    fseek(a, 12, 0);
    for (i = 0; i < 4; i++) {
        buf[i] = fgetc(a);
    }

    fclose(a);

    height = (buf[3] << 24) | (buf[2] << 16) | (buf[1] << 8) | (buf[0]);

    return ntohl(height);
}
