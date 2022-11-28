#include "RooRealVar.h"
#include "RooProfileLL.h"
#include "RooFormulaVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooChebychev.h"
#include "RooCrystalBall.h"
#include "RooExponential.h"
#include "RooPolynomial.h"
#include "RooAddPdf.h"
#include "RooExtendPdf.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "RooPlot.h"
using namespace RooFit;

void Zee_H() {

    // Import files

   TFile *eeFile = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/presel/histos/wzp6_ee_eeH_ecm365_sel_ZeeH_histo.root");
   TFile *WWFile = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/presel/histos/p8_ee_WW_ecm365_sel_ZeeH_histo.root");
   TFile *ZZFile = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/presel/histos/p8_ee_ZZ_ecm365_sel_ZeeH_histo.root");
   //TFile *ZllFile = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/presel/histos/p8_ee_Zll_ecm365_sel_ZeeH_histo.root");
   TFile *ZeeFile = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/presel/histos/wzp6_ee_ee_Mee_30_150_ecm365_sel_ZeeH_histo.root");
   //TFile *ZmumuFile = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/presel/histos/wzp6_ee_mumu_ecm365_sel_ZeeH_histo.root");
   //TFile *ZtautauFile = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/presel/histos/wzp6_ee_tautau_ecm365_sel_ZeeH_histo.root");

   TH1D *h = (TH1D*)eeFile->Get("leptonic_recoil_m_zoom1");
   TH1D *hWW = (TH1D*)WWFile->Get("leptonic_recoil_m_zoom1");
   TH1D *hZZ = (TH1D*)ZZFile->Get("leptonic_recoil_m_zoom1");
   //TH1D *hZll = (TH1D*)ZllFile->Get("leptonic_recoil_m_zoom1");
   TH1D *hZee = (TH1D*)ZeeFile->Get("leptonic_recoil_m_zoom1");
   //TH1D *hZmumu = (TH1D*)ZmumuFile->Get("leptonic_recoil_m_zoom1");
   //TH1D *hZtautau = (TH1D*)ZtautauFile->Get("leptonic_recoil_m_zoom1");

   TH1D *hh = (TH1D*)h->Clone();
   TH1D *hBkg = (TH1D*)hWW->Clone();

   TH1::AddDirectory(kFALSE);

   h->Sumw2();
   hBkg->Sumw2();
   hh->Sumw2();
   hWW->Sumw2();
   hZZ->Sumw2();
   //hZll->Sumw2();
   hZee->Sumw2();
   //hZmumu->Sumw2();
   //hZtautau->Sumw2();
   
   h->Scale(1.5e+06);
   hBkg->Scale(1.5e+06);
   hh->Scale(1.5e+06);
   hWW->Scale(1.5e+06);
   hZZ->Scale(1.5e+06);
   //hZll->Scale(1.5e+06);
   hZee->Scale(1.5e+06);
   //hZmumu->Scale(1.5e+06);
   //hZtautau->Scale(1.5e+06);
   
   
   hh->Add(hWW);
   hh->Add(hZZ);
   //hh->Add(hZll);
   hh->Add(hZee);
   //hh->Add(hZmumu);
   //hh->Add(hZtautau);
   

   hBkg->Add(hZZ);
   //hBkg->Add(hZll);
   hBkg->Add(hZee);
   //hBkg->Add(hZmumu);
   //hBkg->Add(hZtautau);
   

   // Gives yield without background + its error

   Double_t error_nsigMC_365GeV;
   Double_t nsigMC_365GeV = h->IntegralAndError(1, h->GetNbinsX(), error_nsigMC_365GeV, "");
   //Double_t nsigMC_365GeV = h->IntegralAndError(1, 67, error_nsigMC_365GeV, "");

   // Gives yield of the background + its error

   Double_t error_nbkgMC_365GeV;
   Double_t nbkgMC_365GeV = hBkg->IntegralAndError(1, hBkg->GetNbinsX(), error_nbkgMC_365GeV, "");
   //Double_t nbkgMC_365GeV = hBkg->IntegralAndError(1, 67, error_nbkgMC_365GeV, "");

   Double_t nMC_365GeV = nsigMC_365GeV + nbkgMC_365GeV;

   // S e t u p   b a c k g r o u n d - o n l y  f i t
   // ---------------------------------------

   // Declare observable mrec
   RooRealVar mrec("MRec", "MRec [GeV]", 120, 140);
   mrec.setConstant();
   RooRealVar a0("a0_365GeV", "a0",0.,-10.,10.);
   RooRealVar a1("a1_365GeV", "a1",0.,-10.,10.);
   //RooRealVar a2("a2", "a2",0.,-10.,10.);
   //RooRealVar a3("a3", "a3",0.,-10.,10.);

   //RooChebychev bkgModel("bkgModel","Chebychev model",mrec,{a0,a1,a2,a3});
   RooPolynomial bkgModel("bkgModel","Polynomial model",mrec,RooArgList(a0,a1));
   
   // Define side band regions and full range
   mrec.setRange("LEFT",120,123.5);
   mrec.setRange("RIGHT",130,140);                                                                                                                                                        
   mrec.setRange("FULL",120,140);    //signal region 

   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   TFile *eeFileT = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/source/p8_ee_ZH_ecm365_sel_ZeeH_noRVec.root");
   TFile *eeFileT2 = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/source/wzp6_ee_eeH_ecm365_sel_ZeeH_noRVec.root");
   TFile *WWFileT = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/source/p8_ee_WW_ecm365_sel_ZeeH_noRVec.root");
   TFile *ZZFileT = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/source/p8_ee_ZZ_ecm365_sel_ZeeH_noRVec.root");
   //TFile *ZllFileT = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/source/p8_ee_Zll_ecm365_sel_ZeeH_noRVec.root");
   TFile *ZeeFileT = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/source/wzp6_ee_ee_Mee_30_150_ecm365_sel_ZeeH_noRVec.root");
   //TFile *ZmumuFileT = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/source/wzp6_ee_mumu_ecm365_sel_ZeeH_noRVec.root");
   //TFile *ZtautauFileT = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/source/wzp6_ee_tautau_ecm365_sel_ZeeH_noRVec.root");

    RooFormulaVar wFuncHZ("weight_T1","weight_T","(0.03519)",mrec) ; //p8_ZH sample
    RooFormulaVar wFuncHZ2("weight_T15","weight_T","(0.0313875)",mrec) ; //wzp6 sample
    RooFormulaVar wFuncWW("weight_T2","weight_T","(3.21495)",mrec) ;
    RooFormulaVar wFuncZZ("weight_T3","weight_T","(0.19284)",mrec) ;
    RooFormulaVar wFuncZee("weight_T4","weight_T","(0.2295)",mrec) ;
    //RooFormulaVar wFuncZmumu("weight_T4","weight_T","(0.346515152)",mrec) ;
    //RooFormulaVar wFuncZtautau("weight_T5","weight_T","(0.30255)",mrec) ;
    //RooFormulaVar wFuncgaga("weight_T6","weight_T","(0.42645)",mrec) ;
   


    
    RooDataSet * dataHZ = new RooDataSet("dataHZ","dataHZ", (TTree*)eeFileT -> Get("MRecT"), RooArgSet(mrec));
    RooRealVar * weight_T = (RooRealVar *)dataHZ->addColumn(wFuncHZ);
    dataHZ -> Print();
    RooDataSet wdataHZ(dataHZ->GetName(), dataHZ->GetTitle(), dataHZ, *dataHZ->get(), 0, weight_T->GetName());
    RooDataSet wdataHZsig("wdataHZsig", dataHZ->GetTitle(), dataHZ, *dataHZ->get(), 0, weight_T->GetName());
    wdataHZ.Print();
    cout << wdataHZ.isWeighted() << endl; 

    RooDataSet * dataHZ2 = new RooDataSet("dataHZ2","dataHZ2", (TTree*)eeFileT2 -> Get("MRecT"), RooArgSet(mrec));
    RooRealVar * weight_T15 = (RooRealVar *)dataHZ2->addColumn(wFuncHZ2);
    dataHZ2 -> Print();
    RooDataSet wdataHZ2(dataHZ2->GetName(), dataHZ2->GetTitle(), dataHZ2, *dataHZ2->get(), 0, weight_T15->GetName());
    wdataHZ2.Print();
    cout << wdataHZ2.isWeighted() << endl; 

    RooDataSet * dataWW = new RooDataSet("dataWW","dataWW", (TTree*)WWFileT -> Get("MRecT"), RooArgSet(mrec));
    RooRealVar * weight_T2 = (RooRealVar *)dataWW->addColumn(wFuncWW);
    dataWW-> Print();
    RooDataSet wdataWW(dataWW->GetName(), dataWW->GetTitle(), dataWW, *dataWW->get(), 0, weight_T2->GetName());
    wdataWW.Print();
    cout << wdataWW.isWeighted() << endl;

    RooDataSet *  dataZZ = new RooDataSet("dataZZ","dataZZ",(TTree*)ZZFileT -> Get("MRecT"), RooArgSet(mrec));
    RooRealVar * weight_T3 = (RooRealVar *)dataZZ->addColumn(wFuncZZ);
    dataZZ -> Print();
    RooDataSet wdataZZ(dataZZ->GetName(), dataZZ->GetTitle(), dataZZ, *dataZZ->get(), 0, weight_T3->GetName());
    wdataZZ.Print();
    cout << wdataZZ.isWeighted() << endl;

    //RooDataSet *  dataZll = new RooDataSet("dataZll","dataZll",(TTree*)ZllFileT -> Get("MRecT"), RooArgSet(mrec));
    RooDataSet *  dataZee = new RooDataSet("dataZee","dataZee",(TTree*)ZeeFileT -> Get("MRecT"), RooArgSet(mrec));
    RooRealVar * weight_T4 = (RooRealVar *)dataZee->addColumn(wFuncZee);
    dataZee -> Print();
    RooDataSet wdataZee(dataZee->GetName(), dataZee->GetTitle(), dataZee, *dataZee->get(), 0, weight_T4->GetName());
    wdataZee.Print();
    cout << wdataZee.isWeighted() << endl;

    wdataHZ.append(wdataHZ2);
    wdataHZ.append(wdataWW);
    wdataHZ.append(wdataZZ);
    //wdataHZ.append(wdataZll);
    wdataHZ.append(wdataZee);
    //wdataHZ.append(wdataZmumu);
    //wdataHZ.append(wdataZtautau);

    wdataHZsig.append(wdataHZ2);

    wdataWW.append(wdataZZ);
    //wdataWW.append(wdataZll);
    wdataWW.append(wdataZee);
    //wdataWW.append(wdataZmumu);
    //wdataWW.append(wdataZtautau);

    //wdataHZ.addWgtVar(RooArgSet(mrec), weight_T1);

    wdataHZ.Print();
    cout << wdataHZ.isWeighted() <<endl;

    wdataWW.Print();
    cout << wdataWW.isWeighted() <<endl;

    


   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


   RooDataHist dh("dh", "dh", mrec, Import(*hh));
   
   cout << mrec.getBins() << endl;
   
   cout << "Test" << endl;
   wdataHZ.Print();

   // Plot data

   TCanvas * c1 = new TCanvas ("c1", "c1", 100, 200, 700, 500);
   c1 -> cd();
   RooPlot * frame =  mrec.frame(Name("Mrecframe"), Title("Background only Data"), Bins(60));
   wdataHZ.plotOn(frame,DataError(RooAbsData::SumW2));
   frame->Draw();
   c1->Draw();
   c1->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/aplots/data.pdf");

   

   // S+ B fit in background region 
   RooRealVar N("N_365GeV", "Extended term", nbkgMC_365GeV,0,55000);
   
   //Definition of the extended model
   RooExtendPdf extmodel("extmodel", "Extended model", bkgModel, N, "FULL");
   
   TCanvas* c2 = new TCanvas ("c2", "c2", 100, 200, 700, 500);

   c2->cd();

   RooFitResult* r2 = extmodel.fitTo(wdataWW, Range("FULL"),Save(), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit2","migrad"), PrintEvalErrors(-1));
   r2->Print();
   RooPlot* frame2 = mrec.frame(Name("m_recoil_frame"), Title("Fit background"), Bins(60));
   wdataWW.plotOn(frame2);
   extmodel.plotOn(frame2,LineColor(kGreen+2));
   // extmodel.plotOn(frame2, VisualizeError(*r2));
   extmodel.paramOn(frame2, Label("Extended B fit. in Bkg region"), Layout(0.1, 1., 0.25));                                                                                
   frame2 -> GetXaxis()->SetRangeUser(120, 140);
   frame2->Draw();
   c2->Draw();
   c2->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/aplots/bkg_only.pdf");   
   a0.setConstant(kTRUE);
   a1.setConstant(kTRUE);
   //a2.setConstant(kTRUE);
   //a3.setConstant(kTRUE); 

   //N.setVal(nbkgMC_365GeV);
   N.setConstant(kTRUE);

  
   // PART 2: S+B model
   // --------------------------------

   TCanvas* c3 = new TCanvas ("c3", "c3", 100, 200, 700, 500);
   c3 -> cd();

   // COM smearing @ 365 GeV
   RooConstVar COMideal_365GeV("COMideal_365GeV", "ideal COM", 365.);
   RooRealVar COMmess_365GeV("COMmess_365GeV", "measured COM energy", 1., 1. - (365*0.0000012), 1. + (365*0.0000012));
   RooGaussian COMsmear_365GeV("COMsmear_365GeV", "COM smearing", RooConst(1.), COMmess_365GeV, RooConst(0.000012)); // 0.056
   //COMmess_365GeV.setConstant();
   
   // mH smearing @ 365 GeV
   RooRealVar mHmess_365GeV("mHmess_365GeV", "measured Higgs mass", 125., 122., 128.);
   RooGaussian mHsmear_365GeV("mHsmear_365GeV", "Higgs mass smearing", RooConst(125.), mHmess_365GeV, RooConst(0.14));
   RooRealVar mZ("mZ", "mZ", 91.188);
   
   // Luminosity smearing @ 365 GeV
   RooConstVar Lideal_365GeV("Lideal_365GeV", "ideal Luminosity", 1.5e+06);
   RooRealVar Lmess_365GeV("Lmess_365GeV", "Luminosity measured", 1., 1. - (10*0.001), 1. + (10*0.001));
   RooGaussian Lsmear_365GeV("Lsmear_365GeV", "Luminosity smearing", RooConst(1.), Lmess_365GeV, RooConst(0.001));
   RooProduct varL_365GeV("varL_365GeV", "varL_365GeV", RooArgSet(Lmess_365GeV, Lideal_365GeV));
   //Lmess_365GeV.setConstant();
   
   // Efficiency smearing @ 365 GeV
   RooConstVar Eideal_365GeV("Eideal_365GeV", "ideal Efficiency", 0.1774325);
   RooRealVar Emess_365GeV("Emess_365GeV", "Efficiency_mess", 1., 1. - (10*0.01), 1. + (10*0.01)); 
   RooGaussian Esmear_365GeV("Esmear_365GeV", "Efficiency smearing", RooConst(1.), Emess_365GeV, RooConst(0.01));
   RooProduct varE_365GeV("varE_365GeV", "varE_365GeV", RooArgSet(Emess_365GeV, Eideal_365GeV));
   //Emess_365GeV.setConstant();
   
   // BR smearing @ 365 GeV
   RooConstVar BRideal_365GeV("BRideal_365GeV","BRideal_365GeV",1.);
   RooRealVar BRmess_365GeV("BRmess_365GeV", "BR_mess", 1., 1. - 20*(0.002), 1. + 20*(0.002)); // 0.2, 1.5
   RooGaussian BRsmear_365GeV("BRsmear_365GeV", "BR smearing", RooConst(1.), BRmess_365GeV, RooConst(0.002));
   RooProduct varBR_365GeV("varBR_365GeV", "varBR_365GeV", RooArgSet(BRmess_365GeV, BRideal_365GeV));
   //BRmess_365GeV.setConstant();
   
   // Kappa Lambda @ 365 GeV
   RooRealVar varKappaideal_365GeV("varKappaideal_365GeV", "Kappa_ideal", 0.); //0., -10, 15.
   RooConstVar varKappasigma_365GeV("varKappasigma_365GeV", "Kappa_sigma", 10.); //1e-03
   RooRealVar varKappa_365GeV("varKappa_365GeV", "kappa variation", 0., -20, 20); //-20, 20.
   RooRealVar varKappaHZZ_365GeV("varKappaHZZ_365GeV", "kappa HZZ variation", 0.); //0., -2., 2.
   
   RooGaussian varKappasmear_365GeV("varKappasmear_365GeV", "varKappa smearing", varKappaideal_365GeV, varKappa_365GeV, varKappasigma_365GeV);

   // Fit a Crystalball pdf to the data
   
   //RooFormulaVar mean_365GeV("mean", "sqrt((( @0)^2)*@2  + ((@3)^2) + ((@1)^2) - (@2)*((@3)^2 + ((@1)^2)/((@2)^2)))", RooArgSet(mHmess_365GeV,COMideal_365GeV,COMmess_365GeV,mZ));
   //RooRealVar sigma_365GeV("sigma", "sigma", 0.9, 0.2, 1.0);
   //RooRealVar alphaL_365GeV("alphaL", "alphaL", 1., 0.1, 5);
   //RooRealVar alphaR_365GeV("alphaR", "alphaR", 1., 0.1, 5);
   //RooRealVar NL_365GeV("NL", "NL", 1.5, 0.1, 50.); //4.6, 0.1, 20
   //RooRealVar NR_365GeV("NR", "NR", 0.5, 0.1, 50.);
   
   //RooRealVar mean2_365GeV("mean2_365GeV", "mean2", 128, 125, 130);
   //RooRealVar sigma2_365GeV("sigma2_365GeV", "sigma2", 0.9, 0.2, 1.0);
   //RooGaussian sig2_365GeV("sig2_365GeV", "Signal2", mrec, mean2_365GeV, sigma2_365GeV);
   //RooRealVar fsig("fsig", "signal fraction", 0.5, 0., 1.);

   //RooCrystalBall CBsig_365GeV("sig", "Signal", mrec, mean_365GeV, sigma_365GeV, alphaL_365GeV, NL_365GeV, alphaR_365GeV, NR_365GeV);

   //RooAddPdf sig_365GeV("finalsig", "final signal", RooArgList(CBsig_365GeV, sig2_365GeV), fsig);

   RooFormulaVar mean_365GeV("mean", "sqrt((( @0)^2)*@2  + ((@3)^2) + ((@1)^2) - (@2)*((@3)^2 + ((@1)^2)/((@2)^2)))", RooArgSet(mHmess_365GeV,COMideal_365GeV,COMmess_365GeV,mZ));
   RooRealVar sigma_365GeV("sigma", "sigma", 0.55, 0.1, 2);
   RooRealVar alphaL_365GeV("alphaL", "alphaL", 1., -1, 10);
   RooRealVar alphaR_365GeV("alphaR", "alphaR", 1., -1, 10);
   RooRealVar NL_365GeV("NL", "NL", 3., 0.5, 9.); //4.6, 0.1, 20
   RooRealVar NR_365GeV("NR", "NR", 3., 0.5, 9.);
   
   RooRealVar mean2_365GeV("mean2_365GeV", "mean2", 125.5, 123, 127);
   RooRealVar sigma2_365GeV("sigma2_365GeV", "sigma2", 0.8, 0.1, 4);
   RooGaussian gauss_365GeV("gauss_365GeV", "Gaussian", mrec, mean2_365GeV, sigma2_365GeV);
   RooRealVar fsig("fsig", "signal fraction", 0.4, 0.01, 0.7);
   RooRealVar fsig2("fsig2", "signal fraction 2", 0.4, 0.01, 0.7);

   RooCrystalBall CB1sig_365GeV("CB1sig_365GeV", "CB Signal 1", mrec, mean_365GeV, sigma_365GeV, alphaL_365GeV, NL_365GeV, false);
   RooCrystalBall CB2sig_365GeV("CB2sig_365GeV", "CB Signal 2", mrec, mean_365GeV, sigma_365GeV, alphaR_365GeV, NR_365GeV, false);

   RooAddPdf sig_365GeV("finalsig", "final signal", RooArgList(CB1sig_365GeV, CB2sig_365GeV, gauss_365GeV), RooArgList(fsig, fsig2), true);


  
   
   // NLO CS @ 365 GeV
   RooConstVar CSTrue_365GeV("CSTrue_365GeV", "CS_True", 0.00739);
   RooConstVar CSLO_365GeV("CSLO_365GeV", "CS_LO", 0.007359385); // in pb
   RooConstVar C1_365GeV("C1_365GeV", "C1", 0.0057); 
   RooConstVar dZh_365GeV("dZh_365GeV", "deltanZh parameter", -0.00154);
   
   //RooRealVar CSHZTrue_365GeV("CSHZTrue_365GeV", "CS HZ true", 0.9, 0.5, 1.1); //0.9, 0.5, 1.1
   
   RooFormulaVar CSNLO_365GeV("CSNLO_365GeV", "((1./(1.-(@2)*(@3+1.)^2))*(@0)*(1. + (@1)*(@3+1.)))", RooArgSet(CSLO_365GeV, C1_365GeV, dZh_365GeV, varKappa_365GeV)); 
   
   // C o n s t r u c t   e x t e n d e d   c o m p o s i t e   m o d e l
   // -------------------------------------------------------------------
   
   // Sum the composite signal and background into an extended pdf nsig*sig+nbkg*bkg
   RooRealVar nsig_365GeV("nsig", "number of signal events", nsigMC_365GeV, 0., 50000); //nsigMC_365GeV
   
   RooRealVar nsigTrue_365GeV("nsigTrue", "number of MC signal events", nsigMC_365GeV); //nsigMC_365GeV
   nsigTrue_365GeV.setError(error_nsigMC_365GeV); //error_nsigMC_365GeV
   RooRealVar nbkg_365GeV("nbkg_365GeV", "number of background events", nbkgMC_365GeV); //nbkgMC_365GeV
   nbkg_365GeV.setError(error_nbkgMC_365GeV); //error_nbkgMC_365GeV
   
   // Extract kappa
   //RooProduct muZHsig_365GeV("muZHsig_365GeV", "muZHsig_365GeV", RooArgSet(CSNLO_365GeV, varL_365GeV, varE_365GeV, varBR_365GeV));
   
   //Extract muZH
   RooRealVar muZH_365GeV("muZH_365GeV", "muZH_365GeV", 1., 0.5, 1.5); 
   RooProduct muZHsig_365GeV("muZHsig", "muZH_365GeV * varL_365GeV * varE_365GeV * (CSTrue_365GeV * BRideal_365GeV)", RooArgList(muZH_365GeV, varL_365GeV, varE_365GeV, CSTrue_365GeV, BRideal_365GeV));
   
   RooAddPdf modelBare_365GeV("modelBare", "(g1+g2)+a", RooArgList(bkgModel, sig_365GeV), RooArgList(N, muZHsig_365GeV));
   
   //RooProdPdf model_365GeV("model", "Final model", RooArgList(modelBare_365GeV, Lsmear_365GeV, Esmear_365GeV, mHsmear_365GeV, COMsmear_365GeV, BRsmear_365GeV, varKappasmear_365GeV));
   RooProdPdf model_365GeV("model", "Final model", RooArgList(modelBare_365GeV, Lsmear_365GeV, Esmear_365GeV, mHsmear_365GeV, COMsmear_365GeV, BRsmear_365GeV));
   modelBare_365GeV.fixCoefNormalization(mrec);
   sig_365GeV.fixCoefNormalization(mrec);

   //N.setVal(0.);

   // Save snapshot of prefit parameters
   RooArgSet *params = model_365GeV.getParameters(mrec);
   RooArgSet *initParams = (RooArgSet *)params->snapshot();


   //RooFitResult* r3 = model_365GeV.fitTo(dh, Range("FULL"),Save(), Extended(kTRUE), Offset(kTRUE), Constrain(RooArgSet(Lsmear_365GeV, Esmear_365GeV, COMsmear_365GeV, BRsmear_365GeV)));
   //RooFitResult* r3 = model_365GeV.fitTo(dh, Range("FULL"),Save(), Extended(kTRUE), Offset(kTRUE), ExternalConstraints( RooArgSet(mHsmear_365GeV,varKappasmear_365GeV)));
   
   RooFitResult* r3 = model_365GeV.fitTo(wdataHZ,Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(Lsmear_365GeV, Esmear_365GeV, COMsmear_365GeV, BRsmear_365GeV, mHsmear_365GeV)), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit","migrad"), GlobalObservables(RooArgSet(Lmess_365GeV, Emess_365GeV, COMmess_365GeV, BRmess_365GeV)), Strategy(2)); //, Minimizer("Minuit2","migrad") Minos???, Strategy(2)

   r3->Print();

   //RooFitResult* r3 = model_365GeV.fitTo(dh, Range("FULL"),Save(), ExternalConstraints( RooArgSet(mHsmear_365GeV,varKappasmear_365GeV)));
   
   RooPlot* frame3 = mrec.frame(Name("Mrecframe"), Title("S+B fit"), Bins(60));
   frame3 -> GetXaxis() ->SetRangeUser(120., 139.5); 
   wdataHZ.plotOn(frame3,DataError(RooAbsData::SumW2));
   model_365GeV.plotOn(frame3, LineColor(kAzure-2));       //modelsum.
   //modelsum.plotOn(frame3,VisualizeError(*r3));
   //modelsum.plotOn(frame3,VisualizeError(*r3, 2, kFALSE),FillColor(kOrange)); 
   
   model_365GeV.plotOn(frame3,Components(bkgModel), LineColor(kGreen+2),LineStyle(kDashed),Name("Bkg only") );
   model_365GeV.plotOn(frame3,Components(sig_365GeV), LineColor(kRed-4),LineStyle(kDotted),  Name("Sgn only") );
   model_365GeV.plotOn(frame3,Components(gauss_365GeV), LineColor(kGreen-2),LineStyle(kDashDotted), Name("Sgn Gauss only") );
   model_365GeV.plotOn(frame3,Components(CB2sig_365GeV), LineColor(kOrange-4),LineStyle(kDashed), Name("Sgn CB2 only") );
   
   // model_365GeV.paramOn(frame3, Label("S+B fit"));     //modelsum
   frame3->Draw();
   
   c3->Draw();
   c3->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/aplots/S_B_fit.pdf");

   
   // Make list of model parameters
   // P r i n t   l a t ex   t a b l e   o f   p a r a m e t e r s   o f   p d f
   // --------------------------------------------------------------------------
   
   // Print parameter list in LaTeX for (one column with names, one column with values)
   params->printLatex();
   
   // Print parameter list in LaTeX for (names values|names values)
   params->printLatex(Columns(2));
   
   // Print two parameter lists side by side (name values initvalues)
   params->printLatex(Sibling(*initParams));
   
   // Print two parameter lists side by side (name values initvalues|name values initvalues)
   params->printLatex(Sibling(*initParams), Columns(2));
   
   // Write LaTex table to file
   params->printLatex(Sibling(*initParams), OutputFile("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/aplots/latextables.tex"));
   
   RooPlot* frame30 = mrec.frame(Name("Mrecframe"), Title("S+B fit"), Bins(60));  
   wdataHZ.plotOn(frame30,DataError(RooAbsData::SumW2));
   model_365GeV.plotOn(frame30, LineColor(kAzure-2));

   cout << "Background-only chi^2 = " << frame2 -> chiSquare(2) << endl;
   //cout << "S+B chi^2 = " << frame3 -> chiSquare(10) << endl;

   /*
  
   // V i s u a l i z e   c o r r e l a t i o n   m a t r i x
   // -------------------------------------------------------
   
   // Construct 2D color plot of correlation matrix
   gStyle->SetOptStat(0);
   TH2 *hcorr = r3->correlationHist();
   
   // Visualize ellipse corresponding to single correlation matrix element
   RooPlot *framecorr = new RooPlot(mHmess_365GeV, varKappa_365GeV , 124.8, 125.2, -1.2, 0.5);
   framecorr->SetTitle("Covariance between mH and x_sec_norm");
   r3->plotOn(framecorr, mHmess_365GeV,  varKappa_365GeV , "ME12ABHV");
   
   TCanvas *ccorr = new TCanvas("", "", 800, 400);
   ccorr->Divide(2);
   ccorr->cd(1);
   gPad->SetLeftMargin(0.15);
   hcorr->GetYaxis()->SetTitleOffset(1.4);
   hcorr->Draw("colz");
   ccorr->cd(2);
   gPad->SetLeftMargin(0.15);
   framecorr->GetYaxis()->SetTitleOffset(1.6);
   framecorr->Draw();
   ccorr->Draw();
   ccorr->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/aplots/corr.eps"); 

   */


   // C a l c u l a t e   c h i ^ 2
 // ------------------------------
 
 // Show the chi^2 of the curve w.r.t. the histogram
 // If multiple curves or datasets live in the frame you can specify
 // the name of the relevant curve and/or dataset in chiSquare()
  cout << "chi^2 = " << frame30 -> chiSquare(10) << endl;
 
 
 // S h o w   r e s i d u a l   a n d   p u l l   d i s t s
 // -------------------------------------------------------
 
 // Construct a histogram with the residuals of the data w.r.t. the curve
 RooHist *hresid = frame30->residHist();
 
 // Construct a histogram with the pulls of the data w.r.t the curve
 RooHist *hpull = frame30->pullHist();
 
 // Create a new frame to draw the residual distribution and add the distribution to the frame
 RooPlot *frame31 = mrec.frame(Title("Residual Distribution"), Bins(60));
 frame31->addPlotable(hresid, "P");
 
 // Create a new frame to draw the pull distribution and add the distribution to the frame
 RooPlot *frame32 = mrec.frame(Title("Pull Distribution"), Bins(60));
 frame32->addPlotable(hpull, "P");
 RooPlot *frame32b = mrec.frame(Title("Pulls"), Bins(60));
 frame32b->addPlotable(hpull, "P");
 
 TCanvas *c31 = new TCanvas("chi2residpull", "chi2residpull", 900, 300);
 c31->Divide(2);
 c31->cd(1);
 gPad->SetLeftMargin(0.15);
 frame31->GetYaxis()->SetTitleOffset(1.6);
 frame31 -> GetXaxis() ->SetRangeUser(120, 139.5);
 frame31->Draw();
 c31->cd(2);
 gPad->SetLeftMargin(0.15);
 frame32->GetYaxis()->SetTitleOffset(1.6);
 frame32 -> GetXaxis() ->SetRangeUser(120, 139.5);
 frame32->Draw();


 c31->Draw();
 c31->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/aplots/pulls_resid.pdf");

 TCanvas *c = new TCanvas("","",800,800);
 TPad *pad1 = new TPad("","",0,0.33,1,1);
 TPad *pad2 = new TPad("","",0,0,1,0.33);
 pad1->SetBottomMargin(0.00001);
 pad1->SetBorderMode(0);
 // pad1->SetLogy();
 pad2->SetTopMargin(0.00001);
 pad2->SetBottomMargin(0.5);
 pad2->SetBorderMode(0);
 pad1->Draw();
 pad2->Draw();
 pad1->cd();
 frame3 ->GetYaxis()->SetLabelFont(63);
 frame3->GetYaxis()->SetLabelSize(16);
 frame3-> Draw();
 auto leg = new TLegend(0.65,0.73,0.86,0.87);
 leg->AddEntry("data", "ALL MC"," lep");
 leg->AddEntry("Bkg only", "Bkg only", "l");
 leg->AddEntry("Sgn Comp1 only", "Sgn Comp1 only", "l");
 leg->AddEntry("Sgn Comp2 only", "Sgn Comp2 only", "l");
 leg->SetBorderSize(0);
 leg->Draw();
 pad2->cd();

 frame32b->GetXaxis()->SetTitleSize(.10);
 frame32b->GetXaxis()->SetTitleOffset(1.0);
 frame32b->GetXaxis()->SetTitleOffset(1.0);
 frame32b->GetXaxis()->SetLabelFont(63);
 frame32b->GetXaxis()->SetLabelSize(16);
 frame32b->GetYaxis()->SetLabelFont(63);
 frame32b->GetYaxis()->SetLabelSize(16);
 frame32b-> Draw();
 
 c->cd();
 c->Draw();
 c->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/aplots/Fit_pulls.pdf");

 cout << mean_365GeV.getVal() << endl;
 
 RooWorkspace *w = new RooWorkspace("w", "workspace");

 w->import(model_365GeV);

 //w->import(wFuncHZ);
 //w->import(wFuncWW);
 //w->import(wFuncZZ);
 //w->import(wFuncZll);
 //w->import(wFuncgaga);
 w->import(*weight_T);
 
 w->defineSet("poi", "muZH_365GeV");
 //w->defineSet("poi", "varKappa_365GeV");
 w->defineSet("np", RooArgSet(sigma_365GeV, alphaL_365GeV, alphaR_365GeV, NL_365GeV, NR_365GeV, mean2_365GeV, sigma2_365GeV, fsig, fsig2, N, mHmess_365GeV), kTRUE);
 w->defineSet("glob", RooArgSet(Lmess_365GeV, Emess_365GeV, BRmess_365GeV, COMmess_365GeV), kTRUE);
 w->defineSet("obs", "MRec");

 w->import(wdataHZ, Rename("centrally_samples"));
 

 RooArgSet globSet = *(w->set("glob"));
 RooArgSet nuisSet = *(w->set("np"));
 RooArgSet poiSet = *(w->set("poi"));



 RooStats::ModelConfig mc(w);
 mc.SetPdf("model");
 mc.SetObservables(*(w->set("obs")));
 mc.SetParametersOfInterest(poiSet);
 mc.SetNuisanceParameters(nuisSet);
 mc.SetGlobalObservables(globSet);

 w->var("muZH_365GeV")->setVal(1);
 mc.SetSnapshot(*(w->var("muZH_365GeV")));

 //w->var("varKappa_365GeV")->setVal(0);
 //mc.SetSnapshot(*(w->var("varKappa_365GeV")));

 mc.Print();

 w->import(mc);

 

 const RooArgSet * genPoiValues = 0;

 RooAbsData * asimov = RooStats::AsymptoticCalculator::MakeAsimovData(wdataHZ, mc, poiSet, globSet, genPoiValues);

 RooFitResult * r4 = w->pdf("model")->fitTo(*asimov,Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(Lsmear_365GeV, Esmear_365GeV, COMsmear_365GeV, mHsmear_365GeV, BRsmear_365GeV)), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit","migradimproved"), GlobalObservables(globSet), Strategy(2));

 r4->Print();

  // Plot Asimov

   TCanvas * c7 = new TCanvas ("c1", "c1", 100, 200, 700, 500);
   c7 -> cd();
   RooPlot * frame7 =  mrec.frame(Name("Mrecframe"), Title("Data"));
   asimov->plotOn(frame7,DataError(RooAbsData::SumW2));
   frame7->Draw();
   c7->Draw();
   c7->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/aplots/adata.pdf");


  w->import(*asimov, Rename("eeH_Asimov"));

  RooArgSet *asimov_parameters = (RooArgSet*)w->pdf("model")->getParameters(mrec);
  w->saveSnapshot("eeH_asimovFit", *asimov_parameters, kTRUE);

  w->writeToFile("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/ZeeH365_muZH.root");
 

/*

 // PART 3:  Likelihood scan                                                                                                                                                                                  
 // ----------------------------                                                                                                                                                                                  
 
 // C o n s t r u c t   p l a i n   l i k e l i h o o d
 // ---------------------------------------------------
 
 TCanvas* c6 = new TCanvas ("c6", "c6", 100, 200, 700, 500);
 TCanvas* c4 = new TCanvas ("c4", "c4", 100, 200, 700, 500);
 TCanvas* c5 = new TCanvas ("c5", "c5", 100, 200, 700, 500);

 // Construct unbinned likelihood
 //RooAbsReal * nll = model_365GeV.createNLL(dh, Extended(kTRUE), Offset(kTRUE));
 
 //RooAbsReal * nll = model_365GeV.createNLL(dh, Extended(kTRUE), Offset(kTRUE), ExternalConstraints( RooArgSet( mHsmear_365GeV,varKappasmear_365GeV)));
 
 //RooAbsReal * nll = model_365GeV.createNLL(wdataHZ, Extended(kTRUE), ExternalConstraints( RooArgSet( mHsmear_365GeV))); //Best Result
 RooAbsReal * nll = model_365GeV.createNLL(wdataHZ, NumCPU(3)); //Best Result
 
 //RooAbsReal * nll = model_365GeV.createNLL(dh, Extended(kTRUE), ExternalConstraints( RooArgSet( mHsmear_365GeV)));

 //RooAbsReal * nll = model_365GeV.createNLL(dh);
 // RooAbsReal * nllunc = modelsum_stat.createNLL(wdataHZ,ExternalConstraints( RooArgSet( mH_subs,kl_subs)) , NumCPU(2));

 // Minimize likelihood w.r.t all parameters before making /afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/aplots
 RooMinimizer minim(*nll);
 //minim.minimize("Minuit2");
   minim.migrad();
   
   //RooMinimizer(*nllunc).migrad();
 
 // Plot likelihood scan in Nsig
  RooPlot *frame4 = varKappa_365GeV.frame(Range(-8., 17.), Title("NLL in #delta#kappa_{#lambda} "));
  // RooPlot *frame4 = fsig.frame(Bins(20), Range(0.2, 0.6), Title("NLL in f_{sig}"));
   frame4 -> GetXaxis() ->SetRangeUser(-8, +17.);
   
   nll->plotOn(frame4,LineColor(kAzure-2), ShiftToZero());

// C o n s t r u c t   p r o f i l e   l i k e l i h o o d   i n   m u  Z H
 // -----------------------------------------------------------------------
 
 // The profile likelihood estimator on nll for Nsig will minimize nll w.r.t
 // all floating parameters except Nsig for each evaluation

 // Plot likelihood scan in Nsig
  RooPlot *frame6 = muZH_365GeV.frame(Range(0.7, 1.2), Title("NLL in #mu_{ZH} "));
  // RooPlot *frame4 = fsig.frame(Bins(20), Range(0.2, 0.6), Title("NLL in f_{sig}"));
   frame6 -> GetXaxis() ->SetRangeUser(0.7, 1.2);
   
   muZH_365GeV = 1;
   nll->plotOn(frame6,LineColor(kAzure-2), ShiftToZero());
 
 RooAbsReal *pll_muZH = nll->createProfile(muZH_365GeV);
 // RooAbsReal * pll_kl_unc = nllunc->createProfile(delta_kl);

 //RooAbsReal *pll_fsig = nll->createProfile( fsig);
 c6 -> cd();
 // Plot the profile likelihood in frac
 pll_muZH -> plotOn(frame6, LineColor(kRed),LineStyle(kSolid));
 // pll_kl_unc -> plotOn(frame4, LineColor(kAzure-4),LineStyle(kDashDotted));
 // pll_fsig->plotOn(frame4, LineColor(kAzure-2),LineStyle(kDashed));
 frame6->GetYaxis()->SetTitleOffset(1.4);
 frame6->SetMinimum(0.);
 frame6->SetMaximum(4.);
 frame6->Draw(); 
 c6->Draw(); 
 c6->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/aplots/NLL_prf_muZH.pdf");

 cout << "Test2" << endl;
 wdataHZ.Print();
 
 /*
 
 // C o n s t r u c t   p r o f i l e   l i k e l i h o o d   i n   k l
 // -----------------------------------------------------------------------
 
 // The profile likelihood estimator on nll for Nsig will minimize nll w.r.t
 // all floating parameters except Nsig for each evaluation
 
 RooAbsReal *pll_kl = nll->createProfile(varKappa_365GeV);
 // RooAbsReal * pll_kl_unc = nllunc->createProfile(delta_kl);

 //RooAbsReal *pll_fsig = nll->createProfile( fsig);
 c4 -> cd();
 // Plot the profile likelihood in frac
 pll_kl -> plotOn(frame4, LineColor(kRed),LineStyle(kSolid));
 // pll_kl_unc -> plotOn(frame4, LineColor(kAzure-4),LineStyle(kDashDotted));
 // pll_fsig->plotOn(frame4, LineColor(kAzure-2),LineStyle(kDashed));
 frame4->GetYaxis()->SetTitleOffset(1.4);
 frame4->SetMinimum(0.);
 frame4->SetMaximum(8.);
 frame4->Draw(); 
 c4->Draw(); 
 c4->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/aplots/NLL_prf_kl.pdf");

 */

 /*
 // C o n s t r u c t   p r o f i l e   l i k e l i h o o d   i n   m H                                                                                                                                
 // -----------------------------------------------------------------------                                                                                                                            

 // The profile likelihood estimator on nll for Nsig will minimize nll w.r.t                                                                                                                           
 // all floating parameters except Nsig for each evaluation                                                                                                                                            

 RooAbsReal *pll_mh = nll->createProfile(mH);
 //RooAbsReal * pll_mh_unc = nllunc->createProfile(mH);

 //RooAbsReal *pll_fsig = nll->createProfile( fsig);                                                                                                                                                   
 c5 -> cd();
 RooPlot *frame5 = mH.frame(Bins(500), Range(124.8, 125.2), Title("NLL in #delta#kappa_{#lambda} "));
 // Plot the profile likelihood in frac                                                                                                                                                                
 pll_mh -> plotOn(frame5, LineColor(kRed-4),LineStyle(kSolid));
 // pll_mh_unc -> plotOn(frame5, LineColor(kRed-7),LineStyle(kDashDotted));
 // pll_fsig->plotOn(frame4, LineColor(kAzure-2),LineStyle(kDashed));                                                                                                                                  
 frame5->GetYaxis()->SetTitleOffset(1.4);
 frame5->SetMinimum(0.);
 frame5->SetMaximum(2.);
 frame5->Draw();
 c5->Draw();
 c5->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/aplots/NLL_prf_mh.eps");
 */
 
 /*
 // S a v i n g   r e s u l t s ,   c o n t o u r   p l o t s
 // ---------------------------------------------------------
 
 // Save a snapshot of the fit result. This object contains the initial
 // fit parameters, the final fit parameters, the complete correlation
 // matrix, the EDM, the minimized FCN , the last MINUIT status code and
 // the number of times the RooFit function object has indicated evaluation
 // problems (e.g. zero probabilities during likelihood evaluation)
 
 // Create MINUIT interface object

 RooMinimizer m(*nll);
 m.setVerbose(kTRUE); 
 m.migrad();
 
 // Print values of all parameters, that reflect values (and error estimates)
 // that are back propagated from MINUIT
 
 model_365GeV.getParameters( mrec)->Print("s");
 
 // Disable verbose logging
 m.setVerbose(kFALSE);
 
 // Run HESSE to calculate errors from d2L/dp2
 m.hesse();
 
 // Print value (and error) of sigma_g2 parameter, that reflects
 // value and error back propagated from MINUIT
 varKappa_365GeV.Print();      //Nsig
 mHmess_365GeV.Print();
 
 // Run MINOS 
 m.minos();
 
 // Print value (and error) of sigma_g2 parameter, that reflects
 // value and error back propagated from MINUIT
 varKappa_365GeV.Print();     //Nsig
 mHmess_365GeV.Print();

 RooFitResult *r4 = m.save(); 

 
 // Make contour plot of mx vs sx at 1,2,3 sigma

 // RooPlot *frame6 = m.contour(delta_kl, mH, TMath::Sqrt( ROOT::Math::chisquared_quantile(0.68,2) ),TMath::Sqrt( ROOT::Math::chisquared_quantile(0.95,2) ) );    //Nsig
  RooPlot *frame6 = m.contour(varKappa_365GeV, mHmess_365GeV, 1,2 );    //Nsig 
 
 frame6->SetTitle("Minuit contour");
 
 TCanvas* c6 = new TCanvas ("c6", "c6", 100, 200, 700, 500);
 c6 -> cd(); 
 gPad->SetLeftMargin(0.15);
 frame6->GetYaxis()->SetTitleOffset(1.8);
 
 frame6 -> GetXaxis() ->SetRangeUser(-7., 7.);
 frame6 -> GetYaxis() ->SetRangeUser(124., 126.); 

 frame6->Draw();
 c6->Draw();
 c6->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/365/eeH/aplots/contour_kl_mH.pdf");

*/

//delete pll_kl;
 // delete pll_kl_unc;
//delete nll;
 // delete nllunc;
 // delete pll_mh;
 // delete pll_mh_unc;






}
