#include "RooRealVar.h"
#include "RooStats/ModelConfig.h"
#include "RooStats/AsymptoticCalculator.h"
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
#include "RooKeysPdf.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "RooPlot.h"
using namespace RooFit;

void AZmumu_H() {

    // Import files

   TFile *mumuFile = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/presel/histos/wzp6_ee_mumuH_ecm240_sel_ZmumuH4_histo.root");
   TFile *WWFile = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/presel/histos/p8_ee_WW_ecm240_sel_ZmumuH4_histo.root");
   TFile *ZZFile = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/presel/histos/p8_ee_ZZ_ecm240_sel_ZmumuH4_histo.root");
   //TFile *ZllFile = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/presel/histos/p8_ee_Zll_ecm240_sel_ZmumuH4_histo.root");
   TFile *ZeeFile = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/presel/histos/wzp6_ee_ee_Mee_30_150_ecm240_sel_ZmumuH4_histo.root");
   TFile *ZmumuFile = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/presel/histos/wzp6_ee_mumu_ecm240_sel_ZmumuH4_histo.root");
   TFile *ZtautauFile = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/presel/histos/wzp6_ee_tautau_ecm240_sel_ZmumuH4_histo.root");
   TFile *gagaFile = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/presel/histos/wzp6_gaga_mumu_60_ecm240_sel_ZmumuH4_histo.root");

   TH1D *h = (TH1D*)mumuFile->Get("leptonic_recoil_m_zoom6");
   TH1D *hWW = (TH1D*)WWFile->Get("leptonic_recoil_m_zoom6");
   TH1D *hZZ = (TH1D*)ZZFile->Get("leptonic_recoil_m_zoom6");
   //TH1D *hZll = (TH1D*)ZllFile->Get("leptonic_recoil_m_zoom6");
   TH1D *hZee = (TH1D*)ZeeFile->Get("leptonic_recoil_m_zoom6");
   TH1D *hZmumu = (TH1D*)ZmumuFile->Get("leptonic_recoil_m_zoom6");
   TH1D *hZtautau = (TH1D*)ZtautauFile->Get("leptonic_recoil_m_zoom6");
   TH1D *hgaga = (TH1D*)gagaFile->Get("leptonic_recoil_m_zoom6");

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
   hZmumu->Sumw2();
   hZtautau->Sumw2();
   hgaga->Sumw2();
   h->Scale(5e+06);
   hBkg->Scale(5e+06);
   hh->Scale(5e+06);
   hWW->Scale(5e+06);
   hZZ->Scale(5e+06);
   //hZll->Scale(5e+06);
   hZee->Scale(5e+06);
   hZmumu->Scale(5e+06);
   hZtautau->Scale(5e+06);
   hgaga->Scale(5e+06);
   
   hh->Add(hWW);
   hh->Add(hZZ);
   //hh->Add(hZll);
   hh->Add(hZee);
   hh->Add(hZmumu);
   hh->Add(hZtautau);
   hh->Add(hgaga);

   hBkg->Add(hZZ);
   //hBkg->Add(hZll);
   hBkg->Add(hZee);
   hBkg->Add(hZmumu);
   hBkg->Add(hZtautau);
   hBkg->Add(hgaga);

   // Gives yield without background + its error

   Double_t error_nsigMC_240GeV;
   Double_t nsigMC_240GeV = h->IntegralAndError(1, h->GetNbinsX(), error_nsigMC_240GeV, "");
   //Double_t nsigMC_240GeV = h->IntegralAndError(1, 67, error_nsigMC_240GeV, "");

   // Gives yield of the background + its error

   Double_t error_nbkgMC_240GeV;
   Double_t nbkgMC_240GeV = hBkg->IntegralAndError(1, hBkg->GetNbinsX(), error_nbkgMC_240GeV, "");
   //Double_t nbkgMC_240GeV = hBkg->IntegralAndError(1, 67, error_nbkgMC_240GeV, "");

   Double_t nMC_240GeV = nsigMC_240GeV + nbkgMC_240GeV;

   // S e t u p   b a c k g r o u n d - o n l y  f i t
   // ---------------------------------------

   // Declare observable mrec
   RooRealVar mrec("MRec", "MRec [GeV]", 120, 140); //140 (fürs binning)
   mrec.setConstant();
   RooRealVar a0("a0", "a0",0.,-10.,10.);
   RooRealVar a1("a1", "a1",0.,-1,1);
   //RooRealVar a2("a2", "a2",0.,-1,1);
   //RooRealVar a3("a3", "a3",0.,-1,1);

    //RooChebychev bkgModel("bkgModel","Chebychev model",mrec,{a0,a1,a2,a3});
   RooPolynomial bkgModel("bkgModel","Polynomial model",mrec,RooArgList(a0,a1));
   
   //RooHistPdf bkgModel("chebbkgModel","Chebychev model",mrec, dh, 6); //6
   
   // Define side band regions and full range
   mrec.setRange("LEFT",120,123.5);
   mrec.setRange("RIGHT",130,140);                                                                                                                                                        
   mrec.setRange("FULL",120,140);    //signal region 

   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    TFile *mumuFileT = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/source/wzp6_ee_mumuH_ecm240_sel_ZmumuH4_noRVec.root");
    TFile *WWFileT = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/source/p8_ee_WW_ecm240_sel_ZmumuH4_noRVec.root");
    TFile *ZZFileT = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/source/p8_ee_ZZ_ecm240_sel_ZmumuH4_noRVec.root");
    //TFile *ZllFileT = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/source/p8_ee_Zll_ecm240_sel_ZmumuH4_noRVec.root");
    //TFile *ZeeFileT = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/source/wzp6_ee_ee_Mee_30_150_ecm240_sel_ZmumuH4_noRVec.root");
    TFile *ZmumuFileT = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/source/wzp6_ee_mumu_ecm240_sel_ZmumuH4_noRVec.root");
    TFile *ZtautauFileT = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/source/wzp6_ee_tautau_ecm240_sel_ZmumuH4_noRVec.root");
    TFile *gagaFileT = TFile::Open("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/source/wzp6_gaga_mumu_60_ecm240_sel_ZmumuH4_noRVec.root");

    RooFormulaVar wFuncHZ("weight_T1","weight_T","(0.0338215)",mrec) ; // Was ist das? (ist das L*epsilon*CS_LO*BR?)
    //RooRealVar weight_T("weight_T", "weight_T", 0.0338215);
    RooFormulaVar wFuncWW("weight_T2","weight_T","(8.21925)",mrec) ;
    RooFormulaVar wFuncZZ("weight_T3","weight_T","(0.679495)",mrec) ;
    //RooFormulaVar wFuncZll("weight_T4","weight_T","(6.958939394)",mrec) ;
    //RooFormulaVar wFuncZee("weight_T4","weight_T","(0.522984887)",mrec) ;
    RooFormulaVar wFuncZmumu("weight_T4","weight_T","(0.535222672)",mrec) ;
    RooFormulaVar wFuncZtautau("weight_T5","weight_T","(0.470564516)",mrec) ;
    RooFormulaVar wFuncgaga("weight_T6","weight_T","(0.258716667)",mrec) ;
    
    RooDataSet * dataHZ = new RooDataSet("dataHZ","dataHZ", (TTree*)mumuFileT -> Get("MRecT"), RooArgSet(mrec));
    RooRealVar * weight_T = (RooRealVar *)dataHZ->addColumn(wFuncHZ);
    dataHZ -> Print();
    RooDataSet wdataHZ(dataHZ->GetName(), dataHZ->GetTitle(), dataHZ, *dataHZ->get(), 0, weight_T->GetName());
    RooDataSet wdataHZsig("wdataHZsig", "wdataHZsig", dataHZ, *dataHZ->get(), 0, weight_T->GetName());
    wdataHZ.Print();
    cout << wdataHZ.isWeighted() << endl; 

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
    RooDataSet *  dataZmumu = new RooDataSet("dataZmumu","dataZmumu",(TTree*)ZmumuFileT -> Get("MRecT"), RooArgSet(mrec));
    RooRealVar * weight_T4 = (RooRealVar *)dataZmumu->addColumn(wFuncZmumu);
    dataZmumu -> Print();
    RooDataSet wdataZmumu(dataZmumu->GetName(), dataZmumu->GetTitle(), dataZmumu, *dataZmumu->get(), 0, weight_T4->GetName());
    wdataZmumu.Print();
    cout << wdataZmumu.isWeighted() << endl;

    RooDataSet *  dataZtautau = new RooDataSet("dataZtautau","dataZtautau",(TTree*)ZtautauFileT -> Get("MRecT"), RooArgSet(mrec));
    RooRealVar * weight_T5 = (RooRealVar *)dataZtautau->addColumn(wFuncZtautau);
    dataZtautau -> Print();
    RooDataSet wdataZtautau(dataZtautau->GetName(), dataZtautau->GetTitle(), dataZtautau, *dataZtautau->get(), 0, weight_T5->GetName());
    wdataZtautau.Print();
    cout << wdataZtautau.isWeighted() << endl;

    RooDataSet *  datagaga = new RooDataSet("datagaga","datagaga",(TTree*)gagaFileT -> Get("MRecT"), RooArgSet(mrec));
    RooRealVar * weight_T6 = (RooRealVar *)datagaga->addColumn(wFuncgaga);
    datagaga -> Print();
    RooDataSet wdatagaga(datagaga->GetName(), datagaga->GetTitle(), datagaga, *datagaga->get(), 0, weight_T6->GetName());
    wdatagaga.Print();
    cout << wdatagaga.isWeighted() << endl;

    wdataHZ.append(wdataWW);
    wdataHZ.append(wdataZZ);
    //wdataHZ.append(wdataZll);
    //wdataHZ.append(wdataZee);
    wdataHZ.append(wdataZmumu);
    wdataHZ.append(wdataZtautau);
    wdataHZ.append(wdatagaga);

    wdataWW.append(wdataZZ);
    //wdataWW.append(wdataZll);
    //wdataWW.append(wdataZee);
    wdataWW.append(wdataZmumu);
    wdataWW.append(wdataZtautau);
    wdataWW.append(wdatagaga);

    wdataHZ.Print();
    cout << wdataHZ.isWeighted() <<endl;

    wdataWW.Print();
    cout << wdataWW.isWeighted() <<endl;


   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //RooKeysPdf bkgModel("bkgModel","KDE model",mrec,wdataHZ);

  

   //mrec.setBins(70);
   //mrec.setBinning();
   
   //cout << mrec.getBins() << endl;



   RooDataHist dh("dh", "dh", mrec, Import(*hh));

   // Plot data

   TCanvas * c1 = new TCanvas ("c1", "c1", 100, 200, 700, 500);
   c1 -> cd();
   RooPlot * frame =  mrec.frame(Name("Mrecframe"), Title("Data"));
   wdataWW.plotOn(frame,DataError(RooAbsData::SumW2));
   frame->Draw();
   c1->Draw();
   c1->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/aplots/data.pdf");



   // S+ B fit in background region 
   RooRealVar N("N", "Extended term", nbkgMC_240GeV,0,45000);
   //RooRealVar N("N", "Extended term", nbkgMC_240GeV,nbkgMC_240GeV - 5000,nbkgMC_240GeV + 5000);
   
   //Definition of the extended model
   RooExtendPdf extmodel("extmodel", "Extended model", bkgModel, N, "FULL");
   
   TCanvas* c2 = new TCanvas ("c2", "c2", 100, 200, 700, 500);

   c2->cd();

   RooFitResult* r2 = extmodel.fitTo(wdataWW, Range("FULL"),Save(), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit","migrad"), PrintEvalErrors(-1));
   r2->Print();
   RooPlot* frame2 = mrec.frame(Name("m_recoil_frame"), Title("Fit background"), Bins(70));
   wdataWW.plotOn(frame2);
   extmodel.plotOn(frame2,LineColor(kGreen+2));
   // extmodel.plotOn(frame2, VisualizeError(*r2));
   extmodel.paramOn(frame2, Label("Extended B fit. in Bkg region"), Layout(0.1, 1., 0.25));                                                                                
   frame2 -> GetXaxis()->SetRangeUser(120, 140);
   frame2->Draw();
   c2->Draw();
   c2->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/aplots/bkg_only.pdf");   
   a0.setConstant(kTRUE);
   a1.setConstant(kTRUE);
   //a2.setConstant(kTRUE);
   //a3.setConstant(kTRUE); 
   
   //N.setVal(nbkgMC_240GeV);
   N.setConstant(kTRUE);


   // PART 2: S+B model
   // --------------------------------

   TCanvas* c3 = new TCanvas ("c3", "c3", 100, 200, 700, 500);
   c3 -> cd();

   // COM smearing @ 240 GeV
   RooConstVar COMideal_240GeV("COMideal_240GeV", "ideal COM", 240.);
   RooRealVar COMmess_240GeV("COMmess_240GeV", "measured COM energy", 1., 1. - (240*0.0000012), 1. + (240*0.0000012)); //0.00012
   RooGaussian COMsmear_240GeV("COMsmear_240GeV", "COM smearing", RooConst(1.), COMmess_240GeV, RooConst(0.000012)); // 0.0012
   //COMmess_240GeV.setConstant();
   
   // mH smearing @ 240 GeV
   RooRealVar mHmess_240GeV("mHmess_240GeV", "measured Higgs mass", 125., 122., 128.);
   RooGaussian mHsmear_240GeV("mHsmear_240GeV", "Higgs mass smearing", RooConst(125.), mHmess_240GeV, RooConst(0.14));
   RooRealVar mZ("mZ", "mZ", 91.188);
   
   // Luminosity smearing @ 240 GeV
   RooConstVar Lideal_240GeV("Lideal_240GeV", "ideal Luminosity", 5e+06);
   RooRealVar Lmess_240GeV("Lmess_240GeV", "Luminosity measured", 1., 1. - (10*0.001), 1. + (10*0.001)); // 4e+06, 6e+06
   RooGaussian Lsmear_240GeV("Lsmear_240GeV", "Luminosity smearing", RooConst(1.), Lmess_240GeV, RooConst(0.001));
   RooProduct varL_240GeV("varL_240GeV", "varL_240GeV", RooArgSet(Lmess_240GeV, Lideal_240GeV));
   //Lmess_240GeV.setConstant();
   
   // Efficiency smearing @ 240 GeV
   RooConstVar Eideal_240GeV("Eideal_240GeV", "ideal Efficiency", 0.464897);
   RooRealVar Emess_240GeV("Emess_240GeV", "Efficiency_mess", 1., 1. - (30*0.001), 1. + (30*0.001)); //6e-03, 7e-03
   RooGaussian Esmear_240GeV("Esmear_240GeV", "Efficiency smearing", RooConst(1.), Emess_240GeV, RooConst(0.01));
   RooProduct varE_240GeV("varE_240GeV", "varE_240GeV", RooArgSet(Emess_240GeV, Eideal_240GeV));
   //Emess_240GeV.setConstant();
   
   // BR smearing @ 240 GeV
   RooConstVar BRideal_240GeV("BRideal_240GeV","BRideal_240GeV",1.); //??? 0.0336
   RooRealVar BRmess_240GeV("BRmess_240GeV", "BR_mess", 1., 1. - 20*(0.002), 1. + 20*(0.002)); // 0.2, 1.5
   RooGaussian BRsmear_240GeV("BRsmear_240GeV", "BR smearing", RooConst(1.), BRmess_240GeV, RooConst(0.002));
   RooProduct varBR_240GeV("varBR_240GeV", "varBR_240GeV", RooArgSet(BRmess_240GeV, BRideal_240GeV));
   //BRmess_240GeV.setConstant();
   
   // Kappa Lambda @ 240 GeV
   RooRealVar varKappaideal_240GeV("varKappaideal_240GeV", "Kappa_ideal", 0.); //0., -10, 15.
   RooConstVar varKappasigma_240GeV("varKappasigma_240GeV", "Kappa_sigma", 10.); //1e-03
   RooRealVar varKappa_240GeV("varKappa_240GeV", "kappa variation", 0., -20, 20); //-20, 20.
   RooRealVar varKappaHZZ_240GeV("varKappaHZZ_240GeV", "kappa HZZ variation", 0.); //0., -2., 2.
   
   RooGaussian varKappasmear_240GeV("varKappasmear_240GeV", "varKappa smearing", varKappaideal_240GeV, varKappa_240GeV, varKappasigma_240GeV);

   // Fit a Crystalball pdf to the data
   
   RooFormulaVar mean_240GeV("mean", "sqrt((( @0)^2)*@2  + ((@3)^2) + ((@1)^2) - (@2)*((@3)^2 + ((@1)^2)/((@2)^2)))", RooArgSet(mHmess_240GeV,COMideal_240GeV,COMmess_240GeV,mZ));
   RooRealVar sigma_240GeV("sigma", "sigma", 0.5, 0.1, 2);
   RooRealVar alphaL_240GeV("alphaL", "alphaL", 1., -1, 10);
   RooRealVar alphaR_240GeV("alphaR", "alphaR", 1., -1, 10);
   RooRealVar NL_240GeV("NL", "NL", 3., 0.1, 10.); //4.6, 0.1, 20
   RooRealVar NR_240GeV("NR", "NR", 3., 0.1, 10.);
   
   RooRealVar mean2_240GeV("mean2_240GeV", "mean2", 125, 123, 127);
   RooRealVar sigma2_240GeV("sigma2_240GeV", "sigma2", 0.8, 0.1, 2);
   RooGaussian gauss_240GeV("gauss_240GeV", "Gaussian", mrec, mean2_240GeV, sigma2_240GeV);
   RooRealVar fsig("fsig", "signal fraction", 0.4, 0.1, 0.7);
   RooRealVar fsig2("fsig2", "signal fraction 2", 0.4, 0.1, 0.7);

   RooCrystalBall CB1sig_240GeV("CB1sig_240GeV", "CB Signal 1", mrec, mean_240GeV, sigma_240GeV, alphaL_240GeV, NL_240GeV, false);
   RooCrystalBall CB2sig_240GeV("CB2sig_240GeV", "CB Signal 2", mrec, mean_240GeV, sigma_240GeV, alphaR_240GeV, NR_240GeV, false);

   RooAddPdf sig_240GeV("finalsig", "final signal", RooArgList(CB1sig_240GeV, CB2sig_240GeV, gauss_240GeV), RooArgList(fsig, fsig2), true);

   
   // NLO CS @ 240 GeV
   RooConstVar CSTrue_240GeV("CSTrue_240GeV", "CS_True", 0.0067643); // in pb 0.0067643
   RooConstVar CSLO_240GeV("CSLO_240GeV", "CS_LO", 0.006661316053808128); // in pb 0.006661471998033432 approx. CSTrue_240GeV / (1 + C1 + dZh)
   RooConstVar C1_240GeV("C1_240GeV", "C1", 0.017); //0.015
   RooConstVar dZh_240GeV("dZh_240GeV", "deltanZh parameter", -0.00154);
   
   //RooRealVar CSHZTrue_240GeV("CSHZTrue_240GeV", "CS HZ true", 0.9, 0.5, 1.1); //0.9, 0.5, 1.1
   
   RooFormulaVar CSNLO_240GeV("CSNLO_240GeV", "((1./(1.-(@2)*(@3+1.)^2))*(@0)*(1. + (@1)*(@3+1.)))", RooArgSet(CSLO_240GeV, C1_240GeV, dZh_240GeV, varKappa_240GeV)); 
   
   // C o n s t r u c t   e x t e n d e d   c o m p o s i t e   m o d e l
   // -------------------------------------------------------------------
   
   // Sum the composite signal and background into an extended pdf nsig*sig+nbkg*bkg
   RooRealVar nsig_240GeV("nsig", "number of signal events", nsigMC_240GeV, 0., 50000); //nsigMC_240GeV
   
   RooRealVar nsigTrue_240GeV("nsigTrue", "number of MC signal events", nsigMC_240GeV); //nsigMC_240GeV
   nsigTrue_240GeV.setError(error_nsigMC_240GeV); //error_nsigMC_240GeV
   RooRealVar nbkg_240GeV("nbkg_240GeV", "number of background events", nbkgMC_240GeV); //nbkgMC_240GeV
   nbkg_240GeV.setError(error_nbkgMC_240GeV); //error_nbkgMC_240GeV
   
   // Extract kappa
   //RooProduct muZHsig_240GeV("muZHsig_240GeV", "muZHsig_240GeV", RooArgSet(CSNLO_240GeV, varL_240GeV, varE_240GeV, varBR_240GeV));
   
   //Extract muZH
   RooRealVar muZH_240GeV("muZH_240GeV", "muZH_240GeV", 1., 0.5, 1.5); 
   RooProduct muZHsig_240GeV("muZHsig", "muZH_240GeV * varL_240GeV * varE_240GeV * (CSTrue_240GeV * BRideal_240GeV)", RooArgList(muZH_240GeV, varL_240GeV, varE_240GeV, CSTrue_240GeV, BRideal_240GeV));

   //RooProduct muZHsig_240GeV("muZHsig", "muZH_240GeV * nsigTrue_240GeV", RooArgList(muZH_240GeV, nsigTrue_240GeV));

   
   RooAddPdf modelBare_240GeV("modelBare", "(g1+g2)+a", RooArgList(bkgModel, sig_240GeV), RooArgList(N, muZHsig_240GeV));
   
   
   //RooProdPdf model_240GeV("model", "Final model", RooArgList(modelBare_240GeV, Lsmear_240GeV, Esmear_240GeV, mHsmear_240GeV, COMsmear_240GeV, BRsmear_240GeV, varKappasmear_240GeV));
   RooProdPdf model_240GeV("model", "Final model", RooArgList(modelBare_240GeV, Lsmear_240GeV, Esmear_240GeV, mHsmear_240GeV, COMsmear_240GeV, BRsmear_240GeV));
   modelBare_240GeV.fixCoefNormalization(mrec);
   sig_240GeV.fixCoefNormalization(mrec);


   //N.setVal(0.);

   // Save snapshot of prefit parameters
   RooArgSet *params = model_240GeV.getParameters(mrec);
   RooArgSet *initParams = (RooArgSet *)params->snapshot();

   //RooFitResult* r3 = model_240GeV.fitTo(dh, Range("FULL"),Save(), Extended(kTRUE), Offset(kTRUE), Constrain(RooArgSet(Lsmear_240GeV, Esmear_240GeV, COMsmear_240GeV, BRsmear_240GeV)));
   //RooFitResult* r3 = model_240GeV.fitTo(dh, Range("FULL"),Save(), Extended(kTRUE), Offset(kTRUE), ExternalConstraints( RooArgSet(mHsmear_240GeV,varKappasmear_240GeV)));
   
   RooFitResult* r3 = model_240GeV.fitTo(wdataHZ,Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(Lsmear_240GeV, Esmear_240GeV, BRsmear_240GeV, COMsmear_240GeV, mHsmear_240GeV)), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit","migradimproved"), GlobalObservables(RooArgSet(Lmess_240GeV, Emess_240GeV, COMmess_240GeV, BRmess_240GeV)), Strategy(2));
   //RooFitResult* r3 = model_240GeV.fitTo(wdataHZsig,Save(), Extended(kTRUE), PrintEvalErrors(-1), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit","migrad"), GlobalObservables(RooArgSet(Lmess_240GeV, Emess_240GeV, COMmess_240GeV, BRmess_240GeV)), Strategy(2));
   
   //RooFitResult* r3 = model_240GeV.fitTo(dh, Range("FULL"),Save(), Extended(kTRUE), ExternalConstraints( RooArgSet( mHsmear_240GeV)), IntegrateBins(0.));

   r3->Print();

   //RooFitResult* r3 = model_240GeV.fitTo(dh, Range("FULL"),Save(), ExternalConstraints( RooArgSet(mHsmear_240GeV,varKappasmear_240GeV)));
   
   RooPlot* frame3 = mrec.frame(Name("Mrecframe"), Title("S+B fit"), Bins(70));
   frame3 -> GetXaxis() ->SetRangeUser(120., 139.5); 
   wdataHZ.plotOn(frame3,DataError(RooAbsData::SumW2), Bins(70));
   model_240GeV.plotOn(frame3, LineColor(kAzure-2), Bins(70));       //modelsum.
   //modelsum.plotOn(frame3,VisualizeError(*r3));
   //modelsum.plotOn(frame3,VisualizeError(*r3, 2, kFALSE),FillColor(kOrange)); 
   model_240GeV.plotOn(frame3,Components(bkgModel), LineColor(kGreen+2),LineStyle(kDashed),Name("Bkg only") , Bins(70));
   model_240GeV.plotOn(frame3,Components(sig_240GeV), LineColor(kRed-4),LineStyle(kDotted),  Name("Sgn Comp1 only") , Bins(70));
   model_240GeV.plotOn(frame3,Components(gauss_240GeV), LineColor(kGreen-2),LineStyle(kDashDotted), Name("Sgn Gauss only") );
   model_240GeV.plotOn(frame3,Components(CB2sig_240GeV), LineColor(kOrange-4),LineStyle(kDashed), Name("Sgn CB2 only") );
   //model_240GeV.plotOn(frame3,Components(sig2), LineColor(kViolet-4),LineStyle(kDashDotted), Name("Sgn Comp2 only") );
   
   // model_240GeV.paramOn(frame3, Label("S+B fit"));     //modelsum
   frame3->Draw();
   
   c3->Draw();
   c3->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/aplots/S_B_fit.pdf");

   
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
   params->printLatex(Sibling(*initParams), OutputFile("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/aplots/latextables.tex"));
   
   RooPlot* frame30 = mrec.frame(Name("Mrecframe"), Title("S+B fit"));  
   wdataHZ.plotOn(frame30,DataError(RooAbsData::SumW2));
   model_240GeV.plotOn(frame30, LineColor(kAzure-2));

   cout << "Background-only chi^2 = " << frame2 -> chiSquare(2) << endl;
   cout << "S+B chi^2 = " << frame3 -> chiSquare(10) << endl;
   
   

   
   /*

   // V i s u a l i z e   c o r r e l a t i o n   m a t r i x
   // -------------------------------------------------------
   
   // Construct 2D color plot of correlation matrix
   gStyle->SetOptStat(0);
   TH2 *hcorr = r3->correlationHist();
   
   // Visualize ellipse corresponding to single correlation matrix element
   RooPlot *framecorr = new RooPlot(mHmess_240GeV, varKappa_240GeV , 124.8, 125.2, -1.2, 0.5);
   framecorr->SetTitle("Covariance between mH and x_sec_norm");
   r3->plotOn(framecorr, mHmess_240GeV,  varKappa_240GeV , "ME12ABHV");
   
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
   ccorr->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/aplots/corr.eps"); 

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
 RooPlot *frame31 = mrec.frame(Title("Residual Distribution"));
 frame31->addPlotable(hresid, "P");
 
 // Create a new frame to draw the pull distribution and add the distribution to the frame
 RooPlot *frame32 = mrec.frame(Title("Pull Distribution"));
 frame32->addPlotable(hpull, "P");
 RooPlot *frame32b = mrec.frame(Title("Pulls"));
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
 c31->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/aplots/pulls_resid.pdf");

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
 c->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/aplots/Fit_pulls.pdf");

 cout << mean_240GeV.getVal() << endl;

 RooWorkspace *w = new RooWorkspace("w", "workspace");

 w->import(model_240GeV);

 //w->import(wFuncHZ);
 //w->import(wFuncWW);
 //w->import(wFuncZZ);
 //w->import(wFuncZll);
 //w->import(wFuncgaga);
 w->import(*weight_T);
 
 w->defineSet("poi", "muZH_240GeV");
 //w->defineSet("poi", "varKappa_240GeV");
 w->defineSet("np", RooArgSet(sigma_240GeV, alphaL_240GeV, alphaR_240GeV, NL_240GeV, NR_240GeV, mean2_240GeV, sigma2_240GeV, fsig, fsig2, N, mHmess_240GeV), kTRUE);
 w->defineSet("glob", RooArgSet(Lmess_240GeV, Emess_240GeV, BRmess_240GeV, COMmess_240GeV), kTRUE);
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

 w->var("muZH_240GeV")->setVal(1);
 mc.SetSnapshot(*(w->var("muZH_240GeV")));

 //w->var("varKappa_240GeV")->setVal(0);
 //mc.SetSnapshot(*(w->var("varKappa_240GeV")));

 mc.Print();

 w->import(mc);

 RooArgSet combSet = RooArgSet(poiSet, nuisSet, "combSet");

 

 const RooArgSet * genPoiValues = 0;

 //RooAbsData * asimov = RooStats::AsymptoticCalculator::MakeAsimovData(wdataHZ, mc, poiSet, globSet, genPoiValues);
 RooAbsData * asimov = RooStats::AsymptoticCalculator::MakeAsimovData(mc, combSet, globSet);

 RooFitResult * r4 =  w->pdf("model")->fitTo(*asimov,Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(Lsmear_240GeV, Esmear_240GeV, COMsmear_240GeV, mHsmear_240GeV, BRsmear_240GeV)), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit2","migrad"), GlobalObservables(globSet), Strategy(2));

 r4->Print();

 std::cout << "Asimov designed for mu = 1 gave mu-hat = " << w->var("muZH_240GeV")->getVal() << std::endl;

   // Plot Asimov

   TCanvas * c7 = new TCanvas ("c1", "c1", 100, 200, 700, 500);
   c7 -> cd();
   RooPlot * frame7 =  mrec.frame(Name("Mrecframe"), Title("Data"));
   asimov->plotOn(frame7,DataError(RooAbsData::SumW2));
   frame7->Draw();
   c7->Draw();
   c7->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/aplots/adata.pdf");

  w->import(*asimov, Rename("mumuH_Asimov"));

  RooArgSet *asimov_parameters = (RooArgSet*)w->pdf("model")->getParameters(mrec);
  w->saveSnapshot("mumuH_asimovFit", *asimov_parameters, kTRUE);

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////// N O   S Y S T E M A T I C S ///////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  BRmess_240GeV.setVal(1);
  Emess_240GeV.setVal(1);
  Lmess_240GeV.setVal(1);
  COMmess_240GeV.setVal(1);
  mHmess_240GeV.setVal(1);

  BRmess_240GeV.setConstant(kTRUE);
  Emess_240GeV.setConstant(kTRUE);
  Lmess_240GeV.setConstant(kTRUE);
  COMmess_240GeV.setConstant(kTRUE);
  mHmess_240GeV.setConstant(kTRUE);

  RooFitResult* r5 = modelBare_240GeV.fitTo(wdataHZ,Save(), Extended(kTRUE), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit2","migrad"), Strategy(2));
   
  r5->Print();

  w->import(modelBare_240GeV);

  RooStats::ModelConfig mcB(w);
  mcB.SetPdf("modelBare");
  mcB.SetObservables(*(w->set("obs")));
  mcB.SetParametersOfInterest(poiSet);
  mcB.SetNuisanceParameters(nuisSet);


  w->var("muZH_240GeV")->setVal(1);
  mcB.SetSnapshot(*(w->var("muZH_240GeV")));

  w->import(mcB);
  RooArgSet genObs;

  RooAbsData * asimov_bare = RooStats::AsymptoticCalculator::MakeAsimovData(wdataHZ, mcB, poiSet, genObs, genPoiValues);

  RooFitResult * r6 = w->pdf("modelBare")->fitTo(*asimov_bare,Save(), Extended(kTRUE), Offset(kTRUE), NumCPU(8, 0), Minimizer("Minuit2","migrad"), Strategy(2));

  std::cout << "Asimov designed for mu = 1 gave mu-hat = " << w->var("muZH_240GeV")->getVal() << std::endl;

  r6->Print();

  w->import(*asimov_bare, Rename("mumuH_Asimov_bare"));

  RooArgSet *asimov_parameters_bare = (RooArgSet*)w->pdf("modelBare")->getParameters(mrec);
  w->saveSnapshot("mumuH_asimovFit_bare", *asimov_parameters_bare, kTRUE);



  BRmess_240GeV.setConstant(kFALSE);
  Emess_240GeV.setConstant(kFALSE);
  Lmess_240GeV.setConstant(kFALSE);
  COMmess_240GeV.setConstant(kFALSE);
  mHmess_240GeV.setConstant(kFALSE);
   
  
  w->writeToFile("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/ZmumuH240_muZH.root");

/*



 // PART 3:  Likelihood scan                                                                                                                                                                                  
 // ----------------------------                                                                                                                                                                                  
 
 // C o n s t r u c t   p l a i n   l i k e l i h o o d
 // ---------------------------------------------------
 
 TCanvas* c6 = new TCanvas ("c6", "c6", 100, 200, 700, 500);
 TCanvas* c4 = new TCanvas ("c4", "c4", 100, 200, 700, 500);
 TCanvas* c5 = new TCanvas ("c5", "c5", 100, 200, 700, 500);

  
  //sigma_240GeV.setConstant(kTRUE);
   //alphaL_240GeV.setConstant(kTRUE);
   //alphaR_240GeV.setConstant(kTRUE);
   //NL_240GeV.setConstant(kTRUE);
   //NR_240GeV.setConstant(kTRUE);
   //mean2_240GeV.setConstant(kTRUE);
   //sigma2_240GeV.setConstant(kTRUE);


 // Construct unbinned likelihood
 //RooAbsReal * nll = model_240GeV.createNLL(dh, Extended(kTRUE), Offset(kTRUE));
 //RooAbsReal * nll = model_240GeV.createNLL(dh, Extended(kTRUE), ExternalConstraints( RooArgSet( mHsmear_240GeV,varKappasmear_240GeV)));
 
 

 //RooAbsReal * nll = model_240GeV.createNLL(dh, Extended(kTRUE), ExternalConstraints( RooArgSet( mHsmear_240GeV,varKappasmear_240GeV)), IntegrateBins(0.));
 //RooAbsReal * nll = model_240GeV.createNLL(dh, Extended(kTRUE), ExternalConstraints( RooArgSet( mHsmear_240GeV)), IntegrateBins(0.)); //Best Result
 //RooAbsReal * nll = model_240GeV.createNLL(wdataHZ, NumCPU(3)); //Best Result
 //RooAbsReal * nll = model_240GeV.createNLL(dh, Extended(kTRUE), ExternalConstraints( RooArgSet( mHsmear_240GeV)));

 //RooAbsReal * nll = model_240GeV.createNLL(*asimov, Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(Lsmear_240GeV, Esmear_240GeV, COMsmear_240GeV)), Offset(kTRUE), NumCPU(8, 0)); 
 RooAbsReal * nll = model_240GeV.createNLL(*asimov, Save(), Extended(kTRUE), ExternalConstraints(RooArgSet(Lsmear_240GeV, Esmear_240GeV, COMsmear_240GeV, BRsmear_240GeV)), Offset(kTRUE), NumCPU(8, 0)); 

 
 //RooAbsReal * nll = model_240GeV.createNLL(dh);
 // RooAbsReal * nllunc = modelsum_stat.createNLL(wdataHZ,ExternalConstraints( RooArgSet( mH_subs,kl_subs)) , NumCPU(2));

 // Minimize likelihood w.r.t all parameters before making aplots
 RooMinimizer minim(*nll);
 minim.minimize("Minuit2");
   minim.migrad();

 
   
   //RooMinimizer(*nllunc).migrad();
 
 // Plot likelihood scan in Nsig
  RooPlot *frame4 = varKappa_240GeV.frame(Range(-20., 20.), Title("NLL in #delta#kappa_{#lambda} "));
  // RooPlot *frame4 = fsig.frame(Bins(20), Range(0.2, 0.6), Title("NLL in f_{sig}"));
   frame4 -> GetXaxis() ->SetRangeUser(-20, +20.);
   
   nll->plotOn(frame4,LineColor(kAzure-2), ShiftToZero());

    cout << CSNLO_240GeV.getVal() << endl;

  */

/*

// C o n s t r u c t   p r o f i l e   l i k e l i h o o d   i n   m u  Z H
 // -----------------------------------------------------------------------
 
 // The profile likelihood estimator on nll for Nsig will minimize nll w.r.t
 // all floating parameters except Nsig for each evaluation

 // Plot likelihood scan in Nsig
  RooPlot *frame6 = muZH_240GeV.frame(Range(0.7, 1.2), Title("NLL in #mu_{ZH} "));
  // RooPlot *frame4 = fsig.frame(Bins(20), Range(0.2, 0.6), Title("NLL in f_{sig}"));
   frame6 -> GetXaxis() ->SetRangeUser(0.7, 1.2);
   
   nll->plotOn(frame6,LineColor(kAzure-2), ShiftToZero());
 
 RooAbsReal *pll_muZH = nll->createProfile(muZH_240GeV);
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
 c6->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/aplots/NLL_prf_muZH.pdf");

 wdataHZ.Print();
 hh->Print();
 cout << hh->GetNbinsX();
 
 */
 
 /*
 
 
 // C o n s t r u c t   p r o f i l e   l i k e l i h o o d   i n   k l
 // -----------------------------------------------------------------------
 
 // The profile likelihood estimator on nll for Nsig will minimize nll w.r.t
 // all floating parameters except Nsig for each evaluation
 
 RooAbsReal *pll_kl = nll->createProfile(varKappa_240GeV);
 // RooAbsReal * pll_kl_unc = nllunc->createProfile(delta_kl);

 //RooAbsReal *pll_fsig = nll->createProfile( fsig);
 c4 -> cd();
 // Plot the profile likelihood in frac
 pll_kl -> plotOn(frame4, LineColor(kRed),LineStyle(kSolid));
 // pll_kl_unc -> plotOn(frame4, LineColor(kAzure-4),LineStyle(kDashDotted));
 // pll_fsig->plotOn(frame4, LineColor(kAzure-2),LineStyle(kDashed));
 frame4->GetYaxis()->SetTitleOffset(1.4);
 frame4->SetMinimum(-3.);
 frame4->SetMaximum(20.);
 frame4->Draw(); 
 c4->Draw(); 
 c4->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/aplots/NLL_prf_kl.pdf");

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
 c5->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/aplots/NLL_prf_mh.eps");
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
 
 model_240GeV.getParameters( mrec)->Print("s");
 
 // Disable verbose logging
 m.setVerbose(kFALSE);
 
 // Run HESSE to calculate errors from d2L/dp2
 m.hesse();
 
 // Print value (and error) of sigma_g2 parameter, that reflects
 // value and error back propagated from MINUIT
 varKappa_240GeV.Print();      //Nsig
 mHmess_240GeV.Print();
 
 // Run MINOS 
 m.minos();
 
 // Print value (and error) of sigma_g2 parameter, that reflects
 // value and error back propagated from MINUIT
 varKappa_240GeV.Print();     //Nsig
 mHmess_240GeV.Print();

 RooFitResult *r4 = m.save(); 

 
 // Make contour plot of mx vs sx at 1,2,3 sigma

 // RooPlot *frame6 = m.contour(delta_kl, mH, TMath::Sqrt( ROOT::Math::chisquared_quantile(0.68,2) ),TMath::Sqrt( ROOT::Math::chisquared_quantile(0.95,2) ) );    //Nsig
  RooPlot *frame6 = m.contour(varKappa_240GeV, mHmess_240GeV, 1,2 );    //Nsig 
 
 frame6->SetTitle("Minuit contour");
 
 TCanvas* c6 = new TCanvas ("c6", "c6", 100, 200, 700, 500);
 c6 -> cd(); 
 gPad->SetLeftMargin(0.15);
 frame6->GetYaxis()->SetTitleOffset(1.8);
 
 frame6 -> GetXaxis() ->SetRangeUser(-7., 7.);
 frame6 -> GetYaxis() ->SetRangeUser(124., 126.); 

 frame6->Draw();
 c6->Draw();
 c6->SaveAs("/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/mumuH/aplots/contour_kl_mH.pdf");

*/

//delete pll_kl;
 // delete pll_kl_unc;
//delete nll;
 // delete nllunc;
 // delete pll_mh;
 // delete pll_mh_unc;






}
