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


void plotSpecificTrace(int traceToShow = 6) {
    // Open the input file
    std::ifstream file("lowETraces.txt");
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
            // If we were processing the desired trace, stop after saving its graph
            if (isTargetTrace) break;

            // Check if the next trace is the target trace
            isTargetTrace = (++traceCounter == traceToShow);

            // Clear vectors for the next trace
            time.clear();
            value1.clear();
            value2.clear();
        } else if (isTargetTrace) {
            // Parse data lines for the desired trace
            double t, v1, v2;
            std::istringstream iss(line);
            if (iss >> t >> v1 >> v2) {
                time.push_back(t / 4);  // Adjust the time scale if needed
                value1.push_back(v1);
                value2.push_back(v2);
            }
        }
    }

    file.close();

    // Plot the data for the specific trace
    if (!time.empty() && !value1.empty() && !value2.empty()) {
        auto graph1 = new TGraph(time.size(), &time[0], &value1[0]);
        auto graph2 = new TGraph(time.size(), &time[0], &value2[0]);

        // Configure graph1 (value1)
        graph1->SetTitle(Form("Trace %d;Time (4ns);Values", traceToShow));
        graph1->SetMarkerStyle(20);
        graph1->SetMarkerColor(kBlue);
        graph1->SetLineColor(kBlue);
        graph1->SetLineWidth(2);

        // Configure graph2 (value2)
        graph2->SetMarkerStyle(21);
        graph2->SetMarkerColor(kRed);
        graph2->SetLineColor(kRed);
        graph2->SetLineWidth(2);

        // Find the y-axis range for both graphs (value1 and value2)
        double minY = std::min(*std::min_element(value1.begin(), value1.end()), 
                               *std::min_element(value2.begin(), value2.end()));
        double maxY = std::max(*std::max_element(value1.begin(), value1.end()), 
                               *std::max_element(value2.begin(), value2.end()));

        // Add some padding to the y-range to ensure the data is fully visible
        double rangePadding = 0.1 * (maxY - minY);
        minY -= rangePadding;
        maxY += rangePadding;

        // Create and display the canvas with adjusted margins
        auto canvas = new TCanvas("canvas", Form("Trace %d", traceToShow), 950, 800);

        // Set margins to provide space for the y-axis label
        canvas->SetLeftMargin(0.15); // Increase left margin to avoid clipping y-axis label
        canvas->SetBottomMargin(0.15); // Optional: Increase bottom margin if needed

        graph1->Draw("APL"); // Draw graph1
        graph2->Draw("PL SAME"); // Draw graph2 on the same plot

        // Set the y-axis range to include both graphs
        graph1->GetYaxis()->SetRangeUser(minY, maxY);

        // Add a legend and adjust its position and size
        auto legend = new TLegend(0.15, 0.8, 0.35, 0.9); // Position: upper left corner
        legend->AddEntry(graph1, "lPMT", "l");
        legend->AddEntry(graph2, "rPMT", "l");

        // Make the legend smaller by reducing the text size
        legend->SetTextSize(0.03); // Adjust text size as needed

        // Draw the legend
        legend->Draw();

        // Save the plot as an image (optional)
        canvas->SaveAs(Form("trace_%d_values.png", traceToShow));
    } else {
        std::cerr << "Error: No data found for trace " << traceToShow << "." << std::endl;
    }
}
