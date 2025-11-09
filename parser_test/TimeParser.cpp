#include "TimeParser.h"
#include <cctype>
#include <cstring>

static int to2(const char* s) { return (s[0] - '0') * 10 + (s[1] - '0'); }

int time_parse(const char* hhmmss) {

    if (!hhmmss) return TP_ERR_NULL;
    if (std::strlen(hhmmss) != 6) return TP_ERR_LEN;

    for (int i=0; i < 6; ++i) {
        if (!std::isdigit(static_cast<unsigned char>(hhmmss[i])))
            return TP_ERR_NAN;
    }

    int h = to2(hhmmss+0);
    int m = to2(hhmmss+2);
    int s = to2(hhmmss+4);

    if (h < 0 || h > 23) return TP_ERR_RANGEH;
    if (m < 0 || m > 59) return TP_ERR_RANGEM;
    if (s < 0 || s > 59) return TP_ERR_RANGES;

    int total = h * 3600 + m * 60 + s;
    if (total == 0) return TP_ERR_ZERO;
    return total;

}