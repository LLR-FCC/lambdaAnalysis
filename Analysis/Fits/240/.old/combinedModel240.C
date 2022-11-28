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

void combinedModel240() {
    // Import workspace

    TFile qqH("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/qqH/WScombinedModel_muZH.root");
    TFile mumuH("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/ZmumuH240_muZH.root");
    TFile eeH("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/eeH/ZeeH240_muZH.root");
    gROOT->cd();
    


    RooWorkspace *qqH_WS = (RooWorkspace*)qqH.Get("combWS_ZqqH_240");
    RooWorkspace *mumuH_WS = (RooWorkspace*)mumuH.Get("w");
    RooWorkspace *eeH_WS = (RooWorkspace*)eeH.Get("w");

    //Get original models
    RooAbsPdf * model_qqH = qqH_WS->pdf("combModel");
    RooAbsPdf * model_mumuH = mumuH_WS->pdf("model");
    RooAbsPdf * model_eeH = eeH_WS->pdf("model");

    //model_qqH->Print("s");
    //(model_qqH->getPdf("bbH"))->Print();

    //cout << "models = " << model_bbH << " " << model_mumuH << endl;

    //Import data

    RooDataSet* adata_qqH = (RooDataSet*)qqH_WS->data("combined_Asimov");
    RooDataSet* adata_mumuH = (RooDataSet*)mumuH_WS->data("mumuH_Asimov");
    RooDataSet* adata_eeH = (RooDataSet*)eeH_WS->data("eeH_Asimov");
    RooDataSet* adata_bbH = (RooDataSet*)qqH_WS->data("acombData_bbH");
    RooDataSet* adata_bcH = (RooDataSet*)qqH_WS->data("acombData_bcH");
    RooDataSet* adata_bjH = (RooDataSet*)qqH_WS->data("acombData_bjH");
    RooDataSet* adata_ccH = (RooDataSet*)qqH_WS->data("acombData_ccH");
    RooDataSet* adata_cjH = (RooDataSet*)qqH_WS->data("acombData_cjH");
    RooDataSet* adata_ijH = (RooDataSet*)qqH_WS->data("acombData_ijH");


    qqH_WS->loadSnapshot("asimovFit");
    mumuH_WS->loadSnapshot("mumuH_asimovFit");
    eeH_WS->loadSnapshot("eeH_asimovFit");
    
    //wdata_bbH->Print();
    //wdata_mumuH->Print();
    //wdata_eeH->Print();
    //adata_bbH->Print();
    //adata_mumuH->Print();
    //adata_eeH->Print();


    //cout << wdata_bbH_240->get() << endl;
    

    //dh_bbH_240->Print();
    //dh_mumuH_240->Print();

    RooWorkspace* combWS = new RooWorkspace("combWS_240");
    //combWS->import(*model_qqH, RenameAllNodes("qqH"), RenameAllVariables("qqH"));
    combWS->import(*model_qqH, RenameAllNodes("qqH"), RenameAllVariables("qqH"));
    combWS->import(*model_mumuH, RenameAllNodes("mumuH"), RenameAllVariables("mumuH"));
    combWS->import(*model_eeH, RenameAllNodes("eeH"), RenameAllVariables("eeH"));
    
    combWS->import(qqH_WS->allCats());

    //RooSuperCategory SuperqqH("qqH", "qqH", qqH_WS->allCats());

    RooCategory* channel = combWS->cat("channel");
    //channel -> defineType("mumuH", 6);
    //channel -> defineType("eeH", 7);
    //channel -> defineType("qqH", 8);
    //channel->Print("s");

    //combWS->Print();

    RooCategory* topChannel = new RooCategory("topChannel","topChannel");
    topChannel -> defineType("qqH",0);
    topChannel -> defineType("mumuH",1);
    topChannel -> defineType("eeH",2);
    combWS ->import(*topChannel);

    //combWS -> allCats ();
    cout << "hi3" << endl;
    //RooArgSet vars_bbH = *((RooArgSet*)wdata_bbH->get()->clone("vars"));
    RooArgSet avars_qqH = *((RooArgSet*)adata_qqH->get()->clone("avars"));
    //vars_bbH.Print();
    avars_qqH.Print();
    //combWS ->import("weight_T1");

    //RooArgSet vars_mumuH = *((RooArgSet*)wdata_bbH->get()->clone("vars"));
    RooArgSet avars_mumuH = *((RooArgSet*)adata_mumuH->get()->clone("avars"));

    //RooArgSet vars_eeH = *((RooArgSet*)wdata_eeH->get()->clone("vars"));
    RooArgSet avars_eeH = *((RooArgSet*)adata_eeH->get()->clone("avars"));

    RooRealVar *wavars_qqH = ((RooRealVar*)adata_qqH->weightVar()->clone("wavars_qqH"));
    RooRealVar *wavars_mumuH = ((RooRealVar*)adata_mumuH->weightVar()->clone("wavars_mumuH"));
    RooRealVar *wavars_eeH = ((RooRealVar*)adata_eeH->weightVar()->clone("wavars_eeH"));

    avars_mumuH.Print();

    qqH_WS->Print();
    mumuH_WS->Print();
    qqH_WS->Print();

  

  // A S I M O V  D A T A S E T
  // --------------------------

  RooDataSet* acombData = new RooDataSet("acombData", "combined Asimov dataset", RooArgSet(avars_qqH, wavars_qqH), Index(*topChannel), Import("qqH", *adata_qqH), WeightVar("wavars_qqH"));
  RooDataSet* acombData_qqH = new RooDataSet("acombData_qqH", "combined Asimov dataset", RooArgSet(avars_qqH, wavars_qqH),Import(*adata_qqH), WeightVar("wavars_qqH"));
  RooDataSet* acombData_mumuH = new RooDataSet("acombData_mumuH", "combined Asimov dataset", RooArgSet(avars_mumuH, wavars_mumuH) ,Index(*topChannel),Import("mumuH",*adata_mumuH), WeightVar("wavars_mumuH"));
  RooDataSet* acombData_eeH = new RooDataSet("acombData_eeH", "combined Asimov dataset", RooArgSet(avars_eeH, wavars_eeH) ,Index(*topChannel),Import("eeH",*adata_eeH), WeightVar("wavars_eeH"));
  

  acombData->Print();

  acombData->append(*acombData_mumuH);
  acombData->append(*acombData_eeH);

  acombData->Print();
  acombData_mumuH->Print();

  combWS->import(*acombData);
  combWS->import(*acombData_qqH);
  combWS->import(*acombData_mumuH);
  combWS->import(*acombData_eeH);


 //RooDataSet* wcombData = new RooDataSet("combData","combined dataset",vars_qqH,Index(*topChannel),Import("qqH",*wdata_qqH_240));
 //RooDataSet* wcombData2 = new RooDataSet("combData2","combined dataset",vars_mumuH,Index(*topChannel),Import("mumuH",*wdata_mumuH_240));
 //wcombData->append(*wcombData2);

//wcombData->Print();
  

    

    // Create joint pdf 
  
    combWS->factory("SIMUL::finaljoint(topChannel,qqH=combModel_qqH,mumuH=model_mumuH,eeH=model_eeH)") ;
    combWS -> import(*mumuH_WS -> var("mHmess_240GeV"));
    //combWS -> import(*qqH_WS -> var("varKappa_240GeV"));
    combWS -> import(*qqH_WS -> var("muZH_240GeV"));
    combWS -> import(*qqH_WS -> var("MRec"));
    RooRealVar * mrec = combWS -> var("MRec");
    //RooRealVar * mrec2 = combWS -> var("MRec");

    RooAbsPdf * Lsmear_240GeV = mumuH_WS->pdf("Lsmear_240GeV");
    RooAbsPdf * Esmear_240GeV = mumuH_WS->pdf("Esmear_240GeV");
    RooAbsPdf * BRsmear_240GeV = mumuH_WS->pdf("BRsmear_240GeV");
    RooAbsPdf * COMsmear_240GeV = mumuH_WS->pdf("COMsmear_240GeV");
    RooAbsPdf * mHsmear_240GeV = mumuH_WS->pdf("mHsmear_240GeV");

    //combWS->Print();

    

    //combWS -> factory("EDIT::combModel(joint, MRec_qqH = MRec, MRec_mumuH = MRec, mHmess_240GeV_qqH = mHmess_240GeV, mHmess_240GeV_mumuH = mHmess_240GeV, varKappa_240GeV_qqH = varKappa_240GeV, varKappa_240GeV_mumuH = varKappa_240GeV)");
    combWS -> factory("EDIT::finalModel(finaljoint, MRec_qqH = MRec, MRec_mumuH = MRec, MRec_eeH = MRec, muZH_240GeV_qqH = muZH_240GeV, muZH_240GeV_mumuH = muZH_240GeV, muZH_240GeV_eeH = muZH_240GeV, mHmess_240GeV_mumuH = mHmess_240GeV, mHmess_240GeV_eeH = mHmess_240GeV)");
    

    RooAbsPdf* finalModel_split = combWS->pdf("finaljoint");

    cout << "model joint split ...." << endl;
    //combModel_split->Print("t");

    RooAbsPdf* finalModel = combWS->pdf("finalModel");

    cout << "model combined ...." << endl;
    finalModel->Print("t");


    RooArgSet *params = finalModel->getParameters(*mrec);
    RooArgSet *initParams = (RooArgSet *)params->snapshot();
    initParams->Print("s");

    

    combWS->defineSet("poi", "muZH_240GeV");
    //w->defineSet("poi", "varKappa_240GeV");
    //combWS->defineSet("np", RooArgSet(sigma_240GeV, alphaL_240GeV, alphaR_240GeV, NL_240GeV, NR_240GeV, mean2_240GeV, sigma2_240GeV, fsig, fsig2, N, mHmess_240GeV), kTRUE);
    combWS->defineSet("np", "sigma_bbH_qqH,sigma2_bbH_qqH,sigma3_bbH_qqH,sigma4_bbH_qqH,mean2_bbH_qqH,mean3_bbH_qqH,mean4_bbH_qqH,fsig_bbH_qqH,fsig2_bbH_qqH,fsig3_bbH_qqH,N_bbH_qqH,mean_bbH_qqH,sigma_bcH_qqH,sigma2_bcH_qqH,sigma3_bcH_qqH,sigma4_bcH_qqH,mean2_bcH_qqH,mean3_bcH_qqH,mean4_bcH_qqH,fsig_bcH_qqH,fsig2_bcH_qqH,fsig3_bcH_qqH,N_bcH_qqH,mean_bcH_qqH,sigma_bjH_qqH,sigma2_bjH_qqH,sigma3_bjH_qqH,sigma4_bjH_qqH,mean2_bjH_qqH,mean3_bjH_qqH,mean4_bjH_qqH,fsig_bjH_qqH,fsig2_bjH_qqH,fsig3_bjH_qqH,N_bjH_qqH,mean_bjH_qqH,sigma_ccH_qqH,sigma2_ccH_qqH,mean2_ccH_qqH,fsig_ccH_qqH,N_ccH_qqH,mean_ccH_qqH,sigma_cjH_qqH,sigma2_cjH_qqH,sigma3_cjH_qqH,sigma4_cjH_qqH,mean2_cjH_qqH,mean3_cjH_qqH,mean4_cjH_qqH,fsig_cjH_qqH,fsig2_cjH_qqH,fsig3_cjH_qqH,N_cjH_qqH,mean_cjH_qqH,sigma_ijH_qqH,sigma2_ijH_qqH,sigma3_ijH_qqH,sigma4_ijH_qqH,mean2_ijH_qqH,mean3_ijH_qqH,mean4_ijH_qqH,fsig_ijH_qqH,fsig2_ijH_qqH,fsig3_ijH_qqH,N_ijH_qqH,mean_ijH_qqH,sigma_mumuH,sigma2_240GeV_mumuH,mean2_240GeV_mumuH,fsig_mumuH,fsig2_mumuH,N_mumuH,sigma_eeH,sigma2_240GeV_eeH,mean2_240GeV_eeH,fsig_eeH,fsig2_eeH,N_eeH");
    combWS->defineSet("glob", "BRmess_240GeV_mumuH,BRmess_240GeV_eeH,Emess_240GeV_mumuH,Emess_240GeV_eeH,Lmess_240GeV_mumuH,Lmess_240GeV_eeH,BRmess_240GeV_bcH_qqH,BRmess_240GeV_bbH_qqH,BRmess_240GeV_bjH_qqH,BRmess_240GeV_ccH_qqH,BRmess_240GeV_cjH_qqH,BRmess_240GeV_ijH_qqH,Emess_240GeV_bcH_qqH,Emess_240GeV_bjH_qqH,Emess_240GeV_bbH_qqH,Emess_240GeV_ccH_qqH,Emess_240GeV_cjH_qqH,Emess_240GeV_ijH_qqH,Lmess_240GeV_bcH_qqH,Lmess_240GeV_bjH_qqH,Lmess_240GeV_bbH_qqH,Lmess_240GeV_ccH_qqH,Lmess_240GeV_cjH_qqH,Lmess_240GeV_ijH_qqH,COMmess_240GeV_mumuH,COMmess_240GeV_eeH,mHmess_240GeV_mumuH,mHmess_240GeV_eeH");
    combWS->defineSet("obs", "MRec");

    RooArgSet globSet = *(combWS->set("glob"));
    RooArgSet nuisSet = *(combWS->set("np"));
    RooArgSet poiSet = *(combWS->set("poi"));

    combWS->Print();

    RooCategory channel_qqH = *(combWS->cat("channel_qqH"));
    channel_qqH.Print("s");
    topChannel->Print("s");

    //RooSuperCategory joint_index = (RooSuperCategory*)(*combWS->catfunc("joint_index"));
    //joint_index.Print("s");

    

    //Combined fit

    //RooFitResult * r =  combModel -> fitTo(*combData,Save(), Extended(kTRUE), Offset(kTRUE), Constrain(RooArgSet(Lsmear_240GeV, Esmear_240GeV, BRsmear_240GeV)));  //SumW2Error(kTRUE)
    
    //RooFitResult * r =  combModel -> fitTo(*combData,Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(*Lsmear_240GeV, *Esmear_240GeV)), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit2","migrad"));  //SumW2Error(kTRUE)
    
    RooFitResult * r =  finalModel -> fitTo(*acombData,Save(), Extended(kTRUE), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit","migrad"), GlobalObservables(globSet), ExternalConstraints(RooArgSet(*Lsmear_240GeV, *Esmear_240GeV, *BRsmear_240GeV, *COMsmear_240GeV, *mHsmear_240GeV)));  //SumW2Error(kTRUE), ExternalConstraints(RooArgSet(*Lsmear_240GeV, *Esmear_240GeV, *BRsmear_240GeV))
    r->Print("s");

    /*

    //combData2->Print();
    //combData4->Print();

    //combData->get(66)->Print("V");
    //combData->printArgs(cout);
    //combData4->get(29)->Print("V");
    //combData2->get(99)->Print("V");
    //cout << combData4->sum(kFALSE) << endl;
    //cout << combData2->weight() << endl;

    /*

    RooRealVar * mrec_qqH = combWS -> var("MRec_qqH");
    //RooRealVar varKappa_240GeV = *(combWS -> var("varKappa_240GeV"));
    RooRealVar muZH_240GeV = *(combWS -> var("muZH_240GeV"));
    RooRealVar muZH_240GeV_qqH = *(combWS -> var("muZH_240GeV_qqH"));
    RooAbsPdf * model_qqH_pdf = combWS->pdf("model_qqH");

    RooArgSet *combFitParameters = (RooArgSet*)combModel->getParameters(*mrec);
    combWS->saveSnapshot("combinedFit", *combFitParameters, kTRUE);

    RooArgSet *qqHFitParameters = (RooArgSet*)model_qqH_pdf->getParameters(*mrec_qqH);
    combWS->saveSnapshot("qqHFit", *qqHFitParameters, kTRUE);
    
    //mrec->setBins(67);
    //mrec2->setBins(70);


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
   RooPlot* frame1 = mrec->frame(Name("qqH"),Title("qqH"), Bins(60)) ;
   (frame1 -> GetXaxis()) ->SetRangeUser(80., 160.); 
   // Plot all data tagged as physics sample
   //combData->plotOn(frame1);
   combData->plotOn(frame1,Cut("topChannel == topChannel::qqH")) ;
   //acombData->plotOn(frame1,Cut("topChannel == topChannel::qqH")) ;
   // Plot "physics" slice of simultaneous pdf. 
   // NBL You _must_ project the sample index category with data using ProjWData 
   // as a RooSimultaneous makes no prediction on the shape in the index category 
   // and can thus not be integrated
   
   combModel->plotOn(frame1,Slice(*topChannel,"qqH"),ProjWData(*topChannel,*combData)) ;
   //combModel->plotOn(frame1,Slice(*topChannel,"qqH"),Components("model_qqH_combModel"),ProjWData(*topChannel,*combData),LineStyle(kDashed)) ;
   
   // The same plot for the control sample slice

   //RooDataHist *testDH = (RooDataHist *)combData->reduce(vars_qqH, "topChannel==topChannel::mumuH");

   
   RooPlot* frame2 = mrec->frame(Name("mumuH"),Title("mumuH"), Bins(60)) ;
   frame2 -> GetXaxis() ->SetRangeUser(20., 160.); 
   //combData->plotOn(frame2,Cut("topChannel==topChannel::mumuH")) ;
   combData->plotOn(frame2,Cut("topChannel == topChannel::mumuH")) ;
   //acombData->plotOn(frame2,Cut("topChannel == topChannel::mumuH")) ;
   
   combModel->plotOn(frame2,Slice(*topChannel,"mumuH"),ProjWData(*topChannel,*combData)) ;
   //combModel->plotOn(frame2,Slice(topChannel,"control"),Components("px_ctl"),ProjWData(topChannel,combData),LineStyle(kDashed)) ;

   RooPlot* frame3 = mrec->frame(Name("eeH"),Title("eeH"), Bins(60)) ;
   frame3 -> GetXaxis() ->SetRangeUser(20., 160.); 
   combData->plotOn(frame3,Cut("topChannel == topChannel::eeH")) ;
   //acombData->plotOn(frame3,Cut("topChannel == topChannel::eeH")) ;
   
   combModel->plotOn(frame3,Slice(*topChannel,"eeH"),ProjWData(*topChannel,*combData)) ;
   //combModel->plotOn(frame3,Slice(topChannel,"control"),Components("px_ctl"),ProjWData(topChannel,combData),LineStyle(kDashed)) ;

   RooPlot* frame4 = mrec->frame(Name("ccH"),Title("ccH"), Bins(60)) ;
   frame4 -> GetXaxis() ->SetRangeUser(110., 160.); 
   combData->plotOn(frame4,Cut("topChannel == topChannel::ccH")) ;
   //acombData->plotOn(frame3,Cut("topChannel == topChannel::ccH")) ;
   
   combModel->plotOn(frame4,Slice(*topChannel,"ccH"),ProjWData(*topChannel,*combData)) ;
   //combModel->plotOn(frame3,Slice(topChannel,"control"),Components("px_ctl"),ProjWData(topChannel,combData),LineStyle(kDashed)) ;

   RooPlot* frame5 = mrec->frame(Name("cjH"),Title("cjH"), Bins(60)) ;
   frame5 -> GetXaxis() ->SetRangeUser(100., 160.); 
   combData->plotOn(frame5,Cut("topChannel == topChannel::cjH")) ;
   //acombData->plotOn(frame3,Cut("topChannel == topChannel::cjH")) ;
   
   combModel->plotOn(frame5,Slice(*topChannel,"cjH"),ProjWData(*topChannel,*combData)) ;
   //combModel->plotOn(frame3,Slice(topChannel,"control"),Components("px_ctl"),ProjWData(topChannel,combData),LineStyle(kDashed)) ;

   RooPlot* frame6 = mrec->frame(Name("ijH"),Title("ijH"), Bins(60)) ;
   frame6 -> GetXaxis() ->SetRangeUser(100., 160.); 
   combData->plotOn(frame6,Cut("topChannel == topChannel::ijH")) ;
   //acombData->plotOn(frame3,Cut("topChannel == topChannel::ijH")) ;
   
   combModel->plotOn(frame6,Slice(*topChannel,"ijH"),ProjWData(*topChannel,*combData)) ;
   //combModel->plotOn(frame3,Slice(topChannel,"control"),Components("px_ctl"),ProjWData(topChannel,combData),LineStyle(kDashed)) ;
   

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

 /*


  // C o n s t r u c t  A s i m o v  d a t a s e t
  // ---------------------------------------------
  
  


  RooStats::ModelConfig mc("mc_240", combWS);
  mc.SetPdf("combModel");
  mc.SetObservables(*(combWS->set("obs")));
  mc.SetParametersOfInterest(poiSet);
  mc.SetNuisanceParameters(nuisSet);
  mc.SetGlobalObservables(globSet);

  combWS->var("muZH_240GeV")->setVal(1);
  mc.SetSnapshot(*(combWS->var("muZH_240GeV")));

  mc.Print();

  combWS->import(mc);

  r->Print("s");
  


  const RooArgSet * genPoiValues = 0;

  RooAbsData * asimov = RooStats::AsymptoticCalculator::MakeAsimovData(*acombData, mc, poiSet, globSet, genPoiValues);  //ACHTUNG: Asimov vom Asimov!!!

  /*

  //RooFitResult * r2 = combModel->fitTo(*asimov,Save(), Extended(kTRUE), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit","migrad"), GlobalObservables(globSet));
  RooFitResult * r3 = combModel->fitTo(*asimov,Save(), Extended(kTRUE), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit2","migrad"), GlobalObservables(globSet));

  std::cout << "Asimov designed for mu = 1 gave mu-hat = " << combWS->var("muZH_240GeV")->getVal() << std::endl;
  
  combWS->import(*asimov, Rename("combined_Asimov"));

  RooArgSet *asimov_parameters = (RooArgSet*)combModel->getParameters(*mrec);
  combWS->saveSnapshot("asimovFit", *asimov_parameters, kTRUE);

  //r2->Print();
  r3->Print();


  combWS->writeToFile("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/WScombinedModel_muZH.root");


  /*
   // C o n s t r u c t   p l a i n   l i k e l i h o o d
   // ---------------------------------------------------
 TCanvas* c4 = new TCanvas ("c4", "c4", 100, 200, 700, 500);
 TCanvas* c5 = new TCanvas ("c5", "c5", 100, 200, 700, 500);

  // Construct unbinned likelihood
  RooAbsReal * nll = combModel->createNLL(*asimov, Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(*Lsmear_240GeV, *Esmear_240GeV, *BRsmear_240GeV)), Offset(kTRUE), NumCPU(8, 0), PrintEvalErrors(-1)); //Best Result
  RooAbsReal * nll_qqH = model_qqH_pdf->createNLL(*asimov, Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(*Lsmear_240GeV, *Esmear_240GeV, *BRsmear_240GeV)), Offset(kTRUE), NumCPU(8, 0), PrintEvalErrors(-1));
  RooMinimizer minim(*nll);
  minim.migrad();

  RooMinimizer minim_qqH(*nll_qqH);
  minim_qqH.migrad();
  
  
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
  RooAbsReal *pll_qqH_kl = nll_qqH->createProfile(varKappa_240GeV);

  pll_kl -> plotOn(frame4, LineColor(kRed),LineStyle(kSolid));
  pll_qqH_kl -> plotOn(frame4, LineColor(kBlack),LineStyle(kDashed));

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
  RooAbsReal *pll_qqH_muZH = nll_qqH->createProfile(muZH_240GeV_qqH);

  pll_muZH-> plotOn(frame98, LineColor(kRed),LineStyle(kSolid));
  pll_qqH_muZH -> plotOn(frame98, LineColor(kBlack),LineStyle(kDashed));

  frame98->GetYaxis()->SetTitleOffset(1.4);
  frame98->SetMinimum(0.);
  frame98->SetMaximum(4.);
  frame98->Draw(); 
  c5->Draw(); 
  c5->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/qqH/combined_plots/NLL_prf_muZH.pdf");

  */
  
  
  



    


}