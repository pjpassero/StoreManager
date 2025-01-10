#include "Product.h"
#include "UID.h"
#include <fstream>
#include <pqxx/pqxx>

Product::Product(pqxx::connection &conn):C(conn) {
}



Product::Product(string n, double fCost, double pPrice, int qQuantity, int sSupplier, int uUPC, pqxx::connection &conn) : C(conn) {
    name = n;
    factoryCost = fCost;
    price = pPrice;
    quantity = qQuantity;
    lastSupplier = sSupplier;
    UPC = uUPC;
    storeSKU = createUID(5, name, true);
    activationLevel = 0;
}

void Product::SaveToInventoryFile(Product &product) {
    try {
        pqxx::work txn(C);
        std::string query = "INSERT INTO product (sku, productname, productcost, productprice, productinventory, supplierid, upc) "
                            "VALUES ($1, $2, $3, $4, $5, $6, $7)";
        txn.exec_params(query, product.storeSKU, product.name, product.factoryCost, product.price, product.quantity, product.lastSupplier, product.UPC);
        txn.commit();

        std::cout << "Product added to inventory successfully!" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error saving product to inventory: " << e.what() << std::endl;
    }
}


void Product::getProductName() {
    cout << name << endl;
}

void Product::getProductPrice() {
    cout << price <<  endl;
}
