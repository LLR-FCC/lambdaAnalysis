#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooChebychev.h"
#include "RooPlot.h"
#include "RooWorkspace.h"
#include "RooArgSet.h"
#include "RooAbsPdf.h"
#include "RooPlot.h"
#include "RooSimultaneous.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TROOT.h"


using namespace std;


void pickMrec() {
    
    //TFile *currentFile = new TFile("/eos/user/n/niharrin/llr/presel/365/source/wzp6_gaga_mumu_60_ecm365_sel_ZeeH.root");
    //TFile *currentFile = new TFile("/eos/user/n/niharrin/llr/presel/365/source/wzp6_ee_tautau_ecm365_sel_ZeeH.root");
    TFile *currentFile = new TFile("/eos/user/n/niharrin/llr/presel/365/source/wzp6_ee_eeH_ecm365_sel_ZeeH.root");
    //TFile *currentFile = new TFile("/eos/user/n/niharrin/llr/presel/365/source/wzp6_ee_mumu_ecm365_sel_ZeeH.root");
    //TFile *currentFile = new TFile("/eos/user/n/niharrin/llr/presel/365/source/wzp6_ee_ee_Mee_30_150_ecm365_sel_ZeeH.root");
    
    //TFile *currentFile = new TFile("/eos/user/n/niharrin/llr/presel/365/source/p8_ee_ZZ_ecm365_sel_ZeeH.root");
    //TFile *currentFile = new TFile("/eos/user/n/niharrin/llr/presel/365/source/p8_ee_WW_ecm365_sel_ZeeH.root");
    //TFile *currentFile = new TFile("/eos/user/n/niharrin/llr/presel/365/source/p8_ee_ZH_ecm365_sel_ZeeH.root");

    

    //Hier Loop für Trees

    TTree *currentTree = (TTree*)currentFile->Get("events");

    //Hier Loop für verschiedene MRecs

    //TBranch *currentMRec = currentTree->GetBranch("zed_leptonicM_recoil_m");

    std::vector<float> *zed_leptonicE_recoil_m = 0;

    currentTree->SetBranchAddress("zed_leptonicE_recoil_m", &zed_leptonicE_recoil_m);

    //Create output file + tree
    TFile *newFile = new TFile("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/source/wzp6_ee_eeH_ecm365_sel_ZeeH_noRVec.root", "RECREATE");
    TTree *newTree = new TTree("MRecT", "No RVec MRec tree");

    //Create new branch in the new file
    double currentEvtMRec;
    auto MRecBranch = newTree->Branch("MRec", &currentEvtMRec, "MRec/D");

    Long64_t nentries = currentTree->GetEntries();
    
    std::cout << "--- Processing: " << nentries << " events" << std::endl;
    TStopwatch sw;
    sw.Start();
    for (Long64_t ievt=0; ievt<nentries;ievt++) {

        if (ievt%1000 == 0) std::cout << "--- ... Processing event: " << ievt << std::endl;

        currentTree->GetEntry(ievt);

        currentEvtMRec = (*zed_leptonicE_recoil_m)[0];
        newTree->Fill();

    }

    // Get elapsed time
    sw.Stop();
    std::cout << "--- End of event loop: "; sw.Print();

    newFile->cd();
    newTree->Write("", TObject::kOverwrite);
    newFile->Close();


}