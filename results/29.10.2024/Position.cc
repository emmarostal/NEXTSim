#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TGraph.h> // Include this line for TGraph
#include <TCanvas.h>
#include <TAttText.h>
#include <TStyle.h>
#include <TPaveStats.h>
#include <TMath.h>
#include <TSystem.h>
#include <iostream>
#include </home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp>
#include <TGraph2D.h>
#include <TAxis.h>
#include <cstdlib> // Include for std::atoi
#include <vector>
#include <TF2.h> // Include this line for TF1
#include </home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp>
using namespace std;
//use command g++ -o drawPosition Position.cc $(root-config --cflags --libs) -lNextSimEvent -L/home/emma/Documents/TILGITHUB/build/dict to compile
//use command ./drawPosition singlebar_barTOF_test-001.root to draw heatmap of detectors


void drawPosition(const char* filename) {
    // Open data file
    TFile *file = new TFile(filename);
    const char* treeName = "data";

    if (!file->IsOpen()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    // Get the tree
    TTree *tree = dynamic_cast<TTree*>(file->Get(treeName));
    if (!tree) {
        std::cerr << "Error: Unable to retrieve tree " << treeName << " from file " << filename << std::endl;
        file->Close();
        return;
    }

    auto outData = new nDetMultiOutputStructure();
    tree->SetBranchAddress("output", &outData);

    // Define a histogram and set properties
    TH2F *COLZ = new TH2F("COLZ", "Detected position vs simulated position (y direction)", 300, -700, 700, 300, -700, 700);
    // Create a TGraph to hold points from bins with more than 20 counts
    TGraph *histFitGraph = new TGraph();

    // Get the number of entries in the tree
    Long64_t nEntries = tree->GetEntries();

    // Loop over all entries
    for (size_t i = 0; i < nEntries; ++i) {
        tree->GetEntry(i);
        double detected = 0.0;
        

        // Ensure the vectors are populated for the chosen entry
        size_t nElements = std::min({outData->nScatterX.size(), outData->nScatterY.size(), outData->nScatterZ.size()});
        if (nElements == 0) {
            //std::cerr << "Warning: Entry " << i << " has empty vectors." << std::endl;
            continue;
        }
        size_t firstID = nElements -1;
        size_t firstScatterID = 0;
        bool forward = outData->nScatterZ[firstID]>0;
        bool xlim = abs(outData->nScatterX[firstID]/outData->nPathLength[firstID])<0.8;
        bool ylim = abs(outData->nScatterY[firstID]/outData->nPathLength[firstID])<0.8;
        bool inFrame = (forward && xlim && ylim);
        // Loop over all elements in the vectors to find the first detected scatter
        bool scatterFound = false;
        for (size_t j = nElements-1; j-->0;) {
            if (outData->nScatterScint[j]) {
                detected = outData->nScatterY[j];
                firstScatterID = j;
                scatterFound = true;
                break;
            }
        }

        // Ensure a valid scatter event was found before proceeding
        if (!scatterFound) {
            //std::cerr << "Warning: No valid scatter found in entry " << i << std::endl;
            continue;
        }
        if (scatterFound && forward){
        // Calculate predicted y position for the first scatter event

        double first = outData->nScatterY[firstID];
        double predicted = 1000*first / sqrt(TMath::Power(outData->nScatterX[firstID], 2) +
                                        TMath::Power(outData->nScatterZ[firstID], 2));
        
        // Fill the histogram
        COLZ->Fill(predicted, detected);
        }
    }

    // Customize histogram axis labels
    COLZ->GetXaxis()->SetTitle("Calculated position");
    COLZ->GetXaxis()->SetTitleSize(0.04);
    COLZ->GetXaxis()->SetLabelSize(0.03);

    COLZ->GetYaxis()->SetTitle("Detected position");
    COLZ->GetYaxis()->SetTitleSize(0.04);
    COLZ->GetYaxis()->SetLabelSize(0.03);

    // Create and update canvas
    TCanvas *canvas = new TCanvas("canvas", "Position Plot", 800, 800);

    // Adjust margins before drawing
    canvas->SetLeftMargin(0.13);   // Increase the left margin
    canvas->SetRightMargin(0.13);  // Increase the right margin if needed
    canvas->SetBottomMargin(0.1); // Increase the bottom margin
    canvas->SetTopMargin(0.1);     // Increase the top margin if needed
    


    // Display and customize statistics box
    gStyle->SetOptStat(10);  // Only show entries
    canvas->Update();
    TPaveStats *stats = (TPaveStats*)COLZ->GetListOfFunctions()->FindObject("stats");
    if (stats) {
        stats->SetX1NDC(0.1);
        stats->SetX2NDC(0.3);
        stats->SetY1NDC(0.8);
        stats->SetY2NDC(0.9);
        stats->Draw();
    }

    // Loop over the histogram bins to collect points for fitting
    for (int binX = 1; binX <= COLZ->GetNbinsX(); ++binX) {
        for (int binY = 1; binY <= COLZ->GetNbinsY(); ++binY) {
            double binContent = COLZ->GetBinContent(binX, binY);
            if (binContent > 5) { // Check if bin count is greater than 20
                double xValue = COLZ->GetXaxis()->GetBinCenter(binX);
                double yValue = COLZ->GetYaxis()->GetBinCenter(binY);
                histFitGraph->SetPoint(histFitGraph->GetN(), xValue, yValue);
            }
        }
    }

    // Perform a linear fit on the collected points
    TF1 *fitFunction = new TF1("fitFunction", "pol1", COLZ->GetXaxis()->GetXmin(), COLZ->GetXaxis()->GetXmax());
    histFitGraph->Fit(fitFunction); // Fit quietly

    // Draw the fit on top of the histogram
    fitFunction->SetLineColor(kRed); // Set fit line color
    fitFunction->SetLineWidth(2);     // Set fit line width

    COLZ->Draw("COLZ"); // Redraw the histogram
    //fitFunction->Draw("SAME"); // Overlay the fit line

    // Save the canvas as an image
    canvas->SaveAs("Position.pdf");
    std::cout << "Saved pdf file: Position.pdf" << std::endl;


    // Cleanup
    delete canvas;
    delete COLZ;
    delete fitFunction;
    delete histFitGraph;
    file->Close();
    delete file;
    delete outData;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename.root>" << std::endl;
        return 1;
    }

    const char* filename = argv[1];
    drawPosition(filename);
    return 0;
}