#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Structure to represent a single product
struct Product {
    int id;
    std::string name;
    double price;
};

// Class to handle shopping cart operations
class ShoppingCart {
private:
    std::vector<std::pair<Product, int>> items; // Stores pairs of (Product, Quantity)

public:
    // Add a product to the cart or increase quantity if it already exists
    void addProduct(const Product& product, int quantity) {
        if (quantity <= 0) {
            std::cout << "Quantity must be greater than 0.\n";
            return;
        }

        for (auto& item : items) {
            if (item.first.id == product.id) {
                item.second += quantity;
                std::cout << "Updated " << product.name << " quantity to " << item.second << ".\n";
                return;
            }
        }
        items.push_back({product, quantity});
        std::cout << product.name << " added to cart.\n";
    }

    // View all items currently in the cart
    void viewCart() const {
        if (items.empty()) {
            std::cout << "\nYour shopping cart is empty.\n";
            return;
        }

        std::cout << "\n--- Your Shopping Cart ---\n";
        std::cout << std::left << std::setw(15) << "Item" 
                  << std::setw(10) << "Price" 
                  << std::setw(10) << "Qty" 
                  << "Total\n";
        std::cout << "-------------------------------------\n";

        double grandTotal = 0.0;
        for (const auto& item : items) {
            double itemTotal = item.first.price * item.second;
            grandTotal += itemTotal;
            std::cout << std::left << std::setw(15) << item.first.name 
                      << "$" << std::setw(9) << item.first.price 
                      << std::setw(10) << item.second 
                      << "$" << itemTotal << "\n";
        }
        std::cout << "-------------------------------------\n";
        std::cout << "Grand Total: $" << grandTotal << "\n\n";
    }

    // Clear the cart completely
    void checkout() {
        if (items.empty()) {
            std::cout << "Cart is empty. Nothing to check out.\n";
            return;
        }
        viewCart();
        std::cout << "Thank you for your purchase! Processing payment...\n";
        items.clear();
    }
};

int main() {
    // Available store catalog
    Product catalog[] = {
        {1, "Laptop", 999.99},
        {2, "Smartphone", 499.99},
        {3, "Headphones", 79.99},
        {4, "Backpack", 45.00}
    };
    int totalProducts = 4;

    ShoppingCart cart;
    int choice;

    std::cout << std::fixed << std::setprecision(2); // Format output to 2 decimal places

    do {
        std::cout << "=== Main Menu ===\n";
        std::cout << "1. View Catalog & Add Item\n";
        std::cout << "2. View Shopping Cart\n";
        std::cout << "3. Checkout\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "\n--- Available Products ---\n";
            for (int i = 0; i < totalProducts; ++i) {
                std::cout << catalog[i].id << ". " << catalog[i].name << " - $" << catalog[i].price << "\n";
            }
            
            int prodId, qty;
            std::cout << "\nEnter Product ID to add: ";
            std::cin >> prodId;
            std::cout << "Enter Quantity: ";
            std::cin >> qty;

            if (prodId >= 1 && prodId <= totalProducts) {
                cart.addProduct(catalog[prodId - 1], qty);
            } else {
                std::cout << "Invalid Product ID.\n";
            }
            std::cout << "\n";

        } else if (choice == 2) {
            cart.viewCart();
        } else if (choice == 3) {
            cart.checkout();
        } else if (choice == 4) {
            std::cout << "Goodbye!\n";
        } else {
            std::cout << "Invalid selection. Please try again.\n\n";
        }

    } while (choice != 4);

    return 0;
}
