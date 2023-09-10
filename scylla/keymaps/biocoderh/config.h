// Copyright 2023 Biocoder.h <biocoder.h@gmail.com>

#pragma once

#define XXX KC_NO

#define LAYOUT_biocoderh( \
         K00, K01, K02, K03,                          K04, K05, K06, K07, \
         K08, K09, K10, K11, K12,                K13, K14, K15, K16, K17, \
         K18, K19, K20, K21,                          K22, K23, K24, K25, \
                   K26, K27, K28,                K29, K30, K31 \
) \
LAYOUT_split_4x6_5( \
    XXX, XXX, XXX, XXX, XXX, XXX,                XXX, XXX, XXX, XXX, XXX, XXX, \
    XXX, K00, K01, K02, K03, XXX,                XXX, K04, K05, K06, K07, XXX, \
    XXX, K08, K09, K10, K11, K12,                K13, K14, K15, K16, K17, XXX, \
    XXX, K18, K19, K20, K21, XXX,                XXX, K22, K23, K24, K25, XXX, \
                   K26, K27, XXX,                XXX, K30, K31, \
                        K28, XXX,                XXX, K29 \
)
