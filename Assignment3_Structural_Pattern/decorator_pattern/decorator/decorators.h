#ifndef DECORATORS_H
#define DECORATORS_H

#include <stdint.h>
#include "../connectivity/connectivity.h"

typedef struct {
    s_connectivity_t* connectivity;
    void (*crc_16bit)(void);
    /* CRC function simulation */
} s_crc_checksum_t;

typedef struct {
    s_connectivity_t* connectivity;
    void (*enc)(void);
    /* Enc/Dec function simulation */
} s_enc_dec_t;

typedef struct {
    s_connectivity_t* connectivity;
    /* Compress/Descompress function simulation */
} s_compress_descompress_t;

typedef struct {
    s_connectivity_t* connectivity;
    /* Logging function simulation */
} s_logging_t;

s_crc_checksum_t* create_crc_checksum_decorator(s_connectivity_t* connectivity);
s_enc_dec_t* create_enc_dec_decorator(s_connectivity_t* connectivity);
s_compress_descompress_t* create_compress_descompress_decorator(s_connectivity_t* connectivity);
s_logging_t* create_logging_decorator(s_connectivity_t* connectivity);

void free_crc_checksum_decorator(s_crc_checksum_t* crc_checksum_decorator);
void free_enc_dec_decorator(s_enc_dec_t* enc_dec_decorator);
void free_compress_descompress_decorator(s_compress_descompress_t* compress_descompress_decorator);
void free_logging_decorator(s_logging_t* logging_decorator);

#endif
