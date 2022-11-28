#python examples/FCCee/higgs/mH-recoil/mumu/finalSel.py 

from config.common_defaults import deffccdicts

import sys, os
import ROOT

###Input directory where the files produced at the pre-selection level are
baseDir  = "/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/ee_bbH_inclusive/240/presel_10/"

###Link to the dictonary that contains all the cross section informations etc...
procDict = os.path.join(os.getenv('FCCDICTSDIR', deffccdicts), '') + "FCCee_procDict_spring2021_IDEA.json"
#procDict = "/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/auxiliaryFiles/normalization1.json" #Crosssection is 1; damit wir cuts setzen können


process_list=['wzp6_ee_qqH_ecm240','p8_ee_Zqq_ecm240', 'p8_ee_WW_ecm240', 'p8_ee_ZZ_ecm240']
#process_list=['p8_ee_WW_ecm240']
#process_list=['wzp6_ee_qqH_ecm240', 'p8_ee_WW_ecm240']

#muss mit wahr/falsch antworten; std::size_t is the unsigned integer type of the result of the sizeof operator as well as the sizeof... operator and the alignof operator (since C++11).
#mass.at(i) gibt masse von beiden Z's zurück
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
            "selZjjFinal_noBDT":"zed_hadronic_subjets_btag.size() > 1 && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96",
            
            "selZjjFinal":"zed_hadronic_subjets_btag.size() > 1 && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT_jj > 0.2895",
            
            "selZjjFinal2":"zed_hadronic_subjets_btag.size() > 1 && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1)) && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT_jj > 0.2895 && bjetNo[0] > 1",


            #"selZjjFinal3":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT_jj > -0.06 && missingET_e[0] < 60 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98",
            #"selZjjFinal4":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT_jj > -0.06 && missingET_e[0] < 60 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98 && jet_ht[0] > 100",
            #"selZjjFinal5":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT_jj > -0.06 && missingET_e[0] < 60 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98 && jet_ht[0] > 100 && jetNo[0] > 3",
            #"selZjjFinal6":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT_jj > -0.06 && missingET_e[0] < 60 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98 && jet_ht[0] > 100 && jetNo[0] > 3 && zed_hadronic_subjets_pt1[0] > 10",
            #"selZjjFinal7":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT_jj > -0.06 && missingET_e[0] < 60 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98 && jet_ht[0] > 100 && jetNo[0] > 3 && zed_hadronic_subjets_pt1[0] > 10 && zed_hadronic_subjets_pt2[0] > 20",
            #"selZjjFinal8":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT_jj > 0.24 && missingET_e[0] < 60 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98 && jet_ht[0] > 100 && jetNo[0] > 3 && zed_hadronic_subjets_pt1[0] > 10 && zed_hadronic_subjets_pt2[0] > 20",

            }


###Dictionary for the ouput variable/hitograms. The key is the name of the variable in the output files. "name" is the name of the variable in the input file, "title" is the x-axis label of the histogram, "bin" the number of bins of the histogram, "xmin" the minimum x-axis value and "xmax" the maximum x-axis value.
variables = {
    #"btag":{"name":"JET_btag", "title":"btag", "bin":2, "xmin":0, "xmax":3},
    #"ctag":{"name":"jets_kt_ctag", "title":"ctag", "bin":2, "xmin":0, "xmax":2},
    #"m_ij":{"name":"jets_kt_m", "title":"m_ij", "bin":100, "xmin":20, "xmax":180},
    #"pT_b":{"name":"selected_bjets_pt", "title":"pT_b", "bin":100, "xmin":20, "xmax":180},
    #"m_b":{"name":"selected_bjets_m", "title":"pT_b", "bin":100, "xmin":20, "xmax":180}
    "m_rec":{"name":"zed_hadronic_recoil_m","title":"m_{Rec} [GeV]","bin":40,"xmin":100,"xmax":160},
    #"mz_zoom":{"name":"zed_hadronic_m","title":"m_{Z} [GeV]","bin":20,"xmin":80,"xmax":100},
    #"z_pt":{"name":"zed_hadronic_pt","title":"pT_{Z} [GeV]", "bin":100, "xmin":60, "xmax":120},
    "jet_ht":{"name":"jet_ht","title":"HT_{i} [GeV]", "bin":150, "xmin":0, "xmax":250},
    "htheta":{"name":"zed_hadronic_theta","title":"#theta_{ij}", "bin":100, "xmin":0, "xmax":4},
    "hrtheta":{"name":"zed_hadronic_recoil_theta","title":"#theta_{Rec}", "bin":100, "xmin":0, "xmax":4},
    "pT1":{"name":"zed_hadronic_subjets_pt1","title":"p_{T1} [GeV]","bin":125,"xmin":0,"xmax":200},
    "pT2":{"name":"zed_hadronic_subjets_pt2","title":"p_{T2} [GeV]","bin":125,"xmin":0,"xmax":200},
    #"pL1":{"name":"zed_hadronic_subjets_pl1","title":"p_{L1} [GeV]","bin":125,"xmin":0,"xmax":200},
    #"pL2":{"name":"zed_hadronic_subjets_pl2","title":"p_{L2} [GeV]","bin":125,"xmin":0,"xmax":200},
    "E1":{"name":"zed_hadronic_subjets_E1","title":"E_{j1} [GeV]","bin":125,"xmin":0,"xmax":200},
    "E2":{"name":"zed_hadronic_subjets_E2","title":"E_{j2} [GeV]","bin":125,"xmin":0,"xmax":200},
    "Eta1":{"name":"zed_hadronic_subjets_Eta1","title":"Eta_{1}","bin":125,"xmin":-20,"xmax":20},
    "Eta2":{"name":"zed_hadronic_subjets_Eta2","title":"Eta_{2}","bin":125,"xmin":-20,"xmax":20},
    "pT_ij":{"name":"zed_hadronic_pt","title":"p_{Tij} [GeV]","bin":125,"xmin":0,"xmax":200},
    #"pL_ij":{"name":"zed_hadronic_pl","title":"p_{Lij} [GeV]","bin":125,"xmin":0,"xmax":200},
    "M_ij":{"name":"zed_hadronic_m","title":"M_{ij} [GeV]","bin":75,"xmin":80,"xmax":100},
    "Acoll_ij":{"name":"zed_hadronic_subjets_acoll","title":"Acoll_{ij}","bin":125,"xmin":-1.5,"xmax":1.5},
    "Jet_No":{"name":"jetNo","title":"N_{jets}","bin":125,"xmin":0,"xmax":15},
    "bJet_No":{"name":"bjetNo","title":"N_{bjets}","bin":125,"xmin":0,"xmax":10},
    #"cJet_No":{"name":"cjetNo","title":"N_{cjets}","bin":125,"xmin":0,"xmax":10},
    "zed_bJet_No":{"name":"zed_hadronic_subjets_btag","title":"N_{Zbjets}","bin":125,"xmin":0,"xmax":15},
    "zed_cJet_No":{"name":"zed_hadronic_subjets_ctag","title":"N_{Zcjets}","bin":125,"xmin":0,"xmax":15},
    "zed_lJet_No":{"name":"zed_hadronic_subjets_ltag","title":"N_{Zljets}","bin":125,"xmin":0,"xmax":15},
    "MET":{"name":"missingET_e","title":"MET [GeV]","bin":125,"xmin":0,"xmax":120},
    "MET_Angle":{"name":"missingET_costheta","title":"cos(#theta_{Miss})","bin":125,"xmin":-1,"xmax":1},
    #"FinalClassifier_BDT":{"name":"FinalClassifier_BDT","title":"BDT","bin":250,"xmin":0,"xmax":1.2},
    #"FinalClassifier_BDT_bb":{"name":"_FinalClassifier_BDT_bb","title":"#beta_{bb}","bin":125,"xmin":-1,"xmax":1.2},
    #"FinalClassifier_BDT_jb":{"name":"_FinalClassifier_BDT_jb","title":"#beta_{jb}","bin":125,"xmin":-1,"xmax":1.2},
    "FinalClassifier_BDT_jj":{"name":"_FinalClassifier_BDT_jj","title":"#beta_{jj}","bin":125,"xmin":-1,"xmax":1.2},
    #"FinalClassifier_BDT_cc":{"name":"_FinalClassifier_BDT_cc","title":"#beta_{cc}","bin":125,"xmin":-1,"xmax":1.2}
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