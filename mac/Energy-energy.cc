#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TCanvas.h>
#include <TAttText.h>

#include <iostream>
//use command g++ -o drawEnergy Energy-energy.cc $(root-config --cflags --libs) to compile
//use command ./drawEnergy singlebar_barTOF_test-001.root to draw energies


void drawHistogram(const char* filename) {
    // Open data file
    TFile *file = new TFile(filename);

    const char* treeName = "data";
    const char* barTOF = "barTOF";
    const char* nInitEnergy ="nInitEnergy";

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

    // Create a histogram
    TH2F *scatterplot = new TH2F("scatterplot", "Calculated kinetic energy vs simulated energy", 150, 0, 4, 150, 0, 4);


    // Fill the histogram from the branch
    tree->Draw(Form("(0.5*939*(100/9)*(1/(%s*%s))):%s>>scatterplot", barTOF, barTOF, nInitEnergy), "barTOF > 0 && goodEvent", "goff");
    //tree->Draw(Form("%s:(1/(%s*%s)>>scatterplot", nInitEnergy, barTOF, barTOF), "goodEvent", "goff");
    // Get the X axis and Y axis objects
    TAxis *xAxis = scatterplot->GetXaxis();
    TAxis *yAxis = scatterplot->GetYaxis();

    // Customize X axis label
    xAxis->SetTitle("Simulated energy (MeV)");
    xAxis->SetTitleSize(0.04); // Set title size
    xAxis->SetLabelSize(0.03); // Set label size
    // You can customize other properties like font, color, etc.

    // Customize Y axis label
    yAxis->SetTitle("Calculated energy (MeV)"); //used when TOF interval size is 500ns
    yAxis->SetTitleSize(0.04); // Set title size
    yAxis->SetLabelSize(0.03); // Set label size
    // You can customize other properties like font, color, etc.

    // Create a canvas to save the histogram as a PNG
    TCanvas *canvas = new TCanvas("canvas");
    scatterplot->Draw();
    canvas->SaveAs("Energy-energy.pdf");
    std::cout << "Saved pdf file: Response.pdf" << std::endl;


    // Clean up
    delete canvas;
    delete scatterplot;
    file->Close();
    delete file;
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename.root>" << std::endl;
        return 1;
    }

    const char* filename = argv[1];

    drawHistogram(filename);

    return 0;
}