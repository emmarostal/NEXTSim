#include <iostream>
#include <cstdlib>
#include <TFile.h>
#include <TTree.h>
#include <TGraph.h>
#include <TCanvas.h>
#include <vector>
#include <TStyle.h>
#include <TColor.h>
#include <TAxis.h>
#include <TLatex.h>
#include </home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp>
using namespace std;

//use command g++ -o plotMultipleTraces plotMultipleTraces.cc $(root-config --cflags --libs) -L/home/emma/Documents/TILGITHUB/build/dict -lNextSimEvent
// to compile
//use command ./plotMultipleTraces uniform_wTraces.root to draw energies

void drawTraces(const char* filename) {
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
    auto traceData = new nDetTraceStructure();
    double nInitEnergy;  // Declare the variable to store nInitEnergy
    tree->SetBranchAddress("trace", &traceData);
    tree->SetBranchAddress("nInitEnergy", &nInitEnergy);  // Assuming nInitEnergy is a float

    // Get the number of entries in the tree
    Long64_t nEntries = tree->GetEntries();

    // Create a canvas for the plot
    TCanvas *canvas = new TCanvas("canvas", "Trace Plot", 2000, 1800);
    canvas->SetTopMargin(5); // Increase the top margin to make space for the title
    canvas->Divide(4, 4); // Divide into 4x4 grid of pads

    // Set color palette
    gStyle->SetPalette(kRainBow);

    // Define energy range for condition
    float minEnergy = 1.8, maxEnergy = 1.9;

    // Create the title with the energy condition
    TString mainTitle = Form("Traces with nInitEnergy in [%.1f, %.1f]", minEnergy, maxEnergy);
    TLatex titleLatex;
    titleLatex.SetTextSize(0.04);  // Set the font size for the title
    titleLatex.SetTextAlign(22);   // Align the title to the center

    int traceCount = 0;  // To count valid traces
    bool energyConditionMet = false;  // Flag to track if any trace meets the energy condition

    // Loop over the entries and draw traces
    for (int entryIndex = 0; entryIndex < nEntries; ++entryIndex) {
        tree->GetEntry(entryIndex);

        // Check if nInitEnergy is within the desired range (e.g., 1.0 to 100.0)
        if (nInitEnergy < minEnergy || nInitEnergy > maxEnergy) {
            continue;  // Skip this trace if nInitEnergy is out of range
        }

        // Mark that the energy condition was met
        energyConditionMet = true;

        // Create two separate 2D graphs for left and right traces
        TGraph *graphLeft = new TGraph();
        TGraph *graphRight = new TGraph();

        // Get the number of elements in left and right vectors
        size_t nElementsLeft = traceData->left.size();
        size_t nElementsRight = traceData->right.size();
        
        if (nElementsLeft == 0 || nElementsRight == 0) {
            cerr << "Error: Entry " << entryIndex << " has empty left or right vectors." << endl;
            continue;
        }

        // Loop over the left trace elements
        for (size_t j = 0; j < nElementsLeft; ++j) {
            graphLeft->SetPoint(j, j, traceData->left[j]);  // X = index, Y = left value
        }

        // Loop over the right trace elements
        for (size_t j = 0; j < nElementsRight; ++j) {
            graphRight->SetPoint(j, j, traceData->right[j]);  // X = index, Y = right value
        }

        // Set graph title and axis labels
        graphLeft->SetTitle(Form("Trace %d;Index;Value", entryIndex));

        // Get the current pad (1-based index for Divide)
        int padIndex = traceCount + 1; // Pads are indexed from 1 in ROOT's Divide method
        canvas->cd(padIndex); // Change to the correct pad
        canvas->Update();

        // Draw the left trace (in red)
        graphLeft->SetMarkerStyle(20);
        graphLeft->SetMarkerColor(kRed);
        graphLeft->SetMarkerSize(0.2);
        graphLeft->SetLineColor(kRed);
        graphLeft->SetLineWidth(2);
        graphLeft->Draw("ALP");  // Draw left trace

        // Draw the right trace (in blue) on the same plot
        graphRight->SetMarkerStyle(21);
        graphRight->SetMarkerColor(kBlue);
        graphRight->SetMarkerSize(0.2);
        graphRight->SetLineColor(kBlue);
        graphRight->SetLineWidth(2);
        graphRight->Draw("LP");  // Draw right trace

        // Adjust Y-axis range to fit the data
        graphLeft->GetYaxis()->SetRangeUser(graphLeft->GetMinimum(), graphLeft->GetMaximum());
        graphRight->GetYaxis()->SetRangeUser(graphRight->GetMinimum(), graphRight->GetMaximum());

        // Force canvas update
        canvas->Modified();
        canvas->Update();

        // Increment the trace count
        traceCount++;
        
        // Stop after 16 valid traces
        if (traceCount >= 16) break;
    }

    // Draw the main title
    canvas->cd(0);  // Set canvas to the overall area (not individual pads)
    titleLatex.DrawLatexNDC(0.5, 0.92, mainTitle);  // Position title at the top center

    // Save the canvas as an image
    canvas->SaveAs("tracePlot_first16Traces.png");

    // Show the canvas
    canvas->Draw();

    // If no valid traces met the energy condition, show an error message
    if (!energyConditionMet) {
        cerr << "Error: No traces met the energy condition (nInitEnergy out of range)." << endl;
    }

    // Cleanup
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

    // Call the drawTraces function with the filename
    drawTraces(filename);
    
    return 0;
}
