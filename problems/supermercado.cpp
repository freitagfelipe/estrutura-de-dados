#include <iostream>
#include <vector>

class Product {
private:
    std::string name;
    int price;

public:
    Product(std::string name, int price) {
        this->name = name;
        this->price = price;
    }

    bool operator>(const Product &other_product) {
        if (this->price != other_product.price) {
            return this->price > other_product.price;
        }

        return this->name > other_product.name;
    }

    std::string get_name() const {
        return this->name;
    }
};

void insertion_sort(std::vector<Product> &products) {
    for (int i {0}; i < int(products.size()); ++i) {
        Product key {products.at(i)};
        int j {i - 1};

        while (j >= 0 && products.at(j) > key) {
            products.at(j + 1) = products.at(j);

            --j;
        }

        products.at(j + 1) = key;
    }
}

void get_products(std::vector<Product> &container, int size) {
    for (int i {0}; i < size; ++i) {
        std::string name;
        int price;

        std::cin >> name >> price;

        container.emplace_back(name, price);
    }

    insertion_sort(container);
}

int main() {
    std::vector<Product> products_one, products_two;
    int n, m, p, q;

    std::cin >> n >> m >> p >> q;

    get_products(products_one, n);
    get_products(products_two, m);

    std::vector<Product> answer;

    for (int i {0}; i < p; ++i) {
        answer.push_back(products_one.at(i));
    }

    for (int i {0}; i < q; ++i) {
        answer.push_back(products_two.at(i));
    }

    insertion_sort(answer);

    int count {0};
    
    for (const Product &product : answer) {
        if (count++ > 0) {
            std::cout << " ";
        }

        std::cout << product.get_name();
    }

    std::cout << std::endl;

    return 0;
}