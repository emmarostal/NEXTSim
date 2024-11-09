#include <TFile.h>
#include <TTree.h>
#include <TGraph2D.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <iostream>
#include <vector>

#include <TFile.h>
#include <TTree.h>
#include <TGraph2D.h>
#include <TCanvas.h>
#include <vector>
#include <iostream>

#include <TFile.h>
#include <TTree.h>
#include <TGraph2D.h>
#include <TCanvas.h>
#include <vector>
#include <iostream>


void drawPath(const char* filename) {
    
    // Open the file and retrieve the tree
    TFile *file = TFile::Open(filename);
    if (!file || !file->IsOpen()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    TTree *tree = nullptr;
    file->GetObject("data", tree);
    if (!tree) {
        std::cerr << "Error: Tree 'data' not found in file!" << std::endl;
        file->Close();
        return;
    }

    // Define branches to hold data
    std::vector<double> *nScatterX = nullptr;
    std::vector<double> *nScatterY = nullptr;
    std::vector<double> *nScatterZ = nullptr;
    int eventID = -1;

    // Set branch addresses
    tree->SetBranchAddress("nScatterX", &nScatterX);
    tree->SetBranchAddress("nScatterY", &nScatterY);
    tree->SetBranchAddress("nScatterZ", &nScatterZ);
    tree->SetBranchAddress("eventID", &eventID);

    // Debug: Check branch setup
    if (!nScatterX || !nScatterY || !nScatterZ) {
        std::cerr << "Error: Branches not initialized correctly." << std::endl;
        file->Close();
        return;
    }

    for (int i = 0; i < tree->GetEntries(); ++i) {
        tree->GetEntry(i);

        // Ensure the vectors are valid and populated
        if (nScatterX && nScatterY && nScatterZ) {
            std::cout << "Entry " << i << ": Event ID = " << eventID << std::endl;
            std::cout << "nScatterX size: " << nScatterX->size() << std::endl;
            std::cout << "nScatterY size: " << nScatterY->size() << std::endl;
            std::cout << "nScatterZ size: " << nScatterZ->size() << std::endl;
        } else {
            std::cerr << "Warning: One of the vectors is null at entry " << i << std::endl;
            continue;
        }
    }

    // Clean up
    file->Close();
    delete file;
}


void testBranchAccess(const char* filename) {
    TFile *file = TFile::Open(filename);
    if (!file || !file->IsOpen()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    TTree *tree = nullptr;
    file->GetObject("data", tree);
    if (!tree) {
        std::cerr << "Error: Tree 'data' not found in file!" << std::endl;
        file->Close();
        return;
    }

    std::vector<double> *nScatterX = nullptr;
    tree->SetBranchAddress("nScatterX", &nScatterX);

    if (!nScatterX) {
        std::cerr << "Error: Failed to initialize branch 'nScatterX'." << std::endl;
        file->Close();
        return;
    }

    // Try reading the first entry to see if data is loaded
    tree->GetEntry(0);
    if (nScatterX) {
        std::cout << "nScatterX size for first entry: " << nScatterX->size() << std::endl;
    } else {
        std::cerr << "nScatterX pointer is null after GetEntry." << std::endl;
    }

    file->Close();
    delete file;
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename.root>" << std::endl;
        return 1;
    }
    gInterpreter->GenerateDictionary("vector<double>", "vector");


    testBranchAccess(argv[1]);
    return 0;
}






