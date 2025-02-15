#include <fstream>     // For file handling
#include <iostream>    // For standard I/O
#include <sstream>     // For string stream processing
#include <vector>      // For using std::vector
#include <string>      // For std::string
#include "TGraph.h"    // For plotting graphs
#include "TCanvas.h"   // For creating canvases
#include "TLegend.h"   // For legends
#include "TStyle.h"    // For ROOT style settings
#include "TROOT.h"     // For ROOT global settings
#include "TLine.h" // Include for drawing lines
#include "TEllipse.h"







void plotSpecificTrace(int traceToShow = 1) {
    // Set global style for fonts
    gStyle->SetTextFont(42);
    gStyle->SetTitleFont(42, "XYZT");
    gStyle->SetLabelFont(42, "XYZ");
    gStyle->SetTitleSize(0.06, "T");
    gStyle->SetTitleSize(0.05, "XYZ");
    gStyle->SetLabelSize(0.04, "XYZ");
    // Open the input file
    std::ifstream file("Traces.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file!" << std::endl;
        return;
    }

    // Variables to store extracted data
    std::vector<double> time, value1, value2;
    std::string line;
    int traceCounter = 0;
    bool isTargetTrace = false;

    // Read through the file
    while (std::getline(file, line)) {
        // Detect the start of a new trace
        if (line.find("***********************************************************") != std::string::npos) {
            if (isTargetTrace) break;  // Stop if we've read the target trace
            isTargetTrace = (++traceCounter == traceToShow); // Check if this is the target trace
            time.clear();
            value1.clear();
            value2.clear();
        } else if (isTargetTrace) {
            // Parse data lines for the desired trace
            double t, v1, v2;
            std::istringstream iss(line);
            if (iss >> t >> v1 >> v2) {
                time.push_back(t / 4);
                value1.push_back(v1);
                value2.push_back(v2);
            }
        }
    }
    file.close();

    // Ensure there's data to plot
    if (time.empty() || value1.empty() || value2.empty()) {
        std::cerr << "Error: No data found for trace " << traceToShow << "." << std::endl;
        return;
    }

    // Compute minY and maxY after reading the data
    double minY = std::min(*std::min_element(value1.begin(), value1.end()), 
                           *std::min_element(value2.begin(), value2.end()));
    double maxY = std::max(*std::max_element(value1.begin(), value1.end()), 
                           *std::max_element(value2.begin(), value2.end()));

    // Add some padding to the y-range
    double rangePadding = 0.1 * (maxY - minY);
    minY -= rangePadding;
    maxY += rangePadding;

    // Create and display the canvas
    auto canvas = new TCanvas("canvas", Form("Trace %d", traceToShow), 950, 800);
    canvas->SetLeftMargin(0.15);
    canvas->SetBottomMargin(0.15);

    // Create graphs
    auto graph1 = new TGraph(time.size(), &time[0], &value1[0]);
    auto graph2 = new TGraph(time.size(), &time[0], &value2[0]);

    // Configure graph1
    graph1->SetTitle("Generated trace");
    graph1->SetMarkerStyle(20);
    graph1->SetMarkerColor(kBlue);
    graph1->SetLineColor(kBlue);
    graph1->SetLineWidth(2);

    // Configure graph2
    graph2->SetTitle("Generated trace");
    graph2->SetMarkerStyle(21);
    graph2->SetMarkerColor(kRed);
    graph2->SetLineColor(kRed);
    graph2->SetLineWidth(2);
    graph2->GetXaxis()->SetTitle("Time (ADC ticks)");
    graph2->GetXaxis()->SetTitleSize(0.04);  // Adjust title size (optional)
    graph2->GetXaxis()->SetTitleOffset(1.2); // Adjust position (optional)


    // Draw graphs
    //graph1->Draw("APL");
    graph2->Draw("APL");

    //graph2->Draw("PL SAME");
    graph1->GetYaxis()->SetRangeUser(minY, maxY);

    // Define positions for the lines
    double xLine = 54.5;  // Vertical line at midpoint of x-range
    double yLineR = 11680;      // Horizontal line at midpoint of y-range
    double yLineL = 10150;      // Horizontal line at midpoint of y-range

    // Create and configure the vertical line
    TLine *vLine = new TLine(xLine, minY, xLine, maxY);
    vLine->SetLineColor(kBlack);
    vLine->SetLineStyle(kDashed);
    vLine->SetLineWidth(2);

    // Create and configure the horizontal line
    TLine *hLineR = new TLine(44., yLineR, 69., yLineR);
    hLineR->SetLineColor(kBlack);
    hLineR->SetLineStyle(kDashed);
    hLineR->SetLineWidth(2);

    // Create and configure the horizontal line
    TLine *hLineL = new TLine(time.front(), yLineL, time.back(), yLineL);
    hLineL->SetLineColor(kBlue);
    hLineL->SetLineStyle(kDashed);
    hLineL->SetLineWidth(2);

    // Draw the lines **after** drawing the graphs
    vLine->Draw();
    hLineR->Draw();
    //hLineL->Draw();

    // Define circle parameters
    double xCenter = 52.5;  // X-coordinate of center
    double yCenter = 12500.0; // Y-coordinate of center
    double xRadius = 2;  // Radius along the x-axis
    double yRadius = 3000.0;  // Set to 0 to disable y-scaling

    // Create an ellipse (scales only along X)
    TEllipse *ellipse = new TEllipse(xCenter, yCenter, xRadius, yRadius);

    // Customize the ellipse
    ellipse->SetLineColor(kBlack);  // Set border color
    ellipse->SetLineWidth(2);       // Set border thickness
    ellipse->SetFillStyle(0);       // Transparent fill

    // Draw the ellipse
    ellipse->Draw("SAME");

    // Add a legend
    auto legend = new TLegend(0.7, 0.8, 0.9, 0.9);
    //legend->AddEntry(graph1, "lPMT", "l");
    legend->AddEntry(graph2, "rPMT", "l");
    legend->SetTextSize(0.04);
    legend->Draw();

    // Save the plot
    canvas->SaveAs(Form("trace_%d_values.png", traceToShow));
}

