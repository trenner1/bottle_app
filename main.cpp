#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime> // For handling dates and times

/**
 * @brief Represents the size of a beer container, either metric (ml) or non-metric (fl oz).
 */
class ContainerSize {
private:
    bool isMetric; // true for metric (ml), false for non-metric (fl oz)
    int size;      // size in ml (if metric) or fl oz (if non-metric)

public:
    /**
     * @brief Constructor for ContainerSize.
     * @param isMetric True for metric size (ml), false for non-metric size (fl oz).
     * @param size The size value.
     */
    ContainerSize(bool isMetric, int size) : isMetric(isMetric), size(size) {}

    /**
     * @brief Get whether the size is in metric units (ml).
     * @return True if metric, false if non-metric.
     */
    bool getIsMetric() const {
        return isMetric;
    }

    /**
     * @brief Get the size value.
     * @return Size in ml (if metric) or fl oz (if non-metric).
     */
    int getSize() const {
        return size;
    }

    /**
     * @brief Get the size with appropriate units (default to metric).
     * @return Size as a string with units (ml or converted from fl oz).
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
     * @brief Set whether the size is in metric units (ml).
     * @param metric True for metric, false for non-metric.
     */
    void setIsMetric(bool metric) {
        isMetric = metric;
    }

    /**
     * @brief Set the size (with optional conversion).
     * @param newSize The new size value.
     * @param convertToMetric Whether to convert non-metric to metric units.
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
 * @brief Represents a barcode for a beer bottle.
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
 * @brief Represents a beer in the inventory.
 */
class Beer {
private:
    std::string style;             // Style of the beer
    std::string name;              // Name of the beer
    double alcoholContent;         // Alcohol content of the beer (%)
    ContainerSize containerSize;   // Represents bottle size
    int quantity;                  // Quantity of bottles in stock
    Barcode barcode;               // Barcode for the beer
    std::string updatedDate;       // Last updated date

public:
    /**
     * @brief Constructor for Beer.
     * @param style Style of the beer.
     * @param name Name of the beer.
     * @param alcoholContent Alcohol content of the beer (%).
     * @param containerSize Container size (metric or non-metric).
     * @param quantity Quantity of bottles in stock.
     * @param barcodeValue Barcode value for the beer.
     */
    Beer(const std::string& style, const std::string& name, double alcoholContent,
         const ContainerSize& containerSize, int quantity, int barcodeValue)
        : style(style), name(name), alcoholContent(alcoholContent),
          containerSize(containerSize), quantity(quantity), barcode(barcodeValue) {
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
     * @return The alcohol content of the beer (%).
     */
    double getAlcoholContent() const {
        return alcoholContent;
    }

    /**
     * @brief Get the container size of the beer.
     * @return The container size object.
     */
    const ContainerSize& getContainerSize() const {
        return containerSize;
    }

    /**
     * @brief Get the quantity of bottles in stock.
     * @return The quantity of bottles in stock.
     */
    int getQuantity() const {
        return quantity;
    }

    /**
     * @brief Get the barcode for the beer.
     * @return The barcode object.
     */
    const Barcode& getBarcode() const {
        return barcode;
    }

    /**
     * @brief Get the last updated date.
     * @return The last updated date as a string.
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
     * @param newAlcoholContent The new alcohol content of the beer (%).
     */
    void setAlcoholContent(double newAlcoholContent) {
        alcoholContent = newAlcoholContent;
    }

    /**
     * @brief Set the container size of the beer.
     * @param newSize The new size of the container.
     * @param convertToMetric Whether to convert non-metric to metric units.
     */
    void setContainerSize(const ContainerSize& newSize) {
        containerSize = newSize;
    }

    /**
     * @brief Set the quantity of bottles in stock.
     * @param newQuantity The new quantity of bottles in stock.
     */
    void setQuantity(int newQuantity) {
        quantity = newQuantity;
    }

    /**
     * @brief Set the barcode for the beer.
     * @param newBarcode The new barcode value.
     */
    void setBarcode(int newBarcode) {
        barcode.setValue(newBarcode);
    }

    /**
     * @brief Update the last updated date to the current date and time.
     */
    void updateDate() {
        std::time_t currentTime = std::time(nullptr);
        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&currentTime));
        updatedDate = buffer;
    }
};

/**
 * @brief Represents a breakage record, tracking the total breakage quantity.
 */
class Breakage {
private:
    int totalBreakage; // Total quantity of breakage

public:
    /**
     * @brief Constructor for Breakage.
     */
    Breakage() : totalBreakage(0) {}

    /**
     * @brief Get the total quantity of breakage.
     * @return The total quantity of breakage.
     */
    int getTotalBreakage() const {
        return totalBreakage;
    }

    /**
     * @brief Set the total quantity of breakage.
     * @param newTotalBreakage The new total quantity of breakage.
     */
    void setTotalBreakage(int newTotalBreakage) {
        totalBreakage = newTotalBreakage;
    }

    /**
     * @brief Increment the total quantity of breakage.
     * @param amount The amount to increment.
     */
    void incrementTotalBreakage(int amount) {
        totalBreakage += amount;
    }
};

/**
 * @brief Represents the "BOTTLE" app for managing beer inventory.
 */
class BottleApp {
private:
    bool isBreakageFlagged;                    // Flag for breakage
    std::vector<Beer> beers;                   // Vector to store added beers
    std::map<std::string, int> beerCounts;     // Map to store counts of each beer type
    std::vector<std::pair<std::string, int> > flaggedBeers; // Vector to store flagged beers and their quantities
    Breakage breakage;                         // Breakage handling

public:
    /**
     * @brief Constructor for BottleApp.
     */
    BottleApp() : isBreakageFlagged(false) {}

    /**
     * @brief Add beer to the stock.
     * @param beer The Beer object to add.
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
            std::cout << "Last Updated Date: " << beer.getUpdatedDate() << std::endl;
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
     * @brief Edit the details of a specific beer.
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

                std::cout << "Enter new barcode for the beer: ";
                std::cin >> newBarcode;
                beer.setBarcode(newBarcode);

                std::cout << "Beer details updated." << std::endl;
                return;
            }
        }

        std::cout << "Beer with name '" << beerName << "' not found." << std::endl;
    }

    /**
     * @brief Get the total beer count in stock.
     * @return The total beer count in stock.
     */
    int getTotalBottleCount() const {
        return beerCounts.at("Total");
    }
};

int main() {
    BottleApp app;

    // Keep running until the user requests to exit
    bool exitRequested = false;
    while (!exitRequested) {
        std::cout << "\nBOTTLE - Beer Inventory Management" << std::endl;
        std::cout << "1. Add Beer" << std::endl;
        std::cout << "2. Remove Beer" << std::endl;
        std::cout << "3. Display Added Beers" << std::endl;
        std::cout << "4. Display Flagged Beers" << std::endl;
        std::cout << "5. Display Total Counts" << std::endl;
        std::cout << "6. Edit Beer Details" << std::endl;
        std::cout << "7. Get Total Beer Count" << std::endl;
        std::cout << "8. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Add Beer
                ContainerSize containerSize(true, 0); // Initialize with metric (ml)
                std::string style, name;
                double alcoholContent;
                int quantity, barcodeValue;

                std::cout << "Enter style of the beer: ";
                std::cin >> style;

                // Clear any remaining characters from the input buffer, including the newline character
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Enter name of the beer: ";
                std::cin >> name;

                // Clear any remaining characters from the input buffer, including the newline character
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Enter alcohol content of the beer (%): ";
                std::cin >> alcoholContent;

                std::cout << "Enter container size for the beer (size in ml for metric, fl oz for non-metric): ";
                int newSize;
                std::cin >> newSize;
                containerSize.setSize(newSize);

                std::cout << "Is the container size metric (1 for yes, 0 for no): ";
                bool isMetric;
                std::cin >> isMetric;
                containerSize.setIsMetric(isMetric);

                std::cout << "Enter quantity of bottles to add: ";
                std::cin >> quantity;

                std::cout << "Enter barcode for the beer: ";
                std::cin >> barcodeValue;

                // Clear the input buffer
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                Beer newBeer(style, name, alcoholContent, containerSize, quantity, barcodeValue);
                app.addBeer(newBeer);
                break;
            }
            case 2: {
                // Remove Beer
                int amount;
                std::cout << "Enter the quantity of beer bottles to remove: ";
                std::cin >> amount;
                app.removeBeer(amount);
                break;
            }
            case 3:
                // Display Added Beers
                app.displayAddedBeers();
                break;
            case 4:
                // Display Flagged Beers
                app.displayFlaggedBeers();
                break;
            case 5:
                // Display Total Counts
                app.displayTotalCounts();
                break;
            case 6: {
                // Edit Beer Details
                std::string beerNameToEdit;
                std::cout << "Enter the name of the beer to edit: ";
                std::cin >> beerNameToEdit;
                app.editBeer(beerNameToEdit);
                break;
            }
            case 7:
                // Get Total Beer Count
                std::cout << "Total beer count in stock: " << app.getTotalBottleCount() << " bottles." << std::endl;
                break;
            case 8:
                // Exit
                exitRequested = true;
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    }

    std::cout << "Exiting BOTTLE - Beer Inventory Management. Thank you!" << std::endl;

    return 0;
}
