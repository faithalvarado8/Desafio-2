#ifndef COMPARTIMIENTO_H
#define COMPARTIMIENTO_H

class Compartimiento{
private:
    double capacidad_;
    double cantidadActual_;

public:
    //Constructor
    Compartimiento(double capacidad);
    //Getters
    double getCapacidad() const;
    double getCantidadActual() const;

    //Setters
    void setCantidadActual(double cantidad);
};

#endif // COMPARTIMIENTO_H
