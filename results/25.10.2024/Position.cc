#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TCanvas.h>
#include <TAttText.h>
#include <TStyle.h>
#include <TPaveStats.h>
#include <TMath.h>
#include <TSystem.h>
#include <iostream>
#include </home/emma/Documents/TILGITHUB/dict/include/nDetStructures.hpp>
using namespace std;
//use command g++ -o drawPosition Position.cc $(root-config --cflags --libs) -l NextSimEvent -L /home/emma/Documents/TILGITHUB/build/dict to compile
//use command ./drawPosition singlebar_barTOF_test-001.root to draw heatmap of detectors


void drawPosition(const char* filename) {

    gSystem->Load("/home/emma/Documents/TILGITHUB/build/dict/libNextSimEvent.a");

    // Open data file
    TFile *file = new TFile(filename);
    const char* treeName = "data";

    if (!file->IsOpen()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    // Get the tree
    TTree *tree = dynamic_cast<TTree*>(file->Get(treeName));
    auto outData = new nDetMultiOutputStructure();
    tree -> SetBranchAddress("output",&outData);
    tree -> GetEntry(0);
    cout << outData->nScatterX[0] << endl; 
        tree -> GetEntry(1);
    cout << outData->nScatterX[0] << endl; 
    if (!tree) {
        std::cerr << "Error: Unable to retrieve tree " << treeName << " from file " << filename << std::endl;
        file->Close();
        return;
    }

    // Define a histogram and set properties
    TH2F *COLZ = new TH2F("COLZ", "Detected position vs simulated position (y direction)", 1000, -700, 700, 1000, -700, 700);

    // Expression and condition
    const char* detID = "detID";
    const char* detectedPos = "nScatterY[1]";
    const char* numerator = "nScatterY[6]";
    const char* denominator = "sqrt(TMath::Power(nScatterX[6] / nPathLength[6], 2) + TMath::Power(nScatterZ[6] / nPathLength[6], 2))";
    const char* expression = Form("%s : %s / %s", detectedPos, numerator, denominator);
    //const char* condition = "barTOFcorr > 0 && nScatterZ[0]>0 &&nScatterZ[0]<1100 &&nScatterX[0]>-770 &&nScatterX[0]< 770 &&nScatterY[0]>-700 && nScatterY[0]<700 && abs(nScatterY[0])<nScatterZ[0]*0.6 && abs(nScatterY[0])<abs(nScatterX[0]*0.8) &&nScatterX[0]<0.7*nScatterZ[0]";
    const char* condition = "barTOFcorr > 0 && nScatterZ[6]>0 &&nScatterZ[6]<1100 &&nScatterX[6]>-770 &&nScatterX[6]< 770 &&nScatterY[6]>-700 && nScatterY[6]<700";
    // Draw expression into the predefined histogram
    tree->Draw(Form("%s>>COLZ", expression), condition, "COLZ");

    // Customize histogram axis labels
    COLZ->GetXaxis()->SetTitle("Calculated position");
    COLZ->GetXaxis()->SetTitleSize(0.04);
    COLZ->GetXaxis()->SetLabelSize(0.03);

    COLZ->GetYaxis()->SetTitle("Detected position");
    COLZ->GetYaxis()->SetTitleSize(0.04);
    COLZ->GetYaxis()->SetLabelSize(0.03);

    // Create and update canvas
    TCanvas *canvas = new TCanvas("canvas");
    COLZ->Draw("COLZ");

    // Display and customize statistics box
    gStyle->SetOptStat(10);  // Only show entries
    canvas->Update();
    TPaveStats *stats = (TPaveStats*)COLZ->GetListOfFunctions()->FindObject("stats");
    if (stats) {
        stats->SetX1NDC(0.7);
        stats->SetX2NDC(0.9);
        stats->SetY1NDC(0.8);
        stats->SetY2NDC(0.9);
        stats->Draw();
    }

    // Save the canvas as an image
    canvas->SaveAs("Position.pdf");
    std::cout << "Saved pdf file: Position.pdf" << std::endl;

    // Cleanup
    delete canvas;
    delete COLZ;
    file->Close();
    delete file;
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