/**
 * @file Product.cpp
 * Implementation file for the Product class
 * 
 * Pseudo-code overview:
 * 1. Function setProductAttributes
 *    - Take parameters for PLU, name, type, price, and inventory
 *    - Assign each parameter to corresponding class member variable
 * 
 * 2. Function setInventory
 *    - Take parameter for inventory
 *    - Assign parameter to inventory member variable
 * 
 * 3. Function getPLU
 *    - Return the PLU member variable
 * 
 * 4. Function getName
 *    - Return the name member variable
 * 
 * 5. Function getType
 *    - Return the type member variable
 * 
 * 6. Function getPrice
 *    - Return the price member variable
 * 
 * 7. Function getInventory
 *    - Return the inventory member variable
 */

 #include "Product.h"
 #include <iostream>
 #include <iomanip>
 
 /**
  * Sets all attributes of a Product object
  * 
  * @param plu PLU (Product Look-Up) code as a string
  * @param prodName Name of the product
  * @param prodType Type/category of the product (as an integer)
  * @param prodPrice Price of the product
  * @param prodInventory Current inventory count of the product
  */
 void Product::setProductAttributes(string plu, string prodName, int prodType, double prodPrice, int prodInventory) {
     PLU = plu;                  // Assign the PLU code
     name = prodName;            // Assign the product name
     type = prodType;            // Assign the product type/category
     price = prodPrice;          // Assign the product price
     inventory = prodInventory;  // Assign the current inventory count
 }
 
 /**
  * Updates the inventory count of a Product
  * 
  * @param prodInventory New inventory count to be set
  */
 void Product::setInventory(int prodInventory) {
     inventory = prodInventory;  // Update the inventory count
 }
 
 /**
  * Gets the PLU code of the Product
  * 
  * @return The Product's PLU code as a string
  */
 string Product::getPLU() const {
     return PLU;  // Return the PLU code
 }
 
 /**
  * Gets the name of the Product
  * 
  * @return The Product's name as a string
  */
 string Product::getName() const {
     return name;  // Return the product name
 }
 
 /**
  * Gets the type/category of the Product
  * 
  * @return The Product's type as an integer
  */
 int Product::getType() const {
     return type;  // Return the product type
 }
 
 /**
  * Gets the price of the Product
  * 
  * @return The Product's price as a double
  */
 double Product::getPrice() const {
     return price;  // Return the product price
 }
 
 /**
  * Gets the current inventory count of the Product
  * 
  * @return The Product's inventory count as an integer
  */
 int Product::getInventory() const {
     return inventory;  // Return the inventory count
 }