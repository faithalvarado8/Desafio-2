#ifndef COMPARTIMIENTO_H
#define COMPARTIMIENTO_H

class Compartimiento{
private:
    float capacidad_;
    float cantidadActual_;

public:
    //Constructor
    Compartimiento(float capacidad);
    //Getters
    float getCapacidad() const;
    float getCantidadActual() const;

    //Setters
    void setCantidadActual(float cantidad);
};

#endif // COMPARTIMIENTO_H

