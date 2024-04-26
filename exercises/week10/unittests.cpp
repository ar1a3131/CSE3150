#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Electric.h"
#include "Gasoline.h"
#include "Hybrid.h"

TEST_CASE("Testing Electric Vehicle") {
    Electric electric("Electric");


    SUBCASE("Start and Stop") {
        Electric electric("Electric");
        electric.Start();
        electric.Stop();
        
    }
    SUBCASE("Fuel Efficiency") {
        Electric electric("Electric");
        CHECK(electric.FuelEfficiency() == 100.0);
    }
    SUBCASE("Cost Of Fuel") {
        Electric electric("Electric");
        CHECK(electric.CostOfFuel() == 0.05);
    }
}

TEST_CASE("Testing Gasoline Vehicle") {
    SUBCASE("Start and Stop") {
        Gasoline gasoline("Gasoline");
        gasoline.Start();
        gasoline.Stop();
        
    }
    SUBCASE("Fuel Efficiency") {
        Gasoline gasoline("Gasoline");
        CHECK(gasoline.FuelEfficiency() == 30.0);
    }
    SUBCASE("Cost Of Fuel") {
        Gasoline gasoline("Gasoline");
        CHECK(gasoline.CostOfFuel() == 0.15);
    }
}

TEST_CASE("Testing Hybrid Vehicle") {
    SUBCASE("Start and Stop") {
        Hybrid hybrid("Hybrid");
        hybrid.Start();
        hybrid.Stop();
        
    }
    SUBCASE("Fuel Efficiency") {
        Hybrid hybrid("Hybrid");
        double expectedEfficiency = (hybrid.Electric::FuelEfficiency() + hybrid.Gasoline::FuelEfficiency()) / 2.0;
        CHECK(hybrid.FuelEfficiency() == expectedEfficiency);
    }
    SUBCASE("Cost Of Fuel") {
        Hybrid hybrid("Hybrid");
        double expectedCost = (hybrid.Electric::CostOfFuel() + hybrid.Gasoline::CostOfFuel()) / 2.0;
        CHECK(hybrid.CostOfFuel() == expectedCost);
    }
}
