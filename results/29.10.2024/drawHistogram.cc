#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TAttText.h>

#include <iostream>
//use command g++ -o drawHistogram drawHistogram.cc $(root-config --cflags --libs) to compile
//use command ./drawHistogram singlebar_barTOF_test-001.root data barTOF to draw tof


void drawHistogram(const char* filename, const char* treeName, const char* branchName) {
    // Open data file
    TFile *file = new TFile(filename);

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
    TH1F *histogram = new TH1F("histogram", "Response function for full setup run with 3e6 neutrons", 150, 0, 500);


    // Fill the histogram from the branch
    tree->Draw(Form("%s>>histogram", branchName), "goodEvent", "goff");


    // Get the X axis and Y axis objects
    TAxis *xAxis = histogram->GetXaxis();
    TAxis *yAxis = histogram->GetYaxis();

    // Customize X axis label
    xAxis->SetTitle("TOFcorr (ns)");
    xAxis->SetTitleSize(0.04); // Set title size
    xAxis->SetLabelSize(0.03); // Set label size
    // You can customize other properties like font, color, etc.

    // Customize Y axis label
    //yAxis->SetTitle("Counts (200 ps^{-1} )"); //used when TOF interval sizeis 30ns
    //yAxis->SetTitle("Counts (ns^{-1})"); //used when TOF interval size is 150ns
    //yAxis->SetTitle("Counts (2ns^{-1})"); //used when TOF interval size is 300ns
    yAxis->SetTitle("Counts (4ns^{-1})"); //used when TOF interval size is 500ns
    yAxis->SetTitleSize(0.04); // Set title size
    yAxis->SetLabelSize(0.03); // Set label size
    // You can customize other properties like font, color, etc.

    // Create a canvas to save the histogram as a PNG
    TCanvas *canvas = new TCanvas("canvas");
    histogram->Draw();
    canvas->SaveAs("Response.pdf");
    std::cout << "Saved PNG file: Response.pdf" << std::endl;


    // Clean up
    delete canvas;
    delete histogram;
    file->Close();
    delete file;
}


int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename.root> <treeName> <branchName>" << std::endl;
        return 1;
    }

    const char* filename = argv[1];
    const char* treeName = argv[2];
    const char* branchName = argv[3];

    drawHistogram(filename, treeName, branchName);

    return 0;
}