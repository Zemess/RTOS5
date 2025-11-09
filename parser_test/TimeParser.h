#pragma once
#include <cstdint>

enum {
    TP_OK           = 0,
    TP_ERR_NULL     = -1,
    TP_ERR_LEN      = -2,
    TP_ERR_NAN      = -3,
    TP_ERR_RANGEH   = -4,
    TP_ERR_RANGEM   = -5,
    TP_ERR_RANGES   = -6,
    TP_ERR_ZERO     = -7,
};

int time_parse(const char* hhmmss);