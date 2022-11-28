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
#include "RooStats/ProfileLikelihoodCalculator.h"
#include "RooStats/LikelihoodInterval.h"
#include "RooStats/LikelihoodIntervalPlot.h"


using namespace std;
using namespace RooFit;

void NLLcombinedModel() {

    // I m p o r t  W o r k s p a c e
    // ------------------------------

    TFile wsFile("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/combination/WScombinedModel_muZH.root");

    gROOT->cd();

    RooWorkspace *combWS = (RooWorkspace*)wsFile.Get("combWS");

    //Get original models
    RooAbsPdf * combModel = combWS->pdf("combModel");
    //RooAbsPdf * model_bbH = combWS->pdf("model_bbH_combModel");

    combWS->Print();

    RooAbsData *asimov = combWS->data("combined_Asimov");
    //RooAbsData *asimov_bbH = combWS->data("acombData_bbH");

    //RooAbsPdf * Lsmear_240GeV_bbH = combWS->pdf("Lsmear_240GeV_bbH");
    //RooAbsPdf * Esmear_240GeV_bbH = combWS->pdf("Esmear_240GeV_bbH");
    //RooAbsPdf * COMsmear_240GeV_bbH = combWS->pdf("COMsmear_240GeV_bbH");
    //RooAbsPdf * BRsmear_240GeV_bbH = combWS->pdf("BRsmear_240GeV_bbH");

    //RooRealVar * Lmess_240GeV_bbH = combWS->var("Lmess_240GeV_bbH");
    //RooRealVar * Emess_240GeV_bbH = combWS->var("Emess_240GeV_bbH");
    //RooRealVar * BRmess_240GeV_bbH = combWS->var("BRmess_240GeV_bbH");

    //RooRealVar * mrec_bbH = combWS -> var("MRec_bbH");
    RooRealVar * mrec = combWS -> var("MRec");
    RooRealVar * mrec2 = combWS -> var("MRec");
    //RooRealVar varKappa_240GeV = *(combWS -> var("varKappa_240GeV"));
    RooRealVar muZH_240GeV = *(combWS -> var("muZH_240GeV"));
    //RooRealVar muZH_240GeV_bbH = *(combWS -> var("muZH_240GeV_bbH"));

    combWS->loadSnapshot("asimovFit");

    RooArgSet globSet = *(combWS->set("mc_GlobalObservables"));
    RooArgSet smearSet = *(combWS->set("constr"));
    RooArgSet poiSet = *(combWS->set("poi"));
    RooArgSet nuisSet = *(combWS->set("np"));

    mrec->setRange("range_bbH", 80., 160.);
    mrec->setRange("range_bcH", 80., 160.);
    mrec->setRange("range_bjH", 20., 160.);
    mrec->setRange("range_ccH", 110., 160.);
    mrec->setRange("range_cjH", 100., 160.);
    mrec->setRange("range_ijH", 100., 160.);
    mrec->setRange("range_mumuH", 120., 140.);
    mrec->setRange("range_eeH", 120., 140.);




   // C o n s t r u c t   p l a i n   l i k e l i h o o d
   // ---------------------------------------------------
 TCanvas* c4 = new TCanvas ("c4", "c4", 100, 200, 700, 500);
 TCanvas* c5 = new TCanvas ("c5", "c5", 100, 200, 700, 500);

  combModel->graphVizTree("graph.dot");

  // Construct unbinned likelihood
  RooAbsReal * nll = combModel->createNLL(*asimov, Extended(kTRUE), Offset(kTRUE), NumCPU(8, 0), GlobalObservables(globSet), GlobalObservablesSource("model"), ExternalConstraints(smearSet), Range("range"), SplitRange(kTRUE)); //Best Result
  //RooMinimizer minim(*nll, RooMinimizer::FcnMode::gradient);

  
  RooMinimizer minim(*nll);
  minim.setStrategy(2);
  minim.setPrintEvalErrors(-1);
  minim.setPrintLevel(0);
  minim.optimizeConst(2);
  minim.setMinimizerType("Minuit");
  minim.setOffsetting(kTRUE);
  minim.setMaxFunctionCalls(100000);
  minim.setMaxIterations(100000);
  minim.setEps(0.5);
  //RooFitResult * r8 = minim.save();
  minim.minimize("Minuit", "migradimproved");
  //minim.migrad();
  //minim.improve();
  //RooFitResult * r8 = minim.save();
  minim.hesse();
  //minim.minos(muZH_240GeV);

  //RooFitResult * r9 = minim.save();

  //r8->Print();
  //r9->Print();

  cout << combWS->var("muZH_240GeV")->getVal() << endl;

  //RooProfileLL plc("plc", "plc", *nll, poiSet);
  //plc.setAlwaysStartFromMin(kFALSE);

  //cout << plc.alwaysStartFromMin() << endl;

  //RooArgSet bestFit = plc.bestFitParams();

  //bestFit.Print();




 /*

  RooStats::ProfileLikelihoodCalculator plc(*asimov, *combModel, poiSet);

  plc.SetGlobalObservables(globSet);
  plc.SetNuisanceParameters(nuisSet);
  plc.SetConditionalObservables(smearSet);

  plc.SetConfidenceLevel(0.683);

  RooStats::LikelihoodInterval * interval = plc.GetInterval();
  double lowerLimit = interval->LowerLimit(muZH_240GeV);
  double upperLimit = interval->UpperLimit(muZH_240GeV);

  cout << lowerLimit << endl;

  */

  
  

  /*

  // C o n s t r u c t   p r o f i l e   l i k e l i h o o d   i n   k l
 // -----------------------------------------------------------------------

 // The profile likelihood estimator on nll for Nsig will minimize nll w.r.t
 // all floating parameters except Nsig for each evaluation

 c4 -> cd();

 RooPlot *frame4 = varKappa_240GeV.frame(Range(-8., 17.), Title("NLL in #delta#kappa_{#lambda} "), Bins(500));
  frame4 -> GetXaxis() ->SetRangeUser(-8, +17.);

  RooAbsReal *pll_kl = nll->createProfile(varKappa_240GeV);
  RooAbsReal *pll_bbH_kl = nll_bbH->createProfile(varKappa_240GeV);

  pll_kl -> plotOn(frame4, LineColor(kRed),LineStyle(kSolid));
  pll_bbH_kl -> plotOn(frame4, LineColor(kBlack),LineStyle(kDashed));

  frame4->GetYaxis()->SetTitleOffset(1.4);
  frame4->SetMinimum(0.);
  frame4->SetMaximum(8.);
  frame4->Draw(); 
  c4->Draw(); 
  c4->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/combined_plots/NLL_prf_kl.pdf");

  */

 /*

  // C o n s t r u c t   p r o f i l e   l i k e l i h o o d   i n   m u Z H
 // -----------------------------------------------------------------------

 // The profile likelihood estimator on nll for Nsig will minimize nll w.r.t
 // all floating parameters except Nsig for each evaluation

  c5 -> cd();

  RooPlot *frame5 = muZH_240GeV.frame(Range(0.95, 1.05), Title("NLL in #mu ZH "), Bins(100));
  frame5 -> GetXaxis() ->SetRangeUser(0.95, 1.05);

  //nll_bbH->plotOn(frame5,LineColor(kAzure-2), ShiftToZero());
  //RooAbsReal *pll_muZH = nll->createProfile(muZH_240GeV);
  RooAbsReal *pll_muZH = plc.createProfile(muZH_240GeV);
  pll_muZH-> plotOn(frame5, LineColor(kRed),LineStyle(kSolid));

  //RooAbsReal * nll_bbH = model_bbH->createNLL(*asimov_bbH, Save(), Extended(kTRUE), Offset(kTRUE), NumCPU(8, 0), GlobalObservables(RooArgSet(*Lmess_240GeV_bbH, *Emess_240GeV_bbH, *BRmess_240GeV_bbH)), PrintEvalErrors(-1));
  //RooMinimizer minim_bbH(*nll_bbH);
  //minim_bbH.migrad();

  //RooAbsReal *pll_bbH_muZH = nll_bbH->createProfile(muZH_240GeV);
  //pll_bbH_muZH -> plotOn(frame5, LineColor(kBlack),LineStyle(kDashed));

  frame5->GetYaxis()->SetTitleOffset(1.4);
  frame5->SetMinimum(-10.);
  frame5->SetMaximum(10.);
  frame5->Draw(); 
  c5->Draw(); 
  c5->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/combination/aplots/NLL_prf_muZH.pdf");

  //combWS->Print();
  //model_bbH->Print("t");

*/

}


