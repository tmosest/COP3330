//
// Created by Tyler Moses on 3/3/18.
//

#ifndef VEHICLES_H
#define VEHICLES_H

#include "shapes.h"
#include <cstring>

enum VehicleType {
    badSn, vehicle, car, truck, van, tanker, flatbed
};

class Vehicle {
public:
    static VehicleType SnDecode(const char* sn);
    Vehicle(const char* sn = "1", unsigned int passengerCapacity = 1, bool verbose = false);
    virtual ~Vehicle();
    const char* SerialNumber() const;
    unsigned int PassengerCapacity() const;
    virtual float LoadCapacity() const;
    virtual const char* ShortName() const;
    virtual float Toll() const;
private:
    const char* serialNumber_;
    unsigned int passengerCapacity_;
protected:
    bool verbose_;
};

class Car : public Vehicle {
public:
    Car(const char* sn, unsigned int passengerCapacity = 2, bool verbose = false);
    virtual ~Car();
    virtual const char* ShortName() const;
};

class Truck : public Vehicle {
public:
    Truck(const char* sn, unsigned int passengerCapacity, const char* dot, bool verbose = false);
    virtual ~Truck();
    virtual const char* ShortName() const;
    virtual float Toll() const;
    virtual const char* DOTLicense() const;
protected:
    const char* DOTLicense_;
};

class Van : public Truck, public Box {
public:
    Van(const char* sn, unsigned int passengerCapacity, const char* dot, float l = 1, float w = 1, float h = 1, bool verbose = false);
    virtual ~Van();
    virtual float LoadCapacity() const;
    virtual const char* ShortName() const;
};

class Tanker : public Truck, public Cylinder {
public:
    Tanker(const char* sn, unsigned int passengerCapacity, const char* dot, float r = 1.0, float h = 1.0, bool verbose = false);
    virtual ~Tanker();
    virtual float LoadCapacity() const;
    virtual const char* ShortName() const;
};

class Flatbed : public Truck, public Rectangle {
public:
    Flatbed(const char* sn, unsigned int passengerCapacity, const char* dot, float l = 1.0, float w = 1.0, bool verbose = false);
    virtual ~Flatbed();
    virtual float LoadCapacity() const;
    virtual const char* ShortName() const;
};

#endif //VEHICLES_H
