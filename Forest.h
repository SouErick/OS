#ifndef FOREST_H
#define FOREST_H

#include <pthread.h>
#include "defs.h"

class Forest {
private:
    char grid [LINHA][COLUNA];
    pthread_mutex_t mapa_mutex;

public:
    Forest();
    ~Forest();

    void inicializar();

    char getTipo(int x, int y);
    void setTipo(int x, int y, char tipo);

    void imprimir();
};

#endif
