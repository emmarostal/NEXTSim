#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TLegend.h>
#include <set>

#include <iostream>
#include <vector>
#include </home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp>

using namespace std;

// Use command to compile:
// g++ -o drawTOF plotBarTOF.cc $(root-config --cflags --libs) -L/home/emma/Documents/TILGITHUB/build/dict -lNextSimEvent
// Use command to run:
// ./drawTOF filename.root
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

   // Define a set to track unique T1 values (nScatterTime for simplicity)
    //std::set<double> uniqueT1;
    std::set<double> uniqueT2;


void drawTOF(const char* filename) {
    // Open the ROOT file
    TFile *file = TFile::Open(filename, "READ");
    if (!file || file->IsZombie()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    // Define the tree name
    const char* treeName = "data";  
    TTree *tree = dynamic_cast<TTree*>(file->Get(treeName));
    if (!tree) {
        cerr << "Error: Could not retrieve tree " << treeName << " from file." << endl;
        file->Close();
        return;
    }

    // Set up the branch and structure
    auto eventData = new nDetEventStructure();
    auto multiOutput = new nDetMultiOutputStructure();
    tree->SetBranchAddress("output", &multiOutput);
    tree->SetBranchAddress("event", &eventData);
    double lower = 0.0;
    double upper = 400.0;

    // Create histograms for barTOFcorr values
    TH1D *hist1 = new TH1D("hist1", "First bar hit by neutron", 400, lower, upper);
    TH1D *hist2 = new TH1D("hist2", "All bars after the first hit by neutron", 400, lower, upper);
    TH1D *hist3 = new TH1D("hist3", "Second bar hit by neutron", 400, lower, upper);
    TH1D *hist4 = new TH1D("hist4", "All TOF from neutron scattering", 400, lower, upper);

    // Get the number of entries in the tree
    Long64_t nEntries = tree->GetEntries();
    

    // Loop over all entries in the tree
    for (Long64_t entry = 0; entry < nEntries; ++entry) {
    // Load the current entry into memory
    tree->GetEntry(entry);
    // Reset unique sets at the start of each entry
    uniqueT2.clear();
    //uniqueT1.clear();
    

    // Check if multiOutput contains valid data
    //if (!multiOutput || multiOutput->nScatterScint.empty()) {
        //std::cerr << "Entry " << entry << ": Invalid or empty multiOutput structure." << std::endl;
    //    continue;  // Skip invalid or empty entries
    //}

    // Debug: Print the current entry's size and content
    //std::cout << "Processing entry " << entry << " with "
    //          << multiOutput->nScatterTime.size() << " scatter times." << std::endl;

    // Variables for T1 and T2 logic
    double lowestScatterTime = -1.0;
    double firstScatterX = -9999;
    double firstScatterY = -9999;
    double firstScatterZ = -9999;


    double firstBarTOF = -1.0;
    short firstDetID = -1.0;
    bool correspondingScint = false;
    double differentTime = -1.0;
    double diffDetIDBarTOF = -1.0;
    short differentDetID = -1.0;
    bool differentScint = false;
    bool foundT1 = false;
    bool foundT2 = false;
    int index = -1;
    int T2ID = -1;

    

    // Loop backward through the nScatterTime vector
    for (size_t j = multiOutput->nScatterScint.size(); j > 0; --j) {
        size_t i = j-1;  // Adjust for 0-based indexing
        
        if  (multiOutput->multiplicity>1&& multiOutput->nScatterScint[i] && eventData->goodEvent && !foundT1){   
            lowestScatterTime = multiOutput->nScatterTime[i];
            firstScatterX = multiOutput->nScatterX[i];
            firstScatterY = multiOutput->nScatterY[i];
            firstScatterZ = multiOutput->nScatterZ[i];
            std::vector<short> numbers = multiOutput->detID;

            short detectorID = findDetector(firstScatterX, firstScatterY, firstScatterZ, detectors);

            if(detectorID>-1){
            

            // Use std::find to search for the number in the vector
            auto it = std::find(numbers.begin(), numbers.end(), detectorID);

            if (it != numbers.end()) {
                // If found, calculate the index
                index = std::distance(numbers.begin(), it);
                std::cout << "Detector number " << detectorID << " found at index " << index << std::endl;
            } else {
                // If not found
                std::cout << "Detector number " << detectorID << " not found in the vector." << std::endl;
            }

            firstBarTOF = multiOutput->barTOFcorr[index];
            firstDetID = multiOutput->detID[index];
            hist4->Fill(firstBarTOF);
            hist1->Fill(firstBarTOF);
            foundT1 = true;
            //continue;
            }   
        }
        
            //Add TOF values to T2
            //for (const auto& l : otherIndices) {
            //    hist4->Fill(multiOutput->barTOFcorr[l]);
            //    hist2->Fill(multiOutput->barTOFcorr[l]);
            //}
            // Add T2 to the uniqueT2 set to prevent duplicate processing
            //if (T2ID!=-1){
            //uniqueT2.insert(T2ID);
            //}



            
            //if(diffDetIDBarTOF>89 && diffDetIDBarTOF<90){
            //    std::cout <<"Entry: "<< entry <<", TOF: "<< multiOutput->barTOFcorr[index] <<" ID: "<< differentDetID <<", Time: "<< differentTime<<", initE: " << eventData->nInitEnergy<< " EventID: "<< eventData->eventID<< std::endl;
            //}
            //std::cout << "T2: " << differentTime << ", TOF: " << diffDetIDBarTOF
            //              << ", detID: " << differentDetID << ", Scint: " << correspondingScint << std::endl;
            //if(!foundT2){
            //    hist3->Fill(diffDetIDBarTOF);
            //    foundT2 = true;
            //}
            //hist2->Fill(diffDetIDBarTOF);
            

       }
       if (foundT1 && multiOutput->multiplicity>1 && index>-1) {
            
            // add all other TOF values to T2:

            // Vector to store other indices
            //std::vector<size_t> otherIndices;

            //Index to be skipped (first scatter)
            short excludeID = index;

            // Loop through the TOF vector
            for (size_t k = 0; k < multiOutput->barTOFcorr.size(); ++k) {
                if (k==excludeID){
                    continue;
                }
                if (multiOutput->detID[k]!=firstDetID) {
                    //otherIndices.push_back(k);
                    T2ID = multiOutput->detID[k];
                    if (uniqueT2.find(T2ID) != uniqueT2.end() || T2ID<0) {
                    continue;  // Skip to the next entry if T1 is not unique or detector is not found
                    }
                    std::cout << "More Scattering found at index " << k << " detID:" << T2ID <<std::endl;
                    hist2->Fill(multiOutput->barTOFcorr[k]);
                    hist4->Fill(multiOutput->barTOFcorr[k]);
                    if (T2ID>-1){
                        //Check if this T2 has already been processed
                    uniqueT2.insert(T2ID);
                    }
                }
            }

            

            
        // Break early if both T1 and T2 are found
        //if (foundT1 && foundT2) break;
    }


    // Warn if T2 is not found
    //if (foundT1 && !foundT2 && multiOutput->nScatterTime.size()>1) {
        //std::cout << "Warning: No valid T2 found for T1: " << lowestTime
        //          << ", TOF: " << correspondingBarTOF << ", detID: " << correspondingDet << std::endl;
    //}
    
}
//}


    // Create a canvas for the histograms
    TCanvas *canvas = new TCanvas("canvas", "barTOF Histogram Comparison", 1400, 800);
    // Draw both histograms on the same canvas

    // Set axis labels and title
    hist1->GetXaxis()->SetTitle("barTOFcorr (ns)");
    hist1->GetYaxis()->SetTitle("Counts");
    hist1->SetTitle("Distribution of barTOFcorr values");
    
    hist4->SetFillColor(kBlack - 10);
    hist4->SetLineColor(kBlack);
    hist4->SetLineWidth(2);
    hist4->Draw("");
    
    hist1->SetFillColorAlpha(kBlue, 0.2);
    hist1->SetLineColor(kBlue);
    hist1->SetLineWidth(2);
    hist1->Draw("SAME");

    

    

    hist2->SetFillColorAlpha(kRed, 0.2);
    hist2->SetLineColor(kRed);
    hist2->SetLineWidth(2);
    hist2->Draw("SAME");

    //hist3->SetFillColor(kGreen - 10);
    //hist3->SetLineColor(kGreen);
    //hist3->SetLineWidth(2);
    //hist3->Draw("SAME");

    
    

    // Add a legend
    TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend->AddEntry(hist4, "All TOF from neutron Scattering with multiplicity>1");
    legend->AddEntry(hist1, "First bar hit by neutron", "f");
    legend->AddEntry(hist2, "All subsequent bars fired", "f");
    //legend->AddEntry(hist3, "Second bar hit by neutron", "f");
    
    legend->Draw();

    // Save the histogram as an image
    canvas->SaveAs("barTOFcorr_histogram_comparison.png");

    // Cleanup
    delete canvas;  // Explicitly delete the canvas to avoid memory issues
    delete hist1;    // Explicitly delete the histogram
    delete hist2;    // Explicitly delete the histogram
    delete hist3;
    delete hist4;
    file->Close();
    delete file;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename.root>" << endl;
        return 1;
    }

    // Get the filename from the first argument
    const char* filename = argv[1];

    // Call the drawTOF function with the filename
    drawTOF(filename);

    return 0;
}
