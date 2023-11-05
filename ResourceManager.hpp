#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource resource; // Zarządzany obiekt typu Resource

public:
    // Konstruktor domyślny inicjalizujący zarządzany obiekt
    ResourceManager() : resource() {}

    // Metoda get, która zwraca wynik zawołania metody get obiektu Resource
    double get() {
        return resource.get();
    }

    // Konstruktor kopiujący
    ResourceManager(const ResourceManager& other) : resource(other.resource) {}

    // Operator przypisania
    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            resource = other.resource;
        }
        return *this;
    }
};
