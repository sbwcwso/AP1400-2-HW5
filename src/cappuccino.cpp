#include "cappuccino.h"
#include "sub_ingredients.h"

Cappuccino::~Cappuccino()
{
    clear_ingredients(side_items);
}

Cappuccino::Cappuccino()
{
    name = "Cappuccino";
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
}

Cappuccino::Cappuccino(const Cappuccino &cap) : EspressoBased(cap)
{
    for (auto item : cap.side_items)
        side_items.push_back(item->clone());
}

void Cappuccino::operator=(const Cappuccino &cap)
{
    if (this != &cap)
    {
        EspressoBased::operator=(cap);
        clear_ingredients(side_items);
        for (auto item : cap.side_items)
            side_items.push_back(item->clone());
    }
}

std::string Cappuccino::get_name()
{
    return name;
}

double Cappuccino::price()
{
    double price = 0;
    for (const auto i : ingredients)
        price += i->price();
    for (const auto i : side_items)
        price += i->price();
    return price;
}

void Cappuccino::add_side_item(Ingredient *side)
{
    side_items.push_back(side);
}

std::vector<Ingredient *> &Cappuccino::get_side_items()
{
    return side_items;
}