#include <cmath>
#include <vector>
#include <iostream>
#include "TCanvas.h"
#include "TGraph.h"
// plot with 
// root -l plotPMTresponse.cc

// FunctionType enum
enum FunctionType { EXPO, VANDLE, GAUSS };

class pmtResponse {
public:
    double gain = 100.0;
    double risetime = 2.0;  // For EXPO/VANDLE, it's rise time; for GAUSS, it's sigma.
    double falltime = 20.0;  // For VANDLE, it's GAMMA.
    FunctionType functionType = VANDLE;

    double func(const double &t, const double &dt = 0) const {
        if(functionType == EXPO) {
            if(t - dt <= 0) return 0;
            return gain * (1 / (falltime - risetime)) * 
                   (std::exp(-(t - dt) / falltime) - std::exp(-(t - dt) / risetime));
        } else if(functionType == VANDLE) {
            if(t - dt <= 0) return 0;
            return 100 * gain * std::exp((dt - t) * risetime) * 
                   (1 - std::exp(-std::pow((t - dt) * falltime, 4)));
        } else if(functionType == GAUSS) {
            return gain * ((1 / (risetime * std::sqrt(2 * M_PI))) * 
                           std::exp(-0.5 * std::pow((t - dt) / risetime, 2.0)));
        }
        return 0;
    }
};

void plotPMTresponse() {
    pmtResponse response;
    response.gain = 12;
    response.risetime = 0.3;
    response.falltime = 1.2;
    response.functionType = VANDLE; // Change to VANDLE or GAUSS to see other types.

    // Define range and step size for t
    double t_min = -1.0, t_max = 124.0;
    double step = 0.1;
    std::vector<double> t_values, y_values;

    for(double t = t_min; t <= t_max; t += step) {
        t_values.push_back(t);
        y_values.push_back(response.func(t, 56.0)); // Example: dt = 56
    }

    // Create TGraph
    TGraph *graph = new TGraph(t_values.size(), t_values.data(), y_values.data());
    graph->SetTitle("PMT Response Function;Time (acd ticks 4ns);Amplitude");
    graph->SetLineWidth(2);
    graph->SetLineColor(kBlue);

    // Create Canvas and draw the graph
    TCanvas *canvas = new TCanvas("canvas", "PMT Response Function", 950, 800);
    graph->Draw("AL");
    canvas->SaveAs("pmtResponse.png"); // Save the plot as an image
}
