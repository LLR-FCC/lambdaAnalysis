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

    TFile bbH("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/qqH/bbH/ZbbH240_muZH.root");
    TFile bcH("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/qqH/bcH/ZbcH240_muZH.root");
    TFile bjH("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/qqH/bjH/ZbjH240_muZH.root");
    TFile ccH("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/qqH/ccH/ZccH240_muZH.root");
    TFile cjH("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/qqH/cjH/ZcjH240_muZH.root");
    TFile ijH("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/qqH/ijH/ZijH240_muZH.root");
    TFile mumuH("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/ZmumuH240_muZH.root");
    TFile eeH("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/eeH/ZeeH240_muZH.root");
    TFile mumuH_365("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/mumuH/ZmumuH365_muZH.root");
    TFile eeH_365("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/ZeeH365_muZH.root");
    gROOT->cd();
    


    RooWorkspace *bbH_WS = (RooWorkspace*)bbH.Get("w");
    RooWorkspace *bcH_WS = (RooWorkspace*)bcH.Get("w");
    RooWorkspace *bjH_WS = (RooWorkspace*)bjH.Get("w");
    RooWorkspace *ccH_WS = (RooWorkspace*)ccH.Get("w");
    RooWorkspace *cjH_WS = (RooWorkspace*)cjH.Get("w");
    RooWorkspace *ijH_WS = (RooWorkspace*)ijH.Get("w");
    RooWorkspace *mumuH_WS = (RooWorkspace*)mumuH.Get("w");
    RooWorkspace *eeH_WS = (RooWorkspace*)eeH.Get("w");

    RooWorkspace *mumuH_WS_365 = (RooWorkspace*)mumuH_365.Get("w");
    RooWorkspace *eeH_WS_365 = (RooWorkspace*)eeH_365.Get("w");
    

    //Get original models
    RooAbsPdf * model_bbH = bbH_WS->pdf("model");
    RooAbsPdf * model_bcH = bcH_WS->pdf("model");
    RooAbsPdf * model_bjH = bjH_WS->pdf("model");
    RooAbsPdf * model_ccH = ccH_WS->pdf("model");
    RooAbsPdf * model_cjH = cjH_WS->pdf("model");
    RooAbsPdf * model_ijH = ijH_WS->pdf("model");
    RooAbsPdf * model_mumuH = mumuH_WS->pdf("model");
    RooAbsPdf * model_eeH = eeH_WS->pdf("model");
    RooAbsPdf * model_mumuH_365 = mumuH_WS_365->pdf("model");
    RooAbsPdf * model_eeH_365 = eeH_WS_365->pdf("model");

    //cout << "models = " << model_bbH << " " << model_bcH << endl;

    //Import data
    
    RooDataSet* wdata_bbH = (RooDataSet*)bbH_WS->data("centrally_samples");
    RooDataSet* wdata_bcH = (RooDataSet*)bcH_WS->data("centrally_samples");
    RooDataSet* wdata_bjH = (RooDataSet*)bjH_WS->data("centrally_samples");
    RooDataSet* wdata_ccH = (RooDataSet*)ccH_WS->data("centrally_samples");
    RooDataSet* wdata_cjH = (RooDataSet*)cjH_WS->data("centrally_samples");
    RooDataSet* wdata_ijH = (RooDataSet*)ijH_WS->data("centrally_samples");

    RooDataSet* adata_bbH = (RooDataSet*)bbH_WS->data("bbH_Asimov");
    RooDataSet* adata_bcH = (RooDataSet*)bcH_WS->data("bcH_Asimov");
    RooDataSet* adata_bjH = (RooDataSet*)bjH_WS->data("bjH_Asimov");
    RooDataSet* adata_ccH = (RooDataSet*)ccH_WS->data("ccH_Asimov");
    RooDataSet* adata_cjH = (RooDataSet*)cjH_WS->data("cjH_Asimov");
    RooDataSet* adata_ijH = (RooDataSet*)ijH_WS->data("ijH_Asimov");
    RooDataSet* adata_mumuH = (RooDataSet*)mumuH_WS->data("mumuH_Asimov");
    RooDataSet* adata_eeH = (RooDataSet*)eeH_WS->data("eeH_Asimov");
    
    RooDataSet* adata_mumuH_365 = (RooDataSet*)mumuH_WS_365->data("mumuH_Asimov");
    RooDataSet* adata_eeH_365 = (RooDataSet*)eeH_WS_365->data("eeH_Asimov");
    
    bbH_WS->loadSnapshot("bbH_asimovFit");
    bcH_WS->loadSnapshot("bcH_asimovFit");
    bjH_WS->loadSnapshot("bjH_asimovFit");
    ccH_WS->loadSnapshot("ccH_asimovFit");
    cjH_WS->loadSnapshot("cjH_asimovFit");
    ijH_WS->loadSnapshot("ijH_asimovFit");
    mumuH_WS->loadSnapshot("mumuH_asimovFit");
    eeH_WS->loadSnapshot("eeH_asimovFit");
    mumuH_WS_365->loadSnapshot("mumuH_asimovFit");
    eeH_WS_365->loadSnapshot("eeH_asimovFit");

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    (*mumuH_WS->var("NL")).setConstant(kTRUE);
    (*eeH_WS->var("NL")).setConstant(kTRUE);
    (*mumuH_WS_365->var("NL")).setConstant(kTRUE);
    (*eeH_WS_365->var("NL")).setConstant(kTRUE);

    (*mumuH_WS->var("NR")).setConstant(kTRUE);
    (*eeH_WS->var("NR")).setConstant(kTRUE);
    (*mumuH_WS_365->var("NR")).setConstant(kTRUE);
    (*eeH_WS_365->var("NR")).setConstant(kTRUE);

    (*mumuH_WS->var("alphaL")).setConstant(kTRUE);
    (*eeH_WS->var("alphaL")).setConstant(kTRUE);
    (*mumuH_WS_365->var("alphaL")).setConstant(kTRUE);
    (*eeH_WS_365->var("alphaL")).setConstant(kTRUE);

    (*mumuH_WS->var("alphaR")).setConstant(kTRUE);
    (*eeH_WS->var("alphaR")).setConstant(kTRUE);
    (*mumuH_WS_365->var("alphaR")).setConstant(kTRUE);
    (*eeH_WS_365->var("alphaR")).setConstant(kTRUE);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //wdata_bbH->Print();
    //wdata_bcH->Print();
    //wdata_bjH->Print();
    //adata_bbH->Print();
    //adata_bcH->Print();
    //adata_bjH->Print();


    //cout << wdata_bbH_240->get() << endl;
    

    //dh_bbH_240->Print();
    //dh_bcH_240->Print();

    RooWorkspace* combWS = new RooWorkspace("combWS");
    combWS->import(*model_bbH, RenameAllNodes("bbH"), RenameAllVariables("bbH"));
    combWS->import(*model_bcH, RenameAllNodes("bcH"), RenameAllVariables("bcH"));
    combWS->import(*model_bjH, RenameAllNodes("bjH"), RenameAllVariables("bjH"));
    combWS->import(*model_ccH, RenameAllNodes("ccH"), RenameAllVariables("ccH"));
    combWS->import(*model_cjH, RenameAllNodes("cjH"), RenameAllVariables("cjH"));
    combWS->import(*model_ijH, RenameAllNodes("ijH"), RenameAllVariables("ijH"));
    combWS->import(*model_mumuH, RenameAllNodes("mumuH"), RenameAllVariables("mumuH"));
    combWS->import(*model_eeH, RenameAllNodes("eeH"), RenameAllVariables("eeH"));
    combWS->import(*model_mumuH_365, RenameAllNodes("mumuH_365"), RenameAllVariables("mumuH_365"));
    combWS->import(*model_eeH_365, RenameAllNodes("eeH_365"), RenameAllVariables("eeH_365"));

    RooCategory* channel = new RooCategory("channel","channel");
    channel -> defineType("bjH",0);
    channel -> defineType("bbH",1);
    channel -> defineType("bcH",2);
    channel -> defineType("ccH",3);
    channel -> defineType("cjH",4);
    channel -> defineType("ijH",5);
    channel -> defineType("mumuH",6);
    channel -> defineType("eeH",7);
    channel -> defineType("mumuH_365",8);
    channel -> defineType("eeH_365",9);
    combWS ->import(*channel);

    //combWS -> allCats ();
    cout << "hi3" << endl;
    RooArgSet vars_bbH = *((RooArgSet*)wdata_bbH->get()->clone("vars"));
    RooArgSet avars_bbH = *((RooArgSet*)adata_bbH->get()->clone("avars"));
    vars_bbH.Print();
    avars_bbH.Print();
    combWS ->import("weight_T1");

    RooArgSet vars_bcH = *((RooArgSet*)wdata_bbH->get()->clone("vars"));
    RooArgSet avars_bcH = *((RooArgSet*)adata_bcH->get()->clone("avars"));

    RooArgSet vars_bjH = *((RooArgSet*)wdata_bjH->get()->clone("vars"));
    RooArgSet avars_bjH = *((RooArgSet*)adata_bjH->get()->clone("avars"));

    RooArgSet vars_ccH = *((RooArgSet*)wdata_ccH->get()->clone("vars"));
    RooArgSet avars_ccH = *((RooArgSet*)adata_ccH->get()->clone("avars"));

    RooArgSet vars_cjH = *((RooArgSet*)wdata_cjH->get()->clone("vars"));
    RooArgSet avars_cjH = *((RooArgSet*)adata_cjH->get()->clone("avars"));

    RooArgSet vars_ijH = *((RooArgSet*)wdata_ijH->get()->clone("vars"));
    RooArgSet avars_ijH = *((RooArgSet*)adata_ijH->get()->clone("avars"));

    RooArgSet avars_mumuH = *((RooArgSet*)adata_mumuH->get()->clone("avars"));
    RooArgSet avars_eeH = *((RooArgSet*)adata_eeH->get()->clone("avars"));
    RooRealVar *wavars_mumuH = ((RooRealVar*)adata_mumuH->weightVar()->clone("wavars_mumuH"));
    RooRealVar *wavars_eeH = ((RooRealVar*)adata_eeH->weightVar()->clone("wavars_eeH"));

    RooArgSet avars_mumuH_365 = *((RooArgSet*)adata_mumuH_365->get()->clone("avars"));
    RooArgSet avars_eeH_365 = *((RooArgSet*)adata_eeH_365->get()->clone("avars"));
    RooRealVar *wavars_mumuH_365 = ((RooRealVar*)adata_mumuH_365->weightVar()->clone("wavars_mumuH_365"));
    RooRealVar *wavars_eeH_365 = ((RooRealVar*)adata_eeH_365->weightVar()->clone("wavars_eeH_365"));


    RooRealVar *wvars_bbH = ((RooRealVar*)wdata_bbH->weightVar()->clone("wvars_bbH"));
    RooRealVar *wvars_bcH = ((RooRealVar*)wdata_bcH->weightVar()->clone("wvars_bcH"));
    RooRealVar *wvars_bjH = ((RooRealVar*)wdata_bjH->weightVar()->clone("wvars_bjH"));
    RooRealVar *wvars_ccH = ((RooRealVar*)wdata_ccH->weightVar()->clone("wvars_ccH"));
    RooRealVar *wvars_cjH = ((RooRealVar*)wdata_cjH->weightVar()->clone("wvars_cjH"));
    RooRealVar *wvars_ijH = ((RooRealVar*)wdata_ijH->weightVar()->clone("wvars_ijH"));

    RooRealVar *wavars_bbH = ((RooRealVar*)adata_bbH->weightVar()->clone("wavars_bbH"));
    RooRealVar *wavars_bcH = ((RooRealVar*)adata_bcH->weightVar()->clone("wavars_bcH"));
    RooRealVar *wavars_bjH = ((RooRealVar*)adata_bjH->weightVar()->clone("wavars_bjH"));
    RooRealVar *wavars_ccH = ((RooRealVar*)adata_ccH->weightVar()->clone("wavars_ccH"));
    RooRealVar *wavars_cjH = ((RooRealVar*)adata_cjH->weightVar()->clone("wavars_cjH"));
    RooRealVar *wavars_ijH = ((RooRealVar*)adata_ijH->weightVar()->clone("wavars_ijH"));
    vars_bcH.Print();

    bbH_WS->Print();
    bcH_WS->Print();
    bjH_WS->Print();
    cout << wvars_bcH->GetName() << endl;

    avars_mumuH.Print();
    

    


  // W E I G H T E D  D A T A S E T
  // ------------------------------
  
  RooFormulaVar wFuncbjH("weight2","weight2","(0.128168685)",*bjH_WS->var("MRec")) ;  // Nicht noetig
  RooFormulaVar wFuncbbH("weight2","weight2","(0.103594239)",*bbH_WS->var("MRec")) ; // (#Weighted events / # Total events) 
  RooFormulaVar wFuncbcH("weight2","weight2","(0.128168685)",*bcH_WS->var("MRec")) ;  // Nicht noetig
  
  
  RooFormulaVar wFuncccH("weight2","weight2","(0.128168685)",*ccH_WS->var("MRec")) ; // (#Weighted events / # Total events) 
  RooFormulaVar wFunccjH("weight2","weight2","(0.128168685)",*cjH_WS->var("MRec")) ;  // Nicht noetig
  RooFormulaVar wFuncijH("weight2","weight2","(0.128168685)",*ijH_WS->var("MRec")) ;  // Nicht noetig

  

   
  RooDataSet* combData = new RooDataSet("combData","combined dataset", RooArgSet(vars_bjH, wvars_bjH) ,Index(*channel),Import("bjH",*wdata_bjH), WeightVar("wvars_bjH"));  //WeightVar(w)
  combData->Print();
  RooRealVar * weight = (RooRealVar *)combData->addColumn(wFuncbjH);
  RooDataSet * wcombData = new RooDataSet(combData->GetName(), combData->GetTitle(), combData, *combData->get(), 0, weight->GetName());
  wcombData->Print();
  cout << wcombData->isWeighted() << endl; 

  RooDataSet* combData1 = new RooDataSet("combData1","combined dataset1", RooArgSet(vars_bbH, wvars_bbH), Index(*channel),Import("bbH",*wdata_bbH), WeightVar("wvars_bbH"));  //WeightVar(w)
  combData1->Print();
  RooRealVar * weight1 = (RooRealVar *)combData1->addColumn(wFuncbbH);
  RooDataSet * wcombData1 = new RooDataSet(combData1->GetName(), combData1->GetTitle(), combData1, *combData1->get(), 0, weight1->GetName());
  wcombData1->Print();
  cout << wcombData1->isWeighted() << endl;

  RooDataSet* combData2 = new RooDataSet("combData2","combined dataset2", RooArgSet(vars_bcH, wvars_bcH), Index(*channel),Import("bcH",*wdata_bcH), WeightVar("wvars_bcH"));  //WeightVar(w)
  combData2->Print();
  RooRealVar * weight2 = (RooRealVar *)combData2->addColumn(wFuncbcH);
  RooDataSet * wcombData2 = new RooDataSet(combData2->GetName(), combData2->GetTitle(), combData2, *combData2->get(), 0, weight2->GetName());
  wcombData2->Print();
  cout << wcombData2->isWeighted() << endl;

  RooDataSet* combData3 = new RooDataSet("combData3","combined dataset3", RooArgSet(vars_ccH, wvars_ccH), Index(*channel),Import("ccH",*wdata_ccH), WeightVar("wvars_ccH"));  //WeightVar(w)
  combData3->Print();
  RooRealVar * weight3 = (RooRealVar *)combData3->addColumn(wFuncccH);
  RooDataSet * wcombData3 = new RooDataSet(combData3->GetName(), combData3->GetTitle(), combData3, *combData3->get(), 0, weight3->GetName());
  wcombData3->Print();
  cout << wcombData3->isWeighted() << endl;

  RooDataSet* combData4 = new RooDataSet("combData4","combined dataset4", RooArgSet(vars_cjH, wvars_cjH), Index(*channel),Import("cjH",*wdata_cjH), WeightVar("wvars_cjH"));  //WeightVar(w)
  combData4->Print();
  RooRealVar * weight4 = (RooRealVar *)combData4->addColumn(wFunccjH);
  RooDataSet * wcombData4 = new RooDataSet(combData4->GetName(), combData4->GetTitle(), combData4, *combData4->get(), 0, weight4->GetName());
  wcombData4->Print();
  cout << wcombData4->isWeighted() << endl;

  RooDataSet* combData5 = new RooDataSet("combData5","combined dataset5", RooArgSet(vars_ijH, wvars_ijH), Index(*channel),Import("ijH",*wdata_ijH), WeightVar("wvars_ijH"));  //WeightVar(w)
  combData5->Print();
  RooRealVar * weight5 = (RooRealVar *)combData5->addColumn(wFuncijH);
  RooDataSet * wcombData5 = new RooDataSet(combData5->GetName(), combData5->GetTitle(), combData5, *combData5->get(), 0, weight5->GetName());
  wcombData5->Print();
  cout << wcombData5->isWeighted() << endl;
 
  wcombData->append(*wcombData1);
  combData->append(*combData1);  
  wcombData->append(*wcombData2);
  combData->append(*combData2);
  wcombData->append(*wcombData3);
  combData->append(*combData3);
  wcombData->append(*wcombData4);
  combData->append(*combData4);
  wcombData->append(*wcombData5);
  combData->append(*combData5);

  wcombData->Print();
  cout << wcombData->isWeighted() << endl; 

  // A S I M O V  D A T A S E T
  // --------------------------

  adata_bbH->Print();
  RooDataSet* acombData = new RooDataSet("acombData", "combined Asimov dataset", RooArgSet(avars_bjH, wavars_bjH) ,Index(*channel),Import("bjH",*adata_bjH), WeightVar("wavars_bjH"));
  RooDataSet* acombData_bbH = new RooDataSet("acombData_bbH", "combined Asimov dataset", RooArgSet(avars_bbH, wavars_bbH) ,Index(*channel),Import("bbH",*adata_bbH), WeightVar("wavars_bbH"));
  RooDataSet* acombData_bcH = new RooDataSet("acombData_bcH", "combined Asimov dataset", RooArgSet(avars_bcH, wavars_bcH) ,Index(*channel),Import("bcH",*adata_bcH), WeightVar("wavars_bcH"));
  RooDataSet* acombData_ccH = new RooDataSet("acombData_ccH", "combined Asimov dataset", RooArgSet(avars_ccH, wavars_ccH) ,Index(*channel),Import("ccH",*adata_ccH), WeightVar("wavars_ccH"));
  RooDataSet* acombData_cjH = new RooDataSet("acombData_cjH", "combined Asimov dataset", RooArgSet(avars_cjH, wavars_cjH) ,Index(*channel),Import("cjH",*adata_cjH), WeightVar("wavars_cjH"));
  RooDataSet* acombData_ijH = new RooDataSet("acombData_ijH", "combined Asimov dataset", RooArgSet(avars_ijH, wavars_ijH) ,Index(*channel),Import("ijH",*adata_ijH), WeightVar("wavars_ijH"));
  RooDataSet* acombData_mumuH = new RooDataSet("acombData_mumuH", "combined Asimov dataset", RooArgSet(avars_mumuH, wavars_mumuH) ,Index(*channel),Import("mumuH",*adata_mumuH), WeightVar("wavars_mumuH"));
  RooDataSet* acombData_eeH = new RooDataSet("acombData_eeH", "combined Asimov dataset", RooArgSet(avars_eeH, wavars_eeH) ,Index(*channel),Import("eeH",*adata_eeH), WeightVar("wavars_eeH"));

  RooDataSet* acombData_mumuH_365 = new RooDataSet("acombData_mumuH_365", "combined Asimov dataset", RooArgSet(avars_mumuH_365, wavars_mumuH_365) ,Index(*channel),Import("mumuH_365",*adata_mumuH_365), WeightVar("wavars_mumuH_365"));
  RooDataSet* acombData_eeH_365 = new RooDataSet("acombData_eeH_365", "combined Asimov dataset", RooArgSet(avars_eeH_365, wavars_eeH_365) ,Index(*channel),Import("eeH_365",*adata_eeH_365), WeightVar("wavars_eeH_365"));

  RooDataSet* acombData_bjH = new RooDataSet("acombData_bjH", "combined Asimov dataset", RooArgSet(avars_bjH, wavars_bjH) ,Index(*channel),Import("bjH",*adata_bjH), WeightVar("wavars_bjH"));
  

  acombData->Print();

  acombData->append(*acombData_bbH);
  acombData->append(*acombData_bcH);
  acombData->append(*acombData_ccH);
  acombData->append(*acombData_cjH);
  acombData->append(*acombData_ijH);
  acombData->append(*acombData_mumuH);
  acombData->append(*acombData_eeH);
  acombData->append(*acombData_mumuH_365);
  acombData->append(*acombData_eeH_365);

  acombData->Print();
  wdata_bbH->Print();

  combWS->import(*acombData);
  combWS->import(*acombData_bbH);
  combWS->import(*acombData_bcH);
  combWS->import(*acombData_bjH);
  combWS->import(*acombData_ccH);
  combWS->import(*acombData_cjH);
  combWS->import(*acombData_ijH);
  combWS->import(*acombData_mumuH);
  combWS->import(*acombData_eeH); //, RenameVariable("MRec", "MRec_eeH")
  combWS->import(*acombData_mumuH_365);
  combWS->import(*acombData_eeH_365);


  //acombData->Print("V");

 //RooDataSet* wcombData = new RooDataSet("combData","combined dataset",vars_bbH,Index(*channel),Import("bbH",*wdata_bbH_240));
 //RooDataSet* wcombData2 = new RooDataSet("combData2","combined dataset",vars_bcH,Index(*channel),Import("bcH",*wdata_bcH_240));
 //wcombData->append(*wcombData2);

//wcombData->Print();
    

    cout << "hi" << endl;
    combData->Print();
    //combData3->Print();

    

    // Create joint pdf 
  
    combWS->factory("SIMUL::joint(channel,bbH=model_bbH,bcH=model_bcH, bjH=model_bjH, ccH=model_ccH, cjH=model_cjH, ijH=model_ijH, mumuH=model_mumuH, eeH=model_eeH, mumuH_365=model_mumuH_365, eeH_365=model_eeH_365)") ;
    //combWS->factory("SIMUL::joint(channel,bbH=model_bbH,bcH=model_bcH, bjH=model_bjH, ccH=model_ccH, cjH=model_cjH, ijH=model_ijH)") ;
    //combWS -> import(*bbH_WS -> var("mHmess_240GeV"));
    //combWS -> import(*bbH_WS -> var("varKappa_240GeV"));
    combWS -> import(*bbH_WS -> var("muZH_240GeV"));
    combWS -> import(*mumuH_WS_365 -> var("muZH_365GeV"));
    combWS -> import(*mumuH_WS -> var("mHmess_240GeV"));
    combWS -> import(*mumuH_WS_365 -> var("mHmess_365GeV"));
    //combWS -> import(*(bjH_WS -> var("MRec")), Rename("MRec_Meddl"));  //RESOLVE!!!
    RooRealVar * mrec = combWS -> var("MRec");
    //RooRealVar * mrec2 = combWS -> var("MRec_bjH");

    mrec->Print();
    //mrec2->Print();

    //combWS -> import(*bbH_WS -> var("BRmess_240GeV"));
    //combWS -> import(*bbH_WS -> var("Lmess_240GeV"));
    //combWS -> import(*bbH_WS -> var("COMmess_240GeV"));
    //combWS -> import(*bbH_WS -> var("Emess_240GeV"));

    //combWS -> import(*bcH_WS -> var("BRmess_240GeV"));
    //combWS -> import(*bcH_WS -> var("Lmess_240GeV"));
    //combWS -> import(*bcH_WS -> var("COMmess_240GeV"));
    //combWS -> import(*bcH_WS -> var("Emess_240GeV"));

    RooAbsPdf * Lsmear_240GeV = bbH_WS->pdf("Lsmear_240GeV");
    RooAbsPdf * Esmear_240GeV = bbH_WS->pdf("Esmear_240GeV");
    //RooAbsPdf * COMsmear_240GeV = bbH_WS->pdf("COMsmear_240GeV");
    RooAbsPdf * BRsmear_240GeV = bbH_WS->pdf("BRsmear_240GeV");

    //combWS -> factory("EDIT::combModel(joint, MRec_bbH = MRec, MRec_bcH = MRec, mHmess_240GeV_bbH = mHmess_240GeV, mHmess_240GeV_bcH = mHmess_240GeV, varKappa_240GeV_bbH = varKappa_240GeV, varKappa_240GeV_bcH = varKappa_240GeV)");
    
    //combWS -> factory("EDIT::combModel(joint, muZH_240GeV_bbH = muZH_240GeV, muZH_240GeV_bcH = muZH_240GeV, muZH_240GeV_bjH = muZH_240GeV, muZH_240GeV_ccH = muZH_240GeV, muZH_240GeV_cjH = muZH_240GeV, muZH_240GeV_ijH = muZH_240GeV, muZH_240GeV_mumuH = muZH_240GeV, muZH_240GeV_eeH = muZH_240GeV)");

    combWS -> factory("EDIT::combModel(joint, MRec_bbH = MRec, MRec_bcH = MRec, MRec_bjH = MRec, MRec_ccH = MRec, MRec_cjH = MRec, MRec_ijH = MRec, MRec_mumuH = MRec, MRec_eeH = MRec, MRec_eeH_365=MRec, MRec_mumuH_365=MRec, muZH_240GeV_bbH = muZH_240GeV, muZH_240GeV_bcH = muZH_240GeV, muZH_240GeV_bjH = muZH_240GeV, muZH_240GeV_ccH = muZH_240GeV, muZH_240GeV_cjH = muZH_240GeV, muZH_240GeV_ijH = muZH_240GeV, muZH_240GeV_mumuH = muZH_240GeV, muZH_240GeV_eeH = muZH_240GeV, muZH_365GeV_mumuH_365 = muZH_240GeV, muZH_365GeV_eeH_365 = muZH_240GeV, mHmess_240GeV_mumuH=mHmess_240GeV, mHmess_240GeV_eeH=mHmess_240GeV, mHmess_365GeV_mumuH_365=mHmess_240GeV, mHmess_365GeV_eeH_365=mHmess_240GeV)");
    


    RooAbsPdf* combModel_split = combWS->pdf("joint");

    cout << "model joint split ...." << endl;
    //combModel_split->Print("t");

    RooAbsPdf* combModel = combWS->pdf("combModel");

    cout << "model combined ...." << endl;
    combModel->Print("t");

    RooArgSet *params = combModel->getParameters(*mrec);
    RooArgSet *initParams = (RooArgSet *)params->snapshot();
    initParams->Print("t");

    combWS->defineSet("poi", "muZH_240GeV");
    //w->defineSet("poi", "varKappa_240GeV");
    //combWS->defineSet("np", RooArgSet(sigma_240GeV, alphaL_240GeV, alphaR_240GeV, NL_240GeV, NR_240GeV, mean2_240GeV, sigma2_240GeV, fsig, fsig2, N, mHmess_240GeV), kTRUE);
    combWS->defineSet("np", "sigma_bbH,sigma2_bbH,sigma3_bbH,sigma4_bbH,mean2_bbH,mean3_bbH,mean4_bbH,fsig_bbH,fsig2_bbH,fsig3_bbH,N_bbH,mean_bbH,sigma_bcH,sigma2_bcH,sigma3_bcH,sigma4_bcH,mean2_bcH,mean3_bcH,mean4_bcH,fsig_bcH,fsig2_bcH,fsig3_bcH,N_bcH,mean_bcH,sigma_bjH,sigma2_bjH,sigma3_bjH,sigma4_bjH,mean2_bjH,mean3_bjH,mean4_bjH,fsig_bjH,fsig2_bjH,fsig3_bjH,N_bjH,mean_bjH,sigma_ccH,sigma2_ccH,mean2_ccH,fsig_ccH,N_ccH,mean_ccH,sigma_cjH,sigma2_cjH,sigma3_cjH,sigma4_cjH,mean2_cjH,mean3_cjH,mean4_cjH,fsig_cjH,fsig2_cjH,fsig3_cjH,N_cjH,mean_cjH,sigma_ijH,sigma2_ijH,sigma3_ijH,sigma4_ijH,mean2_ijH,mean3_ijH,mean4_ijH,fsig_ijH,fsig2_ijH,fsig3_ijH,N_ijH,mean_ijH,sigma_mumuH,sigma2_240GeV_mumuH,mean2_240GeV_mumuH,fsig_mumuH,fsig2_mumuH,N_mumuH,sigma_eeH,sigma2_240GeV_eeH,mean2_240GeV_eeH,fsig_eeH,fsig2_eeH,N_eeH,mHmess_240GeV,sigma_mumuH_365,sigma2_365GeV_mumuH_365,mean2_365GeV_mumuH_365,fsig_mumuH_365,fsig2_mumuH_365,N_365GeV_mumuH_365,sigma_eeH_365,sigma2_365GeV_eeH_365,mean2_365GeV_eeH_365,fsig_eeH_365,fsig2_eeH_365,N_365GeV_eeH_365,mHmess_365GeV");
    combWS->defineSet("glob", "BRmess_240GeV_bcH,BRmess_240GeV_bbH,BRmess_240GeV_bjH,BRmess_240GeV_ccH,BRmess_240GeV_cjH,BRmess_240GeV_ijH,Emess_240GeV_bcH,Emess_240GeV_bjH,Emess_240GeV_bbH,Emess_240GeV_ccH,Emess_240GeV_cjH,Emess_240GeV_ijH,Lmess_240GeV_bcH,Lmess_240GeV_bjH,Lmess_240GeV_bbH,Lmess_240GeV_ccH,Lmess_240GeV_cjH,Lmess_240GeV_ijH,COMmess_240GeV_mumuH,COMmess_240GeV_eeH,BRmess_240GeV_mumuH,BRmess_240GeV_eeH,Emess_240GeV_mumuH,Emess_240GeV_eeH,Lmess_240GeV_mumuH,Lmess_240GeV_eeH,COMmess_365GeV_mumuH_365,COMmess_365GeV_eeH_365,BRmess_365GeV_mumuH_365,BRmess_365GeV_eeH_365,Emess_365GeV_mumuH_365,Emess_365GeV_eeH_365,Lmess_365GeV_mumuH_365,Lmess_365GeV_eeH_365");
    combWS->defineSet("constr", "BRsmear_240GeV_bcH,BRsmear_240GeV_bbH,BRsmear_240GeV_bjH,BRsmear_240GeV_ccH,BRsmear_240GeV_cjH,BRsmear_240GeV_ijH,Esmear_240GeV_bcH,Esmear_240GeV_bjH,Esmear_240GeV_bbH,Esmear_240GeV_ccH,Esmear_240GeV_cjH,Esmear_240GeV_ijH,Lsmear_240GeV_bcH,Lsmear_240GeV_bjH,Lsmear_240GeV_bbH,Lsmear_240GeV_ccH,Lsmear_240GeV_cjH,Lsmear_240GeV_ijH,COMsmear_240GeV_mumuH,COMsmear_240GeV_eeH,BRsmear_240GeV_mumuH,BRsmear_240GeV_eeH,Esmear_240GeV_mumuH,Esmear_240GeV_eeH,Lsmear_240GeV_mumuH,Lsmear_240GeV_eeH,COMsmear_365GeV_mumuH_365,COMsmear_365GeV_eeH_365,BRsmear_365GeV_mumuH_365,BRsmear_365GeV_eeH_365,Esmear_365GeV_mumuH_365,Esmear_365GeV_eeH_365,Lsmear_365GeV_mumuH_365,Lsmear_365GeV_eeH_365");
    combWS->defineSet("obs", "MRec");
    //combWS->defineSet("obs", "MRec_bbH,MRec_bcH,MRec_bjH,MRec_ccH,MRec_cjH,MRec_ijH,MRec_mumuH,MRec_eeH");

    RooArgSet globSet = *(combWS->set("glob"));
    RooArgSet nuisSet = *(combWS->set("np"));
    RooArgSet poiSet = *(combWS->set("poi"));
    RooArgSet smearSet = *(combWS->set("constr"));

    combWS->Print();

    combModel->Print("t");
    acombData->Print("t");




    //Combined fit

    //RooFitResult * r =  combModel -> fitTo(*combData,Save(), Extended(kTRUE), Offset(kTRUE), Constrain(RooArgSet(Lsmear_240GeV, Esmear_240GeV, BRsmear_240GeV)));  //SumW2Error(kTRUE)
    
    //RooFitResult * r =  combModel -> fitTo(*combData,Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(*Lsmear_240GeV, *Esmear_240GeV)), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit2","migrad"));  //SumW2Error(kTRUE)
    
    RooFitResult * r =  combModel -> fitTo(*acombData,Save(),  Extended(kTRUE), Offset(kTRUE), NumCPU(8, 0), GlobalObservables(globSet), ExternalConstraints(smearSet), Strategy(2), Minos(kTRUE));  //SumW2Error(kTRUE),  Extended(kTRUE), Offset(kTRUE), ExternalConstraints(RooArgSet(*Lsmear_240GeV, *Esmear_240GeV, *BRsmear_240GeV)), GlobalObservables(globSet), , Minimizer("Minuit","migradimproved")


    r->Print("s");

    //combWS->Print();

    //combData2->Print();
    //combData4->Print();

    //combData->get(66)->Print("V");
    //combData->printArgs(cout);
    //combData4->get(29)->Print("V");
    //combData2->get(99)->Print("V");
    //cout << combData4->sum(kFALSE) << endl;
    //cout << combData2->weight() << endl;

    RooRealVar * mrec_bbH = combWS -> var("MRec_bbH");
    //RooRealVar varKappa_240GeV = *(combWS -> var("varKappa_240GeV"));
    RooRealVar muZH_240GeV = *(combWS -> var("muZH_240GeV"));
    RooRealVar muZH_240GeV_bbH = *(combWS -> var("muZH_240GeV_bbH"));
    RooAbsPdf * model_bbH_pdf = combWS->pdf("model_bbH");

    RooArgSet *combFitParameters = (RooArgSet*)combModel->getParameters(*mrec);
    combWS->saveSnapshot("combinedFit", *combFitParameters, kTRUE);

    //RooArgSet *bbHFitParameters = (RooArgSet*)model_bbH_pdf->getParameters(*mrec_bbH);
    //combWS->saveSnapshot("bbHFit", *bbHFitParameters, kTRUE);
    
    //mrec->setBins(67);
    //mrec2->setBins(70);

    /*

    cout << "hi2" << endl;
    wcombData->Print();

    TCanvas* c = new TCanvas("rf501_simultaneouspdf","rf403_simultaneouspdf",800,400) ;
    TCanvas* c2 = new TCanvas("rf501_simultaneouspdf2","rf403_simultaneouspdf2",800,400) ;
    
    c->Divide(3) ;
    c2->Divide(3) ;
    c->cd(1) ; 

   // P l o t   m o d e l   s l i c e s   o n   d a t a    s l i c e s 
   // ----------------------------------------------------------------
   // Make a frame for the physics sample
   RooPlot* frame1 = mrec->frame(Name("bbH"),Title("bbH"), Bins(60)) ;
   frame1 -> GetXaxis() ->SetRangeUser(80., 160.); 
   // Plot all data tagged as physics sample
   //combData->plotOn(frame1);
   combData->plotOn(frame1,Cut("channel == channel::bbH")) ;
   //acombData->plotOn(frame1,Cut("channel == channel::bbH")) ;
   // Plot "physics" slice of simultaneous pdf. 
   // NBL You _must_ project the sample index category with data using ProjWData 
   // as a RooSimultaneous makes no prediction on the shape in the index category 
   // and can thus not be integrated
   
   combModel->plotOn(frame1,Slice(*channel,"bbH"),ProjWData(*channel,*combData)) ;
   //combModel->plotOn(frame1,Slice(*channel,"bbH"),Components("model_bbH_combModel"),ProjWData(*channel,*combData),LineStyle(kDashed)) ;
   
   // The same plot for the control sample slice

   //RooDataHist *testDH = (RooDataHist *)combData->reduce(vars_bbH, "channel==channel::bcH");

   
   RooPlot* frame2 = mrec->frame(Name("bcH"),Title("bcH"), Bins(60)) ;
   frame2 -> GetXaxis() ->SetRangeUser(80., 160.); 
   //combData->plotOn(frame2,Cut("channel==channel::bcH")) ;
   combData->plotOn(frame2,Cut("channel == channel::bcH")) ;
   //acombData->plotOn(frame2,Cut("channel == channel::bcH")) ;
   
   combModel->plotOn(frame2,Slice(*channel,"bcH"),ProjWData(*channel,*combData)) ;
   //combModel->plotOn(frame2,Slice(channel,"control"),Components("px_ctl"),ProjWData(channel,combData),LineStyle(kDashed)) ;

   RooPlot* frame3 = mrec->frame(Name("bjH"),Title("bjH"), Bins(60)) ;
   frame3 -> GetXaxis() ->SetRangeUser(20., 160.); 
   combData->plotOn(frame3,Cut("channel == channel::bjH")) ;
   //acombData->plotOn(frame3,Cut("channel == channel::bjH")) ;
   
   combModel->plotOn(frame3,Slice(*channel,"bjH"),ProjWData(*channel,*combData)) ;
   //combModel->plotOn(frame3,Slice(channel,"control"),Components("px_ctl"),ProjWData(channel,combData),LineStyle(kDashed)) ;

   RooPlot* frame4 = mrec->frame(Name("ccH"),Title("ccH"), Bins(60)) ;
   frame4 -> GetXaxis() ->SetRangeUser(110., 160.); 
   combData->plotOn(frame4,Cut("channel == channel::ccH")) ;
   //acombData->plotOn(frame3,Cut("channel == channel::ccH")) ;
   
   combModel->plotOn(frame4,Slice(*channel,"ccH"),ProjWData(*channel,*combData)) ;
   //combModel->plotOn(frame3,Slice(channel,"control"),Components("px_ctl"),ProjWData(channel,combData),LineStyle(kDashed)) ;

   RooPlot* frame5 = mrec->frame(Name("cjH"),Title("cjH"), Bins(60)) ;
   frame5 -> GetXaxis() ->SetRangeUser(100., 160.); 
   combData->plotOn(frame5,Cut("channel == channel::cjH")) ;
   //acombData->plotOn(frame3,Cut("channel == channel::cjH")) ;
   
   combModel->plotOn(frame5,Slice(*channel,"cjH"),ProjWData(*channel,*combData)) ;
   //combModel->plotOn(frame3,Slice(channel,"control"),Components("px_ctl"),ProjWData(channel,combData),LineStyle(kDashed)) ;

   RooPlot* frame6 = mrec->frame(Name("ijH"),Title("ijH"), Bins(60)) ;
   frame6 -> GetXaxis() ->SetRangeUser(100., 160.); 
   combData->plotOn(frame6,Cut("channel == channel::ijH")) ;
   //acombData->plotOn(frame3,Cut("channel == channel::ijH")) ;
   
   combModel->plotOn(frame6,Slice(*channel,"ijH"),ProjWData(*channel,*combData)) ;
   //combModel->plotOn(frame3,Slice(channel,"control"),Components("px_ctl"),ProjWData(channel,combData),LineStyle(kDashed)) ;
   

   gPad->SetLeftMargin(0.15) ; 
   frame1->GetYaxis()->SetTitleOffset(1.4) ; 
   frame1->Draw() ;
   
   c->cd(2) ; 
   gPad->SetLeftMargin(0.15) ; 
   frame2->GetYaxis()->SetTitleOffset(1.4) ;
   frame2->Draw() ;

   c->cd(3) ; 
   gPad->SetLeftMargin(0.15) ; 
   frame3->GetYaxis()->SetTitleOffset(1.4) ;
   frame3->Draw() ;
   
   c->Draw();
   c->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/qqH/combined_plots/simultaneousFit.pdf");

   c2->cd(1) ; 
   gPad->SetLeftMargin(0.15) ; 
   frame4->GetYaxis()->SetTitleOffset(1.4) ;
   frame4->Draw() ;

   c2->cd(2) ; 
   gPad->SetLeftMargin(0.15) ; 
   frame5->GetYaxis()->SetTitleOffset(1.4) ;
   frame5->Draw() ;

   c2->cd(3) ; 
   gPad->SetLeftMargin(0.15) ; 
   frame6->GetYaxis()->SetTitleOffset(1.4) ;
   frame6->Draw() ;
     

  c2->Draw();
  c2->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/qqH/combined_plots/simultaneousFit2.pdf");


  combWS->Print();

  */



  // C o n s t r u c t  A s i m o v  d a t a s e t
  // ---------------------------------------------
  
  


  RooStats::ModelConfig mc("mc", combWS);
  mc.SetPdf("combModel");
  mc.SetObservables(*(combWS->set("obs")));
  mc.SetParametersOfInterest(poiSet);
  mc.SetNuisanceParameters(nuisSet);
  mc.SetGlobalObservables(globSet);
  mc.SetConstraintParameters(smearSet);

  combWS->var("muZH_240GeV")->setVal(1);
  mc.SetSnapshot(*(combWS->var("muZH_240GeV")));

  mc.Print();

  combWS->import(mc);

  //r->Print("s");
  
  RooArgSet combSet = RooArgSet(poiSet, nuisSet, "combSet");


  const RooArgSet * genPoiValues = 0;

  RooAbsData * asimov = RooStats::AsymptoticCalculator::MakeAsimovData(*acombData, mc, combSet, globSet, genPoiValues);  //ACHTUNG: Asimov vom Asimov!!!

  RooFitResult * r2 = combModel->fitTo(*asimov,Save(), Extended(kTRUE), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit","migradimproved"), GlobalObservables(globSet), ExternalConstraints(smearSet), Strategy(2));
  //RooFitResult * r3 = combModel->fitTo(*asimov,Save(), Extended(kTRUE), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit2","migrad"), GlobalObservables(globSet), ExternalConstraints(smearSet), Strategy(2));

  std::cout << "Asimov designed for mu = 1 gave mu-hat = " << combWS->var("muZH_240GeV")->getVal() << std::endl;
  
  combWS->import(*asimov, Rename("combined_Asimov"));

  RooArgSet *asimov_parameters = (RooArgSet*)combModel->getParameters(*mrec);
  combWS->saveSnapshot("asimovFit", *asimov_parameters, kTRUE);

  r2->Print();
  //r3->Print();


  combWS->writeToFile("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/combination/WScombinedModel_muZH.root");


  /*
   // C o n s t r u c t   p l a i n   l i k e l i h o o d
   // ---------------------------------------------------
 TCanvas* c4 = new TCanvas ("c4", "c4", 100, 200, 700, 500);
 TCanvas* c5 = new TCanvas ("c5", "c5", 100, 200, 700, 500);

  // Construct unbinned likelihood
  RooAbsReal * nll = combModel->createNLL(*asimov, Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(*Lsmear_240GeV, *Esmear_240GeV, *BRsmear_240GeV)), Offset(kTRUE), NumCPU(8, 0), PrintEvalErrors(-1)); //Best Result
  RooAbsReal * nll_bbH = model_bbH_pdf->createNLL(*asimov, Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(*Lsmear_240GeV, *Esmear_240GeV, *BRsmear_240GeV)), Offset(kTRUE), NumCPU(8, 0), PrintEvalErrors(-1));
  RooMinimizer minim(*nll);
  minim.migrad();

  RooMinimizer minim_bbH(*nll_bbH);
  minim_bbH.migrad();
  
  
  //nll->plotOn(frame4,LineColor(kAzure-2), ShiftToZero());


  */
  

  /*

  // C o n s t r u c t   p r o f i l e   l i k e l i h o o d   i n   k l
 // -----------------------------------------------------------------------

 // The profile likelihood estimator on nll for Nsig will minimize nll w.r.t
 // all floating parameters except Nsig for each evaluation

 c4 -> cd();

 RooPlot *frame4 = varKappa_240GeV.frame(Range(-8., 17.), Title("NLL in #delta#kappa_{#lambda} "), Bins(50));
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

  RooPlot *frame98 = muZH_240GeV.frame(Range(0.7, 1.3), Title("NLL in #mu ZH "), Bins(60));
  frame98 -> GetXaxis() ->SetRangeUser(0.9, 1.1);

  RooAbsReal *pll_muZH = nll->createProfile(muZH_240GeV);
  RooAbsReal *pll_bbH_muZH = nll_bbH->createProfile(muZH_240GeV_bbH);

  pll_muZH-> plotOn(frame98, LineColor(kRed),LineStyle(kSolid));
  pll_bbH_muZH -> plotOn(frame98, LineColor(kBlack),LineStyle(kDashed));

  frame98->GetYaxis()->SetTitleOffset(1.4);
  frame98->SetMinimum(0.);
  frame98->SetMaximum(4.);
  frame98->Draw(); 
  c5->Draw(); 
  c5->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/qqH/combined_plots/NLL_prf_muZH.pdf");

  */
  
  
  



    


}