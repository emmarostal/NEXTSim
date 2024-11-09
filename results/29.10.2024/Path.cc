#include <TFile.h>
#include <TTree.h>
#include <TGraph2D.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <iostream>
#include <vector>
#include <TAxis.h>
#include <TFile.h>
#include <TTree.h>
#include <TGraph2D.h>
#include <TCanvas.h>
#include <vector>
#include <iostream>
#include <cstdlib> // Include for std::atoi
#include <TFile.h>
#include <TTree.h>
#include <TGraph2D.h>
#include <TCanvas.h>
#include <vector>
#include <iostream>
#include </home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp>
using namespace std;
//use command g++ -o drawPosition Position.cc $(root-config --cflags --libs) -L/home/emma/Documents/TILGITHUB/build/dict -lNextSimEvent
// to compile
//use command ./drawPath singlebar_barTOF_test-001.root to draw energies


void drawPath(const char* filename, int entryIndex = 0) {
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
    auto outData = new nDetMultiOutputStructure();
    tree->SetBranchAddress("output", &outData);

    // Create a 3D graph to store positions
    TGraph2D *graph = new TGraph2D();
    int pointIndex = 0;  // Index for points in the TGraph2D

    // Get the number of entries in the tree
    Long64_t nEntries = tree->GetEntries();

    // Load the specified entry data into outData
    tree->GetEntry(entryIndex);

    // Ensure the vectors are populated for the chosen entry
    size_t nElements = std::min({outData->nScatterX.size(), outData->nScatterY.size(), outData->nScatterZ.size()});
    if (nElements == 0) {
        cerr << "Error: Entry " << entryIndex << " has empty vectors." << endl;
        file->Close();
        return;
    }

    // Loop over all elements in the vectors and add them to the graph
    for (size_t j = 0; j < nElements; ++j) {
        double x = outData->nScatterX[j];
        double y = outData->nScatterY[j];
        double z = outData->nScatterZ[j];

        // Add the point to the TGraph2D
        graph->SetPoint(j, z, y, x);
    }


    // Draw the 3D graph with points connected by a line
    TCanvas *canvas = new TCanvas("canvas", "3D Path Plot for Entry", 800, 600);
    gStyle->SetPalette(kRainBow);  // Set a color palette for the plot
    graph->SetTitle(Form("3D Path Plot for Entry %d;X;Y;Z", entryIndex));
    

    // Set marker style and size
    graph->SetMarkerStyle(20);  // Circle markers
    graph->SetMarkerColor(kBlack); // Marker color
    graph->SetMarkerSize(1.2);   // Marker size
    // Set line color and width
    graph->SetLineColor(kCyan);   // Change the line color (e.g., kBlue)
    graph->SetLineWidth(2);        // Change the line width (e.g., 2)
    graph->Draw("LINEP");  // "A" for axis, "L" for lines, "P" for points

    // Change axis titles
    graph->GetXaxis()->SetTitle("Z (mm)");
    graph->GetYaxis()->SetTitle("Y (mm)");
    graph->GetZaxis()->SetTitle("X (mm)");

    graph->GetXaxis()->SetLabelSize(0.03); // Change the label size for the X-axis
    graph->GetXaxis()->SetTitleSize(0.05); // Change the title size for the X-axis
    graph->GetYaxis()->SetLabelSize(0.03); // Change the label size for the Y-axis
    graph->GetYaxis()->SetTitleSize(0.05); // Change the title size for the Y-axis
    graph->GetZaxis()->SetLabelSize(0.03); // Change the label size for the Z-axis
    graph->GetZaxis()->SetTitleSize(0.05); // Change the title size for the Z-axis

    graph->GetXaxis()->SetLimits(0, 1200); // Set new limits for the X-axis
    graph->GetYaxis()->SetLimits(-700, 700); // Set new limits for the Y-axis

    

    // Show the canvas
    canvas->Update();   // Ensure the canvas is updated
    
    canvas->SaveAs("3D_Plot.png");
    
    canvas->Draw();
    

    // Cleanup
    file->Close();
    delete file;
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        cerr << "Usage: " << argv[0] << " <filename.root> [entryIndex]" << endl;
        return 1;
    }

    // Get the filename from the first argument
    const char* filename = argv[1];

    // Default entry index to 0
    int entryIndex = 0;

    // If a second argument is provided, convert it to an integer
    if (argc == 3) {
        entryIndex = std::atoi(argv[2]); // Convert to integer
    }

    // Call the drawPath function with the filename and entry index
    drawPath(filename, entryIndex);
    
    return 0;
}

