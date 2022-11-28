#python examples/FCCee/higgs/mH-recoil/mumu/finalSel.py 

from config.common_defaults import deffccdicts

import sys, os
import ROOT

###Input directory where the files produced at the pre-selection level are
baseDir  = "/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/presel/"

###Link to the dictonary that contains all the cross section informations etc...
procDict = os.path.join(os.getenv('FCCDICTSDIR', deffccdicts), '') + "FCCee_procDict_spring2021_IDEA.json"
#procDict = "/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/auxiliaryFiles/normalization1.json" #Crosssection is 1; damit wir cuts setzen knnen


process_list=['wzp6_ee_qqH_ecm365', 'p8_ee_WW_ecm365','p8_ee_ZZ_ecm365','p8_ee_Zqq_ecm365']
#process_list=['wzp6_ee_qqH_ecm365']
#process_list=['p8_ee_WW_ecm365','p8_ee_ZZ_ecm365']


#muss mit wahr/falsch antworten; std::size_t is the unsigned integer type of the result of the sizeof operator as well as the sizeof... operator and the alignof operator (since C++11).
#mass.at(i) gibt masse von beiden Z's zuruck
#myFilter betrachtet 2 Z mit masse zwischen 80 und 100
ROOT.gInterpreter.Declare("""
bool myFilter(ROOT::VecOps::RVec<float> mass) {
    if (mass.size()<2) return false;
    for (size_t i = 0; i < mass.size(); ++i) {
       if (mass.at(i)<80. || mass.at(i)>100.)
        return false;
}
    return true;
}
""")

###Dictionnay of the list of cuts. The key is the name of the selection that will be added to the output file
cut_list = {

            "sel0":"true",

            "sel_noBDT_bbH":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96",

            "sel_bbH":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT_bb > 0.1651",


            #"sel_noBDT_bbHSpecial":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96",

            #"sel_bbHSpecial":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT_bb > 0.4",

            #"sel_noBDT_bbHSpecial2":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96",

            "sel_noBDT_bbHSpecial":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30",


            #"sel_noBDT_bbH1":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96",


            #"sel_noBDT_bbH2":"zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96",

            "sel_noBDT_bjH":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && ((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96",

            "sel_bjH":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && ((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT_bj > 0.1277",
            
            "sel_bjH1":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && ((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && zed_hadronic_subjets_acollPaPb[0] < 2 && _FinalClassifier_BDT_bj > 0.1277",

            "sel_bjH2":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && ((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && zed_hadronic_subjets_acollPaPb[0] < 2 && _FinalClassifier_BDT_bj > 0.2077",



            "sel_noBDT_bcH":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && ((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && ((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96",

            "sel_bcH":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && ((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && ((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT_bc > -0.0627",
            
            "sel_bcH1":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && ((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && ((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && bjetNo[0] > 0 && _FinalClassifier_BDT_bc > -0.0627",

            "sel_bcH2":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && ((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && ((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && bjetNo[0] > 0 && zed_hadronic_subjets_acollPaPb[0] < 2 && _FinalClassifier_BDT_bc > -0.0627",

            "sel_bcH3":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && ((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && ((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && bjetNo[0] > 0 && zed_hadronic_subjets_acollPaPb[0] < 2 && _FinalClassifier_BDT_bc > 0.10",




            "sel_noBDT_ccH":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && (zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96",

            "sel_ccH":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && (zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT_cc > 0.0962",

            "sel_ccH1":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && (zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98 && _FinalClassifier_BDT_cc > 0.0962",

            "sel_ccH2":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && (zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98 && _FinalClassifier_BDT_cc > 0.3",



            "sel_noBDT_cjH":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && ((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96",

            "sel_cjH":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && ((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT_cj > 0.2640",
            
            "sel_cjH1":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && ((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98 && _FinalClassifier_BDT_cj > 0.2640",

            "sel_cjH2":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && ((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98 && zed_hadronic_subjets_acollPaPb[0] < 2 && _FinalClassifier_BDT_cj > 0.2640",



            "sel_noBDT_ijH":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96",

            "sel_ijH":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT_ij > 0.2247",

            "sel_ijH1":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98 && _FinalClassifier_BDT_ij > 0.2247",

            "sel_ijH2":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_hadronic_subjets_btag.size() > 1 && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && TMath::Abs(zed_hadronic_m[0] - 125.) > 30 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98 && zed_hadronic_subjets_acollPaPb[0] < 2 && _FinalClassifier_BDT_ij > 0.2247",

            
            
            
            }


###Dictionary for the ouput variable/hitograms. The key is the name of the variable in the output files. "name" is the name of the variable in the input file, "title" is the x-axis label of the histogram, "bin" the number of bins of the histogram, "xmin" the minimum x-axis value and "xmax" the maximum x-axis value.
variables = {
    #"btag":{"name":"JET_btag", "title":"btag", "bin":2, "xmin":0, "xmax":3},
    #"ctag":{"name":"jets_kt_ctag", "title":"ctag", "bin":2, "xmin":0, "xmax":2},
    #"m_ij":{"name":"jets_kt_m", "title":"m_ij", "bin":100, "xmin":20, "xmax":180},
    #"pT_b":{"name":"selected_bjets_pt", "title":"pT_b", "bin":100, "xmin":20, "xmax":180},
    #"m_b":{"name":"selected_bjets_m", "title":"pT_b", "bin":100, "xmin":20, "xmax":180}
    "m_rec":{"name":"zed_hadronic_recoil_m","title":"m_{Rec} [GeV]","bin":50,"xmin":100,"xmax":160},
    "m_rec2":{"name":"zed_hadronic_recoil_m","title":"m_{Rec} [GeV]","bin":60,"xmin":100,"xmax":250},
    #"mz_zoom":{"name":"zed_hadronic_m","title":"m_{Z} [GeV]","bin":20,"xmin":80,"xmax":100},
    #"z_pt":{"name":"zed_hadronic_pt","title":"pT_{Z} [GeV]", "bin":100, "xmin":60, "xmax":120},
    "jet_ht":{"name":"jet_ht","title":"HT_{i} [GeV]", "bin":150, "xmin":0, "xmax":300},
    "htheta":{"name":"zed_hadronic_theta","title":"#theta_{ij}", "bin":100, "xmin":0, "xmax":3.2},
    "hrtheta":{"name":"zed_hadronic_recoil_theta","title":"#theta_{Rec}", "bin":100, "xmin":0, "xmax":4},
    "pT1":{"name":"zed_hadronic_subjets_pt1","title":"p_{T1} [GeV]","bin":125,"xmin":0,"xmax":200},
    "pT2":{"name":"zed_hadronic_subjets_pt2","title":"p_{T2} [GeV]","bin":125,"xmin":0,"xmax":200},
    "pL1":{"name":"zed_hadronic_subjets_pl1","title":"p_{L1} [GeV]","bin":125,"xmin":-200,"xmax":200},
    "pL2":{"name":"zed_hadronic_subjets_pl2","title":"p_{L2} [GeV]","bin":125,"xmin":-200,"xmax":200},
    "E1":{"name":"zed_hadronic_subjets_E1","title":"E_{j1} [GeV]","bin":125,"xmin":0,"xmax":200},
    "E2":{"name":"zed_hadronic_subjets_E2","title":"E_{j2} [GeV]","bin":125,"xmin":0,"xmax":200},
    "Eta1":{"name":"zed_hadronic_subjets_Eta1","title":"Eta_{1}","bin":125,"xmin":-5,"xmax":5},
    "Eta2":{"name":"zed_hadronic_subjets_Eta2","title":"Eta_{2}","bin":125,"xmin":-5,"xmax":5},
    "pT_ij":{"name":"zed_hadronic_pt","title":"p_{Tij} [GeV]","bin":125,"xmin":0,"xmax":200},
    "pT_Rec":{"name":"zed_hadronic_recoil_pt","title":"p_{TRec} [GeV]","bin":125,"xmin":0,"xmax":200},
    "pL_ij":{"name":"zed_hadronic_pl","title":"p_{Lij} [GeV]","bin":125,"xmin":0,"xmax":200},
    "M_ij":{"name":"zed_hadronic_m","title":"M_{ij} [GeV]","bin":70,"xmin":86,"xmax":96},
    "Acoll_ij":{"name":"zed_hadronic_subjets_acoll","title":"Acoll_{ij}","bin":125,"xmin":-4,"xmax":4},
    "Acoll_PaPb":{"name":"zed_hadronic_subjets_acollPaPb","title":"Acoll_{ij}","bin":125,"xmin":0,"xmax":4},
    "Jet_No":{"name":"jetNo","title":"N_{jets}","bin":125,"xmin":0,"xmax":15},
    "bJet_No":{"name":"bjetNo","title":"N_{bjets}","bin":125,"xmin":0,"xmax":10},
    "cJet_No":{"name":"cjetNo","title":"N_{cjets}","bin":125,"xmin":0,"xmax":10},
    "zed_bJet_No":{"name":"zed_hadronic_subjets_btag","title":"N_{Zbjets}","bin":125,"xmin":0,"xmax":15},
    "zed_cJet_No":{"name":"zed_hadronic_subjets_ctag","title":"N_{Zcjets}","bin":125,"xmin":0,"xmax":15},
    "zed_lJet_No":{"name":"zed_hadronic_subjets_ltag","title":"N_{Zljets}","bin":125,"xmin":0,"xmax":15},
    "MET":{"name":"missingET_e","title":"MET [GeV]","bin":125,"xmin":0,"xmax":200},
    "MET_Angle":{"name":"missingET_costheta","title":"cos(#theta_{Miss})","bin":125,"xmin":-1,"xmax":1},
    "pL_ij":{"name":"zed_hadronic_pl","title":"p_{Lij} [GeV]","bin":125,"xmin":-200,"xmax":200},
    "pL_Rec":{"name":"zed_hadronic_recoil_pl","title":"p_{LRec} [GeV]","bin":125,"xmin":0,"xmax":200},
    "DeltaEta_ij":{"name":"zed_hadronic_subjets_DeltaEta","title":"#Delta #Eta_{ij}","bin":125,"xmin":0,"xmax":10},
    "DeltaPhi_ij":{"name":"zed_hadronic_subjets_DeltaPhi","title":"#Delta #Phi_{ij}","bin":125,"xmin":-10,"xmax":10},
    "NNue":{"name":"number_of_nues","title":"N_{#nu_e}","bin":10,"xmin":0,"xmax":9},
    "NNumu":{"name":"number_of_numus","title":"N_{#nu_#mu}","bin":10,"xmin":0,"xmax":9},
    "NNutau":{"name":"number_of_nutaus","title":"N_{#nu_#tau}","bin":10,"xmin":0,"xmax":9},
    "HTheta":{"name":"MCHiggs2_Theta","title":"#theta","bin":50,"xmin":0,"xmax":4},
    #"M_ee":{"name":"mass_ee","title":"M_{ee} [GeV]","bin":125,"xmin":0,"xmax":350},
    #"M_Zee":{"name":"mass_Zee","title":"M_{ee} [GeV]","bin":125,"xmin":0,"xmax":350},
    #"n_znue":{"name":"n_znue","title":"N_{nuE}","bin":10,"xmin":0,"xmax":9},
    #"n_znuebar":{"name":"n_znuebar","title":"N_{nuE}","bin":10,"xmin":0,"xmax":9},
    #"n_zedsub_nue":{"name":"n_zedsub_nue","title":"N_{nuE}","bin":10,"xmin":0,"xmax":9},
    #"ne_corrected":{"name":"ne_corrected","title":"N_{#nu_#tau}","bin":100,"xmin":0,"xmax":90},
    #"ne_corrected2":{"name":"ne_corrected2","title":"N_{#nu_#tau}","bin":100,"xmin":0,"xmax":9},
    #"ne_corrected3":{"name":"ne_corrected3","title":"N_{#nu_#tau}","bin":100,"xmin":0,"xmax":9},
    #"ne_corrected4":{"name":"ne_corrected4","title":"N_{#nu_#tau}","bin":100,"xmin":0,"xmax":9}
    #"FinalClassifier_BDT":{"name":"FinalClassifier_BDT","title":"BDT","bin":250,"xmin":0,"xmax":1.2},
    "FinalClassifier_BDT_bb":{"name":"_FinalClassifier_BDT_bb","title":"#beta_{bb}","bin":250,"xmin":-2,"xmax":1.2},
    "FinalClassifier_BDT_bj":{"name":"_FinalClassifier_BDT_bj","title":"#beta_{jb}","bin":250,"xmin":-2,"xmax":1.2},
    "FinalClassifier_BDT_bc":{"name":"_FinalClassifier_BDT_bc","title":"#beta_{bc}","bin":250,"xmin":-2,"xmax":1.2},
    "FinalClassifier_BDT_ij":{"name":"_FinalClassifier_BDT_ij","title":"#beta_{ij}","bin":250,"xmin":-2,"xmax":1.2},
    "FinalClassifier_BDT_cc":{"name":"_FinalClassifier_BDT_cc","title":"#beta_{cc}","bin":250,"xmin":-2,"xmax":1.2},
    "FinalClassifier_BDT_cj":{"name":"_FinalClassifier_BDT_cj","title":"#beta_{cj}","bin":250,"xmin":-2,"xmax":1.2}
    #"FinalClassifier_DNN":{"name":"FinalClassifier_DNN","title":"DNN","bin":250,"xmin":0,"xmax":1.2},
    #"FinalClassifier_MLP":{"name":"FinalClassifier_MLP","title":"MLP","bin":250,"xmin":0,"xmax":1.2}
}

###Number of CPUs to use
NUM_CPUS = 5

###This part is standard to all analyses
import config.runDataFrameFinal as rdf
myana=rdf.runDataFrameFinal(baseDir,procDict,process_list,cut_list,variables)
myana.run(ncpu=NUM_CPUS)
print(procDict)
