//
// Created by Tyler Moses on 3/11/18.
//
#include <iostream>
#include <iomanip>
#include "vehicles.h"
#include <typeinfo>

const int SPACE = 17;
int main(int argc, char* argv[])
{
  std::cout << "RCL::Tracker started...";
  int segmentNumber = 1;
  char sn[50];
  char dot[50];
  int passengers;
  while (segmentNumber != 0)
  {
    std::cin >> segmentNumber;
    if (segmentNumber == 0) {
      return 0;
    }
    if (segmentNumber > 100) {
      std::cout << "Segment count is too large";
      return 0;
    }
    int typeCounts[] = {
            0, 0, 0, 0, 0, 0, 0
    };
    double tons = 0.0;
    double toll = 0.0;
    int l, w, h;
    Vehicle* vehicles[segmentNumber];
    for (int i = 0; i < segmentNumber; i++)
    {
      std::cin >> sn;
      std::cin >> passengers;
      if (sn[0] == '1')
      {
        typeCounts[0]++;
        Vehicle* vehicle = new Vehicle(sn, passengers, false);
        vehicles[i] = vehicle;
        toll += vehicle->Toll();
      } else if (sn[0] == '2')
      {
        typeCounts[1]++;
        Car* car = new Car(sn, passengers, false);
        vehicles[i] = static_cast<Vehicle*>(car);
        toll += car->Toll();
      } else if (sn[0] == '3')
      {
        typeCounts[2]++;
        std::cin >> dot;
        Truck* truck = new Truck(sn, passengers, dot, false);
        vehicles[i] = static_cast<Truck*>(truck);
        toll += truck->Toll();
      } else if (sn[0] == '4')
      {
        typeCounts[3]++;
        std::cin >> dot;
        std::cin >> l;
        std::cin >> w;
        std::cin >> h;
        Van* van = new Van(sn, passengers, dot, l, w, h, false);
        vehicles[i] = static_cast<Van*>(van);
        toll += van->Toll();
      } else if (sn[0] == '5')
      {
        typeCounts[4]++;
        std::cin >> dot;
        std::cin >> l;
        std::cin >> w;
        Tanker* tanker = new Tanker(sn, passengers, dot, l, w, false);
        vehicles[i] = static_cast<Tanker*>(tanker);
        toll += tanker->Toll();
      } else if (sn[0] == '6')
      {
        typeCounts[5]++;
        std::cin >> dot;
        std::cin >> l;
        std::cin >> w;
        Flatbed* flatbed = new Flatbed(sn, passengers, dot, l, w, false);
        vehicles[i] = static_cast<Flatbed*>(flatbed);
        toll += flatbed->Toll();
      }
      else {
        typeCounts[6]++;
      }
    }
    std::cout << "\n\nSegment Summary\n===============\n\n";
    std::cout << "Cars: " << typeCounts[1] << "\n";
    std::cout << "Trucks: " << typeCounts[2] << "\n";
    std::cout << "Vans: " << typeCounts[3] << "\n";
    std::cout << "Tankers: " << typeCounts[4] << "\n";
    std::cout << "Flatbeds: " << typeCounts[5] << "\n";
    std::cout << "Unknowns: " << typeCounts[0] << "\n";
    std::cout << "Badsn: " << typeCounts[6] << "\n";
    std::cout << "Tonnage: " << tons << "\n";
    std::cout << "Tolls: $" << toll << "\n";

    std::cout << "\n\nSegment Details\n===============\n\n";
    std::cout << std::setw(SPACE) << "Type"
              << std::setw(SPACE) << "Toll"
              << std::setw(SPACE) << "Pass Cap"
              << std::setw(SPACE) << "Load Cap"
              << std::setw(SPACE) << "DOT License"
              << std::setw(SPACE) << "Serial Number\n";

    std::cout << std::setw(SPACE) << "------"
              << std::setw(SPACE) << "------"
              << std::setw(SPACE) << "---------"
              << std::setw(SPACE) << "---------"
              << std::setw(SPACE) << "------------"
              << std::setw(SPACE) << "--------------\n";

    int size = sizeof(vehicles)/sizeof(vehicles[0]);
    for (int i = 0; i < size; i++)
    {
      if (typeid(*vehicles[i]) == typeid(Vehicle))
      {
        Vehicle* vehicle = vehicles[i];
        std::cout << std::setw(SPACE) << vehicle->ShortName()
                  << std::setw(SPACE) << vehicle->Toll()
                  << std::setw(SPACE) << vehicle->PassengerCapacity()
                  << std::setw(SPACE) << vehicle->LoadCapacity()
                  << std::setw(SPACE) << "(NA)"
                  << std::setw(SPACE) << vehicle->SerialNumber();
      }
      if (typeid(*vehicles[i]) == typeid(Car))
      {
        Car* car = (Car*) vehicles[i];
        std::cout << std::setw(SPACE) << car->ShortName()
                  << std::setw(SPACE) << car->Toll()
                  << std::setw(SPACE) << car->PassengerCapacity()
                  << std::setw(SPACE) << car->LoadCapacity()
                  << std::setw(SPACE) << "(NA)"
                  << std::setw(SPACE) <<  car->SerialNumber();
      }
      if (typeid(*vehicles[i]) == typeid(Truck))
      {
        Truck* truck = (Truck*) vehicles[i];
        std::cout << std::setw(SPACE) << truck->ShortName()
                  << std::setw(SPACE) << truck->Toll()
                  << std::setw(SPACE) << truck->PassengerCapacity()
                  << std::setw(SPACE) << truck->LoadCapacity()
                  << std::setw(SPACE) << truck->DOTLicense()
                  << std::setw(SPACE) << truck->SerialNumber();
      }
      if (typeid(*vehicles[i]) == typeid(Van))
      {
        Van* van = (Van*) vehicles[i];
        std::cout << std::setw(SPACE) << van->ShortName()
                  << std::setw(SPACE) << van->Toll()
                  << std::setw(SPACE) << van->PassengerCapacity()
                  << std::setw(SPACE) << van->LoadCapacity()
                  << std::setw(SPACE) << van->DOTLicense()
                  << std::setw(SPACE) << van->SerialNumber();
      }
      if (typeid(*vehicles[i]) == typeid(Tanker))
      {
        Tanker* tanker = (Tanker*) vehicles[i];
        std::cout << std::setw(SPACE) << tanker->ShortName()
                  << std::setw(SPACE) << tanker->Toll()
                  << std::setw(SPACE) << tanker->PassengerCapacity()
                  << std::setw(SPACE) << tanker->LoadCapacity()
                  << std::setw(SPACE) << tanker->DOTLicense()
                  << std::setw(SPACE) << tanker->SerialNumber();
      }
      if (typeid(*vehicles[i]) == typeid(Flatbed))
      {
        Flatbed* flatbed = (Flatbed*) vehicles[i];
        std::cout << std::setw(SPACE) << flatbed->ShortName()
                  << std::setw(SPACE) << flatbed->Toll()
                  << std::setw(SPACE) << flatbed->PassengerCapacity()
                  << std::setw(SPACE) << flatbed->LoadCapacity()
                  << std::setw(SPACE) << flatbed->DOTLicense()
                  << std::setw(SPACE) << flatbed->SerialNumber();
      }
      std::cout << "\n";
    }
  }
  return 0;
}