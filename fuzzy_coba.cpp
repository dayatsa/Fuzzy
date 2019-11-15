#include "Arduino.h"
#include "fuzzy_coba.h"
#include <math.h>

Fuzzy::Fuzzy(int nb_, int nm_, int ns_, int zero_, int ps_, int pm_, int pb_, int selisih_) {
    nb = nb_;
    nm = nm_;
    ns = ns_;
    zero = zero_;
    ps = ps_;
    pm = pm_;
    pb = pb_;
    selisih = selisih_;
}