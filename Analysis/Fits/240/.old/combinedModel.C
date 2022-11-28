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
using namespace RooFit;

void combinedModel() {
    // Import workspace

    TFile mumuH("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/ZmumuH240_muZH.root");
    TFile eeH("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/eeH/ZeeH240_muZH.root");
    gROOT->cd();
    


    RooWorkspace *mumuH_240 = (RooWorkspace*)mumuH.Get("w");
    RooWorkspace *eeH_240 = (RooWorkspace*)eeH.Get("w");

    //Get original models
    RooAbsPdf * model_mumuH_240 = mumuH_240->pdf("model");
    RooAbsPdf * model_eeH_240 = eeH_240->pdf("model");

    
    

    cout << "models = " << model_mumuH_240 << " " << model_eeH_240 << endl;

    //Import data

    //RooDataHist* dh_mumuH_240 = (RooDataHist*)mumuH_240->data("dh");
    //RooDataHist* dh_eeH_240 = (RooDataHist*)eeH_240->data("dh");
    
    RooDataSet* wdata_mumuH_240 = (RooDataSet*)mumuH_240->data("centrally_samples");
    RooDataSet* wdata_eeH_240 = (RooDataSet*)eeH_240->data("centrally_samples");

    wdata_mumuH_240->Print();
    wdata_eeH_240->Print();

    cout << wdata_mumuH_240->get() << endl;
    

    //dh_mumuH_240->Print();
    //dh_eeH_240->Print();

    RooWorkspace* combWS = new RooWorkspace("combWS");
    combWS->import(*model_mumuH_240, RenameAllNodes("mumuH"), RenameAllVariables("mumuH"));
    combWS->import(*model_eeH_240, RenameAllNodes("eeH"), RenameAllVariables("eeH"));

    RooCategory* channel = new RooCategory("channel","channel");
    channel -> defineType("mumuH",0);
    channel -> defineType("eeH",1);
    combWS ->import(*channel);

    //combWS -> allCats ();
    cout << "hi3" << endl;
    RooArgSet vars_mumuH = *((RooArgSet*)wdata_mumuH_240->get()->clone("vars"));
    vars_mumuH.Print();
    combWS ->import("weight_T1");

    RooArgSet vars_eeH = *((RooArgSet*)wdata_eeH_240->get()->clone("vars"));
    RooRealVar *wvars_mumuH = ((RooRealVar*)wdata_mumuH_240->weightVar()->clone("wvars_mumuH"));
    RooRealVar *wvars_eeH = ((RooRealVar*)wdata_eeH_240->weightVar()->clone("wvars_eeH"));
    vars_eeH.Print();

    mumuH_240->Print();
    cout << wvars_eeH->GetName() << endl;

    //RooFormulaVar wFunc240("weight","weight","(0.769572809226021)",*MEAS_240->var("m_recoil_T")) ;
    //RooFormulaVar wFunc365("weight","weight","(0.0828920124233495)",*MEAS_365->var("m_recoil_T")) ;
    
   RooFormulaVar wFunc240("weight2","weight2","(0.103594239)",*mumuH_240->var("MRec")) ; //#Weighted events / # Total events
  RooFormulaVar wFunc365("weight2","weight2","(0.128168685)",*eeH_240->var("MRec")) ;
   
  RooDataSet* combData = new RooDataSet("combData","combined dataset", RooArgSet(vars_mumuH, wvars_mumuH) ,Index(*channel),Import("mumuH",*wdata_mumuH_240), WeightVar("wvars_mumuH"));  //WeightVar(w)
  combData->Print();
  RooRealVar * weight = (RooRealVar *)combData->addColumn(wFunc240);
  RooDataSet * wcombData = new RooDataSet(combData->GetName(), combData->GetTitle(), combData, *combData->get(), 0, weight->GetName());
  wcombData->Print();
  cout << wcombData->isWeighted() << endl; 

  RooDataSet* combData1 = new RooDataSet("combData1","combined dataset1", RooArgSet(vars_eeH, wvars_eeH), Index(*channel),Import("eeH",*wdata_eeH_240), WeightVar("wvars_eeH"));  //WeightVar(w)
  combData1->Print();
  RooRealVar * weight1 = (RooRealVar *)combData1->addColumn(wFunc365);
  RooDataSet * wcombData1 = new RooDataSet(combData1->GetName(), combData1->GetTitle(), combData1, *combData1->get(), 0, weight1->GetName());
  wcombData1->Print();
  cout << wcombData1->isWeighted() << endl;
 
  wcombData->append(*wcombData1);
  combData->append(*combData1);  

  wcombData->Print();
  cout << wcombData->isWeighted() << endl; 



 //RooDataSet* wcombData = new RooDataSet("combData","combined dataset",vars_mumuH,Index(*channel),Import("mumuH",*wdata_mumuH_240));
 //RooDataSet* wcombData2 = new RooDataSet("combData2","combined dataset",vars_eeH,Index(*channel),Import("eeH",*wdata_eeH_240));
 //wcombData->append(*wcombData2);

//wcombData->Print();
    
   /*
    RooDataHist* combData = new RooDataHist("combData","combined dataset",vars_mumuH,Index(*channel),Import("mumuH",*dh_mumuH_240));
    RooDataHist* combData2 = new RooDataHist("combData2","combined dataset2",vars_eeH,Index(*channel),Import("eeH",*dh_eeH_240));
    RooFormulaVar* cutVar=0;
    //Das binning von vars_mumuH und vars_eeH ist das problem!
    combData->add(*combData2, "channel==channel::eeH", 1.0);
    

    RooDataHist* combData3 = new RooDataHist("combData3", "combined dataset", vars_eeH, Index(*channel), Import({{"eeH", dh_eeH_240}, {"mumuH", dh_mumuH_240}}));
    RooDataHist* combData4 = new RooDataHist("combData4", "combined dataset", vars_mumuH, Index(*channel), Import("mumuH",*dh_mumuH_240));

    */
    
    cout << "hi" << endl;
    combData->Print();
    //combData3->Print();

    

    // Create joint pdf 
  
    combWS->factory("SIMUL::joint(channel,mumuH=model_mumuH,eeH=model_eeH)") ;
    combWS -> import(*mumuH_240 -> var("mHmess_240GeV"));
    //combWS -> import(*mumuH_240 -> var("varKappa_240GeV"));
    combWS -> import(*mumuH_240 -> var("muZH_240GeV"));
    combWS -> import(*mumuH_240 -> var("MRec"));
    

    //combWS -> import(*mumuH_240 -> var("BRmess_240GeV"));
    //combWS -> import(*mumuH_240 -> var("Lmess_240GeV"));
    //combWS -> import(*mumuH_240 -> var("COMmess_240GeV"));
    //combWS -> import(*mumuH_240 -> var("Emess_240GeV"));

    //combWS -> import(*eeH_240 -> var("BRmess_240GeV"));
    //combWS -> import(*eeH_240 -> var("Lmess_240GeV"));
    //combWS -> import(*eeH_240 -> var("COMmess_240GeV"));
    //combWS -> import(*eeH_240 -> var("Emess_240GeV"));

    RooAbsPdf * Lsmear_240GeV = mumuH_240->pdf("Lsmear_240GeV");
    RooAbsPdf * Esmear_240GeV = mumuH_240->pdf("Esmear_240GeV");
    RooAbsPdf * COMsmear_240GeV = mumuH_240->pdf("COMsmear_240GeV");
    RooAbsPdf * BRsmear_240GeV = mumuH_240->pdf("BRsmear_240GeV");

    //combWS -> factory("EDIT::combModel(joint, MRec_mumuH = MRec, MRec_eeH = MRec, mHmess_240GeV_mumuH = mHmess_240GeV, mHmess_240GeV_eeH = mHmess_240GeV, varKappa_240GeV_mumuH = varKappa_240GeV, varKappa_240GeV_eeH = varKappa_240GeV)");
    combWS -> factory("EDIT::combModel(joint, MRec_mumuH = MRec, MRec_eeH = MRec, mHmess_240GeV_mumuH = mHmess_240GeV, mHmess_240GeV_eeH = mHmess_240GeV, muZH_240GeV_mumuH = muZH_240GeV, muZH_240GeV_eeH = muZH_240GeV)");
    

    RooAbsPdf* combModel_split = combWS->pdf("joint");

    cout << "model joint split ...." << endl;
    //combModel_split->Print("t");

    RooAbsPdf* combModel = combWS->pdf("combModel");

    cout << "model combined ...." << endl;
    //combModel->Print("t");

    //Combined fit

    //RooFitResult * r =  combModel -> fitTo(*combData,Save(), Extended(kTRUE), Offset(kTRUE), Constrain(RooArgSet(Lsmear_240GeV, Esmear_240GeV, COMsmear_240GeV, BRsmear_240GeV)));  //SumW2Error(kTRUE)
    //RooFitResult * r =  combModel -> fitTo(*combData,Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(*Lsmear_240GeV, *Esmear_240GeV, *COMsmear_240GeV)), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit2","migrad"));  //SumW2Error(kTRUE)


    //r->Print("s");

    //combData2->Print();
    //combData4->Print();

    //combData->get(66)->Print("V");
    //combData->printArgs(cout);
    //combData4->get(29)->Print("V");
    //combData2->get(99)->Print("V");
    //cout << combData4->sum(kFALSE) << endl;
    //cout << combData2->weight() << endl;

    RooRealVar * mrec_mumuH = combWS -> var("MRec_mumuH");
    RooRealVar * mrec = combWS -> var("MRec");
    RooRealVar * mrec2 = combWS -> var("MRec");
    //RooRealVar varKappa_240GeV = *(combWS -> var("varKappa_240GeV"));
    RooRealVar muZH_240GeV = *(combWS -> var("muZH_240GeV"));
    RooRealVar muZH_240GeV_mumuH = *(combWS -> var("muZH_240GeV_mumuH"));
    RooAbsPdf * model_mumuH = combWS->pdf("model_mumuH");
    
    //mrec->setBins(67);
    //mrec2->setBins(70);

    cout << "hi2" << endl;
    wcombData->Print();

    TCanvas* c = new TCanvas("rf501_simultaneouspdf","rf403_simultaneouspdf",800,400) ;
    
    c->Divide(2) ;
    c->cd(1) ; 

   // P l o t   m o d e l   s l i c e s   o n   d a t a    s l i c e s 
   // ----------------------------------------------------------------
   // Make a frame for the physics sample
   RooPlot* frame1 = mrec->frame(Name("mumuH"),Title("mumuH"), Bins(100)) ;
   (frame1 -> GetXaxis()) ->SetRangeUser(120., 139.5); 
   // Plot all data tagged as physics sample
   //combData->plotOn(frame1);
   combData->plotOn(frame1,Cut("channel == channel::mumuH")) ;
   // Plot "physics" slice of simultaneous pdf. 
   // NBL You _must_ project the sample index category with data using ProjWData 
   // as a RooSimultaneous makes no prediction on the shape in the index category 
   // and can thus not be integrated
   
   combModel->plotOn(frame1,Slice(*channel,"mumuH"),ProjWData(*channel,*combData)) ;
   //combModel->plotOn(frame1,Slice(*channel,"mumuH"),Components("model_mumuH_combModel"),ProjWData(*channel,*combData),LineStyle(kDashed)) ;
   
   // The same plot for the control sample slice

   //RooDataHist *testDH = (RooDataHist *)combData->reduce(vars_mumuH, "channel==channel::eeH");

   
   RooPlot* frame2 = mrec2->frame(Name("eeH"),Title("eeH"), Bins(100)) ;
   frame2 -> GetXaxis() ->SetRangeUser(120., 139.5); 
   //combData->plotOn(frame2,Cut("channel==channel::eeH")) ;
   combData->plotOn(frame2,Cut("channel == channel::eeH")) ;
   
   combModel->plotOn(frame2,Slice(*channel,"eeH"),ProjWData(*channel,*combData)) ;
   //combModel->plotOn(frame2,Slice(channel,"control"),Components("px_ctl"),ProjWData(channel,combData),LineStyle(kDashed)) ;
   

   gPad->SetLeftMargin(0.15) ; 
   frame1->GetYaxis()->SetTitleOffset(1.4) ; 
   frame1->Draw() ;
   
   c->cd(2) ; 
   gPad->SetLeftMargin(0.15) ; 
   frame2->GetYaxis()->SetTitleOffset(1.4) ;
   frame2->Draw() ;
     
  c->Draw();

  combWS->Print();

  // C o n s t r u c t  A s i m o v  d a t a s e t
  // ---------------------------------------------
  
  combWS->defineSet("poi", "muZH_240GeV");
  //w->defineSet("poi", "varKappa_240GeV");
  //combWS->defineSet("np", RooArgSet(sigma_240GeV, alphaL_240GeV, alphaR_240GeV, NL_240GeV, NR_240GeV, mean2_240GeV, sigma2_240GeV, fsig, fsig2, N, mHmess_240GeV), kTRUE);
  combWS->defineSet("np", "sigma_mumuH,alphaL_mumuH,alphaR_mumuH,NL_mumuH,NR_mumuH,mean2_240GeV_mumuH,sigma2_240GeV_mumuH,fsig_mumuH,fsig2_mumuH,N_mumuH,sigma_eeH,alphaL_eeH,alphaR_eeH,NL_eeH,NR_eeH,mean2_240GeV_eeH,sigma2_240GeV_eeH,fsig_eeH,fsig2_eeH,N_eeH,mHmess_240GeV");
  combWS->defineSet("glob", "BRmess_240GeV_eeH,BRmess_240GeV_mumuH,COMmess_240GeV_eeH,COMmess_240GeV_mumuH,Emess_240GeV_eeH,Emess_240GeV_mumuH,Lmess_240GeV_eeH,Lmess_240GeV_mumuH");
  combWS->defineSet("obs", "MRec");

  RooArgSet globSet = *(combWS->set("glob"));
  RooArgSet nuisSet = *(combWS->set("np"));
  RooArgSet poiSet = *(combWS->set("poi"));



  RooStats::ModelConfig mc(combWS);
  mc.SetPdf("combModel");
  mc.SetObservables(*(combWS->set("obs")));
  mc.SetParametersOfInterest(poiSet);
  mc.SetNuisanceParameters(nuisSet);
  mc.SetGlobalObservables(globSet);

  combWS->var("muZH_240GeV")->setVal(1);
  mc.SetSnapshot(*(combWS->var("muZH_240GeV")));

  mc.Print();

  combWS->import(mc);

  const RooArgSet * genPoiValues = 0;

  RooAbsData * asimov = RooStats::AsymptoticCalculator::MakeAsimovData(*combData, mc, poiSet, globSet, genPoiValues);

  combWS->pdf("combModel")->fitTo(*asimov,Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(*Lsmear_240GeV, *Esmear_240GeV, *COMsmear_240GeV)), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit2","migrad"));

  std::cout << "Asimov designed for mu = 1 gave mu-hat = " << combWS->var("muZH_240GeV")->getVal() << std::endl;


  


  

  

   // C o n s t r u c t   p l a i n   l i k e l i h o o d
   // ---------------------------------------------------
 TCanvas* c4 = new TCanvas ("c4", "c4", 100, 200, 700, 500);
 TCanvas* c5 = new TCanvas ("c5", "c5", 100, 200, 700, 500);

  // Construct unbinned likelihood
  RooAbsReal * nll = combModel->createNLL(*asimov, Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(*Lsmear_240GeV, *Esmear_240GeV, *COMsmear_240GeV, *BRsmear_240GeV)), Offset(kTRUE), NumCPU(8, 0)); //Best Result
  RooAbsReal * nll_mumuH = model_mumuH->createNLL(*asimov, Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(*Lsmear_240GeV, *Esmear_240GeV, *COMsmear_240GeV, *BRsmear_240GeV)), Offset(kTRUE), NumCPU(8, 0));
  RooMinimizer minim(*nll);
  minim.migrad();

  RooMinimizer minim_mumuH(*nll_mumuH);
  minim_mumuH.migrad();
  
  
  //nll->plotOn(frame4,LineColor(kAzure-2), ShiftToZero());

  
  

  /*

  // C o n s t r u c t   p r o f i l e   l i k e l i h o o d   i n   k l
 // -----------------------------------------------------------------------

 // The profile likelihood estimator on nll for Nsig will minimize nll w.r.t
 // all floating parameters except Nsig for each evaluation

 c4 -> cd();

 RooPlot *frame4 = varKappa_240GeV.frame(Range(-8., 17.), Title("NLL in #delta#kappa_{#lambda} "), Bins(500));
  frame4 -> GetXaxis() ->SetRangeUser(-8, +17.);

  RooAbsReal *pll_kl = nll->createProfile(varKappa_240GeV);
  RooAbsReal *pll_mumuH_kl = nll_mumuH->createProfile(varKappa_240GeV);

  pll_kl -> plotOn(frame4, LineColor(kRed),LineStyle(kSolid));
  pll_mumuH_kl -> plotOn(frame4, LineColor(kBlack),LineStyle(kDashed));

  frame4->GetYaxis()->SetTitleOffset(1.4);
  frame4->SetMinimum(0.);
  frame4->SetMaximum(8.);
  frame4->Draw(); 
  c4->Draw(); 
  c4->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/combined_plots/NLL_prf_kl.pdf");

  */


  
  // C o n s t r u c t   p r o f i l e   l i k e l i h o o d   i n   m u Z H
 // -----------------------------------------------------------------------

 // The profile likelihood estimator on nll for Nsig will minimize nll w.r.t
 // all floating parameters except Nsig for each evaluation

 c5 -> cd();

  RooPlot *frame5 = muZH_240GeV.frame(Range(0.7, 1.3), Title("NLL in #mu ZH "), Bins(500));
  frame5 -> GetXaxis() ->SetRangeUser(0.7, 1.3);

  RooAbsReal *pll_muZH = nll->createProfile(muZH_240GeV);
  RooAbsReal *pll_mumuH_muZH = nll_mumuH->createProfile(muZH_240GeV_mumuH);

  pll_muZH-> plotOn(frame5, LineColor(kRed),LineStyle(kSolid));
  pll_mumuH_muZH -> plotOn(frame5, LineColor(kBlack),LineStyle(kDashed));

  frame5->GetYaxis()->SetTitleOffset(1.4);
  frame5->SetMinimum(0.);
  frame5->SetMaximum(6.);
  frame5->Draw(); 
  c5->Draw(); 
  c5->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/combined_plots/NLL_prf_muZH.pdf");

  
  
  



    


}