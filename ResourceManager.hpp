#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource* resource; // Zarządzany obiekt typu Resource

public:
    // Konstruktor domyślny inicjalizujący zarządzany obiekt
    ResourceManager() : resource(new Resource()) {}
    
    // Konstruktor kopiujący
    ResourceManager(const ResourceManager& other) : resource(new Resource(*(other.resource))) {}

    // Operator przypisania
    ResourceManager& operator=(const ResourceManager& other) {
        if (this == &other) {
            return *this;
        }
        delete resource;
        resource = new Resource(*(other.resource));
        return *this;
    }

    // Konstruktor przenoszenia
    ResourceManager(ResourceManager&& other) noexcept : resource(other.resource) {
        other.resource = nullptr;
    }

    // Operator przypisania
    ResourceManager& operator=(ResourceManager&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        delete resource;
        resource = other.resource;
        other.resource = nullptr;
        return *this;
    }


    // Destruktor, który zadba o zwolnienie zasobów
    ~ResourceManager() {
        delete resource;
    }

    // Metoda get, która zwraca wynik zawołania metody get obiektu Resource
    double get() const {
        return resource->get();
    }
};
