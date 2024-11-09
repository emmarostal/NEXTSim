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


void drawDetection(const char* filename) {
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
    TH2F *COLZ = new TH2F("COLZ", "Detection in scintillators", 200, -700, 700, 200, -700, 700);

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
        for (size_t j = nElements-1; j-->0;) {
            if (outData->nScatterScint[j]) {
                firstScatterID = j;
                double x = outData->nScatterX[j];
                double y = outData->nScatterY[j];
                COLZ->Fill(y,x);

            }
        }
    }

    // Customize histogram axis labels
    COLZ->GetXaxis()->SetTitle("Y (mm)");
    COLZ->GetXaxis()->SetTitleSize(0.04);
    COLZ->GetXaxis()->SetLabelSize(0.03);

    COLZ->GetYaxis()->SetTitle("X (mm)");
    COLZ->GetYaxis()->SetTitleSize(0.04);
    COLZ->GetYaxis()->SetLabelSize(0.03);

    // Create and update canvas
    TCanvas *canvas = new TCanvas("canvas", "Detection plot", 800, 800);
    


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

    COLZ->Draw("COLZ"); // Redraw the histogram
    //fitFunction->Draw("SAME"); // Overlay the fit line

    // Save the canvas as an image
    canvas->SaveAs("Detection.pdf");
    std::cout << "Saved pdf file: Detection.pdf" << std::endl;


    // Cleanup
    delete canvas;
    delete COLZ;
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
    drawDetection(filename);
    return 0;
}