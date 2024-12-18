#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <TAxis.h>
#include <TCanvas.h>
#include <TGraph.h>

void plotTraces(const std::string& filename, const std::string& outputFilename) {
    // Open the file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    // Read the data from the file
    std::vector<float> data;
    std::string line;
    while (std::getline(file, line)) {
        // Skip lines that start with "Phase (ticks):"
        if (line.find("Phase (ticks):") != std::string::npos) {
            continue;
        }

        // Skip lines that are not numeric (like header lines)
        try {
            float value = std::stof(line);
            data.push_back(value);
        } catch (const std::invalid_argument&) {
            // Ignore non-numeric lines (e.g., phase information)
            continue;
        }
    }

    // Determine the number of traces and the length of each trace
    int traceLength = 124; // Example: assuming each trace has 100 data points
    int numTraces = data.size() / traceLength;

    // Plot only the first 3 traces (or fewer if there are less than 3 traces)
    int tracesToPlot = std::min(numTraces, 3);

    // Create a canvas to draw the traces (we divide the canvas into 'tracesToPlot' pads)
    TCanvas *canvas = new TCanvas("canvas", "Plot Traces", 2800, 2600);
    canvas->Divide(1, tracesToPlot); // Divide canvas into multiple pads (one for each trace)

    // Loop through each trace and plot it on a separate pad
    for (int traceIdx = 0; traceIdx < tracesToPlot; ++traceIdx) {
        int startIdx = traceIdx * traceLength;
        int endIdx = startIdx + traceLength;

        // Create a graph for each trace
        TGraph *graph = new TGraph(traceLength);
        for (int i = startIdx; i < endIdx; ++i) {
            graph->SetPoint(i - startIdx, i - startIdx, data[i]);
        }

        // Move to the next pad
        canvas->cd(traceIdx + 1);

        // Draw the graph for the current trace
        graph->SetTitle(("Trace " + std::to_string(traceIdx + 1)).c_str());
        graph->GetXaxis()->SetTitle("Time (ticks)");
        graph->GetYaxis()->SetTitle("Amplitude");
        graph->Draw("AL");
    }

    // Save the canvas as a PNG file
    canvas->SaveAs(outputFilename.c_str());
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_filename> <output_filename>" << std::endl;
        return 1; // Exit with an error code
    }

    // Get the input and output filenames from the command-line arguments
    std::string inputFilename = argv[1];
    std::string outputFilename = argv[2];

    // Pass the filenames to the plotTraces function
    plotTraces(inputFilename, outputFilename);

    return 0;
}

