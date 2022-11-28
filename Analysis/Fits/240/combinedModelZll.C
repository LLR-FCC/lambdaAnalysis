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
#include "RooLinkedList.h"
#include "RooCmdArg.h"


using namespace std;
using namespace RooFit;

void combinedModelZll() {
    // Import workspace

    TFile mumuH("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/ZmumuH240_muZH.root");
    TFile eeH("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/eeH/ZeeH240_muZH_2.root");
    gROOT->cd();
    
    RooWorkspace *mumuH_WS = (RooWorkspace*)mumuH.Get("w");
    RooWorkspace *eeH_WS = (RooWorkspace*)eeH.Get("w");

    (*eeH_WS->var("sigma2_240GeV")).setRange(0, 0.01, 10.);
   (*mumuH_WS->var("sigma2_240GeV")).setRange(0, 0.01, 10.);
   (*mumuH_WS->var("mean2_240GeV")).setMax(129.);
   (*eeH_WS->var("mean2_240GeV")).setMax(129.);

    //Get original models
    RooAbsPdf * model_mumuH = mumuH_WS->pdf("model");
    RooAbsPdf * model_eeH = eeH_WS->pdf("model");

    RooAbsPdf * bareModel_mumuH = mumuH_WS->pdf("modelBare");
    RooAbsPdf * bareModel_eeH = eeH_WS->pdf("modelBare");

    //cout << "models = " << model_bbH << " " << model_bcH << endl;

    //Import data
    
    RooDataSet* adata_mumuH = (RooDataSet*)mumuH_WS->data("mumuH_Asimov");
    RooDataSet* adata_eeH = (RooDataSet*)eeH_WS->data("eeH_Asimov");

    RooDataSet* adataBare_mumuH = (RooDataSet*)mumuH_WS->data("mumuH_Asimov_bare");
    RooDataSet* adataBare_eeH = (RooDataSet*)eeH_WS->data("eeH_Asimov_bare");

    mumuH_WS->loadSnapshot("mumuH_asimovFit");
    eeH_WS->loadSnapshot("eeH_asimovFit");


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    (*mumuH_WS->var("NL")).setConstant(kTRUE);
    (*eeH_WS->var("NL")).setConstant(kTRUE);

    (*mumuH_WS->var("NR")).setConstant(kTRUE);
    (*eeH_WS->var("NR")).setConstant(kTRUE);

    (*mumuH_WS->var("alphaL")).setConstant(kTRUE);
    (*eeH_WS->var("alphaL")).setConstant(kTRUE);

    (*mumuH_WS->var("alphaR")).setConstant(kTRUE);
    (*eeH_WS->var("alphaR")).setConstant(kTRUE);

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

    RooWorkspace* combWS = new RooWorkspace("combWS_Zll");
    combWS->import(*model_mumuH, RenameAllNodes("mumuH"), RenameAllVariables("mumuH"));
    combWS->import(*model_eeH, RenameAllNodes("eeH"), RenameAllVariables("eeH"));

    combWS->import(*bareModel_mumuH, RenameAllNodes("mumuH"), RenameAllVariables("mumuH"));
    combWS->import(*bareModel_eeH, RenameAllNodes("eeH"), RenameAllVariables("eeH"));

    RooCategory* channel = new RooCategory("channel","channel");
    channel -> defineType("mumuH",0);
    channel -> defineType("eeH",1);
    combWS ->import(*channel);

    //combWS -> allCats ();
    cout << "hi3" << endl;
  
    RooArgSet avars_mumuH = *((RooArgSet*)adata_mumuH->get()->clone("avars_mumuH"));
    RooArgSet avars_eeH = *((RooArgSet*)adata_eeH->get()->clone("avars_eeH"));
    RooRealVar *wavars_mumuH = ((RooRealVar*)adata_mumuH->weightVar()->clone("wavars_mumuH"));
    RooRealVar *wavars_eeH = ((RooRealVar*)adata_eeH->weightVar()->clone("wavars_eeH"));
    
    RooArgSet avarsBare_mumuH = *((RooArgSet*)adataBare_mumuH->get()->clone("avarsBare_mumuH"));
    RooArgSet avarsBare_eeH = *((RooArgSet*)adataBare_eeH->get()->clone("avarsBare_eeH"));
    RooRealVar *wavarsBare_mumuH = ((RooRealVar*)adataBare_mumuH->weightVar()->clone("wavarsBare_mumuH"));
    RooRealVar *wavarsBare_eeH = ((RooRealVar*)adataBare_eeH->weightVar()->clone("wavarsBare_eeH"));

    avars_mumuH.Print();
    

  // A S I M O V  D A T A S E T
  // --------------------------

  RooDataSet* acombData = new RooDataSet("acombData", "combined Asimov dataset", RooArgSet(avars_mumuH, wavars_mumuH) ,Index(*channel),Import("mumuH",*adata_mumuH), WeightVar("wavars_mumuH"));
  RooDataSet* acombData_eeH = new RooDataSet("acombData_eeH", "combined Asimov dataset", RooArgSet(avars_eeH, wavars_eeH) ,Index(*channel),Import("eeH",*adata_eeH), WeightVar("wavars_eeH"));

  RooDataSet* acombDataBare = new RooDataSet("acombDataBare", "combined Asimov dataset", RooArgSet(avarsBare_mumuH, wavarsBare_mumuH) ,Index(*channel),Import("mumuH",*adataBare_mumuH), WeightVar("wavarsBare_mumuH"));
  RooDataSet* acombDataBare_eeH = new RooDataSet("acombDataBare_eeH", "combined Asimov dataset", RooArgSet(avarsBare_eeH, wavarsBare_eeH) ,Index(*channel),Import("eeH",*adataBare_eeH), WeightVar("wavarsBare_eeH"));



  acombData->Print();
  acombData->append(*acombData_eeH);

  acombDataBare->append(*acombDataBare_eeH);


  combWS->import(*acombData);
  combWS->import(*acombData_eeH); //, RenameVariable("MRec", "MRec_eeH")


  //acombData->Print("V");

 //RooDataSet* wcombData = new RooDataSet("combData","combined dataset",vars_bbH,Index(*channel),Import("bbH",*wdata_bbH_240));
 //RooDataSet* wcombData2 = new RooDataSet("combData2","combined dataset",vars_bcH,Index(*channel),Import("bcH",*wdata_bcH_240));
 //wcombData->append(*wcombData2);

//wcombData->Print();
    

    cout << "hi" << endl;
    //combData3->Print();

    

    // Create joint pdf 
  
    combWS->factory("SIMUL::joint(channel, mumuH=model_mumuH, eeH=model_eeH)") ;
    combWS->factory("SIMUL::joint_bare(channel, mumuH=modelBare_mumuH, eeH=modelBare_eeH)") ;
    //combWS->factory("SIMUL::joint(channel,bbH=model_bbH,bcH=model_bcH, bjH=model_bjH, ccH=model_ccH, cjH=model_cjH, ijH=model_ijH)") ;
    combWS -> import(*mumuH_WS -> var("mHmess_240GeV"));
    //combWS -> import(*bbH_WS -> var("varKappa_240GeV"));
    combWS -> import(*mumuH_WS -> var("muZH_240GeV"));
    //combWS -> import(*(bjH_WS -> var("MRec")), Rename("MRec_Meddl"));  //RESOLVE!!!
    RooRealVar * mrec = combWS -> var("MRec");
    //RooRealVar * mrec2 = combWS -> var("MRec_bjH");
    
    mrec->setRange("range_mumuH", 120., 140.);
    mrec->setRange("range_eeH", 120., 140.);

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

    RooAbsPdf * Lsmear_240GeV = mumuH_WS->pdf("Lsmear_240GeV");
    RooAbsPdf * Esmear_240GeV = mumuH_WS->pdf("Esmear_240GeV");
    RooAbsPdf * COMsmear_240GeV = mumuH_WS->pdf("COMsmear_240GeV");
    RooAbsPdf * BRsmear_240GeV = mumuH_WS->pdf("BRsmear_240GeV");

    //combWS -> factory("EDIT::combModel(joint, MRec_bbH = MRec, MRec_bcH = MRec, mHmess_240GeV_bbH = mHmess_240GeV, mHmess_240GeV_bcH = mHmess_240GeV, varKappa_240GeV_bbH = varKappa_240GeV, varKappa_240GeV_bcH = varKappa_240GeV)");
    
    //combWS -> factory("EDIT::combModel(joint, muZH_240GeV_bbH = muZH_240GeV, muZH_240GeV_bcH = muZH_240GeV, muZH_240GeV_bjH = muZH_240GeV, muZH_240GeV_ccH = muZH_240GeV, muZH_240GeV_cjH = muZH_240GeV, muZH_240GeV_ijH = muZH_240GeV, muZH_240GeV_mumuH = muZH_240GeV, muZH_240GeV_eeH = muZH_240GeV)");

    combWS -> factory("EDIT::combModel(joint, MRec_mumuH = MRec, MRec_eeH = MRec, muZH_240GeV_mumuH = muZH_240GeV, muZH_240GeV_eeH = muZH_240GeV, mHmess_240GeV_mumuH=mHmess_240GeV, mHmess_240GeV_eeH=mHmess_240GeV)");

    combWS -> factory("EDIT::combModel_bare(joint_bare, MRec_mumuH = MRec, MRec_eeH = MRec, muZH_240GeV_mumuH = muZH_240GeV, muZH_240GeV_eeH = muZH_240GeV, mHmess_240GeV_mumuH=mHmess_240GeV, mHmess_240GeV_eeH=mHmess_240GeV)");


    RooAbsPdf* combModel_split = combWS->pdf("joint");

    cout << "model joint split ...." << endl;
    //combModel_split->Print("t");

    RooAbsPdf* combModel = combWS->pdf("combModel");
    RooAbsPdf* combModel_bare = combWS->pdf("combModel_bare");

    cout << "model combined ...." << endl;
    //combModel->Print("t");

    RooArgSet *params = combModel->getParameters(*mrec);
    RooArgSet *initParams = (RooArgSet *)params->snapshot();
    initParams->Print("t");

    combWS->defineSet("poi", "muZH_240GeV");
    //w->defineSet("poi", "varKappa_240GeV");
    //combWS->defineSet("np", RooArgSet(sigma_240GeV, alphaL_240GeV, alphaR_240GeV, NL_240GeV, NR_240GeV, mean2_240GeV, sigma2_240GeV, fsig, fsig2, N, mHmess_240GeV), kTRUE);
    //combWS->defineSet("np", "sigma_bbH,sigma2_bbH,sigma3_bbH,sigma4_bbH,mean2_bbH,mean3_bbH,mean4_bbH,fsig_bbH,fsig2_bbH,fsig3_bbH,N_bbH,mean_bbH,sigma_bcH,sigma2_bcH,sigma3_bcH,sigma4_bcH,mean2_bcH,mean3_bcH,mean4_bcH,fsig_bcH,fsig2_bcH,fsig3_bcH,N_bcH,mean_bcH,sigma_bjH,sigma2_bjH,sigma3_bjH,sigma4_bjH,mean2_bjH,mean3_bjH,mean4_bjH,fsig_bjH,fsig2_bjH,fsig3_bjH,N_bjH,mean_bjH,sigma_ccH,sigma2_ccH,mean2_ccH,fsig_ccH,N_ccH,mean_ccH,sigma_cjH,sigma2_cjH,sigma3_cjH,sigma4_cjH,mean2_cjH,mean3_cjH,mean4_cjH,fsig_cjH,fsig2_cjH,fsig3_cjH,N_cjH,mean_cjH,sigma_ijH,sigma2_ijH,sigma3_ijH,sigma4_ijH,mean2_ijH,mean3_ijH,mean4_ijH,fsig_ijH,fsig2_ijH,fsig3_ijH,N_ijH,mean_ijH,sigma_mumuH,sigma2_240GeV_mumuH,mean2_240GeV_mumuH,fsig_mumuH,fsig2_mumuH,N_mumuH,sigma_eeH,sigma2_240GeV_eeH,mean2_240GeV_eeH,fsig_eeH,fsig2_eeH,N_eeH,mHmess_240GeV,NL_eeH,NR_eeH,alphaL_eeH,alphaR_eeH,NL_mumuH,NR_mumuH,alphaL_mumuH,alphaR_mumuH");
    
    combWS->defineSet("np", "sigma_mumuH,sigma2_240GeV_mumuH,mean2_240GeV_mumuH,fsig_mumuH,fsig2_mumuH,sigma_eeH,sigma2_240GeV_eeH,mean2_240GeV_eeH,fsig_eeH,fsig2_eeH,mHmess_240GeV");
    combWS->defineSet("glob", "COMmess_240GeV_mumuH,COMmess_240GeV_eeH,BRmess_240GeV_mumuH,BRmess_240GeV_eeH,Emess_240GeV_mumuH,Emess_240GeV_eeH,Lmess_240GeV_mumuH,Lmess_240GeV_eeH");
    combWS->defineSet("constr", "COMsmear_240GeV_mumuH,COMsmear_240GeV_eeH,BRsmear_240GeV_mumuH,BRsmear_240GeV_eeH,Esmear_240GeV_mumuH,Esmear_240GeV_eeH,Lsmear_240GeV_mumuH,Lsmear_240GeV_eeH");
    


    combWS->defineSet("glob_eeH", "COMmess_240GeV_eeH,BRmess_240GeV_eeH,Emess_240GeV_eeH,Lmess_240GeV_eeH");
    combWS->defineSet("glob_mumuH", "COMmess_240GeV_mumuH,BRmess_240GeV_mumuH,Emess_240GeV_mumuH,Lmess_240GeV_mumuH");

    combWS->defineSet("constr_eeH", "COMsmear_240GeV_eeH,BRsmear_240GeV_eeH,Esmear_240GeV_eeH,Lsmear_240GeV_eeH,mHsmear_240GeV_eeH");
    combWS->defineSet("constr_mumuH", "COMsmear_240GeV_mumuH,BRsmear_240GeV_mumuH,Esmear_240GeV_mumuH,Lsmear_240GeV_mumuH,mHsmear_240GeV_mumuH");

    combWS->defineSet("obs", "MRec");
    //combWS->defineSet("obs", "MRec_bbH,MRec_bcH,MRec_bjH,MRec_ccH,MRec_cjH,MRec_ijH,MRec_mumuH,MRec_eeH");

    RooArgSet globSet = *(combWS->set("glob"));
    RooArgSet nuisSet = *(combWS->set("np"));
    RooArgSet poiSet = *(combWS->set("poi"));
    RooArgSet smearSet = *(combWS->set("constr"));
    
    RooArgSet globSet_eeH = *(combWS->set("glob_eeH"));
    RooArgSet globSet_mumuH = *(combWS->set("glob_mumuH"));
    RooArgSet smearSet_eeH = *(combWS->set("constr_eeH"));
    RooArgSet smearSet_mumuH = *(combWS->set("constr_mumuH"));

    /*
    (*combWS->var("sigma3_ijH")).setRange(0, 0.01, 20.);
    (*combWS->var("sigma_bjH")).setRange(0, 0.01, 20.);
    (*combWS->var("mean2_240GeV_mumuH")).setRange(0, 50, 150.);
    (*combWS->var("sigma2_240GeV_eeH")).setRange(0, 0.01, 20.);
    (*combWS->var("sigma2_240GeV_mumuH")).setRange(0, 0.01, 20.);
    (*combWS->var("sigma2_bbH")).setRange(0, 0.01, 20.);
    (*combWS->var("sigma2_bcH")).setRange(0, 0.01, 20.);
    (*combWS->var("sigma2_cjH")).setRange(0, 0.01, 20.);
    (*combWS->var("sigma2_bjH")).setRange(0, 0.01, 20.);
    (*combWS->var("fsig2_eeH")).setRange(0, 0., 1.);
    (*combWS->var("fsig_eeH")).setRange(0, 0., 1.);
    (*combWS->var("fsig2_mumuH")).setRange(0, 0., 1.);
    (*combWS->var("fsig_mumuH")).setRange(0, 0., 1.);
    (*combWS->var("mean_bbH")).setRange(0, 50, 150.);
    (*combWS->var("mean_bcH")).setRange(0, 50, 150.);
    (*combWS->var("sigma_eeH")).setRange(0, 0.01, 20.);
    (*combWS->var("sigma_mumuH")).setRange(0, 0.01, 20.);
    */
   (*combWS->var("sigma2_240GeV_eeH")).setRange(0, 0.01, 10.);
   (*combWS->var("sigma2_240GeV_mumuH")).setRange(0, 0.01, 10.);
   (*combWS->var("mean2_240GeV_mumuH")).setMax(129.);
   (*combWS->var("mean2_240GeV_eeH")).setMax(129.);

    

    //combWS->Print();

    //combModel->Print("t");
    //acombData->Print("t");

    RooCmdArg cmdList;
    cmdList.addArg(Range("range"));
    cmdList.addArg(SplitRange());
    cmdList.addArg(Extended(kTRUE));
    cmdList.addArg(Offset(kTRUE));
    cmdList.addArg(NumCPU(8, 0));
    cmdList.addArg(GlobalObservables(globSet));
    //cmdList.addArg(SumCoefRange("range"));
    cmdList.addArg(ExternalConstraints(smearSet));
    cmdList.addArg(Save(kTRUE));
    cmdList.addArg(Minimizer("Minuit2", "migrad"));
    cmdList.addArg(Strategy(2));

    RooLinkedList linkedCmdList = cmdList.subArgs();


    


    //RooFitResult * r =  combModel -> fitTo(*combData,Save(), Extended(kTRUE), Offset(kTRUE), Constrain(RooArgSet(Lsmear_240GeV, Esmear_240GeV, BRsmear_240GeV)));  //SumW2Error(kTRUE)
    
    //RooFitResult * r =  combModel -> fitTo(*combData,Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(*Lsmear_240GeV, *Esmear_240GeV)), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit2","migrad"));  //SumW2Error(kTRUE)
    
    RooFitResult * r =  combModel -> fitTo(*acombData, linkedCmdList);  //SumW2Error(kTRUE),  Extended(kTRUE), Offset(kTRUE), ExternalConstraints(RooArgSet(*Lsmear_240GeV, *Esmear_240GeV, *BRsmear_240GeV)), GlobalObservables(globSet), Minimizer("Minuit2","migrad")
    r->Print("s");


    //RooFitResult * rB =  combModel_bare -> fitTo(*acombData, Save(), Range("range"), SplitRange(), Extended(kTRUE), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit", "migradimproved"), Strategy(2));

    //rB->Print("s");

    //combData2->Print();
    //combData4->Print();

    //combData->get(66)->Print("V");
    //combData->printArgs(cout);
    //combData4->get(29)->Print("V");
    //combData2->get(99)->Print("V");
    //cout << combData4->sum(kFALSE) << endl;
    //cout << combData2->weight() << endl;

    RooRealVar muZH_240GeV = *(combWS -> var("muZH_240GeV"));

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
  mc.SetConstraintParameters(globSet);

  combWS->var("muZH_240GeV")->setVal(1);
  mc.SetSnapshot(*(combWS->var("muZH_240GeV")));

  cout << combWS->var("muZH_240GeV")->getVal() << endl;

  mc.Print();

  combWS->import(mc);

  RooArgSet *params2 = combModel->getParameters(*mrec);
  params2->Print("V");

  //r->Print("s");
  
  RooArgSet combSet = RooArgSet(poiSet, nuisSet, "combSet");


  const RooArgSet * genPoiValues = 0;
  RooArgSet genObs;

  RooAbsData * asimov = RooStats::AsymptoticCalculator::MakeAsimovData(*acombData, mc, poiSet, globSet, genPoiValues);  //ACHTUNG: Asimov vom Asimov!!!
  //RooAbsData * asimov = RooStats::AsymptoticCalculator::MakeAsimovData(mc, combSet, globSet);



  //RooAbsData * asimov = RooStats::AsymptoticCalculator::MakeAsimovData(mc, combSet, genObs);

  //RooFitResult * r2 = combModel->fitTo(*asimov,Save(), Extended(kTRUE), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit","migradimproved"), GlobalObservables(globSet), ExternalConstraints(smearSet), Strategy(1));

  RooCmdArg cmdList2;
    cmdList2.addArg(Range("range"));
    cmdList2.addArg(SplitRange(kTRUE));
    cmdList2.addArg(Extended(kTRUE));
    cmdList2.addArg(Offset(kTRUE));
    cmdList2.addArg(NumCPU(8, 0));
    cmdList2.addArg(GlobalObservables(globSet));
    //cmdList2.addArg(SumCoefRange("range"));
    cmdList2.addArg(ExternalConstraints(smearSet));
    cmdList2.addArg(Save(kTRUE));
    cmdList2.addArg(Minimizer("Minuit2", "migrad"));
    cmdList2.addArg(Strategy(2));
    //cmdList2.addArg(Minos(muZH_240GeV));

    RooLinkedList linkedCmdList2 = cmdList2.subArgs();

  RooFitResult * r98 = combModel->fitTo(*asimov, linkedCmdList2);

  RooAbsPdf* combModel_eeH = combWS->pdf("model_eeH_combModel");
  RooAbsPdf* combModel_mumuH = combWS->pdf("model_mumuH_combModel");



  

  //RooFitResult * r3 = combModel->fitTo(*asimov, cmdList);
  //RooFitResult * rB2 =  combModel_bare -> fitTo(*asimov, Save(), Range("range"), SplitRange(), Extended(kTRUE), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit2", "migrad"), Strategy(2));

  std::cout << "Asimov designed for mu = 1 gave mu-hat = " << combWS->var("muZH_240GeV")->getVal() << std::endl;
  
  r98->Print();


  
  combWS->import(*asimov, Rename("combined_Asimov"));

  RooArgSet *asimov_parameters = (RooArgSet*)combModel->getParameters(*mrec);
  combWS->saveSnapshot("asimovFit", *asimov_parameters, kTRUE);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////// N O   S Y S T E M A T I C S ///////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  (combWS->var("Lmess_240GeV_mumuH"))->setConstant(kTRUE);
  (combWS->var("Lmess_240GeV_eeH"))->setConstant(kTRUE);
  (combWS->var("COMmess_240GeV_mumuH"))->setConstant(kTRUE);
  (combWS->var("COMmess_240GeV_eeH"))->setConstant(kTRUE);
  (combWS->var("BRmess_240GeV_mumuH"))->setConstant(kTRUE);
  (combWS->var("BRmess_240GeV_eeH"))->setConstant(kTRUE);
  (combWS->var("Emess_240GeV_mumuH"))->setConstant(kTRUE);
  (combWS->var("Emess_240GeV_eeH"))->setConstant(kTRUE);
  //(combWS->var("N_eeH"))->setConstant(kFALSE);
  //(combWS->var("N_mumuH"))->setConstant(kFALSE);


  (combWS->var("BRmess_240GeV_mumuH"))->setVal(1);
  (combWS->var("BRmess_240GeV_eeH"))->setVal(1);
  (combWS->var("Emess_240GeV_mumuH"))->setVal(1);
  (combWS->var("Emess_240GeV_eeH"))->setVal(1);
  (combWS->var("Lmess_240GeV_mumuH"))->setVal(1);
  (combWS->var("Lmess_240GeV_eeH"))->setVal(1);
  (combWS->var("COMmess_240GeV_mumuH"))->setVal(1);
  (combWS->var("COMmess_240GeV_eeH"))->setVal(1);

  RooCmdArg cmdList3;
    cmdList3.addArg(Range("range"));
    cmdList3.addArg(SplitRange(kTRUE));
    cmdList3.addArg(Extended(kTRUE));
    cmdList3.addArg(Offset(kTRUE));
    cmdList3.addArg(NumCPU(8, 0));
    //cmdList3.addArg(GlobalObservables(globSet));
    //cmdList3.addArg(SumCoefRange("range"));
    //cmdList3.addArg(ExternalConstraints(smearSet));
    cmdList3.addArg(Save(kTRUE));
    cmdList3.addArg(Minimizer("Minuit2", "migrad"));
    cmdList3.addArg(Strategy(2));
    //cmdList3.addArg(Minos(muZH_240GeV));

    RooLinkedList linkedCmdList3 = cmdList3.subArgs();

  RooFitResult* r5 = combModel_bare->fitTo(*acombDataBare, linkedCmdList3);
   
  r5->Print();

  combWS->import(*combModel_bare);

  RooStats::ModelConfig mcB("mcB", combWS);
  mcB.SetPdf("combModel_bare");
  mcB.SetObservables(*(combWS->set("obs")));
  mcB.SetParametersOfInterest(poiSet);
  mcB.SetNuisanceParameters(nuisSet);


  combWS->var("muZH_240GeV")->setVal(1);
  mcB.SetSnapshot(*(combWS->var("muZH_240GeV")));

  combWS->import(mcB);
  //RooArgSet genObs;

  RooAbsData * combAsimov_bare = RooStats::AsymptoticCalculator::MakeAsimovData(*acombDataBare, mcB, poiSet, genObs, genPoiValues);

  RooFitResult * r6 = combWS->pdf("combModel_bare")->fitTo(*combAsimov_bare, linkedCmdList3);

  std::cout << "Asimov designed for mu = 1 gave mu-hat = " << combWS->var("muZH_240GeV")->getVal() << std::endl;

  r6->Print();

  combWS->import(*combAsimov_bare, Rename("llH_Asimov_bare"));

  //RooArgSet *asimov_parameters_bare = (RooArgSet*)combWS->pdf("combModel_bare")->getParameters(mrec);
  //combWS->saveSnapshot("llH_asimovFit_bare", *asimov_parameters_bare, kTRUE);



  (combWS->var("Lmess_240GeV_mumuH"))->setConstant(kFALSE);
  (combWS->var("Lmess_240GeV_eeH"))->setConstant(kFALSE);
  (combWS->var("COMmess_240GeV_mumuH"))->setConstant(kFALSE);
  (combWS->var("COMmess_240GeV_eeH"))->setConstant(kFALSE);
  (combWS->var("BRmess_240GeV_mumuH"))->setConstant(kFALSE);
  (combWS->var("BRmess_240GeV_eeH"))->setConstant(kFALSE);
  (combWS->var("Emess_240GeV_mumuH"))->setConstant(kFALSE);
  (combWS->var("Emess_240GeV_eeH"))->setConstant(kFALSE);

  combWS->writeToFile("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/WScombinedModelZll_muZH.root");



   // C o n s t r u c t   p l a i n   l i k e l i h o o d
   // ---------------------------------------------------
 TCanvas* c4 = new TCanvas ("c4", "c4", 100, 200, 700, 500);
 TCanvas* c5 = new TCanvas ("c5", "c5", 100, 200, 700, 500);

  // Construct unbinned likelihood
  //RooAbsReal * nll = combModel_bare->createNLL(*combAsimov_bare, Save(), Extended(kTRUE), Offset(kTRUE), NumCPU(8, 0), PrintEvalErrors(-1)); //Best Result
  
  //RooAbsReal * nll_eeH = model_eeH->createNLL(*adata_eeH, Extended(kTRUE), ExternalConstraints(smearSet_eeH), Offset(kTRUE), NumCPU(8, 0), PrintEvalErrors(-1), GlobalObservables(globSet_eeH));
  //RooAbsReal * nll_mumuH = model_mumuH->createNLL(*adata_mumuH, Extended(kTRUE), ExternalConstraints(smearSet_mumuH), Offset(kTRUE), NumCPU(8, 0), PrintEvalErrors(-1), GlobalObservables(globSet_mumuH));

  RooAbsReal * nll_eeH = model_eeH->createNLL(*adata_eeH, Extended(kTRUE), ExternalConstraints(smearSet_eeH), Offset(kTRUE), NumCPU(8, 0), PrintEvalErrors(-1), GlobalObservables(globSet_eeH));
  RooAbsReal * nll_mumuH = model_mumuH->createNLL(*adata_mumuH, Extended(kTRUE), ExternalConstraints(smearSet_mumuH), Offset(kTRUE), NumCPU(8, 0), PrintEvalErrors(-1), GlobalObservables(globSet_mumuH));
  //RooAddition * nll = new RooAddition("nll_add", "nll_add", RooArgList(*nll_eeH, *nll_mumuH));
  
  RooAbsReal * nll = combModel->createNLL(*asimov, Range("range"), SplitRange(kTRUE), Extended(kTRUE), ExternalConstraints(smearSet), Offset(kTRUE), NumCPU(8, 0), PrintEvalErrors(-1), GlobalObservables(globSet)); //Best Result


  //RooAbsReal * nll_bbH = model_bbH_pdf->createNLL(*asimov, Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(*Lsmear_240GeV, *Esmear_240GeV, *BRsmear_240GeV)), Offset(kTRUE), NumCPU(8, 0), PrintEvalErrors(-1));
  RooMinimizer minim(*nll);
  minim.setMinimizerType("Minuit2");
  minim.optimizeConst(kTRUE);
  minim.setOffsetting(kTRUE);
  minim.setStrategy(2);
  minim.migrad();
  minim.hesse();

  RooAbsReal *pll_muZH = nll->createProfile(muZH_240GeV);

  RooMinimizer minim_eeH(*nll_eeH);
  minim_eeH.setMinimizerType("Minuit2");
  minim_eeH.optimizeConst(kTRUE);
  minim_eeH.setOffsetting(kTRUE);
  minim_eeH.setStrategy(2);
  minim_eeH.migrad();
  minim_eeH.hesse();

  RooAbsReal *pll_muZH_eeH = nll_eeH->createProfile(muZH_240GeV);

  RooMinimizer minim_mumuH(*nll_mumuH);
  minim_mumuH.setMinimizerType("Minuit2");
  minim_mumuH.optimizeConst(kTRUE);
  minim_mumuH.setOffsetting(kTRUE);
  minim_mumuH.setStrategy(2);
  minim_mumuH.migrad();
  minim_mumuH.hesse();
  
  RooAbsReal *pll_muZH_mumuH = nll_mumuH->createProfile(muZH_240GeV);


  (combWS->var("BRmess_240GeV_mumuH"))->setVal(1);
  (combWS->var("BRmess_240GeV_eeH"))->setVal(1);
  (combWS->var("Emess_240GeV_mumuH"))->setVal(1);
  (combWS->var("Emess_240GeV_eeH"))->setVal(1);
  (combWS->var("Lmess_240GeV_mumuH"))->setVal(1);
  (combWS->var("Lmess_240GeV_eeH"))->setVal(1);
  (combWS->var("COMmess_240GeV_mumuH"))->setVal(1);
  (combWS->var("COMmess_240GeV_eeH"))->setVal(1);

  (combWS->var("Lmess_240GeV_mumuH"))->setConstant(kTRUE);
  (combWS->var("Lmess_240GeV_eeH"))->setConstant(kTRUE);
  (combWS->var("COMmess_240GeV_mumuH"))->setConstant(kTRUE);
  (combWS->var("COMmess_240GeV_eeH"))->setConstant(kTRUE);
  (combWS->var("BRmess_240GeV_mumuH"))->setConstant(kTRUE);
  (combWS->var("BRmess_240GeV_eeH"))->setConstant(kTRUE);
  (combWS->var("Emess_240GeV_mumuH"))->setConstant(kTRUE);
  (combWS->var("Emess_240GeV_eeH"))->setConstant(kTRUE);

  

  //RooAbsReal * nll_bare = combModel->createNLL(*combAsimov_bare, Save(), Extended(kTRUE), Offset(kTRUE), NumCPU(8, 0), PrintEvalErrors(-1), GlobalObservables(globSet), ExternalConstraints(smearSet)); //Best Result
  //RooAbsReal * nll_bare = combModel->createNLL(*asimov, Save(), Extended(kTRUE), Offset(kTRUE), NumCPU(8, 0), PrintEvalErrors(-1), GlobalObservables(globSet));
  RooNLLVar nll_bare("nll_bare", "nll_bare", *combModel_bare, *combAsimov_bare, Extended(kTRUE), Offset(kTRUE), NumCPU(8, 0), Range("range"), SplitRange(kTRUE));
  //RooAbsReal * nll_bbH = model_bbH_pdf->createNLL(*asimov, Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(*Lsmear_240GeV, *Esmear_240GeV, *BRsmear_240GeV)), Offset(kTRUE), NumCPU(8, 0), PrintEvalErrors(-1));
  RooMinimizer minim2(nll_bare);
  minim2.setMinimizerType("Minuit2");
  minim2.optimizeConst(kTRUE);
  minim2.setOffsetting(kTRUE);
  minim2.setStrategy(2);
  minim2.migrad();
  minim2.hesse();

  RooAbsReal *pll_muZH_bare = nll_bare.createProfile(muZH_240GeV);

  pll_muZH_bare->Print();
  pll_muZH->Print();

  (combWS->var("Lmess_240GeV_mumuH"))->setConstant(kFALSE);
  (combWS->var("Lmess_240GeV_eeH"))->setConstant(kFALSE);
  (combWS->var("COMmess_240GeV_mumuH"))->setConstant(kFALSE);
  (combWS->var("COMmess_240GeV_eeH"))->setConstant(kFALSE);
  (combWS->var("BRmess_240GeV_mumuH"))->setConstant(kFALSE);
  (combWS->var("BRmess_240GeV_eeH"))->setConstant(kFALSE);
  (combWS->var("Emess_240GeV_mumuH"))->setConstant(kFALSE);
  (combWS->var("Emess_240GeV_eeH"))->setConstant(kFALSE);

  //pll_muZH_bare->Print();
  //pll_muZH->Print();

  nll->Print("t");
  nll_bare.Print("t");

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
  // C o n s t r u c t   p r o f i l e   l i k e l i h o o d   i n   m u Z H
 // -----------------------------------------------------------------------

 // The profile likelihood estimator on nll for Nsig will minimize nll w.r.t
 // all floating parameters except Nsig for each evaluation

 c5 -> cd();

  RooPlot *frame98 = muZH_240GeV.frame(Range(0.7, 1.3), Title("NLL in #mu ZH "), Bins(300));
  frame98 -> GetXaxis() ->SetRangeUser(0.9, 1.1);

  //pll_muZH_bare->Print();
  //pll_muZH->Print();
  
  //RooAbsReal *pll_bbH_muZH = nll_bbH->createProfile(muZH_240GeV_bbH);
  pll_muZH_mumuH-> plotOn(frame98, LineColor(kBlue),LineStyle(kSolid), Name("mumuH"));
  pll_muZH-> plotOn(frame98, LineColor(kRed),LineStyle(kSolid), Name("combined"));
  //pll_muZH_eeH-> plotOn(frame98, LineColor(kGreen),LineStyle(kSolid), Name("eeH"));
  //pll_muZH-> plotOn(frame98, Slice(*channel, "mumuH"), ProjWData(*channel, *asimov), NumCPU(8), LineColor(kRed),LineStyle(kSolid));
  (combWS->var("Lmess_240GeV_mumuH"))->setConstant(kTRUE);
  (combWS->var("Lmess_240GeV_eeH"))->setConstant(kTRUE);
  (combWS->var("COMmess_240GeV_mumuH"))->setConstant(kTRUE);
  (combWS->var("COMmess_240GeV_eeH"))->setConstant(kTRUE);
  (combWS->var("BRmess_240GeV_mumuH"))->setConstant(kTRUE);
  (combWS->var("BRmess_240GeV_eeH"))->setConstant(kTRUE);
  (combWS->var("Emess_240GeV_mumuH"))->setConstant(kTRUE);
  (combWS->var("Emess_240GeV_eeH"))->setConstant(kTRUE);
  
  //pll_muZH-> plotOn(frame98, Components("nll_combModel_asimovDataFullModel"), LineColor(kBlack),LineStyle(kSolid));
  pll_muZH_bare-> plotOn(frame98, LineColor(kBlack),LineStyle(kDashed));

  //pll_bbH_muZH -> plotOn(frame98, LineColor(kBlack),LineStyle(kDashed));

  frame98->GetYaxis()->SetTitleOffset(1.4);
  frame98->SetMinimum(0.);
  frame98->SetMaximum(4.);
  frame98->Draw(); 
  c5->Draw(); 
  c5->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/qqH/combined_plots/NLL_prf_muZH.pdf");


}