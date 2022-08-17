#ifndef MPTVLAKYO_H
#define MPTVLAKYO_H

#include "mtypy.h"

const string Server="http://95.173.69.9:5823";

UkPolozka ZiskejData(string T, unsigned int AdrId);
void PosliData(string T, unsigned int AdrId, string Fce, Polozka Hodnota);

#endif