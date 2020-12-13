//---------------------------------------------------------------------------

#ifndef rdc_draphH
#define rdc_draphH
//---------------------------------------------------------------------------
// Данные для определения расстояния до цели //
// 1. По размерам большого диаметра СМ //
double rdc_sm_dsm[16]; // Диаметр СМ (4,2 м)
double rdc_sm_dsu[16]; // Диаметр СУ (1,3 м)
double rdc_sm_hm[16];  // Размер мишени (0,4 м)

// 2. По размерам большого диаметра МИМ1
double rdc_mim1_dmim1[16];
double rdc_mim1_dsu[16];
double rdc_mim1_hmm[16];
double rdc_mim1_dsm[16];

// 3. По размерам большого диаметра СО1 и МИМ2
double rdc_somim_dso1[16];
double rdc_somim_dsu[16];
double rdc_somim_hmm[16];
double rdc_somim_dsm[16];
#endif
