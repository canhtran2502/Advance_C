#include <stdio.h>
#include <stdlib.h>
#include "decorators.h"


s_crc_checksum_t* create_crc_checksum_decorator(s_connectivity_t* connectivity)
{
    s_crc_checksum_t* crc_checksum_decorator = (s_crc_checksum_t*)malloc(sizeof(s_crc_checksum_t));
    if (crc_checksum_decorator != NULL)
    {
        crc_checksum_decorator->connectivity = connectivity;
    }
    else
    {
        printf("Error when creating crc checksum decorator\n");
    }

    return crc_checksum_decorator;
}

s_enc_dec_t* create_enc_dec_decorator(s_connectivity_t* connectivity)
{
    s_enc_dec_t* enc_dec_decorator = (s_enc_dec_t*)malloc(sizeof(s_enc_dec_t));
    if (enc_dec_decorator != NULL)
    {
        enc_dec_decorator->connectivity = connectivity;
    }
    else
    {
        printf("Error when creating encode/decode decorator\n");
    }

    return enc_dec_decorator;
}
s_compress_descompress_t* create_compress_descompress_decorator(s_connectivity_t* connectivity)
{
    s_compress_descompress_t* compress_descompress_decorator = (s_compress_descompress_t*)malloc(sizeof(s_compress_descompress_t));
    if (compress_descompress_decorator != NULL)
    {
        compress_descompress_decorator->connectivity = connectivity;
    }
    else
    {
        printf("Error when creating compress/decompress decorator\n");
    }

    return compress_descompress_decorator;
}

s_logging_t* create_logging_decorator(s_connectivity_t* connectivity)
{
    s_logging_t* logging_decorator = (s_logging_t*)malloc(sizeof(s_logging_t));
    if (logging_decorator != NULL)
    {
        logging_decorator->connectivity = connectivity;
    }
    else
    {
        printf("Error when creating logging decorator\n");
    }

    return logging_decorator;
}

void free_crc_checksum_decorator(s_crc_checksum_t* crc_checksum_decorator)
{
    free(crc_checksum_decorator);
}

void free_enc_dec_decorator(s_enc_dec_t* enc_dec_decorator)
{
    free(enc_dec_decorator);
}

void free_compress_descompress_decorator(s_compress_descompress_t* compress_descompress_decorator)
{
    free(compress_descompress_decorator);
}

void free_logging_decorator(s_logging_t* logging_decorator)
{
    free(logging_decorator);
}

