#ifndef SENSOR_H
#define SENSOR_H

#include <pthread.h>
#include "defs.h"
#include "Forest.h"

class Central;

class Sensor {
private:
    int id;
    int x, y;
    Forest* floresta;
    Central* central;
    pthread_t thread_id; // Identificador da thread no sistema
    bool ativo;

    static Sensor* mapa_sensores[LINHA][COLUNA];

    void cicloDeVida();
    static void* threadHelper(void* context); // funcao estática para pthread_create
    void propagarMensagem(MensagemIncendio msg);
    bool souBorda();

public:
    Sensor(int id, int x, int y, Forest* floresta, Central* central);
    ~Sensor();

    void iniciar();
    void aguardar();
    void receberPropagacao(MensagemIncendio msg);
};

#endif