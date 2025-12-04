#ifndef CENTRAL_H
#define CENTRAL_H

#include <vector>
#include <pthread.h>
#include "Forest.h"

using namespace std;

class Central;
struct DadosBombeiro {
    Forest* floresta;
    int x;
    int y;
    Central* central;
};

class Central {
private:
    Forest* floresta;
    bool ativa;

    pthread_t thread_central;
    pthread_mutex_t mutex_fila;

    vector<MensagemIncendio> fila_mensagens;
    vector<Coordenada> incendios_atendidos;

public:
    Central(Forest* f);
    ~Central();

    void receberMensagem(MensagemIncendio msg);

    static void* threadHelper(void* context);
    void iniciar();
    void aguardar();

    bool incendioJaAtendido(const Coordenada& coord);
    bool isIncendioDuplicado(const Coordenada& local_fogo);

    void apagarIncendio(DadosBombeiro* dados);
    void cicloDeVida();

    static void* rotinaBombeiro(void* arg);
    void RegistraLog(MensagemIncendio msg);
};

#endif
