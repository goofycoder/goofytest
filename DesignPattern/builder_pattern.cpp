/*
    Builder Pattern (Creational Pattern)
        - separate the construction of a complex object from its representation 
        - so that the same construction process can create different objects representations.
    
    Problem 
        - We want to construct a complex object 
        - However, we do not want to have a complex constructor member or one that would need many arguments.

    Solution 
        - Define an intermediate object whose member functions define the desired object part by part before the object is available to the client. 
        - Build Pattern lets us defer the construction of the object until all the options for creation have been specified.    
        
 */


#include <string>
#include <iostream>
#include <new>

// "Product"
class Pizza
{
public:
    void setDough(const std::string& dough) {
        m_dough = dough;
    }
    
    void setSauce(const std::string& sauce) {
        m_sauce = sauce;
    }
    
    void setTopping(const std::string& topping) {
        m_topping = topping;
    }              

    void open() const {
        std::cout << "Pizza with " << m_dough << " dough, " << m_sauce << " sauce and "
                  << m_topping << " topping. Mmm.\n";
    }
private:
    std::string m_dough;
    std::string m_sauce;
    std::string m_topping;
};
 
// "Abstract Builder"
class PizzaBuilder
{
public:
    Pizza* getPizza() {
        return m_pizza;
    }
    
    void createNewPizzaProduct()  {
        m_pizza = new Pizza;
    }
    
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;

protected:
    Pizza* m_pizza;
};
 
//----------------------------------------------------------------
class HawaiianPizzaBuilder : public PizzaBuilder
{
public:
    virtual void buildDough() {
        m_pizza->setDough("cross");
    }

    virtual void buildSauce() {
        m_pizza->setSauce("mild");
    }
    
    virtual void buildTopping() {
        m_pizza->setTopping("ham+pineapple");
    }
};
 
class SpicyPizzaBuilder : public PizzaBuilder
{
public:
    virtual void buildDough() {
        m_pizza->setDough("pan baked");
    }
    
    virtual void buildSauce() {
        m_pizza->setSauce("hot");
    }
 
    virtual void buildTopping() {
        m_pizza->setTopping("pepperoni+salami");
    }
};
 
//----------------------------------------------------------------
class Cook
{
public:
    void setPizzaBuilder(PizzaBuilder* pb) {
        m_pizzaBuilder = pb;
    }

    Pizza* getPizza() {
        return m_pizzaBuilder->getPizza();
    }
    
    void constructPizza()  {
        m_pizzaBuilder->createNewPizzaProduct();
        m_pizzaBuilder->buildDough();
        m_pizzaBuilder->buildSauce();
        m_pizzaBuilder->buildTopping();
    }

private:
    PizzaBuilder* m_pizzaBuilder;
};
 
int main()
{
    Cook cook;
    PizzaBuilder* hawaiianPizzaBuilder = new HawaiianPizzaBuilder;
    PizzaBuilder* spicyPizzaBuilder    = new SpicyPizzaBuilder;
 
    cook.setPizzaBuilder(hawaiianPizzaBuilder);
    cook.constructPizza();
 
    Pizza* hawaiianPizza = cook.getPizza();
    hawaiianPizza->open();
 
    cook.setPizzaBuilder(spicyPizzaBuilder);
    cook.constructPizza();
 
    Pizza* spicyPizza = cook.getPizza();
    spicyPizza->open();
 
    delete hawaiianPizzaBuilder;
    delete spicyPizzaBuilder;
    delete hawaiianPizza;  
    delete spicyPizza;     
}
