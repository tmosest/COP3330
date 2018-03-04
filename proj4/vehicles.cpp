//
// Created by Tyler Moses on 3/3/18.
//

#include <vehicles.h>
#include <shapes.h>
#include <cstdlib>
#include <cstring>
#include <iostream>   // Input / Output Stream

/*
 * Vehicle
 */

VehicleType Vehicle::SnDecode(const char* sn) {
  int code = atoi(sn);
  if (code < badSn || code > flatbed) {
    return badSn;
  }
  return static_cast<VehicleType>(code);
}

Vehicle::Vehicle(const char* sn, unsigned int capacity, bool verbose)
{
  if (verbose) {
    std::cout << "Vehicle(" << sn << "," << capacity << "," << verbose << ")\n";
  }
  std::size_t size = std::strlen(sn);
  char* s = new char[size+1];
  std::strcpy (s, sn);
  serialNumber_ = s;
  passengerCapacity_ = capacity;
  verbose_ = verbose;
}

Vehicle::~Vehicle() {
  if (verbose_) {
    std::cout << "~Vehicle()\n";
  }
}

const char* Vehicle::SerialNumber() const {
  return serialNumber_;
}

unsigned int Vehicle::PassengerCapacity() const {
  return passengerCapacity_;
}

float Vehicle::LoadCapacity() const {
  return 0.0;
}

const char* Vehicle::ShortName() const {
  return "UNK";
}

float Vehicle::Toll() const {
  return 2.0;
}

/*
 * Car
 */

Car::Car(const char* sn, unsigned int passengerCapacity, bool verbose) : Vehicle(sn, passengerCapacity, verbose)
{
  if (verbose)
  {
    std::cout << "Car(" << sn << "," << passengerCapacity << "," << verbose << ")\n";
  }
}

Car::~Car()
{
 if (verbose_)
 {
    std::cout << "~Car()\n";
 }
}

const char* Car::ShortName() const
{
  return "CAR";
}

/*
 * Truck
 */

Truck::Truck(const char* sn, unsigned int passengerCapacity, const char* dot, bool verbose) :
  Vehicle(sn, passengerCapacity, verbose)
{
  if (verbose)
  {
    std::cout << "Truck(" << sn << "," << passengerCapacity << "," << dot << "," << verbose << ")\n";
  }
  std::size_t size = std::strlen(dot);
  char* d = new char[size+1];
  std::strcpy (d, dot);
  DOTLicense_ = d;
}

Truck::~Truck()
{
  if (Vehicle::verbose_)
  {
    std::cout << "~Truck()\n";
  }
}

const char * Truck::ShortName() const
{
  return "TRK";
}

float Truck::Toll() const
{
  return 10.00;
}

const char* Truck::DOTLicense() const
{
  return DOTLicense_;
}

/*
 * Van
 */

Van::Van(const char* sn, unsigned int passengerCapacity, const char* dot, float l, float w, float h, bool verbose) :
  Truck(sn, passengerCapacity, dot, verbose), Box(l, w, h, verbose)
{
  if (verbose)
  {
    std::cout
      << "Van("
      << sn
      << ","
      << passengerCapacity
      << ","
      << dot
      << ","
      << l
      << ","
      << w
      << ","
      << h
      << ","
      << verbose
      << ")\n";
  }
}

Van::~Van()
{
  if (Vehicle::verbose_)
  {
    std::cout << "~Van()\n";
  }
}

float Van::LoadCapacity() const
{
  return this->Volume();
}

const char * Van::ShortName() const
{
  return "VAN";
}

/*
 * Tanker
 */

Tanker::Tanker(const char* sn, unsigned int passengerCapacity, const char* dot, float r, float h, bool verbose) :
  Truck(sn, passengerCapacity, dot, verbose), Cylinder(r, h, verbose)
{
  if (verbose)
  {
    std::cout << "Tank("
              << sn
              << ","
              << passengerCapacity
              << ","
              << dot
              << ","
              << r
              << ","
              << h
              << ","
              << verbose
              << ")\n";
  }
}

Tanker::~Tanker()
{
  if (Vehicle::verbose_)
  {
    std::cout << "~Tanker()\n";
  }
}

float Tanker::LoadCapacity() const
{
  return this->Volume();
}

const char * Tanker::ShortName() const
{
  return "TNK";
}

/*
 * Flatbed
 */
Flatbed::Flatbed(const char* sn, unsigned int passengerCapacity, const char* dot, float l, float w, bool verbose) :
  Truck(sn, passengerCapacity, dot, verbose), Rectangle(l, w, verbose)
{
  if (verbose)
  {
    std::cout
    << "Flatbed("
    << sn
    << ","
    << passengerCapacity
    << ","
    << dot
    << ","
    << l
    << ","
    << w
    << ","
    << verbose
    << ")\n";
  }
}

Flatbed::~Flatbed()
{
  if (Vehicle::verbose_)
  {
    std::cout << "~Flatbed()\n";
  }
}

float Flatbed::LoadCapacity() const
{
  return this->Area();
}

const char * Flatbed::ShortName() const
{
  return "FLT";
}
