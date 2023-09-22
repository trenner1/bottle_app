#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

/**
 * @brief Represents the size of a beer container.
 */
class ContainerSize {
private:
    bool isMetric; // true for metric (ml), false for non-metric (fl oz)
    int size;      // size in ml (if metric) or fl oz (if non-metric)

public:
    /**
     * @brief Constructor for ContainerSize.
     * @param isMetric True for metric (ml), false for non-metric (fl oz).
     * @param size The size of the container.
     */
    ContainerSize(bool isMetric, int size) : isMetric(isMetric), size(size) {}

    /**
     * @brief Get whether the size is in metric units (ml).
     * @return True if the size is in metric units, false otherwise.
     */
    bool getIsMetric() const {
        return isMetric;
    }

    /**
     * @brief Get the size of the container.
     * @return The size of the container in ml (if metric) or fl oz (if non-metric).
     */
    int getSize() const {
        return size;
    }

    /**
     * @brief Get the size with appropriate units (default to metric).
     * @return A string representation of the size with units.
     */
    std::string getSizeWithUnits() const {
        if (isMetric) {
            return std::to_string(size) + " ml";
        } else {
            // Convert non-metric (fl oz) to metric (ml)
            double mlSize = size * 29.5735; // 1 fl oz = 29.5735 ml
            return std::to_string(static_cast<int>(mlSize)) + " ml (Converted from " + std::to_string(size) + " fl oz)";
        }
    }

    /**
     * @brief Set the units to metric or non-metric.
     * @param metric True to set the units to metric (ml), false for non-metric (fl oz).
     */
    void setIsMetric(bool metric) {
        isMetric = metric;
    }

    /**
     * @brief Set the size of the container (with optional conversion).
     * @param newSize The new size of the container.
     * @param convertToMetric True to convert to metric units (ml) if not already metric (fl oz).
     */
    void setSize(int newSize, bool convertToMetric = false) {
        size = newSize;
        if (convertToMetric && !isMetric) {
            // Convert non-metric (fl oz) to metric (ml)
            double mlSize = size * 29.5735; // 1 fl oz = 29.5735 ml
            size = static_cast<int>(mlSize);
            isMetric = true;
        }
    }
};

/**
 * @brief Represents a barcode associated with a beer.
 */
class Barcode {
private:
    int value;

public:
    /**
     * @brief Constructor for Barcode.
     * @param barcodeValue The barcode value.
     */
    Barcode(int barcodeValue) : value(barcodeValue) {}

    /**
     * @brief Get the barcode value.
     * @return The barcode value.
     */
    int getValue() const {
        return value;
    }

    /**
     * @brief Set the barcode value.
     * @param newValue The new barcode value.
     */
    void setValue(int newValue) {
        value = newValue;
    }
};

/**
 * @brief Represents a beer with various attributes.
 */
class Beer {
private:
    std::string style;
    std::string name;
    double alcoholContent;
    ContainerSize containerSize; // Represents bottle size
    int quantity;
    Barcode barcode;
    std::string updatedDate; // Date when the beer was last updated

public:
    /**
     * @brief Constructor for Beer.
     * @param style The style of the beer.
     * @param name The name of the beer.
     * @param alcoholContent The alcohol content of the beer (percentage).
     * @param containerSize The container size of the beer.
     * @param quantity The quantity of the beer.
     * @param barcodeValue The barcode value associated with the beer.
     */
    Beer(const std::string& style, const std::string& name, double alcoholContent, const ContainerSize& containerSize, int quantity, int barcodeValue)
        : style(style), name(name), alcoholContent(alcoholContent), containerSize(containerSize), quantity(quantity), barcode(barcodeValue) {
        // Initialize the updated date with the current date and time
        updateDate();
    }

    /**
     * @brief Get the style of the beer.
     * @return The style of the beer.
     */
    std::string getStyle() const {
        return style;
    }

    /**
     * @brief Get the name of the beer.
     * @return The name of the beer.
     */
    std::string getName() const {
        return name;
    }

    /**
     * @brief Get the alcohol content of the beer.
     * @return The alcohol content of the beer (percentage).
     */
    double getAlcoholContent() const {
        return alcoholContent;
    }

    /**
     * @brief Get the container size of the beer.
     * @return The container size of the beer.
     */
    const ContainerSize& getContainerSize() const {
        return containerSize;
    }

    /**
     * @brief Get the quantity of the beer.
     * @return The quantity of the beer.
     */
    int getQuantity() const {
        return quantity;
    }

    /**
     * @brief Get the barcode associated with the beer.
     * @return The barcode associated with the beer.
     */
    const Barcode& getBarcode() const {
        return barcode;
    }

    /**
     * @brief Get the date when the beer was last updated.
     * @return The updated date.
     */
    std::string getUpdatedDate() const {
        return updatedDate;
    }

    /**
     * @brief Set the style of the beer.
     * @param newStyle The new style of the beer.
     */
    void setStyle(const std::string& newStyle) {
        style = newStyle;
    }

    /**
     * @brief Set the name of the beer.
     * @param newName The new name of the beer.
     */
    void setName(const std::string& newName) {
        name = newName;
    }

    /**
     * @brief Set the alcohol content of the beer.
     * @param newAlcoholContent The new alcohol content of the beer (percentage).
     */
    void setAlcoholContent(double newAlcoholContent) {
        alcoholContent = newAlcoholContent;
    }

    /**
     * @brief Set the container size of the beer.
     * @param newSize The new container size of the beer.
     */
    void setContainerSize(const ContainerSize& newSize) {
        containerSize = newSize;
    }

    /**
     * @brief Set the quantity of the beer.
     * @param newQuantity The new quantity of the beer.
     */
    void setQuantity(int newQuantity) {
        quantity = newQuantity;
    }

    /**
     * @brief Update the date to the current date and time.
     */
    void updateDate() {
        std::time_t currentTime = std::time(nullptr);
        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&currentTime));
        updatedDate = buffer;
    }
};

/**
 * @brief Represents a breakage handling class.
 */
class Breakage {
private:
    int totalBreakage;

public:
    /**
     * @brief Constructor for Breakage.
     */
    Breakage() : totalBreakage(0) {}

    /**
     * @brief Get the total breakage count.
     * @return The total breakage count.
     */
    int getTotalBreakage() const {
        return totalBreakage;
    }

    /**
     * @brief Set the total breakage count.
     * @param newTotalBreakage The new total breakage count.
     */
    void setTotalBreakage(int newTotalBreakage) {
        totalBreakage = newTotalBreakage;
    }

    /**
     * @brief Increment the total breakage count by a specified amount.
     * @param amount The amount to increment by.
     */
    void incrementTotalBreakage(int amount) {
        totalBreakage += amount;
    }
};

/**
 * @brief Represents a beer inventory management application.
 */
class BottleApp {
private:
    bool isBreakageFlagged;
    std::vector<Beer> beers; // Vector to store added beers
    std::map<std::string, int> beerCounts; // Map to store counts of each beer type
    std::vector<std::pair<std::string, int>> flaggedBeers; // Vector to store flagged beers and their quantities
    Breakage breakage; // Breakage handling

public:
    /**
     * @brief Constructor for BottleApp.
     */
    BottleApp() : isBreakageFlagged(false) {}

    /**
     * @brief Add beer to the stock.
     * @param beer The beer to add.
     */
    void addBeer(const Beer& beer) {
        if (beer.getQuantity() <= 0) {
            std::cout << "Invalid quantity. Please enter a positive value." << std::endl;
            return;
        }

        std::string beerName = beer.getName();
        int quantity = beer.getQuantity();

        // Update the total count for this beer type
        beerCounts[beerName] += quantity;

        // Update the total count of all beers
        beerCounts["Total"] += quantity;

        std::cout << quantity << " bottles of " << beerName << " added to stock." << std::endl;

        // Store the added beer in the vector
        beers.push_back(beer);

        // Update the date when the beer was added
        beers.back().updateDate();

        if (isBreakageFlagged) {
            std::cout << "Breakage has been flagged while adding beer." << std::endl;
            // Store the flagged beer and its quantity
            flaggedBeers.push_back(std::make_pair(beerName, quantity));
            // Increment total breakage
            breakage.incrementTotalBreakage(quantity);
        }
    }

    /**
     * @brief Flag breakage while adding beer.
     */
    void flagBreakage() {
        isBreakageFlagged = true;
    }

    /**
     * @brief Remove beer from the stock.
     * @param amount The amount of beer to remove.
     */
    void removeBeer(int amount) {
        if (amount <= 0) {
            std::cout << "Invalid amount. Please enter a positive value." << std::endl;
            return;
        }

        std::string beerName = "Total"; // Default to total count

        // Find the beer with the largest quantity available
        for (const auto& beer : beers) {
            if (beer.getQuantity() >= amount && beerCounts[beer.getName()] >= amount) {
                beerName = beer.getName();
                break;
            }
        }

        if (beerCounts[beerName] >= amount) {
            beerCounts[beerName] -= amount;
            std::cout << amount << " bottles of " << beerName << " removed from stock." << std::endl;

            // Update the date when the beer was removed
            for (Beer& beer : beers) {
                if (beer.getName() == beerName) {
                    beer.updateDate();
                    break;
                }
            }
        } else {
            std::cout << "Not enough " << beerName << " in stock to remove " << amount << " bottles." << std::endl;
        }

        if (isBreakageFlagged) {
            std::cout << "Breakage has been flagged while removing beer." << std::endl;
        }
    }

    /**
     * @brief Display details of all added beers.
     */
    void displayAddedBeers() const {
        std::cout << "List of added beers:" << std::endl;
        for (const Beer& beer : beers) {
            std::cout << "Name: " << beer.getName() << std::endl;
            std::cout << "Style: " << beer.getStyle() << std::endl;
            std::cout << "Alcohol Content: " << beer.getAlcoholContent() << "%" << std::endl;
            std::cout << "Container Size: " << beer.getContainerSize().getSizeWithUnits() << std::endl;
            std::cout << "Quantity: " << beer.getQuantity() << " bottles" << std::endl;
            std::cout << "Barcode: " << beer.getBarcode().getValue() << std::endl;
            std::cout << "Updated Date: " << beer.getUpdatedDate() << std::endl;
            std::cout << "-----------------------" << std::endl;
        }
    }

    /**
     * @brief Display details of flagged beers.
     */
    void displayFlaggedBeers() const {
        if (flaggedBeers.empty()) {
            std::cout << "No beers flagged for breakage." << std::endl;
        } else {
            std::cout << "List of flagged beers for breakage:" << std::endl;
            for (const auto& flaggedBeer : flaggedBeers) {
                std::cout << "Name: " << flaggedBeer.first << std::endl;
                std::cout << "Quantity: " << flaggedBeer.second << " bottles" << std::endl;
                std::cout << "-----------------------" << std::endl;
            }
        }
    }

    /**
     * @brief Display the total count of each beer type.
     */
    void displayTotalCounts() const {
        std::cout << "Total counts of each beer type:" << std::endl;
        for (const auto& entry : beerCounts) {
            std::cout << entry.first << ": " << entry.second << " bottles" << std::endl;
        }
    }

    /**
     * @brief Edit beer details.
     * @param beerName The name of the beer to edit.
     */
    void editBeer(const std::string& beerName) {
        for (Beer& beer : beers) {
            if (beer.getName() == beerName) {
                std::string newName, newStyle;
                double newAlcoholContent;
                ContainerSize newContainerSize = beer.getContainerSize();
                int newQuantity, newBarcode;

                std::cout << "Enter new name for the beer: ";
                std::cin >> newName;
                beer.setName(newName);

                std::cout << "Enter new style for the beer: ";
                std::cin >> newStyle;
                beer.setStyle(newStyle);

                std::cout << "Enter new alcohol content for the beer (%): ";
                std::cin >> newAlcoholContent;
                beer.setAlcoholContent(newAlcoholContent);

                std::cout << "Enter new container size for the beer (size in ml for metric, fl oz for non-metric): ";
                int newSize;
                std::cin >> newSize;
                newContainerSize.setSize(newSize, newContainerSize.getIsMetric());

                std::cout << "Is the new container size metric (1 for yes, 0 for no): ";
                bool isMetric;
                std::cin >> isMetric;
                newContainerSize.setIsMetric(isMetric);

                beer.setContainerSize(newContainerSize);

                std::cout << "Enter new quantity for the beer: ";
                std::cin >> newQuantity;
                beer.setQuantity(newQuantity);

                std::cout << "Beer details updated." << std::endl;
                return;
            }
        }

        std::cout << "Beer with name '" << beerName << "' not found." << std::endl;
    }

    /**
     * @brief Get the total count of all beers.
     * @return The total count of all beers.
     */
    int getTotalBottleCount() const {
        return beerCounts.at("Total");
    }
};

int main() {
    BottleApp app;

    // Flag breakage
    app.flagBreakage();

    // Add some beer
    ContainerSize containerSize1(true, 355); // Metric (ml)
    Beer beer1("IPA", "Example IPA", 6.5, containerSize1, 24, 123456);
    app.addBeer(beer1);

    // Add more beer
    ContainerSize containerSize2(false, 12); // Non-metric (fl oz)
    Beer beer2("Stout", "Sample Stout", 7.0, containerSize2, 12, 789012);
    app.addBeer(beer2);

    // Display added beers
    app.displayAddedBeers();

    // Display flagged beers
    app.displayFlaggedBeers();

    // Display the total count of each beer type
    app.displayTotalCounts();

    // Edit beer details
    app.editBeer("Example IPA");

    // Check the total beer count
    std::cout << "Total beer count in stock: " << app.getTotalBottleCount() << " bottles." << std::endl;

    return 0;
}