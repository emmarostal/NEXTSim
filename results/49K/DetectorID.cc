#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TLegend.h>
#include <set>
#include <TH2D.h> 
#include <map>

#include <iostream>
#include <vector>
#include </home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp>

using namespace std;

// Use command to compile:
// g++ -o getID DetectorID.cc $(root-config --cflags --libs) -L/home/emma/Documents/TILGITHUB/build/dict -lNextSimEvent
// Use command to run:
// ./getID filename.root
#include <vector>
#include <iostream>

// Define a struct to represent a detector's boundaries
struct Detector {
    short id;             // Detector ID
    double xMin, xMax;  // x boundaries
    double yMin, yMax;  // y boundaries
    double zMin, zMax;  // z boundaries

    // Function to check if a point is inside the detector
    bool contains(double x, double y, double z) const {
        return (x >= xMin && x <= xMax &&
                y >= yMin && y <= yMax &&
                z >= zMin && z <= zMax);
    }
};

// Function to find which detector contains the point
short findDetector(double x, double y, double z, const std::vector<Detector>& detectors) {
    for (const auto& detector : detectors) {
        if (detector.contains(x, y, z)) {
            return detector.id; // Return the ID of the detector
        }
    }
    return -1; // Return -1 if no detector contains the point
}

std::vector<Detector> detectors = {
        {0, -600.0, 600.0, 740.0, 805.0, 665.0, 725.0},
        {1, -600.0, 600.0, 697.0, 760.0, 715.0, 780.0},
        {2, -600.0, 600.0, 650.0, 710.0, 765.0, 825.0},
        {3, -600.0, 600.0, 580.0, 640.0, 825.0, 885.0},
        {4, -600.0, 600.0, 520.0, 585.0, 865.0, 925.0},
        {5, -600.0, 600.0, 460.0, 520.0, 900.0, 960.0},
        {6, -600.0, 600.0, 395.0, 450.0, 935.0, 990.0},
        {7, -600.0, 600.0, 315.0, 375.0, 970.0, 1025.0},
        {8, -600.0, 600.0, 250.0, 310.0, 995.0, 1045.0},
        {9, -600.0, 600.0, 180.0, 240.0, 1010.0, 1055.0},
        {10, -600.0, 600.0, 110.0, 165.0, 1025.0, 1070.0},
        {11, -600.0, 600.0, 20.0, 75.0, 1040.0, 1076.0},
        {12, -600.0, 600.0, -40.0, 15.0, 1040.0, 1076.0},
        {13, -600.0, 600.0, -130.0, -75.0, 1035.0, 1075.0},
        {14, -600.0, 600.0, -205.0, -145.0, 1025.0, 1066.0},
        {15, -600.0, 600.0, -275.0, -215.0, 1010.0, 1055.0},
        {16, -600.0, 600.0, -345.0, -280.0, 988.0, 1035.0},
        {17, -600.0, 600.0, -430.0, -370.0, 950.0, 1005.0},
        {18, -600.0, 600.0, -495.0, -435.0, 922.0, 975.0},
        {19, -600.0, 600.0, -560.0, -500.0, 885.0, 940.0},
        {20, -600.0, 600.0, -620.0, -560.0, 848.0, 905.0},
    };



std::vector<std::tuple<Int_t, short, double, double>> getID(const char* filename) {
    // Open the ROOT file
    TFile *file = TFile::Open(filename, "READ");
    if (!file || file->IsZombie()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return {}; // Return empty vector on error
    }

    // Define the tree name
    const char* treeName = "data";  
    TTree *tree = dynamic_cast<TTree*>(file->Get(treeName));
    if (!tree) {
        std::cerr << "Error: Could not retrieve tree " << treeName << " from file." << std::endl;
        file->Close();
        return {}; // Return empty vector on error
    }

    // Set up the branch and structure
    auto eventData = new nDetEventStructure();
    auto multiOutput = new nDetMultiOutputStructure();
    tree->SetBranchAddress("output", &multiOutput);
    tree->SetBranchAddress("event", &eventData);

    // Get the number of entries in the tree
    Long64_t nEntries = tree->GetEntries();

    // Vector to store the results
    std::vector<std::tuple<int, short, double, double>> detIDScatterTimeTOF;

    // Loop over all entries in the tree
    for (Long64_t entry = 0; entry < nEntries; ++entry) {
        // Load the current entry into memory
        tree->GetEntry(entry);

        double ScatterTime = -1.0;
        double ScatterX = -9999;
        double ScatterY = -9999;
        double ScatterZ = -9999;
        double BarTOF = -1.0;
        short DetID = -1;
        int eventID = eventData->eventID;
        int index = -1;

        // Loop backward through the nScatterTime vector
        for (size_t j = multiOutput->nScatterScint.size(); j > 0; --j) {
            size_t i = j - 1;  // Adjust for 0-based indexing

            if (multiOutput->multiplicity > 1 && multiOutput->nScatterScint[i] && eventData->goodEvent) {
                ScatterTime = multiOutput->nScatterTime[i];
                ScatterX = multiOutput->nScatterX[i];
                ScatterY = multiOutput->nScatterY[i];
                ScatterZ = multiOutput->nScatterZ[i];
                std::vector<short> numbers = multiOutput->detID;

                short detectorID = findDetector(ScatterX, ScatterY, ScatterZ, detectors);

                if (detectorID > -1) {
                    // Use std::find to search for the number in the vector
                    auto it = std::find(numbers.begin(), numbers.end(), detectorID);

                    if (it != numbers.end()) {
                        // If found, calculate the index
                        int index = std::distance(numbers.begin(), it);
                        BarTOF = multiOutput->barTOFcorr[index];
                        DetID = multiOutput->detID[index];

                        // Add the data to the vector
                        detIDScatterTimeTOF.emplace_back(eventID, DetID, ScatterTime, BarTOF);
                        //std::cout << "eventID: " << eventID << " detID: "<<DetID <<std::endl;
                        //std::cout << "Detector number " << detectorID << " found at index " << index << std::endl;
                    } else {
                        // If not found
                        //std::cout << "Detector number " << detectorID << " not found in the vector." << std::endl;
                    }

                }
            }
        }
    }

    // Cleanup
    file->Close();
    delete file;

    return detIDScatterTimeTOF; // Return the filled vector
}


//Plot detector heatmap
void fillHeatmap(const std::vector<std::tuple<int, short, double, double>>& dataVector) {
    // Step 1: Define the 2D histogram
    int maxDetID = 20; // Adjust according to your detector range
    TH2D* heatmap = new TH2D("heatmap", "Detector Pair Heatmap;detID 1;detID 2",
                             maxDetID, 0, maxDetID, // X-axis: detID 1
                             maxDetID, 0, maxDetID); // Y-axis: detID 2

    // Group the data by eventID
    std::map<int, std::vector<short>> groupedData;
    for (const auto& entry : dataVector) {
        Int_t eventID = std::get<0>(entry);
        short detID = std::get<1>(entry);
        groupedData[eventID].push_back(detID);
    }

    // Step 2: Fill the histogram with data
    for (const auto& group : groupedData) {
        const auto& detIDs = group.second; // Get the vector of detIDs for this eventID
        std::cout << "Processing eventID " << group.first << ": ";
        
        for (auto detID : detIDs) {
            std::cout << detID << " ";
        }
        std::cout << std::endl;

        if (detIDs.size() >= 2) {
            short detID1 = detIDs[0]; // First detID
            short detID2 = detIDs[1]; // Second detID

            // Ensure that the two detIDs are different
            if (detID1 == detID2) {
                // If detID1 == detID2, find the next available detID that is different
                bool foundDiff = false;
                for (size_t i = 2; i < detIDs.size(); ++i) {
                    detID2 = detIDs[i];
                    if (detID1 != detID2) {
                        foundDiff = true;
                        break;
                    }
                }

                // Debugging: Print info if no different detID is found
                if (!foundDiff) {
                    std::cout << "No different detID found for eventID " << group.first << std::endl;
                }
            }

            // Fill the heatmap if detID1 and detID2 are different
            if (detID1 != detID2) {
                std::cout << "Filling heatmap with detID1: " << detID1 << ", detID2: " << detID2 << std::endl;
                heatmap->Fill(detID1, detID2); // Fill the heatmap with the pair
            }
        }
    }

    // Step 3: Set the color scale to logarithmic using SetContour
    int nContours = 300;
    Double_t contourLevels[nContours];
    for (int i = 0; i < nContours; ++i) {
        contourLevels[i] = pow(10, i / 100.0);  // Set logarithmic contour levels
    }
    gStyle->SetPalette(kRainbow);
    heatmap->SetContour(nContours, contourLevels); // Apply logarithmic contour levels

    // Step 4: Draw the heatmap with logarithmic color scale
    TCanvas* canvas = new TCanvas("canvas", "Heatmap", 950, 800);
    heatmap->Draw("COLZ"); // "COLZ" gives a color-coded 2D plot

    // Optional: Save the heatmap as an image
    canvas->SaveAs("heatmap.png");

    // Cleanup
    delete heatmap;
    delete canvas;
}




int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename.root>" << endl;
        return 1;
    }

    // Get the filename from the first argument
    const char* filename = argv[1];

    // Call getID to retrieve the data
    std::vector<std::tuple<Int_t, short, double, double>> data = getID(filename);

    std::cout << "Number of entries in data: " << data.size() << std::endl;

    // Call the fillHeatmap function with the data
    fillHeatmap(data);

    return 0;
}