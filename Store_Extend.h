#pragma once
#include "FTLGame.h"
#include "Systems.h"

enum class Currency
{
    SCRAP,
    FUEL,
    MISSILES,
    DRONE_PARTS,
    WEAPONS,
    DRONES,
    AUGMENTS,
    CREW,
    SYSTEMS,
    REACTOR,
    HULL
};

enum class Resource
{
    FUEL,
    MISSILES,
    DRONE_PARTS
};

enum class CategoryType
{
    WEAPONS,
    DRONES,
    CREW,
    AUGMENTATIONS,
    SYSTEMS
};

struct ResourceItem
{
    Resource type;
    int minCount;
    int maxCount;

    bool modifiedPrice = false;
    bool flatModifier = false;
    bool setPrice = false;
    float modifier = 1.f; // multiplies the price by 1 by default
    int price;

    bool visible;
};

struct HullRepair
{
    int maxRepairs = -1; // infinite
    int price; // sector-scaled by default
    bool visible;
};

struct StoreItem
{
    StoreBox* origItem;
    std::string blueprintList; // for random items
    std::string itemName;
    std::string iconFileName;

    std::vector<StoreItem> bundledItems;
    std::vector<ResourceItem> bundledResources;

    bool modifiedPrice = false;
    bool flatModifier = false;
    bool setPrice = false;
    float modifier = 1.f; // multiplies the price by 1 by default

    float bundleChance;
    float bundlePriceIncrease;

    int price; // item's xml price by default
    int stock = -1; // infinite by default
    Currency individualCurrency; // uses the store's currency by default
};

struct StoreCategory
{
    std::vector<StoreItem> items;
    std::string blueprintList;

    CategoryType categoryType;
    std::vector<SystemId> allowedSystems; // contains all by default
    std::string categoryName;
    std::string iconFileName;

    int categoryStock; // infinite by default
};

struct FullStore
{
    std::vector<StoreCategory> categories;
    std::vector<ResourceItem> resources;
    HullRepair hullRepair;

    Currency buyCurrency = Currency::SCRAP; // all stores use scrap by default
    Currency sellCurrency = Currency::SCRAP;
    float sellToBuyRatio = 0.5; // selling at half the price of buying for an item's currency value
    bool canBuy = true;
    bool canSell = true;
    std::vector<Currency> validSells; // is weapons, drones, augments by default
    std::vector<std::string> validItemSells;

    int totalItemStock = -1; // infinite by default
    int sellLimit = -1;

    int storeNum; // for when multiple stores are created at once
};

struct Store_Extend
{
    Store *orig;
    FullStore customStore;


    ~Store_Extend()
    {

    }
};

Store_Extend* Get_Store_Extend(Store* c);

#define STORE_EX Get_Store_Extend
