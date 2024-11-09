#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TCanvas.h>
#include <TAttText.h>
#include <TStyle.h>
#include <TPaveStats.h>

#include <iostream>
//use command g++ -o detHeat DetectorHeatMap.cc $(root-config --cflags --libs) to compile
//use command ./detHeat singlebar_barTOF_test-001.root to draw heatmap of detectors


void drawHistogram(const char* filename) {
    // Open data file
    TFile *file = new TFile(filename);

    const char* treeName = "data";
    const char* barTOF = "barTOF";
    const char* nInitEnergy ="nInitEnergy";
    const char* mult = "multiplicity";
    const char* detID0 = "detID[0]";
    const char* detID1 = "detID[1]";
    const char* eventID = "eventID";

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
    TH2F *COLZ = new TH2F("COLZ", "Detectors hit for each event", 26, 0, 26, 26, 0, 26);


    // Fill the histogram from the branch
    //tree->Draw("detID:eventID", "multiplicity==2 && abs(detID[0] - detID[1]) == 1");
    tree->Draw(Form("%s:%s>>COLZ", detID0, detID1), "barTOF > 0 && goodEvent && multiplicity==2", "COLZ");
    //tree->Draw(Form("%s:(1/(%s*%s)>>scatterplot", nInitEnergy, barTOF, barTOF), "goodEvent", "goff");
    // Get the X axis and Y axis objects
    TAxis *xAxis = COLZ->GetXaxis();
    TAxis *yAxis = COLZ->GetYaxis();

    // Customize the statistics box (show entries only)
    gStyle->SetOptStat(10);  // This will only show entries



    // Customize X axis label
    xAxis->SetTitle("DetectorID[1]");
    xAxis->SetTitleSize(0.04); // Set title size
    xAxis->SetLabelSize(0.03); // Set label size
    // You can customize other properties like font, color, etc.

    // Customize Y axis label
    yAxis->SetTitle("Detector ID[0]"); //used when TOF interval size is 500ns
    yAxis->SetTitleSize(0.04); // Set title size
    yAxis->SetLabelSize(0.03); // Set label size
    // You can customize other properties like font, color, etc.

    // Create a canvas to save the histogram as a PNG
    TCanvas *canvas = new TCanvas("canvas");
    COLZ->Draw("COLZ");

    // Update the canvas to ensure stats box is created
    canvas->Update();

    // Retrieve the statistics box
    TPaveStats *stats = (TPaveStats*)COLZ->GetListOfFunctions()->FindObject("stats");
    if (stats) {
        stats->SetX1NDC(0.7); // Left boundary (0 to 1 range)
        stats->SetX2NDC(0.9); // Right boundary (0 to 1 range)
        stats->SetY1NDC(0.9); // Bottom boundary (moves it up)
        stats->SetY2NDC(0.99); // Top boundary (moves it up)
        stats->Draw();         // Redraw the stats box in new position
    }




    canvas->SaveAs("Heatmap.pdf");
    std::cout << "Saved pdf file: Heatmap.pdf" << std::endl;

    


    // Clean up
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

    drawHistogram(filename);

    return 0;
}