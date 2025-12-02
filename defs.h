#ifndef DEFS_H
#define DEFS_H

#include <string>


constexpr int LINHA = 30;
constexpr int COLUNA = 30;
constexpr int MAX_THREADS = 100;

constexpr char TIPO_LIVRE = '-';
constexpr char TIPO_SENSOR = 'T';
constexpr char TIPO_FOGO = '@';

struct Coordenada {
    int x;
    int y;
    bool operator==(const Coordenada& other) const {
        return x == other.x && y == other.y;
    }
};

struct MensagemIncendio {
    int sensor_id;
    Coordenada local_fogo;
    std::string horario;
    bool ativo;
};

#endif