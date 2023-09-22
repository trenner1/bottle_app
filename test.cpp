#include <iostream>
#include "main.cpp" // Include the main.cpp code with the classes

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
