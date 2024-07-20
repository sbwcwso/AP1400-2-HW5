#include "mocha.h"
#include "sub_ingredients.h"

Mocha::Mocha()
{
    name = "Mocha";
    ingredients.push_back(new Chocolate(1));
}
